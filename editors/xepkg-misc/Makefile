#-*- mode: makefile; tab-width: 4; -*-
# $FreeBSD$

PORTNAME=				misc
PORTVERSION=			1.0
CATEGORIES=				editors xepkgs

MAINTAINER=				xemacs@FreeBSD.org
COMMENT=				Meta port for miscellaneous XEmacs pacakges

LICENSE=				GPLv2

OPTIONS_DEFAULT=		SOUNDS_AU \
						SOUNDS_WAV \
						CLEARCASE \
						EDE \
						FLIM \
						GNATS \
						PCL_CVS \
						RE_BUILDER \
						SEMI \
						SDOC_MODE \
						VC_CC \
						VC \
						W3M \
						WL \
						APEL \
						BUILD \
						EDIFF \
						EIEIO \
						EMERGE \
						ESCREEN \
						ESHELL \
						FORMS \
						FRAME_ICON \
						IBUFFER \
						IDLWAVE \
						IGREP \
						ILISP \
						MERCURIAL \
						MMM_MODE \
						PCOMPLETE \
						SLIDER \
						SML_MODE \
						SPEEDBAR \
						TM \
						TPU \
						XETLA \
						CRISP \
						EDT \
						ETERM \
						PC \
						VIPER \
						GAMES \
						MINE \
						MISC_GAMES \
						COGRE \
						ERC \
						RIECE \
						ZENIRC \
						JDE \
						ADA \
						ELIB \
						FORTRAN_MODES \
						HASKELL_MODE \
						OCAML \
						PERL_MODES \
						PYTHON_MODES \
						RUBY_MODES \
						SCHEME \
						SEMANTIC \
						SH_SCRIPT \
						FOOTNOTE \
						MEW \
						MH_E \
						RMAIL \
						SIEVE \
						SUPERCITE \
						VM \
						CALC \
						SUN \
						CALENDAR \
						CEDET_COMMON \
						COOKIE \
						DICTIONARY \
						EUDC \
						GENERAL_DOCS \
						GUIDED_TOUR \
						HYPERBOLE \
						ISPELL \
						STROKES \
						TOOLTALK \
						VHDL \
						TRAMP \
						GNUS \
						PS_PRINT \
						EASYPG \
						ECRYPTO \
						MAILCRYPT \
						PGG \
						SASL \
						AUCTEX \
						DOCBOOKIDE \
						PSGML_DTDS \
						PSGML \
						REFTEX \
						SGML \
						TEXINFO \
						TEXTOOLS \
						X_SYMBOL \
						XSLIDE \
						XSLT_PROCESS \
						ECB \
						HM__HTML_MENUS \
						OO_BROWSER \
						VIEW_PROCESS \
						W3 \
						XLIB \
						XWEM

OPTIONS_GROUP=			AUDIO
OPTIONS_GROUP_AUDIO=	SOUNDS_AU \
						SOUNDS_WAV
AUDIO_DESC=				Audio utilities - most require a supported sound card.
SOUNDS_AU_DESC=			XEmacs Sun sound files
SOUNDS_WAV_DESC=		XEmacs Microsoft sound files
SOUNDS_AU_RUN_DEPENDS=	xepkg-sounds-au${PKGNAMESUFFIX}>=1.12:${PORTSDIR}/audio/xepkg-sounds-au
SOUNDS_WAV_RUN_DEPENDS=	xepkg-sounds-wav${PKGNAMESUFFIX}>=1.12:${PORTSDIR}/audio/xepkg-sounds-wav

OPTIONS_GROUP+=			DEVEL
OPTIONS_GROUP_DEVEL=	CLEARCASE \
						EDE \
						GNATS \
						MERCURIAL \
						PCL_CVS \
						RE_BUILDER \
						VC_CC \
						VC
