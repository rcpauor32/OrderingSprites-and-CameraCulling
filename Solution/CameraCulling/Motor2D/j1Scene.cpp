#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Input.h"
#include "j1Textures.h"
#include "j1Render.h"
#include "j1Window.h"
#include "j1Map.h"
#include "j1Scene.h"

j1Scene::j1Scene() : j1Module()
{
	name.create("scene");
}

// Destructor
j1Scene::~j1Scene()
{}

// Called before render is available
bool j1Scene::Awake()
{
	LOG("Loading Scene");
	bool ret = true;

	return ret;
}

// Called before the first frame
bool j1Scene::Start()
{
	App->map->Load("iso.tmx");
	
	SDL_Texture* ItemTex = App->tex->Load("Sprites/Items.png");

	Key = App->ent->CreateEntity();
	Bowl = App->ent->CreateEntity();
	Heart = App->ent->CreateEntity();

	Key->SetTexture(ItemTex);
	Bowl->SetTexture(ItemTex);
	Heart->SetTexture(ItemTex);

	Key->SetTexRect(362, 146, 28, 32);
	Bowl->SetTexRect(36, 218, 32, 32);
	Heart->SetTexRect(182, 40, 28, 26);

	Key->pos = { 100, 100 };
	Bowl->pos = { 320, 250 };
	Heart->pos = { 400, 500 };

	return true;
}

// Called each loop iteration
bool j1Scene::PreUpdate()
{
	return true;
}

// Called each loop iteration
bool j1Scene::Update(float dt)
{
	if(App->input->GetKey(SDL_SCANCODE_L) == KEY_DOWN)
		App->LoadGame("save_game.xml");

	if(App->input->GetKey(SDL_SCANCODE_S) == KEY_DOWN)
		App->SaveGame("save_game.xml");

	if(App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
		App->render->MoveCamera(0, -1);

	if(App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
		App->render->MoveCamera(0, 1);

	if(App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
		App->render->MoveCamera(-1, 0);

	if(App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
		App->render->MoveCamera(1, 0);

	App->map->Draw();

	App->win->SetTitle("Camera Culling TODOs %d %d");


	return true;
}

// Called each loop iteration
bool j1Scene::PostUpdate()
{
	bool ret = true;

	if(App->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN)
		ret = false;

	return ret;
}

// Called before quitting
bool j1Scene::CleanUp()
{
	LOG("Freeing scene");

	return true;
}
