#!/bin/sh
#-*- tab-width: 4; -*-
# $FreeBSD$
#
# MAINTAINER: xemacs@FreeBSD.org

set -e

cmdname=`basename $0 .sh`

error() {
	echo 1>&2 "*** ERROR[${1}]:${2}"
	exit 1
}

copy() {
	local	__src=$1 \
			__dest=$2 \
			__src_dir=`dirname $1` \
			__dest_dir=`dirname $2` \
			__src_file=`basename $1` \
			__dest_file=`basename $2`

	if [ ! -f ${__src} ]; then
		error ${cmdname}:copy "soruce file not found"
	fi
	if [ ! -f ${__dest} ]; then
		error ${cmdname}:copy "destination file not found"
	fi
	if [ "${__src_file}" = "${__dest_file}" ]; then
		cp ${__dest_dir}/${__dest_file} ${__dest_dir}/${__dest_file}.org
	fi
	if [ "${__src_dir}" != "${__dest_dir}" ]; then
		cp ${__src} ${__dest}
	fi
}

escape_char() {
	local __str

	__str="`echo \"${1}\" | sed -Ee 's/([+\$*\(\)#&><;|])/\\\\\1/g'`"
	echo "${__str}"
}

glob_csh() {
	csh -c "echo $*" 2> /dev/null
}

if [ -z "${ENCODING_FILES}" ]; then
	exit 0
fi
encoding=${ENCODING}
case ${encoding} in
[Jj][Ii][Ss])
	conv_args='-j'
	;;
[Ss][Jj][Ii][Ss])
	conv_args='-s'
	;;
[Ee][Uu][Cc]-[Jj][Pp])
	conv_args='-e'
	;;
[Uu][Tt][Ff]-8)
	conv_args='-w'
	;;
*)
	error ${cmdname} "wrong \`ENCODING\' name or not specified"
	;;
esac
files_elisp=""
for path in ${ENCODING_FILES}; do
	path=`escape_char ${path}`
	if echo ${path} | egrep -qe ':'; then
		file=${path%%:*}
		path=${path#*:}
		case ${file} in
		*.in)
			file=${file%.in}
			srcdir=${WRKDIR}
			;;
		*)
			srcdir=${FILESDIR}
			;;
		esac
		destfile=${DESTDIR}/${path}
		copy ${destfile} ${destfile}
		nkf ${conv_args} ${srcdir}/${file} > ${destfile}
	else
		file=`basename ${path}`
		srcdir=`dirname ${DESTDIR}/${path}`
		destdir=${srcdir}
		srcfiles=`glob_csh ${srcdir}/${file}`
		for srcfile in ${srcfiles}; do
			file=`basename ${srcfile}`
			case ${file} in
			*.jis)
				destfile=${destdir}/${file%.jis}
				case ${encoding} in
				[Ss][Jj][Ii][Ss]|[Ee][Uu][Cc]-[Jj][Pp]|[Uu][Tt][Ff]-8)
					conv_cmdline="nkf ${conv_args} ${srcfile} > ${destfile}"
					;;
				*)
					conv_cmdline="cp ${srcfile} ${destfile}"
					;;
				esac
				;;
			*.sjis)
				destfile=${destdir}/${file%.sjis}
				case ${encoding} in
				[Jj][Ii][Ss]|[Ee][Uu][Cc]-[Jj][Pp]|[Uu][Tt][Ff]-8)
					conv_cmdline="nkf ${conv_args} ${srcfile} > ${destfile}"
					;;
				*)
					conv_cmdline="cp ${srcfile} ${destfile}"
					;;
				esac
				;;
			*.euc)
				destfile=${destdir}/${file%.euc}
				case ${encoding} in
				[Jj][Ii][Ss]|[Ss][Jj][Ii][Ss]|[Uu][Tt][Ff]-8)
					conv_cmdline="nkf ${conv_args} ${srcfile} > ${destfile}"
					;;
				*)
					conv_cmdline="cp ${srcfile} ${destfile}"
					;;
				esac
				;;
			*.utf8)
				destfile=${destdir}/${file%.utf8}
				case ${encoding} in
				[Jj][Ii][Ss]|[Ss][Jj][Ii][Ss]|[Ee][Uu][Cc]-[Jj][Pp])
					conv_cmdline="nkf ${conv_args} ${srcfile} > ${destfile}"
					;;
				*)
					conv_cmdline="cp ${srcfile} ${destfile}"
					;;
				esac
				;;
			*.el)
				destfile=${destdir}/${file}
				if [ -z "${files_elisp}" ]; then
					files_elisp=${destfile}
				else
					files_elisp="${files_elisp} ${destfile}"
				fi
				conv_cmdline="nkf ${conv_args} --in-place ${destfile}"
				;;
			*)
				destfile=${destdir}/${file}
				conv_cmdline="nkf ${conv_args} --in-place ${destfile}"
				;;
			esac
			copy ${srcfile} ${destfile}
			eval ${conv_cmdline}
		done
	fi
done
for file_elisp in ${files_elisp}; do
	rm -f ${file_elisp%.el}.elc
#	${EMACS_CMD} -q -no-site-file -l un-define -eval '(set-language-environment "Japanese")' -eval "(prefer-coding-system 'utf-8)" -eval "(set-coding-priority-list '(utf-8))" -eval "(set-coding-category-system 'utf-8 'utf-8)" -eval "(prefer-coding-system 'utf-8)" -eval "(set-default-coding-systems 'utf-8)" -eval "(set-default-buffer-file-coding-system 'utf-8)" -eval "(set-keyboard-coding-system 'utf-8)" -eval "(setq terminal-coding-system 'utf-8)" -eval "(set-default-file-coding-system 'utf-8)" -eval "(set-pathname-coding-system 'utf-8)" -batch -f batch-byte-compile ${file_elisp}
done
