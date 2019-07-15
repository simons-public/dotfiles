all: rcfiles bashprompt
	mkdir -p dotfiles

rcfiles:
	cp src/inputrc.md 		dotfiles/inputrc
	cp src/bashrc.md 		dotfiles/bashrc
	cp src/bash_profile.md 	dotfiles/bash_profile
	cp src/tmux.conf.md		dotfiles/tmux.conf
	sed -e 's/^#/"#/' src/vimrc.md > dotfiles/vimrc

bashprompt:
	mkdir -p dotfiles/bin
	$(CC) src/bashprompt/bashprompt.c -o dotfiles/bin/bashprompt

install:
	cp -r dotfiles ~/.config/
	ln -sf ~/.config/dotfiles/bash_profile ~/.bash_profile
	ln -sf ~/.config/dotfiles/bashrc 	~/.bashrc
	ln -sf ~/.config/dotfiles/inputrc	~/.inputrc
	ln -sf ~/.config/dotfiles/tmux.conf ~/.tmux.conf
	ln -sf ~/.config/dotfiles/vimrc		~/.vimrc

package:
	tar czf dotfiles.tar.gz dotfiles