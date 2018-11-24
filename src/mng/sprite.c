#include <mng/sprite.h>

#include <stdlib.h>

#include <mng/macros.h>

Sprite* sprite_new(void)
{
    Sprite* sprite = malloc(sizeof(Sprite));
    RETURN_VALUE_IF_NULL(sprite, NULL);

    sprite->texture = NULL;
    sprite->region = (Rect){0, 0, 0, 0};
    sprite->position = (Point2){0, 0};
    sprite->scale = (Vector2){1.0, 1.0};
    sprite->rotation = 0.0;
    sprite->origin = (Point2){0, 0};

    return sprite;
}

void sprite_free(Sprite* sprite)
{
    RETURN_IF_NULL(sprite);
    free(sprite);
}
