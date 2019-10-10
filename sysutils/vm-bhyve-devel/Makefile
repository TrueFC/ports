# $FreeBSD: head/sysutils/vm-bhyve/Makefile 423053 2016-10-01 11:26:06Z riggs $

PORTNAME=	vm-bhyve
PORTVERSION=	1.3b
DISTVERSIONPREFIX=v
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-devel

MAINTAINER=	churchers@gmail.com
COMMENT=	Management system for bhyve virtual machines (beta version)

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

OPTIONS_DEFINE=	EXAMPLES
EXAMPLES_DESC=	Install example guest templates

USE_GITHUB=	yes
GH_ACCOUNT=	churchers
GH_TAGNAME=	c2027a4fd32761a07b2d33cdb16fefd52204b49e

PATCH_STRIP=	-p1
NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/vm ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d/vm ${STAGEDIR}${PREFIX}/etc/rc.d
	(cd ${WRKSRC}/lib/ && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/vm-bhyve)
	(cd ${WRKSRC}/sample-templates/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
	${INSTALL_MAN} ${WRKSRC}/vm.8 ${STAGEDIR}${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
