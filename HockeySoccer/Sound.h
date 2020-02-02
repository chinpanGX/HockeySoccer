/*====================================================

	[Sound.h]
	Author : 出合翔太

=====================================================*/

#pragma once
#include "main.h"
#include "xaudio2.h"  // Xaudioを使用

enum SoundLabel
{
	S_BGM_TITLE,	// タイトルBGM
	S_BGM_GAME,		// ゲームBGM
	S_SE_BALL,		// ボールSE
	S_SE_WHISTIL,	// ホイッスルSE

	SOUND_MAX
};

class Sound
{
private:
	static IXAudio2 *m_pXAudio2;								// XAudio2オブジェクトへのインターフェイス
	static IXAudio2MasteringVoice *m_pMasteringVoice;			// マスターボイス
	static IXAudio2SourceVoice *m_apSourceVoice[SOUND_MAX];	// ソースボイス
	static BYTE *m_apDataAudio[SOUND_MAX];					// オーディオデータ
	static DWORD m_aSizeAudio[SOUND_MAX];					// オーディオデータサイズ
	
	static HRESULT CheckChunk(HANDLE hFile, DWORD format, DWORD *pChunkSize, DWORD *pChunkDataPosition);
	static HRESULT ReadChunkData(HANDLE hFile, void *pBuffer, DWORD dwBuffersize, DWORD dwBufferoffset);
public:
	static bool Init(HWND hWnd);
	static void Uninit();
	static void Play(SoundLabel label);
	static void Stop(SoundLabel label);
	static void Stop();
};

