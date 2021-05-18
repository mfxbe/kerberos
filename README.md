<sup>Internally known as eu.kosy.Kerberos</sup>
# Kerberos (Kosy Lock screen)

![Status](https://img.shields.io/badge/⚒_status-active-blue?style=flat-square)
![GitHub](https://img.shields.io/github/license/kosyteam/kerberos?style=flat-square)
[![Matrix](https://img.shields.io/matrix/kosyteam:mfxbe.de?logo=matrix&style=flat-square&color=brightgreen)](https://matrix.to/#/#kosyteam:mfxbe.de)
[![Liberapay receiving](https://img.shields.io/liberapay/receives/mfxbe?logo=liberapay&style=flat-square)](https://liberapay.com/mfxbe/donate)


> :warning: **Warning**: This software is still in a development statues. Use on productiv systems is not recommended. There might be major safety and stability problems. Multi monitors systems aren't supported at all.

Kerberos is a simple Gtk4 based lock screen for wayland compositors. It is tested on [Wayfire](https://wayfire.org/) but should work on simular system as well (check dependencies).

[![Preview image with link to video](https://raw.githubusercontent.com/KosyTeam/kerberos/master/preview.png "Click to see video")](https://tube.odat.xyz/videos/watch/bae82edf-c454-4f10-9fd1-856e7fd7b3c0?autoplay=1&muted=1)

It provides a simple screenshield with a login prompt and allows a custom background image. There is also a possebilty to use you on CSS themes for your personal experience.

### Installing
At the moment there are no available packages for Kerberos. If you want to install it check the instructions for an installation from the source code.

#### Dependencies

**Build dependencies**
* build essentials
* GTK 4 (>= 4.0)
* wayland-client (>= 1.19)
* libpam

**Additional runtime dependencies**
* wayland compositor
  * [Protocolls required by GTK]
  * wlr-input-inhibitor-unstable-v1
  * idle-inhibit-unstable-v1
* dbus
* swayidle (or simular)

#### Install from source
```
# Clone project
git clone https://github.com/KosyTeam/kerberos.git
cd kerberos
# Build and (if desired) generate locales
make
make update-locale
# Install (requires root)
sudo make install
```
#### Setup
Kerberos does not provide a graphical interface to change its settings, but this can easily done with `gsettings` (alternativly dconf-editor could be used). Before doing this please take sure that everything installed without any error.

If using gsettings all comands are in the same format: `gsettings set eu.kosy.Kerberos [key] [value]`. See table for the specific settings.
|Setting|Key|Possible values|
|---|---|---|
|Allow shutdown from lock screen|`allow-shutdown`|`true` or `false`|
|Set the background image to be used|`background-image`|Absolute path (e.g. `/home/user/Images/background.jpg`) or `''` for default|
|Use custom theme instead of the integrated|`custom-theme`|`true` or `false`|
|Set the css file containing the custom styling|`custom-theme-path`|Absolute path (e.g. `/home/user/.themes/custom.css`)*||

*Not setting `custom-theme-path` will cause the default system theme to be used. This can be very buggy.

### Run
It's recommended to start Kerberos with an idle management daemon like [swayidle](https://github.com/swaywm/swayidle). The command should be executed at startup or login and could like the following:

```
swayidle -w \
timeout 300 'kerberos' \
before-sleep 'kerberos'
```

Please note that because of limitaions in GTK 4 in combination with the wlr-layer-shell-unstable-v1-protocol some implementations will prevent further idle actions (like automatic suspend) after the start of kerberos. For more information see [#1](https://github.com/KosyTeam/kerberos/issues/1#issue-894604370).

Of course it's also possible to start kerberos directly with the `kerberos` command. It's no problem to call kerberos multiple times. If there is a running instance nothing will happen.

### Notifications
If the [Mako notification deamon](https://wayland.emersion.fr/mako/) is reachable via dbus Kerberos will automaticly show the number of missed notifications on the bottom of the screen. Other servises are not yet supported. 

### Getting help & Reporting bugs

The simplest way to get help is the [Kosy Team Matrix Group](https://matrix.to/#/#kosyteam:mfxbe.de) alternativly you can also write a e-mail. There'll be a solution on the way. If you have found a bug than you can use our [bug tracker](https://github.com/KosyTeam/kerberos/issues), but please do not ask questions there.

---

### Whats Kosy? Kosy Team?
I (*mfxbe*) use Kosy as a project name for number of applications I've written for personal use with a specific design and structur in mind. Right now Kerberos is the only one being available in public. Other might or might not be released in future.
