#include "j1Player.h"
#include "j1Input.h"

#include "p2Log.h"

bool j1Player::Start()
{

	texture = App->tex->Load("Sprites/Link_Movement.png");

	//Walk
	{
		rect[up][0] = { 0, link_y * 2, link_width, link_height };
		rect[up][1] = { link_x, link_y * 2, link_width, link_height };
		rect[up][2] = { link_x * 2 , link_y * 2, link_width, link_height };
		rect[up][3] = { link_x * 3, link_y * 2, link_width, link_height };
		rect[up][4] = { link_x * 4, link_y * 2, link_width, link_height };
		rect[up][5] = { link_x * 5, link_y * 2, link_width, link_height };
		rect[up][6] = { link_x * 6, link_y * 2, link_width, link_height };

		rect[down][0] = { 0 ,  link_y, link_width, link_height };
		rect[down][1] = { link_x, link_y, link_width, link_height };
		rect[down][2] = { link_x * 2, link_y, link_width, link_height };
		rect[down][3] = { link_x * 3, link_y, link_width, link_height };
		rect[down][4] = { link_x * 4, link_y, link_width, link_height };
		rect[down][5] = { link_x * 5, link_y, link_width, link_height };
		rect[down][6] = { link_x * 6, link_y, link_width, link_height };

		rect[right][0] = { 0  ,link_y * 3,link_width,link_height };
		rect[right][1] = { link_x,link_y * 3,link_width,link_height };
		rect[right][2] = { link_x * 2,link_y * 3,link_width,link_height };
		rect[right][3] = { link_x * 3,link_y * 3,link_width,link_height };
		rect[right][4] = { link_x * 4,link_y * 3,link_width,link_height };
		rect[right][5] = { link_x * 5,link_y * 3,link_width,link_height };
		rect[right][6] = { link_x * 6,link_y * 3,link_width,link_height };

		rect[left][0] = { 0  ,link_y * 4,link_width,link_height };
		rect[left][1] = { link_x,link_y * 4,link_width,link_height };
		rect[left][2] = { link_x * 2,link_y * 4,link_width,link_height };
		rect[left][3] = { link_x * 3,link_y * 4,link_width,link_height };
		rect[left][4] = { link_x * 4,link_y * 4,link_width,link_height };
		rect[left][5] = { link_x * 5,link_y * 4,link_width,link_height };
		rect[left][6] = { link_x * 6,link_y * 4,link_width,link_height };
	}

	walk[up].PushBack(rect[up][0]);
	walk[up].PushBack(rect[up][1]);
	walk[up].PushBack(rect[up][2]);
	walk[up].PushBack(rect[up][3]);
	walk[up].PushBack(rect[up][4]);
	walk[up].PushBack(rect[up][5]);
	walk[up].PushBack(rect[up][6]);
	walk[up].speed = PL_WALK_FPS;

	walk[down].PushBack(rect[down][0]);
	walk[down].PushBack(rect[down][1]);
	walk[down].PushBack(rect[down][2]);
	walk[down].PushBack(rect[down][3]);
	walk[down].PushBack(rect[down][4]);
	walk[down].PushBack(rect[down][5]);
	walk[down].PushBack(rect[down][6]);
	walk[down].speed = PL_WALK_FPS;

	walk[left].PushBack(rect[left][0]);
	walk[left].PushBack(rect[left][1]);
	walk[left].PushBack(rect[left][2]);
	walk[left].PushBack(rect[left][3]);
	walk[left].PushBack(rect[left][4]);
	walk[left].PushBack(rect[left][5]);
	walk[left].PushBack(rect[left][6]);
	walk[left].speed = PL_WALK_FPS;

	walk[right].PushBack(rect[right][0]);
	walk[right].PushBack(rect[right][1]);
	walk[right].PushBack(rect[right][2]);
	walk[right].PushBack(rect[right][3]);
	walk[right].PushBack(rect[right][4]);
	walk[right].PushBack(rect[right][5]);
	walk[right].PushBack(rect[right][6]);
	walk[right].speed = PL_WALK_FPS;


	return true;
}

bool j1Player::Update(float dt)
{

	idle = true;

	if (App->input->GetKey(SDL_SCANCODE_W)) {
		pos.y -= PL_SPD;
		curr_dir = up;
		idle = false;
	}
	if (App->input->GetKey(SDL_SCANCODE_A)) {
		pos.x -= PL_SPD;
		curr_dir = left;
		idle = false;
	}
	if (App->input->GetKey(SDL_SCANCODE_S)) {
		pos.y += PL_SPD;
		curr_dir = down;
		idle = false;
	}
	if (App->input->GetKey(SDL_SCANCODE_D)) {
		pos.x += PL_SPD;
		curr_dir = right;
		idle = false;
	}

	// TODO 4 -- Call the method and assign a Priority to the player (Recommended: 0) 
	toDraw(walk[curr_dir].GetCurrentFrame(), PLAYER_PRIORITY);

	return true;
}

bool j1Player::PostUpdate()
{
	return true;
}

SDL_Rect j1Player::GetRect()
{
	return walk[curr_dir].GetCurrentFrame();
}

// TODO 3 -- Create a method that pushes Sprites from the player into the list we already made 
bool j1Player::toDraw(SDL_Rect rect, int priority)
{
	Sprite aux;
	aux.pos = pos;
	aux.texture = texture;
	aux.rect = rect;
	aux.priority = priority;

	App->render->sprites_toDraw.push_front(aux);

	return true;
}

bool j1Player::CleanUp()
{
	if(texture != nullptr)
		App->tex->UnLoad(texture);

	return true;
}
