# .twmrc

## configuration for twm (Tab Window Manager)

### Don't use default settings

    NoDefaults

### Color Scheme & Appearance
    Color
    {
        BorderColor          "#6E6E6E"
        BorderTileForeground "#4E4E4E"
        BorderTileBackground "#4E4E4E"
        DefaultBackground    "#D6D6D6"
        DefaultForeground    "#000000"

        TitleBackground      "#4E4E4E"
        TitleForeground      "#FFFFFF"

        MenuTitleBackground  "#4E4E4E"
        MenuTitleForeground  "#FFFFFF"

        MenuBackground       "#D6D6D6"
        MenuForeground       "#4E4E4E"

        MenuShadowColor      "#303639"
        MenuBorderColor      "#000000"
    }

### Cursors

    Cursors
    {
        Frame   "fleur"
        Title   "top_left_arrow"
        Move    "fleur"
        Resize  "fleur"
        Menu    "top_left_arrow"
        Button  "top_left_arrow"
        Wait    "watch"
        Select  "dot"
        Destroy "pirate"
    }

### Window and Menu Settings

#### Number of pixels for border around window
    BorderWidth 1

#### Number of pixels between titlebar buttons and frame
    FramePadding 1

#### Number of pixels for button border
    TitleButtonBorderWidth 0

#### Number of pixels around title buttons
    TitlePadding 2

#### Button indent (can squash buttons together)
    ButtonIndent 0

#### Number of pixels for the menu border
    MenuBorderWidth 1

#### Remove the shadow behind the menu
    NoMenuShadows

#### Titlebar Font
    TitleFont "-misc-fixed-medium-r-normal--12-*-*-*-*-*-*-"

#### Directory for non-default icons
    IconDirectory "~/.twm/icons"

#### Left titlebar buttons
    LeftTitleButton "hamburger.xbm"=f.menu "WindowMenu"

#### Right titlebar buttons
    RightTitleButton "minus.xbm"=f.iconify
    RightTitleButton "plus.xbm"=f.fullzoom
    RightTitleButton "resize.xbm"=f.resize
    RightTitleButton "cross.xbm"=f.delete

#### Don't show the titlebar highlight
    NoTitleHighlight

#### Show window contents while dragging
    OpaqueMove

#### Icons override client-supplied pixmaps
    ForceIcons

#### Squeezed titlebars (BeOS style)
    SqueezeTitle

### Mouse and keyboard mappings

    # Button1=left, Button2=middle, Button3=right, m=alt, c=ctrl, s=shift

#### Functions for other actions to use
    Function "move-or-iconify" { f.move f.deltastop f.iconify }
    Function "raise-lower-move" { f.move f.raiselower }

#### The root window actions i.e. clicking on the backgound
    Button1 = : root : f.menu "TwmWindows"
    Button3 = : root : f.menu "DesktopMenu"

#### Left click the window title to lower / raise + gain focus or move
    Button1 = : title : f.function "raise-lower-move"

#### Roght click the window title for options for individual windows
    Button3 = : title : f.menu "WindowMenu"

#### Hold alt key and left click to move entire window
    Button1 = m : window : f.move

#### Hold shift key and right click / move to resize
    Button3 = s : window : f.resize

#### Resize from frame
    Button1 = : frame : f.resize

#### Hold Alt and Tab cycles through windows bringing up focus
    Function "winup" { f.circleup }
    "Tab" = m : root|window|frame|title : f.function "winup"

#### Hold Alt plus left click window title to maximize window vertically
    Button1 = m : title|frame : f.zoom

#### Hold Alt plus right click window title to maximize window horizontally
    Button3 = m : title|frame : f.horizoom

#### Restore icon when clicked on. Unused when IconifyByUnmapping is set
    Button1 = : icon : f.function "move-or-iconify"
    Button3 = : icon : f.resize

#### Key or button events with no binding action
    DefaultFunction f.nop

### Window Management

#### Don't show iconified windows
    IconifyByUnmapping

#### Don't require crossing window edge to resize
    AutoRelativeResize

