#ifndef MNG_TEXTURE_H
#define MNG_TEXTURE_H

#include <mng/types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Texture Texture;

Texture* texture_new();
void texture_free(Texture* texture);

Size texture_size(Texture* texture);

#ifdef __cplusplus
}
#endif

#endif /* MNG_TEXTURE_H */
