gdk_wayland_sources = files([
  'gdkapplaunchcontext-wayland.c',
  'gdkcursor-wayland.c',
  'gdkdevice-wayland.c',
  'gdkdisplay-wayland.c',
  'gdkdnd-wayland.c',
  'gdkeventsource.c',
  'gdkglcontext-wayland.c',
  'gdkkeys-wayland.c',
  'gdkmonitor-wayland.c',
  'gdkselection-wayland.c',
  'gdkvulkancontext-wayland.c',
  'gdkwindow-wayland.c',
  'wm-button-layout-translation.c',
])

gdk_wayland_public_headers = files([
  'gdkwaylanddevice.h',
  'gdkwaylanddisplay.h',
  'gdkwaylandglcontext.h',
  'gdkwaylandmonitor.h',
  'gdkwaylandwindow.h'
])

install_headers(gdk_wayland_public_headers, subdir: 'gtk-4.0/gdk/wayland/')
install_headers('gdkwayland.h', subdir: 'gtk-4.0/gdk/')

gdk_wayland_deps = [
  shmlib,
  xkbdep,
  wlclientdep,
  wlprotocolsdep,
  wlcursordep,
  wlegldep,
]

# wayland protocols
proto_dir = dependency('wayland-protocols').get_pkgconfig_variable('pkgdatadir')
assert(proto_dir != '', 'Could not get pkgdatadir from wayland-protocols.pc')

wayland_scanner = find_program('wayland-scanner')
genprotocols = find_program('genprotocolfiles.py')

# Format:
#  - protocol name
#  - protocol stability ('stable' or 'unstable')
#  - protocol version (if stability is 'unstable')
proto_sources = [
  ['gtk-shell', 'stable', ],
  ['gtk-primary-selection', 'stable', ],
  ['pointer-gestures', 'unstable', 'v1', ],
  ['xdg-shell', 'unstable', 'v6', ],
  ['xdg-foreign', 'unstable', 'v1', ],
  ['tablet', 'unstable', 'v2', ],
  ['keyboard-shortcuts-inhibit', 'unstable', 'v1', ],
  ['server-decoration', 'stable' ],
]

gdk_wayland_gen_headers = []

foreach p: proto_sources
  proto_name = p.get(0)
  proto_stability = p.get(1)

  if proto_stability == 'stable'
    output_base = proto_name
    input = 'protocol/@0@.xml'.format(proto_name)
  else
    proto_version = p.get(2)
    output_base = '@0@-@1@-@2@'.format(proto_name, proto_stability, proto_version)
    input = join_paths(proto_dir, '@0@/@1@/@2@.xml'.format(proto_stability, proto_name, output_base))
  endif

  gdk_wayland_gen_headers += custom_target('@0@ client header'.format(output_base),
                                           input: input,
                                           output: '@0@-client-protocol.h'.format(output_base),
                                           command: [
                                             genprotocols,
                                             wayland_scanner,
                                             '@INPUT@', '@OUTPUT@',
                                             'client-header',
                                           ])

  gdk_wayland_sources += custom_target('@0@ source'.format(output_base),
                                       input: input,
                                       output: '@0@-protocol.c'.format(output_base),
                                       command: [
                                         genprotocols,
                                         wayland_scanner,
                                         '@INPUT@', '@OUTPUT@',
                                         'code',
                                       ])
endforeach

libgdk_wayland = static_library('gdk-wayland',
                                gdk_wayland_sources, gdk_wayland_gen_headers, gdkconfig, gdkenum_h,
                                include_directories: [ confinc, gdkinc, ],
                                c_args: [
                                  '-DGDK_COMPILATION',
                                  '-DG_LOG_DOMAIN="Gdk"',
                                ] + common_cflags,
                                link_args: common_ldflags,
                                dependencies: [ gdk_deps, gdk_wayland_deps, ])
