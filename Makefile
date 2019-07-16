MODULES = ble

all: rcfiles bashprompt modules

rcfiles:
	mkdir -p dotfiles
	touch dotfiles/hushlogin
	cp src/inputrc.md 		dotfiles/inputrc
	cp src/bashrc.md 		dotfiles/bashrc
	cp src/bash_profile.md 	dotfiles/bash_profile
	cp src/tmux.conf.md		dotfiles/tmux.conf
	cp src/twmrc.md         dotfiles/twmrc
	cp src/spectrwm.conf.md dotfiles/spectrwm.conf
	mkdir -p dotfiles/twm
	cp -r src/twm/*         dotfiles/twm/
	sed -e 's/^#/"#/' src/vimrc.md > 		dotfiles/vimrc
	sed -e 's/^    //' src/pythonrc.md > 	dotfiles/pythonrc
	sed -e 's/^#/!/' src/Xresources.md >    dotfiles/Xresources

bashprompt:
	mkdir -p dotfiles/bin
	$(CC) src/bashprompt/bashprompt.c -o dotfiles/bin/bashprompt

modules: modules-init module-ble

modules-init:
	git submodule init
	git submodule update

module-ble:
	-mkdir -p dotfiles/lib
	-$(MAKE) --directory modules/ble/
	-cp -r modules/ble/out dotfiles/lib/ble

install:
	cp -r dotfiles ~/.config/
	ln -sf ~/.config/dotfiles/bash_profile 	~/.bash_profile
	ln -sf ~/.config/dotfiles/bashrc 	  	~/.bashrc
	ln -sf ~/.config/dotfiles/inputrc		~/.inputrc
	ln -sf ~/.config/dotfiles/tmux.conf 	~/.tmux.conf
	ln -sf ~/.config/dotfiles/vimrc			~/.vimrc
	ln -sf ~/.config/dotfiles/vimrc			~/.nvimrc
	mkdir -p ~/.vim/undo
	ln -sf ~/.config/dotfiles/hushlogin		~/.hushlogin
	ln -sf ~/.config/dotfiles/pythonrc		~/.pythonrc
	ln -sf ~/.config/dotfiles/twmrc         ~/.twmrc
	ln -sfn ~/.config/dotfiles/twm          ~/.twm
	ln -sf ~/.config/dotfiles/spectrwm.conf ~/.spectrwm.conf
	ln -sf ~/.config/dotfiles/Xresources    ~/.Xresources

package:
	tar czf dotfiles.tar.gz dotfiles

clean: clean-files clean-$(MODULES)

clean-files:
	rm -rf dotfiles
	rm -f dotfiles.tar.gz

clean-$(MODULES):
	$(MAKE) --directory modules/$(MODULES) clean
