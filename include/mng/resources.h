#ifndef MNG_RESOURCES_H
#define MNG_RESOURCES_H

#include <mng/texture.h>
#include <mng/renderer.h>

#ifdef __cplusplus
extern "C" {
#endif

Texture* load_texture(Renderer* renderer, const char* filename);

#ifdef __cplusplus
}
#endif

#endif /* MNG_RESOURCES_H */