DEVEL_DESC=				Software development utilities and libraries.
CLEARCASE_DESC=			New Clearcase Version Control for XEmacs (UNIX, Windows)
EDE_DESC=				Emacs Development Environment
GNATS_DESC=				XEmacs bug reports
MERCURIAL_DESC=			Support for the Mercurial distributed SCM
PCL_CVS_DESC=			CVS frontend
RE_BUILDER_DESC=		Interactive development tool for regular expressions
VC_CC_DESC=				Version Control for ClearCase (UnFree) systems
VC_DESC=				Version Control for Free systems
CLEARCASE_RUN_DEPENDS=	xepkg-clearcase${PKGNAMESUFFIX}>=1.10:${PORTSDIR}/devel/xepkg-clearcase
EDE_RUN_DEPENDS=		xepkg-ede${PKGNAMESUFFIX}>=1.03:${PORTSDIR}/devel/xepkg-ede
GNATS_RUN_DEPENDS=		xepkg-gnats${PKGNAMESUFFIX}>=1.17:${PORTSDIR}/devel/xepkg-gnats
MERCURIAL_RUN_DEPENDS=	xepkg-mercurial${PKGNAMESUFFIX}>=1.10:${PORTSDIR}/devel/xepkg-mercurial
PCL_CVS_RUN_DEPENDS=	xepkg-pcl-cvs${PKGNAMESUFFIX}>=1.70:${PORTSDIR}/devel/xepkg-pcl-cvs
RE_BUILDER_RUN_DEPENDS=	xepkg-re-builder${PKGNAMESUFFIX}>=1.05:${PORTSDIR}/devel/xepkg-re-builder
VC_CC_RUN_DEPENDS=		xepkg-vc-cc${PKGNAMESUFFIX}>=1.22:${PORTSDIR}/devel/xepkg-vc-cc
VC_RUN_DEPENDS=			xepkg-vc${PKGNAMESUFFIX}>=1.48:${PORTSDIR}/devel/xepkg-vc

OPTIONS_GROUP+=			EDITORS
OPTIONS_GROUP_EDITORS=	APEL \
						BUILD \
						EDIFF \
						EIEIO \
						EMERGE \
						ESCREEN \
						ESHELL \
						FLIM \
						FORMS \
						FRAME_ICON \
						IBUFFER \
						IDLWAVE \
						IGREP \
						ILISP \
						MMM_MODE \
						PCOMPLETE \
						SEMI \
						SLIDER \
						SML_MODE \
						SPEEDBAR \
						TM \
						TPU \
						XETLA
