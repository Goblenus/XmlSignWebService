/// @file
/// @brief ���� �������� ����������� ������� ������ ����������� ��������� ������.
///
/// Copyright (c) InfoTeCS. All Rights Reserved.
#include "stdafx.h"
#include "flag.h"
#include "cmdline-parser.h"

#if defined (__unix__)
#if defined(UNICODE) || defined(_UNICODE)
#define _tcsrchr wcsrchr 
#else
#define _tcsrchr strrchr
#endif
#endif

namespace cmdlineparser{

using flag::operator <<;

CmdLineParser::CmdLineParser():
default_( "set default", "-d", false ),
help_( "print help", "-h", false )
{
}

void CmdLineParser::AddFlag( IFlag * flag )
{
     flags_.push_back( flag->GetImplIface() );
}

void CmdLineParser::RemoveFlag( IFlag * flag )
{
     flags_.remove( flag->GetImplIface() );
}

void CmdLineParser::SetDefault()
{
     for( FlagList::iterator fl = flags_.begin(); fl != flags_.end(); ++fl )
          (*fl)->SetDefault();
}

void CmdLineParser::SetCmdLine( int argc, TCHAR* const argv[] )
{
	assert( argc > 0 && argv != NULL && argv[0] != NULL && "invalid args" );

	SetModuleName( argv[0] );
	--argc; // ������� ��� ���.���������
	if( !argc )
		throw exception::NoArgs(); // ���� ������� ��� ����������
	for( int i = 0; i < argc; ++i )
		args_.push_back( argv[ i + 1 ] ); // ��������� argv ��������� �� ��� ���.���������
}

void CmdLineParser::SetCmdLine( const CmdLineInput& _in )
{
	SetCmdLine( _in.argc, _in.argv );
}

void CmdLineParser::Parse()
{
     help_.Parse( args_ );
     if( help_.GetVal() )
     {
          throw exception::NeedHelp();
     }
     default_.Parse( args_ );
     if( default_.GetVal() )
     {
          SetDefault();
          return;
     }
     for( FlagList::iterator fl = flags_.begin(); fl != flags_.end(); ++fl )
          (*fl)->Parse( args_ );
}

void CmdLineParser::PrintHelp() const
{
     printf( "Usage:  %s flags\n", moduleName_.c_str() );
     printf( "list of availible flags:\n" );
     std::cout<<&help_<<&default_;
     for( FlagList::const_iterator fl = flags_.begin(); fl != flags_.end(); ++fl )
           std::cout<<( *fl );
}

void CmdLineParser::SetModuleName( const char* fullName )
{
	const TCHAR * p = NULL;
	if( ( p = _tcsrchr( fullName, '\\' )) 
	||  ( p = _tcsrchr( fullName, '/'  )) )
	{
		moduleName_.assign( ++p );
		return;
	}
	moduleName_.assign( fullName );
}

} // namespace cmdlineparser
