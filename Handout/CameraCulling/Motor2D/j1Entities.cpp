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
