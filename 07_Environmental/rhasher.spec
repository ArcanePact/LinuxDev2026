%define _unpackaged_files_terminate_build 1
Name:		rhasher
Version:	0.0.1
Release:	alt1
Group:		Other
License:	MIT

Summary: package for 07_Environmental

Source:		%name-%version.tar.gz

BuildRequires: librhash-devel

%description
A simple hasher for strings or files

%prep
%setup

%conf
%configure

%build
%make_build

%install
%makeinstall_std

%files
%_bindir/rhasher

%changelog
* Sun Nov 11 2026 ArcanePact <arcane@host> 0.0.1-alt1
- Initial build for ALT


