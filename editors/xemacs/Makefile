# Created by: Gary Jennejohn (gj@FreeBSD.org)
# $FreeBSD: head/editors/xemacs/Makefile 359318 2014-06-26 07:32:36Z antoine $

PORTNAME?=	xemacs
PORTVERSION=	${XEMACS_VER}
CATEGORIES?=	editors
MASTER_SITES=	${MASTER_SITE_XEMACS}
MASTER_SITE_SUBDIR=	xemacs-${XEMACS_REL}
DISTNAME=	xemacs-${XEMACS_VER}
DIST_SUBDIR=	xemacs

MAINTAINER?=	xemacs@FreeBSD.org
COMMENT?=	The stable version of the XEmacs text editor

BUILD_DEPENDS=	autoconf-2.13:${PORTSDIR}/devel/autoconf213
.if !defined(XEMACS_ARCH_INDEP) && defined(L10N)
RUN_DEPENDS=	${LOCALBASE}/lib/${DISTNAME}/etc/README:${PORTSDIR}/editors/xemacs
.endif

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS?=	emacs21-[0-9]* emacs22-[0-9]* emacs23-[0-9]* emacs24-[0-9]* \
		emacs-nox11-[0-9]* xemacs-devel-[0-9]* ja-xemacs-devel-* \
		xemacs-common-[0-9]*  xemacs-devel-common-[0-9]*

XEMACS_REL=	21.4
XEMACS_VER=	21.4.24
XEMACS_ARCH=	${MACHINE_ARCH}--freebsd
XEMACS_INSTALL?=${PORTNAME}
.export XEMACS_INSTALL
XEMACS_SITELISPDIR=	lib/xemacs/site-lisp
.if !defined(L10N)
XEMACS_PACKAGESDIR=	lib/xemacs/xemacs-packages
.else
XEMACS_PACKAGESDIR=	lib/xemacs/mule-packages
.endif

USES=		gmake makeinfo tar:bzip2
INFO_PATH=	lib/xemacs-${XEMACS_VER}/info
USE_CSTD=	gnu89
WITHOUT_SSP=	yes
STRIP=
CFLAGS=         -D__CLANG_MAX_ALIGN_T_DEFINED
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	${XEMACS_ARCH}
CONFIGURE_ARGS=	--site-includes=${LOCALBASE}/include \
		--site-libraries=${LOCALBASE}/lib \
		--with-site-lisp \
		--infopath=${INFOPATH}

.if make(package-noinstall) && ${XEMACS_INSTALL} == xemacs-canna
XEMACS_ARCH_INDEP=	yes
.endif
.if defined(XEMACS_ARCH_INDEP)
PLIST_SUB+=	XEMACS_ARCH_DEP="@comment " XEMACS_ARCH_INDEP=""
.elif !defined(XEMACS_ARCH_INDEP) || defined(L10N)
PLIST_SUB+=	XEMACS_ARCH_DEP="" XEMACS_ARCH_INDEP="@comment "
.else
PLIST_SUB+=	XEMACS_ARCH_DEP="" XEMACS_ARCH_INDEP=""
.endif
PLIST_SUB+=	XEMACS_VER=${XEMACS_VER} XEMACS_ARCH=${XEMACS_ARCH}

.if defined(XEMACS_ARCH_INDEP) || !defined(L10N)
INFO=		cl custom emodules external-widget info internals \
		lispref new-users-guide standards term termcap texinfo \
		widget xemacs-faq xemacs
.endif

ALL_TARGET=	all dist
.if defined(XEMACS_ARCH_INDEP)
INSTALL_TARGET=	install-arch-indep
PKGNAMEPREFIX=	
PORTNAME=	xemacs
PKGNAMESUFFIX=	-common
COMMENT=	The architecuture independent part of XEmacs stable version
CONFLICTS=	emacs21-[0-9]* emacs22-[0-9]* emacs23-[0-9]* emacs24-[0-9]* \
		emacs-nox11-[0-9]* xemacs-[0-9]* xemacs-devel-[0-9]* \
		xemacs-devel-common-[0-9]* ja-xemacs-devel-*
