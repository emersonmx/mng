#ifndef MNG_TEXTURE_H
#define MNG_TEXTURE_H

#include <mng/size.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Texture Texture;


Texture* texture_new(void);
void texture_free(Texture* texture);

Size texture_get_size(Texture* texture);

#ifdef __cplusplus
}
#endif

#endif /* MNG_TEXTURE_H */
