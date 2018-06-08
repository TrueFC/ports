# Created by: Gary Jennejohn (gj@FreeBSD.org)
# $FreeBSD: head/editors/xemacs/Makefile 359318 2014-06-26 07:32:36Z antoine $

PORTNAME?=	xemacs-devel
PORTVERSION=	${XEMACS_VER:S/-/./}
CATEGORIES?=	editors
MASTER_SITES=	${MASTER_SITE_XEMACS}
MASTER_SITE_SUBDIR=	xemacs-${XEMACS_REL}
DISTNAME=	xemacs-${XEMACS_VER:S/-b/./}
DIST_SUBDIR=	xemacs

MAINTAINER?=	xemacs@FreeBSD.org
COMMENT?=	The beta version of the XEmacs text editor

.if !defined(XEMACS_ARCH_INDEP) && defined(L10N)
RUN_DEPENDS=	${LOCALBASE}/share/xemacs-${XEMACS_VER}/etc/README:${PORTSDIR}/editors/xemacs-devel
.endif

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS?=	emacs21-[0-9]* emacs22-[0-9]* emacs23-[0-9]* emacs24-[0-9]* \
		emacs-nox11-[0-9]* xemacs-[0-9]* ja-xemacs-canna-* \
		xemacs-common-[0-9]* xemacs-devel-common-[0-9]*

XEMACS_REL=	21.5
XEMACS_VER=	${XEMACS_REL}-b34
XEMACS_ARCH=	${MACHINE_ARCH}--freebsd
XEMACS_INSTALL?=${PORTNAME}
.export XEMACS_INSTALL

USE_AUTOTOOLS=	autoconf
USES=		gmake makeinfo
INFO_PATH=	lib/${DISTNAME}/info
USE_CSTD=	gnu99
WITHOUT_SSP=	yes
STRIP=
CFLAGS=         -D__CLANG_MAX_ALIGN_T_DEFINED
CONFIGURE_TARGET=	${XEMACS_ARCH}
CONFIGURE_ARGS=	--with-site-includes=${LOCALBASE}/include \
		--with-site-libraries=${LOCALBASE}/lib \
		--with-site-lisp \
		--with-infopath=${INFOPATH}

.if make(package-noinstall) && ${XEMACS_INSTALL} == xemacs-devel-canna
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
INFO=		beta cl emodules external-widget info internals \
		lispref new-users-guide standards termcap texinfo widget \
		xemacs xemacs-faq
.endif

ALL_TARGET=	all dist
.if defined(XEMACS_ARCH_INDEP)
INSTALL_TARGET=	install-arch-indep
PKGNAMEPREFIX=	
PORTNAME=	xemacs-devel
PKGNAMESUFFIX=	-common
COMMENT=	The architecuture independent part of XEmacs beta version
CONFLICTS=	emacs21-[0-9]* emacs22-[0-9]* emacs23-[0-9]* emacs24-[0-9]* \
		emacs-nox11-[0-9]* xemacs-[0-9]*  xemacs-devel-[0-9]* \
		xemacs-common-[0-9]* ja-xemacs-canna-*
MASTERDIR=	${.CURDIR}
.elif defined(L10N)
INSTALL_TARGET=	install-arch-dep
DEPENDS_ARGS=	-DXEMACS_ARCH_INDEP
.else
MASTERDIR=	${.CURDIR}
.endif
INFOPATH=	${LOCALBASE}/info:${LOCALBASE}/share/texmf-dist/doc/info

.include "${MASTERDIR}/Makefile.options.pre"
.include <bsd.port.options.mk>
.include "${MASTERDIR}/Makefile.options.post"
.include <bsd.port.pre.mk>

pre-fetch:
.if ! ${PORT_OPTIONS:M*_GTK}
	@${ECHO_MSG} "If you want to use GTK, please select *_GTK and recompile."
.endif
.if ${PORT_OPTIONS:M*_MOTIF}
.  if defined(WANT_LESSTIF)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "If you use MOTIF library lesstif, you might occasionally"
	@${ECHO_MSG} "experience locked-up frames."
	@${ECHO_MSG} "In this case, select *_ATHENA or *_LUCID instead of *_MOTIF"
	@${ECHO_MSG} "and recompile, which will force the use of athena or lucid for"
	@${ECHO_MSG} "scrollbars, dialogs and widgets."
.  endif
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

pre-build:
	${FIND} ${WRKSRC} \( -name \*~ -o -name \*.core -o -name \*.elc \) \
		-exec ${RM} -f \{} \;
	${RM} -f ${WRKSRC}/lib-src/DOC* ${WRKSRC}/src/xemacs

.if !defined(XEMACS_ARCH_INDEP)
post-stage:
	${MV} ${STAGEDIR}${PREFIX}/bin/xemacs-${XEMACS_VER}-*.dmp \
		${STAGEDIR}${PREFIX}/bin/xemacs-${XEMACS_VER}.dmp

post-install:
.  for f in b2m ctags etags gnuclient ootags xemacs-${XEMACS_VER}
	if [ -x ${STAGEDIR}${PREFIX}/bin/${f} ]; then \
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${f}; \
	fi
.  endfor
.elif defined(XEMACS_ARCH_INDEP) || !defined(L10N)
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/xemacs/site-lisp
	${CHMOD} 755 ${STAGEDIR}${PREFIX}/lib/xemacs/site-lisp
	${RM} -f ${STAGEDIR}${PREFIX}/bin/send-pr
.endif
.if !defined(XEMACS_ARCH_INDEP)
.  if defined(L10N) && ${L10N} == ja
	${MKDIR} ${STAGEDIR}${PREFIX}/share/xemacs/mule-packages/etc/app-defaults
	${LN} -sf ja \
		${STAGEDIR}${PREFIX}/share/xemacs/mule-packages/etc/app-defaults/${LOCALE}
.  endif
.endif

.include <bsd.port.post.mk>
