Name:		package
Version:	0.0.1
Release:	alt1
Group:		Other
License:	MIT

Summary: package for 01_TerminalProject

Source:		%name-%version.tar.gz

BuildRequires: libncurses-devel libncursesw-devel

%description
package for 01_TerminalProject
homework owo

%prep
%setup

%build
make

%install
make install DESTDIR=%buildroot

%files
%_bindir/Show

%changelog
* Thu Oct 08 2026 ArcanePact <arcane@host> 0.0.1-alt1
- Initial build for ALT