EDITORS_DESC=			Common text editors.
APEL_DESC=				A Portable Emacs Library used by XEmacs MIME support
BUILD_DESC=				Build XEmacs from within UNIX or Windows
EDIFF_DESC=				Interface over GNU patch
EIEIO_DESC=				Enhanced Implementation of Emacs Interpreted Objects
EMERGE_DESC=			Another interface over GNU patch
ESCREEN_DESC=			Multiple editing sessions within a single frame (like screen)
ESHELL_DESC=			Command shell implemented entirely in Emacs Lisp
FLIM_DESC=				Faithful Library about Internet Message
FORMS_DESC=				Forms editing support (obsolete, use Widget instead)
FRAME_ICON_DESC=		Set up mode-specific icons for each frame under XEmacs
IBUFFER_DESC=			Advanced replacement for buffer-menu
IDLWAVE_DESC=			Editing and Shell mode for the Interactive Data Language
IGREP_DESC=				Enhanced front-end for Grep
ILISP_DESC=				Front-end for Inferior Lisp
MMM_MODE_DESC=			Multiple major modes in a single buffer
PCOMPLETE_DESC=			Provides programmatic completion
SEMI_DESC=				Secure Emacs MIME Interface
SLIDER_DESC=			User interface tool
SML_MODE_DESC=			SML editing support
SPEEDBAR_DESC=			Provides a separate frame with convenient references
TM_DESC=				Emacs MIME support not needed for gnus >= 5.8.0
TPU_DESC=				DEC EDIT/TPU support
XETLA_DESC=				(S)XEmacs Frontend to GNU/arch (tla)
APEL_RUN_DEPENDS=		xepkg-apel${PKGNAMESUFFIX}>=1.34:${PORTSDIR}/editors/xepkg-apel
BUILD_RUN_DEPENDS=		xepkg-build${PKGNAMESUFFIX}>=1.15:${PORTSDIR}/editors/xepkg-build
EDIFF_RUN_DEPENDS=		xepkg-ediff${PKGNAMESUFFIX}>=1.81:${PORTSDIR}/editors/xepkg-ediff
EIEIO_RUN_DEPENDS=		xepkg-eieio${PKGNAMESUFFIX}>=1.07:${PORTSDIR}/editors/xepkg-eieio
EMERGE_RUN_DEPENDS=		xepkg-emerge${PKGNAMESUFFIX}>=1.11:${PORTSDIR}/editors/xepkg-emerge
ESCREEN_RUN_DEPENDS=	xepkg-escreen${PKGNAMESUFFIX}>=1.01:${PORTSDIR}/editors/xepkg-escreen
ESHELL_RUN_DEPENDS=		xepkg-eshell${PKGNAMESUFFIX}>=1.18:${PORTSDIR}/editors/xepkg-eshell
FLIM_RUN_DEPENDS=		xepkg-flim${PKGNAMESUFFIX}>=1.10:${PORTSDIR}/editors/xepkg-flim
FORMS_RUN_DEPENDS=		xepkg-forms${PKGNAMESUFFIX}>=1.15:${PORTSDIR}/editors/xepkg-forms
FRAME_ICON_RUN_DEPENDS=	xepkg-frame-icon${PKGNAMESUFFIX}>=1.11:${PORTSDIR}/editors/xepkg-frame-icon
IBUFFER_RUN_DEPENDS=	xepkg-ibuffer${PKGNAMESUFFIX}>=1.10:${PORTSDIR}/editors/xepkg-ibuffer
IDLWAVE_RUN_DEPENDS=	xepkg-idlwave${PKGNAMESUFFIX}>=1.32:${PORTSDIR}/editors/xepkg-idlwave
IGREP_RUN_DEPENDS=		xepkg-igrep${PKGNAMESUFFIX}>=1.16:${PORTSDIR}/editors/xepkg-igrep
ILISP_RUN_DEPENDS=		xepkg-ilisp${PKGNAMESUFFIX}>=1.36:${PORTSDIR}/editors/xepkg-ilisp
MMM_MODE_RUN_DEPENDS=	xepkg-mmm-mode${PKGNAMESUFFIX}>=1.05:${PORTSDIR}/editors/xepkg-mmm-mode
PCOMPLETE_RUN_DEPENDS=	xepkg-pcomplete${PKGNAMESUFFIX}>=1.06:${PORTSDIR}/editors/xepkg-pcomplete
SEMI_RUN_DEPENDS=		xepkg-semi${PKGNAMESUFFIX}>=1.10:${PORTSDIR}/editors/xepkg-semi
SLIDER_RUN_DEPENDS=		xepkg-slider${PKGNAMESUFFIX}>=1.16:${PORTSDIR}/editors/xepkg-slider
SML_MODE_RUN_DEPENDS=	xepkg-sml-mode${PKGNAMESUFFIX}>=0.12:${PORTSDIR}/editors/xepkg-sml-mode
SPEEDBAR_RUN_DEPENDS=	xepkg-speedbar${PKGNAMESUFFIX}>=1.29:${PORTSDIR}/editors/xepkg-speedbar
TM_RUN_DEPENDS=			xepkg-tm${PKGNAMESUFFIX}>=1.39:${PORTSDIR}/editors/xepkg-tm
TPU_RUN_DEPENDS=		xepkg-tpu${PKGNAMESUFFIX}>=1.14:${PORTSDIR}/editors/xepkg-tpu
XETLA_RUN_DEPENDS=		xepkg-xetla${PKGNAMESUFFIX}>=1.02:${PORTSDIR}/editors/xepkg-xetla

OPTIONS_GROUP+=			EMULATORS
OPTIONS_GROUP_EMULATORS=	CRISP \
						EDT \
						ETERM \
						PC \
						VIPER
