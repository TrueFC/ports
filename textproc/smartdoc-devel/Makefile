# New ports collection makefile for:	SmartDoc devel
# Date created:		19 December 2000
# Whom:			KIRIYAMA Kazuhiko <kiri@FreeBSD.org>
#
# $FreeBSD: head/textproc/smartdoc-devel/Makefile 132658 2005-04-06 23:35:41Z hq $
#

PORTNAME=	smartdoc
PORTVERSION=	1.1b
PORTREVISION=   1
CATEGORIES=	textproc java
MASTER_SITES=	http://www.asamioffice.com/ja/2010/smartdoc/download/
DISTFILES=	beta.zip

MAINTAINER=	kiri@OpenEdu.org
COMMENT=	XML utility to create various documents(devel version)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.txt

BUILD_DEPENDS=	xmlcatmgr:textproc/xmlcatmgr
RUN_DEPENDS=	javavm:java/javavmwrapper \
		xmlcatmgr:textproc/xmlcatmgr

NO_BUILD=	yes
USES=		zip
USE_JAVA=	yes
JAVA_EXTRACT=	jre
JAVA_RUN=	jre
EXTRACT_CMD=	${JAVA}
EXTRACT_BEFORE_ARGS=	-jar ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} \
			-batch -bindir:${WRKSRC}/bin -installbasedir:${WRKSRC}
WRKSRC=		${WRKDIR}/sdoc

DTDDIR=		share/xml/${PORTNAME}
PLIST_SUB=	DTDDIR=${DTDDIR}
CATALOG_FILES=	catalog catalog.xml
EMACSLISPDIR=	${LOCALBASE}/share/emacs/site-lisp
XEMACSLISPDIR=	${LOCALBASE}/lib/xemacs/site-lisp

PORTDOCS=	COPYING.txt OroLICENSE.txt README README.sdoc \
		README_en.html README_ja.html \
		XalanLICENSE.txt XercesLICENSE.txt

SUB_FILES=	sdoc.sh pkg-message ${CATALOG_FILES}
SUB_LIST=	DTDDIR=${PREFIX}/${DTDDIR} \
		EMACSLISPDIR=${EMACSLISPDIR} XEMACSLISPDIR=${XEMACSLISPDIR} \
		INSTALL_DATA="${INSTALL_DATA}"
PKGMESSAGE=	${WRKDIR}/pkg-message

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin ${STAGEDIR}${JAVAJARDIR} \
		${STAGEDIR}${PREFIX}/${DTDDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/sdoc.sh ${STAGEDIR}${PREFIX}/bin/sdoc
	cd ${WRKSRC} && \
		${INSTALL_DATA} SmartDoc.jar isorelax.jar jakarta-oro.jar tex2mathml.jar \
				${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/pure/PureSmartDoc.dtd ${STAGEDIR}${PREFIX}/${DTDDIR}
	cd ${WRKDIR} && ${INSTALL_DATA} ${CATALOG_FILES} ${STAGEDIR}${PREFIX}/${DTDDIR}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/doc
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/ ${STAGEDIR}${DOCSDIR}/doc

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/etc
	${CP} -R ${WRKSRC}/etc/ ${STAGEDIR}${EXAMPLESDIR}/etc

.include <bsd.port.mk>
