#ifndef MNG_MACROS_H
#define MNG_MACROS_H

#include <assert.h>

#define RETURN_R_IF_TRUE(X, R) if (X) { \
        return R; \
    }

#define RETURN_R_IF_NULL(X, R) RETURN_R_IF_TRUE(X == NULL, R)
#define RETURN_IF_NULL(X) RETURN_R_IF_NULL(X,)
#define RETURN_NULL_IF_NULL(X) RETURN_R_IF_NULL(X, NULL)
#define ASSERT_VALID_OBJECT(X) assert(X != NULL)

#endif /* MNG_MACROS_H */