EMULATORS_DESC=			Utilities for emulating other OS types.
CRISP_DESC=				Crisp/Brief emulation
EDT_DESC=				DEC EDIT/EDT emulation
ETERM_DESC=				Terminal emulation
PC_DESC=				PC style interface emulation
VIPER_DESC=				VI emulation support
CRISP_RUN_DEPENDS=		xepkg-crisp${PKGNAMESUFFIX}>=1.15:${PORTSDIR}/emulators/xepkg-crisp
EDT_RUN_DEPENDS=		xepkg-edt${PKGNAMESUFFIX}>=1.14:${PORTSDIR}/emulators/xepkg-edt
ETERM_RUN_DEPENDS=		xepkg-eterm${PKGNAMESUFFIX}>=1.18:${PORTSDIR}/emulators/xepkg-eterm
PC_RUN_DEPENDS=			xepkg-pc${PKGNAMESUFFIX}>=1.28:${PORTSDIR}/emulators/xepkg-pc
VIPER_RUN_DEPENDS=		xepkg-viper${PKGNAMESUFFIX}>=1.67:${PORTSDIR}/emulators/xepkg-viper

OPTIONS_GROUP+=			GAMES
OPTIONS_GROUP_GAMES=	GAMES \
						MINE \
						MISC_GAMES
GAMES_DESC=				Various and sundry amusements.
GAMES_DESC=				Tetris, Sokoban, and Snake
MINE_DESC=				Minehunt Game
MISC_GAMES_DESC=		Other amusements and diversions
GAMES_RUN_DEPENDS=		xepkg-games${PKGNAMESUFFIX}>=1.20:${PORTSDIR}/games/xepkg-games
MINE_RUN_DEPENDS=		xepkg-mine${PKGNAMESUFFIX}>=1.16:${PORTSDIR}/games/xepkg-mine
MISC_GAMES_RUN_DEPENDS=	xepkg-misc-games${PKGNAMESUFFIX}>=1.22:${PORTSDIR}/games/xepkg-misc-games

OPTIONS_GROUP+=			GRAPHICS
OPTIONS_GROUP_GRAPHICS=	COGRE
GRAPHICS_DESC=			Graphics libraries and utilities.
COGRE_DESC=				Graph editing mode
COGRE_RUN_DEPENDS=		xepkg-cogre${PKGNAMESUFFIX}>=1.02:${PORTSDIR}/graphics/xepkg-cogre

OPTIONS_GROUP+=			IRC
OPTIONS_GROUP_IRC=		ERC \
						RIECE \
						ZENIRC
IRC_DESC=				Internet Relay Chat utilities.
ERC_DESC=				ERC is an Emacs InternetRelayChat client
RIECE_DESC=				IRC (Internet Relay Chat) client for Emacs
ZENIRC_DESC=			ZENIRC IRC Client
ERC_RUN_DEPENDS=		xepkg-erc${PKGNAMESUFFIX}>=0.23:${PORTSDIR}/irc/xepkg-erc
RIECE_RUN_DEPENDS=		xepkg-riece${PKGNAMESUFFIX}>=1.23:${PORTSDIR}/irc/xepkg-riece
ZENIRC_RUN_DEPENDS=		xepkg-zenirc${PKGNAMESUFFIX}>=1.16:${PORTSDIR}/irc/xepkg-zenirc

OPTIONS_GROUP+=			JAVA
OPTIONS_GROUP_JAVA=		JDE
JAVA_DESC=				Java language support.
JDE_DESC=				Integrated Development Environment for Java
JDE_RUN_DEPENDS=		xepkg-jde${PKGNAMESUFFIX}>=1.52:${PORTSDIR}/java/xepkg-jde

OPTIONS_GROUP+=			LANG
OPTIONS_GROUP_LANG=		ADA \
						ELIB \
						FORTRAN_MODES \
						HASKELL_MODE \
						OCAML \
						PERL_MODES \
						PYTHON_MODES \
						RUBY_MODES \
						SCHEME \
						SEMANTIC \
						SH_SCRIPT
