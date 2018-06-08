# Created by: xeamcs@FreeBSD.org
# $FreeBSD$

PORTNAME=	xemacs-devel-canna
CATEGORIES=	japanese editors

MAINTAINER=	xemacs@FreeBSD.org
COMMENT=	The development version of the XEmacs with CANNA input method

CONFLICTS=	emacs21-[0-9]* emacs22-[0-9]* emacs23-[0-9]* emacs24-[0-9]* \
		emacs-nox11-[0-9]* xemacs-devel-[0-9]* xemacs-[0-9]* \
		xemacs-common-[0-9]* ja-xemacs-canna-*

XEMACS_INSTALL=	${PORTNAME}
DESCR=		${.CURDIR}/pkg-descr

L10N=		ja
WITH=		CANNA JA_JP_UTF_8 MISC

MASTERDIR=	${.CURDIR}/../../editors/xemacs-devel

.include "${MASTERDIR}/Makefile"
