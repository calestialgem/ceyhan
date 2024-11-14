#include "ceyhan.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argumentCount, char const *const *arguments) {
    // TODO(Cem): Parse arguments and stop at the stage the user asked for.

    CeyStatus status;
    char const *configuredModulePath;
    CeyPath modulePath;
    CeyTarget target;
    CeyArtifact artifact;
    int64_t exitCode;
    int compilerExitCode;

    compilerExitCode = 0;

    status = ceyInitializePath(&modulePath);
    if (!ceyTestStatus(&status)) {
        goto end;
    }

    if (argumentCount < 2) {
        configuredModulePath = ".";
    } else {
        configuredModulePath = arguments[1];
    }
    status = ceyAppendTerminatedToPath(&modulePath, configuredModulePath);
    if (!ceyTestStatus(&status)) {
        goto initializedModulePath;
    }

    status = ceyCheck(&modulePath, &target);
    if (!ceyTestStatus(&status)) {
        goto initializedModulePath;
    }

    if (!ceyTestTarget(&target)) {
        goto initializedTarget;
    }

    status = ceyGenerate(&target, &artifact);
    if (!ceyTestStatus(&status)) {
        goto initializedTarget;
    }

    if (!ceyTestArtifact(&artifact)) {
        goto initializedArtifact;
    }

    // TODO(Cem): Pass arguments after the separator `--` to the artifact.
    status = ceyExecute(&artifact, &exitCode);
    if (!ceyTestStatus(&status)) {
        goto initializedArtifact;
    }

    {
        int signBit;
        int byte;
        signBit = (int)((uint64_t)exitCode >> (sizeof(exitCode) * CHAR_BIT - 1));
        byte = -signBit;
        memset(&compilerExitCode, byte, sizeof(compilerExitCode));
        memcpy(&compilerExitCode, &exitCode, ceyMinSize(sizeof(compilerExitCode), sizeof(exitCode)));
    }

initializedArtifact:
    ceyDestroyArtifact(artifact);

initializedTarget:
    ceyDestroyTarget(target);

initializedModulePath:
    ceyDestroyPath(modulePath);

end:
    ceyPrintStatus(stderr, &status);
    ceyDestroyStatus(status);

    return compilerExitCode;
}
