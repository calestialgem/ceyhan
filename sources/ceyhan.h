#pragma once

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

typedef struct CeyStatus CeyStatus;
typedef struct CeyPath CeyPath;
typedef struct CeyTarget CeyTarget;
typedef struct CeyArtifact CeyArtifact;

size_t ceyMinSize(size_t size0, size_t size1);

bool ceyTestStatus(CeyStatus const *restrict status);

bool ceyTestTarget(CeyTarget const *restrict target);

bool ceyTestArtifact(CeyArtifact const *restrict artifact);

void ceyPrintStatus(FILE *restrict stream, CeyStatus const *restrict status);

void ceyDestroyStatus(CeyStatus status);

void ceyDestroyPath(CeyPath path);

void ceyDestroyTarget(CeyTarget target);

void ceyDestroyArtifact(CeyArtifact artifact);

CeyStatus ceyInitializePath(CeyPath *restrict path);

CeyStatus ceyAppendTerminatedToPath(CeyPath *restrict path, char const *restrict terminated);

CeyStatus ceyCheck(CeyPath const *restrict modulePath, CeyTarget *restrict oTarget);

CeyStatus ceyGenerate(CeyTarget const *restrict target, CeyArtifact *restrict oArtifact);

// TODO(Cem): Take arguments.
CeyStatus ceyExecute(CeyArtifact const *restrict artifact, int64_t *restrict oExitCode);

struct CeyStatus {};

struct CeyPath {};

struct CeyTarget {};

struct CeyArtifact {};

char const *cey_version();
