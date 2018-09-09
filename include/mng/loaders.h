#ifndef MNG_LOADERS_H
#define MNG_LOADERS_H

#include <mng/renderer.h>

#ifdef __cplusplus
extern "C" {
#endif

Texture* load_texture(Renderer* renderer, const char* filename);

#ifdef __cplusplus
}
#endif

#endif /* MNG_LOADERS_H */
