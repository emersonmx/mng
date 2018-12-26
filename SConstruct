import os

BUILD_ROOT = 'build'
DEFAULT_CFLAGS = [
    '-std=c11',
]
RELEASE_CFLAGS = [
    '-O3', '-DNDEBUG',
]
DEBUG_CFLAGS = [
    '-g', '-Wall', '-Wextra', '-Wpedantic',
    '-Wformat=2', '-Wno-unused-parameter', '-Wshadow',
    '-Wwrite-strings', '-Wstrict-prototypes', '-Wold-style-definition',
    '-Wredundant-decls', '-Wnested-externs', '-Wmissing-include-dirs',
]

env = Environment(
    CFLAGS=DEFAULT_CFLAGS,
    CPPPATH=['#include', '#src'],
)

build_type = ARGUMENTS.get('build', 'debug')
if build_type == 'debug':
    env.Append(
        CFLAGS=DEBUG_CFLAGS,
    )
elif build_type == 'release':
    env.Append(
        CFLAGS=RELEASE_CFLAGS,
    )

dirs = [
    'examples', 'src',
]

for subdir in dirs:
    variant_path = os.path.join(BUILD_ROOT, subdir)
    SConscript(
        dirs=subdir,
        exports=['env', 'variant_path'],
        variant_dir=variant_path,
        duplicate=0
    )