LANG_DESC=				Computer languages.
ADA_DESC=				Ada language support
ELIB_DESC=				Portable Emacs Lisp utilities library
FORTRAN_MODES_DESC=		Fortran support
HASKELL_MODE_DESC=		Haskell editing support
OCAML_DESC=				Objective Caml editing support
PERL_MODES_DESC=		Perl support
PYTHON_MODES_DESC=		Python support
RUBY_MODES_DESC=		Ruby support
SCHEME_DESC=			Front-end support for Inferior Scheme
SEMANTIC_DESC=			Semantic bovinator (Yacc/Lex for XEmacs) includes Senator
SH_SCRIPT_DESC=			Support for editing shell scripts
ADA_RUN_DEPENDS=		xepkg-ada${PKGNAMESUFFIX}>=1.14:${PORTSDIR}/lang/xepkg-ada
ELIB_RUN_DEPENDS=		xepkg-elib${PKGNAMESUFFIX}>=1.13:${PORTSDIR}/lang/xepkg-elib
FORTRAN_MODES_RUN_DEPENDS=	xepkg-fortran-modes${PKGNAMESUFFIX}>=1.05:${PORTSDIR}/lang/xepkg-fortran-modes
HASKELL_MODE_RUN_DEPENDS=	xepkg-haskell-mode${PKGNAMESUFFIX}>=1.11:${PORTSDIR}/lang/xepkg-haskell-mode
OCAML_RUN_DEPENDS=		xepkg-ocaml${PKGNAMESUFFIX}>=0.06:${PORTSDIR}/lang/xepkg-ocaml
PERL_MODES_RUN_DEPENDS=	xepkg-perl-modes${PKGNAMESUFFIX}>=1.14:${PORTSDIR}/lang/xepkg-perl-modes
PYTHON_MODES_RUN_DEPENDS=	xepkg-python-modes${PKGNAMESUFFIX}>=1.14:${PORTSDIR}/lang/xepkg-python-modes
RUBY_MODES_RUN_DEPENDS=	xepkg-ruby-modes${PKGNAMESUFFIX}>=1.04:${PORTSDIR}/lang/xepkg-ruby-modes
SCHEME_RUN_DEPENDS=		xepkg-scheme${PKGNAMESUFFIX}>=1.18:${PORTSDIR}/lang/xepkg-scheme
SEMANTIC_RUN_DEPENDS=	xepkg-semantic${PKGNAMESUFFIX}>=1.21:${PORTSDIR}/lang/xepkg-semantic
SH_SCRIPT_RUN_DEPENDS=	xepkg-sh-script${PKGNAMESUFFIX}>=1.24:${PORTSDIR}/lang/xepkg-sh-script

OPTIONS_GROUP+=			MAIL
OPTIONS_GROUP_MAIL=		FOOTNOTE \
						MEW \
						MH_E \
						RMAIL \
						SIEVE \
						SUPERCITE \
						VMEDITORS \
						WL
MAIL_DESC=				Electronic mail packages and utilities.
FOOTNOTE_DESC=			Footnoting in mail message editing modes
MEW_DESC=				Messaging in an Emacs World
MH_E_DESC=				The XEmacs Interface to the MH Mail System
RMAIL_DESC=				An obsolete Emacs mailer
SIEVE_DESC=				Manage Sieve email filtering scripts
SUPERCITE_DESC=			An Emacs citation tool for News and Mail messages
VM_DESC=				An Emacs mailer
WL_DESC=				Yet Another Message Interface on Emacsen
FOOTNOTE_RUN_DEPENDS=	xepkg-footnote${PKGNAMESUFFIX}>=1.16:${PORTSDIR}/mail/xepkg-footnote
MEW_RUN_DEPENDS=		xepkg-mew${PKGNAMESUFFIX}>=1.19:${PORTSDIR}/mail/xepkg-mew
MH_E_RUN_DEPENDS=		xepkg-mh-e${PKGNAMESUFFIX}>=1.32:${PORTSDIR}/mail/xepkg-mh-e
RMAIL_RUN_DEPENDS=		xepkg-rmail${PKGNAMESUFFIX}>=1.14:${PORTSDIR}/mail/xepkg-rmail
SIEVE_RUN_DEPENDS=		xepkg-sieve${PKGNAMESUFFIX}>=1.18:${PORTSDIR}/mail/xepkg-sieve
SUPERCITE_RUN_DEPENDS=	xepkg-supercite${PKGNAMESUFFIX}>=1.21:${PORTSDIR}/mail/xepkg-supercite
VM_RUN_DEPENDS=			xepkg-vm${PKGNAMESUFFIX}>=8.08:${PORTSDIR}/mail/xepkg-vm
WL_RUN_DEPENDS=			xepkg-wl${PKGNAMESUFFIX}>=1.10:${PORTSDIR}/mail/xepkg-wl

