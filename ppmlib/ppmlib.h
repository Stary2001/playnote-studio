#pragma once

#include "pd_api.h"
#include "ppm.h"

// TODO
#define AUDIO_SIZE_LIMIT = 12 * 1024 * 1024;

typedef struct ppmlib_ctx
{
  ppm_ctx_t* ppm;
  const u32* layerPattern[2];
	s16* masterAudio;
	AudioSample* masterAudioSample;
	SamplePlayer* audioPlayer;
} ppmlib_ctx;

extern void registerPpmlib(void);