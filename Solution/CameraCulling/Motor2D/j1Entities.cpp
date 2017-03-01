#include "j1Entities.h"
#include "j1Render.h"
#include "p2Log.h"

bool j1EntityManager::PostUpdate()
{
	for (std::list<Entity*>::iterator it = entities.begin(); it != entities.end(); it++) {
		it._Ptr->_Myval->Update();
	}

	return true;
}

bool j1EntityManager::CleanUp()
{
	DeleteEntities();

	return true;
}

Entity* j1EntityManager::CreateEntity()
{
	Entity* ent = nullptr;

	ent = new Entity();

	entities.push_back(ent);

	return ent;
}

void j1EntityManager::DeleteEntities()
{
	if(entities.size() != 0)
		for (std::list<Entity*>::iterator it = entities.begin(); it == entities.end(); it++) {
			if(it._Ptr != nullptr)
				delete it._Ptr->_Myval;
		}
}

void Entity::Update()
{
	// OPTIONAL TODO -- Do the Same Camera Culling But apply it to Entities

	SDL_Rect cam = App->render->culling_cam;

	if (App->render->debug == true)
	{
		cam.x += ENT_CULLING_OFFSET_X;
		cam.y += ENT_CULLING_OFFSET_Y;
		cam.w -= ENT_CULLING_OFFSET_X * 2;
		cam.h -= ENT_CULLING_OFFSET_Y * 2;

		// Debugging Camera Culling Quad
		App->render->DrawQuad(cam, 84, 39, 136, 100, false, true);
	}

	if (pos.x + rect.w >= cam.x && pos.x <= cam.x + cam.w)
		if (pos.y + rect.h > cam.y && pos.y < cam.y + cam.h)
			App->render->Blit(texture, pos.x, pos.y, &rect);
}

void Entity::SetTexture(SDL_Texture * tex)
{
	texture = tex;
}

void Entity::SetTexRect(int x, int y, int w, int h)
{
	rect = { x, y, w, h };
}
