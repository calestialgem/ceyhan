#include "ceyhan.h"

#include <stdint.h>

static CeyStatus ceyTestModule(CeyPath const *restrict modulePath);

int main() {
    // TODO(Cem): For each module in `tests` directory, run `ceyTestModule`.
}

CeyStatus ceyTestModule(CeyPath const *restrict modulePath) {
    CeyStatus status;
    CeyTarget target;
    CeyArtifact artifact;
    int64_t exitCode;

    status = ceyCheck(modulePath, &target);
    if (!ceyTestStatus(&status)) {
        goto end;
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

    status = ceyExecute(&artifact, &exitCode);
    if (ceyTestStatus(&status)) {
        goto initializedArtifact;
    }

    // TODO(Cem): Check whether `exitCode` has the expected value.

initializedArtifact:
    ceyDestroyArtifact(artifact);

initializedTarget:
    ceyDestroyTarget(target);

end:
    return status;
}
