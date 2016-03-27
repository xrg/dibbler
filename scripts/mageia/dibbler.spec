%define git_repo dibbler
%define git_head HEAD

Summary: Dibbler - a portable DHCPv6
Name: dibbler
Version:        %git_get_ver
Release:        %mkrel %git_get_rel2
License: GPL
Group: Applications/Internet
Source:         %git_bs_source %{name}-%{version}.tar.gz
URL: http://klub.com.pl/dhcpv6/


%description
Dibbler is a portable DHCPv6 implementation. It supports stateful (i.e. IPv6 address granting and IPv6 prefix delegation) as well as stateless (i.e. option granting) autoconfiguration for IPv6. Currently Linux 2.4 or later and Windows XP or later are supported. 

%prep
%git_get_source
%setup -q

%build
%configure2_5x
%make


%install
%makeinstall_std

install -d %{buildroot}%{_localstatedir}/lib/%{name}
install -d %{buildroot}%{_sysconfdir}/%{name}

install doc/examples/client-autodetect.conf %{buildroot}%{_sysconfdir}/%{name}/client.conf


%files
%{_docdir}/%{name}/*
%{_sysconfdir}/dibbler
%{_localstatedir}/lib/dibbler
%{_sbindir}/%{name}-*
%{_mandir}/man*/%{name}-*

%changelog -f %{_sourcedir}/%{name}-changelog.gitrpm.txt
