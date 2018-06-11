#
# Provide support for ports requiring XEmacs.  This includes flavors with proper
# dependencies and useful variables.
#
# Feature:		xemacs
# Usage:		USES=xemacs
#
# XEmacs will be added to RUN_DEPENDS.  XEMACS_NO_RUN_DEPENDS can be set to prevent
# XEmacs dependence.
#
#
# Variables, which can be set in make.conf:
# DEFAULT_VERSIONS+=          The default flavor for XEmacs ports can be added to
#                             DEFAULT_VERSIONS.  For example,
#                             DEFAULT_VERSIONS+= xemacs=devel
#                             Valid flavors: basic canna devel devel_canna
#
# Variables, which can be set by ports:
# XEMACS_NO_RUN_DEPENDS:      Do NOT add run dependence on XEmacs.
#
# Variables, which can be read by ports:
# XEMACS_CMD:                 XEmacs command with full path (e.g. /usr/local/bin/xemacs-21.4.24)
# XEMACS_FLAVOR:              Used for dependencies
# XEMACS_LIBDIR:              XEmacs Library directory without ${PREFIX} (e.g. lib/xemacs)
# XEMACS_LIBDIR_WITH_VER:     Library directory without ${PREFIX} including version (e.g. lib/xemacs-21.4.24)
# XEPKG_AUTOPLIST:            Generate packing list for XEmacs based port automatically (default: yes)
# XEMACS_PACKAGESDIR:         Xemacsen's package installed base directory (e.g. lib/xemacs/mule-packages)
#-------------------------------------------------------------------------------
#
# MAINTAINER:	xemacs@TrueFC.org

.if !defined(_INCLUDE_USES_XEMACS_MK)
_INCLUDE_USES_XEMACS_MK=	yes

.if defined(XEMACS_DEFAULT) && ! empty(XEMACS_DEFAULT)
.  if ${XEMACS_DEFAULT} == basic
DEFAULT_XEMACS_PORT=	xemacs
.  elif ${XEMACS_DEFAULT} == devel
DEFAULT_XEMACS_PORT=	xemacs-devel
.  elif ${XEMACS_DEFAULT} == canna
DEFAULT_XEMACS_PORT=	xemacs-canna
.  elif ${XEMACS_DEFAULT} == devel_canna
DEFAULT_XEMACS_PORT=	xemacs-devel-canna
.  else
DEFAULT_XEMACS_PORT=	xemacs
.  endif
.else
DEFAULT_XEMACS_PORT=	xemacs
.endif

_XEMACSENS=		xemacs \
			xemacs-devel \
			xemacs-canna \
			xemacs-devel-canna

.if defined(XEMACS_INSTALL)
.  if ${_XEMACSENS:M${XEMACS_INSTALL}}
.    if ${XEMACS_INSTALL} == xemacs-devel || \
        ${XEMACS_INSTALL} == xemacs-devel-canna
XEMACS_PORT_NAME=	xemacs-devel
.    else
XEMACS_PORT_NAME=	xemacs
.    endif
XEMACS_NO_RUN_DEPENDS=	yes
.  else
IGNORE=			Installing XEmacs name is strange or empty
XEMACS_NO_RUN_DEPENDS=	yes
.  endif
.else
.  if !defined(XEMACS_NO_RUN_DEPENDS)
.    if !defined(XEMACS_PORT_NAME) || empty(XEMACS_PORT_NAME)
XEMACS_PORT_NAME!=	{ ${PKG_QUERY} -g "%o" 'xemacs-*' 2>/dev/null || : ; } \
	| while read origin; do \
		case $${origin} in \
		editors/xemacs) \
			${ECHO_CMD} -n "xemacs"; \
			break; \
			;; \
		editors/xemacs-devel) \
			${ECHO_CMD} -n "xemacs-devel"; \
			break; \
			;; \
		japanese/xemacs-canna) \
			${ECHO_CMD} -n "xemacs"; \
			break; \
			;; \
		japanese/xemacs-devel-canna) \
			${ECHO_CMD} -n "xemacs-devel"; \
			break; \
			;; \
		*) \
			${ECHO_CMD} -n "irregular"; \
			break; \
			;; \
			esac; \
	done
.      if ${XEMACS_PORT_NAME} != xemacs && ${XEMACS_PORT_NAME} != xemacs-devel

IGNORE=			There is NO XEmacs installed yet. If you force to install, define XEMACS_NO_RUN_DEPENDS
XEMACS_NO_RUN_DEPENDS=	yes
.      elif ${XEMACS_PORT_NAME} == irregular || empty(XEMACS_PORT_NAME)
IGNORE=			Installed XEmacs is irregular one
XEMACS_NO_RUN_DEPENDS=	yes
.      endif
.    endif
.  else
XEMACS_PORT_NAME=	${DEFAULT_XEMACS_PORT}
.  endif
.endif

