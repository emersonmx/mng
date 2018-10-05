#include <stdlib.h>
#include <time.h>

#include "app.h"

static App* app = NULL;

void Finalize()
{
    app_finalize(app);
    app_free(app);
}

int main()
{
    srand(time(NULL));

    app = app_new();

    atexit(Finalize);
    app_initialize(app);
    app_run(app);

    return 0;
}