OPTIONS_GROUP+=			MATH
OPTIONS_GROUP_MATH=		CALC
MATH_DESC=				Mathematical computation software.
CALC_DESC=				Emacs calculator
CALC_RUN_DEPENDS=		xepkg-calc${PKGNAMESUFFIX}>=1.26:${PORTSDIR}/math/xepkg-calc

OPTIONS_GROUP+=			MISC
OPTIONS_GROUP_MISC=		SUN \
						CALENDAR \
						CEDET_COMMON \
						COOKIE \
						DICTIONARY \
						EUDC \
						GENERAL_DOCS \
						GUIDED_TOUR \
						HYPERBOLE \
						ISPELL \
						STROKES \
						TOOLTALK \
						VHDL
MISC_DESC=				Miscellaneous utilities.
SUN_DESC=				Support for Sparcworks
CALENDAR_DESC=			Calendar and diary support
CEDET_COMMON_DESC=		Common files for CEDET development environment
COOKIE_DESC=			Spook and Yow (Zippy quotes)
DICTIONARY_DESC=		Interface to RFC2229 dictionary servers
EUDC_DESC=				Emacs Unified Directory Client (LDAP, PH)
GENERAL_DOCS_DESC=		General XEmacs documentation
GUIDED_TOUR_DESC=		Phil Sung's Guided Tour of Emacs
HYPERBOLE_DESC=			The Everyday Info Manager
ISPELL_DESC=			Spell-checking with GNU ispell
STROKES_DESC=			Mouse enhancement utility
TOOLTALK_DESC=			Support for building with Tooltalk
VHDL_DESC=				Support for VHDL
SUN_RUN_DEPENDS=		xepkg-Sun${PKGNAMESUFFIX}>=1.16:${PORTSDIR}/misc/xepkg-Sun
CALENDAR_RUN_DEPENDS=	xepkg-calendar${PKGNAMESUFFIX}>=1.38:${PORTSDIR}/misc/xepkg-calendar
CEDET_COMMON_RUN_DEPENDS=	xepkg-cedet-common${PKGNAMESUFFIX}>=1.01:${PORTSDIR}/misc/xepkg-cedet-common
COOKIE_RUN_DEPENDS=		xepkg-cookie${PKGNAMESUFFIX}>=1.15:${PORTSDIR}/misc/xepkg-cookie
DICTIONARY_RUN_DEPENDS=	xepkg-dictionary${PKGNAMESUFFIX}>=1.16:${PORTSDIR}/misc/xepkg-dictionary
EUDC_RUN_DEPENDS=		xepkg-eudc${PKGNAMESUFFIX}>=1.40:${PORTSDIR}/misc/xepkg-eudc
GENERAL_DOCS_RUN_DEPENDS=	xepkg-general-docs${PKGNAMESUFFIX}>=1.06:${PORTSDIR}/misc/xepkg-general-docs
GUIDED_TOUR_RUN_DEPENDS=xepkg-guided-tour${PKGNAMESUFFIX}>=0.52:${PORTSDIR}/misc/xepkg-guided-tour
HYPERBOLE_RUN_DEPENDS=	xepkg-hyperbole${PKGNAMESUFFIX}>=1.17:${PORTSDIR}/misc/xepkg-hyperbole
ISPELL_RUN_DEPENDS=		xepkg-ispell${PKGNAMESUFFIX}>=1.32:${PORTSDIR}/misc/xepkg-ispell
STROKES_RUN_DEPENDS=	xepkg-strokes${PKGNAMESUFFIX}>=1.10:${PORTSDIR}/misc/xepkg-strokes
TOOLTALK_RUN_DEPENDS=	xepkg-tooltalk${PKGNAMESUFFIX}>=1.15:${PORTSDIR}/misc/xepkg-tooltalk
VHDL_RUN_DEPENDS=		xepkg-vhdl${PKGNAMESUFFIX}>=1.22:${PORTSDIR}/misc/xepkg-vhdl

OPTIONS_GROUP+=			NET
OPTIONS_GROUP_NET=		TRAMP
NET_DESC=				Networking utilities.
TRAMP_DESC=				Remote shell-based file editing
TRAMP_RUN_DEPENDS=		xepkg-tramp${PKGNAMESUFFIX}>=1.40:${PORTSDIR}/net/xepkg-tramp