# Check this port is mule or not
_XEMACS_LATIN1_PACKAGES_NAMES=	c-support \
			cc-mode \
			debug \
			dired \
			edit-utils \
			efs \
			fsf-compat \
			mail-lib \
			net-utils \
			os-utils \
			prog-modes \
			text-modes \
			time \
			xemacs-base \
			xemacs-devel
_XEMACS_MULE_PACKAGES_NAMES=	ddskk \
			edict \
			egg-its \
			latin-euro-standards \
			latin-unity \
			leim \
			locale \
			lookup \
			mule-base \
			mule-ucs
_XEMACS_MISC_PACKAGES_NAMES=	Sun \
			ada \
			apel \
			auctex \
			bbdb \
			build \
			calc \
			calendar \
			cedet-common \
			clearcase \
			cogre \
			cookie \
			crisp \
			dictionary \
			docbookide \
			easypg \
			ecb \
			ecrypto \
			ede \
			ediff \
			edt \
			eieio \
			elib \
			emerge \
			erc \
			escreen \
			eshell \
			ess \
			eterm \
			eudc \
			flim \
			footnote \
			forms \
			fortran-modes \
			frame-icon \
			games \
			general-docs \
			gnats \
			gnus \
			guided-tour \
			haskell-mode \
			hm--html-menus \
			hyperbole \
			ibuffer \
			idlwave \
			igrep \
			ilisp \
			ispell \
			jde \
			liece \
			mailcrypt \
			mew \
			mercurial \
			mh-e \
			mine \
			misc-games \
			mmm-mode \
			ocaml \
			oo-browser \
			pc \
			pcl-cvs \
			pcomplete \
			perl-modes \
			pgg \
			ps-print \
			psgml-dtds \
			psgml \
			python-modes \
			re-builder \
			reftex \
			riece \
			rmail \
			ruby-modes \
			sasl \
			scheme \
			sdoc-mode \
			semi \
			semantic \
			sgml \
			sh-script \
			sieve \
			slider \
			sml-mode \
			sounds-au \
			sounds-wav \
			speedbar \
			strokes \
			supercite \
			texinfo \
			textools \
			tm \
			tooltalk \
			tpu \
			tramp \
			vc-cc \
			vc \
			vhdl \
			view-process \
			viper \
			vm \
			w3 \
			w3m \
			wl \
			x-symbol \
			xetla \
			xlib \
			xslide \
			xslt-process \
			xwem \
			zenirc
_XEMACS_META_PACKAGES_NAMES=	latin1 \
			mule \
			misc
_XEMACS_ALL_PACKAGES_NAMES=	${_XEMACS_LATIN1_PACKAGES_NAMES} \
			${_XEMACS_MULE_PACKAGES_NAMES} \
			${_XEMACS_MISC_PACKAGES_NAMES} \
			${_XEMACS_META_PACKAGES_NAMES}

.if ${_XEMACS_ALL_PACKAGES_NAMES:M${PORTNAME}}
.  if ${_XEMACS_MULE_PACKAGES_NAMES:M${PORTNAME}}
XEPKG_HAS_MULE=	yes
.  else
.    undef XEPKG_HAS_MULE
.  endif
.  if ${_XEMACS_META_PACKAGES_NAMES:M${PORTNAME}}
XEPKG_METAPORT=	yes
.  else
.    undef XEPKG_METAPORT
.  endif
.else
IGNORE=			Unknown XEmacs package name: ${PORTNAME}
.endif

# XEmacs-21.x
.if ${XEMACS_PORT_NAME} == xemacs
XEMACS_NAME=		xemacs
XEMACS_VER=		21.4.24
XEMACS_MAJOR_VER=	21
PKGNAMESUFFIX=
XEMACS_LIBDIR?=		lib/${XEMACS_NAME}
XEMACS_LIBDIR_WITH_VER?=lib/${XEMACS_NAME}-${XEMACS_VER}
.  if defined(XEPKG_HAS_MULE)
XEMACS_PACKAGESDIR?=	${XEMACS_LIBDIR}/mule-packages
.  else
XEMACS_PACKAGESDIR?=	${XEMACS_LIBDIR}/${XEMACS_NAME}-packages
.  endif
XEMACS_PORTSDIR=	${PORTSDIR}/editors/xemacs

