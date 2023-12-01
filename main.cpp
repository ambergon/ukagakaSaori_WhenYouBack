


#include <windows.h>
#include <iostream>
#include <string>
#include <regex>


//#define Debug

using namespace std;



FILE* ConsoleWindow;
typedef void* HGLOBAL;
char* resBuf;
char* SaoriDirectory;


//{{{
int ZenToHan( string str ){
    //shiftjis
    str = regex_replace( str , regex( "�O" ) ,"0" );
    str = regex_replace( str , regex( "�P" ) ,"1" );
    str = regex_replace( str , regex( "�Q" ) ,"2" );
    str = regex_replace( str , regex( "�R" ) ,"3" );
    str = regex_replace( str , regex( "�S" ) ,"4" );
    str = regex_replace( str , regex( "�T" ) ,"5" );
    str = regex_replace( str , regex( "�U" ) ,"6" );
    str = regex_replace( str , regex( "�V" ) ,"7" );
    str = regex_replace( str , regex( "�W" ) ,"8" );
    str = regex_replace( str , regex( "�X" ) ,"9" );
    str = regex_replace( str , regex( "�@" ) ,"" );
    str = regex_replace( str , regex( " " ) ,"" );
    int res = atoi( str.c_str() );

    return res ;
}
//}}}

//{{{
//チェック用main関数------------------------------------------------
int main() {

    printf( "\n" );

    return 0;
}
//}}}

//{{{
//Load 処理---------------------------------------------------------
extern "C" __declspec(dllexport) bool __cdecl load(HGLOBAL h, long len){
    //hにはdllまでのLogFilePathが入っている。
    //lenはアドレスの長さ。\0の分は入っていない。
#ifdef Debug
    AllocConsole();
    //標準出力(stdout)を新しいコンソールに向ける
    freopen_s(&ConsoleWindow, "CONOUT$", "w+", stdout);
    //標準エラー出力(stderr)を新しいコンソールに向ける
    freopen_s(&ConsoleWindow, "CONOUT$", "w+", stderr);
    //文字コードをutf-8に変更。
    //satoriはshift-jis決め打ちである。
    //system( "chcp 65001 > /nul" );
#endif

    SaoriDirectory = (char*)malloc(sizeof(char) * (len + 1 ));
    memset( SaoriDirectory , '\0' , ( len + 1 ));
    memcpy( SaoriDirectory , (char*)h , (int)len  );
    GlobalFree( h );

    printf( "load Saori WhenYouBack\n" );
    return true;
}
//}}}
//{{{
//Unload 処理-------------------------------------------------------
extern "C" __declspec(dllexport) bool __cdecl unload(void){
    printf( "unload Saori WhenYouBack\n" );

    free( SaoriDirectory );

#ifdef Debug
    FreeConsole();
#endif

    return true;
}
//}}}


