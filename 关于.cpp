// 关于.cpp: 实现文件
//

#include "pch.h"
#include "DISLIKE.h"
#include "afxdialogex.h"
#include "关于.h"


// 关于 对话框

IMPLEMENT_DYNAMIC(关于, CDialogEx)

关于::关于(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ABOUTBOX, pParent)
{

}

关于::~关于()
{
}

void 关于::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(关于, CDialogEx)
END_MESSAGE_MAP()


// 关于 消息处理程序
