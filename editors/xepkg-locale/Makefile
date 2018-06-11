# $FreeBSD$

PORTNAME=	locale
PORTVERSION=	1.28
CATEGORIES=	editors xepkgs
MASTER_SITES=	XEP

MAINTAINER=	xemacs@FreeBSD.org
COMMENT=	Localized menubars and localized splash screens

LICENSE=	GPLv2

USES=		xemacs
NO_ARCH=	yes

.include <bsd.port.options.mk>

SUB_FILES=	Emacs_ja
.if ${PORT_OPTIONS:MUTF8}
SUB_LIST=	CHARSETREGISTRY=iso10646
.else
SUB_LIST=	CHARSETREGISTRY='*'
.endif

ENCODING_FILES=	Emacs_ja.in:etc/app-defaults/ja/Emacs

.include <bsd.port.mk>
