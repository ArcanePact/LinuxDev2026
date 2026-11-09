%define _unpackaged_files_terminate_build 1
Name:		prophet
Version:	0.0.1
Release:	alt1
Group:		Other
License:	MIT

Summary: package for 08_I18n

Source:		%name-%version.tar.gz

%description
A program which guesses numbers. I replaced constant intervals with random numbers to achieve better user expirience

%prep
%setup

%conf
%autoreconf
%configure

%build
%make_build

%install
%makeinstall_std

%files
%_bindir/prophet
%_datadir/locale/*/*/*.mo

%changelog
* Sun Nov 11 2026 ArcanePact <arcane@host> 0.0.1-alt1
- Initial build for ALT


