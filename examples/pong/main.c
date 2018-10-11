#include <stdlib.h>

#include "app.h"

int main()
{
    App* app = app_new();
    app_run(app);
    app_free(app);

    return 0;
}
