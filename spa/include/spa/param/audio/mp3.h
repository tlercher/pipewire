/* Simple Plugin API
 *
 * Copyright © 2023 Wim Taymans
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef SPA_AUDIO_MP3_H
#define SPA_AUDIO_MP3_H

#ifdef __cplusplus
extern "C" {
#endif

#include <spa/param/audio/raw.h>

enum spa_audio_mp3_channel_mode {
	SPA_AUDIO_MP3_CHANNEL_MODE_UNKNOWN,
	SPA_AUDIO_MP3_CHANNEL_MODE_MONO,
	SPA_AUDIO_MP3_CHANNEL_MODE_STEREO,
	SPA_AUDIO_MP3_CHANNEL_MODE_JOINTSTEREO,
	SPA_AUDIO_MP3_CHANNEL_MODE_DUAL,
};

struct spa_audio_info_mp3 {
	uint32_t rate;				/*< sample rate */
	uint32_t channels;			/*< number of channels */
};

#define SPA_AUDIO_INFO_MP3_INIT(...)		((struct spa_audio_info_mp3) { __VA_ARGS__ })

/**
 * \}
 */

#ifdef __cplusplus
}  /* extern "C" */
#endif

#endif /* SPA_AUDIO_MP3_H */
