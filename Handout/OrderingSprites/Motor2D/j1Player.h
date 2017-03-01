#ifndef __J1PLAYER_H__
#define __J1PLAYER_H__

#include "j1App.h"
#include "j1Textures.h"
#include "j1Render.h"
#include "Animation.h"

#define PL_SPD 0.1f
#define PL_WALK_FRAMES 7

#define PL_WALK_FPS 0.008f

#define link_width 99
#define link_height 107
#define link_y 110
#define link_x 102

#define PLAYER_PRIORITY 0

#define PLAYER_OFFSET_Y 35
#define PLAYER_OFFSET_H 60

enum directions {
	up = 0,
	down,
	left,
	right,
	__LAST
};

class j1Player : public j1Module {

public:
	fPoint pos;
	directions curr_dir;

private:
	bool idle = true;

	SDL_Texture* texture;
	SDL_Rect rect[directions::__LAST][PL_WALK_FRAMES];
	
	Animation walk[directions::__LAST];

public:
	j1Player() {};
	virtual ~j1Player() {
		if (texture != nullptr)
			App->tex->UnLoad(texture);
	};

public:
	bool Start();
	bool Update(float dt);
	bool PostUpdate();

	SDL_Rect GetRect();

	// TODO 3 -- Create a method that pushes Sprites from tha player into the list we made.
	//	Keep in mind in also needs to recieve a priority to fill the Sprite's one.

	bool CleanUp();

};

#endif