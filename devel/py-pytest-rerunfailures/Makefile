# $FreeBSD: head/devel/py-pytest-rerunfailures/Makefile 506067 2019-07-06 22:04:59Z swills $

PORTNAME=	pytest-rerunfailures
PORTVERSION=	${PY_SPFC_VER}
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Re-run tests to eliminate flaky failures

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=3.8:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3000
PY_SPFC_VER=	7.0
.else
PY_SPFC_VER=	9.1
.endif

.include <bsd.port.post.mk>
