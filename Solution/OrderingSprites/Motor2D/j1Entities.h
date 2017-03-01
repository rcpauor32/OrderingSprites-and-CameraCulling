#ifndef __ENTITIES_H__
#define __ENTITIES_H__

#include "j1App.h"
#include "j1Module.h"
#include "j1Render.h"
#include "j1Textures.h"

#include <list>

#define ENT_CULLING_OFFSET_X 125
#define ENT_CULLING_OFFSET_Y 100


class Entity;

class j1EntityManager : public j1Module {
private:

	std::list<Entity*> entities;

public:
	j1EntityManager() {};
	virtual ~j1EntityManager() {};

public:
	bool PostUpdate();
	bool Update(float dt);
	bool CleanUp();

	Entity* CreateEntity();
	void DeleteEntities();

	
};

class Entity {
public:

	void Update();

	void SetTexture(SDL_Texture* tex);
	void SetTexRect(int x, int y, int w, int h);

	SDL_Rect GetRect()
	{
		return rect;
	}

	// TODO 5 -- Create a similar method for the entities.
	void toDraw(int priority);

public:
	iPoint pos;

private:
	SDL_Texture* texture;
	SDL_Rect rect;
};

#endif // !__ENTITIES_H__