#### Decorate transient windows
    DecorateTransients

#### Use previeous window state when starting
    RestartPreviousState

#### Use window hints for window location
    UsePPosition "on"

#### Place windows psuedo-randomly instead of user specified location
    RandomPlacement

#### Number of pixels before starting to move with f.move
    Movedelta 2

#### Repainting is faster than saving
    NoSaveUnders

#### Turn off horizontal/vertical only moving
    ConstrainedMoveTime 0

### Menus

#### Desktop Menu
    Menu "DesktopMenu"
    {
        "Desktop Menu" f.title
        "Terminal" f.exec "xterm &"
        "Set Desktop Color..." f.menu "DesktopColorMenu"
    }

#### Window Menu
    Menu "WindowMenu"
    {
        "Window Menu" f.title
        "Minimize" f.iconify
        "Zoom" f.fullzoom
        "Lower" f.lower
        "" f.nop
        "Tile..." f.menu "TileMenu"
        "" f.nop
        "Close" f.delete
        "Kill" f.destroy
        "" f.nop
        "Windows..." f.menu "TwmWindows"
    }

#### Tile Menu
    Menu "TileMenu"
    {
        "Top" f.topzoom
        "Right" f.rightzoom
        "Left" f.leftzoom
        "Bottom" f.bottomzoom
        "Wide" f.horizoom
    }

#### Desktop Color Menu (FlatUI Colors v1)
    Menu "DesktopColorMenu"
    {
        "Wet Asphalt"   ("#34495e":"#D6D6D6")   f.exec "xsetroot -solid \\#34495e"
        "Midnight Blue" ("#2c3e50":"#D6D6D6")   f.exec "xsetroot -solid \\#2c3e50"
        "Amethyst"      ("#9b59b6":"#D6D6D6")   f.exec "xsetroot -solid \\#9b59b6"
        "Wisteria"      ("#8e44ad":"#D6D6D6")   f.exec "xsetroot -solid \\#8e44ad"
        "Belize Hole"   ("#2980b9":"#D6D6D6")   f.exec "xsetroot -solid \\#2980b9"
        "Peter River"   ("#3498db":"#D6D6D6")   f.exec "xsetroot -solid \\#3498db"
        "Nephritis"     ("#27ae60":"#D6D6D6")   f.exec "xsetroot -solid \\#27ae60"
        "Emerald"       ("#2ecc71":"#D6D6D6")   f.exec "xsetroot -solid \\#2ecc71"
        "Green Sea"     ("#16a085":"#D6D6D6")   f.exec "xsetroot -solid \\#16a085"
        "Turquoise"     ("#1abc9c":"#D6D6D6")   f.exec "xsetroot -solid \\#1abc9c"
        "Orange"        ("#f39c12":"#D6D6D6")   f.exec "xsetroot -solid \\#f39c12"
        "Sunflower"     ("#f1c40f":"#D6D6D6")   f.exec "xsetroot -solid \\#f1c40f"
        "Pumpkin"       ("#d35400":"#D6D6D6")   f.exec "xsetroot -solid \\#d35400"
        "Carrot"        ("#e67e22":"#D6D6D6")   f.exec "xsetroot -solid \\#e67e22"
        "Pomegranate"   ("#c0392b":"#D6D6D6")   f.exec "xsetroot -solid \\#c0392b"
        "Alizarin"      ("#e74c3c":"#D6D6D6")   f.exec "xsetroot -solid \\#e74c3c"
        "Silver"        ("#bdc3c7":"#D6D6D6")   f.exec "xsetroot -solid \\#bdc3c7"
        "Clouds"        ("#ecf0f1":"#D6D6D6")   f.exec "xsetroot -solid \\#ecf0f1"
        "Asbestos"      ("#7f8c8d":"#D6D6D6")   f.exec "xsetroot -solid \\#7f8c8d"
        "Concrete"      ("#95a5a6":"#D6D6D6")   f.exec "xsetroot -solid \\#95a5a6"
    }
