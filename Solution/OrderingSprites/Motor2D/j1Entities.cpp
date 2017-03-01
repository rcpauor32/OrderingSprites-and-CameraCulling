#include "j1Entities.h"
#include "j1Render.h"
#include "j1Player.h"
#include "p2Log.h"

bool j1EntityManager::PostUpdate()
{
	// TODO 7 -- Check if the character's BOTTOM is under or over the entities.
	//	Assign a priority to every entity depending on that (Calling the method you created to assign entities' sprites).
	for (std::list<Entity*>::iterator it = entities.begin(); it != entities.end(); it++) {
		int aux_prio = 0;
		// The OFFSET is due to the algorith created to load all the player textures. 
		// It could be optimized by creating an additional rect inside j1Player that already held the "offsetted" coords.
		if (it._Ptr->_Myval->pos.y + it._Ptr->_Myval->GetRect().h > (int)App->player->pos.y + PLAYER_OFFSET_Y + (int)App->player->GetRect().h - PLAYER_OFFSET_H) {
			aux_prio += 1;
		}
		else {
			aux_prio -= 1;
		}
	
		it._Ptr->_Myval->toDraw(aux_prio);
	
	}

	return true;
}

bool j1EntityManager::Update(float dt)
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
			if (it._Ptr != nullptr) {
				delete it._Ptr->_Myval;
			}
		}
}

void Entity::Update()
{
		
}

void Entity::SetTexture(SDL_Texture * tex)
{
	texture = tex;
}

void Entity::SetTexRect(int x, int y, int w, int h)
{
	rect = { x, y, w, h };
}

// TODO 5 -- Create a similar method for the entities
void Entity::toDraw(int priority)
{
	Sprite aux;
	aux.rect = rect;
	aux.texture = texture;
	aux.pos.x = (float)pos.x;
	aux.pos.y = (float)pos.y;
	aux.priority = priority;

	App->render->sprites_toDraw.push_back(aux);

}