extern "C" __declspec(dllexport) HGLOBAL __cdecl request(HGLOBAL h, long *len){
    char req[*len+1];
    memset( req , '\0' , *len+1 );
    memcpy( req , (char*)h , *len );
    GlobalFree( h );
//#ifdef Debug
//    printf( "%s----\n" , req );
//#endif


    bool NOTIFY = false;
    resBuf = NULL;

    char* Sender    = NULL;


    //{{{
    //char* Argument0-23 = NULL
    char* Argument0 = NULL;
    char* Argument1 = NULL;
    char* Argument2 = NULL;
    char* Argument3 = NULL;
    char* Argument4 = NULL;
    char* Argument5 = NULL;
    char* Argument6 = NULL;
    char* Argument7 = NULL;
    char* Argument8 = NULL;
    char* Argument9 = NULL;
    char* Argument10 = NULL;
    char* Argument11 = NULL;
    char* Argument12 = NULL;
    char* Argument13 = NULL;
    char* Argument14 = NULL;
    char* Argument15 = NULL;
    char* Argument16 = NULL;
    char* Argument17 = NULL;
    char* Argument18 = NULL;
    char* Argument19 = NULL;
    char* Argument20 = NULL;
    char* Argument21 = NULL;
    char* Argument22 = NULL;
    char* Argument23 = NULL;
    //}}}

    char  sepLine[]    = "\r\n";
    char  sepLR[] = ": ";
    char* tp ;
    tp = strtok( req , sepLine );
    while( tp != NULL ){
        if ( tp == "GET Version SAORI/1.0" ){
            tp = strtok( NULL , sepLine );
            continue;
        }

        //左右分割を試みる。
        char* checkR = strstr( tp , sepLR );
        if ( checkR == NULL ){
            tp = strtok( NULL , sepLine );
            continue;
        }


        int Lsize = strlen( tp ) - strlen( checkR ) ;
        char L[ Lsize + 1 ] ;
        memset( L , '\0' , Lsize + 1 );
        memcpy( L , tp , Lsize);

        int Rsize = strlen( tp ) - ( Lsize + strlen( sepLR ) );
        
        if ( strcmp( L , "Sender" ) == 0 ) {
            Sender = (char*)calloc( Rsize + 1 , sizeof(char) );
            memcpy( Sender , &tp[ Lsize + strlen( sepLR ) ] , Rsize );

        //{{{ Argument0-23 
        } else if ( strcmp( L , "Argument0" ) == 0 ) {
            Argument0 = (char*)calloc( Rsize + 1 , sizeof(char) );
            memcpy( Argument0 , &tp[ Lsize + strlen( sepLR ) ] , Rsize );

        } else if ( strcmp( L , "Argument1" ) == 0 ) {
            Argument1 = (char*)calloc( Rsize + 1 , sizeof(char) );
            memcpy( Argument1 , &tp[ Lsize + strlen( sepLR ) ] , Rsize );

        } else if ( strcmp( L , "Argument2" ) == 0 ) {
            Argument2 = (char*)calloc( Rsize + 1 , sizeof(char) );
            memcpy( Argument2 , &tp[ Lsize + strlen( sepLR ) ] , Rsize );

        } else if ( strcmp( L , "Argument3" ) == 0 ) {
            Argument3 = (char*)calloc( Rsize + 1 , sizeof(char) );
            memcpy( Argument3 , &tp[ Lsize + strlen( sepLR ) ] , Rsize );

        } else if ( strcmp( L , "Argument4" ) == 0 ) {
            Argument4 = (char*)calloc( Rsize + 1 , sizeof(char) );
            memcpy( Argument4 , &tp[ Lsize + strlen( sepLR ) ] , Rsize );

        } else if ( strcmp( L , "Argument5" ) == 0 ) {
            Argument5 = (char*)calloc( Rsize + 1 , sizeof(char) );
            memcpy( Argument5 , &tp[ Lsize + strlen( sepLR ) ] , Rsize );

        } else if ( strcmp( L , "Argument6" ) == 0 ) {
            Argument6 = (char*)calloc( Rsize + 1 , sizeof(char) );
            memcpy( Argument6 , &tp[ Lsize + strlen( sepLR ) ] , Rsize );

        } else if ( strcmp( L , "Argument7" ) == 0 ) {
            Argument7 = (char*)calloc( Rsize + 1 , sizeof(char) );
            memcpy( Argument7 , &tp[ Lsize + strlen( sepLR ) ] , Rsize );

        } else if ( strcmp( L , "Argument8" ) == 0 ) {
            Argument8 = (char*)calloc( Rsize + 1 , sizeof(char) );
            memcpy( Argument8 , &tp[ Lsize + strlen( sepLR ) ] , Rsize );

        } else if ( strcmp( L , "Argument9" ) == 0 ) {
            Argument9 = (char*)calloc( Rsize + 1 , sizeof(char) );
            memcpy( Argument9 , &tp[ Lsize + strlen( sepLR ) ] , Rsize );

        } else if ( strcmp( L , "Argument10" ) == 0 ) {
            Argument10 = (char*)calloc( Rsize + 1 , sizeof(char) );
            memcpy( Argument10 , &tp[ Lsize + strlen( sepLR ) ] , Rsize );

        } else if ( strcmp( L , "Argument11" ) == 0 ) {
            Argument11 = (char*)calloc( Rsize + 1 , sizeof(char) );
            memcpy( Argument11 , &tp[ Lsize + strlen( sepLR ) ] , Rsize );

        } else if ( strcmp( L , "Argument12" ) == 0 ) {
            Argument12 = (char*)calloc( Rsize + 1 , sizeof(char) );
            memcpy( Argument12 , &tp[ Lsize + strlen( sepLR ) ] , Rsize );

        } else if ( strcmp( L , "Argument13" ) == 0 ) {
            Argument13 = (char*)calloc( Rsize + 1 , sizeof(char) );
            memcpy( Argument13 , &tp[ Lsize + strlen( sepLR ) ] , Rsize );

        } else if ( strcmp( L , "Argument14" ) == 0 ) {
            Argument14 = (char*)calloc( Rsize + 1 , sizeof(char) );
            memcpy( Argument14 , &tp[ Lsize + strlen( sepLR ) ] , Rsize );

        } else if ( strcmp( L , "Argument15" ) == 0 ) {
            Argument15 = (char*)calloc( Rsize + 1 , sizeof(char) );
            memcpy( Argument15 , &tp[ Lsize + strlen( sepLR ) ] , Rsize );

        } else if ( strcmp( L , "Argument16" ) == 0 ) {
            Argument16 = (char*)calloc( Rsize + 1 , sizeof(char) );
            memcpy( Argument16 , &tp[ Lsize + strlen( sepLR ) ] , Rsize );

        } else if ( strcmp( L , "Argument17" ) == 0 ) {
            Argument17 = (char*)calloc( Rsize + 1 , sizeof(char) );
            memcpy( Argument17 , &tp[ Lsize + strlen( sepLR ) ] , Rsize );

        } else if ( strcmp( L , "Argument18" ) == 0 ) {
            Argument18 = (char*)calloc( Rsize + 1 , sizeof(char) );
            memcpy( Argument18 , &tp[ Lsize + strlen( sepLR ) ] , Rsize );

        } else if ( strcmp( L , "Argument19" ) == 0 ) {
            Argument19 = (char*)calloc( Rsize + 1 , sizeof(char) );
            memcpy( Argument19 , &tp[ Lsize + strlen( sepLR ) ] , Rsize );

        } else if ( strcmp( L , "Argument20" ) == 0 ) {
            Argument20 = (char*)calloc( Rsize + 1 , sizeof(char) );
            memcpy( Argument20 , &tp[ Lsize + strlen( sepLR ) ] , Rsize );

        } else if ( strcmp( L , "Argument21" ) == 0 ) {
            Argument21 = (char*)calloc( Rsize + 1 , sizeof(char) );
            memcpy( Argument21 , &tp[ Lsize + strlen( sepLR ) ] , Rsize );

        } else if ( strcmp( L , "Argument22" ) == 0 ) {
            Argument22 = (char*)calloc( Rsize + 1 , sizeof(char) );
            memcpy( Argument22 , &tp[ Lsize + strlen( sepLR ) ] , Rsize );

        } else if ( strcmp( L , "Argument23" ) == 0 ) {
            Argument23 = (char*)calloc( Rsize + 1 , sizeof(char) );
            memcpy( Argument23 , &tp[ Lsize + strlen( sepLR ) ] , Rsize );
        //}}}
        
        //} else if ( strcomp( L , "" ) == 0 ) {
        }
        tp = strtok( NULL , sepLine );
    }




    //引数は24固定。
    //無ければ0に。
    //半角に。
    //shiftjis


    int ArgIntArray[24] = {};
    //{{{
    if ( Argument0  != NULL ){ ArgIntArray[0]  = ZenToHan( Argument0  ); } 
    if ( Argument1  != NULL ){ ArgIntArray[1]  = ZenToHan( Argument1  ); } 
    if ( Argument2  != NULL ){ ArgIntArray[2]  = ZenToHan( Argument2  ); } 
    if ( Argument3  != NULL ){ ArgIntArray[3]  = ZenToHan( Argument3  ); } 
    if ( Argument4  != NULL ){ ArgIntArray[4]  = ZenToHan( Argument4  ); } 
    if ( Argument5  != NULL ){ ArgIntArray[5]  = ZenToHan( Argument5  ); } 
    if ( Argument6  != NULL ){ ArgIntArray[6]  = ZenToHan( Argument6  ); } 
    if ( Argument7  != NULL ){ ArgIntArray[7]  = ZenToHan( Argument7  ); } 
    if ( Argument8  != NULL ){ ArgIntArray[8]  = ZenToHan( Argument8  ); } 
    if ( Argument9  != NULL ){ ArgIntArray[9]  = ZenToHan( Argument9  ); } 
    if ( Argument10 != NULL ){ ArgIntArray[10] = ZenToHan( Argument10 ); } 
    if ( Argument11 != NULL ){ ArgIntArray[11] = ZenToHan( Argument11 ); } 
    if ( Argument12 != NULL ){ ArgIntArray[12] = ZenToHan( Argument12 ); } 
    if ( Argument13 != NULL ){ ArgIntArray[13] = ZenToHan( Argument13 ); } 
    if ( Argument14 != NULL ){ ArgIntArray[14] = ZenToHan( Argument14 ); } 
    if ( Argument15 != NULL ){ ArgIntArray[15] = ZenToHan( Argument15 ); } 
    if ( Argument16 != NULL ){ ArgIntArray[16] = ZenToHan( Argument16 ); } 
    if ( Argument17 != NULL ){ ArgIntArray[17] = ZenToHan( Argument17 ); } 
    if ( Argument18 != NULL ){ ArgIntArray[18] = ZenToHan( Argument18 ); } 
    if ( Argument19 != NULL ){ ArgIntArray[19] = ZenToHan( Argument19 ); } 
    if ( Argument20 != NULL ){ ArgIntArray[20] = ZenToHan( Argument20 ); } 
    if ( Argument21 != NULL ){ ArgIntArray[21] = ZenToHan( Argument21 ); } 
    if ( Argument22 != NULL ){ ArgIntArray[22] = ZenToHan( Argument22 ); } 
    if ( Argument23 != NULL ){ ArgIntArray[23] = ZenToHan( Argument23 ); } 
    //}}}


    int count = 0;
    int MAX   = 0;
    //同じ数字は最初のものが優先
    for( int i = 0 ; i < (sizeof( ArgIntArray ) / sizeof( int )) ; i++ ){
        if( MAX < ArgIntArray[ i ] ) {
            count = i;
            MAX = ArgIntArray[ i ];
        }
    }

    ////resultで返すのはめんどくさいと判断した。
    string Res;
    Res = "SAORI/1.0 200 OK\r\nValue0: " + to_string( count ) + "\r\nValue1: " + to_string( MAX ) +"\r\n\r\n";
    int i = strlen( Res.c_str() );
    char* res_buf;
    res_buf = (char*)calloc( i + 1 , sizeof(char) );
    memcpy( res_buf , Res.c_str() , i );
    resBuf = res_buf;
    

    //Saoriにおいて、Charsetはshift-jis決め打ちである。
    //返すものがなかった時
    if ( resBuf == NULL ){
        //char res_buf[] = "SAORI/1.0 204 No Content\r\nCharset: UTF-8\r\n\r\n";
        char res_buf[] = "SAORI/1.0 204 No Content\r\n\r\n";
        resBuf = res_buf;
    }

    if ( Sender != NULL ){ free( Sender ); }
    //{{{
    //Argument0 != NULL ){ free( Argument0 ); }
    if ( Argument0 != NULL ){ free( Argument0 ); }
    if ( Argument1 != NULL ){ free( Argument1 ); }
    if ( Argument2 != NULL ){ free( Argument2 ); }
    if ( Argument3 != NULL ){ free( Argument3 ); }
    if ( Argument4 != NULL ){ free( Argument4 ); }
    if ( Argument5 != NULL ){ free( Argument5 ); }
    if ( Argument6 != NULL ){ free( Argument6 ); }
    if ( Argument7 != NULL ){ free( Argument7 ); }
    if ( Argument8 != NULL ){ free( Argument8 ); }
    if ( Argument9 != NULL ){ free( Argument9 ); }
    if ( Argument10 != NULL ){ free( Argument10 ); }
    if ( Argument11 != NULL ){ free( Argument11 ); }
    if ( Argument12 != NULL ){ free( Argument12 ); }
    if ( Argument13 != NULL ){ free( Argument13 ); }
    if ( Argument14 != NULL ){ free( Argument14 ); }
    if ( Argument15 != NULL ){ free( Argument15 ); }
    if ( Argument16 != NULL ){ free( Argument16 ); }
    if ( Argument17 != NULL ){ free( Argument17 ); }
    if ( Argument18 != NULL ){ free( Argument18 ); }
    if ( Argument19 != NULL ){ free( Argument19 ); }
    if ( Argument20 != NULL ){ free( Argument20 ); }
    if ( Argument21 != NULL ){ free( Argument21 ); }
    if ( Argument22 != NULL ){ free( Argument22 ); }
    if ( Argument23 != NULL ){ free( Argument23 ); }
    //}}}



    
    //pluginは2.0で返す。
    //char res_buf[] = "SAORI/1.0 204 No Content";
    *len = strlen(resBuf);
    HGLOBAL ret = GlobalAlloc(GPTR, (SIZE_T)(*len));
    memcpy(ret, (void*)(resBuf), *len);
    return ret;
}
