MASTERDIR=	${.CURDIR}
.elif defined(L10N)
INSTALL_TARGET=	install-arch-dep
DEPENDS_ARGS=	-DXEMACS_ARCH_INDEP
.else
MASTERDIR=	${.CURDIR}
.endif
INFOPATH=	${LOCALBASE}/info:${LOCALBASE}/share/texmf-dist/doc/info

SUB_FILES+=	xemacs.desktop
SUB_LIST+=	XEMACS_ICON=${LOCALBASE}/lib/xemacs-${XEMACS_VER}/etc/xemacs-icon.xpm

.include "${MASTERDIR}/Makefile.options.pre"
.include <bsd.port.options.mk>
.include "${MASTERDIR}/Makefile.options.post"
.include <bsd.port.pre.mk>

pre-fetch:
.if ! ${PORT_OPTIONS:M*_GTK}
	@${ECHO_MSG} "If you want to use GTK, please select *_GTK and recompile."
.endif
.if ${PORT_OPTIONS:M*_MOTIF}
.if defined(WANT_LESSTIF)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "If you use MOTIF library lesstif, you might occasionally"
	@${ECHO_MSG} "experience locked-up frames."
	@${ECHO_MSG} "In this case, select *_ATHENA or *_LUCID instead of *_MOTIF"
	@${ECHO_MSG} "and recompile, which will force the use of athena or lucid for"
	@${ECHO_MSG} "scrollbars, dialogs and widgets."
.endif
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Set the environment variable WITHOUT=X11 if you do not"
	@${ECHO_MSG} "want to use X11."
.endif

# fix .so references in a few man pages
pre-configure:
.for f in etc/ctags.1 etc/gnuattach.1 etc/gnuclient.1 etc/gnudoit.1
	@${SED} -e 's/\.1/&.gz/' ${WRKSRC}/${f} > ${WRKDIR}/tmp_zot
	@${MV} ${WRKDIR}/tmp_zot ${WRKSRC}/${f}
.endfor
	(cd ${WRKSRC} && ${LOCALBASE}/bin/autoconf-2.13)

pre-build:
	${FIND} ${WRKSRC} \( -name \*~ -o -name \*.core -o -name \*.elc \) \
		-exec ${RM} -f \{} \;
	${RM} -f ${WRKSRC}/lib-src/DOC* ${WRKSRC}/src/xemacs

post-install:
.if !defined(XEMACS_ARCH_INDEP)
.  for f in b2m ctags ellcc etags gnuclient xemacs-${XEMACS_VER}
	if [ -x ${STAGEDIR}${PREFIX}/bin/${f} ]; then \
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${f}; \
	fi
.  endfor
.elif defined(XEMACS_ARCH_INDEP) || !defined(L10N)
	${MKDIR} ${STAGEDIR}${PREFIX}/${XEMACS_SITELISPDIR}
	${CHMOD} 755 ${STAGEDIR}${PREFIX}/${XEMACS_SITELISPDIR}
	${RM} -f ${STAGEDIR}${PREFIX}/bin/send-pr
.  if ${PORT_OPTIONS:MDESKTOP}
	${INSTALL_DATA} ${WRKDIR}/xemacs.desktop \
		${STAGEDIR}${PREFIX}/share/applications
.  endif
.endif
.if !defined(XEMACS_ARCH_INDEP)
.  if defined(L10N) && ${L10N} == ja
	${MKDIR} ${STAGEDIR}${PREFIX}/man/ja/man1
	${INSTALL_MAN} ${WRKSRC}/etc/xemacs-ja.1 \
		${STAGEDIR}${PREFIX}/man/ja/man1/xemacs.1
	${MKDIR} ${STAGEDIR}${PREFIX}/${XEMACS_PACKAGESDIR}/etc/app-defaults
	${LN} -sf ja \
		${STAGEDIR}${PREFIX}/${XEMACS_PACKAGESDIR}/etc/app-defaults/${LOCALE}
	${INSTALL_DATA} ${FILESDIR}/Emacs \
		${STAGEDIR}${PREFIX}/${XEMACS_PACKAGESDIR}/etc/app-defaults/ja
.  endif
.endif

.include <bsd.port.post.mk>
