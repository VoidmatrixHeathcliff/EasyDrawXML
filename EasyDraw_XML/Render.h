#ifndef _RENDER_H_
#define _RENDER_H_

#include "../libs/SDL2-2.0.12/include/SDL.h"
#include "../libs/SDL2_gfx-1.0.4/SDL2_gfxPrimitives.h"
#include "../libs/SDL2_image-2.0.5/include/SDL_image.h"
#include "../libs/SDL2_ttf-2.0.15/include/SDL_ttf.h"

struct Spirit
{
	SDL_Texture* texture;
	int w, h;
};

#endif // !_RENDER_H_