# XEmacs-21 development version
.elif ${XEMACS_PORT_NAME} == xemacs-devel
XEMACS_NAME=		xemacs
XEMACS_VER=		21.5-b34
XEMACS_MAJOR_VER=	21
PKGNAMESUFFIX=		-devel
XEMACS_LIBDIR?=		lib/${XEMACS_NAME}
.  if defined(XEPKG_HAS_MULE)
XEMACS_PACKAGESDIR?=	share/${XEMACS_NAME}/mule-packages
.  else
XEMACS_PACKAGESDIR?=	share/${XEMACS_NAME}/${XEMACS_NAME}-packages
.  endif
XEMACS_LIBDIR_WITH_VER?=lib/${XEMACS_NAME}-${XEMACS_VER}
XEMACS_PORTSDIR=	${PORTSDIR}/editors/xemacs-devel
.else
check-makevars::
	@${ECHO} "Makefile error: Bad value of XEMACS_PORT_NAME: ${XEMACS_PORT_NAME}."
	@${ECHO} "Valid values are:"
	@${ECHO} "	XEmacs family: ${_XEMACSENS}"
	@${FALSE}
.endif

#
# Common Definitions
#

# find where emacsen is installed
# look for it in PREFIX first and fall back to LOCALBASE then
.if exists(/bin/${XEMACS_NAME}-${XEMACS_VER})
XEMACS_BASE?=		${PREFIX}
.else
XEMACS_BASE?=		${LOCALBASE}
.endif
# emacsen command-line filename
XEMACS_CMD?=		${XEMACS_BASE}/bin/${XEMACS_NAME}-${XEMACS_VER}

# build&run-dependency
.if !defined(XEMACS_NO_RUN_DEPENDS)
RUN_DEPENDS+=	${XEMACS_CMD}:${XEMACS_PORTSDIR}
.endif

# environments for build
MAKE_ARGS+=		XEMACS=${XEMACS_CMD}
# pkg/PLIST substrings
PLIST_SUB+=		XEMACS_LIBDIR=${XEMACS_LIBDIR} \
			XEMACS_VER=${XEMACS_VER} \
			XEMACS_LIBDIR_WITH_VER=${XEMACS_LIBDIR_WITH_VER}

PKGNAMEPREFIX=		xepkg-
.if defined(XEPKG_METAPORT)
USES=			metaport
.else
XEPKG_AUTOPLIST?=	yes
EXTRACT_SUFX=		.tar.gz
EXTRACT_ONLY=

XEPKGS_BASE_DIR=	${XEMACS_PACKAGESDIR}
XEPKGS_PKGINFO_DIR=	${XEMACS_PACKAGESDIR}/pkginfo
XEPKGS_LISP_DIR=	${XEMACS_PACKAGESDIR}/lisp/${PORTNAME}
XEPKGS_INFO_DIR=	${XEMACS_PACKAGESDIR}/info
XEPKGS_MAN_DIR=		${XEMACS_PACKAGESDIR}/man/${PORTNAME}
XEPKGS_ETC_DIR=		${XEMACS_PACKAGESDIR}/etc/${PORTNAME}

PLIST_SUB+=		PORTVERSION="${PORTVERSION}" \
			XEPKGS_BASE_DIR="${XEPKGS_BASE_DIR}" \
			XEPKGS_PKGINFO_DIR="${XEPKGS_PKGINFO_DIR}" \
			XEPKGS_LISP_DIR="${XEPKGS_LISP_DIR}" \
			XEPKGS_INFO_DIR="${XEPKGS_INFO_DIR}" \
			XEPKGS_MAN_DIR="${XEPKGS_MAN_DIR}" \
			XEPKGS_ETC_DIR="${XEPKGS_ETC_DIR}"

DIST_SUBDIR=		xemacs
.  if defined(DISTFILES)
XEPKGFILES=		${DISTFILES:C/:[^:]+$//}
.  else
DISTNAME=		${PORTNAME}-${PORTVERSION}-pkg
XEPKGFILES=		${DISTNAME}${EXTRACT_SUFX}
.  endif

.  if !target(do-extract)
do-extract:
	@${DO_NADA}
.  endif

.  if !target(do-build)
do-build:
	@${DO_NADA}
.  endif

EXTRACT_AFTER_ARGS+=	-C

.  if !target(do-install)
do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${XEMACS_PACKAGESDIR}
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${XEPKGFILES} \
		${EXTRACT_AFTER_ARGS} ${STAGEDIR}${PREFIX}/${XEMACS_PACKAGESDIR}
.  endif

.  if defined(XEPKG_AUTOPLIST)
.    if !target(post-install-script)
post-install-script:
	@${FIND} -ds ${STAGEDIR}${PREFIX}/${XEMACS_PACKAGESDIR} -type f -print | \
		${SED} -E -e 's,^${STAGEDIR}${PREFIX}/?,,' >> ${TMPPLIST}
.    endif
.  endif
.endif

.endif # _INCLUDE_USES_XEMACS_MK