OPTIONS_GROUP+=			NEWS
OPTIONS_GROUP_NEWS=		GNUS
NEWS_DESC=				USENET News support software.
GNUS_DESC=				The Gnus Newsreader and Mailreader
GNUS_RUN_DEPENDS=		xepkg-gnus${PKGNAMESUFFIX}>=1.94:${PORTSDIR}/news/xepkg-gnus

OPTIONS_GROUP+=			PRINT
OPTIONS_GROUP_PRINT=	PS_PRINT
PRINT_DESC=				Utilities for dealing with printing.
PS_PRINT_DESC=			Printing functions and utilities
PS_PRINT_RUN_DEPENDS=	xepkg-ps-print${PKGNAMESUFFIX}>=1.12:${PORTSDIR}/print/xepkg-ps-print

OPTIONS_GROUP+=			SECURITY
OPTIONS_GROUP_SECURITY=	EASYPG \
						ECRYPTO \
						MAILCRYPT \
						PGG \
						SASL
SECURITY_DESC=			System security software.
EASYPG_DESC=			GnuPG interface for Emacs
ECRYPTO_DESC=			Crypto functionality in Emacs Lisp
MAILCRYPT_DESC=			Support for messaging encryption with PGP
PGG_DESC=				Emacs interface to various PGP implementations
SASL_DESC=				Simple Authentication and Security Layer (SASL) library
EASYPG_RUN_DEPENDS=		xepkg-easypg${PKGNAMESUFFIX}>=1.03:${PORTSDIR}/security/xepkg-easypg
ECRYPTO_RUN_DEPENDS=	xepkg-ecrypto${PKGNAMESUFFIX}>=0.21:${PORTSDIR}/security/xepkg-ecrypto
MAILCRYPT_RUN_DEPENDS=	xepkg-mailcrypt${PKGNAMESUFFIX}>=2.14:${PORTSDIR}/security/xepkg-mailcrypt
PGG_RUN_DEPENDS=		xepkg-pgg${PKGNAMESUFFIX}>=1.07:${PORTSDIR}/security/xepkg-pgg
SASL_RUN_DEPENDS=		xepkg-sasl${PKGNAMESUFFIX}>=1.16:${PORTSDIR}/security/xepkg-sasl

OPTIONS_GROUP+=			TEXTPROC
OPTIONS_GROUP_TEXTPROC=	AUCTEX \
						DOCBOOKIDE \
						PSGML_DTDS \
						PSGML \
						REFTEX \
						SDOC_MODE \
						SGML \
						TEXINFO \
						TEXTOOLS \
						X_SYMBOL \
						XSLIDE \
						XSLT_PROCESS
TEXTPROC_DESC=			Text processing/search utilities.
AUCTEX_DESC=			Basic TeX/LaTeX support
DOCBOOKIDE_DESC=		DocBook editing support
PSGML_DTDS_DESC=		Deprecated collection of DTDs for psgml
PSGML_DESC=				Validated HTML/SGML editing
REFTEX_DESC=			Emacs support for LaTeX cross-references, citations..
SDOC_MODE_DESC=			SamrtDoc mode
SGML_DESC=				SGML/Linuxdoc-SGML editing
TEXINFO_DESC=			XEmacs TeXinfo support
TEXTOOLS_DESC=			Miscellaneous support for editing text files
X_SYMBOL_DESC=			Semi WYSIWYG for LaTeX, HTML, etc, using additional fonts
XSLIDE_DESC=			XSL editing support
XSLT_PROCESS_DESC=		XSLT processing support
AUCTEX_RUN_DEPENDS=		xepkg-auctex${PKGNAMESUFFIX}>=1.51:${PORTSDIR}/textproc/xepkg-auctex
DOCBOOKIDE_RUN_DEPENDS=	xepkg-docbookide${PKGNAMESUFFIX}>=0.08:${PORTSDIR}/textproc/xepkg-docbookide
PSGML_DTDS_RUN_DEPENDS=	xepkg-psgml-dtds${PKGNAMESUFFIX}>=1.03:${PORTSDIR}/textproc/xepkg-psgml-dtds
PSGML_RUN_DEPENDS=		xepkg-psgml${PKGNAMESUFFIX}>=1.45:${PORTSDIR}/textproc/xepkg-psgml
REFTEX_RUN_DEPENDS=		xepkg-reftex${PKGNAMESUFFIX}>=1.34:${PORTSDIR}/textproc/xepkg-reftex
SDOC_MODE_RUN_DEPENDS=	xepkg-sdoc-mode${PKGNAMESUFFIX}>=1.10:${PORTSDIR}/textproc/xepkg-sdoc-mode
SGML_RUN_DEPENDS=		xepkg-sgml${PKGNAMESUFFIX}>=1.11:${PORTSDIR}/textproc/xepkg-sgml
TEXINFO_RUN_DEPENDS=	xepkg-texinfo${PKGNAMESUFFIX}>=1.30:${PORTSDIR}/textproc/xepkg-texinfo
TEXTOOLS_RUN_DEPENDS=	xepkg-textools${PKGNAMESUFFIX}>=1.15:${PORTSDIR}/textproc/xepkg-textools
X_SYMBOL_RUN_DEPENDS=	xepkg-x-symbol${PKGNAMESUFFIX}>=1.11:${PORTSDIR}/textproc/xepkg-x-symbol
XSLIDE_RUN_DEPENDS=		xepkg-xslide${PKGNAMESUFFIX}>=1.09:${PORTSDIR}/textproc/xepkg-xslide
XSLT_PROCESS_RUN_DEPENDS=	xepkg-xslt-process${PKGNAMESUFFIX}>=1.12:${PORTSDIR}/textproc/xepkg-xslt-process

OPTIONS_GROUP+=			WWW
OPTIONS_GROUP_WWW=		ECB \
						HM__HTML_MENUS \
						OO_BROWSER \
						VIEW_PROCESS \
						W3 \
						W3M
WWW_DESC=				WEB utilities (browsers, HTTP servers, etc).
ECB_DESC=				Emacs source code browser
HM__HTML_MENUS_DESC=	HTML editing
OO_BROWSER_DESC=		The Multi-Language Object-Oriented Code Browser
VIEW_PROCESS_DESC=		A Unix process browsing tool
W3_DESC=				A Web browser
W3M_DESC=				An Emacs interface to w3m
ECB_RUN_DEPENDS=		xepkg-ecb${PKGNAMESUFFIX}>=1.22:${PORTSDIR}/www/xepkg-ecb
HM__HTML_MENUS_RUN_DEPENDS=	xepkg-hm--html-menus${PKGNAMESUFFIX}>=1.24:${PORTSDIR}/www/xepkg-hm--html-menus
OO_BROWSER_RUN_DEPENDS=	xepkg-oo-browser${PKGNAMESUFFIX}>=1.05:${PORTSDIR}/www/xepkg-oo-browser
VIEW_PROCESS_RUN_DEPENDS=	xepkg-view-process${PKGNAMESUFFIX}>=1.13:${PORTSDIR}/www/xepkg-view-process
W3_RUN_DEPENDS=			xepkg-w3${PKGNAMESUFFIX}>=1.35:${PORTSDIR}/www/xepkg-w3
W3M_RUN_DEPENDS=		xepkg-w3m${PKGNAMESUFFIX}>=1.10:${PORTSDIR}/www/xepkg-w3m

OPTIONS_GROUP+=			X11
OPTIONS_GROUP_X11=		XLIB
X11_DESC=				X Window System based utilities.
XLIB_DESC=				Emacs interface to X server
XLIB_RUN_DEPENDS=		xepkg-xlib${PKGNAMESUFFIX}>=1.14:${PORTSDIR}/x11/xepkg-xlib

OPTIONS_GROUP+=			X11_WM
OPTIONS_GROUP_X11_WM=	XWEM
X11_WM_DESC=			X Window System window managers.
XWEM_DESC=				X Emacs Window Manager
XWEM_RUN_DEPENDS=		xepkg-xwem${PKGNAMESUFFIX}>=1.23:${PORTSDIR}/x11-wm/xepkg-xwem

USES=					xemacs

.include <bsd.port.mk>
