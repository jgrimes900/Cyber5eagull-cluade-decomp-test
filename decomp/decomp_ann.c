// ===== FUN_140001000 @ 140001000 size=514

undefined8 *
FUN_140001000(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
             undefined8 param_5)

{
  ulonglong *puVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined1 *puVar6;
  longlong *plVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  uint uVar10;
  
  *param_1 = param_2;
  *(undefined1 (*) [16])(param_1 + 1) = (undefined1  [16])0x0;
  plVar7 = &DAT_140029878;
  if ((longlong *)*param_1 != (longlong *)0x0) {
    plVar7 = (longlong *)*param_1;
  }
  uVar4 = plVar7[2] + 7U & 0xfffffffffffffff8;
  lVar5 = *plVar7 + uVar4;
  plVar7[2] = uVar4 + 0x40;
  *(undefined4 *)((longlong)param_1 + 0x14) = 8;
  param_1[1] = lVar5;
  *(undefined8 *)(lVar5 + (ulonglong)*(uint *)(param_1 + 2) * 8) = param_3;
  *(int *)(param_1 + 2) = *(int *)(param_1 + 2) + 1;
  uVar2 = *(uint *)((longlong)param_1 + 0x14);
  if (*(uint *)(param_1 + 2) == uVar2) {
    uVar10 = 8;
    if (8 < uVar2 * 2) {
      uVar10 = uVar2 * 2;
    }
    if (uVar2 < uVar10) {
      puVar8 = (undefined1 *)param_1[1];
      plVar7 = &DAT_140029878;
      if ((longlong *)*param_1 != (longlong *)0x0) {
        plVar7 = (longlong *)*param_1;
      }
      puVar1 = (ulonglong *)(plVar7 + 2);
      if (puVar8 == (undefined1 *)0x0) {
        uVar4 = *puVar1 + 7 & 0xfffffffffffffff8;
        *puVar1 = uVar4;
        puVar6 = (undefined1 *)(*plVar7 + uVar4);
LAB_14000110b:
        *puVar1 = *puVar1 + (ulonglong)uVar10 * 8;
      }
      else {
        uVar4 = *puVar1;
        lVar5 = (ulonglong)uVar2 * 8;
        if (puVar8 + lVar5 != (undefined1 *)(uVar4 + *plVar7)) {
          uVar4 = uVar4 + 7 & 0xfffffffffffffff8;
          *puVar1 = uVar4;
          puVar6 = (undefined1 *)(uVar4 + *plVar7);
          puVar9 = puVar6;
          for (; lVar5 != 0; lVar5 = lVar5 + -1) {
            *puVar9 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar9 = puVar9 + 1;
          }
          goto LAB_14000110b;
        }
        *puVar1 = uVar4 + (ulonglong)(uVar10 - uVar2) * 8;
        puVar6 = puVar8;
      }
      param_1[1] = puVar6;
      *(uint *)((longlong)param_1 + 0x14) = uVar10;
    }
  }
  *(undefined8 *)(param_1[1] + (ulonglong)*(uint *)(param_1 + 2) * 8) = param_4;
  *(int *)(param_1 + 2) = *(int *)(param_1 + 2) + 1;
  uVar2 = *(uint *)((longlong)param_1 + 0x14);
  if (*(uint *)(param_1 + 2) != uVar2) goto LAB_1400011e0;
  uVar10 = 8;
  if (8 < uVar2 * 2) {
    uVar10 = uVar2 * 2;
  }
  if (uVar10 <= uVar2) goto LAB_1400011e0;
  puVar8 = (undefined1 *)param_1[1];
  plVar7 = &DAT_140029878;
  if ((longlong *)*param_1 != (longlong *)0x0) {
    plVar7 = (longlong *)*param_1;
  }
  if (puVar8 == (undefined1 *)0x0) {
    uVar4 = plVar7[2] + 7U & 0xfffffffffffffff8;
    plVar7[2] = uVar4;
    puVar6 = (undefined1 *)(*plVar7 + uVar4);
LAB_1400011cd:
    plVar7[2] = plVar7[2] + (ulonglong)uVar10 * 8;
  }
  else {
    lVar3 = plVar7[2];
    lVar5 = (ulonglong)uVar2 * 8;
    if (puVar8 + lVar5 != (undefined1 *)(lVar3 + *plVar7)) {
      uVar4 = lVar3 + 7U & 0xfffffffffffffff8;
      plVar7[2] = uVar4;
      puVar6 = (undefined1 *)(uVar4 + *plVar7);
      puVar9 = puVar6;
      for (; lVar5 != 0; lVar5 = lVar5 + -1) {
        *puVar9 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar9 = puVar9 + 1;
      }
      goto LAB_1400011cd;
    }
    plVar7[2] = lVar3 + (ulonglong)(uVar10 - uVar2) * 8;
    puVar6 = puVar8;
  }
  param_1[1] = puVar6;
  *(uint *)((longlong)param_1 + 0x14) = uVar10;
LAB_1400011e0:
  *(undefined8 *)(param_1[1] + (ulonglong)*(uint *)(param_1 + 2) * 8) = param_5;
  *(int *)(param_1 + 2) = *(int *)(param_1 + 2) + 1;
  return param_1;
}


// ===== FUN_140001210 @ 140001210 size=488

void FUN_140001210(undefined8 *param_1,uint param_2,undefined1 (*param_3) [16])

{
  longlong lVar1;
  uint uVar2;
  undefined8 uVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong uVar6;
  char *pcVar7;
  undefined1 *puVar8;
  ulonglong uVar9;
  char *pcVar10;
  undefined1 *puVar11;
  undefined8 unaff_XMM6_Qa;
  undefined8 unaff_XMM6_Qb;
  undefined1 auVar12 [16];
  char *local_78;
  longlong lStack_70;
  char *local_68;
  undefined8 uStack_60;
  char local_58 [63];
  char local_19;
  undefined8 local_18;
  undefined8 uStack_10;
  
  lVar1 = DAT_140029828;
  if (DAT_140029828 != -1) {
    local_78 = (char *)*param_1;
    lStack_70 = param_1[1];
    uVar9 = (ulonglong)param_2;
    uVar3 = FUN_14001c490(&DAT_140029818,(longlong *)&local_78);
    if ((int)uVar3 != 0) {
      local_18 = unaff_XMM6_Qa;
      uStack_10 = unaff_XMM6_Qb;
      if ((lStack_70 == 0) || (*local_78 != 'x')) {
        pcVar7 = (char *)&local_18;
        do {
          pcVar7 = pcVar7 + -1;
          uVar6 = uVar9 / 10;
          *pcVar7 = (char)uVar9 + (char)uVar6 * -10 + '0';
          uVar9 = uVar6;
        } while (uVar6 != 0);
        pcVar10 = (char *)&local_18;
      }
      else {
        lStack_70 = lStack_70 + -1;
        pcVar7 = local_58;
        local_78 = local_78 + 1;
        uVar2 = param_2 & 0xf;
        if (uVar2 != 0) {
          do {
            pcVar7 = pcVar7 + -1;
            uVar9 = uVar9 >> 4;
            *pcVar7 = "0123456789ABCDEF"[uVar2];
            uVar2 = (uint)uVar9 & 0xf;
          } while ((uVar9 & 0xf) != 0);
        }
        pcVar10 = local_58;
      }
      lVar5 = (longlong)pcVar10 - (longlong)pcVar7;
      auVar12 = *param_3;
      pcVar10 = (char *)(DAT_140029818 + DAT_140029828);
      DAT_140029828 = DAT_140029828 + lVar5;
      for (; lVar5 != 0; lVar5 = lVar5 + -1) {
        *pcVar10 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar10 = pcVar10 + 1;
      }
      uVar3 = FUN_14001c490(&DAT_140029818,(longlong *)&local_78);
      if ((int)uVar3 != 0) {
        lVar4 = vpextrq_avx(auVar12,1);
        puVar8 = auVar12._0_8_;
        puVar11 = (undefined1 *)(DAT_140029818 + DAT_140029828);
        for (lVar5 = lVar4; lVar5 != 0; lVar5 = lVar5 + -1) {
          *puVar11 = *puVar8;
          puVar8 = puVar8 + 1;
          puVar11 = puVar11 + 1;
        }
        DAT_140029828 = DAT_140029828 + lVar4;
        local_68 = local_78;
        uStack_60 = lStack_70;
        FUN_14001c490(&DAT_140029818,(longlong *)&local_68);
      }
    }
    WriteFile(DAT_1400299a0,(LPCVOID)(DAT_140029818 + lVar1),(int)DAT_140029828 - (int)lVar1,
              (LPDWORD)0x0,(LPOVERLAPPED)0x0);
  }
  DAT_140029828 = lVar1;
  return;
}


// ===== FUN_140001400 @ 140001400 size=172

void FUN_140001400(longlong *param_1,DWORD param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong local_28;
  longlong lStack_20;
  longlong local_18 [2];
  
  lVar1 = DAT_140029828;
  if (DAT_140029828 != -1) {
    local_28 = *param_1;
    lStack_20 = param_1[1];
    uVar2 = FUN_14001c490(&DAT_140029818,&local_28);
    if ((int)uVar2 != 0) {
      FUN_1400098c0(local_18,&DAT_140029818,param_2);
      FUN_14001c490(&DAT_140029818,&local_28);
    }
    WriteFile(DAT_1400299a0,(LPCVOID)(DAT_140029818 + lVar1),(int)DAT_140029828 - (int)lVar1,
              (LPDWORD)0x0,(LPOVERLAPPED)0x0);
  }
  DAT_140029828 = lVar1;
  return;
}


// ===== FUN_1400014b0 @ 1400014b0 size=305

void FUN_1400014b0(undefined8 *param_1,undefined1 *param_2)

{
  ulonglong *puVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined1 *puVar4;
  longlong *plVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  uint uVar8;
  longlong lVar9;
  undefined1 local_2088 [8320];
  
  uVar2 = *(uint *)((longlong)param_1 + 0x14);
  if (*(uint *)(param_1 + 2) != uVar2) goto LAB_14000159c;
  uVar8 = 8;
  if (8 < uVar2 * 2) {
    uVar8 = uVar2 * 2;
  }
  if (uVar8 <= uVar2) goto LAB_14000159c;
  puVar6 = (undefined1 *)param_1[1];
  plVar5 = &DAT_140029878;
  if ((longlong *)*param_1 != (longlong *)0x0) {
    plVar5 = (longlong *)*param_1;
  }
  puVar1 = (ulonglong *)(plVar5 + 2);
  if (puVar6 == (undefined1 *)0x0) {
    uVar3 = *puVar1 + 3 & 0xfffffffffffffffc;
    *puVar1 = uVar3;
    puVar4 = (undefined1 *)(*plVar5 + uVar3);
LAB_140001577:
    *puVar1 = *puVar1 + (ulonglong)uVar8 * 0x2080;
  }
  else {
    uVar3 = *puVar1;
    lVar9 = (ulonglong)uVar2 * 0x2080;
    if (puVar6 + lVar9 != (undefined1 *)(*plVar5 + uVar3)) {
      uVar3 = uVar3 + 3 & 0xfffffffffffffffc;
      *puVar1 = uVar3;
      puVar4 = (undefined1 *)(uVar3 + *plVar5);
      puVar7 = puVar4;
      for (; lVar9 != 0; lVar9 = lVar9 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
      goto LAB_140001577;
    }
    *puVar1 = (ulonglong)(uVar8 - uVar2) * 0x2080 + uVar3;
    puVar4 = puVar6;
  }
  param_1[1] = puVar4;
  *(uint *)((longlong)param_1 + 0x14) = uVar8;
LAB_14000159c:
  FUN_1400200a0(local_2088,param_2,0x2080);
  FUN_1400200a0((undefined1 *)((ulonglong)*(uint *)(param_1 + 2) * 0x2080 + param_1[1]),local_2088,
                0x2080);
  *(int *)(param_1 + 2) = *(int *)(param_1 + 2) + 1;
  return;
}


// ===== FUN_1400015f0 @ 1400015f0 size=516

LPVOID FUN_1400015f0(DWORD *param_1,longlong *param_2,longlong *param_3)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  DWORD DVar4;
  BOOL BVar5;
  DWORD DVar6;
  LPCSTR lpFileName;
  HANDLE hFile;
  ulonglong uVar7;
  longlong *plVar8;
  longlong lVar9;
  ulonglong uVar10;
  LPVOID lpBuffer;
  CHAR *pCVar11;
  LPCSTR pCVar12;
  DWORD local_res10 [2];
  char *local_58;
  undefined8 local_50;
  longlong local_48;
  longlong lStack_40;
  longlong local_38 [2];
  
  lVar1 = param_2[2];
  lVar2 = param_3[1];
  if ((lVar2 == 0) || (lpFileName = (LPCSTR)*param_3, lpFileName[lVar2 + -1] != '\0')) {
    pCVar11 = (CHAR *)*param_3;
    param_2[2] = lVar2 + 1 + lVar1;
    lpFileName = (LPCSTR)(*param_2 + lVar1);
    pCVar12 = lpFileName;
    for (lVar9 = lVar2; lVar9 != 0; lVar9 = lVar9 + -1) {
      *pCVar12 = *pCVar11;
      pCVar11 = pCVar11 + 1;
      pCVar12 = pCVar12 + 1;
    }
    lpFileName[lVar2] = '\0';
  }
  hFile = CreateFileA(lpFileName,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x8000080,(HANDLE)0x0);
  param_2[2] = lVar1;
  if (hFile == (HANDLE)0xffffffffffffffff) {
    DVar4 = GetLastError();
    plVar8 = FUN_1400098c0(local_38,param_2,DVar4);
    local_50 = 0x25;
    local_58 = "Failed to create file, reason: (%) %\n";
    local_48 = *plVar8;
    lStack_40 = plVar8[1];
    FUN_140001210(&local_58,DVar4,(undefined1 (*) [16])&local_48);
    param_2[2] = lVar1;
    return (LPVOID)0x0;
  }
  DVar4 = GetFileSize(hFile,(LPDWORD)0x0);
  uVar3 = param_2[2];
  lVar2 = *param_2;
  param_2[2] = uVar3;
  uVar7 = 0;
  uVar10 = uVar3 + 0xfff + (ulonglong)DVar4 & 0xfffffffffffff000;
  if (uVar10 != (uVar3 & 0xfffffffffffff000)) {
    do {
      *(undefined1 *)(uVar7 + lVar2 + uVar3) = 0;
      uVar7 = uVar7 + 0x1000;
    } while (uVar7 < uVar10 - (uVar3 & 0xfffffffffffff000));
  }
  lpBuffer = (LPVOID)(*param_2 + param_2[2]);
  local_res10[0] = 0;
  param_2[2] = param_2[2] + (ulonglong)DVar4;
  BVar5 = ReadFile(hFile,lpBuffer,DVar4,local_res10,(LPOVERLAPPED)0x0);
  if (BVar5 == 0) {
    lpBuffer = (LPVOID)0x0;
    DVar6 = GetLastError();
    plVar8 = FUN_1400098c0(local_38,param_2,DVar6);
    local_50 = 0x23;
    local_48 = *plVar8;
    lStack_40 = plVar8[1];
    local_58 = "Failed to read file, reason: (%) %\n";
    FUN_140001210(&local_58,DVar6,(undefined1 (*) [16])&local_48);
    param_2[2] = lVar1;
  }
  CloseHandle(hFile);
  *param_1 = DVar4;
  return lpBuffer;
}


// ===== FUN_140001800 @ 140001800 size=375

void FUN_140001800(int *param_1,byte *param_2,undefined4 *param_3,longlong param_4,
                  undefined8 param_5,byte *param_6,uint param_7)

{
  longlong lVar1;
  byte bVar2;
  undefined4 uVar3;
  uint uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined4 local_res8;
  
  uVar4 = param_1[1] * *param_1;
  if (uVar4 != 0) {
    local_res8 = 0xff000000;
    if (param_1[3] != 0) {
      if (param_7 == 0) {
        uVar6 = (ulonglong)uVar4;
        do {
          bVar2 = *param_2;
          param_2 = param_2 + 1;
          local_res8 = CONCAT13(local_res8._3_1_,*(undefined3 *)(param_4 + (ulonglong)bVar2 * 3));
          *param_3 = local_res8;
          uVar6 = uVar6 - 1;
          param_3 = param_3 + 1;
        } while (uVar6 != 0);
        return;
      }
      uVar6 = (ulonglong)uVar4;
      do {
        uVar3 = local_res8;
        bVar2 = *param_2;
        uVar5 = (ulonglong)bVar2;
        lVar1 = param_4 + uVar5 * 2;
        local_res8._3_1_ = SUB41(uVar3,3);
        local_res8._0_3_ =
             CONCAT12(*(undefined1 *)(lVar1 + 2 + uVar5),
                      CONCAT11(*(undefined1 *)(lVar1 + 1 + uVar5),*(undefined1 *)(lVar1 + uVar5)));
        *param_3 = local_res8;
        if (bVar2 < param_7) {
          *(byte *)((longlong)param_3 + 3) = param_6[uVar5];
        }
        param_2 = param_2 + 1;
        param_3 = param_3 + 1;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
      return;
    }
    local_res8 = 0xff000000;
    uVar6 = (ulonglong)uVar4;
    if (param_6 != (byte *)0x0) {
      do {
        local_res8 = CONCAT31(local_res8._1_3_,*param_2);
        *param_3 = local_res8;
        if (*param_2 == *param_6) {
          *(undefined1 *)((longlong)param_3 + 3) = 0;
        }
        param_2 = param_2 + 1;
        param_3 = param_3 + 1;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
      return;
    }
    do {
      local_res8 = CONCAT31(local_res8._1_3_,*param_2);
      param_2 = param_2 + 1;
      *param_3 = local_res8;
      uVar6 = uVar6 - 1;
      param_3 = param_3 + 1;
    } while (uVar6 != 0);
  }
  return;
}


// ===== FUN_140001980 @ 140001980 size=344

void FUN_140001980(int *param_1,byte *param_2,undefined4 *param_3,longlong param_4,
                  undefined8 param_5,undefined2 *param_6,uint param_7)

{
  byte *pbVar1;
  longlong lVar2;
  byte bVar3;
  undefined4 uVar4;
  uint uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  undefined1 local_res8 [2];
  undefined1 uStackX_a;
  byte bStackX_b;
  
  uVar5 = param_1[1] * *param_1;
  if (uVar5 != 0) {
    if (param_1[3] != 0) {
      _local_res8 = 0xff000000;
      uVar6 = (ulonglong)uVar5;
      if (param_7 == 0) {
        do {
          bVar3 = *param_2;
          param_2 = param_2 + 2;
          _local_res8 = CONCAT13(bStackX_b,*(undefined3 *)(param_4 + (ulonglong)bVar3 * 3));
          *param_3 = _local_res8;
          uVar6 = uVar6 - 1;
          param_3 = param_3 + 1;
        } while (uVar6 != 0);
        return;
      }
      do {
        uVar4 = _local_res8;
        bVar3 = *param_2;
        uVar7 = (ulonglong)bVar3;
        lVar2 = param_4 + uVar7 * 2;
        bStackX_b = SUB41(uVar4,3);
        _local_res8 = CONCAT12(*(undefined1 *)(lVar2 + 2 + uVar7),
                               CONCAT11(*(undefined1 *)(lVar2 + 1 + uVar7),
                                        *(undefined1 *)(lVar2 + uVar7)));
        *param_3 = _local_res8;
        if (bVar3 < param_7) {
          *(undefined1 *)((longlong)param_3 + 3) = *(undefined1 *)(uVar7 + (longlong)param_6);
        }
        param_2 = param_2 + 2;
        param_3 = param_3 + 1;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
      return;
    }
    uVar6 = (ulonglong)uVar5;
    if (param_6 != (undefined2 *)0x0) {
      do {
        _local_res8 = (uint3)*param_2;
        _local_res8 = CONCAT13(param_2[1],_local_res8);
        *param_3 = _local_res8;
        if ((*param_2 == (byte)*param_6) && (param_2[1] == (byte)((ushort)*param_6 >> 8))) {
          *(undefined1 *)((longlong)param_3 + 3) = 0;
        }
        param_2 = param_2 + 2;
        param_3 = param_3 + 1;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
      return;
    }
    do {
      bVar3 = *param_2;
      pbVar1 = param_2 + 1;
      param_2 = param_2 + 2;
      _local_res8 = (uint3)bVar3;
      _local_res8 = CONCAT13(*pbVar1,_local_res8);
      *param_3 = _local_res8;
      uVar6 = uVar6 - 1;
      param_3 = param_3 + 1;
    } while (uVar6 != 0);
  }
  return;
}


// ===== FUN_140001af0 @ 140001af0 size=417

void FUN_140001af0(int *param_1,byte *param_2,undefined4 *param_3,longlong param_4,
                  undefined8 param_5,byte *param_6,uint param_7)

{
  longlong lVar1;
  byte bVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  uint uVar5;
  byte *pbVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  undefined4 local_res8;
  undefined4 local_18;
  
  uVar5 = param_1[1] * *param_1;
  if (uVar5 != 0) {
    if (param_1[3] != 0) {
      local_18 = 0xff000000;
      if (param_7 == 0) {
        uVar8 = (ulonglong)uVar5;
        do {
          bVar2 = *param_2;
          param_2 = param_2 + 3;
          local_18 = CONCAT13(local_18._3_1_,*(undefined3 *)(param_4 + (ulonglong)bVar2 * 3));
          *param_3 = local_18;
          uVar8 = uVar8 - 1;
          param_3 = param_3 + 1;
        } while (uVar8 != 0);
        return;
      }
      uVar8 = (ulonglong)uVar5;
      do {
        uVar4 = local_18;
        uVar3 = *(undefined2 *)param_2;
        uVar7 = (ulonglong)(byte)uVar3;
        lVar1 = param_4 + uVar7 * 2;
        local_18._3_1_ = SUB41(uVar4,3);
        local_18._0_3_ =
             CONCAT12(*(undefined1 *)(lVar1 + 2 + uVar7),
                      CONCAT11(*(undefined1 *)(lVar1 + 1 + uVar7),*(undefined1 *)(lVar1 + uVar7)));
        *param_3 = local_18;
        if ((byte)uVar3 < param_7) {
          *(byte *)((longlong)param_3 + 3) = param_6[uVar7];
        }
        param_2 = param_2 + 3;
        param_3 = param_3 + 1;
        uVar8 = uVar8 - 1;
      } while (uVar8 != 0);
      return;
    }
    local_res8 = 0xff000000;
    pbVar6 = param_2 + 2;
    uVar8 = (ulonglong)uVar5;
    if (param_6 != (byte *)0x0) {
      do {
        local_res8._0_3_ = CONCAT12(*pbVar6,*(undefined2 *)(pbVar6 + -2));
        *param_3 = local_res8;
        if (((pbVar6[-2] == *param_6) && (pbVar6[-1] == param_6[1])) && (*pbVar6 == param_6[2])) {
          *(undefined1 *)((longlong)param_3 + 3) = 0;
        }
        pbVar6 = pbVar6 + 3;
        param_3 = param_3 + 1;
        uVar8 = uVar8 - 1;
      } while (uVar8 != 0);
      return;
    }
    do {
      local_res8._0_3_ = CONCAT12(*pbVar6,*(undefined2 *)(pbVar6 + -2));
      *param_3 = local_res8;
      uVar8 = uVar8 - 1;
      pbVar6 = pbVar6 + 3;
      param_3 = param_3 + 1;
    } while (uVar8 != 0);
  }
  return;
}


// ===== FUN_140001ca0 @ 140001ca0 size=107

undefined8 *
FUN_140001ca0(undefined8 *param_1,longlong *param_2,undefined8 *param_3,undefined8 *param_4)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  
  lVar1 = param_4[1];
  lVar3 = param_2[2];
  lVar2 = param_3[1];
  param_1[1] = lVar1 + lVar2;
  puVar6 = (undefined1 *)(*param_2 + lVar3);
  *param_1 = puVar6;
  param_2[2] = lVar3 + lVar1 + lVar2;
  lVar1 = param_3[1];
  puVar4 = (undefined1 *)*param_3;
  puVar5 = puVar6;
  for (lVar3 = lVar1; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  puVar4 = (undefined1 *)*param_4;
  puVar5 = puVar6 + lVar1;
  for (lVar3 = param_4[1]; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  return param_1;
}


// ===== FUN_140001d10 @ 140001d10 size=324

longlong * FUN_140001d10(longlong *param_1,longlong *param_2,longlong *param_3,ulonglong param_4)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  undefined8 uVar4;
  char *pcVar5;
  longlong lVar6;
  ulonglong uVar7;
  char *pcVar8;
  longlong local_68;
  undefined8 uStack_60;
  char local_58 [63];
  char local_19;
  
  lVar1 = param_2[2];
  uVar4 = FUN_14001c490(param_2,param_3);
  if ((int)uVar4 != 0) {
    if ((param_3[1] == 0) || (*(char *)*param_3 != 'x')) {
      pcVar8 = &stack0xffffffffffffffe8;
      do {
        pcVar8 = pcVar8 + -1;
        uVar7 = param_4 / 10;
        *pcVar8 = (char)param_4 + (char)uVar7 * -10 + '0';
        param_4 = uVar7;
      } while (uVar7 != 0);
      pcVar5 = &stack0xffffffffffffffe8;
    }
    else {
      pcVar8 = local_58;
      *param_3 = (longlong)((char *)*param_3 + 1);
      param_3[1] = param_3[1] + -1;
      uVar3 = (uint)param_4;
      uVar7 = param_4 & 0xf;
      while (uVar7 != 0) {
        pcVar8 = pcVar8 + -1;
        param_4 = param_4 >> 4;
        *pcVar8 = "0123456789ABCDEF"[uVar3 & 0xf];
        uVar3 = (uint)param_4;
        uVar7 = param_4 & 0xf;
      }
      pcVar5 = local_58;
    }
    lVar2 = param_2[2];
    lVar6 = (longlong)pcVar5 - (longlong)pcVar8;
    local_68 = *param_3;
    uStack_60 = param_3[1];
    param_2[2] = lVar2 + lVar6;
    pcVar5 = (char *)(*param_2 + lVar2);
    for (; lVar6 != 0; lVar6 = lVar6 + -1) {
      *pcVar5 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      pcVar5 = pcVar5 + 1;
    }
    FUN_14001c490(param_2,&local_68);
  }
  lVar2 = *param_2;
  param_1[1] = param_2[2] - lVar1;
  *param_1 = lVar2 + lVar1;
  return param_1;
}


// ===== FUN_140001e60 @ 140001e60 size=428

undefined8 *
FUN_140001e60(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined1 auVar1 [16];
  uint uVar2;
  int iVar3;
  int iVar4;
  
  param_1[1] = 0;
  param_1[2] = param_2;
  param_1[3] = param_3;
  *(undefined4 *)(param_1 + 4) = param_4;
  *(undefined8 *)((longlong)param_1 + 0x24) = 0;
  *(undefined4 *)((longlong)param_1 + 0x2c) = 0;
  *(undefined1 *)((longlong)param_1 + 0x34) = 0;
  *(undefined1 *)(param_1 + 7) = 0;
  *(undefined8 *)((longlong)param_1 + 0x39) = 0;
  *(undefined8 *)((longlong)param_1 + 0x41) = 0;
  *(undefined2 *)((longlong)param_1 + 0x49) = 0;
  *(undefined1 *)((longlong)param_1 + 0x4b) = 0;
  *(undefined8 *)((longlong)param_1 + 0x4c) = 0;
  *(undefined8 *)((longlong)param_1 + 0x54) = 1;
  *(undefined1 *)((longlong)param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  FUN_1400200d0((undefined1 *)((longlong)param_1 + 100),0,0x2000);
  *(undefined8 *)((longlong)param_1 + 0x2064) = 0;
  *(undefined8 *)((longlong)param_1 + 0x206c) = 0;
  iVar3 = (int)((ulonglong)param_2 >> 0x20);
  iVar4 = (int)param_2;
  auVar1 = vunpcklps_avx(ZEXT416((uint)((float)(param_1[2] & 0xffffffff) + *(float *)(param_1 + 3)))
                         ,ZEXT416((uint)((float)((ulonglong)param_1[2] >> 0x20) +
                                        *(float *)((longlong)param_1 + 0x1c))));
  *param_1 = auVar1._0_8_;
  *(undefined4 *)((longlong)param_1 + 0x2074) = 0;
  uVar2 = iVar4 * 0x2c9277b5 + iVar3 * -0x53a9b4fb + 0x108ef2d9;
  uVar2 = (uVar2 >> 0x10 ^ uVar2) * -0x7a143589;
  *(float *)(param_1 + 6) = (float)((uVar2 >> 0xd ^ uVar2) & 0x3ff) * (0.0009765625f);
  uVar2 = iVar4 * -0x61c88647 ^ iVar3 * -0x7a143595 ^ 0x1234abcd;
  uVar2 = (uVar2 >> 0x10 ^ uVar2) * 0x45d9f3b;
  uVar2 = (uVar2 >> 0x10 ^ uVar2) * 0x45d9f3b;
  *(float *)(param_1 + 0x40f) = (float)((uVar2 >> 0x10 ^ uVar2) & 0xffff) * (1.52590219e-05f);
  uVar2 = iVar4 * -0x3d4d51cb ^ iVar3 * 0x27d4eb2f ^ 0xb5297a4d;
  uVar2 = (uVar2 >> 0x10 ^ uVar2) * 0x45d9f3b;
  uVar2 = (uVar2 >> 0x10 ^ uVar2) * 0x45d9f3b;
  *(float *)((longlong)param_1 + 0x207c) = (float)((uVar2 >> 0x10 ^ uVar2) & 0xffff) * (1.52590219e-05f)
  ;
  return param_1;
}


// ===== FUN_140002010 @ 140002010 size=30

void FUN_140002010(char *param_1)

{
  code *pcVar1;
  char *local_18;
  longlong local_10;
  
  local_18 = param_1;
  local_10 = FUN_1400200f0(param_1);
  FUN_140002030(&local_18);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ===== FUN_140002030 @ 140002030 size=25

void FUN_140002030(undefined8 *param_1)

{
  code *pcVar1;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = *param_1;
  uStack_10 = param_1[1];
  FUN_140012ca0(&local_18);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ===== FUN_140002060 @ 140002060 size=347

void FUN_140002060(longlong param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined8 *puVar4;
  uint uVar5;
  longlong lVar6;
  undefined1 *puVar7;
  undefined1 local_4108 [8320];
  undefined8 local_2088 [1040];
  
  puVar4 = FUN_140001e60(local_2088,*(undefined8 *)param_2,*(undefined8 *)(param_2 + 2),
                         *(undefined4 *)(param_1 + 0x60));
  puVar7 = local_4108;
  for (lVar6 = 0x2080; lVar6 != 0; lVar6 = lVar6 + -1) {
    *puVar7 = *(undefined1 *)puVar4;
    puVar4 = (undefined8 *)((longlong)puVar4 + 1);
    puVar7 = puVar7 + 1;
  }
  FUN_1400014b0((undefined8 *)(param_1 + 8),local_4108);
  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *param_2;
  lVar6 = (ulonglong)(iVar1 - 1) * 0x2080 + *(longlong *)(param_1 + 0x10);
  iVar3 = param_2[1];
  *(float *)(lVar6 + 0x30) =
       (float)(iVar1 * 0xad - 0xadU & 0x3ff) * (0.0009765625f) + *(float *)(lVar6 + 0x30);
  uVar5 = iVar2 * -0x7a143595 ^ iVar3 * -0x3d4d51cb ^ iVar1 * -0x61c88647;
  uVar5 = (uVar5 >> 0x10 ^ uVar5) * 0x45d9f3b;
  uVar5 = (uVar5 >> 0x10 ^ uVar5) * 0x45d9f3b;
  iVar2 = param_2[1];
  *(float *)(lVar6 + 0x2078) = (float)((uVar5 >> 0x10 ^ uVar5) & 0xffff) * (1.52590219e-05f);
  uVar5 = iVar1 * 0x27d4eb2f ^ iVar2 * -0x2c5d9b94 ^ *param_2 * 0x165667b1;
  uVar5 = (uVar5 >> 0x10 ^ uVar5) * 0x45d9f3b;
  uVar5 = (uVar5 >> 0x10 ^ uVar5) * 0x45d9f3b;
  *(float *)(lVar6 + 0x207c) = (float)((uVar5 >> 0x10 ^ uVar5) & 0xffff) * (1.52590219e-05f);
  FUN_1400036d0(param_1);
  return;
}


// ===== FUN_1400021c0 @ 1400021c0 size=334

void FUN_1400021c0(longlong param_1)

{
  int iVar1;
  undefined8 *puVar2;
  uint uVar3;
  longlong lVar4;
  undefined1 *puVar5;
  undefined1 local_4108 [8320];
  undefined8 local_2088 [1040];
  
  puVar2 = FUN_140001e60(local_2088,*(undefined8 *)(param_1 + 0x50),*(undefined8 *)(param_1 + 0x58),
                         *(undefined4 *)(param_1 + 0x60));
  puVar5 = local_4108;
  for (lVar4 = 0x2080; lVar4 != 0; lVar4 = lVar4 + -1) {
    *puVar5 = *(undefined1 *)puVar2;
    puVar2 = (undefined8 *)((longlong)puVar2 + 1);
    puVar5 = puVar5 + 1;
  }
  FUN_1400014b0((undefined8 *)(param_1 + 8),local_4108);
  iVar1 = *(int *)(param_1 + 0x18);
  lVar4 = (ulonglong)(iVar1 - 1) * 0x2080 + *(longlong *)(param_1 + 0x10);
  *(float *)(lVar4 + 0x30) =
       (float)(iVar1 * 0xad - 0xadU & 0x3ff) * (0.0009765625f) + *(float *)(lVar4 + 0x30);
  uVar3 = *(int *)(param_1 + 0x50) * -0x7a143595 ^ *(int *)(param_1 + 0x54) * -0x3d4d51cb ^
          iVar1 * -0x61c88647;
  uVar3 = (uVar3 >> 0x10 ^ uVar3) * 0x45d9f3b;
  uVar3 = (uVar3 >> 0x10 ^ uVar3) * 0x45d9f3b;
  *(float *)(lVar4 + 0x2078) = (float)((uVar3 >> 0x10 ^ uVar3) & 0xffff) * (1.52590219e-05f);
  uVar3 = iVar1 * 0x27d4eb2f ^ *(int *)(param_1 + 0x54) * -0x2c5d9b94 ^
          *(int *)(param_1 + 0x50) * 0x165667b1;
  uVar3 = (uVar3 >> 0x10 ^ uVar3) * 0x45d9f3b;
  uVar3 = (uVar3 >> 0x10 ^ uVar3) * 0x45d9f3b;
  *(float *)(lVar4 + 0x207c) = (float)((uVar3 >> 0x10 ^ uVar3) & 0xffff) * (1.52590219e-05f);
  FUN_1400036d0(param_1);
  return;
}


// ===== FUN_140002310 @ 140002310 size=107

ulonglong FUN_140002310(ulonglong param_1)

{
  code *pcVar1;
  undefined1 auVar2 [16];
  float fVar3;
  float fVar4;
  ulonglong uVar5;
  
  if (DAT_14002a9d8 == 0) {
    pcVar1 = (code *)swi(3);
    uVar5 = (*pcVar1)();
    return uVar5;
  }
  fVar3 = (float)(param_1 >> 0x20) - (float)(*DAT_14002a9d0 >> 0x20);
  fVar4 = (float)(param_1 & 0xffffffff) - (float)(*DAT_14002a9d0 & 0xffffffff);
  auVar2 = vsqrtps_avx(ZEXT416((uint)(fVar4 * fVar4 + fVar3 * fVar3)));
  return (ulonglong)(uint)(auVar2._0_4_ * (3f));
}


// ===== FUN_140002380 @ 140002380 size=455

void FUN_140002380(float *param_1,ulonglong param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  undefined1 auVar10 [16];
  float fVar11;
  float fVar12;
  float fVar13;
  float local_res8;
  
  fVar8 = (0.980000019f);
  fVar7 = (0.5f);
  fVar6 = (0.00639999984f);
  fVar5 = (9.99999975e-05f);
  fVar3 = param_1[0x819];
  if (1 < (uint)fVar3) {
    while( true ) {
      fVar4 = param_1[0x81a];
      fVar9 = (float)((int)fVar4 + 1);
      if ((uint)fVar3 <= (uint)fVar9) break;
      if ((int)fVar4 + 2U < (uint)fVar3) {
        fVar12 = (float)(*(ulonglong *)(param_1 + (ulonglong)(uint)fVar9 * 2 + 0x19) >> 0x20) +
                 fVar7;
        fVar13 = (float)(*(ulonglong *)(param_1 + (ulonglong)(uint)fVar9 * 2 + 0x19) & 0xffffffff) +
                 fVar7;
      }
      else {
        local_res8 = (float)param_2;
        auVar10._8_8_ = 0;
        auVar10._0_8_ = param_2;
        auVar10 = vshufps_avx(auVar10,auVar10,0x55);
        fVar12 = auVar10._0_4_;
        fVar13 = local_res8;
      }
      fVar1 = *param_1;
      fVar2 = param_1[1];
      if (fVar6 < (fVar2 - fVar12) * (fVar2 - fVar12) + (fVar1 - fVar13) * (fVar1 - fVar13)) {
        if (fVar4 == 0.0) {
          auVar10 = vunpcklps_avx(ZEXT416((uint)fVar1),ZEXT416((uint)fVar2));
          local_res8 = auVar10._0_4_;
          auVar10 = vshufps_avx(auVar10,auVar10,0x55);
          fVar11 = auVar10._0_4_;
        }
        else {
          fVar11 = (float)(*(ulonglong *)(param_1 + (ulonglong)(uint)fVar4 * 2 + 0x19) >> 0x20) +
                   fVar7;
          local_res8 = (float)(*(ulonglong *)(param_1 + (ulonglong)(uint)fVar4 * 2 + 0x19) &
                              0xffffffff) + fVar7;
        }
        fVar12 = fVar12 - fVar11;
        fVar13 = fVar13 - local_res8;
        fVar4 = fVar12 * fVar12 + fVar13 * fVar13;
        if (fVar4 <= fVar5) {
          return;
        }
        if (((fVar2 - fVar11) * fVar12 + (fVar1 - local_res8) * fVar13) / fVar4 < fVar8) {
          return;
        }
      }
      param_1[0x81a] = fVar9;
    }
  }
  return;
}


// ===== FUN_140002550 @ 140002550 size=432

undefined8 * FUN_140002550(undefined8 *param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  longlong lVar8;
  ulonglong uVar9;
  undefined8 *puVar10;
  longlong *plVar11;
  undefined8 *puVar12;
  undefined8 *puVar13;
  undefined4 local_178 [2];
  undefined8 uStack_170;
  undefined1 auStack_168 [16];
  undefined8 local_158;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  undefined8 uStack_148;
  undefined4 uStack_140;
  undefined1 auStack_13c [16];
  undefined8 uStack_12c;
  undefined8 uStack_124;
  undefined8 uStack_11c;
  undefined4 local_114;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 uStack_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined4 local_b0;
  undefined2 local_ac;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined1 auStack_50 [16];
  undefined8 uStack_40;
  undefined8 uStack_38;
  undefined8 uStack_30;
  undefined8 uStack_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  puVar13 = (undefined8 *)param_1[1];
  if (puVar13 == (undefined8 *)0x0) {
    plVar11 = &DAT_140029878;
    if ((longlong *)*param_1 != (longlong *)0x0) {
      plVar11 = (longlong *)*param_1;
    }
    uVar9 = plVar11[2] + 7U & 0xfffffffffffffff8;
    puVar13 = (undefined8 *)(*plVar11 + uVar9);
    plVar11[2] = uVar9 + 0x168;
  }
  else {
    param_1[1] = *puVar13;
  }
  uStack_14c = 1;
  local_18 = 0;
  local_178[0] = 0;
  uStack_170 = 0;
  uStack_150 = 0;
  uStack_140 = 0;
  local_110 = 0;
  uStack_108 = 0;
  uStack_100 = 0;
  uStack_f8 = 0;
  local_f0 = 0;
  uStack_e8 = 0;
  uStack_e0 = 0;
  uStack_d8 = 0;
  local_d0 = 0;
  uStack_c8 = 0;
  uStack_c0 = 0;
  uStack_b8 = 0;
  local_58 = 0;
  local_158 = 0;
  uStack_12c = 0;
  uStack_124 = 0;
  uStack_11c = 0;
  local_b0 = 0;
  local_ac = 0;
  local_a8 = 0;
  local_60 = 0;
  uStack_20 = 0;
  lVar8 = 2;
  auStack_168 = (undefined1  [16])0x0;
  uStack_148 = 1;
  auStack_13c = (undefined1  [16])0x0;
  local_114 = 1;
  local_a0 = 0;
  uStack_98 = 0;
  uStack_90 = 0;
  uStack_88 = 0;
  local_80 = 0;
  uStack_78 = 0;
  uStack_70 = 0;
  uStack_68 = 0;
  auStack_50 = (undefined1  [16])0x0;
  uStack_40 = 0;
  uStack_38 = 0;
  uStack_30 = 0;
  uStack_28 = 0;
  puVar6 = (undefined8 *)local_178;
  puVar7 = puVar13;
  do {
    puVar12 = puVar7;
    puVar10 = puVar6;
    uVar3 = puVar10[1];
    uVar4 = puVar10[2];
    uVar5 = puVar10[3];
    uVar1 = puVar10[0xe];
    uVar2 = puVar10[0xf];
    *puVar12 = *puVar10;
    puVar12[1] = uVar3;
    puVar12[2] = uVar4;
    puVar12[3] = uVar5;
    uVar3 = puVar10[5];
    uVar4 = puVar10[6];
    uVar5 = puVar10[7];
    puVar12[4] = puVar10[4];
    puVar12[5] = uVar3;
    puVar12[6] = uVar4;
    puVar12[7] = uVar5;
    uVar3 = puVar10[9];
    uVar4 = puVar10[10];
    uVar5 = puVar10[0xb];
    puVar12[8] = puVar10[8];
    puVar12[9] = uVar3;
    puVar12[10] = uVar4;
    puVar12[0xb] = uVar5;
    uVar3 = puVar10[0xd];
    puVar12[0xc] = puVar10[0xc];
    puVar12[0xd] = uVar3;
    puVar12[0xe] = uVar1;
    puVar12[0xf] = uVar2;
    lVar8 = lVar8 + -1;
    puVar6 = puVar10 + 0x10;
    puVar7 = puVar12 + 0x10;
  } while (lVar8 != 0);
  uVar2 = puVar10[0x11];
  uVar3 = puVar10[0x12];
  uVar4 = puVar10[0x13];
  uVar1 = puVar10[0x1c];
  puVar12[0x10] = puVar10[0x10];
  puVar12[0x11] = uVar2;
  puVar12[0x12] = uVar3;
  puVar12[0x13] = uVar4;
  uVar2 = puVar10[0x15];
  uVar3 = puVar10[0x16];
  uVar4 = puVar10[0x17];
  puVar12[0x14] = puVar10[0x14];
  puVar12[0x15] = uVar2;
  puVar12[0x16] = uVar3;
  puVar12[0x17] = uVar4;
  uVar2 = puVar10[0x19];
  uVar3 = puVar10[0x1a];
  uVar4 = puVar10[0x1b];
  puVar12[0x18] = puVar10[0x18];
  puVar12[0x19] = uVar2;
  puVar12[0x1a] = uVar3;
  puVar12[0x1b] = uVar4;
  puVar12[0x1c] = uVar1;
  return puVar13;
}


// ===== FUN_140002700 @ 140002700 size=702

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140002700(void)

{
  byte bVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  tagPOINT tVar6;
  bool bVar7;
  int iVar8;
  undefined8 uVar9;
  longlong lVar10;
  int *piVar11;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  int iVar12;
  int iVar13;
  tagPOINT local_res8;
  
  local_res8.x = 0;
  local_res8.y = 0;
  uVar9 = FUN_140011060(&local_res8);
  tVar6 = local_res8;
  uVar5 = DAT_140029980;
  iVar2 = DAT_140029054;
  if ((int)uVar9 == 0) {
    return;
  }
  iVar12 = 0;
  if (((DAT_1400296fc != 0) && (local_res8.x == DAT_1400298a0)) && (local_res8.y == DAT_1400298a4))
  {
    return;
  }
  iVar13 = 1;
  DAT_1400296fc = 1;
  _DAT_1400298a0 = local_res8;
  if (DAT_1400298a8 != 0) {
    iVar4 = DAT_1400298b0.x;
    iVar8 = DAT_1400298b0.y;
    if (((local_res8.x != iVar4 + 1) || (local_res8.y != iVar8)) &&
       ((iVar4 == 0 || ((local_res8.x + 1 != iVar4 || (iVar13 = iVar12, local_res8.y != iVar8))))))
    {
      if ((local_res8.y == iVar8 + 1) && (local_res8.x == iVar4)) {
        iVar13 = 3;
      }
      else {
        if (iVar8 == 0) {
          DAT_1400296fc = 1;
          return;
        }
        if (local_res8.y + 1 != iVar8) {
          DAT_1400296fc = 1;
          return;
        }
        if (local_res8.x != iVar4) {
          DAT_1400296fc = 1;
          return;
        }
        iVar13 = 2;
      }
    }
    if ((DAT_140029054 == iVar13) &&
       (bVar7 = FUN_14001b880((ulonglong)DAT_1400298b0,DAT_140029980,
                              *(int *)(&DAT_140029000 + (longlong)iVar13 * 4),iVar13),
       (int)CONCAT71(extraout_var,bVar7) == 0)) {
      return;
    }
    FUN_14001b880((ulonglong)DAT_1400298b0,uVar5,iVar2,iVar13);
    iVar2 = *(int *)(&DAT_140029000 + (longlong)iVar13 * 4);
    uVar9 = FUN_140007b70((ulonglong)tVar6,uVar5,DAT_140029664,(uint)(DAT_140029660 == 0));
    if ((int)uVar9 == 0) {
      return;
    }
    bVar7 = FUN_14001b880((ulonglong)local_res8,uVar5,iVar2,iVar13);
    if ((int)CONCAT71(extraout_var_00,bVar7) == 0) {
      return;
    }
    DAT_140029054 = iVar2;
    DAT_1400298b0 = tVar6;
    return;
  }
  lVar10 = FUN_140009990((longlong)local_res8,DAT_140029980);
  if ((lVar10 == 0) ||
     (((piVar11 = (int *)FUN_140009990((longlong)tVar6,uVar5), piVar11 != (int *)0x0 &&
       (*(longlong *)(piVar11 + 2) != 0)) && (*piVar11 == 1)))) {
    lVar10 = FUN_140009990((longlong)tVar6,uVar5);
    if (lVar10 == 0) {
      uVar9 = FUN_140007b70((ulonglong)tVar6,uVar5,DAT_140029664,(uint)(DAT_140029660 == 0));
      if ((int)uVar9 == 0) goto LAB_1400027aa;
      iVar12 = *(int *)(&DAT_140029000 +
                       (longlong)*(int *)(&DAT_140029010 + (longlong)DAT_140029664 * 4) * 4);
    }
    else {
      lVar10 = FUN_140009990((longlong)tVar6,uVar5);
      bVar1 = *(byte *)(lVar10 + 0xe0);
      if ((bVar1 & 2) == 0) {
        if ((bVar1 & 1) == 0) {
          if ((bVar1 & 4) == 0) {
            if ((bVar1 & 8) == 0) {
              pcVar3 = (code *)swi(3);
              (*pcVar3)();
              return;
            }
            iVar12 = 1;
          }
        }
        else {
          iVar12 = 2;
        }
      }
      else {
        iVar12 = 3;
      }
    }
    DAT_1400298a8 = 1;
    DAT_1400298b0 = tVar6;
    DAT_140029054 = iVar12;
  }
  else {
LAB_1400027aa:
    DAT_1400298a8 = 0;
    DAT_140029054 = -1;
  }
  return;
}


// ===== FUN_1400029d0 @ 1400029d0 size=741

void FUN_1400029d0(char param_1,ulonglong param_2,uint param_3,uint param_4,int param_5)

{
  char cVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined1 uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar6 = (uint)param_2;
  if ((uint)DAT_140029a88 <= uVar6) {
    return;
  }
  uVar7 = (uint)(param_2 >> 0x20);
  if (DAT_140029a88._4_4_ <= uVar7) {
    return;
  }
  switch(param_1) {
  case '\0':
    FUN_140013770(param_2);
    break;
  case '\x01':
    if ((((((int)uVar6 < 0) || ((longlong)param_2 < 0)) || (DAT_140029a88._4_4_ <= uVar7)) ||
        (DAT_1400299a8 == 0)) ||
       ((cVar1 = *(char *)((ulonglong)(uVar7 * (uint)DAT_140029a88 + uVar6) + DAT_140029a90),
        cVar1 != '\a' && (cVar1 != '\x06')))) {
      FUN_14001dfb0(param_2);
      FUN_140014fd0(param_2,param_3);
      if (param_5 != 0) {
        FUN_140014a90(param_2);
        if ((uVar6 < (uint)DAT_140029a88) && (uVar7 < DAT_140029a88._4_4_)) {
          *(undefined1 *)((ulonglong)(uVar7 * (uint)DAT_140029a88 + uVar6) + DAT_140029a90) = 1;
        }
        FUN_14001c540(param_2);
        uVar3 = (ulonglong)(uVar7 * (uint)DAT_140029a88 + uVar6);
        *(undefined2 *)(&DAT_14004a9f0 + uVar3 * 2) = 0;
        *(undefined2 *)(&DAT_14006a9f0 + uVar3 * 2) = 0;
        *(undefined2 *)(&DAT_14008a9f0 + uVar3 * 2) = 0;
      }
    }
    break;
  case '\x02':
  case '\x03':
  case '\x04':
  case '\x05':
  case '\x06':
  case '\a':
  case '\b':
  case '\t':
    FUN_14001dfb0(param_2);
    FUN_140014fd0(param_2,0);
    FUN_140014a90(param_2);
    uVar5 = 1;
    switch(param_1) {
    case '\x03':
      uVar5 = 2;
      break;
    case '\x04':
      uVar5 = 3;
      break;
    case '\x05':
      uVar5 = 4;
      break;
    case '\x06':
      uVar5 = 5;
      break;
    case '\a':
      uVar5 = 6;
      break;
    case '\b':
      uVar5 = 7;
      break;
    case '\t':
      uVar5 = 8;
    }
    if ((uVar6 < (uint)DAT_140029a88) && (uVar7 < DAT_140029a88._4_4_)) {
      *(undefined1 *)((ulonglong)(uVar7 * (uint)DAT_140029a88 + uVar6) + DAT_140029a90) = uVar5;
    }
    FUN_14001c540(param_2);
    FUN_14001a4f0(param_2);
    break;
  case '\n':
    FUN_140007b70(param_2,0,param_4,(uint)(param_5 == 0));
    break;
  case '\v':
  case '\f':
  case '\r':
  case '\x0e':
  case '\x0f':
  case '\x10':
  case '\x11':
  case '\x12':
  case '\x13':
    if ((param_5 == 0) && (uVar3 = FUN_14001be70(param_1), (int)uVar3 == 0)) {
      return;
    }
    uVar6 = 0;
    switch(param_1) {
    case '\n':
      uVar6 = 1;
      break;
    case '\v':
      uVar6 = 2;
      break;
    case '\f':
      uVar6 = 3;
      break;
    case '\r':
      uVar6 = 4;
      break;
    case '\x0e':
      uVar6 = 5;
      break;
    case '\x0f':
      uVar6 = 6;
      break;
    case '\x10':
      uVar6 = 7;
      break;
    case '\x11':
      uVar6 = 8;
      break;
    case '\x12':
      uVar6 = 9;
      break;
    case '\x13':
      uVar6 = 10;
    }
    uVar4 = FUN_1400127b0(param_2,param_3,uVar6,(ulonglong)param_4,(uint)(param_5 == 0));
    iVar2 = (int)uVar4;
    goto joined_r0x000140002c8d;
  case '\x14':
  case '\x15':
    if ((param_5 == 0) && (uVar3 = FUN_14001be70(param_1), (int)uVar3 == 0)) {
      return;
    }
    uVar4 = FUN_140012520(param_2,(uint)(param_1 == '\x15'),(uint)(param_5 == 0));
    iVar2 = (int)uVar4;
joined_r0x000140002c8d:
    if ((iVar2 == 0) && (param_5 == 0)) {
      FUN_1400148e0(param_1);
    }
  }
  return;
}


// ===== FUN_140002d30 @ 140002d30 size=138

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140002d30(char param_1)

{
  undefined8 uVar1;
  tagPOINT local_res10 [3];
  
  if (param_1 == '\n') {
    FUN_140002700();
    return;
  }
  local_res10[0].x = 0;
  local_res10[0].y = 0;
  uVar1 = FUN_140011060(local_res10);
  if (((int)uVar1 != 0) &&
     (((DAT_1400296fc == 0 || (local_res10[0].x != DAT_1400298a0)) ||
      (local_res10[0].y != DAT_1400298a4)))) {
    _DAT_1400298a0 = local_res10[0];
    DAT_1400296fc = 1;
    FUN_1400029d0(param_1,(ulonglong)local_res10[0],DAT_140029980,DAT_140029664,DAT_140029660);
  }
  return;
}


// ===== FUN_140002dc0 @ 140002dc0 size=2311

void FUN_140002dc0(int *param_1,int *param_2)

{
  code *pcVar1;
  longlong lVar2;
  int *piVar3;
  longlong lVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  undefined1 *puVar10;
  int *piVar11;
  uint uVar12;
  uint uVar13;
  undefined1 auVar14 [16];
  undefined8 uStack_70;
  undefined1 local_68 [80];
  
  piVar6 = (int *)0x0;
  piVar11 = param_1 + 0x36;
  puVar10 = local_68;
  for (lVar2 = 0x48; lVar2 != 0; lVar2 = lVar2 + -1) {
    *puVar10 = (char)*piVar11;
    piVar11 = (int *)((longlong)piVar11 + 1);
    puVar10 = puVar10 + 1;
  }
  piVar11 = piVar6;
  uVar8 = DAT_140029a88._4_4_;
  uVar13 = (uint)DAT_140029a88;
  if (param_1[0xc] != 0) {
    do {
      piVar3 = piVar6;
      if (param_1[0xb] != 0) {
        do {
          uVar12 = param_1[8] + (int)piVar3;
          uVar7 = param_1[9] + (int)piVar11;
          if (((uVar12 < uVar13) && (uVar7 < uVar8)) &&
             (*(int *)(DAT_140029a98 +
                      (ulonglong)((param_1[10] * uVar8 + uVar7) * uVar13 + uVar12) * 4) != 0)) {
            *(undefined1 *)
             ((ulonglong)(param_1[10] * uVar8 * uVar13) +
             (ulonglong)(uVar12 + uVar7 * uVar13) + DAT_140029aa0) = 0;
            uVar8 = DAT_140029a88._4_4_;
            uVar13 = (uint)DAT_140029a88;
          }
          uVar7 = (int)piVar3 + 1;
          piVar3 = (int *)(ulonglong)uVar7;
        } while (uVar7 < (uint)param_1[0xb]);
      }
      uVar7 = (int)piVar11 + 1;
      piVar11 = (int *)(ulonglong)uVar7;
    } while (uVar7 < (uint)param_1[0xc]);
  }
  *param_1 = *param_2;
  *(undefined8 *)(param_1 + 0xb) = *(undefined8 *)(param_2 + 1);
  *(undefined8 *)(param_1 + 4) = *(undefined8 *)(param_2 + 4);
  *(undefined8 *)(param_1 + 6) = *(undefined8 *)(param_2 + 6);
  param_1[0xe] = 0;
  param_1[0x19] = param_2[8];
  *(undefined8 *)(param_1 + 0x48) = *(undefined8 *)(param_2 + 0x1c);
  piVar11 = param_2 + 10;
  piVar3 = param_1 + 0x36;
  for (lVar2 = 0x48; lVar2 != 0; lVar2 = lVar2 + -1) {
    *(char *)piVar3 = (char)*piVar11;
    piVar11 = (int *)((longlong)piVar11 + 1);
    piVar3 = (int *)((longlong)piVar3 + 1);
  }
  if ((char)param_1[0x38] != '\0') {
    uVar13 = param_1[8] + param_1[0x36];
    uVar8 = param_1[0x37] + param_1[9];
    if (((uVar13 < (uint)DAT_140029a88) && (uVar8 < DAT_140029a88._4_4_)) &&
       (*(int *)(DAT_140029a98 +
                (ulonglong)
                ((param_1[10] * DAT_140029a88._4_4_ + uVar8) * (uint)DAT_140029a88 + uVar13) * 4) !=
        0)) {
      *(char *)((ulonglong)(param_1[10] * DAT_140029a88._4_4_ * (uint)DAT_140029a88) +
               (ulonglong)(uVar13 + uVar8 * (uint)DAT_140029a88) + DAT_140029aa0) =
           (char)param_1[0x38];
    }
  }
  if (*(char *)((longlong)param_1 + 0xe9) != '\0') {
    uVar13 = *(int *)((longlong)param_1 + 0xe1) + param_1[8];
    uVar8 = *(int *)((longlong)param_1 + 0xe5) + param_1[9];
    if (((uVar13 < (uint)DAT_140029a88) && (uVar8 < DAT_140029a88._4_4_)) &&
       (*(int *)(DAT_140029a98 +
                (ulonglong)
                ((param_1[10] * DAT_140029a88._4_4_ + uVar8) * (uint)DAT_140029a88 + uVar13) * 4) !=
        0)) {
      *(char *)((ulonglong)(param_1[10] * DAT_140029a88._4_4_ * (uint)DAT_140029a88) +
               (ulonglong)(uVar13 + uVar8 * (uint)DAT_140029a88) + DAT_140029aa0) =
           *(char *)((longlong)param_1 + 0xe9);
    }
  }
  if (*(char *)((longlong)param_1 + 0xf2) != '\0') {
    uVar13 = *(int *)((longlong)param_1 + 0xea) + param_1[8];
    uVar8 = *(int *)((longlong)param_1 + 0xee) + param_1[9];
    if (((uVar13 < (uint)DAT_140029a88) && (uVar8 < DAT_140029a88._4_4_)) &&
       (*(int *)(DAT_140029a98 +
                (ulonglong)
                ((param_1[10] * DAT_140029a88._4_4_ + uVar8) * (uint)DAT_140029a88 + uVar13) * 4) !=
        0)) {
      *(char *)((ulonglong)(param_1[10] * DAT_140029a88._4_4_ * (uint)DAT_140029a88) +
               (ulonglong)(uVar13 + uVar8 * (uint)DAT_140029a88) + DAT_140029aa0) =
           *(char *)((longlong)param_1 + 0xf2);
    }
  }
  if (*(char *)((longlong)param_1 + 0xfb) != '\0') {
    uVar13 = *(int *)((longlong)param_1 + 0xf3) + param_1[8];
    uVar8 = *(int *)((longlong)param_1 + 0xf7) + param_1[9];
    if (((uVar13 < (uint)DAT_140029a88) && (uVar8 < DAT_140029a88._4_4_)) &&
       (*(int *)(DAT_140029a98 +
                (ulonglong)
                ((param_1[10] * DAT_140029a88._4_4_ + uVar8) * (uint)DAT_140029a88 + uVar13) * 4) !=
        0)) {
      *(char *)((ulonglong)(param_1[10] * DAT_140029a88._4_4_ * (uint)DAT_140029a88) +
               (ulonglong)(uVar13 + uVar8 * (uint)DAT_140029a88) + DAT_140029aa0) =
           *(char *)((longlong)param_1 + 0xfb);
    }
  }
  if ((char)param_1[0x41] != '\0') {
    uVar13 = param_1[0x3f] + param_1[8];
    uVar8 = param_1[0x40] + param_1[9];
    if (((uVar13 < (uint)DAT_140029a88) && (uVar8 < DAT_140029a88._4_4_)) &&
       (*(int *)(DAT_140029a98 +
                (ulonglong)
                ((param_1[10] * DAT_140029a88._4_4_ + uVar8) * (uint)DAT_140029a88 + uVar13) * 4) !=
        0)) {
      *(char *)((ulonglong)(param_1[10] * DAT_140029a88._4_4_ * (uint)DAT_140029a88) +
               (ulonglong)(uVar13 + uVar8 * (uint)DAT_140029a88) + DAT_140029aa0) =
           (char)param_1[0x41];
    }
  }
  if (*(char *)((longlong)param_1 + 0x10d) != '\0') {
    uVar13 = *(int *)((longlong)param_1 + 0x105) + param_1[8];
    uVar8 = *(int *)((longlong)param_1 + 0x109) + param_1[9];
    if (((uVar13 < (uint)DAT_140029a88) && (uVar8 < DAT_140029a88._4_4_)) &&
       (*(int *)(DAT_140029a98 +
                (ulonglong)
                ((param_1[10] * DAT_140029a88._4_4_ + uVar8) * (uint)DAT_140029a88 + uVar13) * 4) !=
        0)) {
      *(char *)((ulonglong)(param_1[10] * DAT_140029a88._4_4_ * (uint)DAT_140029a88) +
               (ulonglong)(uVar13 + uVar8 * (uint)DAT_140029a88) + DAT_140029aa0) =
           *(char *)((longlong)param_1 + 0x10d);
    }
  }
  if (*(char *)((longlong)param_1 + 0x116) != '\0') {
    uVar13 = *(int *)((longlong)param_1 + 0x10e) + param_1[8];
    uVar8 = *(int *)((longlong)param_1 + 0x112) + param_1[9];
    if (((uVar13 < (uint)DAT_140029a88) && (uVar8 < DAT_140029a88._4_4_)) &&
       (*(int *)(DAT_140029a98 +
                (ulonglong)
                ((param_1[10] * DAT_140029a88._4_4_ + uVar8) * (uint)DAT_140029a88 + uVar13) * 4) !=
        0)) {
      *(char *)((ulonglong)(param_1[10] * DAT_140029a88._4_4_ * (uint)DAT_140029a88) +
               (ulonglong)(uVar13 + uVar8 * (uint)DAT_140029a88) + DAT_140029aa0) =
           *(char *)((longlong)param_1 + 0x116);
    }
  }
  if (*(char *)((longlong)param_1 + 0x11f) != '\0') {
    uVar13 = *(int *)((longlong)param_1 + 0x117) + param_1[8];
    uVar8 = *(int *)((longlong)param_1 + 0x11b) + param_1[9];
    if (((uVar13 < (uint)DAT_140029a88) && (uVar8 < DAT_140029a88._4_4_)) &&
       (*(int *)(DAT_140029a98 +
                (ulonglong)
                ((param_1[10] * DAT_140029a88._4_4_ + uVar8) * (uint)DAT_140029a88 + uVar13) * 4) !=
        0)) {
      *(char *)((ulonglong)(param_1[10] * DAT_140029a88._4_4_ * (uint)DAT_140029a88) +
               (ulonglong)(uVar13 + uVar8 * (uint)DAT_140029a88) + DAT_140029aa0) =
           *(char *)((longlong)param_1 + 0x11f);
    }
  }
  piVar11 = param_1 + 0x36;
  lVar2 = 8;
  uVar8 = DAT_140029a88._4_4_;
  uVar13 = (uint)DAT_140029a88;
  do {
    if ((char)piVar11[2] != '\0') {
      FUN_14001f1e0(param_1);
      uVar7 = *piVar11 + param_1[8] + 1;
      uVar13 = piVar11[1] + param_1[9];
      uVar8 = param_1[10];
      piVar3 = piVar6;
      if (((((uVar7 < (uint)DAT_140029a88) && (uVar13 < DAT_140029a88._4_4_)) &&
           (uVar8 < DAT_1400299a8)) && ((-1 < (int)uVar7 && (-1 < (int)uVar13)))) &&
         (-1 < (int)uVar8)) {
        uVar8 = *(uint *)(DAT_140029a98 +
                         (ulonglong)
                         ((uVar8 * DAT_140029a88._4_4_ + uVar13) * (uint)DAT_140029a88 + uVar7) * 4)
        ;
        if ((uVar8 != 0) && (uVar8 < DAT_14002a870)) {
          if ((ulonglong)DAT_14002a870 <= (ulonglong)uVar8) {
            pcVar1 = (code *)swi(3);
            (*pcVar1)();
            return;
          }
          piVar3 = *(int **)(DAT_14002a868 + (ulonglong)uVar8 * 8);
        }
      }
      FUN_14001f1e0(piVar3);
      uVar7 = *piVar11 + param_1[8] + -1;
      uVar13 = piVar11[1] + param_1[9];
      uVar8 = param_1[10];
      piVar3 = piVar6;
      if ((((uVar7 < (uint)DAT_140029a88) && (uVar13 < DAT_140029a88._4_4_)) &&
          (uVar8 < DAT_1400299a8)) &&
         (((-1 < (int)uVar7 && (-1 < (int)uVar13)) && (-1 < (int)uVar8)))) {
        uVar8 = *(uint *)(DAT_140029a98 +
                         (ulonglong)
                         ((uVar8 * DAT_140029a88._4_4_ + uVar13) * (uint)DAT_140029a88 + uVar7) * 4)
        ;
        if ((uVar8 != 0) && (uVar8 < DAT_14002a870)) {
          if ((ulonglong)DAT_14002a870 <= (ulonglong)uVar8) {
            pcVar1 = (code *)swi(3);
            (*pcVar1)();
            return;
          }
          piVar3 = *(int **)(DAT_14002a868 + (ulonglong)uVar8 * 8);
        }
      }
      FUN_14001f1e0(piVar3);
      uVar7 = param_1[9] + 1 + piVar11[1];
      uVar13 = param_1[8] + *piVar11;
      uVar8 = param_1[10];
      piVar3 = piVar6;
      if ((((uVar13 < (uint)DAT_140029a88) && (uVar7 < DAT_140029a88._4_4_)) &&
          (uVar8 < DAT_1400299a8)) &&
         (((-1 < (int)uVar13 && (-1 < (int)uVar7)) && (-1 < (int)uVar8)))) {
        uVar8 = *(uint *)(DAT_140029a98 +
                         (ulonglong)
                         ((uVar8 * DAT_140029a88._4_4_ + uVar7) * (uint)DAT_140029a88 + uVar13) * 4)
        ;
        if ((uVar8 != 0) && (uVar8 < DAT_14002a870)) {
          if ((ulonglong)DAT_14002a870 <= (ulonglong)uVar8) {
            pcVar1 = (code *)swi(3);
            (*pcVar1)();
            return;
          }
          piVar3 = *(int **)(DAT_14002a868 + (ulonglong)uVar8 * 8);
        }
      }
      FUN_14001f1e0(piVar3);
      uVar7 = param_1[9] + -1 + piVar11[1];
      uVar13 = param_1[8] + *piVar11;
      uVar8 = param_1[10];
      piVar3 = piVar6;
      if (((((uVar13 < (uint)DAT_140029a88) && (uVar7 < DAT_140029a88._4_4_)) &&
           (uVar8 < DAT_1400299a8)) && ((-1 < (int)uVar13 && (-1 < (int)uVar7)))) &&
         (-1 < (int)uVar8)) {
        uVar8 = *(uint *)(DAT_140029a98 +
                         (ulonglong)
                         ((uVar8 * DAT_140029a88._4_4_ + uVar7) * (uint)DAT_140029a88 + uVar13) * 4)
        ;
        if ((uVar8 != 0) && (uVar8 < DAT_14002a870)) {
          if ((ulonglong)DAT_14002a870 <= (ulonglong)uVar8) {
            pcVar1 = (code *)swi(3);
            (*pcVar1)();
            return;
          }
          piVar3 = *(int **)(DAT_14002a868 + (ulonglong)uVar8 * 8);
        }
      }
      FUN_14001f1e0(piVar3);
      uVar8 = DAT_140029a88._4_4_;
      uVar13 = (uint)DAT_140029a88;
    }
    piVar11 = (int *)((longlong)piVar11 + 9);
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  if (*param_1 - 7U < 3) {
    lVar2 = *(longlong *)(param_1 + 8);
    uVar12 = param_1[10] + 1;
    uVar7 = (uint)lVar2;
    piVar11 = piVar6;
    if ((((uVar7 < uVar13) && (uVar5 = (uint)((ulonglong)lVar2 >> 0x20), uVar5 < uVar8)) &&
        (uVar12 < DAT_1400299a8)) &&
       (((-1 < (int)uVar7 && (-1 < lVar2)) &&
        ((-1 < (int)uVar12 && ((uVar7 < uVar13 && (uVar5 < uVar8)))))))) {
      uVar8 = *(uint *)(DAT_140029a98 + (ulonglong)((uVar12 * uVar8 + uVar5) * uVar13 + uVar7) * 4);
      if ((uVar8 != 0) && (uVar8 < DAT_14002a870)) {
        if ((ulonglong)DAT_14002a870 <= (ulonglong)uVar8) {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
        piVar11 = *(int **)(DAT_14002a868 + (ulonglong)uVar8 * 8);
      }
    }
    FUN_14001f1e0(piVar11);
    lVar2 = *(longlong *)(param_1 + 8);
    uVar13 = param_1[10] - 1;
    uVar8 = (uint)lVar2;
    piVar11 = piVar6;
    if ((((uVar8 < (uint)DAT_140029a88) &&
         (uVar7 = (uint)((ulonglong)lVar2 >> 0x20), uVar7 < DAT_140029a88._4_4_)) &&
        (uVar13 < DAT_1400299a8)) &&
       (((-1 < (int)uVar8 && (-1 < lVar2)) &&
        ((-1 < (int)uVar13 && ((uVar8 < (uint)DAT_140029a88 && (uVar7 < DAT_140029a88._4_4_))))))))
    {
      uVar8 = *(uint *)(DAT_140029a98 +
                       (ulonglong)
                       ((uVar13 * DAT_140029a88._4_4_ + uVar7) * (uint)DAT_140029a88 + uVar8) * 4);
      if ((uVar8 != 0) && (uVar8 < DAT_14002a870)) {
        if ((ulonglong)DAT_14002a870 <= (ulonglong)uVar8) {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
        piVar11 = *(int **)(DAT_14002a868 + (ulonglong)uVar8 * 8);
      }
    }
    FUN_14001f1e0(piVar11);
  }
  if (*param_1 == 10) {
    param_1[0x58] = 0;
    uVar8 = param_1[9] - 2;
    lVar2 = DAT_140029ac8;
    uVar13 = DAT_1400299ac;
    if (uVar8 <= param_1[9] + 2U) {
      do {
        iVar9 = param_1[8] + -4;
        if (iVar9 < param_1[8]) {
          do {
            if (4 < (uint)param_1[0x58]) break;
            piVar11 = piVar6;
            if (uVar13 != 0) {
              do {
                if ((*(int *)((longlong)piVar11 * 0x40 + lVar2) == iVar9) &&
                   (*(uint *)((longlong)piVar11 * 0x40 + 4 + lVar2) == uVar8)) {
                  if ((-1 < (int)piVar11) && (lVar4 = (longlong)piVar11 * 0x40 + lVar2, lVar4 != 0))
                  {
                    *(longlong *)(param_1 + (ulonglong)(uint)param_1[0x58] * 2 + 0x4e) = lVar4;
                    param_1[0x58] = param_1[0x58] + 1;
                    lVar2 = DAT_140029ac8;
                    uVar13 = DAT_1400299ac;
                  }
                  break;
                }
                uVar7 = (int)piVar11 + 1;
                piVar11 = (int *)(ulonglong)uVar7;
              } while (uVar7 < uVar13);
            }
            iVar9 = iVar9 + 1;
          } while (iVar9 < param_1[8]);
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 <= param_1[9] + 2U);
    }
  }
  lVar2 = *(longlong *)(param_1 + 0x48);
  if (lVar2 == 0) {
    if (iRam0000000000000010 == 0) goto LAB_140003678;
    lVar2 = *plRam0000000000000008;
  }
  else {
    if (*(int *)(lVar2 + 0x10) == 0) {
LAB_140003678:
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    piVar11 = piVar6;
    piVar3 = piVar6;
    if (*(longlong *)(param_1 + 0x4a) != 0) {
      do {
        if ((int *)(ulonglong)*(uint *)(lVar2 + 0x10) <= piVar11) {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
        piVar3 = piVar11;
        if (*(longlong *)(*(longlong *)(lVar2 + 8) + (longlong)piVar11 * 8) ==
            *(longlong *)(param_1 + 0x4a)) break;
        lVar2 = *(longlong *)(param_1 + 0x48);
        uVar8 = (int)piVar11 + 1;
        piVar11 = (int *)(ulonglong)uVar8;
        piVar3 = piVar6;
      } while (uVar8 < *(uint *)(lVar2 + 0x10));
    }
    if ((int *)(ulonglong)*(uint *)(*(longlong *)(param_1 + 0x48) + 0x10) <= piVar3) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    lVar2 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x48) + 8) + (longlong)piVar3 * 8);
  }
  if (lVar2 == 0) {
    auVar14 = (undefined1  [16])0x0;
  }
  else {
    auVar14._8_8_ = uStack_70;
    auVar14._0_8_ = lVar2;
    auVar14 = vinsertps_avx(auVar14,ZEXT416(*(uint *)(lVar2 + 0x24)),0x20);
  }
  *(undefined1 (*) [16])(param_1 + 0x4a) = auVar14;
  return;
}


// ===== FUN_1400036d0 @ 1400036d0 size=869

void FUN_1400036d0(longlong param_1)

{
  char *pcVar1;
  undefined8 *puVar2;
  char cVar3;
  uint uVar4;
  undefined4 uVar5;
  code *pcVar6;
  float fVar7;
  float fVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined1 (*pauVar12) [16];
  longlong lVar13;
  ulonglong uVar14;
  longlong lVar15;
  uint *puVar16;
  ulonglong uVar17;
  int iVar18;
  uint uVar19;
  longlong lVar21;
  undefined1 auVar22 [16];
  undefined1 auVar23 [16];
  undefined1 auVar24 [64];
  undefined1 auVar25 [16];
  undefined1 auVar26 [64];
  undefined1 auVar27 [16];
  undefined1 auVar28 [64];
  undefined8 local_88;
  undefined1 local_78 [96];
  ulonglong uVar20;
  
  uVar4 = *(uint *)(param_1 + 0x30);
  if (uVar4 != 0) {
    auVar24 = ZEXT464((0.5f));
    auVar26 = ZEXT464((inff));
    auVar28 = ZEXT464((1f));
    uVar17 = 0;
    do {
      auVar25 = auVar26._0_16_;
      auVar23 = auVar24._0_16_;
      auVar27 = auVar28._0_16_;
      if (uVar4 <= uVar17) {
        pcVar6 = (code *)swi(3);
        (*pcVar6)();
        return;
      }
      pcVar1 = (char *)(*(longlong *)(param_1 + 0x28) + uVar17 * 0x28);
      if ((*(int *)(*(longlong *)(param_1 + 0x28) + 0x24 + uVar17 * 0x28) != 0) &&
         (*(int *)(pcVar1 + 0x20) < 0)) {
        iVar18 = -1;
        uVar4 = *(uint *)(param_1 + 0x18);
        auVar26 = ZEXT1664(auVar25);
        if (uVar4 != 0) {
          uVar14 = (ulonglong)uVar4;
          uVar20 = 0;
          do {
            if (uVar14 <= uVar20) {
              pcVar6 = (code *)swi(3);
              (*pcVar6)();
              return;
            }
            lVar15 = *(longlong *)(param_1 + 0x10);
            lVar21 = uVar20 * 0x2080;
            if ((*(char *)(lVar15 + 0x34 + lVar21) == '\0') &&
               (*(int *)(lVar15 + 0x58 + lVar21) == 0)) {
              uVar14 = (ulonglong)*(uint *)(param_1 + 0x18);
              if (uVar14 <= uVar20) {
                pcVar6 = (code *)swi(3);
                (*pcVar6)();
                return;
              }
              fVar7 = *(float *)(lVar21 + lVar15) -
                      ((float)(*(ulonglong *)(pcVar1 + 1) & 0xffffffff) + auVar24._0_4_);
              fVar8 = *(float *)(lVar21 + 4 + lVar15) -
                      ((float)(*(ulonglong *)(pcVar1 + 1) >> 0x20) + auVar24._0_4_);
              fVar7 = fVar8 * fVar8 + fVar7 * fVar7;
              if ((iVar18 < 0) || (fVar7 < auVar26._0_4_)) {
                auVar26 = ZEXT464((uint)fVar7);
                iVar18 = (int)uVar20;
              }
            }
            uVar19 = (int)uVar20 + 1;
            uVar20 = (ulonglong)uVar19;
          } while (uVar19 < uVar4);
        }
        puVar16 = (uint *)(param_1 + 0x18);
        if (iVar18 < 0) {
          return;
        }
        if (*(code **)(param_1 + 0x68) == (code *)0x0) {
          auVar22 = *(undefined1 (*) [16])(param_1 + 0x50);
        }
        else {
          pauVar12 = (undefined1 (*) [16])
                     (**(code **)(param_1 + 0x68))
                               (local_78,*(undefined8 *)(pcVar1 + 1),*(undefined8 *)(param_1 + 0x70)
                               );
          auVar22 = *pauVar12;
        }
        lVar15 = (longlong)iVar18;
        if ((iVar18 < 0) || ((longlong)(ulonglong)*puVar16 <= lVar15)) {
          pcVar6 = (code *)swi(3);
          (*pcVar6)();
          return;
        }
        lVar21 = *(longlong *)(param_1 + 0x10);
        lVar13 = lVar15;
        if (iVar18 < 0) {
          lVar13 = (ulonglong)*puVar16 + lVar15;
        }
        lVar13 = lVar13 * 0x2080;
        local_88 = auVar22._0_8_;
        *(undefined8 *)(lVar13 + 0x10 + lVar21) = local_88;
        *(undefined8 *)(lVar13 + 0x2064 + lVar21) = 0;
        *(undefined8 *)(lVar13 + 0x206c + lVar21) = 0;
        *(undefined4 *)(lVar13 + 0x2074 + lVar21) = 0;
        uVar5 = vextractps_avx(auVar22,2);
        *(undefined4 *)(lVar13 + 0x18 + lVar21) = uVar5;
        uVar5 = vextractps_avx(auVar22,3);
        *(undefined4 *)(lVar13 + 0x1c + lVar21) = uVar5;
        if ((iVar18 < 0) || ((longlong)(ulonglong)*puVar16 <= lVar15)) {
          pcVar6 = (code *)swi(3);
          (*pcVar6)();
          return;
        }
        lVar21 = *(longlong *)(param_1 + 0x10);
        if (iVar18 < 0) {
          lVar15 = (ulonglong)*puVar16 + lVar15;
        }
        lVar15 = lVar15 * 0x2080;
        uVar20 = *(ulonglong *)(lVar15 + 0x10 + lVar21);
        *(undefined8 *)(lVar15 + 0x2064 + lVar21) = 0;
        *(undefined8 *)(lVar15 + 0x206c + lVar21) = 0;
        *(undefined4 *)(lVar15 + 0x2074 + lVar21) = 0;
        lVar13 = (longlong)iVar18;
        *(undefined8 *)(lVar15 + 8 + lVar21) = 0;
        *(float *)(lVar15 + lVar21) =
             (float)(uVar20 & 0xffffffff) + *(float *)(lVar15 + 0x18 + lVar21);
        *(float *)(lVar15 + 4 + lVar21) =
             (float)(uVar20 >> 0x20) + *(float *)(lVar15 + 0x1c + lVar21);
        if ((iVar18 < 0) || ((longlong)(ulonglong)*(uint *)(param_1 + 0x18) <= lVar13)) {
          pcVar6 = (code *)swi(3);
          (*pcVar6)();
          return;
        }
        lVar15 = *(longlong *)(param_1 + 0x10);
        if (iVar18 < 0) {
          lVar13 = (ulonglong)*(uint *)(param_1 + 0x18) + lVar13;
        }
        uVar9 = *(undefined8 *)(pcVar1 + 8);
        uVar10 = *(undefined8 *)(pcVar1 + 0x10);
        uVar11 = *(undefined8 *)(pcVar1 + 0x18);
        lVar13 = lVar13 * 0x2080;
        puVar2 = (undefined8 *)(lVar13 + 0x38 + lVar15);
        *puVar2 = *(undefined8 *)pcVar1;
        puVar2[1] = uVar9;
        puVar2[2] = uVar10;
        puVar2[3] = uVar11;
        cVar3 = *pcVar1;
        *(undefined4 *)(lVar13 + 0x24 + lVar15) = 0;
        *(undefined4 *)(lVar13 + 0x2c + lVar15) = 0;
        *(undefined8 *)(lVar13 + 0x2064 + lVar15) = 0;
        *(uint *)(lVar13 + 0x58 + lVar15) = (uint)(cVar3 != '\0');
        *(undefined8 *)(lVar13 + 0x206c + lVar15) = 0;
        *(bool *)(lVar13 + 0x34 + lVar15) = cVar3 != '\0';
        *(undefined8 *)(lVar13 + 8 + lVar15) = 0;
        *(undefined4 *)(lVar13 + 0x2074 + lVar15) = 0;
        auVar24 = ZEXT1664(auVar23);
        auVar26 = ZEXT1664(auVar25);
        auVar28 = ZEXT1664(auVar27);
        FUN_140012a70(&DAT_14002a8c0,auVar27._0_4_);
        *(int *)(pcVar1 + 0x20) = iVar18;
        FUN_140012eb0(param_1,1,iVar18,(undefined8 *)pcVar1);
      }
      uVar4 = *(uint *)(param_1 + 0x30);
      uVar19 = (int)uVar17 + 1;
      uVar17 = (ulonglong)uVar19;
    } while (uVar19 < uVar4);
  }
  return;
}


// ===== FUN_140003a40 @ 140003a40 size=469

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_140003a40(void)

{
  undefined1 auVar1 [12];
  BOOL BVar2;
  DWORD DVar3;
  int iVar4;
  uint uVar5;
  longlong lVar6;
  int local_res10 [2];
  LARGE_INTEGER local_res18;
  ulonglong local_res20;
  
  FUN_14000d300(FUN_140007fb0);
  do {
    if (DAT_140029974 != 0) {
      return 0;
    }
    lVar6 = (longlong)(((double)DAT_14002a97c * (double)_DAT_14002a9a8) / (double)DAT_14002a984);
    if (DAT_14002a9b8 == (HANDLE)0x0) {
LAB_140003b20:
      Sleep((DWORD)(lVar6 / 20000));
    }
    else {
      local_res18.QuadPart = -(lVar6 / 2);
      BVar2 = SetWaitableTimer(DAT_14002a9b8,&local_res18,0,(PTIMERAPCROUTINE)0x0,(LPVOID)0x0,1);
      if ((BVar2 == 0) ||
         (DVar3 = WaitForSingleObject(DAT_14002a9b8,0xffffffff), DVar3 == 0xffffffff))
      goto LAB_140003b20;
    }
    iVar4 = (**(code **)(*DAT_14002a968 + 0x30))(DAT_14002a968,local_res10);
    if (((iVar4 == 0) && (uVar5 = DAT_14002a97c - local_res10[0], uVar5 != 0)) &&
       (iVar4 = (**(code **)(*DAT_14002a970 + 0x18))(DAT_14002a970,uVar5), iVar4 == 0)) {
      auVar1._4_8_ = SUB128(ZEXT812(0),4);
      auVar1._0_4_ = (float)uVar5 / (float)*(uint *)(&DAT_140023fa0 + (longlong)DAT_14002a978 * 4);
      (*DAT_14002a9c0)(DAT_14002a9b0,uVar5,DAT_14002a982,auVar1._0_8_);
      FUN_1400075e0(local_res20,DAT_14002a9b0,uVar5,(uint)DAT_14002a982,DAT_14002a978);
      (**(code **)(*DAT_14002a970 + 0x20))(DAT_14002a970,uVar5);
    }
  } while( true );
}


// ===== FUN_140003c20 @ 140003c20 size=950

/* WARNING: Removing unreachable block (ram,0x000140003d67) */

void FUN_140003c20(float param_1)

{
  float fVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  float fVar4;
  uint uVar5;
  float fVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  longlong lVar9;
  longlong lVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  uint uVar13;
  uint uVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  ulonglong *puVar17;
  undefined1 auVar18 [16];
  undefined1 local_68 [16];
  
  fVar6 = (1000f);
  uVar5 = (100f);
  fVar4 = (0.5f);
  uVar13 = 0;
  if (DAT_1400299ac != 0) {
    do {
      puVar17 = (ulonglong *)((ulonglong)uVar13 * 0x40 + DAT_140029ac8);
      fVar1 = *(float *)(puVar17 + 1);
      *(float *)(puVar17 + 1) = fVar1 - param_1;
      if (fVar1 - param_1 <= 0.0) {
        uVar7 = DAT_140029ab8 ^ DAT_140029aa8;
        uVar11 = ((DAT_140029ac0 + DAT_140029aa8) * 0x800000 | DAT_140029ac0 + DAT_140029aa8 >> 0x1f
                 ) + DAT_140029aa8;
        DAT_140029ab8 = uVar7 ^ DAT_140029ab0 << 0x11;
        uVar15 = DAT_140029ab0 ^ DAT_140029ac0;
        DAT_140029aa8 = DAT_140029aa8 ^ uVar15;
        DAT_140029ac0 = uVar15 >> 0x13 | uVar15 << 0x2d;
        DAT_140029ab0 = DAT_140029ab0 ^ uVar7;
        *(float *)(puVar17 + 1) = (float)(uVar11 % 0xdd + 0x1e);
        if (*(int *)((longlong)puVar17 + 0xc) != 3) {
          uVar7 = DAT_140029ac0 + DAT_140029aa8;
          uVar16 = DAT_140029ab8 ^ DAT_140029aa8 ^ DAT_140029ab0;
          uVar11 = DAT_140029ab0 ^ DAT_140029ac0;
          DAT_140029ab8 = DAT_140029ab8 ^ DAT_140029aa8 ^ DAT_140029ab0 << 0x11;
          uVar8 = uVar11 ^ DAT_140029aa8;
          DAT_140029ac0 = uVar11 >> 0x13 | uVar11 << 0x2d;
          uVar12 = DAT_140029ac0 ^ uVar16;
          uVar15 = ((DAT_140029ac0 + uVar8) * 0x800000 | DAT_140029ac0 + uVar8 >> 0x1f) + uVar8;
          auVar2._8_8_ = 0;
          auVar2._0_8_ = uVar15;
          lVar9 = SUB168(ZEXT816(0x624dd2f1a9fbe77) * auVar2,8);
          uVar11 = (uVar12 >> 0x13 | uVar12 << 0x2d) + (uVar12 ^ uVar8);
          uVar11 = (uVar12 ^ uVar8) + (uVar11 * 0x800000 | uVar11 >> 0x1f);
          auVar3._8_8_ = 0;
          auVar3._0_8_ = uVar11;
          lVar10 = SUB168(ZEXT816(0x624dd2f1a9fbe77) * auVar3,8);
          local_68[8] = (&DAT_140024c70)[((uVar7 * 0x800000 | uVar7 >> 0x1f) + DAT_140029aa8) % 0xb]
          ;
          auVar18._4_12_ = local_68._4_12_;
          auVar18._0_4_ =
               ((float)(*puVar17 & 0xffffffff) +
               (float)(uVar15 + ((uVar15 - lVar9 >> 1) + lVar9 >> 9) * -1000) / fVar6) - fVar4;
          auVar2 = vinsertps_avx(auVar18,ZEXT416((uint)(((float)(*puVar17 >> 0x20) +
                                                        (float)(uVar11 + ((uVar11 - lVar10 >> 1) +
                                                                          lVar10 >> 9) * -1000) /
                                                        fVar6) - fVar4)),0x10);
          local_68 = vinsertps_avx(auVar2,ZEXT416(uVar5),0x30);
          DAT_140029aa8 = uVar8;
          DAT_140029ab0 = uVar16;
          *(undefined1 (*) [16])(puVar17 + ((ulonglong)*(uint *)((longlong)puVar17 + 0xc) + 1) * 2)
               = local_68;
          *(int *)((longlong)puVar17 + 0xc) = *(int *)((longlong)puVar17 + 0xc) + 1;
        }
      }
      uVar14 = 0;
      if (*(int *)((longlong)puVar17 + 0xc) != 0) {
        do {
          uVar7 = (ulonglong)uVar14;
          fVar1 = *(float *)((longlong)puVar17 + uVar7 * 0x10 + 0x1c) - param_1;
          *(float *)((longlong)puVar17 + uVar7 * 0x10 + 0x1c) = fVar1;
          if (0.0 < fVar1) {
            uVar14 = uVar14 + 1;
          }
          else {
            uVar11 = (puVar17 + ((ulonglong)(*(int *)((longlong)puVar17 + 0xc) - 1) + 1) * 2)[1];
            puVar17[uVar7 * 2 + 2] =
                 puVar17[((ulonglong)(*(int *)((longlong)puVar17 + 0xc) - 1) + 1) * 2];
            (puVar17 + uVar7 * 2 + 2)[1] = uVar11;
            *(int *)((longlong)puVar17 + 0xc) = *(int *)((longlong)puVar17 + 0xc) + -1;
          }
        } while (uVar14 < *(uint *)((longlong)puVar17 + 0xc));
      }
      uVar13 = uVar13 + 1;
    } while (uVar13 < DAT_1400299ac);
  }
  return;
}


// ===== FUN_140003fe0 @ 140003fe0 size=789

undefined8 FUN_140003fe0(undefined8 param_1,longlong param_2,longlong param_3)

{
  code *pcVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  undefined8 uVar6;
  uint uVar7;
  int iVar8;
  ulonglong uVar9;
  uint uVar10;
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  undefined1 auVar14 [16];
  uint uStackX_14;
  uint uStackX_1c;
  float local_78;
  float fStack_74;
  
  local_78 = (float)param_1;
  if ((((local_78 < 0.0) ||
       (fStack_74 = (float)((ulonglong)param_1 >> 0x20), fVar4 = fStack_74, fStack_74 < 0.0)) ||
      ((float)(uint)DAT_140029a88 <= local_78)) || ((float)DAT_140029a88._4_4_ <= fStack_74)) {
LAB_1400042c6:
    uVar6 = 1;
  }
  else {
    uVar9 = 0;
    uStackX_1c = (uint)((ulonglong)param_3 >> 0x20);
    uStackX_14 = (uint)((ulonglong)param_2 >> 0x20);
    if (DAT_14002a9d8 != 0) {
      do {
        if (DAT_14002a9d8 <= uVar9) {
          pcVar1 = (code *)swi(3);
          uVar6 = (*pcVar1)();
          return uVar6;
        }
        uVar6 = 0x200000002;
        iVar8 = *(int *)(DAT_14002a9d0 + 8 + uVar9 * 0xc);
        uVar7 = *(uint *)(DAT_14002a9d0 + uVar9 * 0xc);
        if (iVar8 == 0) {
          uVar6 = 0x100000001;
        }
        iVar5 = (int)((ulonglong)uVar6 >> 0x20);
        if ((((uVar7 <= (uint)param_2) &&
             (uVar10 = *(uint *)(DAT_14002a9d0 + 4 + uVar9 * 0xc), uVar10 <= uStackX_14)) &&
            (((uint)param_2 < uVar7 + (int)uVar6 && (uStackX_14 < iVar5 + uVar10)))) ||
           (((uVar7 <= (uint)param_3 &&
             (uVar10 = *(uint *)(DAT_14002a9d0 + 4 + uVar9 * 0xc), uVar10 <= uStackX_1c)) &&
            (((uint)param_3 < uVar7 + (int)uVar6 && (uStackX_1c < iVar5 + uVar10)))))) {
          uVar6 = 0x200000002;
          if (iVar8 == 0) {
            uVar6 = 0x100000001;
          }
          if (((((float)uVar7 - (0.180000007f) <= local_78) &&
               (local_78 <= (float)(uVar7 + (int)uVar6) + (0.180000007f))) &&
              ((float)uVar10 - (0.180000007f) <= fStack_74)) &&
             (fStack_74 <= (float)(uVar10 + (int)((ulonglong)uVar6 >> 0x20)) + (0.180000007f)))
          goto LAB_1400042c2;
        }
        uVar7 = (int)uVar9 + 1;
        uVar9 = (ulonglong)uVar7;
      } while (uVar7 < DAT_14002a9d8);
    }
    iVar8 = -1;
    auVar12._4_8_ = SUB128(ZEXT812(0),4);
    auVar12._0_4_ = local_78;
    auVar12._12_4_ = 0;
    auVar12 = vroundps_avx(auVar12,1);
    auVar13._4_8_ = SUB128(ZEXT812(0),4);
    auVar13._0_4_ = fStack_74;
    auVar13._12_4_ = 0;
    auVar13 = vroundps_avx(auVar13,1);
    fStack_74 = (float)(longlong)auVar13._0_4_;
    do {
      uVar7 = (int)fStack_74 + iVar8;
      iVar5 = (int)(longlong)auVar12._0_4_;
      uVar10 = iVar5 - 1;
      do {
        if ((((-1 < (int)uVar10) && (-1 < (int)uVar7)) &&
            (((int)uVar10 < (int)(uint)DAT_140029a88 && ((int)uVar7 < (int)DAT_140029a88._4_4_))))
           && ((((uint)DAT_140029a88 <= uVar10 || (DAT_140029a88._4_4_ <= uVar7)) ||
               ((param_2 != CONCAT44(uVar7,uVar10) &&
                ((param_3 != CONCAT44(uVar7,uVar10) &&
                 ((byte)(*(char *)((ulonglong)(uVar7 * (uint)DAT_140029a88 + uVar10) + DAT_140029a90
                                  ) - 7U) < 2)))))))) {
          auVar11._0_4_ = (float)(int)uVar10;
          auVar11._4_8_ = SUB128(ZEXT812(0),4);
          auVar11._12_4_ = 0;
          auVar13 = vmaxss_avx(auVar11,ZEXT416((uint)local_78));
          auVar13 = vminss_avx(ZEXT416((uint)(auVar11._0_4_ + (1f))),auVar13);
          fVar2 = local_78 - auVar13._0_4_;
          auVar14._0_4_ = (float)(int)uVar7;
          auVar14._4_8_ = SUB128(ZEXT812(0),4);
          auVar14._12_4_ = 0;
          auVar13 = vmaxss_avx(auVar14,ZEXT416((uint)fVar4));
          auVar13 = vminss_avx(ZEXT416((uint)(auVar14._0_4_ + (1f))),auVar13);
          fVar3 = fVar4 - auVar13._0_4_;
          if (fVar2 * fVar2 + fVar3 * fVar3 < (0.0324000008f)) goto LAB_1400042c6;
        }
        uVar10 = uVar10 + 1;
      } while ((int)(uVar10 - iVar5) < 2);
      iVar8 = iVar8 + 1;
    } while (iVar8 < 2);
LAB_1400042c2:
    uVar6 = 0;
  }
  return uVar6;
}


// ===== FUN_140004300 @ 140004300 size=165

ulonglong FUN_140004300(void)

{
  byte bVar1;
  code *pcVar2;
  uint uVar3;
  ulonglong uVar4;
  uint *puVar5;
  uint uVar6;
  
  FUN_14000c940();
  uVar4 = (ulonglong)DAT_1400294f0;
  if (DAT_1400294f0 == 0) {
    return 1;
  }
  uVar6 = 0xffffffff;
  if (DAT_1400294f0 != 0) {
    puVar5 = (uint *)((longlong)&DAT_1400294d0 + 4);
    do {
      uVar3 = uVar6;
      if (*puVar5 != 0) {
        bVar1 = (byte)puVar5[-1];
        uVar3 = 0;
        if (bVar1 < DAT_140029a30) {
          if ((ulonglong)DAT_140029a30 <= (ulonglong)bVar1) {
            pcVar2 = (code *)swi(3);
            uVar4 = (*pcVar2)();
            return uVar4;
          }
          uVar3 = *(uint *)(DAT_140029a28 + (ulonglong)bVar1 * 4);
        }
        uVar3 = uVar3 / *puVar5;
        if (uVar6 < uVar3) {
          uVar3 = uVar6;
        }
      }
      uVar6 = uVar3;
      puVar5 = puVar5 + 2;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  uVar4 = (ulonglong)uVar6;
  if (uVar6 == 0xffffffff) {
    uVar4 = 0;
  }
  return uVar4;
}


// ===== FUN_1400043b0 @ 1400043b0 size=87

undefined8 * FUN_1400043b0(undefined8 *param_1)

{
  uint uVar1;
  
  FUN_14000c940();
  uVar1 = DAT_1400294f0;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  *(undefined1 *)param_1 = 0xc;
  *(undefined1 *)(param_1 + 1) = 0xc;
  *(undefined1 *)(param_1 + 2) = 0xc;
  *(undefined1 *)(param_1 + 3) = 0xc;
  *(uint *)(param_1 + 4) = uVar1;
  if (uVar1 != 0) {
    FUN_1400200a0((undefined1 *)param_1,(undefined1 *)&DAT_1400294d0,(ulonglong)uVar1 << 3);
  }
  return param_1;
}


// ===== FUN_140004410 @ 140004410 size=311

void FUN_140004410(longlong *param_1,int param_2,int param_3,int param_4,int param_5)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  longlong lVar5;
  int iVar6;
  ulonglong uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  iVar10 = 0;
  if (0 < param_2) {
    iVar10 = param_2;
  }
  iVar8 = 0;
  if (0 < param_3) {
    iVar8 = param_3;
  }
  iVar12 = ((int)param_1[2] * param_5 + (int)param_1[1]) * param_4;
  if (param_2 < 0) {
    iVar12 = iVar12 - param_2;
  }
  iVar11 = param_4 * *(int *)((longlong)param_1 + 0xc);
  if (param_3 < 0) {
    iVar11 = iVar11 - param_3;
  }
  iVar9 = (int)param_1[2] * param_4 + param_2;
  iVar4 = param_4 * *(int *)((longlong)param_1 + 0x14) + param_3;
  iVar6 = DAT_1400296d4;
  if (iVar4 < DAT_1400296d4) {
    iVar6 = iVar4;
  }
  iVar4 = DAT_1400296d0;
  if (iVar9 < DAT_1400296d0) {
    iVar4 = iVar9;
  }
  if (0 < iVar6 - iVar8) {
    iVar11 = iVar11 - iVar8;
    uVar7 = (ulonglong)(uint)(iVar6 - iVar8);
    iVar6 = DAT_1400296d0;
    do {
      lVar3 = ((longlong *)*param_1)[1];
      lVar2 = *(longlong *)*param_1;
      lVar1 = DAT_1400296c8 + ((longlong)(iVar8 * iVar6) + (longlong)iVar10) * 4;
      lVar5 = 0;
      iVar9 = iVar12;
      if (0 < (longlong)(iVar4 - iVar10)) {
        do {
          *(undefined4 *)(lVar1 + lVar5 * 4) =
               *(undefined4 *)
                (lVar2 + (ulonglong)(uint)(((iVar11 + iVar8) / param_4) * (int)lVar3) * 4 +
                (longlong)(iVar9 / param_4) * 4);
          lVar5 = lVar5 + 1;
          iVar6 = DAT_1400296d0;
          iVar9 = iVar9 + 1;
        } while (lVar5 < iVar4 - iVar10);
      }
      iVar8 = iVar8 + 1;
      uVar7 = uVar7 - 1;
    } while (uVar7 != 0);
  }
  return;
}


// ===== FUN_140004550 @ 140004550 size=321

void FUN_140004550(longlong *param_1,int param_2,int param_3,int param_4,int param_5)

{
  longlong lVar1;
  undefined4 uVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  longlong lVar6;
  ulonglong uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  
  iVar11 = 0;
  if (0 < param_2) {
    iVar11 = param_2;
  }
  iVar8 = 0;
  if (0 < param_3) {
    iVar8 = param_3;
  }
  iVar13 = ((int)param_1[2] * param_5 + (int)param_1[1]) * param_4;
  if (param_2 < 0) {
    iVar13 = iVar13 - param_2;
  }
  iVar12 = param_4 * *(int *)((longlong)param_1 + 0xc);
  if (param_3 < 0) {
    iVar12 = iVar12 - param_3;
  }
  iVar9 = (int)param_1[2] * param_4 + param_2;
  iVar5 = param_4 * *(int *)((longlong)param_1 + 0x14) + param_3;
  iVar10 = DAT_1400296d4;
  if (iVar5 < DAT_1400296d4) {
    iVar10 = iVar5;
  }
  iVar5 = DAT_1400296d0;
  if (iVar9 < DAT_1400296d0) {
    iVar5 = iVar9;
  }
  if (0 < iVar10 - iVar8) {
    iVar12 = iVar12 - iVar8;
    uVar7 = (ulonglong)(uint)(iVar10 - iVar8);
    iVar10 = DAT_1400296d0;
    do {
      lVar4 = ((longlong *)*param_1)[1];
      lVar3 = *(longlong *)*param_1;
      lVar1 = DAT_1400296c8 + ((longlong)(iVar8 * iVar10) + (longlong)iVar11) * 4;
      lVar6 = 0;
      iVar9 = iVar13;
      if (0 < (longlong)(iVar5 - iVar11)) {
        do {
          uVar2 = *(undefined4 *)
                   (lVar3 + (ulonglong)(uint)(((iVar12 + iVar8) / param_4) * (int)lVar4) * 4 +
                   (longlong)(iVar9 / param_4) * 4);
          if ((char)((uint)uVar2 >> 0x18) != '\0') {
            *(undefined4 *)(lVar1 + lVar6 * 4) = uVar2;
          }
          lVar6 = lVar6 + 1;
          iVar10 = DAT_1400296d0;
          iVar9 = iVar9 + 1;
        } while (lVar6 < iVar5 - iVar11);
      }
      iVar8 = iVar8 + 1;
      uVar7 = uVar7 - 1;
    } while (uVar7 != 0);
  }
  return;
}


// ===== FUN_1400046a0 @ 1400046a0 size=332

void FUN_1400046a0(longlong *param_1,int param_2,int param_3,int param_4,int param_5)

{
  longlong lVar1;
  undefined4 uVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  longlong lVar6;
  int iVar7;
  ulonglong uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  
  iVar7 = 0;
  if (0 < param_2) {
    iVar7 = param_2;
  }
  iVar10 = 0;
  if (0 < param_3) {
    iVar10 = param_3;
  }
  iVar13 = ((int)param_1[2] * param_5 + (int)param_1[1]) * param_4;
  if (param_2 < 0) {
    iVar13 = iVar13 - param_2;
  }
  iVar12 = param_4 * *(int *)((longlong)param_1 + 0xc);
  if (param_3 < 0) {
    iVar12 = iVar12 - param_3;
  }
  iVar11 = (int)param_1[2] * param_4 + param_2;
  iVar5 = param_4 * *(int *)((longlong)param_1 + 0x14) + param_3;
  iVar9 = DAT_1400296d4;
  if (iVar5 < DAT_1400296d4) {
    iVar9 = iVar5;
  }
  iVar5 = DAT_1400296d0;
  if (iVar11 < DAT_1400296d0) {
    iVar5 = iVar11;
  }
  if (0 < iVar9 - iVar10) {
    iVar12 = iVar12 - iVar10;
    uVar8 = (ulonglong)(uint)(iVar9 - iVar10);
    iVar9 = DAT_1400296d0;
    do {
      lVar4 = ((longlong *)*param_1)[1];
      lVar3 = *(longlong *)*param_1;
      lVar1 = DAT_1400296c8 + ((longlong)(iVar10 * iVar9) + (longlong)iVar7) * 4;
      lVar6 = 0;
      iVar11 = iVar13;
      if (0 < (longlong)(iVar5 - iVar7)) {
        do {
          uVar2 = *(undefined4 *)
                   (lVar3 + (ulonglong)(uint)(((iVar12 + iVar10) / param_4) * (int)lVar4) * 4 +
                   (longlong)(iVar11 / param_4) * 4);
          param_5._3_1_ = (char)((uint)uVar2 >> 0x18);
          param_5._0_3_ = (uint3)(byte)uVar2;
          if (param_5._3_1_ != '\0') {
            *(int *)(lVar1 + lVar6 * 4) = param_5;
          }
          lVar6 = lVar6 + 1;
          iVar9 = DAT_1400296d0;
          iVar11 = iVar11 + 1;
        } while (lVar6 < iVar5 - iVar7);
      }
      iVar10 = iVar10 + 1;
      uVar8 = uVar8 - 1;
    } while (uVar8 != 0);
  }
  return;
}


// ===== FUN_1400047f0 @ 1400047f0 size=332

void FUN_1400047f0(longlong *param_1,int param_2,int param_3,int param_4,uint param_5)

{
  longlong lVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  longlong lVar6;
  int iVar7;
  ulonglong uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  bool bVar14;
  
  iVar7 = 0;
  if (0 < param_2) {
    iVar7 = param_2;
  }
  iVar10 = 0;
  if (0 < param_3) {
    iVar10 = param_3;
  }
  iVar13 = ((int)param_1[2] * param_5 + (int)param_1[1]) * param_4;
  if (param_2 < 0) {
    iVar13 = iVar13 - param_2;
  }
  iVar12 = param_4 * *(int *)((longlong)param_1 + 0xc);
  if (param_3 < 0) {
    iVar12 = iVar12 - param_3;
  }
  iVar11 = (int)param_1[2] * param_4 + param_2;
  iVar5 = param_4 * *(int *)((longlong)param_1 + 0x14) + param_3;
  iVar9 = DAT_1400296d4;
  if (iVar5 < DAT_1400296d4) {
    iVar9 = iVar5;
  }
  iVar5 = DAT_1400296d0;
  if (iVar11 < DAT_1400296d0) {
    iVar5 = iVar11;
  }
  if (0 < iVar9 - iVar10) {
    iVar12 = iVar12 - iVar10;
    uVar8 = (ulonglong)(uint)(iVar9 - iVar10);
    iVar9 = DAT_1400296d0;
    do {
      lVar4 = ((longlong *)*param_1)[1];
      lVar3 = *(longlong *)*param_1;
      lVar1 = DAT_1400296c8 + ((longlong)(iVar10 * iVar9) + (longlong)iVar7) * 4;
      lVar6 = 0;
      iVar11 = iVar13;
      if (0 < (longlong)(iVar5 - iVar7)) {
        do {
          uVar2 = *(uint *)(lVar3 + (ulonglong)(uint)(((iVar12 + iVar10) / param_4) * (int)lVar4) *
                                    4 + (longlong)(iVar11 / param_4) * 4);
          param_5._3_1_ = (char)(uVar2 >> 0x18);
          bVar14 = param_5._3_1_ != '\0';
          param_5 = uVar2 & 0xffff0000;
          if (bVar14) {
            *(uint *)(lVar1 + lVar6 * 4) = param_5;
          }
          lVar6 = lVar6 + 1;
          iVar9 = DAT_1400296d0;
          iVar11 = iVar11 + 1;
        } while (lVar6 < iVar5 - iVar7);
      }
      iVar10 = iVar10 + 1;
      uVar8 = uVar8 - 1;
    } while (uVar8 != 0);
  }
  return;
}


// ===== FUN_140004940 @ 140004940 size=629

void FUN_140004940(int param_1,int param_2,uint param_3,uint param_4,uint param_5,undefined4 param_6
                  )

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  longlong lVar6;
  longlong lVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  longlong lVar12;
  undefined4 *puVar13;
  uint uVar14;
  int iVar15;
  longlong lVar16;
  ulonglong uVar17;
  int iVar18;
  
  iVar4 = DAT_1400296d0;
  if (((((DAT_1400296c8 != 0) && (0 < (int)param_3)) && (0 < (int)param_4)) &&
      ((0 < (int)param_5 && (lVar12 = (longlong)DAT_1400296d0, 0 < DAT_1400296d0)))) &&
     (0 < DAT_1400296d4)) {
    iVar9 = param_2 + param_4;
    iVar11 = param_1 + param_3;
    if (((0 < iVar11) && (0 < iVar9)) && ((param_1 < DAT_1400296d0 && (param_2 < DAT_1400296d4)))) {
      if ((int)param_3 < (int)param_4) {
        param_4 = param_3;
      }
      uVar14 = param_4 >> 1;
      if ((int)param_5 < (int)(param_4 >> 1)) {
        uVar14 = param_5;
      }
      if (uVar14 != 0) {
        iVar8 = param_2 + uVar14;
        iVar1 = DAT_1400296d4;
        if (iVar8 < DAT_1400296d4) {
          iVar1 = iVar8;
        }
        iVar5 = iVar9 - uVar14;
        iVar2 = 0;
        if (0 < iVar5) {
          iVar2 = iVar5;
        }
        iVar3 = DAT_1400296d4;
        if (iVar9 < DAT_1400296d4) {
          iVar3 = iVar9;
        }
        iVar9 = 0;
        if (0 < param_1) {
          iVar9 = param_1;
        }
        iVar18 = DAT_1400296d0;
        if ((int)(param_1 + uVar14) < DAT_1400296d0) {
          iVar18 = param_1 + uVar14;
        }
        iVar10 = 0;
        if (0 < (int)(iVar11 - uVar14)) {
          iVar10 = iVar11 - uVar14;
        }
        iVar15 = DAT_1400296d0;
        if (iVar11 < DAT_1400296d0) {
          iVar15 = iVar11;
        }
        iVar11 = 0;
        if (0 < iVar8) {
          iVar11 = iVar8;
        }
        iVar8 = DAT_1400296d4;
        if (iVar5 < DAT_1400296d4) {
          iVar8 = iVar5;
        }
        iVar5 = 0;
        if (0 < param_2) {
          iVar5 = param_2;
        }
        if (iVar5 < iVar1) {
          lVar16 = (longlong)(iVar5 * DAT_1400296d0) << 2;
          uVar17 = (ulonglong)(uint)(iVar1 - iVar5);
          do {
            if (iVar9 < iVar15) {
              puVar13 = (undefined4 *)(DAT_1400296c8 + lVar16 + (longlong)iVar9 * 4);
              for (lVar6 = (longlong)(iVar15 - iVar9); lVar6 != 0; lVar6 = lVar6 + -1) {
                *puVar13 = param_6;
                puVar13 = puVar13 + 1;
              }
            }
            lVar16 = lVar16 + lVar12 * 4;
            uVar17 = uVar17 - 1;
          } while (uVar17 != 0);
        }
        if (iVar2 < iVar3) {
          lVar16 = (longlong)(iVar2 * iVar4) << 2;
          uVar17 = (ulonglong)(uint)(iVar3 - iVar2);
          do {
            if (iVar9 < iVar15) {
              puVar13 = (undefined4 *)(DAT_1400296c8 + lVar16 + (longlong)iVar9 * 4);
              for (lVar6 = (longlong)(iVar15 - iVar9); lVar6 != 0; lVar6 = lVar6 + -1) {
                *puVar13 = param_6;
                puVar13 = puVar13 + 1;
              }
            }
            lVar16 = lVar16 + lVar12 * 4;
            uVar17 = uVar17 - 1;
          } while (uVar17 != 0);
        }
        if (iVar11 < iVar8) {
          lVar16 = (longlong)(iVar11 * iVar4) << 2;
          uVar17 = (ulonglong)(uint)(iVar8 - iVar11);
          do {
            lVar6 = DAT_1400296c8 + lVar16;
            if (iVar9 < iVar18) {
              puVar13 = (undefined4 *)(lVar6 + (longlong)iVar9 * 4);
              for (lVar7 = (longlong)(iVar18 - iVar9); lVar7 != 0; lVar7 = lVar7 + -1) {
                *puVar13 = param_6;
                puVar13 = puVar13 + 1;
              }
            }
            if (iVar10 < iVar15) {
              puVar13 = (undefined4 *)(lVar6 + (longlong)iVar10 * 4);
              for (lVar7 = (longlong)(iVar15 - iVar10); lVar7 != 0; lVar7 = lVar7 + -1) {
                *puVar13 = param_6;
                puVar13 = puVar13 + 1;
              }
            }
            lVar16 = lVar16 + lVar12 * 4;
            uVar17 = uVar17 - 1;
          } while (uVar17 != 0);
        }
      }
    }
  }
  return;
}


// ===== FUN_140004bc0 @ 140004bc0 size=371

void FUN_140004bc0(int param_1,int param_2,uint param_3,uint param_4,uint param_5,undefined4 param_6
                  ,undefined4 param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  ulonglong uVar6;
  longlong lVar7;
  longlong lVar8;
  undefined4 *puVar9;
  longlong lVar10;
  ulonglong uVar11;
  int iVar12;
  
  iVar1 = DAT_1400296d4;
  iVar2 = DAT_1400296d0;
  if ((((DAT_1400296c8 != 0) && (0 < (int)param_3)) && (0 < (int)param_4)) &&
     ((lVar7 = (longlong)DAT_1400296d0, 0 < DAT_1400296d0 && (0 < DAT_1400296d4)))) {
    iVar5 = DAT_1400296d0;
    if ((int)(param_1 + param_3) < DAT_1400296d0) {
      iVar5 = param_1 + param_3;
    }
    iVar3 = 0;
    if (0 < param_1) {
      iVar3 = param_1;
    }
    if (iVar3 < iVar5) {
      iVar5 = DAT_1400296d4;
      if ((int)(param_2 + param_4) < DAT_1400296d4) {
        iVar5 = param_2 + param_4;
      }
      iVar3 = 0;
      if (0 < param_2) {
        iVar3 = param_2;
      }
      if (iVar3 < iVar5) {
        FUN_140004940(param_1,param_2,param_3,param_4,param_5,param_6);
        iVar5 = 0;
        if (0 < (int)(param_1 + param_5)) {
          iVar5 = param_1 + param_5;
        }
        iVar3 = 0;
        if (0 < (int)(param_2 + param_5)) {
          iVar3 = param_2 + param_5;
        }
        iVar12 = (param_1 - param_5) + param_3;
        iVar4 = iVar2;
        if (iVar12 < iVar2) {
          iVar4 = iVar12;
        }
        iVar12 = (param_2 - param_5) + param_4;
        if (iVar12 < iVar1) {
          iVar1 = iVar12;
        }
        if ((iVar5 < iVar4) && (iVar3 < iVar1)) {
          lVar10 = (longlong)(iVar3 * iVar2) << 2;
          uVar11 = (ulonglong)(uint)(iVar1 - iVar3);
          do {
            lVar8 = DAT_1400296c8 + lVar10;
            lVar10 = lVar10 + lVar7 * 4;
            puVar9 = (undefined4 *)(lVar8 + (longlong)iVar5 * 4);
            for (uVar6 = (longlong)(iVar4 - iVar5) & 0x3fffffffffffffff; uVar6 != 0;
                uVar6 = uVar6 - 1) {
              *puVar9 = param_7;
              puVar9 = puVar9 + 1;
            }
            uVar11 = uVar11 - 1;
          } while (uVar11 != 0);
        }
      }
    }
  }
  return;
}


// ===== FUN_140004d40 @ 140004d40 size=295

void FUN_140004d40(undefined2 *param_1,byte *param_2,uint param_3)

{
  byte bVar1;
  uint uVar2;
  ushort uVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined2 *puVar6;
  byte *pbVar7;
  uint local_58 [4];
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  
  puVar6 = param_1;
  for (lVar4 = 0x20; lVar4 != 0; lVar4 = lVar4 + -1) {
    *(undefined1 *)puVar6 = 0;
    puVar6 = (undefined2 *)((longlong)puVar6 + 1);
  }
  if (param_3 != 0) {
    uVar5 = (ulonglong)param_3;
    pbVar7 = param_2;
    do {
      bVar1 = *pbVar7;
      pbVar7 = pbVar7 + 1;
      param_1[bVar1] = param_1[bVar1] + 1;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  uVar3 = 0;
  *param_1 = 0;
  local_58[2] = (uint)(ushort)param_1[1];
  local_58[3] = (uint)(ushort)param_1[1] + (uint)(ushort)param_1[2];
  local_48 = local_58[3] + (ushort)param_1[3];
  local_44 = local_48 + (uint)(ushort)param_1[4];
  local_40 = local_44 + (uint)(ushort)param_1[5];
  local_3c = local_40 + (uint)(ushort)param_1[6];
  local_38 = local_3c + (uint)(ushort)param_1[7];
  local_34 = local_38 + (uint)(ushort)param_1[8];
  local_30 = local_34 + (uint)(ushort)param_1[9];
  local_2c = local_30 + (uint)(ushort)param_1[10];
  local_28 = local_2c + (uint)(ushort)param_1[0xb];
  local_24 = local_28 + (uint)(ushort)param_1[0xc];
  local_20 = local_24 + (uint)(ushort)param_1[0xd];
  local_1c = local_20 + (uint)(ushort)param_1[0xe];
  local_58[0] = 0;
  local_58[1] = 0;
  local_18 = (uint)(ushort)param_1[0xf] + local_1c;
  if (param_3 != 0) {
    do {
      bVar1 = param_2[uVar3];
      if (bVar1 != 0) {
        uVar2 = local_58[bVar1];
        param_1[(ulonglong)uVar2 + 0x10] = uVar3;
        local_58[bVar1] = uVar2 + 1;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < param_3);
  }
  return;
}


// ===== FUN_140004e70 @ 140004e70 size=274

ulonglong FUN_140004e70(char param_1)

{
  byte bVar1;
  code *pcVar2;
  uint uVar3;
  ulonglong uVar4;
  uint *puVar5;
  char *pcVar6;
  ulonglong uVar7;
  longlong lVar8;
  uint uVar9;
  
  FUN_14000c940();
  uVar7 = 0;
  pcVar6 = &DAT_140029290;
  uVar4 = uVar7;
  do {
    if (*pcVar6 == param_1) {
      lVar8 = uVar4 * 0x30;
      if (lVar8 == -0x140029290) {
        return 0;
      }
      uVar3 = *(uint *)(&DAT_1400292b4 + lVar8);
      uVar4 = (ulonglong)uVar3;
      if (uVar3 == 0) {
        uVar4 = 1;
      }
      else {
        uVar9 = 0xffffffff;
        if (uVar3 != 0) {
          puVar5 = (uint *)(&DAT_140029298 + lVar8);
          do {
            uVar3 = uVar9;
            if (*puVar5 != 0) {
              bVar1 = (byte)puVar5[-1];
              uVar3 = 0;
              if (bVar1 < DAT_140029a30) {
                if ((ulonglong)DAT_140029a30 <= (ulonglong)bVar1) {
                  pcVar2 = (code *)swi(3);
                  uVar4 = (*pcVar2)();
                  return uVar4;
                }
                uVar3 = *(uint *)(DAT_140029a28 + (ulonglong)bVar1 * 4);
              }
              uVar3 = uVar3 / *puVar5;
              if (uVar9 < uVar3) {
                uVar3 = uVar9;
              }
            }
            uVar9 = uVar3;
            puVar5 = puVar5 + 2;
            uVar4 = uVar4 - 1;
          } while (uVar4 != 0);
        }
        uVar4 = (ulonglong)uVar9;
        if (uVar9 == 0xffffffff) {
          uVar4 = uVar7;
        }
      }
      bVar1 = (&DAT_1400292b8)[lVar8];
      if ((bVar1 != 0xe) && (*(uint *)(&DAT_1400292bc + lVar8) != 0)) {
        if (bVar1 < DAT_140029a30) {
          if ((ulonglong)DAT_140029a30 <= (ulonglong)bVar1) {
            pcVar2 = (code *)swi(3);
            uVar4 = (*pcVar2)();
            return uVar4;
          }
          uVar7 = (ulonglong)*(uint *)(DAT_140029a28 + (ulonglong)bVar1 * 4);
        }
        uVar4 = (ulonglong)(uint)((int)(uVar7 / *(uint *)(&DAT_1400292bc + lVar8)) + (int)uVar4);
      }
      return uVar4;
    }
    uVar3 = (int)uVar4 + 1;
    uVar4 = (ulonglong)uVar3;
    pcVar6 = pcVar6 + 0x30;
  } while (uVar3 < 0xc);
  return 0;
}


// ===== FUN_140004f90 @ 140004f90 size=163

undefined8 * FUN_140004f90(undefined8 *param_1,char param_2)

{
  char *pcVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  uVar4 = 0;
  *(undefined1 *)param_1 = 0xc;
  *(undefined1 *)(param_1 + 1) = 0xc;
  *(undefined1 *)(param_1 + 2) = 0xc;
  *(undefined1 *)(param_1 + 3) = 0xc;
  *(undefined4 *)(param_1 + 4) = 0;
  FUN_14000c940();
  pcVar1 = &DAT_140029290;
  do {
    if (*pcVar1 == param_2) {
      lVar2 = uVar4 * 0x30;
      if (lVar2 != -0x140029290) {
        uVar3 = *(uint *)(&DAT_1400292b4 + lVar2);
        *(uint *)(param_1 + 4) = uVar3;
        if (uVar3 != 0) {
          FUN_1400200a0((undefined1 *)param_1,&DAT_140029294 + lVar2,(ulonglong)uVar3 << 3);
        }
      }
      return param_1;
    }
    uVar3 = (int)uVar4 + 1;
    uVar4 = (ulonglong)uVar3;
    pcVar1 = pcVar1 + 0x30;
  } while (uVar3 < 0xc);
  return param_1;
}


// ===== FUN_140005040 @ 140005040 size=425

undefined8 FUN_140005040(void)

{
  int *piVar1;
  byte bVar2;
  code *pcVar3;
  uint uVar4;
  undefined8 uVar5;
  byte *pbVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  uint uVar9;
  longlong lVar10;
  ulonglong uVar11;
  int local_28;
  undefined4 local_24;
  float local_20;
  float local_1c;
  undefined8 local_18;
  
  FUN_14000c940();
  uVar11 = (ulonglong)DAT_1400294f0;
  uVar7 = 0;
  if (DAT_1400294f0 != 0) {
    uVar8 = (ulonglong)DAT_140029a30;
    pbVar6 = (byte *)&DAT_1400294d0;
    do {
      uVar9 = *(uint *)((longlong)&DAT_1400294d0 + uVar7 * 8 + 4);
      if (uVar9 != 0) {
        bVar2 = *(byte *)(&DAT_1400294d0 + uVar7);
        if (bVar2 < DAT_140029a30) {
          if (uVar8 <= bVar2) {
            pcVar3 = (code *)swi(3);
            uVar5 = (*pcVar3)();
            return uVar5;
          }
          uVar4 = *(uint *)(DAT_140029a28 + (ulonglong)bVar2 * 4);
        }
        else {
          uVar4 = 0;
        }
        if (uVar4 < uVar9) {
          return 0;
        }
      }
      uVar9 = (int)uVar7 + 1;
      uVar7 = (ulonglong)uVar9;
      lVar10 = DAT_140029a28;
    } while (uVar9 < DAT_1400294f0);
    do {
      uVar9 = *(uint *)(pbVar6 + 4);
      if ((uVar9 != 0) && (uVar7 = (ulonglong)*pbVar6, (uint)*pbVar6 < (uint)uVar8)) {
        if (uVar8 <= uVar7) {
          pcVar3 = (code *)swi(3);
          uVar5 = (*pcVar3)();
          return uVar5;
        }
        if (uVar9 <= *(uint *)(lVar10 + uVar7 * 4)) {
          if (uVar8 <= uVar7) {
            pcVar3 = (code *)swi(3);
            uVar5 = (*pcVar3)();
            return uVar5;
          }
          piVar1 = (int *)(lVar10 + uVar7 * 4);
          *piVar1 = *piVar1 - uVar9;
          uVar8 = (ulonglong)DAT_140029a30;
          lVar10 = DAT_140029a28;
        }
      }
      pbVar6 = pbVar6 + 8;
      uVar11 = uVar11 - 1;
    } while (uVar11 != 0);
  }
  if ((DAT_14002a9d8 != 0) && (DAT_14002a9d0 != (undefined8 *)0x0)) {
    uVar5 = *DAT_14002a9d0;
    uVar11 = 0x200000002;
    if (*(int *)(DAT_14002a9d0 + 1) == 0) {
      uVar11 = 0x100000001;
    }
    local_20 = (float)(uVar11 & 0xffffffff) * (0.5f);
    local_1c = (float)(uVar11 >> 0x20) * (0.5f);
    if ((uVar11 & 1) == 0) {
      local_20 = local_20 + (-0.0500000007f);
    }
    if ((uVar11 >> 0x20 & 1) == 0) {
      local_1c = local_1c + (-0.0500000007f);
    }
    local_18._0_4_ = (int)uVar5;
    local_18._4_4_ = (undefined4)((ulonglong)uVar5 >> 0x20);
    local_28 = (int)local_18;
    local_24 = local_18._4_4_;
    local_18 = uVar5;
    FUN_140002060(0x1400291d0,&local_28);
    return 1;
  }
  FUN_1400021c0(0x1400291d0);
  return 1;
}


// ===== FUN_1400051f0 @ 1400051f0 size=168

undefined8 FUN_1400051f0(longlong param_1,longlong param_2,ulonglong param_3,int param_4)

{
  undefined8 uVar1;
  ulonglong uVar2;
  uint uVar3;
  
  if ((((((uint)param_3 < (uint)DAT_140029a88) &&
        (uVar3 = (uint)(param_3 >> 0x20), uVar3 < DAT_140029a88._4_4_)) &&
       (uVar2 = (ulonglong)(uVar3 * (uint)DAT_140029a88 + (uint)param_3),
       *(char *)(uVar2 + 4 + param_1) == '\0')) &&
      ((*(char *)(uVar2 + 0x10004 + param_1) == '\0' && (uVar3 < DAT_140029a88._4_4_)))) &&
     ((*(char *)(uVar2 + DAT_140029a90) == '\x01' &&
      (uVar1 = FUN_14001cba0(param_3,param_2), (int)uVar1 == 0)))) {
    if ((param_4 != 0) && (uVar1 = FUN_14001c960(param_3,param_2), (int)uVar1 != 0)) {
      return 0;
    }
    return 1;
  }
  return 0;
}


// ===== FUN_1400052a0 @ 1400052a0 size=385

undefined8 FUN_1400052a0(ulonglong param_1,undefined8 param_2)

{
  code *pcVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  char cVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  undefined8 local_res8;
  uint local_res18;
  
  uVar5 = DAT_14002a870;
  lVar4 = DAT_140029a98;
  uVar3 = (uint)DAT_140029a88;
  uVar2 = (uint)param_2;
  if (uVar2 + (int)param_1 <= (uint)DAT_140029a88) {
    uVar12 = (uint)(param_1 >> 0x20);
    uVar10 = (uint)((ulonglong)param_2 >> 0x20);
    if (uVar12 + uVar10 <= DAT_140029a88._4_4_) {
      local_res18 = 0;
      uVar6 = DAT_140029a88._4_4_;
      if (uVar10 != 0) {
        do {
          if (uVar2 != 0) {
            uVar7 = param_1 & 0xffffffff;
            do {
              uVar11 = (uint)uVar7;
              local_res8 = CONCAT44(uVar12,uVar11);
              if (uVar3 <= uVar11) {
                return 0;
              }
              if (uVar6 <= uVar12) {
                return 0;
              }
              if (DAT_1400299a8 == 0) {
                return 0;
              }
              if (((int)uVar11 < 0) || ((int)uVar12 < 0)) {
                cVar9 = '\0';
              }
              else {
                uVar7 = (ulonglong)(uVar12 * uVar3 + uVar11);
                cVar9 = *(char *)(uVar7 + DAT_140029a90);
                if (*(int *)(lVar4 + uVar7 * 4) != 0) {
                  return 0;
                }
              }
              if (cVar9 != '\x01') {
                if (cVar9 == '\x02') {
                  return 0;
                }
                if (cVar9 == '\x03') {
                  return 0;
                }
                if (cVar9 == '\x04') {
                  return 0;
                }
                if (cVar9 != '\x05') {
                  return 0;
                }
              }
              uVar6 = uVar12 * uVar3 + uVar11;
              if ((byte)(*(char *)((ulonglong)uVar6 + DAT_140029a90) - 7U) < 2) {
                return 0;
              }
              if ((((-1 < (int)uVar11) && (-1 < (int)uVar12)) &&
                  (uVar6 = *(uint *)(lVar4 + (ulonglong)uVar6 * 4), uVar6 != 0)) && (uVar6 < uVar5))
              {
                if (uVar5 <= uVar6) {
                  pcVar1 = (code *)swi(3);
                  uVar8 = (*pcVar1)();
                  return uVar8;
                }
                if (*(longlong *)(DAT_14002a868 + (ulonglong)uVar6 * 8) != 0) {
                  return 0;
                }
              }
              uVar8 = FUN_14000a5d0(local_res8);
              if ((int)uVar8 != 0) {
                return 0;
              }
              uVar7 = (ulonglong)(uVar11 + 1);
              uVar6 = DAT_140029a88._4_4_;
            } while ((uVar11 + 1) - (int)param_1 < uVar2);
          }
          local_res18 = local_res18 + 1;
          uVar12 = uVar12 + 1;
        } while (local_res18 < uVar10);
      }
      return 1;
    }
  }
  return 0;
}


// ===== FUN_140005430 @ 140005430 size=166

bool FUN_140005430(longlong param_1,ulonglong param_2)

{
  uint uVar1;
  undefined8 uVar2;
  uint uVar3;
  
  uVar3 = (uint)param_2;
  if ((uVar3 < (uint)DAT_140029a88) &&
     (uVar1 = (uint)(param_2 >> 0x20), uVar1 < DAT_140029a88._4_4_)) {
    uVar2 = FUN_14001cba0(param_2,param_1);
    if ((int)uVar2 == 0) {
      uVar2 = FUN_14001c960(param_2,param_1);
      if ((int)uVar2 == 0) {
        if ((uVar3 < (uint)DAT_140029a88) && (uVar1 < DAT_140029a88._4_4_)) {
          return *(char *)((ulonglong)(uVar1 * (uint)DAT_140029a88 + uVar3) + DAT_140029a90) ==
                 '\x01';
        }
        return false;
      }
    }
  }
  return false;
}


// ===== FUN_1400054e0 @ 1400054e0 size=409

undefined8 FUN_1400054e0(ulonglong param_1,uint param_2,uint param_3,undefined8 param_4,int param_5)

{
  char cVar1;
  uint uVar2;
  bool bVar3;
  uint uVar4;
  undefined7 extraout_var;
  uint uVar5;
  undefined8 uVar6;
  uint uVar7;
  uint uVar8;
  ulonglong uVar9;
  uint uVar10;
  longlong local_res8;
  
  switch(param_3) {
  default:
    uVar6 = 0x100000001;
    break;
  case 3:
    uVar6 = 0x200000002;
    break;
  case 4:
    uVar6 = 0x200000003;
  }
  uVar2 = (uint)uVar6;
  if (uVar2 + (int)param_1 <= (uint)DAT_140029a88) {
    uVar7 = (uint)(param_1 >> 0x20);
    uVar5 = (uint)((ulonglong)uVar6 >> 0x20);
    if (uVar5 + uVar7 <= DAT_140029a88._4_4_) {
      if (param_2 == 0) {
        if (param_3 != 8) {
LAB_1400055b5:
          uVar10 = 0;
          uVar4 = (uint)DAT_140029a88;
          if (uVar5 != 0) {
            do {
              if (uVar2 != 0) {
                local_res8 = (ulonglong)uVar7 << 0x20;
                uVar9 = param_1 & 0xffffffff;
                do {
                  uVar8 = (uint)uVar9;
                  local_res8 = CONCAT44(local_res8._4_4_,uVar8);
                  if ((uVar8 < uVar4) && (uVar7 < DAT_140029a88._4_4_)) {
                    cVar1 = *(char *)((ulonglong)(uVar7 * uVar4 + uVar8) + DAT_140029a90);
                    if (cVar1 == '\a') {
                      return 0;
                    }
                    if (cVar1 == '\b') {
                      return 0;
                    }
                  }
                  bVar3 = FUN_14001c590(local_res8,param_2);
                  if ((int)CONCAT71(extraout_var,bVar3) == 0) {
                    return 0;
                  }
                  if (((param_2 == 0) && (param_5 != 0)) &&
                     (uVar6 = FUN_14000a5d0(CONCAT44(uVar7,uVar8)), (int)uVar6 != 0)) {
                    return 0;
                  }
                  uVar9 = (ulonglong)(uVar8 + 1);
                  uVar4 = (uint)DAT_140029a88;
                } while ((uVar8 + 1) - (int)param_1 < uVar2);
              }
              uVar10 = uVar10 + 1;
              uVar7 = uVar7 + 1;
            } while (uVar10 < uVar5);
          }
          return 1;
        }
      }
      else if ((param_3 < 10) && ((0x322U >> (param_3 & 0x1f) & 1) != 0)) goto LAB_1400055b5;
    }
  }
  return 0;
}


// ===== FUN_1400056b0 @ 1400056b0 size=246

void FUN_1400056b0(ulonglong param_1)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  
  auVar3 = ZEXT416((-250f));
  auVar1 = vmaxss_avx(ZEXT416((uint)((float)((int)DAT_140029a88 * DAT_140029020 * 0x10 -
                                            DAT_1400296d0) + (250f))),auVar3);
  auVar2 = vmaxss_avx(auVar3,ZEXT416((uint)((float)(DAT_140029020 << 4) *
                                            ((float)(param_1 & 0xffffffff) + (0.5f)) -
                                           (float)DAT_1400296d0 * (0.5f))));
  auVar1 = vminss_avx(auVar1,auVar2);
  DAT_140029630 = auVar1._0_4_;
  auVar1 = vmaxss_avx(auVar3,ZEXT416((uint)((float)(DAT_140029020 << 4) *
                                            ((float)(param_1 >> 0x20) + (0.5f)) -
                                           (float)DAT_1400296d4 * (0.5f))));
  auVar2 = vmaxss_avx(ZEXT416((uint)((float)(DAT_140029a88._4_4_ * DAT_140029020 * 0x10 -
                                            DAT_1400296d4) + (250f))),auVar3);
  auVar1 = vminss_avx(auVar2,auVar1);
  DAT_140029634 = auVar1._0_4_;
  return;
}


// ===== FUN_1400057b0 @ 1400057b0 size=129

void FUN_1400057b0(void)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  
  auVar3 = ZEXT416((-250f));
  auVar1 = vmaxss_avx(auVar3,ZEXT416(DAT_140029630));
  auVar2 = vmaxss_avx(ZEXT416((uint)((float)(DAT_140029020 * (int)DAT_140029a88 * 0x10 -
                                            DAT_1400296d0) + (250f))),auVar3);
  auVar1 = vminss_avx(auVar2,auVar1);
  DAT_140029630 = auVar1._0_4_;
  auVar1 = vmaxss_avx(auVar3,ZEXT416(DAT_140029634));
  auVar2 = vmaxss_avx(ZEXT416((uint)((float)(DAT_140029020 * DAT_140029a88._4_4_ * 0x10 -
                                            DAT_1400296d4) + (250f))),auVar3);
  auVar1 = vminss_avx(auVar2,auVar1);
  DAT_140029634 = auVar1._0_4_;
  return;
}


// ===== FUN_140005840 @ 140005840 size=915

void FUN_140005840(void)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  byte bVar3;
  int *piVar4;
  code *pcVar5;
  undefined8 uVar6;
  longlong lVar7;
  uint uVar8;
  ulonglong uVar9;
  uint *puVar10;
  longlong lVar11;
  uint uVar12;
  uint uVar14;
  uint uVar15;
  ulonglong uVar17;
  int iStackX_c;
  ulonglong uVar13;
  ulonglong uVar16;
  
  uVar13 = (ulonglong)DAT_1400eaa18;
  if (DAT_1400eaa18 != 0) {
    uVar17 = (ulonglong)DAT_1400eaa18;
    lVar11 = uVar13 * 0x18;
    uVar16 = uVar13;
    uVar15 = DAT_140029200;
    do {
      uVar12 = (int)uVar13 - 1;
      uVar13 = (ulonglong)uVar12;
      uVar17 = uVar17 - 1;
      lVar11 = lVar11 + -0x18;
      if (uVar16 <= uVar17) {
        pcVar5 = (code *)swi(3);
        (*pcVar5)();
        return;
      }
      puVar10 = (uint *)(DAT_1400eaa10 + lVar11);
      if (-1 < (int)puVar10[4]) goto LAB_140005bb1;
      uVar14 = *puVar10;
      uVar8 = puVar10[1];
      if ((((uVar14 < (uint)DAT_140029a88) && (uVar8 < DAT_140029a88._4_4_)) && (DAT_1400299a8 != 0)
          ) && ((-1 < (int)uVar14 && (-1 < (int)uVar8)))) {
        uVar14 = *(uint *)(DAT_140029a98 + (ulonglong)(uVar8 * (uint)DAT_140029a88 + uVar14) * 4);
        if ((uVar14 == 0) || (DAT_14002a870 <= uVar14)) goto LAB_140005aaf;
        if ((ulonglong)DAT_14002a870 <= (ulonglong)uVar14) {
          pcVar5 = (code *)swi(3);
          (*pcVar5)();
          return;
        }
        piVar4 = *(int **)(DAT_14002a868 + (ulonglong)uVar14 * 8);
        if (((piVar4 == (int *)0x0) || (*(longlong *)(piVar4 + 2) == 0)) || (*piVar4 != 1))
        goto LAB_140005aaf;
        if ((char)puVar10[5] == '\x01') {
          lVar7 = *(longlong *)puVar10;
          uVar14 = (uint)lVar7;
          if (((uVar14 < (uint)DAT_140029a88) &&
              (uVar8 = (uint)((ulonglong)lVar7 >> 0x20), uVar8 < DAT_140029a88._4_4_)) &&
             ((DAT_1400299a8 != 0 && ((-1 < (int)uVar14 && (-1 < lVar7)))))) {
            uVar14 = *(uint *)(DAT_140029a98 + (ulonglong)(uVar8 * (uint)DAT_140029a88 + uVar14) * 4
                              );
            if ((uVar14 != 0) && (uVar14 < DAT_14002a870)) {
              if ((ulonglong)DAT_14002a870 <= (ulonglong)uVar14) {
                pcVar5 = (code *)swi(3);
                (*pcVar5)();
                return;
              }
              piVar4 = *(int **)(DAT_14002a868 + (ulonglong)uVar14 * 8);
              if (((piVar4 != (int *)0x0) && (*(longlong *)(piVar4 + 2) != 0)) && (*piVar4 == 1)) {
                lVar7 = 0x58;
                if (piVar4[0x16] == 0) {
                  lVar7 = 0x40;
                }
                if (*(int *)(lVar7 + (longlong)piVar4) != 0) goto LAB_140005bb1;
              }
            }
          }
          uVar9 = 0;
          if (uVar15 != 0) {
            iStackX_c = (int)((ulonglong)*(undefined8 *)puVar10 >> 0x20);
            if (uVar15 == 0) {
              pcVar5 = (code *)swi(3);
              (*pcVar5)();
              return;
            }
            do {
              uVar14 = (uint)uVar9;
              if (((*(int *)(DAT_1400291f8 + 0x24 + uVar9 * 0x28) != 0) &&
                  (*(int *)(DAT_1400291f8 + 1 + uVar9 * 0x28) == (int)*(undefined8 *)puVar10)) &&
                 (*(int *)(DAT_1400291f8 + 5 + uVar9 * 0x28) == iStackX_c)) {
                if (-1 < (int)uVar14) {
                  FUN_14001dd40(0x1400291d0,uVar14);
                  uVar16 = (ulonglong)DAT_1400eaa18;
                  uVar15 = DAT_140029200;
                }
                break;
              }
              uVar9 = (ulonglong)(uVar14 + 1);
            } while (uVar14 + 1 < uVar15);
          }
          if ((uint)uVar16 <= uVar12) goto LAB_140005bb1;
          DAT_1400eaa18 = (uint)uVar16 - 1;
          uVar16 = (ulonglong)DAT_1400eaa18;
          uVar14 = uVar12;
          if (DAT_1400eaa18 <= uVar12) goto LAB_140005bb1;
          do {
            lVar7 = DAT_1400eaa10;
            uVar15 = uVar14 + 1;
            puVar1 = (undefined8 *)(DAT_1400eaa10 + (ulonglong)uVar15 * 0x18);
            uVar6 = puVar1[1];
            puVar2 = (undefined8 *)(DAT_1400eaa10 + (ulonglong)uVar14 * 0x18);
            *puVar2 = *puVar1;
            puVar2[1] = uVar6;
            *(undefined8 *)(lVar7 + 0x10 + (ulonglong)uVar14 * 0x18) =
                 *(undefined8 *)(lVar7 + 0x10 + (ulonglong)uVar15 * 0x18);
            uVar14 = uVar15;
          } while (uVar15 < DAT_1400eaa18);
          goto LAB_140005baa;
        }
      }
      else {
LAB_140005aaf:
        if ((char)puVar10[5] == '\0') {
          bVar3 = (byte)puVar10[2];
          if ((bVar3 < DAT_140029a30) && (puVar10[3] != 0)) {
            if ((ulonglong)DAT_140029a30 <= (ulonglong)bVar3) {
              pcVar5 = (code *)swi(3);
              (*pcVar5)();
              return;
            }
            piVar4 = (int *)(DAT_140029a28 + (ulonglong)bVar3 * 4);
            *piVar4 = *piVar4 + puVar10[3];
            uVar16 = (ulonglong)DAT_1400eaa18;
            uVar15 = DAT_140029200;
          }
        }
        uVar9 = 0;
        if (uVar15 != 0) {
          iStackX_c = (int)((ulonglong)*(undefined8 *)puVar10 >> 0x20);
          if (uVar15 == 0) {
            pcVar5 = (code *)swi(3);
            (*pcVar5)();
            return;
          }
          do {
            uVar14 = (uint)uVar9;
            if (((*(int *)(DAT_1400291f8 + 0x24 + uVar9 * 0x28) != 0) &&
                (*(int *)(DAT_1400291f8 + 1 + uVar9 * 0x28) == (int)*(undefined8 *)puVar10)) &&
               (*(int *)(DAT_1400291f8 + 5 + uVar9 * 0x28) == iStackX_c)) {
              if (-1 < (int)uVar14) {
                FUN_14001dd40(0x1400291d0,uVar14);
                uVar16 = (ulonglong)DAT_1400eaa18;
                uVar15 = DAT_140029200;
              }
              break;
            }
            uVar9 = (ulonglong)(uVar14 + 1);
          } while (uVar14 + 1 < uVar15);
        }
        if (uVar12 < (uint)uVar16) {
          DAT_1400eaa18 = (uint)uVar16 - 1;
          uVar16 = (ulonglong)DAT_1400eaa18;
          uVar9 = uVar13;
          if (uVar12 < DAT_1400eaa18) {
            do {
              lVar7 = DAT_1400eaa10;
              uVar15 = (int)uVar9 + 1;
              uVar16 = (ulonglong)uVar15;
              puVar1 = (undefined8 *)(DAT_1400eaa10 + uVar16 * 0x18);
              uVar6 = puVar1[1];
              puVar2 = (undefined8 *)(DAT_1400eaa10 + uVar9 * 0x18);
              *puVar2 = *puVar1;
              puVar2[1] = uVar6;
              *(undefined8 *)(lVar7 + 0x10 + uVar9 * 0x18) =
                   *(undefined8 *)(lVar7 + 0x10 + uVar16 * 0x18);
              uVar9 = uVar16;
            } while (uVar15 < DAT_1400eaa18);
LAB_140005baa:
            uVar16 = (ulonglong)DAT_1400eaa18;
            uVar15 = DAT_140029200;
          }
        }
      }
LAB_140005bb1:
    } while (uVar12 != 0);
  }
  return;
}


// ===== FUN_140005be0 @ 140005be0 size=403

void FUN_140005be0(undefined8 param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  code *pcVar2;
  longlong lVar3;
  uint uVar4;
  ulonglong uVar5;
  uint uVar6;
  ulonglong uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar11;
  int iStackX_c;
  undefined8 local_res10;
  ulonglong uVar10;
  
  uVar11 = 0;
  uVar4 = (uint)((ulonglong)param_2 >> 0x20);
  if (uVar4 != 0) {
    iStackX_c = (int)((ulonglong)param_1 >> 0x20);
    do {
      uVar6 = 0;
      if ((uint)param_2 != 0) {
        do {
          local_res10 = CONCAT44(iStackX_c + uVar11,(int)param_1 + uVar6);
          uVar5 = FUN_1400086a0(local_res10);
          uVar8 = (uint)uVar5;
          uVar7 = uVar5 & 0xffffffff;
          if (-1 < (int)uVar8) {
            if (uVar8 < DAT_1400eaa00) {
              if (DAT_1400eaa00 <= uVar7) {
                pcVar2 = (code *)swi(3);
                (*pcVar2)();
                return;
              }
              if (*(int *)(DAT_1400ea9f8 + uVar7 * 4) != 0) {
                if (DAT_14002a9d8 <= uVar7) {
                  pcVar2 = (code *)swi(3);
                  (*pcVar2)();
                  return;
                }
                FUN_1400148e0((*(int *)(DAT_14002a9d0 + 8 + uVar7 * 0xc) != 0) + '\x14');
              }
            }
            uVar5 = uVar5 & 0xffffffff;
            DAT_14002a9d8 = DAT_14002a9d8 - 1;
            if (uVar8 < DAT_14002a9d8) {
              do {
                lVar3 = DAT_14002a9d0;
                uVar9 = (int)uVar5 + 1;
                uVar10 = (ulonglong)uVar9;
                puVar1 = (undefined8 *)(DAT_14002a9d0 + uVar5 * 0xc);
                *puVar1 = *(undefined8 *)(DAT_14002a9d0 + uVar10 * 0xc);
                *(undefined4 *)(puVar1 + 1) = *(undefined4 *)(lVar3 + 8 + uVar10 * 0xc);
                uVar5 = uVar10;
              } while (uVar9 < DAT_14002a9d8);
            }
            if ((uVar8 < DAT_1400eaa00) &&
               (DAT_1400eaa00 = DAT_1400eaa00 - 1, uVar8 < DAT_1400eaa00)) {
              do {
                uVar8 = (int)uVar7 + 1;
                *(undefined4 *)(DAT_1400ea9f8 + uVar7 * 4) =
                     *(undefined4 *)(DAT_1400ea9f8 + (ulonglong)uVar8 * 4);
                uVar7 = (ulonglong)uVar8;
              } while (uVar8 < DAT_1400eaa00);
            }
          }
          uVar6 = uVar6 + 1;
        } while (uVar6 < (uint)param_2);
      }
      uVar11 = uVar11 + 1;
    } while (uVar11 < uVar4);
  }
  return;
}


// ===== FUN_140005d80 @ 140005d80 size=336

void FUN_140005d80(undefined8 param_1,uint param_2,undefined8 param_3)

{
  uint uVar1;
  undefined8 *puVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  int iStackX_c;
  
  uVar5 = 0;
  uVar1 = (uint)((ulonglong)param_3 >> 0x20);
  if (uVar1 != 0) {
    iStackX_c = (int)((ulonglong)param_1 >> 0x20);
    do {
      uVar4 = 0;
      if ((uint)param_3 != 0) {
        do {
          puVar2 = (undefined8 *)
                   FUN_140009990(CONCAT44(uVar5 + iStackX_c,(int)param_1 + uVar4),param_2);
          if (puVar2 != (undefined8 *)0x0) {
            if (((puVar2[1] != 0) && (*(uint *)((longlong)puVar2 + 0x34) < 0x10000)) &&
               (*(int *)(&DAT_1400aa9f0 + (ulonglong)*(uint *)((longlong)puVar2 + 0x34) * 4) != 0))
            {
              switch(*(undefined4 *)puVar2) {
              case 1:
                cVar3 = '\n';
                break;
              case 2:
                cVar3 = '\v';
                break;
              case 3:
                cVar3 = '\f';
                break;
              case 4:
                cVar3 = '\r';
                break;
              case 5:
                cVar3 = '\x0e';
                break;
              case 6:
                cVar3 = '\x0f';
                break;
              case 7:
                cVar3 = '\x10';
                break;
              case 8:
                cVar3 = '\x11';
                break;
              case 9:
                cVar3 = '\x12';
                break;
              case 10:
                cVar3 = '\x13';
                break;
              default:
                cVar3 = '\0';
              }
              FUN_1400148e0(cVar3);
            }
            if ((puVar2[1] != 0) && (*(uint *)((longlong)puVar2 + 0x34) < 0x10000)) {
              *(undefined4 *)(&DAT_1400aa9f0 + (ulonglong)*(uint *)((longlong)puVar2 + 0x34) * 4) =
                   0;
            }
            FUN_140014b90(puVar2);
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < (uint)param_3);
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar1);
  }
  return;
}


// ===== FUN_140005f00 @ 140005f00 size=221

void FUN_140005f00(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  uint uVar5;
  uint uVar6;
  longlong lVar7;
  uint uVar8;
  int iStackX_c;
  
  uVar8 = 0;
  uVar2 = (uint)((ulonglong)param_2 >> 0x20);
  if (uVar2 != 0) {
    iStackX_c = (int)((ulonglong)param_1 >> 0x20);
    lVar7 = DAT_1400291f8;
    uVar6 = DAT_140029200;
    do {
      uVar5 = 0;
      if ((uint)param_2 != 0) {
        do {
          uVar4 = 0;
          if (uVar6 != 0) {
            if (uVar6 == 0) {
              pcVar1 = (code *)swi(3);
              (*pcVar1)();
              return;
            }
            do {
              uVar3 = (uint)uVar4;
              if (((*(int *)(lVar7 + 0x24 + uVar4 * 0x28) != 0) &&
                  (*(int *)(lVar7 + 1 + uVar4 * 0x28) == (int)param_1 + uVar5)) &&
                 (*(int *)(lVar7 + 5 + uVar4 * 0x28) == iStackX_c + uVar8)) {
                if (-1 < (int)uVar3) {
                  FUN_14001dd40(0x1400291d0,uVar3);
                  lVar7 = DAT_1400291f8;
                  uVar6 = DAT_140029200;
                }
                break;
              }
              uVar4 = (ulonglong)(uVar3 + 1);
            } while (uVar3 + 1 < uVar6);
          }
          uVar5 = uVar5 + 1;
        } while (uVar5 < (uint)param_2);
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < uVar2);
  }
  return;
}


// ===== FUN_140005fe0 @ 140005fe0 size=389

undefined8 FUN_140005fe0(undefined8 param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  ulonglong uVar6;
  int iVar7;
  float local_res10;
  float fStackX_14;
  
  local_res10 = (float)param_1;
  iVar4 = (int)local_res10;
  fStackX_14 = (float)((ulonglong)param_1 >> 0x20);
  iVar7 = (int)fStackX_14;
  if (((DAT_140029078 <= iVar4) && (iVar4 < DAT_140029074 + 0x52 + DAT_140029078)) &&
     (DAT_14002907c <= iVar7)) {
    uVar6 = 0;
    iVar3 = 0;
    if (0 < (int)(DAT_140029a30 - 1)) {
      iVar3 = DAT_140029a30 - 1;
    }
    if (iVar7 < (int)(iVar3 * 4 + 0x16 + (DAT_140029074 + 8) * DAT_140029a30 + DAT_14002907c)) {
      if (((((iVar4 < DAT_140029078) || (iVar7 < DAT_14002907c)) ||
           ((iVar7 = (iVar7 - DAT_14002907c) + -0xb, (iVar4 - DAT_140029078) + -3 < 0 ||
            ((iVar7 < 0 || (iVar4 = DAT_140029074 + 0xc, iVar4 < 1)))))) ||
          (DAT_140029074 + 8 <= iVar7 - (int)((longlong)iVar7 / (longlong)iVar4) * iVar4)) ||
         (DAT_140029a30 == 0)) {
        return 1;
      }
      do {
        uVar5 = (uint)uVar6;
        if (DAT_140029a30 <= uVar6) {
          pcVar1 = (code *)swi(3);
          uVar2 = (*pcVar1)();
          return uVar2;
        }
        if (*(int *)(DAT_140029a28 + uVar6 * 4) != 0) {
          if (DAT_140029568 <= uVar6) {
            pcVar1 = (code *)swi(3);
            uVar2 = (*pcVar1)();
            return uVar2;
          }
          if (*(char *)(DAT_140029560 + uVar6) == (char)((longlong)iVar7 / (longlong)iVar4)) {
            if ((int)uVar5 < 0) {
              return 1;
            }
            if (DAT_140029a30 <= uVar5) {
              return 1;
            }
            if (DAT_140029a30 <= (uVar5 & 0xff)) {
              return 1;
            }
            if ((uVar6 & 0xff) < (ulonglong)DAT_140029a30) {
              if (*(int *)(DAT_140029a28 + (uVar6 & 0xff) * 4) == 0) {
                return 1;
              }
              if (DAT_140029024 != (char)uVar6) {
                DAT_140029024 = (char)uVar6;
                return 1;
              }
              DAT_140029024 = 0xe;
              return 1;
            }
            pcVar1 = (code *)swi(3);
            uVar2 = (*pcVar1)();
            return uVar2;
          }
        }
        uVar6 = (ulonglong)(uVar5 + 1);
        if (DAT_140029a30 <= uVar5 + 1) {
          return 1;
        }
      } while( true );
    }
  }
  return 0;
}


// ===== FUN_140006170 @ 140006170 size=523

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_140006170(undefined8 param_1)

{
  ulonglong uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  ulonglong uVar11;
  int iVar12;
  bool bVar13;
  float local_28;
  float fStack_24;
  
  if (DAT_140029af0 != 0) {
    iVar9 = 1;
    if (1 < DAT_140029124 * DAT_140029120) {
      iVar9 = DAT_140029124 * DAT_140029120;
    }
    if (DAT_140029af4 == 0) {
      uVar2 = (DAT_1400296d0 + (DAT_14002912c + DAT_140029130) * -2) / iVar9;
      uVar7 = 1;
      if (1 < (int)uVar2) {
        uVar7 = uVar2;
      }
    }
    else {
      uVar7 = DAT_140029ae0;
      if ((int)DAT_140029ae0 < 1) {
        uVar7 = 1;
      }
      if (4 < (int)uVar7) {
        uVar7 = 4;
      }
    }
    if (DAT_140029af4 == 0) {
      uVar11 = 1;
      uVar1 = (longlong)(DAT_1400296d0 + (DAT_14002912c + DAT_140029130) * -2) / (longlong)iVar9;
      if (1 < (int)uVar1) {
        uVar11 = uVar1 & 0xffffffff;
      }
    }
    else {
      uVar2 = DAT_140029ae0;
      if ((int)DAT_140029ae0 < 1) {
        uVar2 = 1;
      }
      if (4 < (int)uVar2) {
        uVar2 = 4;
      }
      uVar11 = (ulonglong)uVar2;
    }
    iVar4 = 0;
    iVar5 = (uint)((int)((ulonglong)DAT_140029ae0 % uVar11) != 0) + (int)(DAT_140029ae0 / uVar11);
    iVar8 = 1;
    if (1 < iVar5) {
      iVar8 = iVar5;
    }
    iVar10 = iVar9 * uVar7 + DAT_140029130 * 2;
    iVar6 = DAT_140029130 * 2 + iVar8 * iVar9;
    iVar5 = DAT_14002912c;
    iVar3 = DAT_14002912c;
    if (DAT_140029af4 != 0) {
      iVar12 = DAT_1400296d0 - iVar10;
      iVar5 = DAT_140029af8 - iVar10 / 2;
      iVar3 = iVar4;
      if (0 < iVar12) {
        iVar3 = iVar12;
      }
      if (iVar5 < 0) {
        iVar5 = iVar4;
      }
      if (iVar3 < iVar5) {
        iVar5 = iVar3;
      }
      iVar3 = DAT_1400296d4 - iVar6;
      iVar10 = 0;
      if (0 < iVar3) {
        iVar10 = iVar3;
      }
      iVar3 = (DAT_140029afc - iVar6) - _DAT_140029138;
      if (iVar3 < 0) {
        iVar3 = iVar4;
      }
      if (iVar10 < iVar3) {
        iVar3 = iVar10;
      }
    }
    local_28 = (float)param_1;
    fStack_24 = (float)((ulonglong)param_1 >> 0x20);
    iVar5 = ((int)local_28 - DAT_140029130) - iVar5;
    iVar4 = ((int)fStack_24 - iVar3) - DAT_140029130;
    if ((((-1 < iVar5) && (iVar5 < (int)(iVar9 * uVar7))) && (-1 < iVar4)) &&
       (iVar4 < iVar8 * iVar9)) {
      uVar7 = (iVar4 / iVar9) * uVar7 + iVar5 / iVar9;
      if ((-1 < (int)uVar7) && (uVar7 < DAT_140029ae0)) {
        bVar13 = uVar7 == DAT_140029128;
        DAT_140029128 = uVar7;
        if (bVar13) {
          DAT_140029128 = 0xffffffff;
        }
        if (DAT_140029ae8 != (code *)0x0) {
          (*DAT_140029ae8)();
        }
        DAT_140029af0 = 0;
        DAT_140029af4 = 0;
      }
      return 1;
    }
  }
  return 0;
}


// ===== FUN_140006380 @ 140006380 size=542

undefined4 FUN_140006380(undefined8 param_1,undefined1 *param_2)

{
  uint uVar1;
  longlong lVar2;
  char cVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  ulonglong uVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  
  lVar2 = DAT_140029a90;
  uVar8 = DAT_140029a88._4_4_;
  uVar4 = (uint)DAT_140029a88;
  uVar1 = (uint)param_1;
  if ((uVar1 < (uint)DAT_140029a88) &&
     (uVar9 = (uint)((ulonglong)param_1 >> 0x20), uVar9 < DAT_140029a88._4_4_)) {
    uVar7 = (ulonglong)(uVar9 * (uint)DAT_140029a88 + uVar1);
    if (uVar9 < DAT_140029a88._4_4_) {
      cVar3 = *(char *)(uVar7 + DAT_140029a90);
    }
    else {
      cVar3 = '\0';
    }
    if (cVar3 == '\x02') {
      if (*(short *)(&DAT_14004a9f0 + uVar7 * 2) != 0) {
        *(short *)(&DAT_14004a9f0 + uVar7 * 2) = *(short *)(&DAT_14004a9f0 + uVar7 * 2) + -1;
        if (param_2 != (undefined1 *)0x0) {
          *param_2 = 0;
          lVar2 = DAT_140029a90;
          uVar8 = DAT_140029a88._4_4_;
          uVar4 = (uint)DAT_140029a88;
        }
        bVar10 = *(short *)(&DAT_14004a9f0 + uVar7 * 2) == 0;
LAB_140006568:
        if (((bVar10) && (uVar1 < uVar4)) && (uVar9 < uVar8)) {
          *(undefined1 *)((ulonglong)(uVar9 * uVar4 + uVar1) + lVar2) = 1;
        }
        return 1;
      }
    }
    else if (cVar3 == '\x03') {
      if (*(short *)(&DAT_14006a9f0 + uVar7 * 2) != 0) {
        *(short *)(&DAT_14006a9f0 + uVar7 * 2) = *(short *)(&DAT_14006a9f0 + uVar7 * 2) + -1;
        if (param_2 != (undefined1 *)0x0) {
          *param_2 = 1;
          lVar2 = DAT_140029a90;
          uVar8 = DAT_140029a88._4_4_;
          uVar4 = (uint)DAT_140029a88;
        }
        bVar10 = *(short *)(&DAT_14006a9f0 + uVar7 * 2) == 0;
        goto LAB_140006568;
      }
    }
    else if (cVar3 == '\x04') {
      if (*(short *)(&DAT_14008a9f0 + uVar7 * 2) != 0) {
        *(short *)(&DAT_14008a9f0 + uVar7 * 2) = *(short *)(&DAT_14008a9f0 + uVar7 * 2) + -1;
        if (param_2 != (undefined1 *)0x0) {
          *param_2 = 0xb;
          lVar2 = DAT_140029a90;
          uVar8 = DAT_140029a88._4_4_;
          uVar4 = (uint)DAT_140029a88;
        }
        bVar10 = *(short *)(&DAT_14008a9f0 + uVar7 * 2) == 0;
        goto LAB_140006568;
      }
    }
    else if (cVar3 == '\x06') {
      uVar5 = 0;
      uVar4 = 0;
      uVar6 = 0;
      if (DAT_1400299ac != 0) {
        while ((*(uint *)((ulonglong)uVar4 * 0x40 + DAT_140029ac8) != uVar1 ||
               (*(uint *)((ulonglong)uVar4 * 0x40 + 4 + DAT_140029ac8) != uVar9))) {
          uVar4 = uVar4 + 1;
          if (DAT_1400299ac <= uVar4) {
            return 0;
          }
        }
        uVar6 = uVar5;
        if (((-1 < (int)uVar4) && (lVar2 = (ulonglong)uVar4 * 0x40 + DAT_140029ac8, lVar2 != 0)) &&
           (*(int *)(lVar2 + 0xc) != 0)) {
          uVar4 = *(int *)(lVar2 + 0xc) - 1;
          uVar6 = 1;
          *(uint *)(lVar2 + 0xc) = uVar4;
          *param_2 = *(undefined1 *)(lVar2 + 0x18 + (ulonglong)uVar4 * 0x10);
        }
      }
      return uVar6;
    }
  }
  return 0;
}


// ===== FUN_1400065a0 @ 1400065a0 size=202

undefined * FUN_1400065a0(undefined1 param_1)

{
  switch(param_1) {
  case 0:
    return &DAT_1400eb3c0;
  default:
    return (undefined *)0x0;
  case 2:
    return &DAT_1400eaa40;
  case 3:
    return &DAT_1400eaa60;
  case 4:
    return &DAT_1400eaa80;
  case 5:
    return &DAT_1400eaaa0;
  case 6:
    return &DAT_1400eaac0;
  case 7:
    return &DAT_1400eaae0;
  case 8:
    return &DAT_1400eab00;
  case 9:
    return &DAT_1400eab20;
  case 10:
    return &DAT_1400eb320;
  case 0xb:
    return &DAT_1400eb380;
  case 0xc:
    return &DAT_1400eb340;
  case 0xd:
    return &DAT_1400eb3a0;
  case 0xe:
    return &DAT_1400eb400;
  case 0xf:
    return &DAT_1400eb420;
  case 0x10:
    return &DAT_1400eb460;
  case 0x11:
    return &DAT_1400eb440;
  case 0x12:
    return &DAT_1400eb480;
  case 0x13:
    return &DAT_1400eb4a0;
  case 0x14:
    return &DAT_1400eb360;
  case 0x15:
    return &DAT_1400eb3e0;
  }
}


// ===== FUN_1400066d0 @ 1400066d0 size=103

double FUN_1400066d0(void)

{
  code *pcVar1;
  BOOL BVar2;
  double dVar3;
  LARGE_INTEGER local_res8 [4];
  
  BVar2 = QueryPerformanceCounter(local_res8);
  if (BVar2 == 0) {
    FUN_140002010("Could not get performanceCounter");
    pcVar1 = (code *)swi(3);
    dVar3 = (double)(*pcVar1)();
    return dVar3;
  }
  if (-1 < (longlong)DAT_140029670) {
    return (double)local_res8[0].QuadPart / (double)(longlong)DAT_140029670;
  }
  return (double)local_res8[0].QuadPart / (double)DAT_140029670;
}


// ===== FUN_140006740 @ 140006740 size=1089

void FUN_140006740(ulonglong *param_1,undefined2 *param_2,undefined2 *param_3)

{
  uint uVar1;
  byte bVar2;
  code *pcVar3;
  longlong lVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  byte *pbVar8;
  uint uVar9;
  int iVar10;
  short *psVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  ushort uVar16;
  uint *puVar17;
  undefined1 local_658 [16];
  undefined2 local_648;
  byte local_646;
  uint local_638 [20];
  short local_5e8 [4];
  ushort local_5e0;
  ushort local_5de;
  ushort local_5dc;
  ushort local_5da;
  ushort local_5d8;
  ushort local_5d6;
  ushort local_5d4;
  ushort local_5d2;
  ushort local_5d0;
  ushort local_5ce;
  ushort local_5cc;
  ushort local_5ca;
  ushort auStack_5c8 [576];
  byte local_148 [288];
  ulonglong uVar11;
  
  uVar15 = param_1[2];
  uVar14 = *param_1;
  uVar9 = (int)uVar15 - 5;
  uVar11 = (ulonglong)uVar9;
  uVar13 = *param_1 >> 5;
  *(uint *)(param_1 + 2) = uVar9;
  *param_1 = uVar13;
  if (uVar9 < 0x21) {
    uVar9 = (int)uVar15 + 0x1b;
    uVar13 = uVar13 | (ulonglong)*(uint *)param_1[1] << (uVar11 & 0x3f);
    param_1[1] = (ulonglong)((uint *)param_1[1] + 1);
  }
  uVar5 = uVar9 - 5;
  uVar15 = (ulonglong)uVar5;
  uVar1 = ((uint)uVar14 & 0x1f) + 0x101;
  *(uint *)(param_1 + 2) = uVar5;
  uVar14 = uVar13 >> 5;
  *param_1 = uVar14;
  if (uVar5 < 0x21) {
    uVar5 = uVar9 + 0x1b;
    uVar14 = uVar14 | (ulonglong)*(uint *)param_1[1] << (uVar15 & 0x3f);
    param_1[1] = (ulonglong)((uint *)param_1[1] + 1);
  }
  uVar9 = ((uint)uVar13 & 0x1f) + 1;
  uVar6 = uVar5 - 4;
  uVar11 = (ulonglong)uVar6;
  uVar15 = uVar14 >> 4;
  *(uint *)(param_1 + 2) = uVar6;
  *param_1 = uVar15;
  if (uVar6 < 0x21) {
    uVar15 = (ulonglong)*(uint *)param_1[1] << (uVar11 & 0x3f) | uVar15;
    param_1[1] = (ulonglong)((uint *)param_1[1] + 1);
    uVar11 = (ulonglong)(uVar5 + 0x1c);
    *param_1 = uVar15;
    *(uint *)(param_1 + 2) = uVar5 + 0x1c;
  }
  uVar5 = ((uint)uVar14 & 0xf) + 4;
  if (0x11e < uVar1) {
    FUN_140002010("HLIT out of range!");
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  if (0x20 < uVar9) {
    FUN_140002010("HDIST out of range!");
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  if (uVar5 < 0x14) {
    uVar6 = 0;
    uVar16 = 0;
    local_638[0] = 0x10;
    local_638[1] = 0x11;
    local_638[2] = 0x12;
    local_638[3] = 0;
    local_638[4] = 8;
    local_638[5] = 7;
    local_638[6] = 9;
    local_638[7] = 6;
    local_638[8] = 10;
    local_638[9] = 5;
    local_638[10] = 0xb;
    local_638[0xb] = 4;
    local_638[0xc] = 0xc;
    local_638[0xd] = 3;
    local_638[0xe] = 0xd;
    local_638[0xf] = 2;
    local_638[0x10] = 0xe;
    local_638[0x11] = 1;
    local_638[0x12] = 0xf;
    local_648 = 0;
    local_646 = 0;
    local_658 = (undefined1  [16])0x0;
    if (uVar5 != 0) {
      puVar17 = local_638;
      uVar13 = (ulonglong)uVar5;
      uVar14 = uVar15;
      do {
        uVar15 = uVar15 >> 3;
        iVar10 = (int)uVar11;
        uVar5 = iVar10 - 3;
        uVar11 = (ulonglong)uVar5;
        *(uint *)(param_1 + 2) = uVar5;
        *param_1 = uVar15;
        uVar7 = uVar15 & 0xffffffff;
        if (uVar5 < 0x21) {
          uVar15 = (ulonglong)*(uint *)param_1[1] << (uVar11 & 0x3f) | uVar15;
          param_1[1] = (ulonglong)((uint *)param_1[1] + 1);
          uVar5 = iVar10 + 0x1d;
          uVar11 = (ulonglong)uVar5;
          *param_1 = uVar15;
          *(uint *)(param_1 + 2) = uVar5;
          uVar7 = uVar15;
        }
        uVar5 = *puVar17;
        puVar17 = puVar17 + 1;
        local_658[uVar5] = (byte)uVar14 & 7;
        uVar14 = uVar7 & 0xffffffff;
        uVar13 = uVar13 - 1;
      } while (uVar13 != 0);
      uVar6 = (uint)local_646;
    }
    local_638[0] = 0;
    local_638[1] = 0;
    psVar12 = local_5e8;
    for (lVar4 = 0x20; lVar4 != 0; lVar4 = lVar4 + -1) {
      *(undefined1 *)psVar12 = 0;
      psVar12 = (short *)((longlong)psVar12 + 1);
    }
    local_5e8[local_658[0]] = local_5e8[local_658[0]] + 1;
    local_5e8[local_658[1]] = local_5e8[local_658[1]] + 1;
    local_5e8[local_658[2]] = local_5e8[local_658[2]] + 1;
    local_5e8[local_658[3]] = local_5e8[local_658[3]] + 1;
    local_5e8[local_658[4]] = local_5e8[local_658[4]] + 1;
    local_5e8[local_658[5]] = local_5e8[local_658[5]] + 1;
    local_5e8[local_658[6]] = local_5e8[local_658[6]] + 1;
    local_5e8[local_658[7]] = local_5e8[local_658[7]] + 1;
    local_5e8[local_658[8]] = local_5e8[local_658[8]] + 1;
    local_5e8[local_658[9]] = local_5e8[local_658[9]] + 1;
    local_5e8[local_658[10]] = local_5e8[local_658[10]] + 1;
    local_5e8[local_658[0xb]] = local_5e8[local_658[0xb]] + 1;
    local_5e8[local_658[0xc]] = local_5e8[local_658[0xc]] + 1;
    local_5e8[local_658[0xd]] = local_5e8[local_658[0xd]] + 1;
    local_5e8[local_658[0xe]] = local_5e8[local_658[0xe]] + 1;
    local_5e8[local_658[0xf]] = local_5e8[local_658[0xf]] + 1;
    local_5e8[(byte)local_648] = local_5e8[(byte)local_648] + 1;
    local_5e8[local_648._1_1_] = local_5e8[local_648._1_1_] + 1;
    local_5e8[uVar6] = local_5e8[uVar6] + 1;
    local_638[3] = (uint)(ushort)local_5e8[2] + (uint)(ushort)local_5e8[1];
    local_638[4] = (ushort)local_5e8[3] + local_638[3];
    local_638[2] = (uint)(ushort)local_5e8[1];
    local_638[5] = local_5e0 + local_638[4];
    local_638[6] = local_5de + local_638[5];
    local_638[7] = local_5dc + local_638[6];
    local_638[8] = local_5da + local_638[7];
    local_638[9] = local_5d8 + local_638[8];
    local_638[10] = local_5d6 + local_638[9];
    local_638[0xb] = local_5d4 + local_638[10];
    local_638[0xc] = local_5d2 + local_638[0xb];
    local_638[0xd] = local_5d0 + local_638[0xc];
    local_638[0xe] = local_5ce + local_638[0xd];
    local_5e8[0] = 0;
    local_638[0xf] = local_5cc + local_638[0xe];
    local_638[0x10] = local_5ca + local_638[0xf];
    pbVar8 = local_658;
    do {
      bVar2 = *pbVar8;
      if (bVar2 != 0) {
        uVar5 = local_638[bVar2];
        auStack_5c8[uVar5] = uVar16;
        local_638[bVar2] = uVar5 + 1;
      }
      uVar16 = uVar16 + 1;
      pbVar8 = pbVar8 + 1;
    } while (uVar16 < 0x13);
    FUN_1400144d0(param_1,(longlong)local_5e8,uVar1,(longlong)local_148);
    FUN_1400144d0(param_1,(longlong)local_5e8,uVar9,(longlong)local_658);
    FUN_140004d40(param_2,local_148,uVar1);
    FUN_140004d40(param_3,local_658,uVar9);
    return;
  }
  FUN_140002010("HCLEN out of range!");
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}


// ===== FUN_140006b90 @ 140006b90 size=361

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_140006b90(undefined4 param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  undefined1 auVar6 [32];
  undefined1 auVar7 [16];
  undefined1 auVar9 [16];
  float fVar8;
  undefined1 auVar10 [32];
  undefined1 auVar11 [32];
  undefined1 auVar12 [32];
  float fVar13;
  undefined1 in_ZMM5 [64];
  undefined1 auVar14 [64];
  undefined1 auVar15 [32];
  
  auVar10._4_4_ = param_1;
  auVar10._0_4_ = param_1;
  auVar10._8_4_ = param_1;
  auVar10._12_4_ = param_1;
  auVar10._16_4_ = param_1;
  auVar10._20_4_ = param_1;
  auVar10._24_4_ = param_1;
  auVar10._28_4_ = param_1;
  auVar6 = vroundps_avx(auVar10,9);
  auVar10 = vsubps_avx(auVar10,auVar6);
  auVar15._4_4_ = auVar10._4_4_ * _UNK_140025244;
  auVar15._0_4_ = auVar10._0_4_ * _DAT_140025240;
  auVar15._8_4_ = auVar10._8_4_ * _UNK_140025248;
  auVar15._12_4_ = auVar10._12_4_ * _UNK_14002524c;
  auVar15._16_4_ = auVar10._16_4_ * _UNK_140025250;
  auVar15._20_4_ = auVar10._20_4_ * _UNK_140025254;
  auVar15._24_4_ = auVar10._24_4_ * _UNK_140025258;
  auVar15._28_4_ = auVar6._28_4_;
  auVar15 = vcvtps2dq_avx(auVar15);
  auVar6 = vpsubd_avx2(auVar15,_DAT_1400250e0);
  auVar11 = vpcmpeqd_avx2(auVar15,SUB6432(ZEXT1664((undefined1  [16])0x0),0));
  auVar6 = vpermilps_avx(_DAT_1400251e0,auVar6);
  auVar6 = vandnps_avx(auVar11,auVar6);
  auVar6 = vsubps_avx(auVar10,auVar6);
  fVar8 = auVar6._0_4_;
  auVar14._0_4_ = fVar8 * fVar8;
  fVar1 = auVar6._4_4_;
  auVar14._4_4_ = fVar1 * fVar1;
  fVar13 = auVar6._8_4_;
  auVar14._8_4_ = fVar13 * fVar13;
  fVar2 = auVar6._12_4_;
  auVar14._12_4_ = fVar2 * fVar2;
  fVar3 = auVar6._16_4_;
  auVar14._16_4_ = fVar3 * fVar3;
  fVar4 = auVar6._20_4_;
  auVar14._20_4_ = fVar4 * fVar4;
  fVar5 = auVar6._24_4_;
  auVar14._28_36_ = in_ZMM5._28_36_;
  auVar14._24_4_ = fVar5 * fVar5;
  auVar10 = auVar14._0_32_;
  auVar7 = vfmadd231ps_fma(_DAT_1400252c0,auVar10,_DAT_1400253e0);
  auVar7 = vfmadd231ps_fma(_DAT_1400253c0,auVar10,ZEXT1632(auVar7));
  auVar7 = vfmadd231ps_fma(_DAT_140025260,auVar10,ZEXT1632(auVar7));
  auVar6 = vpermilps_avx(_DAT_1400250c0,auVar15);
  auVar12._0_4_ = (uint)(auVar7._0_4_ * fVar8) ^ auVar6._0_4_;
  auVar12._4_4_ = (uint)(auVar7._4_4_ * fVar1) ^ auVar6._4_4_;
  auVar12._8_4_ = (uint)(auVar7._8_4_ * fVar13) ^ auVar6._8_4_;
  auVar12._12_4_ = (uint)(auVar7._12_4_ * fVar2) ^ auVar6._12_4_;
  auVar12._16_4_ = (uint)(fVar3 * 0.0) ^ auVar6._16_4_;
  auVar12._20_4_ = (uint)(fVar4 * 0.0) ^ auVar6._20_4_;
  auVar12._24_4_ = (uint)(fVar5 * 0.0) ^ auVar6._24_4_;
  auVar12._28_4_ = auVar6._28_4_;
  auVar7 = vfmadd231ps_fma(_DAT_140025400,auVar10,_DAT_140025280);
  auVar7 = vfmadd231ps_fma(_DAT_1400252a0,auVar10,ZEXT1632(auVar7));
  auVar7 = vfmadd231ps_fma(_DAT_1400253a0,auVar10,ZEXT1632(auVar7));
  auVar7 = vfmadd231ps_fma(_DAT_140025200,auVar10,ZEXT1632(auVar7));
  auVar6 = vpermilps_avx(_DAT_140025300,auVar15);
  auVar11._0_4_ = auVar7._0_4_ ^ auVar6._0_4_;
  auVar11._4_4_ = auVar7._4_4_ ^ auVar6._4_4_;
  auVar11._8_4_ = auVar7._8_4_ ^ auVar6._8_4_;
  auVar11._12_4_ = auVar7._12_4_ ^ auVar6._12_4_;
  auVar11._16_4_ = auVar6._16_4_;
  auVar11._20_4_ = auVar6._20_4_;
  auVar11._24_4_ = auVar6._24_4_;
  auVar11._28_4_ = auVar6._28_4_;
  auVar15 = vpslld_avx2(auVar15,0x1f);
  auVar6 = vblendvps_avx(auVar11,auVar12,auVar15);
  fVar1 = auVar6._0_4_ * (0.75f);
  auVar6 = vblendvps_avx(auVar12,auVar11,auVar15);
  fVar13 = auVar6._0_4_;
  fVar8 = fVar1 * fVar1 + fVar13 * fVar13;
  if (fVar8 <= (9.99999905e-09f)) {
    return 0;
  }
  auVar7._8_8_ = 0;
  auVar7._0_8_ = SUB648(ZEXT6064((undefined1  [60])0x0),4);
  auVar9._4_12_ = SUB1612(auVar7 << 0x40,4);
  auVar9._0_4_ = fVar8;
  auVar7 = vsqrtps_avx(auVar9);
  fVar8 = (1f) / auVar7._0_4_;
  auVar7 = vunpcklps_avx(ZEXT416((uint)(fVar1 * fVar8)),ZEXT416((uint)(fVar8 * fVar13)));
  return auVar7._0_8_;
}


// ===== FUN_140006d00 @ 140006d00 size=195

void FUN_140006d00(uint param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  ulonglong uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = (int)((param_4 >> 0x1f & 0xfU) + param_4) >> 4;
  if (param_1 == 0) {
    FUN_140004550((longlong *)&DAT_1400eaee0,param_2,param_3,iVar4,0);
  }
  else {
    uVar2 = FUN_140012110(param_1);
    iVar3 = (int)uVar2 * param_4 + param_2;
    do {
      FUN_140004550((longlong *)(&DAT_1400eaee0 + (ulonglong)(param_1 % 10) * 0x20),iVar3,param_3,
                    iVar4,0);
      iVar3 = iVar3 - param_4;
      uVar1 = param_1 / 10;
      param_1 = param_1 / 10;
    } while (uVar1 != 0);
  }
  return;
}


// ===== FUN_140006dd0 @ 140006dd0 size=882

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140006dd0(void)

{
  int iVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined1 auVar4 [16];
  int iVar5;
  int iVar6;
  int iVar7;
  ulonglong uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  ulonglong uVar13;
  undefined8 uVar14;
  int iVar15;
  uint uVar16;
  
  if (DAT_140029af0 != 0) {
    uVar16 = 1;
    if (1 < DAT_140029124 * DAT_140029120) {
      uVar16 = DAT_140029124 * DAT_140029120;
    }
    if (DAT_140029af4 == 0) {
      uVar10 = (int)(DAT_1400296d0 + (DAT_14002912c + DAT_140029130) * -2) / (int)uVar16;
      uVar9 = 1;
      if (1 < (int)uVar10) {
        uVar9 = uVar10;
      }
    }
    else {
      uVar9 = DAT_140029ae0;
      if ((int)DAT_140029ae0 < 1) {
        uVar9 = 1;
      }
      if (4 < (int)uVar9) {
        uVar9 = 4;
      }
    }
    if (DAT_140029af4 == 0) {
      uVar13 = 1;
      uVar8 = (longlong)(int)(DAT_1400296d0 + (DAT_14002912c + DAT_140029130) * -2) /
              (longlong)(int)uVar16;
      if (1 < (int)uVar8) {
        uVar13 = uVar8 & 0xffffffff;
      }
    }
    else {
      uVar10 = DAT_140029ae0;
      if ((int)DAT_140029ae0 < 1) {
        uVar10 = 1;
      }
      uVar13 = (ulonglong)uVar10;
      if (4 < (int)uVar10) {
        uVar13 = 4;
      }
    }
    iVar5 = (uint)((int)((ulonglong)DAT_140029ae0 % uVar13) != 0) + (int)(DAT_140029ae0 / uVar13);
    iVar15 = 1;
    if (1 < iVar5) {
      iVar15 = iVar5;
    }
    uVar10 = uVar9 * uVar16 + DAT_140029130 * 2;
    iVar12 = iVar15 * uVar16 + DAT_140029130 * 2;
    iVar15 = DAT_14002912c;
    iVar5 = DAT_14002912c;
    if (DAT_140029af4 != 0) {
      iVar15 = DAT_140029af8 - (int)uVar10 / 2;
      iVar5 = 0;
      if (0 < (int)(DAT_1400296d0 - uVar10)) {
        iVar5 = DAT_1400296d0 - uVar10;
      }
      if (iVar15 < 0) {
        iVar15 = 0;
      }
      if (iVar5 < iVar15) {
        iVar15 = iVar5;
      }
      iVar6 = 0;
      if (0 < DAT_1400296d4 - iVar12) {
        iVar6 = DAT_1400296d4 - iVar12;
      }
      iVar5 = (DAT_140029afc - iVar12) - _DAT_140029138;
      if (iVar5 < 0) {
        iVar5 = 0;
      }
      if (iVar6 < iVar5) {
        iVar5 = iVar6;
      }
    }
    iVar6 = iVar15 + DAT_140029130;
    iVar1 = iVar5 + DAT_140029130;
    auVar4._4_4_ = iVar5;
    auVar4._0_4_ = iVar15;
    auVar4._8_4_ = uVar10;
    auVar4._12_4_ = iVar12;
    uVar14 = vpextrq_avx(auVar4,1);
    FUN_140004bc0(iVar15,iVar5,uVar10,(uint)((ulonglong)uVar14 >> 0x20),DAT_140029130,DAT_140029570,
                  DAT_140029574);
    uVar8 = (ulonglong)DAT_140029ae0;
    uVar10 = 0;
    if (DAT_140029ae0 != 0) {
      do {
        if (uVar8 <= uVar10) {
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        plVar2 = *(longlong **)(DAT_140029ad8 + (ulonglong)uVar10 * 8);
        if (plVar2 != (longlong *)0x0) {
          iVar15 = (int)plVar2[2];
          iVar5 = *(int *)((longlong)plVar2 + 0x14);
          iVar12 = 1;
          if (1 < iVar15) {
            iVar12 = iVar15;
          }
          iVar11 = 1;
          if (1 < (int)uVar16 / iVar12) {
            iVar11 = (int)uVar16 / iVar12;
          }
          iVar12 = 1;
          if (1 < iVar5) {
            iVar12 = iVar5;
          }
          iVar7 = 1;
          if (1 < (int)uVar16 / iVar12) {
            iVar7 = (int)uVar16 / iVar12;
          }
          if (iVar11 < iVar7) {
            iVar7 = iVar11;
          }
          iVar12 = 1;
          if (1 < iVar7) {
            iVar12 = iVar7;
          }
          iVar5 = uVar16 - iVar5 * iVar12;
          if (iVar5 < 0) {
            iVar5 = iVar5 + 1;
          }
          iVar15 = uVar16 - iVar15 * iVar12;
          if (iVar15 < 0) {
            iVar15 = iVar15 + 1;
          }
          FUN_140004550(plVar2,(uVar10 % uVar9) * uVar16 + iVar6 + (iVar15 >> 1),
                        (uVar10 / uVar9) * uVar16 + iVar1 + (iVar5 >> 1),iVar12,0);
          uVar8 = (ulonglong)DAT_140029ae0;
        }
        uVar10 = uVar10 + 1;
      } while (uVar10 < (uint)uVar8);
    }
    if (DAT_140029128 != -1) {
      FUN_140004940((DAT_140029128 % (int)uVar9) * uVar16 + iVar6,
                    (DAT_140029128 / (int)uVar9) * uVar16 + iVar1,uVar16,uVar16,DAT_140029134,
                    DAT_1400294f4);
    }
  }
  return;
}


// ===== FUN_140007150 @ 140007150 size=1102

void FUN_140007150(void)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  uint uVar4;
  int iVar5;
  LONG LVar6;
  undefined4 uVar7;
  ulonglong uVar8;
  uint uVar9;
  ulonglong uVar10;
  int iVar11;
  ulonglong uVar12;
  int iVar13;
  longlong lVar14;
  longlong lVar15;
  int iVar16;
  int iVar17;
  float fVar18;
  float fVar19;
  tagPOINT local_res8;
  undefined4 local_res10;
  undefined4 local_res18;
  undefined4 local_res20;
  
  iVar5 = DAT_140029078;
  uVar4 = DAT_140029074;
  local_res8.x = 0;
  local_res8.y = 0;
  GetCursorPos(&local_res8);
  ScreenToClient(DAT_140029680,&local_res8);
  uVar8 = (ulonglong)DAT_140029a30;
  uVar10 = 0;
  fVar19 = (float)local_res8.x;
  fVar18 = (float)local_res8.y;
  if (DAT_140029a30 != 0) {
    uVar12 = (ulonglong)DAT_140029568;
    lVar14 = DAT_140029560;
    lVar15 = DAT_140029a28;
    do {
      if (uVar12 <= uVar10) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      if (*(char *)(lVar14 + uVar10) == -1) {
        if (uVar8 <= uVar10) {
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        if (*(int *)(lVar15 + uVar10 * 4) != 0) {
          DAT_140029025 = DAT_140029025 + '\x01';
          if (uVar12 <= uVar10) {
            pcVar3 = (code *)swi(3);
            (*pcVar3)();
            return;
          }
          *(char *)(lVar14 + uVar10) = DAT_140029025;
          uVar8 = (ulonglong)DAT_140029a30;
          uVar12 = (ulonglong)DAT_140029568;
          lVar14 = DAT_140029560;
          lVar15 = DAT_140029a28;
          goto LAB_14000726e;
        }
      }
      else {
LAB_14000726e:
        uVar9 = DAT_140029074;
        if (uVar12 <= uVar10) {
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        uVar1 = DAT_140029074 + 8;
        iVar17 = (uint)*(byte *)(lVar14 + uVar10) * (DAT_140029074 + 0xc) + DAT_14002907c;
        if (uVar8 <= uVar10) {
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        local_res8.x = -0x6d8d6a;
        if (*(int *)(lVar15 + uVar10 * 4) == 0) {
          local_res8.x = -0xb1b99c;
        }
        if (uVar8 <= uVar10) {
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        local_res10 = 0xff1c1c1c;
        if (*(int *)(lVar15 + uVar10 * 4) == 0) {
          local_res10 = 0xff2c2c2c;
        }
        if (DAT_140029024 == (char)uVar10) {
          local_res18 = 0xff52a896;
          local_res20 = 0xff60ebeb;
          local_res8.x = -0xad576a;
          local_res10 = 0xff60ebeb;
        }
        uVar7 = local_res10;
        LVar6 = local_res8.x;
        if (uVar8 <= uVar10) {
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        uVar8 = FUN_140012110(*(uint *)(lVar15 + uVar10 * 4));
        iVar16 = iVar5 + 2;
        iVar2 = iVar17 + 6;
        iVar11 = uVar4 + 0x4e + (int)uVar8 * uVar9 + iVar16;
        iVar13 = uVar9 + 0x12 + iVar2;
        if ((((iVar16 <= (int)fVar19) && ((int)fVar19 <= iVar11)) && (iVar2 <= (int)fVar18)) &&
           ((int)fVar18 <= iVar13)) {
          switch(uVar10 & 0xff) {
          case 0:
            DAT_140029990 = &DAT_1400eb840;
            break;
          case 1:
            DAT_140029990 = &DAT_1400eb7a0;
            break;
          case 2:
            DAT_140029990 = &DAT_1400eb890;
            break;
          case 3:
            DAT_140029990 = &DAT_1400eb7b0;
            break;
          case 4:
            DAT_140029990 = &DAT_1400eb850;
            break;
          case 5:
            DAT_140029990 = &DAT_1400eb780;
            break;
          case 6:
            DAT_140029990 = &DAT_1400eb750;
            break;
          case 7:
            DAT_140029990 = &DAT_1400eb7e0;
            break;
          case 8:
            DAT_140029990 = &DAT_1400eb800;
            break;
          case 9:
            DAT_140029990 = &DAT_1400eb880;
            break;
          case 10:
            DAT_140029990 = &DAT_1400eb8b0;
            break;
          case 0xb:
            DAT_140029990 = &DAT_1400eb870;
            break;
          case 0xc:
            DAT_140029990 = &DAT_1400eb830;
            break;
          case 0xd:
            DAT_140029990 = &DAT_1400eb7c0;
            break;
          default:
            DAT_140029990 = (undefined *)0x0;
            goto LAB_140007478;
          }
          DAT_140029998 = iVar11 + 4;
          DAT_14002999c = (int)(fVar18 - (float)(*(uint *)(DAT_140029990 + 0xc) & 0x7fffffff));
        }
LAB_140007478:
        FUN_140004bc0(iVar16,iVar2,iVar11 - iVar16,iVar13 - iVar2,3,0xff181818,0xff624e46);
        FUN_140004bc0(iVar5 + 7,iVar17 + 0xb,uVar4 + 0x44 + (int)uVar8 * DAT_140029074,uVar1,2,uVar7
                      ,LVar6);
        FUN_140004550((longlong *)(&DAT_1400299b0)[uVar10],iVar5 + 0xb,iVar17 + 0xf,
                      DAT_140029074 >> 4,0);
        if (DAT_140029a30 <= uVar10) {
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        FUN_140006d00(*(uint *)(DAT_140029a28 + uVar10 * 4),DAT_140029074 + 6 + iVar5 + 0xb,
                      iVar17 + 0xf,DAT_140029074);
        uVar8 = (ulonglong)DAT_140029a30;
        uVar12 = (ulonglong)DAT_140029568;
        lVar14 = DAT_140029560;
        lVar15 = DAT_140029a28;
      }
      uVar9 = (int)uVar10 + 1;
      uVar10 = (ulonglong)uVar9;
    } while (uVar9 < (uint)uVar8);
  }
  return;
}


// ===== FUN_1400075e0 @ 1400075e0 size=1313

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400075e0(ulonglong param_1,ulonglong param_2,int param_3,int param_4,int param_5)

{
  longlong lVar1;
  undefined1 auVar2 [32];
  undefined1 auVar3 [16];
  char cVar4;
  undefined1 auVar5 [32];
  undefined1 auVar6 [32];
  uint uVar7;
  undefined4 *puVar8;
  byte bVar9;
  uint uVar10;
  ulonglong uVar11;
  uint *puVar12;
  short *psVar13;
  uint uVar14;
  uint uVar15;
  ulonglong uVar16;
  char *pcVar17;
  int *piVar18;
  longlong lVar19;
  float fVar20;
  undefined1 auVar21 [16];
  undefined1 auVar22 [16];
  
  auVar6 = _DAT_140025380;
  auVar5 = _DAT_140025200;
  uVar14 = param_3 * param_4;
  uVar11 = 0;
  uVar7 = 0;
  uVar15 = *(uint *)(&DAT_140023f20 + (longlong)param_5 * 4);
  if (*(int *)(&DAT_140023f60 + (longlong)param_5 * 4) != 0) {
    if (uVar14 == 0) {
      return;
    }
    if ((0x1f < uVar14) &&
       ((param_2 + (ulonglong)(uVar14 - 1) * 4 < param_1 ||
        (param_1 + (ulonglong)(uVar14 - 1) * 4 < param_2)))) {
      uVar15 = 0x10;
      uVar16 = uVar11;
      do {
        uVar10 = (int)uVar16 + 0x20;
        uVar11 = (ulonglong)uVar10;
        auVar2 = vmaxps_avx(auVar6,*(undefined1 (*) [32])(param_2 + uVar16 * 4));
        auVar2 = vminps_avx(auVar5,auVar2);
        *(undefined1 (*) [32])(param_1 + uVar16 * 4) = auVar2;
        auVar2 = vmaxps_avx(auVar6,*(undefined1 (*) [32])(param_2 + (ulonglong)(uVar15 - 8) * 4));
        auVar2 = vminps_avx(auVar5,auVar2);
        *(undefined1 (*) [32])(param_1 + (ulonglong)(uVar15 - 8) * 4) = auVar2;
        auVar2 = vmaxps_avx(auVar6,*(undefined1 (*) [32])(param_2 + (ulonglong)uVar15 * 4));
        auVar2 = vminps_avx(auVar5,auVar2);
        *(undefined1 (*) [32])(param_1 + (ulonglong)uVar15 * 4) = auVar2;
        uVar7 = uVar15 + 8;
        uVar15 = uVar15 + 0x20;
        auVar2 = vmaxps_avx(auVar6,*(undefined1 (*) [32])(param_2 + (ulonglong)uVar7 * 4));
        auVar2 = vminps_avx(auVar5,auVar2);
        *(undefined1 (*) [32])(param_1 + (ulonglong)uVar7 * 4) = auVar2;
        uVar16 = uVar11;
      } while (uVar10 < (uVar14 & 0xffffffe0));
    }
    uVar15 = (uint)uVar11;
    if (uVar14 <= uVar15) {
      return;
    }
    lVar19 = param_2 - param_1;
    auVar21 = ZEXT416((-1f));
    auVar22 = ZEXT416((1f));
    if (3 < uVar14 - uVar15) {
      lVar1 = uVar11 * 4;
      uVar7 = ((uVar14 - uVar15) - 4 >> 2) + 1;
      uVar16 = (ulonglong)uVar7;
      uVar15 = uVar15 + uVar7 * 4;
      uVar11 = uVar11 + (ulonglong)uVar7 * 4;
      puVar8 = (undefined4 *)(param_1 + 4 + lVar1);
      do {
        auVar3 = vmaxss_avx(auVar21,ZEXT416(*(uint *)((longlong)puVar8 + lVar19 + -4)));
        auVar3 = vminss_avx(auVar22,auVar3);
        puVar8[-1] = auVar3._0_4_;
        auVar3 = vmaxss_avx(auVar21,ZEXT416(*(uint *)((longlong)puVar8 + lVar19)));
        auVar3 = vminss_avx(auVar22,auVar3);
        *puVar8 = auVar3._0_4_;
        auVar3 = vmaxss_avx(auVar21,ZEXT416(*(uint *)((longlong)puVar8 + lVar19 + 4)));
        auVar3 = vminss_avx(auVar22,auVar3);
        puVar8[1] = auVar3._0_4_;
        auVar3 = vmaxss_avx(auVar21,ZEXT416(*(uint *)((longlong)puVar8 + lVar19 + 8)));
        auVar3 = vminss_avx(auVar22,auVar3);
        puVar8[2] = auVar3._0_4_;
        uVar16 = uVar16 - 1;
        puVar8 = puVar8 + 4;
      } while (uVar16 != 0);
      if (uVar14 <= uVar15) {
        return;
      }
    }
    uVar16 = (ulonglong)(uVar14 - uVar15);
    puVar8 = (undefined4 *)(param_1 + uVar11 * 4);
    do {
      auVar3 = vmaxss_avx(auVar21,ZEXT416(*(uint *)((longlong)puVar8 + lVar19)));
      auVar3 = vminss_avx(auVar22,auVar3);
      *puVar8 = auVar3._0_4_;
      uVar16 = uVar16 - 1;
      puVar8 = puVar8 + 1;
    } while (uVar16 != 0);
    return;
  }
  fVar20 = (float)((1 << (uVar15 - 1 & 0x1f)) + -1);
  auVar21 = ZEXT416((-1f));
  auVar22 = ZEXT416((1f));
  cVar4 = (char)uVar15;
  if (uVar15 < 9) {
    if (uVar14 < 4) {
      if (uVar14 == 0) {
        return;
      }
      bVar9 = 8 - cVar4;
    }
    else {
      bVar9 = 8 - cVar4;
      uVar15 = (uVar14 - 4 >> 2) + 1;
      uVar16 = (ulonglong)uVar15;
      uVar7 = uVar15 * 4;
      uVar11 = (ulonglong)uVar15 * 4;
      puVar12 = (uint *)(param_2 + 8);
      pcVar17 = (char *)(param_1 + 2);
      do {
        auVar3 = vmaxss_avx(auVar21,ZEXT416(puVar12[-2]));
        auVar3 = vminss_avx(auVar22,auVar3);
        pcVar17[-2] = (char)(longlong)(auVar3._0_4_ * fVar20) << (bVar9 & 0x1f);
        auVar3 = vmaxss_avx(auVar21,ZEXT416(puVar12[-1]));
        auVar3 = vminss_avx(auVar22,auVar3);
        pcVar17[-1] = (char)(longlong)(auVar3._0_4_ * fVar20) << (bVar9 & 0x1f);
        auVar3 = vmaxss_avx(auVar21,ZEXT416(*puVar12));
        auVar3 = vminss_avx(auVar22,auVar3);
        *pcVar17 = (char)(longlong)(auVar3._0_4_ * fVar20) << (bVar9 & 0x1f);
        auVar3 = vmaxss_avx(auVar21,ZEXT416(puVar12[1]));
        auVar3 = vminss_avx(auVar22,auVar3);
        pcVar17[1] = (char)(longlong)(auVar3._0_4_ * fVar20) << (bVar9 & 0x1f);
        uVar16 = uVar16 - 1;
        puVar12 = puVar12 + 4;
        pcVar17 = pcVar17 + 4;
      } while (uVar16 != 0);
      if (uVar14 <= uVar7) {
        return;
      }
    }
    pcVar17 = (char *)(uVar11 + param_1);
    uVar16 = (ulonglong)(uVar14 - uVar7);
    puVar12 = (uint *)(param_2 + uVar11 * 4);
    do {
      auVar3 = vmaxss_avx(auVar21,ZEXT416(*puVar12));
      auVar3 = vminss_avx(auVar22,auVar3);
      puVar12 = puVar12 + 1;
      *pcVar17 = (char)(longlong)(auVar3._0_4_ * fVar20) << (bVar9 & 0x1f);
      pcVar17 = pcVar17 + 1;
      uVar16 = uVar16 - 1;
    } while (uVar16 != 0);
    return;
  }
  if (uVar15 < 0x11) {
    if (uVar14 < 4) {
      if (uVar14 == 0) {
        return;
      }
      bVar9 = 0x10 - cVar4;
      uVar16 = uVar11;
    }
    else {
      bVar9 = 0x10 - cVar4;
      uVar15 = (uVar14 - 4 >> 2) + 1;
      uVar16 = (ulonglong)uVar15;
      uVar11 = (ulonglong)(uVar15 * 4);
      psVar13 = (short *)(param_1 + 4);
      puVar12 = (uint *)(param_2 + 8);
      do {
        auVar3 = vmaxss_avx(auVar21,ZEXT416(puVar12[-2]));
        auVar3 = vminss_avx(auVar22,auVar3);
        psVar13[-2] = (short)(longlong)(auVar3._0_4_ * fVar20) << (bVar9 & 0x1f);
        auVar3 = vmaxss_avx(auVar21,ZEXT416(puVar12[-1]));
        auVar3 = vminss_avx(auVar22,auVar3);
        psVar13[-1] = (short)(longlong)(auVar3._0_4_ * fVar20) << (bVar9 & 0x1f);
        auVar3 = vmaxss_avx(auVar21,ZEXT416(*puVar12));
        auVar3 = vminss_avx(auVar22,auVar3);
        *psVar13 = (short)(longlong)(auVar3._0_4_ * fVar20) << (bVar9 & 0x1f);
        auVar3 = vmaxss_avx(auVar21,ZEXT416(puVar12[1]));
        auVar3 = vminss_avx(auVar22,auVar3);
        psVar13[1] = (short)(longlong)(auVar3._0_4_ * fVar20) << (bVar9 & 0x1f);
        uVar16 = uVar16 - 1;
        psVar13 = psVar13 + 4;
        puVar12 = puVar12 + 4;
      } while (uVar16 != 0);
      uVar16 = (ulonglong)uVar15 * 4;
      if (uVar14 <= uVar15 * 4) {
        return;
      }
    }
    puVar12 = (uint *)(param_2 + uVar16 * 4);
    psVar13 = (short *)(param_1 + uVar16 * 2);
    do {
      auVar3 = vmaxss_avx(auVar21,ZEXT416(*puVar12));
      auVar3 = vminss_avx(auVar22,auVar3);
      puVar12 = puVar12 + 1;
      uVar15 = (int)uVar11 + 1;
      uVar11 = (ulonglong)uVar15;
      *psVar13 = (short)(longlong)(auVar3._0_4_ * fVar20) << (bVar9 & 0x1f);
      psVar13 = psVar13 + 1;
    } while (uVar15 < uVar14);
    return;
  }
  if (uVar14 < 4) {
    if (uVar14 == 0) {
      return;
    }
    uVar15 = 0x20 - uVar15;
    lVar19 = param_2 - param_1;
    uVar16 = uVar11;
  }
  else {
    uVar15 = 0x20 - uVar15;
    lVar19 = param_2 - param_1;
    uVar7 = (uVar14 - 4 >> 2) + 1;
    uVar16 = (ulonglong)uVar7;
    uVar11 = (ulonglong)(uVar7 * 4);
    piVar18 = (int *)(param_1 + 4);
    do {
      auVar3 = vmaxss_avx(auVar21,ZEXT416(*(uint *)((longlong)piVar18 + lVar19 + -4)));
      auVar3 = vminss_avx(auVar22,auVar3);
      piVar18[-1] = (int)(longlong)(auVar3._0_4_ * fVar20) << (uVar15 & 0x1f);
      auVar3 = vmaxss_avx(auVar21,ZEXT416(*(uint *)((longlong)piVar18 + lVar19)));
      auVar3 = vminss_avx(auVar22,auVar3);
      *piVar18 = (int)(longlong)(auVar3._0_4_ * fVar20) << (uVar15 & 0x1f);
      auVar3 = vmaxss_avx(auVar21,ZEXT416(*(uint *)((longlong)piVar18 + lVar19 + 4)));
      auVar3 = vminss_avx(auVar22,auVar3);
      piVar18[1] = (int)(longlong)(auVar3._0_4_ * fVar20) << (uVar15 & 0x1f);
      auVar3 = vmaxss_avx(auVar21,ZEXT416(*(uint *)((longlong)piVar18 + lVar19 + 8)));
      auVar3 = vminss_avx(auVar22,auVar3);
      piVar18[2] = (int)(longlong)(auVar3._0_4_ * fVar20) << (uVar15 & 0x1f);
      uVar16 = uVar16 - 1;
      piVar18 = piVar18 + 4;
    } while (uVar16 != 0);
    uVar16 = (ulonglong)uVar7 * 4;
    if (uVar14 <= uVar7 * 4) {
      return;
    }
  }
  piVar18 = (int *)(param_1 + uVar16 * 4);
  do {
    auVar3 = vmaxss_avx(auVar21,ZEXT416(*(uint *)(lVar19 + (longlong)piVar18)));
    auVar3 = vminss_avx(auVar22,auVar3);
    uVar7 = (int)uVar11 + 1;
    uVar11 = (ulonglong)uVar7;
    *piVar18 = (int)(longlong)(auVar3._0_4_ * fVar20) << (uVar15 & 0x1f);
    piVar18 = piVar18 + 1;
  } while (uVar7 < uVar14);
  return;
}


// ===== FUN_140007b10 @ 140007b10 size=88

undefined8 FUN_140007b10(longlong param_1)

{
  uint uVar1;
  uint *puVar2;
  code *pcVar3;
  undefined8 uVar4;
  uint uVar5;
  ulonglong uVar6;
  
  puVar2 = *(uint **)(param_1 + 0x128);
  if (puVar2 == (uint *)0x0) {
    pcVar3 = (code *)swi(3);
    uVar4 = (*pcVar3)();
    return uVar4;
  }
  uVar1 = *puVar2;
  if (uVar1 != 0) {
    uVar6 = 0;
    if (uVar1 != 0) {
      do {
        if (*(uint *)(param_1 + 0x40 + uVar6 * 8) < puVar2[uVar6 * 2 + 2]) {
          return 0;
        }
        uVar5 = (int)uVar6 + 1;
        uVar6 = (ulonglong)uVar5;
      } while (uVar5 < uVar1);
    }
    return 1;
  }
  if ((*(int *)(param_1 + 0x40) == 0) && (*(int *)(param_1 + 0x48) == 0)) {
    return 0;
  }
  return 1;
}


// ===== FUN_140007b70 @ 140007b70 size=284

undefined8 FUN_140007b70(ulonglong param_1,uint param_2,int param_3,int param_4)

{
  char cVar1;
  bool bVar2;
  int *piVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined7 extraout_var;
  uint uVar6;
  
  if (((((uint)param_1 < (uint)DAT_140029a88) &&
       (uVar6 = (uint)(param_1 >> 0x20), uVar6 < DAT_140029a88._4_4_)) &&
      (cVar1 = *(char *)((ulonglong)(uVar6 * (uint)DAT_140029a88 + (uint)param_1) + DAT_140029a90),
      cVar1 != '\a')) && (cVar1 != '\b')) {
    piVar3 = (int *)FUN_140009990(param_1,param_2);
    if (((piVar3 != (int *)0x0) && (*(longlong *)(piVar3 + 2) != 0)) && (*piVar3 == 1)) {
      return 1;
    }
    lVar4 = FUN_140009990(param_1,param_2);
    if (lVar4 == 0) {
      if (param_2 == 0) {
        if ((param_4 != 0) && (uVar5 = FUN_14000a5d0(param_1), (int)uVar5 != 0)) {
          return 0;
        }
        FUN_14001dfb0(param_1);
        FUN_140014a90(param_1);
      }
      bVar2 = FUN_140012490(param_1,param_2,param_3);
      if ((int)CONCAT71(extraout_var,bVar2) != 0) {
        lVar4 = FUN_140009990(param_1,param_2);
        if (lVar4 == 0) {
          return 1;
        }
        if (*(longlong *)(lVar4 + 8) == 0) {
          return 1;
        }
        if (0xffff < *(uint *)(lVar4 + 0x34)) {
          return 1;
        }
        *(int *)(&DAT_1400aa9f0 + (ulonglong)*(uint *)(lVar4 + 0x34) * 4) = param_4;
        return 1;
      }
    }
  }
  return 0;
}


// ===== FUN_140007c90 @ 140007c90 size=366

undefined8 FUN_140007c90(ulonglong *param_1,longlong param_2)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  ulonglong local_res8;
  
  local_res8 = *param_1;
  auVar8._8_8_ = 0;
  auVar8._0_8_ = local_res8;
  auVar6._4_12_ = ZEXT812(0) << 0x20;
  auVar6._0_4_ = (int)local_res8;
  auVar6 = vroundps_avx(auVar6,1);
  auVar7 = vshufps_avx(auVar8,auVar8,0x55);
  auVar7._4_12_ = ZEXT812(0) << 0x20;
  auVar7 = vroundps_avx(auVar7,1);
  iVar5 = (int)(longlong)auVar7._0_4_;
  iVar4 = (int)(longlong)auVar6._0_4_;
  if (param_2 == CONCAT44(iVar5,iVar4)) {
    *(ulonglong *)((longlong)param_1 + 100) =
         (longlong)auVar7._0_4_ << 0x20 | (longlong)auVar6._0_4_ & 0xffffffffU;
    *(undefined8 *)((longlong)param_1 + 0x2064) = 1;
  }
  else {
    if (((*(int *)((longlong)param_1 + 0x2074) == 0) ||
        (*(int *)((longlong)param_1 + 0x206c) != (int)param_2)) ||
       (bVar2 = true, (int)param_1[0x40e] != (int)((ulonglong)param_2 >> 0x20))) {
      bVar2 = false;
    }
    if (((*(uint *)((longlong)param_1 + 0x2064) == 0) ||
        (uVar1 = (uint)param_1[0x40d], *(uint *)((longlong)param_1 + 0x2064) <= uVar1)) ||
       ((*(int *)((longlong)param_1 + (ulonglong)uVar1 * 8 + 100) != iVar4 ||
        (bVar3 = true, (int)param_1[(ulonglong)uVar1 + 0xd] != iVar5)))) {
      bVar3 = false;
    }
    if ((bVar2) && (bVar3)) {
      return 1;
    }
    *(undefined8 *)((longlong)param_1 + 0x2064) = 0;
    *(undefined8 *)((longlong)param_1 + 0x206c) = 0;
    *(undefined4 *)((longlong)param_1 + 0x2074) = 0;
    if (DAT_14002a8f0 == (code *)0x0) {
      return 0;
    }
    local_res8 = local_res8 & 0xffffffff00000000;
    iVar4 = (*DAT_14002a8f0)(0,param_2,(longlong)param_1 + 100,&local_res8,0x400,DAT_14002a8f8);
    if (iVar4 == 0) {
      return 0;
    }
    if ((int)local_res8 == 0) {
      return 0;
    }
    *(int *)((longlong)param_1 + 0x2064) = (int)local_res8;
    *(undefined4 *)(param_1 + 0x40d) = 0;
  }
  *(longlong *)((longlong)param_1 + 0x206c) = param_2;
  *(undefined4 *)((longlong)param_1 + 0x2074) = 1;
  return 1;
}


// ===== FUN_140007e00 @ 140007e00 size=432

void FUN_140007e00(uint *param_1,longlong param_2,undefined8 param_3)

{
  int iVar1;
  int iVar2;
  ulonglong uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  iVar1 = (int)((ulonglong)param_3 >> 0x20);
  uVar7 = 0;
  if (0 < (int)(iVar1 - 0xcU)) {
    uVar7 = iVar1 - 0xcU;
  }
  iVar8 = DAT_140029a88._4_4_ - 1;
  if (iVar1 + 0xc < (int)(DAT_140029a88._4_4_ - 1)) {
    iVar8 = iVar1 + 0xc;
  }
  iVar2 = (int)param_3;
  if ((int)uVar7 <= iVar8) {
    uVar4 = 0;
    if (0 < (int)(iVar2 - 0xcU)) {
      uVar4 = iVar2 - 0xcU;
    }
    uVar5 = uVar4;
    iVar6 = (uint)DAT_140029a88 - 1;
    if (iVar2 + 0xc < (int)((uint)DAT_140029a88 - 1)) {
      iVar6 = iVar2 + 0xc;
    }
    do {
      for (; (int)uVar5 <= iVar6; uVar5 = uVar5 + 1) {
        if (((uVar5 < (uint)DAT_140029a88) && (uVar7 < DAT_140029a88._4_4_)) &&
           (*(char *)((ulonglong)(uVar7 * (uint)DAT_140029a88 + uVar5) + DAT_140029a90) == '\x04'))
        {
          return;
        }
      }
      uVar7 = uVar7 + 1;
      uVar5 = uVar4;
    } while ((int)uVar7 <= iVar8);
  }
  uVar7 = 0;
  do {
    uVar4 = uVar7 * -0x7a143595 ^ *param_1 ^ 0xf10a0f55;
    uVar4 = (uVar4 >> 0x10 ^ uVar4) * 0x45d9f3b;
    uVar4 = (uVar4 >> 0x10 ^ uVar4) * 0x45d9f3b;
    uVar4 = uVar4 >> 0x10 ^ uVar4;
    uVar5 = uVar4 >> 9 & 5;
    iVar8 = (uVar4 >> 4 & 5) + 6 + iVar2;
    if (iVar8 < 0) {
      iVar8 = 0;
    }
    iVar6 = uVar5 - 2;
    if ((uVar4 & 2) == 0) {
      iVar6 = 2 - uVar5;
    }
    iVar6 = iVar6 + iVar1;
    if (iVar6 < 0) {
      iVar6 = 0;
    }
    if ((int)(DAT_140029a88._4_4_ - 1) < iVar6) {
      iVar6 = DAT_140029a88._4_4_ - 1;
    }
    if ((int)((uint)DAT_140029a88 - 1) < iVar8) {
      iVar8 = (uint)DAT_140029a88 - 1;
    }
    uVar3 = FUN_14001d610((longlong)param_1,param_2,CONCAT44(iVar6,iVar8),4,(uVar4 >> 0xd & 3) + 0xb
                          ,uVar4,0,1);
  } while (((int)uVar3 == 0) && (uVar7 = uVar7 + 1, uVar7 < 0x10));
  return;
}


// ===== FUN_140007fb0 @ 140007fb0 size=50

void FUN_140007fb0(float *param_1,uint param_2,uint param_3,undefined8 param_4)

{
  FUN_140010300(param_1,param_2,param_3,param_4);
  DAT_14002a8a0 = (double)(float)param_4 + DAT_14002a8a0;
  return;
}


// ===== FUN_140007ff0 @ 140007ff0 size=153

void FUN_140007ff0(int param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  ulonglong uVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = 0;
  if (0 < param_1) {
    iVar7 = param_1;
  }
  iVar5 = 0;
  if (0 < param_2) {
    iVar5 = param_2;
  }
  iVar1 = DAT_1400296d0;
  if (param_1 + param_3 < DAT_1400296d0) {
    iVar1 = param_1 + param_3;
  }
  iVar2 = DAT_1400296d4;
  if (param_2 + param_4 < DAT_1400296d4) {
    iVar2 = param_2 + param_4;
  }
  if ((iVar7 < iVar1) && (iVar5 < iVar2)) {
    do {
      iVar6 = iVar5 + 1;
      puVar4 = (undefined4 *)
               (DAT_1400296c8 + (longlong)(iVar5 * DAT_1400296d0) * 4 + (longlong)iVar7 * 4);
      for (uVar3 = (longlong)(iVar1 - iVar7) & 0x3fffffffffffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar4 = param_5;
        puVar4 = puVar4 + 1;
      }
      iVar5 = iVar6;
    } while (iVar6 < iVar2);
  }
  return;
}


// ===== FUN_140008090 @ 140008090 size=377

ulonglong FUN_140008090(int param_1,int param_2,int param_3,int param_4,uint param_5)

{
  uint uVar1;
  ulonglong uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar7;
  int iVar8;
  undefined1 *puVar9;
  int iVar10;
  longlong lVar11;
  longlong lVar12;
  ulonglong uVar6;
  
  iVar8 = 0;
  if (0 < param_1) {
    iVar8 = param_1;
  }
  iVar10 = 0;
  if (0 < param_2) {
    iVar10 = param_2;
  }
  iVar3 = DAT_1400296d0;
  if (param_1 + param_3 < DAT_1400296d0) {
    iVar3 = param_1 + param_3;
  }
  uVar5 = param_2 + param_4;
  uVar6 = (ulonglong)uVar5;
  uVar4 = DAT_1400296d4;
  if ((int)uVar5 < (int)DAT_1400296d4) {
    uVar4 = uVar5;
  }
  if ((iVar8 < iVar3) && (iVar10 < (int)uVar4)) {
    uVar5 = param_5 >> 0x18;
    uVar6 = (ulonglong)uVar5;
    if ((char)(param_5 >> 0x18) != '\0') {
      iVar7 = 0xff - uVar5;
      lVar12 = (longlong)iVar8;
      iVar8 = DAT_1400296d0;
      do {
        uVar6 = DAT_1400296c8;
        if (lVar12 < iVar3) {
          lVar11 = iVar3 - lVar12;
          puVar9 = (undefined1 *)(lVar12 * 4 + 2 + DAT_1400296c8 + (longlong)(iVar10 * iVar8) * 4);
          do {
            uVar1 = *(uint *)(puVar9 + -2);
            puVar9[1] = 0xff;
            puVar9[-2] = (char)((ulonglong)((uVar1 & 0xff) * iVar7 + (param_5 & 0xff) * uVar5) /
                               0xff);
            puVar9[-1] = (char)((ulonglong)
                                ((uVar1 >> 8 & 0xff) * iVar7 + (param_5 >> 8 & 0xff) * uVar5) / 0xff
                               );
            uVar2 = (ulonglong)((uVar1 >> 0x10 & 0xff) * iVar7 + (param_5 >> 0x10 & 0xff) * uVar5);
            uVar6 = uVar2 * 0x80808081 & 0xffffffff;
            *puVar9 = (char)(uVar2 / 0xff);
            lVar11 = lVar11 + -1;
            puVar9 = puVar9 + 4;
            iVar8 = DAT_1400296d0;
          } while (lVar11 != 0);
        }
        iVar10 = iVar10 + 1;
      } while (iVar10 < (int)uVar4);
    }
  }
  return uVar6;
}


// ===== FUN_140008210 @ 140008210 size=1163

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
FUN_140008210(ulonglong param_1,ulonglong param_2,undefined8 *param_3,uint *param_4,uint param_5)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  ulonglong uVar7;
  uint uVar9;
  ulonglong uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  undefined8 *puVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  undefined1 *puVar18;
  uint uVar19;
  undefined1 uVar20;
  int iVar21;
  char *pcVar22;
  longlong lVar23;
  uint uVar24;
  uint uVar25;
  undefined8 local_res8;
  char local_2068 [4];
  uint local_2064;
  uint local_2060;
  ulonglong local_2058;
  undefined8 local_2048 [1025];
  ulonglong uVar8;
  
  uVar25 = 0;
  *param_4 = 0;
  uVar17 = DAT_140029a88._4_4_;
  uVar19 = (uint)DAT_140029a88;
  if (((((uint)param_1 < (uint)DAT_140029a88) &&
       (uVar24 = (uint)(param_1 >> 0x20), uVar24 < DAT_140029a88._4_4_)) &&
      (uVar15 = (uint)param_2, uVar15 < (uint)DAT_140029a88)) &&
     ((uVar9 = (uint)(param_2 >> 0x20), uVar9 < DAT_140029a88._4_4_ && (param_5 != 0)))) {
    if (param_1 == param_2) {
      *param_3 = param_1;
      *param_4 = 1;
      return 1;
    }
    uVar11 = DAT_140029a88._4_4_ * (uint)DAT_140029a88;
    puVar18 = &DAT_14012bb40;
    for (uVar10 = (ulonglong)uVar11; uVar10 != 0; uVar10 = uVar10 - 1) {
      *puVar18 = 0;
      puVar18 = puVar18 + 1;
    }
    if (uVar11 != 0) {
      FUN_1400200d0(&DAT_1400ebb40,0xff,(ulonglong)uVar11 << 2);
    }
    uVar10 = 0;
    uVar11 = uVar9 * uVar19 + uVar15;
    local_2060 = uVar11;
    _DAT_14013bb40 = param_1;
    (&DAT_14012bb40)[uVar24 * uVar19 + (uint)param_1] = 1;
    uVar24 = 1;
    do {
      lVar1 = DAT_140029a90;
      local_2064 = (int)uVar10 + 1;
      local_2058 = *(ulonglong *)(&DAT_14013bb40 + uVar10 * 8);
      iVar6 = (int)local_2058;
      uVar12 = (uint)(local_2058 >> 0x20);
      if (param_2 == local_2058) break;
      local_2068[1] = '\x03';
      iVar4 = uVar15 - iVar6;
      local_2068[3] = 2;
      uVar20 = 1;
      if (-1 < iVar4) {
        local_2068[1] = '\x01';
        uVar20 = 3;
      }
      iVar16 = uVar9 - uVar12;
      cVar2 = '\0';
      if (-1 < iVar16) {
        local_2068[3] = 0;
        cVar2 = '\x02';
      }
      iVar3 = -iVar4;
      if (0 < iVar4) {
        iVar3 = iVar4;
      }
      iVar4 = -iVar16;
      if (0 < iVar16) {
        iVar4 = iVar16;
      }
      if (iVar3 < iVar4) {
        local_2068[0] = cVar2;
        local_2068[2] = uVar20;
      }
      else {
        local_2068[0] = local_2068[1];
        local_2068[1] = cVar2;
        local_2068[2] = local_2068[3];
        local_2068[3] = uVar20;
      }
      uVar10 = (ulonglong)uVar12;
      pcVar22 = local_2068;
      lVar23 = 4;
      do {
        cVar2 = *pcVar22;
        if (cVar2 == '\0') {
          if (uVar12 == 0) {
            uVar7 = 0;
          }
          else {
            uVar7 = (ulonglong)(uVar12 - 1);
          }
LAB_14000841c:
          uVar8 = local_2058 & 0xffffffff;
LAB_14000841e:
          uVar8 = uVar7 << 0x20 | uVar8;
        }
        else {
          uVar7 = uVar10;
          if (cVar2 == '\x01') {
            uVar8 = (ulonglong)(iVar6 + 1);
            goto LAB_14000841e;
          }
          if (cVar2 == '\x02') {
            uVar7 = (ulonglong)(uVar12 + 1);
            goto LAB_14000841c;
          }
          uVar8 = local_2058;
          if (cVar2 == '\x03') {
            if (iVar6 == 0) {
              uVar8 = 0;
            }
            else {
              uVar8 = (ulonglong)(iVar6 - 1);
            }
            goto LAB_14000841e;
          }
        }
        uVar5 = (uint)uVar8;
        if ((((uVar5 < uVar19) && (uVar13 = (uint)(uVar8 >> 0x20), uVar13 < uVar17)) &&
            ((uVar7 = (ulonglong)(uVar13 * uVar19 + uVar5), (&DAT_14012bb40)[uVar7] == '\0' &&
             ((uVar5 < uVar19 && (uVar13 < uVar17)))))) &&
           (((param_1 == uVar8 || ((param_2 == uVar8 || (uVar17 <= uVar13)))) ||
            ((*(char *)(uVar7 + lVar1) != '\a' && (*(char *)(uVar7 + lVar1) != '\b')))))) {
          (&DAT_14012bb40)[uVar7] = 1;
          *(uint *)(&DAT_1400ebb40 + uVar7 * 4) = uVar12 * uVar19 + iVar6;
          uVar7 = (ulonglong)uVar24;
          uVar24 = uVar24 + 1;
          *(ulonglong *)(&DAT_14013bb40 + uVar7 * 8) = uVar8;
        }
        pcVar22 = pcVar22 + 1;
        lVar23 = lVar23 + -1;
      } while (lVar23 != 0);
      uVar10 = (ulonglong)local_2064;
    } while (local_2064 < uVar24);
    uVar10 = (ulonglong)uVar11;
    if ((&DAT_14012bb40)[uVar10] != '\0') {
      FUN_1400200d0((undefined1 *)local_2048,0,0x2000);
      uVar17 = 0;
      if (-1 < (int)uVar11) {
        do {
          uVar24 = uVar17;
          if (0x3ff < uVar24) {
            return 0;
          }
          local_res8 = CONCAT44((int)(uVar10 / uVar19),(int)(uVar10 % (ulonglong)uVar19));
          uVar17 = uVar24 + 1;
          local_2048[uVar24] = local_res8;
          lVar1 = uVar10 * 4;
          uVar10 = (ulonglong)*(uint *)(&DAT_1400ebb40 + lVar1);
        } while (-1 < (int)*(uint *)(&DAT_1400ebb40 + lVar1));
        if (uVar17 != 0) {
          puVar14 = &DAT_1401bbb40;
          do {
            iVar6 = uVar17 - uVar25;
            uVar25 = uVar25 + 1;
            *puVar14 = local_2048[iVar6 - 1];
            puVar14 = puVar14 + 1;
          } while (uVar25 < uVar17);
          uVar19 = 1;
          *param_3 = CONCAT44(DAT_1401bbb40._4_4_,(int)DAT_1401bbb40);
          if (1 < uVar17) {
            iVar6 = DAT_1401bbb48 - (int)DAT_1401bbb40;
            iVar4 = _DAT_1401bbb4c - DAT_1401bbb40._4_4_;
            if (2 < uVar17) {
              uVar10 = 2;
              do {
                iVar16 = *(int *)(&DAT_1401bbb40 + uVar10);
                uVar25 = (int)uVar10 - 1;
                iVar3 = *(int *)(&DAT_1401bbb40 + uVar25);
                iVar21 = *(int *)((longlong)&DAT_1401bbb40 + uVar10 * 8 + 4) -
                         *(int *)((longlong)&DAT_1401bbb40 + (ulonglong)uVar25 * 8 + 4);
                if ((iVar16 - iVar3 != iVar6) || (iVar21 != iVar4)) {
                  if (param_5 <= uVar19) {
                    return 0;
                  }
                  uVar7 = (ulonglong)uVar19;
                  uVar19 = uVar19 + 1;
                  param_3[uVar7] = (&DAT_1401bbb40)[uVar25];
                  iVar6 = iVar16 - iVar3;
                  iVar4 = iVar21;
                }
                uVar25 = (int)uVar10 + 1;
                uVar10 = (ulonglong)uVar25;
              } while (uVar25 < uVar17);
            }
            if (param_5 <= uVar19) {
              return 0;
            }
            uVar10 = (ulonglong)uVar19;
            uVar19 = uVar19 + 1;
            param_3[uVar10] = (&DAT_1401bbb40)[uVar24];
          }
          *param_4 = uVar19;
          return 1;
        }
      }
    }
  }
  return 0;
}


// ===== FUN_1400086a0 @ 1400086a0 size=178

ulonglong FUN_1400086a0(undefined8 param_1)

{
  uint *puVar1;
  uint uVar2;
  code *pcVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  uint uVar6;
  uint uStackX_c;
  
  uVar4 = 0;
  if (DAT_14002a9d8 != 0) {
    uStackX_c = (uint)((ulonglong)param_1 >> 0x20);
    do {
      if (DAT_14002a9d8 <= uVar4) {
        pcVar3 = (code *)swi(3);
        uVar4 = (*pcVar3)();
        return uVar4;
      }
      puVar1 = (uint *)(DAT_14002a9d0 + uVar4 * 0xc);
      uVar6 = *puVar1;
      uVar5 = 0x200000002;
      if (*(int *)(DAT_14002a9d0 + 8 + uVar4 * 0xc) == 0) {
        uVar5 = 0x100000001;
      }
      if ((((uVar6 <= (uint)param_1) && (uVar2 = puVar1[1], uVar2 <= uStackX_c)) &&
          ((uint)param_1 < uVar6 + (int)uVar5)) &&
         (uStackX_c < (int)((ulonglong)uVar5 >> 0x20) + uVar2)) {
        return uVar4;
      }
      uVar6 = (int)uVar4 + 1;
      uVar4 = (ulonglong)uVar6;
    } while (uVar6 < DAT_14002a9d8);
  }
  return 0xffffffff;
}


// ===== FUN_140008760 @ 140008760 size=156

void FUN_140008760(longlong param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 8) = 1;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined8 *)(param_1 + 0x2064) = 0;
  *(undefined8 *)(param_1 + 0x206c) = 0;
  *(undefined4 *)(param_1 + 0x2074) = 0;
  if (*(int *)(param_1 + 0x54) != 0) {
    *(undefined1 *)(param_1 + 0x34) = 3;
    return;
  }
  if (*(int *)(param_1 + 0x50) != 0) {
    *(undefined1 *)(param_1 + 0x34) = 2;
    return;
  }
  *(undefined8 *)(param_1 + 0x38) = 0;
  *(undefined8 *)(param_1 + 0x40) = 0;
  *(undefined8 *)(param_1 + 0x48) = 0;
  *(undefined8 *)(param_1 + 0x50) = 0x100000000;
  *(undefined1 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined4 *)(param_2 + 0x10) = 1;
  return;
}


// ===== FUN_140008800 @ 140008800 size=699

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * FUN_140008800(undefined8 *param_1,undefined8 param_2,uint param_3,int *param_4)

{
  undefined8 uVar1;
  bool bVar2;
  int *piVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined1 *puVar6;
  uint uVar7;
  longlong *plVar8;
  undefined1 *puVar9;
  int iStackX_14;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  
  piVar3 = (int *)FUN_140002550((undefined8 *)&DAT_14002a838);
  lVar4 = DAT_140029140 + 1;
  *(longlong *)(piVar3 + 2) = DAT_140029140;
  DAT_140029140 = lVar4;
  if (DAT_14002a858 == 0) {
    piVar3[0xd] = DAT_14002a870;
    puVar9 = DAT_14002a868;
    if (DAT_14002a870 == DAT_14002a874) {
      uVar7 = 8;
      if (8 < DAT_14002a874 * 2) {
        uVar7 = DAT_14002a874 * 2;
      }
      if (DAT_14002a874 < uVar7) {
        lVar4 = (ulonglong)DAT_14002a874 * 8;
        plVar8 = &DAT_140029878;
        if (DAT_14002a860 != (longlong *)0x0) {
          plVar8 = DAT_14002a860;
        }
        if ((DAT_14002a868 == (undefined1 *)0x0) ||
           (DAT_14002a868 + lVar4 != (undefined1 *)(*plVar8 + plVar8[2]))) {
          bVar2 = DAT_14002a874 < uVar7;
          puVar9 = (undefined1 *)0x0;
          DAT_14002a874 = uVar7;
          if (bVar2) {
            uVar5 = plVar8[2] + 7U & 0xfffffffffffffff8;
            puVar9 = (undefined1 *)(*plVar8 + uVar5);
            plVar8[2] = uVar5;
            puVar6 = puVar9;
            if (DAT_14002a868 != (undefined1 *)0x0) {
              for (; lVar4 != 0; lVar4 = lVar4 + -1) {
                *puVar6 = *DAT_14002a868;
                DAT_14002a868 = DAT_14002a868 + 1;
                puVar6 = puVar6 + 1;
              }
            }
            plVar8[2] = plVar8[2] + (ulonglong)uVar7 * 8;
          }
        }
        else {
          plVar8[2] = plVar8[2] + (ulonglong)(uVar7 - DAT_14002a874) * 8;
          DAT_14002a874 = uVar7;
        }
      }
    }
    DAT_14002a868 = puVar9;
    *(int **)(DAT_14002a868 + (ulonglong)DAT_14002a870 * 8) = piVar3;
    DAT_14002a870 = DAT_14002a870 + 1;
  }
  else {
    DAT_14002a858 = DAT_14002a858 - 1;
    uVar7 = *(uint *)(DAT_14002a850 + (ulonglong)DAT_14002a858 * 4);
    piVar3[0xd] = uVar7;
    *(int **)(DAT_14002a868 + (ulonglong)uVar7 * 8) = piVar3;
  }
  uVar1 = *(undefined8 *)(piVar3 + 2);
  *param_1 = piVar3;
  param_1[1] = uVar1;
  iStackX_14 = (int)((ulonglong)param_2 >> 0x20);
  *(undefined8 *)(piVar3 + 8) = param_2;
  piVar3[10] = param_3;
  local_44 = iStackX_14;
  local_48 = (int)param_2;
  local_40 = param_4[1] + -1 + local_48;
  local_3c = iStackX_14 + -1 + param_4[2];
  FUN_14001ba90(&local_48,param_3,piVar3[0xd]);
  puVar9 = DAT_14002a880;
  if (DAT_14002a888 == _DAT_14002a88c) {
    uVar7 = 8;
    if (8 < _DAT_14002a88c * 2) {
      uVar7 = _DAT_14002a88c * 2;
    }
    if (_DAT_14002a88c < uVar7) {
      lVar4 = (ulonglong)_DAT_14002a88c * 8;
      plVar8 = &DAT_140029878;
      if (DAT_14002a878 != (longlong *)0x0) {
        plVar8 = DAT_14002a878;
      }
      if ((DAT_14002a880 == (undefined1 *)0x0) ||
         (DAT_14002a880 + lVar4 != (undefined1 *)(*plVar8 + plVar8[2]))) {
        bVar2 = _DAT_14002a88c < uVar7;
        puVar9 = (undefined1 *)0x0;
        _DAT_14002a88c = uVar7;
        if (bVar2) {
          uVar5 = plVar8[2] + 7U & 0xfffffffffffffff8;
          puVar9 = (undefined1 *)(*plVar8 + uVar5);
          plVar8[2] = uVar5;
          puVar6 = puVar9;
          if (DAT_14002a880 != (undefined1 *)0x0) {
            for (; lVar4 != 0; lVar4 = lVar4 + -1) {
              *puVar6 = *DAT_14002a880;
              DAT_14002a880 = DAT_14002a880 + 1;
              puVar6 = puVar6 + 1;
            }
          }
          plVar8[2] = plVar8[2] + (ulonglong)uVar7 * 8;
        }
      }
      else {
        plVar8[2] = plVar8[2] + (ulonglong)(uVar7 - _DAT_14002a88c) * 8;
        _DAT_14002a88c = uVar7;
      }
    }
  }
  DAT_14002a880 = puVar9;
  *(int **)(DAT_14002a880 + (ulonglong)DAT_14002a888 * 8) = piVar3;
  DAT_14002a888 = DAT_14002a888 + 1;
  FUN_140002dc0(piVar3,param_4);
  return param_1;
}


// ===== FUN_140008ac0 @ 140008ac0 size=1052

/* WARNING: Removing unreachable block (ram,0x000140008b55) */

void FUN_140008ac0(uint *param_1,undefined8 *param_2,undefined8 param_3)

{
  undefined1 *puVar1;
  bool bVar2;
  uint uVar3;
  undefined7 extraout_var;
  longlong lVar4;
  ulonglong uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  uint *puVar12;
  undefined1 *puVar13;
  uint uVar14;
  float fVar15;
  double dVar16;
  float fVar17;
  float fVar18;
  ulonglong local_res10;
  
  dVar16 = FUN_1400066d0();
  uVar8 = (uint)DAT_140029a88 * 0x1003 ^ DAT_140029a88._4_4_ * 0x83 ^
          (uint)(longlong)(dVar16 * (1000000.0)) ^ 0xc5e4f123;
  uVar8 = (uVar8 >> 0x10 ^ uVar8) * 0x45d9f3b;
  uVar8 = (uVar8 >> 0x10 ^ uVar8) * 0x45d9f3b;
  *param_1 = uVar8 >> 0x10 ^ uVar8;
  *param_2 = &DAT_140029878;
  *(undefined4 *)(param_2 + 2) = 0;
  if (*(uint *)((longlong)param_2 + 0x14) == 0) {
    puVar13 = (undefined1 *)param_2[1];
    if (puVar13 == (undefined1 *)0x0) {
      DAT_140029888 = DAT_140029888 + 3 & 0xfffffffffffffffc;
      puVar13 = (undefined1 *)(DAT_140029878 + DAT_140029888);
    }
    else {
      lVar4 = (ulonglong)*(uint *)((longlong)param_2 + 0x14) * 0xc;
      if (puVar13 + lVar4 != (undefined1 *)(DAT_140029888 + DAT_140029878)) {
        DAT_140029888 = DAT_140029888 + 3 & 0xfffffffffffffffc;
        puVar1 = (undefined1 *)(DAT_140029888 + DAT_140029878);
        puVar10 = puVar13;
        puVar11 = puVar1;
        for (; puVar13 = puVar1, lVar4 != 0; lVar4 = lVar4 + -1) {
          *puVar11 = *puVar10;
          puVar10 = puVar10 + 1;
          puVar11 = puVar11 + 1;
        }
      }
    }
    DAT_140029888 = DAT_140029888 + 0x60;
    param_2[1] = puVar13;
    *(undefined4 *)((longlong)param_2 + 0x14) = 8;
  }
  uVar8 = *(uint *)(param_2 + 2);
  lVar4 = param_2[1];
  *(undefined8 *)(lVar4 + (ulonglong)uVar8 * 0xc) = 0;
  *(undefined4 *)(lVar4 + 8 + (ulonglong)uVar8 * 0xc) = 0;
  uVar8 = *(uint *)(param_2 + 2);
  *(uint *)(param_2 + 2) = uVar8 + 1;
  lVar4 = param_2[1];
  *(undefined8 *)(lVar4 + (ulonglong)uVar8 * 0xc) = param_3;
  *(undefined4 *)(lVar4 + 8 + (ulonglong)uVar8 * 0xc) = 1;
  uVar8 = 0x10000;
  if (DAT_140029a88._4_4_ * (uint)DAT_140029a88 < 0x10000) {
    uVar8 = DAT_140029a88._4_4_ * (uint)DAT_140029a88;
  }
  puVar12 = param_1 + 1;
  for (uVar5 = (ulonglong)uVar8; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined1 *)puVar12 = 0;
    puVar12 = (uint *)((longlong)puVar12 + 1);
  }
  puVar12 = param_1 + 0x4001;
  for (uVar5 = (ulonglong)uVar8; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined1 *)puVar12 = 0;
    puVar12 = (uint *)((longlong)puVar12 + 1);
  }
  FUN_14001b3e0(param_1);
  uVar5 = CONCAT44(DAT_140029a88._4_4_,(uint)DAT_140029a88);
  if ((0x17 < (uint)DAT_140029a88) && (0x11 < DAT_140029a88._4_4_)) {
    uVar8 = (*param_1 & 1) + 7;
    if (uVar8 != 0) {
      uVar14 = 0;
      local_res10 = (ulonglong)uVar8;
      fVar17 = (0.159999996f);
      fVar18 = (1.45000005f);
      do {
        uVar9 = 0;
        uVar8 = 0;
        while( true ) {
          uVar6 = uVar14 ^ uVar8 ^ *param_1 ^ 0x6d2b79f5;
          uVar6 = (uVar6 >> 0x10 ^ uVar6) * 0x45d9f3b;
          uVar7 = (uVar6 >> 0x10 ^ uVar6) * 0x45d9f3b;
          uVar3 = (uint)(uVar5 >> 1) & 0x7fffffff;
          fVar15 = (float)(uVar7 >> 0x10 ^ uVar7);
          uVar6 = 1;
          if (1 < uVar3) {
            uVar6 = uVar3;
          }
          uVar3 = 1;
          if (1 < DAT_140029a88._4_4_ - 8) {
            uVar3 = DAT_140029a88._4_4_ - 8;
          }
          uVar5 = CONCAT44(((uint)fVar15 >> 0xb) % uVar3 + 4,
                           (uint)fVar15 % uVar6 + (int)((uVar5 & 0xffffffff) / 3));
          bVar2 = FUN_140005430((longlong)param_2,uVar5);
          if ((int)CONCAT71(extraout_var,bVar2) != 0) break;
          uVar9 = uVar9 + 1;
          uVar8 = uVar8 + 0x85ebca6b;
          if (0x17 < uVar9) goto LAB_140008de5;
          uVar5 = CONCAT44(DAT_140029a88._4_4_,(uint)DAT_140029a88);
        }
        FUN_140008ee0((longlong)param_1,(longlong)param_2,uVar5,
                      (ulonglong)((uVar7 >> 0x16 & 0xd) + 0xb),
                      (float)(uVar7 >> 0x12 & 7) * fVar17 + fVar18,fVar15);
LAB_140008de5:
        uVar14 = uVar14 + 0x9e3779b9;
        local_res10 = local_res10 - 1;
        if (local_res10 == 0) break;
        uVar5 = CONCAT44(DAT_140029a88._4_4_,(uint)DAT_140029a88);
      } while( true );
    }
    FUN_14001bbb0((longlong)param_1,(longlong)param_2);
  }
  FUN_14001b580(param_1,(longlong)param_2,param_3);
  FUN_140009290(param_1,(longlong)param_2,2,3,7,0xc,0x51a91d1d);
  FUN_140009290(param_1,(longlong)param_2,3,3,7,0xc,0xc0ffee11);
  FUN_140009290(param_1,(longlong)param_2,4,4,8,0xe,0xf10a0f55);
  FUN_140007e00(param_1,(longlong)param_2,param_3);
  return;
}


// ===== FUN_140008ee0 @ 140008ee0 size=944

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140008ee0(longlong param_1,longlong param_2,ulonglong param_3,undefined8 param_4,
                  float param_5,float param_6)

{
  undefined1 auVar1 [16];
  float fVar2;
  undefined8 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  float fVar9;
  float fVar10;
  undefined1 auVar11 [64];
  float fVar12;
  undefined1 auVar13 [64];
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  undefined1 auVar18 [64];
  float fVar19;
  float local_res18;
  float fStackX_1c;
  
  fVar2 = param_6;
  uVar8 = (uint)param_4;
  auVar13 = ZEXT464((uint)((float)(param_3 & 0xffffffff) + (0.5f)));
  auVar11 = ZEXT464((uint)((float)(param_3 >> 0x20) + (0.5f)));
  fVar17 = (float)((uint)param_6 & 0xff) * (0.00048828125f) + (0.140000001f);
  uVar3 = FUN_140006b90(fVar17);
  uVar7 = 0;
  if (uVar8 != 0) {
    local_res18 = (float)uVar3;
    uVar6 = 0;
    auVar18 = ZEXT464((1f));
    fStackX_1c = (float)((ulonglong)uVar3 >> 0x20);
    param_6 = local_res18;
    fVar15 = (3f);
    fVar16 = (0.550000012f);
    fVar19 = (2f);
    do {
      uVar4 = ((uVar6 ^ (uint)fVar2) >> 0x10 ^ uVar6 ^ (uint)fVar2) * 0x45d9f3b;
      uVar4 = (uVar4 >> 0x10 ^ uVar4) * 0x45d9f3b;
      uVar5 = uVar4 >> 0x10 ^ uVar4;
      if (uVar8 < 2) {
        fVar9 = 0.0;
      }
      else {
        fVar9 = (float)uVar7 / (float)(uVar8 - 1);
      }
      auVar1 = vandps_avx(ZEXT416((uint)((fVar9 + fVar9) - auVar18._0_4_)),_DAT_140025060);
      fVar9 = (auVar18._0_4_ - auVar1._0_4_ * fVar16) * param_5 + fVar16;
      auVar1 = vunpcklps_avx(auVar13._0_16_,auVar11._0_16_);
      fVar14 = ((float)(uVar4 >> 0x14 & 1) * (0.150000006f) + (0.800000012f)) * fVar9;
      FUN_14001c1d0(param_1,param_2,auVar1._0_8_,param_4,fVar14,uVar5);
      fVar12 = auVar13._0_4_;
      fVar10 = auVar11._0_4_;
      if ((uVar5 & 3) == 0) {
        auVar1 = vpcmpeqd_avx(ZEXT416(uVar5 & 0x10),ZEXT416(0));
        auVar1 = vblendvps_avx(auVar18._0_16_,ZEXT416((-1f)),auVar1);
        auVar1 = vunpcklps_avx(ZEXT416((uint)(auVar1._0_4_ *
                                              (float)((uint)fStackX_1c ^ _DAT_140025070) * fVar9 *
                                              fVar16 + fVar12)),
                               ZEXT416((uint)(auVar1._0_4_ * param_6 * fVar9 * fVar16 + fVar10)));
        FUN_14001c1d0(param_1,param_2,auVar1._0_8_,param_4,fVar14 * fVar16,uVar5 ^ 0xa57e2d1b);
      }
      fVar17 = fVar17 + ((float)(uVar5 >> 8 & 7) - fVar15) * (0.00350000011f);
      uVar3 = FUN_140006b90(fVar17);
      local_res18 = (float)uVar3;
      param_6 = local_res18;
      fStackX_1c = (float)((ulonglong)uVar3 >> 0x20);
      fVar9 = (float)(uVar5 >> 0xf & 1) * (0.349999994f) + (0.949999988f);
      fVar10 = fVar9 * fStackX_1c + fVar10;
      auVar11 = ZEXT464((uint)fVar10);
      fVar12 = local_res18 * fVar9 + fVar12;
      auVar13 = ZEXT464((uint)fVar12);
      if (fVar12 < (12f)) {
        return;
      }
      if ((float)(uint)DAT_140029a88 - (4f) < fVar12) {
        return;
      }
      if (fVar10 < fVar19) {
        return;
      }
      if ((float)DAT_140029a88._4_4_ - fVar15 < fVar10) {
        return;
      }
      uVar7 = uVar7 + 1;
      uVar6 = uVar6 + 0x9e3779b9;
    } while (uVar7 < uVar8);
  }
  return;
}


// ===== FUN_140009290 @ 140009290 size=471

void FUN_140009290(uint *param_1,longlong param_2,undefined1 param_3,uint param_4,int param_5,
                  int param_6,uint param_7)

{
  ulonglong uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  if ((((0xe < (uint)DAT_140029a88) && (10 < DAT_140029a88._4_4_)) && (0xd < (uint)DAT_140029a88))
     && (6 < DAT_140029a88._4_4_)) {
    uVar9 = DAT_140029a88._4_4_ - 6;
    uVar4 = 0;
    uVar8 = (uint)DAT_140029a88 - 0xd;
    if (param_4 != 0) {
      uVar5 = 0;
      do {
        uVar3 = 0;
        uVar6 = 0;
        while( true ) {
          uVar2 = uVar5 ^ *param_1 ^ uVar6 ^ param_7;
          uVar2 = (uVar2 >> 0x10 ^ uVar2) * 0x45d9f3b;
          uVar2 = (uVar2 >> 0x10 ^ uVar2) * 0x45d9f3b;
          uVar7 = uVar2 >> 0x10 ^ uVar2;
          uVar1 = FUN_14001d610((longlong)param_1,param_2,
                                CONCAT44((uVar7 >> 0xc) % uVar9 + 3,uVar7 % uVar8 + 10),param_3,
                                (uVar2 >> 0x18) % ((param_6 - param_5) + 1U) + param_5,
                                uVar7 ^ param_7,1,1);
          if ((int)uVar1 != 0) break;
          uVar3 = uVar3 + 1;
          uVar6 = uVar6 + 0x85ebca6b;
          if (0x5f < uVar3) {
            return;
          }
        }
        uVar4 = uVar4 + 1;
        uVar5 = uVar5 + 0x9e3779b9;
      } while (uVar4 < param_4);
    }
  }
  return;
}


// ===== FUN_140009470 @ 140009470 size=580

undefined4 * FUN_140009470(undefined4 *param_1,int param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  
  param_1[3] = 0;
  *(undefined8 *)(param_1 + 4) = 0;
  *(undefined8 *)(param_1 + 6) = 0;
  param_1[8] = 1;
  param_1[9] = 1;
  *(undefined8 *)(param_1 + 10) = 0;
  *(undefined8 *)(param_1 + 0xc) = 0;
  *(undefined8 *)(param_1 + 0xe) = 0;
  *(undefined8 *)(param_1 + 0x10) = 0;
  *(undefined8 *)(param_1 + 0x12) = 0;
  *(undefined8 *)(param_1 + 0x14) = 0;
  *(undefined8 *)(param_1 + 0x16) = 0;
  *(undefined8 *)(param_1 + 0x18) = 0;
  *(undefined8 *)(param_1 + 0x1a) = 0;
  *(undefined8 *)(param_1 + 1) = 0x100000001;
  *param_1 = 1;
  if (param_2 == 0) {
    bVar2 = 4;
  }
  else if (param_2 == 1) {
    bVar2 = 8;
  }
  else if (param_2 == 2) {
    bVar2 = 1;
  }
  else if (param_2 == 3) {
    bVar2 = 2;
  }
  else {
    bVar2 = 0;
  }
  if (param_3 == 0) {
    bVar1 = 0x40;
  }
  else if (param_3 == 1) {
    bVar1 = 0x80;
  }
  else if (param_3 == 2) {
    bVar1 = 0x10;
  }
  else if (param_3 == 3) {
    bVar1 = 0x20;
  }
  else {
    bVar1 = 0;
  }
  *(undefined8 *)(param_1 + 10) = 0;
  *(byte *)(param_1 + 0xc) = bVar1 | bVar2;
  *(undefined **)(param_1 + 0x1c) = &DAT_1400eba70;
  if (param_2 == 0) {
    if (param_3 == 1) {
      *(undefined **)(param_1 + 4) = &DAT_1400ead00;
    }
    else {
      if (param_3 == 2) {
        *(undefined **)(param_1 + 4) = &DAT_1400ead20;
        return param_1;
      }
      if (param_3 == 3) {
        *(undefined **)(param_1 + 4) = &DAT_1400ead40;
        return param_1;
      }
    }
  }
  else if (param_2 == 1) {
    if (param_3 == 0) {
      *(undefined **)(param_1 + 4) = &DAT_1400ead60;
      return param_1;
    }
    if (param_3 == 2) {
      *(undefined **)(param_1 + 4) = &DAT_1400ead80;
      return param_1;
    }
    if (param_3 == 3) {
      *(undefined **)(param_1 + 4) = &DAT_1400eada0;
      return param_1;
    }
  }
  else if (param_2 == 2) {
    if (param_3 == 0) {
      *(undefined **)(param_1 + 4) = &DAT_1400eade0;
      return param_1;
    }
    if (param_3 == 1) {
      *(undefined **)(param_1 + 4) = &DAT_1400eae00;
      return param_1;
    }
    if (param_3 == 3) {
      *(undefined **)(param_1 + 4) = &DAT_1400eadc0;
      return param_1;
    }
  }
  else if (param_2 == 3) {
    if (param_3 == 0) {
      *(undefined **)(param_1 + 4) = &DAT_1400eace0;
      return param_1;
    }
    if (param_3 == 1) {
      *(undefined **)(param_1 + 4) = &DAT_1400eacc0;
      return param_1;
    }
    if (param_3 == 2) {
      *(undefined **)(param_1 + 4) = &DAT_1400eaca0;
      return param_1;
    }
  }
  return param_1;
}


// ===== FUN_1400096c0 @ 1400096c0 size=509

undefined4 * FUN_1400096c0(undefined4 *param_1,int param_2)

{
  undefined1 uVar1;
  code *pcVar2;
  undefined4 *puVar3;
  undefined *puVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  undefined8 local_28;
  undefined1 local_20;
  undefined8 local_18 [2];
  
  param_1[3] = 0;
  *(undefined8 *)(param_1 + 4) = 0;
  *(undefined8 *)(param_1 + 6) = 0;
  param_1[8] = 1;
  param_1[9] = 1;
  *(undefined8 *)(param_1 + 10) = 0;
  *(undefined8 *)(param_1 + 0xc) = 0;
  *(undefined8 *)(param_1 + 0xe) = 0;
  *(undefined8 *)(param_1 + 0x10) = 0;
  *(undefined8 *)(param_1 + 0x12) = 0;
  *(undefined8 *)(param_1 + 0x14) = 0;
  *(undefined8 *)(param_1 + 0x16) = 0;
  *(undefined8 *)(param_1 + 0x18) = 0;
  *(undefined8 *)(param_1 + 0x1a) = 0;
  *(undefined8 *)(param_1 + 1) = 0x200000003;
  *(undefined8 *)(param_1 + 0x1c) = 0;
  *param_1 = 4;
  if (param_2 == 0) {
    *(undefined **)(param_1 + 4) = &DAT_1400eb580;
    puVar4 = &DAT_1400eb5a0;
  }
  else if (param_2 == 1) {
    *(undefined **)(param_1 + 4) = &DAT_1400eb600;
    puVar4 = &DAT_1400eb620;
  }
  else if (param_2 == 2) {
    *(undefined **)(param_1 + 4) = &DAT_1400eb5c0;
    puVar4 = &DAT_1400eb5e0;
  }
  else {
    if (param_2 != 3) {
      pcVar2 = (code *)swi(3);
      puVar3 = (undefined4 *)(*pcVar2)();
      return puVar3;
    }
    *(undefined **)(param_1 + 4) = &DAT_1400eb640;
    puVar4 = &DAT_1400eb660;
  }
  *(undefined **)(param_1 + 6) = puVar4;
  param_1[8] = 10;
  local_28 = 0x100000000;
  local_20 = 2;
  puVar5 = FUN_14001a610(local_18,&local_28,*(undefined8 *)(param_1 + 1),param_2);
  local_28 = 0x100000001;
  local_20 = 2;
  uVar1 = *(undefined1 *)(puVar5 + 1);
  *(undefined8 *)(param_1 + 10) = *puVar5;
  *(undefined1 *)(param_1 + 0xc) = uVar1;
  puVar5 = FUN_14001a610(local_18,&local_28,*(undefined8 *)(param_1 + 1),param_2);
  local_28 = 0x100000002;
  local_20 = 2;
  uVar1 = *(undefined1 *)(puVar5 + 1);
  *(undefined8 *)((longlong)param_1 + 0x31) = *puVar5;
  *(undefined1 *)((longlong)param_1 + 0x39) = uVar1;
  puVar5 = FUN_14001a610(local_18,&local_28,*(undefined8 *)(param_1 + 1),param_2);
  local_28 = 1;
  local_20 = 0x10;
  uVar1 = *(undefined1 *)(puVar5 + 1);
  *(undefined8 *)((longlong)param_1 + 0x3a) = *puVar5;
  *(undefined1 *)((longlong)param_1 + 0x42) = uVar1;
  puVar5 = FUN_14001a610(local_18,&local_28,*(undefined8 *)(param_1 + 1),param_2);
  uVar1 = *(undefined1 *)(puVar5 + 1);
  *(undefined8 *)((longlong)param_1 + 0x43) = *puVar5;
  *(undefined1 *)((longlong)param_1 + 0x4b) = uVar1;
  uVar6 = *(undefined8 *)(param_1 + 1);
  if ((param_2 == 1) || (param_2 == 3)) {
    uVar6 = CONCAT44((int)uVar6,(int)((ulonglong)uVar6 >> 0x20));
  }
  *(undefined **)(param_1 + 0x1c) = &DAT_1400ebb00;
  *(undefined8 *)(param_1 + 1) = uVar6;
  return param_1;
}


// ===== FUN_1400098c0 @ 1400098c0 size=201

longlong * FUN_1400098c0(longlong *param_1,longlong *param_2,DWORD param_3)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong lVar3;
  DWORD DVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  
  uVar1 = param_2[2];
  lVar2 = *param_2;
  uVar5 = 0;
  uVar6 = uVar1 + 0x10ffe & 0xfffffffffffff000;
  if (uVar6 != (uVar1 & 0xfffffffffffff000)) {
    do {
      *(undefined1 *)(uVar5 + lVar2 + uVar1) = 0;
      uVar5 = uVar5 + 0x1000;
    } while (uVar5 < uVar6 - (uVar1 & 0xfffffffffffff000));
  }
  DVar4 = FormatMessageA(0x1000,(LPCVOID)0x0,param_3,0x800,(LPSTR)(param_2[2] + *param_2),0xffff,
                         (va_list *)0x0);
  if (DVar4 == 0) {
    param_1[1] = 0;
    *param_1 = (longlong)&DAT_140024975;
    return param_1;
  }
  lVar2 = *param_2;
  lVar3 = param_2[2];
  param_2[2] = param_2[2] + (ulonglong)DVar4;
  param_1[1] = (ulonglong)DVar4;
  *param_1 = lVar2 + lVar3;
  return param_1;
}


// ===== FUN_140009990 @ 140009990 size=113

undefined8 FUN_140009990(longlong param_1,uint param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = (uint)param_1;
  if (uVar3 < (uint)DAT_140029a88) {
    uVar4 = (uint)((ulonglong)param_1 >> 0x20);
    if (((((uVar4 < DAT_140029a88._4_4_) && (param_2 < DAT_1400299a8)) && (-1 < (int)uVar3)) &&
        ((-1 < param_1 && (-1 < (int)param_2)))) && (uVar4 < DAT_140029a88._4_4_)) {
      uVar3 = *(uint *)(DAT_140029a98 +
                       (ulonglong)
                       ((param_2 * DAT_140029a88._4_4_ + uVar4) * (uint)DAT_140029a88 + uVar3) * 4);
      if ((uVar3 != 0) && (uVar3 < DAT_14002a870)) {
        if ((ulonglong)DAT_14002a870 <= (ulonglong)uVar3) {
          pcVar1 = (code *)swi(3);
          uVar2 = (*pcVar1)();
          return uVar2;
        }
        return *(undefined8 *)(DAT_14002a868 + (ulonglong)uVar3 * 8);
      }
    }
  }
  return 0;
}


// ===== FUN_140009a10 @ 140009a10 size=76

undefined8 FUN_140009a10(void)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  tagPOINT local_res8 [4];
  
  local_res8[0].x = 0;
  local_res8[0].y = 0;
  GetCursorPos(local_res8);
  ScreenToClient(DAT_140029680,local_res8);
  auVar2._0_4_ = (float)local_res8[0].x;
  auVar2._4_8_ = SUB128(ZEXT812(0),4);
  auVar2._12_4_ = 0;
  auVar1._0_4_ = (float)local_res8[0].y;
  auVar1._4_8_ = SUB128(ZEXT812(0),4);
  auVar1._12_4_ = 0;
  auVar1 = vunpcklps_avx(auVar2,auVar1);
  return auVar1._0_8_;
}


// ===== FUN_140009a60 @ 140009a60 size=1145

undefined8 * FUN_140009a60(undefined8 *param_1,undefined4 param_2,int param_3)

{
  undefined8 uVar1;
  undefined1 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined *puVar16;
  undefined8 *puVar17;
  undefined8 local_a8;
  undefined1 local_a0;
  undefined4 local_98;
  undefined4 uStack_94;
  undefined8 uStack_90;
  undefined *puStack_88;
  undefined *puStack_80;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined8 uStack_70;
  byte bStack_68;
  undefined7 uStack_67;
  undefined1 uStack_60;
  undefined1 uStack_5f;
  undefined6 uStack_5e;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 local_20 [3];
  
  *(undefined4 *)((longlong)param_1 + 4) = 1;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[1] = 1;
  *(undefined4 *)(param_1 + 4) = 1;
  *(undefined4 *)((longlong)param_1 + 0x24) = 1;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  *(undefined4 *)param_1 = param_2;
  param_1[0xe] = 0;
  switch(param_2) {
  case 2:
    if (param_3 == 0) {
LAB_140009b5a:
      bStack_68 = 0x12;
    }
    else if (param_3 == 1) {
      bStack_68 = 0x84;
    }
    else if (param_3 == 2) {
      bStack_68 = 0x21;
    }
    else {
      if (param_3 != 3) goto LAB_140009b5a;
      bStack_68 = 0x48;
    }
    *param_1 = 0x100000002;
    param_1[1] = 1;
    param_1[2] = &DAT_1400eb680;
    param_1[3] = &DAT_1400eb6a0;
    param_1[4] = 0x100000006;
    param_1[5] = 0;
    param_1[6] = (ulonglong)bStack_68;
    param_1[7] = 0;
    param_1[8] = 0;
    param_1[9] = 0;
    param_1[10] = 0;
    param_1[0xb] = 0;
    param_1[0xc] = 0;
    param_1[0xd] = 0;
    param_1[0xe] = &DAT_1400ebaa0;
    break;
  case 3:
    uStack_90 = 2;
    uStack_74 = 1;
    local_30 = 0;
    local_98 = 3;
    uStack_94 = 2;
    puStack_88 = (undefined *)0x0;
    puStack_80 = (undefined *)0x0;
    uStack_70 = 0;
    bStack_68 = 0;
    uStack_67 = 0;
    uStack_60 = 0;
    uStack_5f = 0;
    uStack_5e = 0;
    uStack_58 = 0;
    uStack_50 = 0;
    uStack_48 = 0;
    uStack_40 = 0;
    uStack_38 = 0;
    if (param_3 == 0) {
      puStack_88 = &DAT_1400eb220;
      puStack_80 = &DAT_1400eb240;
    }
    else if (param_3 == 1) {
      puStack_88 = &DAT_1400eb2a0;
      puStack_80 = &DAT_1400eb2c0;
    }
    else if (param_3 == 2) {
      puStack_88 = &DAT_1400eb260;
      puStack_80 = &DAT_1400eb280;
    }
    else if (param_3 == 3) {
      puStack_88 = &DAT_1400eb2e0;
      puStack_80 = &DAT_1400eb300;
    }
    local_78 = 8;
    local_a8 = 0x100000000;
    local_a0 = 2;
    puVar17 = FUN_14001a610(local_20,&local_a8,0x200000002,param_3);
    local_a8 = 0x100000001;
    local_a0 = 0x20;
    uStack_70 = *puVar17;
    bStack_68 = *(byte *)(puVar17 + 1);
    puVar17 = FUN_14001a610(local_20,&local_a8,0x200000002,param_3);
    uVar2 = *(undefined1 *)(puVar17 + 1);
    uStack_67 = (undefined7)*puVar17;
    uStack_60 = (undefined1)((ulonglong)*puVar17 >> 0x38);
    *param_1 = CONCAT44(uStack_94,local_98);
    param_1[1] = uStack_90;
    param_1[2] = puStack_88;
    param_1[3] = puStack_80;
    param_1[4] = CONCAT44(uStack_74,local_78);
    param_1[5] = uStack_70;
    param_1[6] = CONCAT71(uStack_67,bStack_68);
    param_1[7] = CONCAT62(uStack_5e,CONCAT11(uVar2,uStack_60));
    param_1[8] = uStack_58;
    param_1[9] = uStack_50;
    param_1[10] = uStack_48;
    param_1[0xb] = uStack_40;
    param_1[0xc] = uStack_38;
    param_1[0xd] = local_30;
    param_1[0xe] = &DAT_1400ebad0;
    break;
  case 4:
    puVar17 = (undefined8 *)FUN_1400096c0(&local_98,param_3);
    uVar5 = puVar17[1];
    uVar6 = puVar17[2];
    uVar7 = puVar17[3];
    uVar8 = puVar17[4];
    uVar9 = puVar17[5];
    uVar10 = puVar17[6];
    uVar11 = puVar17[7];
    uVar12 = puVar17[8];
    uVar13 = puVar17[9];
    uVar14 = puVar17[10];
    uVar15 = puVar17[0xb];
    uVar3 = puVar17[0xc];
    uVar4 = puVar17[0xd];
    uVar1 = puVar17[0xe];
    *param_1 = *puVar17;
    param_1[1] = uVar5;
    param_1[2] = uVar6;
    param_1[3] = uVar7;
    param_1[4] = uVar8;
    param_1[5] = uVar9;
    param_1[6] = uVar10;
    param_1[7] = uVar11;
    param_1[8] = uVar12;
    param_1[9] = uVar13;
    param_1[10] = uVar14;
    param_1[0xb] = uVar15;
    param_1[0xc] = uVar3;
    param_1[0xd] = uVar4;
    param_1[0xe] = uVar1;
    break;
  case 5:
    *(undefined8 *)((longlong)param_1 + 4) = 0x100000001;
    puVar16 = &DAT_1400eabe0;
    goto LAB_140009d61;
  case 6:
    *(undefined8 *)((longlong)param_1 + 4) = 0x100000001;
    puVar16 = &DAT_1400eac00;
LAB_140009d61:
    param_1[2] = puVar16;
    param_1[0xe] = &DAT_1400eba70;
    *(undefined4 *)(param_1 + 4) = 1;
    param_1[5] = 0;
    *(undefined1 *)(param_1 + 6) = 0xff;
    break;
  case 7:
    *(undefined8 *)((longlong)param_1 + 4) = 0x100000001;
    puVar16 = &DAT_1400eae40;
    goto LAB_140009dc0;
  case 8:
    *(undefined8 *)((longlong)param_1 + 4) = 0x100000001;
    puVar16 = &DAT_1400eae20;
LAB_140009dc0:
    param_1[2] = puVar16;
    param_1[0xe] = &DAT_1400eba70;
    *(undefined4 *)(param_1 + 4) = 1;
    param_1[5] = 0;
    *(undefined1 *)(param_1 + 6) = 0xf;
    break;
  case 9:
    *(undefined8 *)((longlong)param_1 + 4) = 0x100000001;
    if (param_3 == 0) {
      puVar16 = &DAT_1400eae80;
LAB_140009e4f:
      param_1[2] = puVar16;
    }
    else {
      if (param_3 == 1) {
        puVar16 = &DAT_1400eae60;
        goto LAB_140009e4f;
      }
      if (param_3 == 2) {
        puVar16 = &DAT_1400eaec0;
        goto LAB_140009e4f;
      }
      if (param_3 == 3) {
        puVar16 = &DAT_1400eaea0;
        goto LAB_140009e4f;
      }
    }
    local_a8 = 0;
    param_1[0xe] = &DAT_1400eba70;
    *(undefined4 *)(param_1 + 4) = 1;
    local_a0 = 0x20;
    puVar17 = FUN_14001a610(local_20,&local_a8,0x100000001,param_3);
    uVar2 = *(undefined1 *)(puVar17 + 1);
    param_1[5] = *puVar17;
    *(undefined1 *)(param_1 + 6) = uVar2;
    break;
  case 10:
    *(undefined8 *)((longlong)param_1 + 4) = 0x100000001;
    param_1[0xe] = &DAT_1400eba70;
    param_1[2] = &DAT_1400eb6c0;
  }
  return param_1;
}


// ===== FUN_140009f00 @ 140009f00 size=123

undefined * FUN_140009f00(undefined1 param_1)

{
  switch(param_1) {
  case 10:
    return &DAT_1400eb790;
  case 0xb:
    return &DAT_1400eb7f0;
  case 0xc:
    return &DAT_1400eb720;
  case 0xd:
    return &DAT_1400eb730;
  case 0xe:
    return &DAT_1400eb8a0;
  default:
    return (undefined *)0x0;
  case 0x10:
    return &DAT_1400eb770;
  case 0x11:
    return &DAT_1400eb7d0;
  case 0x12:
    return &DAT_1400eb860;
  case 0x13:
    return &DAT_1400eb760;
  case 0x14:
    return &DAT_1400eb810;
  case 0x15:
    return &DAT_1400eb820;
  }
}


// ===== FUN_140009fb0 @ 140009fb0 size=46

ulonglong FUN_140009fb0(undefined8 param_1)

{
  uint uVar1;
  
  if (((uint)param_1 < (uint)DAT_140029a88) &&
     (uVar1 = (uint)((ulonglong)param_1 >> 0x20), uVar1 < DAT_140029a88._4_4_)) {
    return (ulonglong)
           *(byte *)((ulonglong)(uVar1 * (uint)DAT_140029a88 + (uint)param_1) + DAT_140029a90);
  }
  return CONCAT44(DAT_140029a88._4_4_,(uint)DAT_140029a88) & 0xffffffffffffff00;
}


// ===== FUN_140009fe0 @ 140009fe0 size=390

undefined8 FUN_140009fe0(undefined8 param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  undefined4 local_res10;
  undefined4 uStackX_14;
  
  if (DAT_1400298ac != 0) {
    iVar4 = 1;
    if (1 < DAT_140029044 * DAT_140029040) {
      iVar4 = DAT_140029044 * DAT_140029040;
    }
    iVar9 = 0x60;
    if (0x60 < iVar4 + 0x18) {
      iVar9 = iVar4 + 0x18;
    }
    uVar1 = (DAT_1400296d0 + (DAT_140029048 + DAT_14002904c) * -2) / iVar9;
    uVar8 = 1;
    if (1 < (int)uVar1) {
      uVar8 = uVar1;
    }
    if ((int)uVar8 < 1) {
      uVar8 = 1;
    }
    if (0xc < (int)uVar8) {
      uVar8 = 0xc;
    }
    local_res10 = (float)param_1;
    iVar4 = (int)local_res10;
    uVar2 = (uint)((int)(0xc % (ulonglong)uVar8) != 0) + (int)(0xc / (ulonglong)uVar8);
    uVar1 = 1;
    if (1 < uVar2) {
      uVar1 = uVar2;
    }
    iVar6 = uVar8 * iVar9 + DAT_14002904c * 2;
    iVar7 = (DAT_1400296d0 - iVar6) - DAT_140029048;
    uStackX_14 = (float)((ulonglong)param_1 >> 0x20);
    iVar3 = (int)uStackX_14;
    iVar5 = 0;
    if (0 < iVar7) {
      iVar5 = iVar7;
    }
    if ((((iVar5 <= iVar4) && (iVar4 < iVar5 + iVar6)) && (DAT_140029048 <= iVar3)) &&
       (iVar3 < (int)(DAT_140029048 + uVar1 * iVar9 + DAT_14002904c * 2))) {
      iVar3 = (iVar3 - DAT_140029048) - DAT_14002904c;
      iVar4 = (iVar4 - iVar5) - DAT_14002904c;
      if ((-1 < iVar4) && (-1 < iVar3)) {
        iVar4 = iVar4 / iVar9;
        iVar3 = iVar3 / iVar9;
        if (((-1 < iVar4) && ((iVar4 < (int)uVar8 && (-1 < iVar3)))) && (iVar3 < (int)uVar1)) {
          uVar8 = uVar8 * iVar3 + iVar4;
          if (((int)uVar8 < 0) || (0xb < uVar8)) {
            uVar8 = 0xffffffff;
          }
          if (-1 < (int)uVar8) {
            FUN_14001b770(uVar8);
          }
        }
      }
      DAT_1400296fc = 0;
      DAT_1400298a8 = 0;
      return 1;
    }
  }
  return 0;
}


// ===== FUN_14000a170 @ 14000a170 size=1113

void FUN_14000a170(longlong param_1)

{
  ulonglong *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  code *pcVar4;
  char cVar5;
  undefined1 uVar6;
  int iVar7;
  uint uVar8;
  undefined8 uVar9;
  undefined1 (*pauVar10) [16];
  ulonglong uVar11;
  uint uVar12;
  int *piVar13;
  uint uVar14;
  longlong lVar15;
  ulonglong uVar16;
  uint uVar17;
  uint uVar19;
  undefined1 auVar18 [16];
  undefined8 local_res8;
  undefined8 local_res20;
  undefined8 local_a8;
  undefined1 local_98 [16];
  undefined1 local_88 [16];
  undefined1 local_78 [8];
  char cStack_70;
  uint uStack_6c;
  undefined8 local_68;
  
  if ((ulonglong)DAT_1400291e8 <= (ulonglong)*(uint *)(param_1 + 4)) {
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  lVar15 = (ulonglong)*(uint *)(param_1 + 4) * 0x2080 + DAT_1400291e0;
  if (*(char *)(lVar15 + 0x38) == '\x06') {
    if ((*(uint *)(lVar15 + 0x60) != 0) &&
       (uVar9 = FUN_14001dc40(*(longlong *)(lVar15 + 0x39),*(char *)(lVar15 + 0x5c),
                              *(uint *)(lVar15 + 0x60)), (int)uVar9 != 0)) {
      *(undefined1 *)(lVar15 + 0x5c) = 0xc;
      *(undefined4 *)(lVar15 + 0x60) = 0;
      pauVar10 = FUN_140011e40(&local_98,*(ulonglong *)(lVar15 + 0x39));
      *(undefined8 *)(lVar15 + 0x39) = *(undefined8 *)*pauVar10;
      *(undefined8 *)(lVar15 + 8) = 0;
      *(undefined1 *)(lVar15 + 0x34) = 1;
      return;
    }
    if (*(int *)(lVar15 + 0x60) != 0) {
      return;
    }
    uVar11 = FUN_1400086a0(*(undefined8 *)(lVar15 + 0x39));
    if ((int)uVar11 == -1) {
      return;
    }
    uVar11 = (ulonglong)*(byte *)(lVar15 + 0x49);
    if (DAT_140029a30 <= *(byte *)(lVar15 + 0x49)) {
      return;
    }
    if (DAT_140029a30 <= uVar11) {
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    if (*(int *)(DAT_140029a28 + uVar11 * 4) == 0) {
      return;
    }
    if (uVar11 < DAT_140029a30) {
      piVar13 = (int *)(DAT_140029a28 + uVar11 * 4);
      *piVar13 = *piVar13 + -1;
      *(undefined1 *)(lVar15 + 0x5c) = *(undefined1 *)(lVar15 + 0x49);
      *(undefined8 *)(lVar15 + 0x39) = *(undefined8 *)(lVar15 + 0x41);
      *(undefined8 *)(lVar15 + 8) = 0;
      *(undefined4 *)(lVar15 + 0x60) = 1;
      *(undefined1 *)(lVar15 + 0x34) = 1;
      return;
    }
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  uVar16 = 0;
  uVar11 = *(ulonglong *)(param_1 + 9);
  uVar8 = 0;
  puVar1 = (ulonglong *)(param_1 + 9);
  if (DAT_1400eaa18 != 0) {
    local_res8._4_4_ = (int)(uVar11 >> 0x20);
    do {
      uVar17 = (uint)uVar16;
      local_res8 = uVar11;
      if (DAT_1400eaa18 <= uVar16) {
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      if ((*(int *)(DAT_1400eaa10 + uVar16 * 0x18) == (int)uVar11) &&
         (*(int *)(DAT_1400eaa10 + 4 + uVar16 * 0x18) == local_res8._4_4_)) {
        if (-1 < (int)uVar17) {
          if (DAT_1400eaa18 <= uVar16) {
            pcVar4 = (code *)swi(3);
            (*pcVar4)();
            return;
          }
          puVar2 = (undefined4 *)(DAT_1400eaa10 + uVar16 * 0x18);
          local_78._0_4_ = *puVar2;
          local_78._4_4_ = puVar2[1];
          _cStack_70 = puVar2[2];
          uVar19 = puVar2[3];
          local_68 = *(undefined8 *)(DAT_1400eaa10 + 0x10 + uVar16 * 0x18);
          uStack_6c = uVar19;
          pauVar10 = FUN_140011e40(&local_88,*puVar1);
          auVar18 = *pauVar10;
          local_a8 = auVar18._0_8_;
          *(undefined8 *)(lVar15 + 0x10) = local_a8;
          uVar3 = vextractps_avx(auVar18,2);
          *(undefined4 *)(lVar15 + 0x18) = uVar3;
          uVar3 = vextractps_avx(auVar18,3);
          *(undefined4 *)(lVar15 + 0x1c) = uVar3;
          *(undefined8 *)(lVar15 + 0x2064) = 0;
          *(undefined8 *)(lVar15 + 0x206c) = 0;
          *(undefined4 *)(lVar15 + 0x2074) = 0;
          if (local_68._4_1_ != '\x01') {
            if (*(int *)(lVar15 + 0x60) == 0) {
              *(char *)(lVar15 + 0x5c) = cStack_70;
              *(uint *)(lVar15 + 0x60) = uStack_6c;
            }
            uVar9 = FUN_14001dc40(*puVar1,cStack_70,uStack_6c);
            if ((int)uVar9 != 0) {
              *(undefined1 *)(lVar15 + 0x5c) = 0xc;
              *(undefined4 *)(lVar15 + 0x60) = 0;
              FUN_140014a30(uVar17);
              return;
            }
            *(undefined1 *)(lVar15 + 0x34) = 3;
            local_res20 = 0;
            *(undefined8 *)(lVar15 + 8) = 0;
            FUN_140014a30(uVar17);
            return;
          }
          uVar11 = *puVar1;
          if ((((uVar19 != 0) && (uVar14 = (uint)uVar11, uVar14 < (uint)DAT_140029a88)) &&
              (uVar12 = (uint)(uVar11 >> 0x20), uVar12 < DAT_140029a88._4_4_)) &&
             (((DAT_1400299a8 != 0 && (-1 < (int)uVar14)) && (-1 < (longlong)uVar11)))) {
            uVar14 = *(uint *)(DAT_140029a98 +
                              (ulonglong)(uVar12 * (uint)DAT_140029a88 + uVar14) * 4);
            if ((uVar14 != 0) && (uVar14 < DAT_14002a870)) {
              if ((ulonglong)DAT_14002a870 <= (ulonglong)uVar14) {
                pcVar4 = (code *)swi(3);
                (*pcVar4)();
                return;
              }
              piVar13 = *(int **)(DAT_14002a868 + (ulonglong)uVar14 * 8);
              if (((piVar13 != (int *)0x0) && (*(longlong *)(piVar13 + 2) != 0)) && (*piVar13 == 1))
              {
                if (piVar13[0x16] == 0) {
                  piVar13 = piVar13 + 0xf;
                }
                else {
                  piVar13 = piVar13 + 0x15;
                }
                uVar14 = piVar13[1];
                if (uVar14 != 0) {
                  uVar8 = uVar14;
                  if (uVar19 < uVar14) {
                    uVar8 = uVar19;
                  }
                  piVar13[1] = uVar14 - uVar8;
                  uVar6 = (undefined1)*piVar13;
                  goto LAB_14000a448;
                }
              }
            }
          }
          uVar6 = 0xc;
LAB_14000a448:
          *(undefined1 *)(lVar15 + 0x5c) = uVar6;
          *(uint *)(lVar15 + 0x60) = uVar8;
          FUN_140014a30(uVar17);
          FUN_14001df40(0x1400291d0,*puVar1);
          return;
        }
        break;
      }
      uVar16 = (ulonglong)(uVar17 + 1);
    } while (uVar17 + 1 < DAT_1400eaa18);
  }
  local_res8 = uVar11 & 0xffffffffffffff00;
  iVar7 = FUN_140006380(uVar11,(undefined1 *)&local_res8);
  if (iVar7 == 0) {
    FUN_14001df40(0x1400291d0,*puVar1);
    *(undefined1 *)(lVar15 + 0x5c) = 0xc;
    *(undefined4 *)(lVar15 + 0x60) = 0;
    return;
  }
  uVar8 = FUN_14001c7a0(*puVar1);
  pauVar10 = FUN_140011e40((undefined1 (*) [16])local_78,*(ulonglong *)(param_1 + 9));
  auVar18 = *pauVar10;
  cVar5 = (char)local_res8;
  local_a8 = auVar18._0_8_;
  if (((*(char *)(param_1 + 8) == '\x02') || (*(char *)(param_1 + 8) == '\x03')) &&
     (*(int *)(lVar15 + 0x54) == 0)) {
    uVar9 = FUN_14001da50(*puVar1,(char)local_res8,1);
    if ((int)uVar9 != 0) {
      *(undefined1 *)(lVar15 + 0x5c) = 0xc;
      *(undefined4 *)(lVar15 + 0x60) = 0;
      goto LAB_14000a57b;
    }
    *(undefined8 *)(lVar15 + 0x10) = local_a8;
    *(undefined8 *)(lVar15 + 8) = 0;
    *(char *)(lVar15 + 0x5c) = cVar5;
    *(undefined1 *)(lVar15 + 0x34) = 3;
  }
  else {
    *(undefined8 *)(lVar15 + 0x10) = local_a8;
    *(char *)(lVar15 + 0x5c) = (char)local_res8;
  }
  uVar3 = vextractps_avx(auVar18,3);
  *(undefined4 *)(lVar15 + 0x1c) = uVar3;
  uVar3 = vextractps_avx(auVar18,2);
  *(undefined4 *)(lVar15 + 0x18) = uVar3;
  *(undefined8 *)(lVar15 + 0x2064) = 0;
  *(undefined8 *)(lVar15 + 0x206c) = 0;
  *(undefined4 *)(lVar15 + 0x2074) = 0;
  *(undefined4 *)(lVar15 + 0x60) = 1;
LAB_14000a57b:
  if (uVar8 == 0) {
    FUN_14001df40(0x1400291d0,*(undefined8 *)(param_1 + 9));
  }
  return;
}


// ===== FUN_14000a5d0 @ 14000a5d0 size=125

undefined8 FUN_14000a5d0(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  longlong *plVar5;
  int iVar6;
  int iStackX_c;
  
  plVar1 = (longlong *)((longlong)DAT_14002a9d0 + (ulonglong)DAT_14002a9d8 * 0xc);
  if (DAT_14002a9d0 != plVar1) {
    iStackX_c = (int)((ulonglong)param_1 >> 0x20);
    plVar5 = DAT_14002a9d0;
    do {
      lVar2 = *plVar5;
      iVar3 = (int)((ulonglong)lVar2 >> 0x20);
      if ((param_1 == lVar2) ||
         (((int)plVar5[1] != 0 &&
          ((iVar6 = iVar3 + 1, param_1 == CONCAT44(iVar6,(int)lVar2) ||
           ((iVar4 = (int)lVar2 + 1, (int)param_1 == iVar4 &&
            ((iStackX_c == iVar3 || (param_1 == CONCAT44(iVar6,iVar4))))))))))) {
        return 1;
      }
      plVar5 = (longlong *)((longlong)plVar5 + 0xc);
    } while (plVar5 != plVar1);
  }
  return 0;
}


// ===== FUN_14000a650 @ 14000a650 size=519

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_14000a650(void)

{
  ulonglong uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  ulonglong uVar10;
  int iVar11;
  tagPOINT local_res8;
  
  if (DAT_140029af0 != 0) {
    iVar2 = 1;
    if (1 < DAT_140029124 * DAT_140029120) {
      iVar2 = DAT_140029124 * DAT_140029120;
    }
    if (DAT_140029af4 == 0) {
      uVar3 = (DAT_1400296d0 + (DAT_14002912c + DAT_140029130) * -2) / iVar2;
      uVar6 = 1;
      if (1 < (int)uVar3) {
        uVar6 = uVar3;
      }
    }
    else {
      uVar6 = DAT_140029ae0;
      if ((int)DAT_140029ae0 < 1) {
        uVar6 = 1;
      }
      if (4 < (int)uVar6) {
        uVar6 = 4;
      }
    }
    if (DAT_140029af4 == 0) {
      uVar10 = 1;
      uVar1 = (longlong)(DAT_1400296d0 + (DAT_14002912c + DAT_140029130) * -2) / (longlong)iVar2;
      if (1 < (int)uVar1) {
        uVar10 = uVar1 & 0xffffffff;
      }
    }
    else {
      uVar3 = DAT_140029ae0;
      if ((int)DAT_140029ae0 < 1) {
        uVar3 = 1;
      }
      uVar10 = (ulonglong)uVar3;
      if (4 < (int)uVar3) {
        uVar10 = 4;
      }
    }
    iVar5 = (uint)((int)((ulonglong)DAT_140029ae0 % uVar10) != 0) + (int)(DAT_140029ae0 / uVar10);
    iVar7 = 1;
    if (1 < iVar5) {
      iVar7 = iVar5;
    }
    iVar9 = iVar2 * uVar6 + DAT_140029130 * 2;
    iVar11 = iVar7 * iVar2 + DAT_140029130 * 2;
    iVar5 = DAT_14002912c;
    iVar4 = DAT_14002912c;
    if (DAT_140029af4 != 0) {
      iVar8 = DAT_1400296d0 - iVar9;
      iVar5 = DAT_140029af8 - iVar9 / 2;
      iVar4 = 0;
      if (0 < iVar8) {
        iVar4 = iVar8;
      }
      if (iVar5 < 0) {
        iVar5 = 0;
      }
      if (iVar4 < iVar5) {
        iVar5 = iVar4;
      }
      iVar4 = DAT_1400296d4 - iVar11;
      iVar9 = 0;
      if (0 < iVar4) {
        iVar9 = iVar4;
      }
      iVar4 = (DAT_140029afc - iVar11) - _DAT_140029138;
      if (iVar4 < 0) {
        iVar4 = 0;
      }
      if (iVar9 < iVar4) {
        iVar4 = iVar9;
      }
    }
    local_res8.x = 0;
    local_res8.y = 0;
    iVar5 = iVar5 + DAT_140029130;
    iVar4 = iVar4 + DAT_140029130;
    GetCursorPos(&local_res8);
    ScreenToClient(DAT_140029680,&local_res8);
    iVar5 = (int)(float)local_res8.x - iVar5;
    iVar4 = (int)(float)local_res8.y - iVar4;
    if ((((-1 < iVar5) && (-1 < iVar4)) && (iVar5 < (int)(iVar2 * uVar6))) &&
       (iVar4 < iVar7 * iVar2)) {
      uVar6 = (iVar4 / iVar2) * uVar6 + iVar5 / iVar2;
      if (((int)uVar6 < 0) || (DAT_140029ae0 <= uVar6)) {
        uVar6 = 0xffffffff;
      }
      return uVar6;
    }
  }
  return 0xffffffff;
}


// ===== FUN_14000a860 @ 14000a860 size=2601

/* WARNING: Removing unreachable block (ram,0x00014000b248) */

longlong FUN_14000a860(longlong *param_1,ulonglong *param_2,undefined8 *param_3,undefined4 *param_4,
                      uint param_5,undefined2 *param_6,undefined2 *param_7)

{
  ushort uVar1;
  code *pcVar2;
  sbyte sVar3;
  ulonglong uVar4;
  uint uVar5;
  undefined2 *puVar6;
  longlong lVar7;
  uint uVar8;
  int iVar9;
  ulonglong uVar10;
  uint uVar11;
  ulonglong uVar12;
  uint uVar13;
  ulonglong uVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  ushort *puVar18;
  ulonglong *puVar19;
  ulonglong uVar20;
  ulonglong uVar21;
  ulonglong uVar22;
  int iVar23;
  undefined1 *puVar24;
  ulonglong local_bb8;
  ulonglong *local_bb0;
  uint local_ba8;
  undefined2 *local_ba0;
  ushort *local_b98;
  uint local_b88 [32];
  int local_b08 [32];
  uint local_a88 [32];
  int local_a08 [32];
  undefined2 local_988 [592];
  undefined2 local_4e8 [596];
  
  uVar20 = 0;
  uVar21 = 0;
  uVar8 = 8 - ((uint)param_2 & 3);
  if (uVar8 != 0) {
    uVar12 = (ulonglong)uVar8;
    do {
      uVar14 = *param_2;
      param_2 = (ulonglong *)((longlong)param_2 + 1);
      uVar21 = uVar21 | (ulonglong)(byte)uVar14 << (uVar20 & 0x3f);
      uVar20 = (ulonglong)((int)uVar20 + 8);
      uVar12 = uVar12 - 1;
    } while (uVar12 != 0);
  }
  lVar7 = param_1[2];
  uVar14 = 0;
  uVar12 = (ulonglong)param_5;
  param_5 = 0;
  local_b88[0] = 0;
  local_b88[1] = 0;
  param_1[2] = lVar7 + uVar12;
  local_b88[2] = 0;
  local_b88[3] = 0;
  local_b88[4] = 0;
  local_b88[5] = 0;
  local_b88[6] = 0;
  local_b88[7] = 0;
  local_b88[8] = 1;
  local_b88[9] = 1;
  local_b88[10] = 1;
  local_b88[0xb] = 1;
  local_b88[0xc] = 2;
  local_b88[0xd] = 2;
  local_b88[0xe] = 2;
  local_b88[0xf] = 2;
  local_b88[0x10] = 3;
  local_b88[0x11] = 3;
  local_b88[0x12] = 3;
  local_b88[0x13] = 3;
  local_b88[0x14] = 4;
  local_b88[0x15] = 4;
  local_b88[0x16] = 4;
  local_b88[0x17] = 4;
  local_b88[0x18] = 5;
  local_b88[0x19] = 5;
  local_b88[0x1a] = 5;
  local_b88[0x1b] = 5;
  local_b88[0x1c] = 0;
  local_b08[0] = 3;
  local_b08[1] = 4;
  local_b08[2] = 5;
  local_b08[3] = 6;
  local_b08[4] = 7;
  local_b08[5] = 8;
  local_b08[6] = 9;
  local_b08[7] = 10;
  local_b08[8] = 0xb;
  local_b08[9] = 0xd;
  local_b08[10] = 0xf;
  local_b08[0xb] = 0x11;
  local_b08[0xc] = 0x13;
  local_b08[0xd] = 0x17;
  local_b08[0xe] = 0x1b;
  local_b08[0xf] = 0x1f;
  local_b08[0x10] = 0x23;
  local_b08[0x11] = 0x2b;
  local_b08[0x12] = 0x33;
  local_b08[0x13] = 0x3b;
  local_b08[0x14] = 0x43;
  local_b08[0x15] = 0x53;
  local_b08[0x16] = 99;
  local_b08[0x17] = 0x73;
  local_b08[0x18] = 0x83;
  local_b08[0x19] = 0xa3;
  local_b08[0x1a] = 0xc3;
  local_b08[0x1b] = 0xe3;
  local_b08[0x1c] = 0x102;
  local_a88[0] = 0;
  local_a88[1] = 0;
  local_a88[2] = 0;
  local_a88[3] = 0;
  local_a88[4] = 1;
  local_a88[5] = 1;
  local_a88[6] = 2;
  local_a88[7] = 2;
  local_a88[8] = 3;
  local_a88[9] = 3;
  local_a88[10] = 4;
  local_a88[0xb] = 4;
  local_a88[0xc] = 5;
  local_a88[0xd] = 5;
  local_a88[0xe] = 6;
  local_a88[0xf] = 6;
  local_a88[0x10] = 7;
  local_a88[0x11] = 7;
  local_a88[0x12] = 8;
  local_a88[0x13] = 8;
  local_a88[0x14] = 9;
  local_a88[0x15] = 9;
  local_a88[0x16] = 10;
  local_a88[0x17] = 10;
  local_a88[0x18] = 0xb;
  local_a88[0x19] = 0xb;
  local_a88[0x1a] = 0xc;
  local_a88[0x1b] = 0xc;
  local_a88[0x1c] = 0xd;
  local_a88[0x1d] = 0xd;
  local_a08[0] = 1;
  local_a08[1] = 2;
  local_a08[2] = 3;
  local_a08[3] = 4;
  local_a08[4] = 5;
  local_a08[5] = 7;
  local_a08[6] = 9;
  local_a08[7] = 0xd;
  local_a08[8] = 0x11;
  local_a08[9] = 0x19;
  local_a08[10] = 0x21;
  local_a08[0xb] = 0x31;
  local_a08[0xc] = 0x41;
  local_a08[0xd] = 0x61;
  local_a08[0xe] = 0x81;
  local_a08[0xf] = 0xc1;
  local_a08[0x10] = 0x101;
  local_a08[0x11] = 0x181;
  local_a08[0x12] = 0x201;
  local_a08[0x13] = 0x301;
  local_a08[0x14] = 0x401;
  local_a08[0x15] = 0x601;
  local_a08[0x16] = 0x801;
  local_a08[0x17] = 0xc01;
  local_a08[0x18] = 0x1001;
  local_a08[0x19] = 0x1801;
  local_a08[0x1a] = 0x2001;
  local_a08[0x1b] = 0x3001;
  local_a08[0x1c] = 0x4001;
  local_a08[0x1d] = 0x6001;
  puVar16 = (undefined1 *)(*param_1 + lVar7);
  local_bb0 = param_2;
  do {
    uVar8 = (int)uVar20 - 1;
    uVar4 = uVar21 & 1;
    uVar22 = uVar21 >> 1;
    if (uVar8 < 0x21) {
      uVar21 = *param_2;
      param_2 = (ulonglong *)((longlong)param_2 + 4);
      uVar22 = (ulonglong)(uint)uVar21 << ((ulonglong)uVar8 & 0x3f) | uVar22;
      uVar8 = (int)uVar20 + 0x1f;
      local_bb0 = param_2;
    }
    local_ba8 = uVar8 - 2;
    uVar20 = (ulonglong)local_ba8;
    uVar21 = uVar22 >> 2;
    uVar11 = (uint)uVar22 & 3;
    if (local_ba8 < 0x21) {
      uVar10 = *param_2;
      param_2 = (ulonglong *)((longlong)param_2 + 4);
      uVar21 = (ulonglong)(uint)uVar10 << (uVar20 & 0x3f) | uVar21;
      local_ba8 = uVar8 + 0x1e;
      uVar20 = (ulonglong)local_ba8;
      local_bb0 = param_2;
    }
    local_bb8 = uVar21;
    if (uVar11 == 3) {
      FUN_140002010("Bad compression type! This value is reserved");
      pcVar2 = (code *)swi(3);
      lVar7 = (*pcVar2)();
      return lVar7;
    }
    uVar10 = uVar12;
    puVar17 = puVar16;
    if ((uVar22 & 3) == 0) {
      uVar8 = (uint)uVar20 & 0xfffffff8;
      uVar22 = uVar21 >> ((ulonglong)((uint)uVar20 - uVar8) & 0x3f);
      if (uVar8 < 0x21) {
        uVar21 = *param_2;
        param_2 = (ulonglong *)((longlong)param_2 + 4);
        uVar22 = uVar22 | (ulonglong)(uint)uVar21 << ((ulonglong)uVar8 & 0x3f);
        uVar8 = uVar8 + 0x20;
      }
      uVar11 = uVar8 - 0x10;
      uVar21 = uVar22 >> 0x10;
      if (uVar11 < 0x21) {
        uVar20 = *param_2;
        param_2 = (ulonglong *)((longlong)param_2 + 4);
        uVar21 = uVar21 | (ulonglong)(uint)uVar20 << ((ulonglong)uVar11 & 0x3f);
        uVar11 = uVar8 + 0x10;
      }
      uVar8 = uVar11 - 0x10;
      local_bb8 = uVar21 >> 0x10;
      if (uVar8 < 0x21) {
        uVar20 = *param_2;
        param_2 = (ulonglong *)((longlong)param_2 + 4);
        local_bb8 = (ulonglong)(uint)uVar20 << ((ulonglong)uVar8 & 0x3f) | local_bb8;
        uVar8 = uVar11 + 0x10;
      }
      uVar11 = (uint)uVar22 & 0xffff;
      if (uVar11 != (ushort)~(ushort)uVar21) {
        FUN_140002010(
                     "Data corruption? Length and the one\'s complement of length are not inverse of each other"
                     );
        pcVar2 = (code *)swi(3);
        lVar7 = (*pcVar2)();
        return lVar7;
      }
      uVar21 = (ulonglong)(uVar8 + 7 >> 3);
      puVar24 = (undefined1 *)((longlong)param_2 - uVar21);
      uVar20 = 0x40;
      uVar11 = uVar11 + (int)uVar14;
      puVar19 = (ulonglong *)((longlong)param_2 + ((uVar22 & 0xffff) - uVar21));
      uVar21 = *puVar19;
      param_2 = puVar19 + 1;
      uVar8 = (uint)uVar12;
      if (uVar8 <= uVar11) {
        do {
          uVar13 = (int)uVar10 + (int)(uVar10 >> 1);
          uVar10 = (ulonglong)uVar13;
        } while (uVar13 <= uVar11);
        puVar17 = (undefined1 *)0x0;
        if ((puVar16 == (undefined1 *)0x0) ||
           (puVar16 + uVar12 != (undefined1 *)(*param_1 + param_1[2]))) {
          if (uVar8 < uVar13) {
            puVar17 = (undefined1 *)(*param_1 + param_1[2]);
            param_1[2] = param_1[2];
            puVar15 = puVar17;
            if (puVar16 != (undefined1 *)0x0) {
              for (; uVar12 != 0; uVar12 = uVar12 - 1) {
                *puVar15 = *puVar16;
                puVar16 = puVar16 + 1;
                puVar15 = puVar15 + 1;
              }
            }
            param_1[2] = param_1[2] + (ulonglong)uVar13;
          }
        }
        else {
          param_1[2] = (ulonglong)(uVar13 - uVar8) + param_1[2];
          puVar17 = puVar16;
        }
        uVar14 = (ulonglong)param_5;
      }
      puVar16 = puVar17 + uVar14;
      param_5 = (int)uVar14 + ((uint)uVar22 & 0xffff);
      uVar14 = (ulonglong)param_5;
      for (uVar22 = uVar22 & 0xffff; local_bb0 = param_2, uVar22 != 0; uVar22 = uVar22 - 1) {
        *puVar16 = *puVar24;
        puVar24 = puVar24 + 1;
        puVar16 = puVar16 + 1;
      }
    }
    else if (uVar11 - 1 < 2) {
      local_ba0 = param_7;
      puVar6 = param_6;
      if (uVar11 == 2) {
        FUN_140006740(&local_bb8,local_988,local_4e8);
        uVar20 = (ulonglong)local_ba8;
        puVar6 = local_988;
        local_ba0 = local_4e8;
        param_2 = local_bb0;
      }
      local_b98 = puVar6 + 1;
      uVar21 = local_bb8;
      while( true ) {
        uVar11 = (uint)uVar21 & 0x7fff;
        iVar23 = 0;
        iVar9 = 0;
        uVar13 = 0;
        uVar8 = 1;
        puVar18 = local_b98;
        while( true ) {
          if (0xf < uVar8) {
            FUN_140002010("Huffman decode failed");
            pcVar2 = (code *)swi(3);
            lVar7 = (*pcVar2)();
            return lVar7;
          }
          uVar1 = *puVar18;
          uVar5 = uVar11 & 1;
          uVar11 = uVar11 >> 1;
          uVar13 = uVar13 * 2 | uVar5;
          if ((int)(uVar13 - uVar1) < iVar9) break;
          iVar23 = iVar23 + (uint)uVar1;
          iVar9 = (iVar9 + (uint)uVar1) * 2;
          uVar8 = uVar8 + 1;
          puVar18 = puVar18 + 1;
        }
        uVar8 = 0xf - uVar8;
        sVar3 = ((byte)uVar8 < 0x21) * (' ' - (byte)uVar8);
        uVar5 = (int)uVar20 + -0xf + uVar8;
        uVar20 = (ulonglong)uVar5;
        uVar21 = (ulonglong)((uVar11 << sVar3) >> sVar3) |
                 (uVar21 >> 0xf) << ((ulonglong)uVar8 & 0x3f);
        if (uVar5 < 0x21) {
          uVar12 = *param_2;
          param_2 = (ulonglong *)((longlong)param_2 + 4);
          uVar21 = (ulonglong)(uint)uVar12 << (uVar20 & 0x3f) | uVar21;
          uVar20 = (ulonglong)(uVar5 + 0x20);
          local_bb0 = param_2;
        }
        uVar1 = puVar6[(longlong)(int)((uVar13 - iVar9) + iVar23) + 0x10];
        if (uVar1 == 0x100) break;
        uVar8 = (uint)uVar10;
        if (uVar1 < 0x100) {
          uVar14 = (ulonglong)param_5;
          uVar12 = uVar10;
          puVar16 = puVar17;
          if (param_5 + 1 < uVar8) {
LAB_14000b029:
            param_5 = param_5 + 1;
            puVar16[uVar14] = (char)uVar1;
            uVar10 = uVar12;
            puVar17 = puVar16;
          }
          else {
            do {
              uVar11 = (int)uVar12 + (int)(uVar12 >> 1);
              uVar12 = (ulonglong)uVar11;
            } while (uVar11 <= param_5 + 1);
            puVar16 = (undefined1 *)0x0;
            if ((puVar17 == (undefined1 *)0x0) ||
               (puVar17 + uVar10 != (undefined1 *)(*param_1 + param_1[2]))) {
              if (uVar8 < uVar11) {
                puVar16 = (undefined1 *)(*param_1 + param_1[2]);
                param_1[2] = param_1[2];
                puVar24 = puVar16;
                if (puVar17 != (undefined1 *)0x0) {
                  for (; uVar10 != 0; uVar10 = uVar10 - 1) {
                    *puVar24 = *puVar17;
                    puVar17 = puVar17 + 1;
                    puVar24 = puVar24 + 1;
                  }
                }
                param_1[2] = param_1[2] + (ulonglong)uVar11;
              }
              goto LAB_14000b029;
            }
            param_5 = param_5 + 1;
            param_1[2] = (ulonglong)(uVar11 - uVar8) + param_1[2];
            puVar17[uVar14] = (char)uVar1;
            uVar10 = uVar12;
          }
        }
        else {
          if (0x11d < uVar1) {
            FUN_140002010("Read wrong value!");
            pcVar2 = (code *)swi(3);
            lVar7 = (*pcVar2)();
            return lVar7;
          }
          uVar11 = local_b88[(ushort)(uVar1 - 0x101)];
          local_ba8 = (int)uVar20 - uVar11;
          uVar20 = (ulonglong)local_ba8;
          sVar3 = ((byte)uVar11 < 0x21) * (' ' - (byte)uVar11);
          local_bb8 = uVar21 >> ((ulonglong)uVar11 & 0x3f);
          if (local_ba8 < 0x21) {
            local_ba8 = local_ba8 + 0x20;
            local_bb0 = (ulonglong *)((longlong)param_2 + 4);
            local_bb8 = (ulonglong)(uint)*param_2 << (uVar20 & 0x3f) | local_bb8;
          }
          uVar11 = local_b08[(ushort)(uVar1 - 0x101)] + ((uint)((int)uVar21 << sVar3) >> sVar3);
          uVar12 = FUN_1400143d0((longlong)local_ba0,&local_bb8);
          if (0x1d < (ushort)uVar12) {
            FUN_140002010("Distance read out of range");
            pcVar2 = (code *)swi(3);
            lVar7 = (*pcVar2)();
            return lVar7;
          }
          uVar13 = local_a88[uVar12 & 0xffff];
          sVar3 = ((byte)uVar13 < 0x21) * (' ' - (byte)uVar13);
          uVar21 = local_bb8 >> ((ulonglong)uVar13 & 0x3f);
          uVar13 = local_ba8 - uVar13;
          uVar20 = (ulonglong)uVar13;
          if (uVar13 < 0x21) {
            uVar14 = *local_bb0;
            local_bb0 = (ulonglong *)((longlong)local_bb0 + 4);
            uVar21 = (ulonglong)(uint)uVar14 << (uVar20 & 0x3f) | uVar21;
            uVar20 = (ulonglong)(uVar13 + 0x20);
          }
          iVar9 = local_a08[uVar12 & 0xffff];
          uVar12 = uVar10;
          puVar16 = puVar17;
          if (uVar8 <= uVar11 + param_5) {
            do {
              uVar13 = (int)uVar12 + (int)(uVar12 >> 1);
              uVar12 = (ulonglong)uVar13;
            } while (uVar13 <= uVar11 + param_5);
            puVar16 = (undefined1 *)0x0;
            if ((puVar17 == (undefined1 *)0x0) ||
               (puVar17 + uVar10 != (undefined1 *)(*param_1 + param_1[2]))) {
              if (uVar8 < uVar13) {
                puVar16 = (undefined1 *)(*param_1 + param_1[2]);
                param_1[2] = param_1[2];
                puVar24 = puVar16;
                if (puVar17 != (undefined1 *)0x0) {
                  for (; uVar10 != 0; uVar10 = uVar10 - 1) {
                    *puVar24 = *puVar17;
                    puVar17 = puVar17 + 1;
                    puVar24 = puVar24 + 1;
                  }
                }
                param_1[2] = param_1[2] + (ulonglong)uVar13;
              }
            }
            else {
              param_1[2] = (ulonglong)(uVar13 - uVar8) + param_1[2];
              puVar16 = puVar17;
            }
          }
          if (uVar11 != 0) {
            uVar14 = (ulonglong)uVar11;
            uVar8 = param_5;
            do {
              uVar22 = (ulonglong)uVar8;
              uVar13 = uVar8 - (iVar9 + ((uint)((int)local_bb8 << sVar3) >> sVar3));
              uVar8 = uVar8 + 1;
              puVar16[uVar22] = puVar16[uVar13];
              uVar14 = uVar14 - 1;
            } while (uVar14 != 0);
          }
          param_5 = param_5 + uVar11;
          uVar10 = uVar12;
          param_2 = local_bb0;
          puVar17 = puVar16;
        }
      }
      uVar14 = (ulonglong)param_5;
    }
    uVar12 = uVar10;
    puVar16 = puVar17;
    if (uVar4 != 0) {
      uVar8 = (uint)uVar20 & 0xfffffff8;
      *param_3 = puVar17;
      *param_4 = (int)uVar14;
      if (uVar8 < 0x21) {
        param_2 = (ulonglong *)((longlong)param_2 + 4);
        uVar8 = uVar8 + 0x20;
      }
      return (longlong)param_2 - (ulonglong)(uVar8 + 7 >> 3);
    }
  } while( true );
}


// ===== FUN_14000b290 @ 14000b290 size=1572

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14000b290(ulonglong param_1)

{
  longlong lVar1;
  float fVar2;
  char cVar3;
  longlong *plVar4;
  undefined8 uVar5;
  code *pcVar6;
  ulonglong uVar7;
  uint uVar8;
  longlong lVar9;
  undefined1 *puVar10;
  uint uVar11;
  uint uVar12;
  undefined1 *puVar13;
  uint uVar14;
  longlong lVar15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  undefined1 *puVar18;
  float fVar19;
  float fVar20;
  undefined8 local_res10;
  undefined4 local_138;
  undefined4 uStack_134;
  undefined4 local_128;
  undefined4 uStack_124;
  undefined4 local_118;
  undefined4 uStack_114;
  undefined8 uStack_110;
  undefined *puStack_108;
  undefined8 uStack_100;
  undefined4 local_f8;
  undefined4 uStack_f4;
  undefined8 uStack_f0;
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined *local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined *puStack_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined1 local_40 [16];
  undefined *local_30;
  
  FUN_14001a480();
  puVar18 = (undefined1 *)0x0;
  puVar10 = puVar18;
  uVar8 = DAT_14002a888;
  if (DAT_14002a888 != 0) {
    do {
      if ((undefined1 *)(ulonglong)uVar8 <= puVar10) {
        pcVar6 = (code *)swi(3);
        (*pcVar6)();
        return;
      }
      plVar4 = *(longlong **)(DAT_14002a880 + (longlong)puVar10 * 8);
      if ((plVar4 != (longlong *)0x0) && (plVar4[1] != 0)) {
        if ((ulonglong)DAT_14002a870 <= (ulonglong)*(uint *)((longlong)plVar4 + 0x34)) {
          pcVar6 = (code *)swi(3);
          (*pcVar6)();
          return;
        }
        *(undefined8 *)(DAT_14002a868 + (ulonglong)*(uint *)((longlong)plVar4 + 0x34) * 8) = 0;
        plVar4[1] = 0;
        *plVar4 = (longlong)DAT_14002a840;
        uVar8 = DAT_14002a888;
        DAT_14002a840 = plVar4;
      }
      uVar11 = (int)puVar10 + 1;
      puVar10 = (undefined1 *)(ulonglong)uVar11;
    } while (uVar11 < uVar8);
  }
  DAT_14002a858 = 0;
  DAT_14002a888 = 0;
  uVar7 = 1;
  if (1 < DAT_14002a870) {
    do {
      if (DAT_14002a870 <= uVar7) {
        pcVar6 = (code *)swi(3);
        (*pcVar6)();
        return;
      }
      uVar8 = (int)uVar7 + 1;
      *(undefined8 *)(DAT_14002a868 + uVar7 * 8) = 0;
      uVar7 = (ulonglong)uVar8;
    } while (uVar8 < DAT_14002a870);
  }
  puVar10 = puVar18;
  uVar8 = DAT_140029a88._4_4_;
  uVar11 = (uint)DAT_140029a88;
  if (DAT_140029a88._4_4_ != 0) {
    do {
      puVar13 = puVar18;
      if (uVar11 != 0) {
        do {
          uVar12 = (int)puVar13 + 1;
          *(undefined4 *)(DAT_140029a98 + (ulonglong)((int)puVar10 * uVar11 + (int)puVar13) * 4) = 0
          ;
          puVar13 = (undefined1 *)(ulonglong)uVar12;
          uVar8 = DAT_140029a88._4_4_;
          uVar11 = (uint)DAT_140029a88;
        } while (uVar12 < (uint)DAT_140029a88);
      }
      uVar12 = (int)puVar10 + 1;
      puVar10 = (undefined1 *)(ulonglong)uVar12;
    } while (uVar12 < uVar8);
  }
  FUN_140008ac0((uint *)&DAT_14002a9e0,&DAT_14002a9c8,param_1);
  DAT_14002a8f8 = 0;
  DAT_14002a8f0 = FUN_140008210;
  DAT_14002a908 = 0;
  DAT_14002a900 = FUN_140003fe0;
  puVar10 = &DAT_14004a9f0;
  for (lVar9 = 0x20000; lVar9 != 0; lVar9 = lVar9 + -1) {
    *puVar10 = 0;
    puVar10 = puVar10 + 1;
  }
  puVar10 = &DAT_14006a9f0;
  for (lVar9 = 0x20000; lVar9 != 0; lVar9 = lVar9 + -1) {
    *puVar10 = 0;
    puVar10 = puVar10 + 1;
  }
  puVar10 = &DAT_14008a9f0;
  for (lVar9 = 0x20000; lVar9 != 0; lVar9 = lVar9 + -1) {
    *puVar10 = 0;
    puVar10 = puVar10 + 1;
  }
  puVar10 = puVar18;
  uVar8 = DAT_140029a88._4_4_;
  uVar11 = (uint)DAT_140029a88;
  if (DAT_140029a88._4_4_ != 0) {
    do {
      if (uVar11 != 0) {
        local_res10 = (longlong)puVar10 << 0x20;
        puVar13 = puVar18;
        do {
          local_res10 = CONCAT44(local_res10._4_4_,(int)puVar13);
          FUN_14001a4f0(local_res10);
          uVar12 = (int)puVar13 + 1;
          puVar13 = (undefined1 *)(ulonglong)uVar12;
          uVar8 = DAT_140029a88._4_4_;
          uVar11 = (uint)DAT_140029a88;
        } while (uVar12 < (uint)DAT_140029a88);
      }
      uVar12 = (int)puVar10 + 1;
      puVar10 = (undefined1 *)(ulonglong)uVar12;
    } while (uVar12 < uVar8);
  }
  DAT_14004a9e4 = 0;
  FUN_14000c940();
  uVar8 = DAT_14002a9d8;
  puVar13 = (undefined1 *)(ulonglong)DAT_14002a9d8;
  DAT_1400ea9f0 = &DAT_140029878;
  DAT_1400eaa00 = 0;
  DAT_1400eaa08 = &DAT_140029878;
  DAT_1400eaa18 = 0;
  puVar10 = &DAT_1400aa9f0;
  for (lVar9 = 0x40000; lVar9 != 0; lVar9 = lVar9 + -1) {
    *puVar10 = 0;
    puVar10 = puVar10 + 1;
  }
  if (uVar8 == 0) {
    DAT_1400eaa00 = uVar8;
  }
  else {
    puVar10 = puVar18;
    if (DAT_1400eaa04 < uVar8) {
      lVar9 = (ulonglong)DAT_1400eaa04 * 4;
      if ((DAT_1400ea9f8 == (undefined1 *)0x0) ||
         (DAT_1400ea9f8 + lVar9 != (undefined1 *)(DAT_140029888 + DAT_140029878))) {
        puVar17 = puVar18;
        if (DAT_1400eaa04 < uVar8) {
          DAT_140029888 = DAT_140029888 + 3 & 0xfffffffffffffffc;
          puVar17 = (undefined1 *)(DAT_140029878 + DAT_140029888);
          puVar16 = puVar17;
          if (DAT_1400ea9f8 != (undefined1 *)0x0) {
            for (; lVar9 != 0; lVar9 = lVar9 + -1) {
              *puVar16 = *DAT_1400ea9f8;
              DAT_1400ea9f8 = DAT_1400ea9f8 + 1;
              puVar16 = puVar16 + 1;
            }
            puVar10 = (undefined1 *)(ulonglong)DAT_1400eaa00;
          }
          DAT_140029888 = DAT_140029888 + (longlong)puVar13 * 4;
        }
      }
      else {
        DAT_140029888 = DAT_140029888 + (ulonglong)(uVar8 - DAT_1400eaa04) * 4;
        puVar17 = DAT_1400ea9f8;
      }
      DAT_1400eaa04 = uVar8;
      DAT_1400ea9f8 = puVar17;
    }
    lVar9 = (ulonglong)(uVar8 - (int)puVar10) << 2;
    puVar10 = DAT_1400ea9f8 + (longlong)puVar10 * 4;
    for (; lVar9 != 0; lVar9 = lVar9 + -1) {
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
    }
    DAT_1400eaa00 = uVar8;
    puVar10 = puVar18;
    do {
      if (puVar13 <= puVar10) {
        pcVar6 = (code *)swi(3);
        (*pcVar6)();
        return;
      }
      uVar8 = (int)puVar10 + 1;
      *(undefined4 *)(DAT_1400ea9f8 + (longlong)puVar10 * 4) = 0;
      puVar13 = (undefined1 *)(ulonglong)DAT_1400eaa00;
      puVar10 = (undefined1 *)(ulonglong)uVar8;
    } while (uVar8 < DAT_1400eaa00);
  }
  FUN_14000b8c0(&PTR_DAT_1400291d0,5,param_1,(6f),&DAT_140029878);
  _DAT_140029240 = 0;
  _DAT_140029238 = FUN_14001b7f0;
  if (DAT_14002a9d8 != 0) {
    uVar5 = *DAT_14002a9d0;
    uVar7 = 0x200000002;
    if (*(int *)(DAT_14002a9d0 + 1) == 0) {
      uVar7 = 0x100000001;
    }
    fVar20 = (float)(uVar7 & 0xffffffff) * (0.5f);
    fVar19 = (float)(uVar7 >> 0x20) * (0.5f);
    if ((uVar7 & 1) == 0) {
      fVar20 = fVar20 + (-0.0500000007f);
    }
    if ((uVar7 >> 0x20 & 1) == 0) {
      fVar19 = fVar19 + (-0.0500000007f);
    }
    local_138 = (undefined4)uVar5;
    uStack_134 = (undefined4)((ulonglong)uVar5 >> 0x20);
    local_128 = local_138;
    uStack_124 = uStack_134;
    _DAT_140029220 = uVar5;
    _DAT_140029228 = fVar20;
    _DAT_14002922c = fVar19;
    if (DAT_1400291e8 != 0) {
      do {
        lVar9 = DAT_1400291e0;
        if ((undefined1 *)(ulonglong)DAT_1400291e8 <= puVar18) {
          pcVar6 = (code *)swi(3);
          (*pcVar6)();
          return;
        }
        lVar15 = (longlong)puVar18 * 0x2080;
        *(float *)(lVar15 + 0x18 + DAT_1400291e0) = fVar20;
        *(float *)(lVar15 + 0x1c + lVar9) = fVar19;
        *(undefined8 *)(lVar15 + 0x10 + lVar9) = uVar5;
        *(undefined8 *)(lVar15 + 0x2064 + lVar9) = 0;
        *(undefined8 *)(lVar15 + 0x206c + lVar9) = 0;
        *(undefined4 *)(lVar15 + 0x2074 + lVar9) = 0;
        lVar9 = DAT_1400291e0;
        if ((undefined1 *)(ulonglong)DAT_1400291e8 <= puVar18) {
          pcVar6 = (code *)swi(3);
          (*pcVar6)();
          return;
        }
        uVar8 = (int)puVar18 + 1;
        puVar18 = (undefined1 *)(ulonglong)uVar8;
        uVar7 = *(ulonglong *)(DAT_1400291e0 + 0x10 + lVar15);
        lVar1 = DAT_1400291e0 + 0x18;
        fVar2 = *(float *)(DAT_1400291e0 + 0x1c + lVar15);
        *(undefined8 *)(DAT_1400291e0 + 8 + lVar15) = 0;
        *(float *)(lVar9 + lVar15) = (float)(uVar7 & 0xffffffff) + *(float *)(lVar1 + lVar15);
        *(float *)(lVar9 + 4 + lVar15) = (float)(uVar7 >> 0x20) + fVar2;
        *(undefined8 *)(lVar9 + 0x2064 + lVar15) = 0;
        *(undefined8 *)(lVar9 + 0x206c + lVar15) = 0;
        *(undefined4 *)(lVar9 + 0x2074 + lVar15) = 0;
      } while (uVar8 < DAT_1400291e8);
    }
  }
  uVar12 = 1;
  uVar8 = DAT_140029a88._4_4_;
  uVar11 = (uint)DAT_140029a88;
  do {
    uVar14 = (uVar8 >> 1) + 1;
    if ((((-1 < (int)uVar12) && (-1 < (int)uVar14)) && (uVar12 < uVar11)) &&
       (((uVar14 < uVar8 && (DAT_1400299a8 != 0)) &&
        ((cVar3 = *(char *)((ulonglong)(uVar14 * uVar11 + uVar12) + DAT_140029a90), cVar3 == '\a' ||
         (cVar3 == '\x06')))))) {
      uStack_e0 = 0;
      uStack_d8 = 0;
      uStack_d0 = 0;
      uStack_c8 = 0;
      uStack_c0 = 0;
      uStack_b8 = 0;
      uStack_110 = 1;
      uStack_100 = 0;
      local_118 = 1;
      uStack_114 = 1;
      puStack_108 = &DAT_1400ead60;
      local_a0 = 0x100000001;
      uStack_98 = 1;
      puStack_90 = &DAT_1400ead60;
      uStack_88 = 0;
      local_60 = 0;
      uStack_58 = 0;
      uStack_50 = 0;
      uStack_48 = 0;
      local_f8 = 1;
      uStack_f4 = 1;
      uStack_f0 = 0;
      uStack_e8 = 0x48;
      local_80 = 0x100000001;
      uStack_78 = 0;
      uStack_70 = 0x48;
      uStack_68 = 0;
      local_b0 = 0;
      local_40 = ZEXT816(0);
      local_a8 = &DAT_1400eba70;
      local_res10 = CONCAT44(uVar14,uVar12);
      local_30 = &DAT_1400eba70;
      FUN_140008800((undefined8 *)&local_128,local_res10,0,(int *)&local_a0);
      uVar8 = DAT_140029a88._4_4_;
      uVar11 = (uint)DAT_140029a88;
    }
    uVar12 = uVar12 + 1;
  } while (uVar12 < 7);
  return;
}


// ===== FUN_14000b8c0 @ 14000b8c0 size=1064

void FUN_14000b8c0(undefined8 *param_1,uint param_2,ulonglong param_3,undefined4 param_4,
                  undefined8 *param_5)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  int iVar4;
  float *pfVar5;
  undefined8 *puVar6;
  undefined1 *puVar7;
  uint uVar8;
  uint uVar9;
  float fVar10;
  undefined4 uVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  uint local_res10;
  int iStackX_1c;
  ulonglong local_41b8;
  float local_41b0;
  float local_41ac;
  undefined8 local_41a8;
  ulonglong local_41a0;
  float local_4198;
  float local_4194;
  undefined4 local_4190;
  undefined4 local_418c;
  undefined4 local_4188;
  undefined4 local_4184;
  float local_4180;
  undefined1 local_417c;
  undefined1 local_4178;
  undefined8 local_4177;
  undefined8 local_416f;
  undefined2 local_4167;
  undefined1 local_4165;
  undefined4 local_4164;
  undefined4 local_4160;
  undefined8 local_415c;
  undefined1 local_4154;
  undefined4 local_4150;
  undefined1 local_414c [8192];
  undefined8 local_214c;
  undefined8 local_2144;
  undefined4 local_213c;
  float local_2138;
  float local_2134;
  undefined1 local_2130 [8432];
  
  local_41b8 = (ulonglong)param_2;
  *(undefined4 *)(param_1 + 0xb) = 0x3f000000;
  puVar6 = &DAT_140029878;
  if (param_5 != (undefined8 *)0x0) {
    puVar6 = param_5;
  }
  param_1[10] = param_3;
  *param_1 = puVar6;
  param_1[1] = puVar6;
  param_1[4] = puVar6;
  param_1[7] = puVar6;
  *(undefined4 *)(param_1 + 3) = 0;
  *(undefined4 *)(param_1 + 6) = 0;
  *(undefined4 *)(param_1 + 9) = 0;
  *(undefined4 *)((longlong)param_1 + 0x5c) = 0x3f000000;
  *(undefined4 *)(param_1 + 0xc) = param_4;
  if (param_2 != 0) {
    iStackX_1c = (int)(param_3 >> 0x20);
    uVar8 = 0;
    uVar9 = 0x27d4eb2f;
    iVar4 = (int)param_3;
    local_res10 = 0x9e3779b9;
    uVar11 = 0;
    uVar1 = iVar4 * 0x2c9277b5 + iStackX_1c * -0x53a9b4fb + 0x108ef2d9;
    uVar1 = (uVar1 >> 0x10 ^ uVar1) * -0x7a143589;
    fVar13 = (float)((uVar1 >> 0xd ^ uVar1) & 0x3ff) * (0.0009765625f);
    uVar1 = iVar4 * -0x61c88647 ^ iStackX_1c * -0x7a143595 ^ 0x1234abcd;
    uVar1 = (uVar1 >> 0x10 ^ uVar1) * 0x45d9f3b;
    uVar1 = (uVar1 >> 0x10 ^ uVar1) * 0x45d9f3b;
    fVar14 = (float)((uVar1 >> 0x10 ^ uVar1) & 0xffff) * (1.52590219e-05f);
    uVar1 = iVar4 * -0x3d4d51cb ^ iStackX_1c * 0x27d4eb2f ^ 0xb5297a4d;
    uVar1 = (uVar1 >> 0x10 ^ uVar1) * 0x45d9f3b;
    uVar1 = (uVar1 >> 0x10 ^ uVar1) * 0x45d9f3b;
    fVar15 = (float)((uVar1 >> 0x10 ^ uVar1) & 0xffff) * (1.52590219e-05f);
    fVar10 = (1.52590219e-05f);
    fVar12 = (0.0009765625f);
    do {
      local_4198 = *(float *)(param_1 + 0xb);
      local_4194 = *(float *)((longlong)param_1 + 0x5c);
      local_4190 = *(undefined4 *)(param_1 + 0xc);
      local_41a8 = 0;
      local_417c = 0;
      local_4178 = 0;
      local_4177 = 0;
      local_416f = 0;
      local_4167 = 0;
      local_4165 = 0;
      local_4160 = 0;
      local_415c = 1;
      local_4154 = 0;
      local_4150 = 0;
      local_41a0 = param_3;
      local_418c = uVar11;
      local_4188 = uVar11;
      local_4184 = uVar11;
      local_4164 = uVar11;
      FUN_1400200d0(local_414c,0,0x2000);
      local_213c = 0;
      local_2144 = 0;
      local_41ac = (float)(local_41a0 >> 0x20) + local_4194;
      local_41b0 = (float)(local_41a0 & 0xffffffff) + local_4198;
      local_4180 = fVar13;
      local_214c = 0;
      pfVar5 = &local_41b0;
      puVar7 = local_2130;
      for (lVar3 = 0x2080; lVar3 != 0; lVar3 = lVar3 + -1) {
        *puVar7 = *(undefined1 *)pfVar5;
        pfVar5 = (float *)((longlong)pfVar5 + 1);
        puVar7 = puVar7 + 1;
      }
      local_2138 = fVar14;
      local_2134 = fVar15;
      FUN_1400014b0(param_1 + 1,local_2130);
      uVar1 = local_res10 ^ iVar4 * -0x7a143595 ^ iStackX_1c * -0x3d4d51cb;
      lVar3 = (ulonglong)(*(int *)(param_1 + 3) - 1) * 0x2080 + param_1[2];
      uVar1 = (uVar1 >> 0x10 ^ uVar1) * 0x45d9f3b;
      *(float *)(lVar3 + 0x30) = (float)(uVar8 & 0x3ff) * fVar12 + *(float *)(lVar3 + 0x30);
      uVar1 = (uVar1 >> 0x10 ^ uVar1) * 0x45d9f3b;
      local_res10 = local_res10 + 0x9e3779b9;
      uVar8 = uVar8 + 0xad;
      uVar2 = uVar9 ^ iStackX_1c * -0x2c5d9b94 ^ iVar4 * 0x165667b1;
      uVar9 = uVar9 + 0x27d4eb2f;
      uVar2 = (uVar2 >> 0x10 ^ uVar2) * 0x45d9f3b;
      *(float *)(lVar3 + 0x2078) = (float)((uVar1 >> 0x10 ^ uVar1) & 0xffff) * fVar10;
      uVar1 = (uVar2 >> 0x10 ^ uVar2) * 0x45d9f3b;
      local_41b8 = local_41b8 - 1;
      *(float *)(lVar3 + 0x207c) = (float)((uVar1 >> 0x10 ^ uVar1) & 0xffff) * fVar10;
    } while (local_41b8 != 0);
  }
  return;
}


// ===== FUN_14000bcf0 @ 14000bcf0 size=994

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14000bcf0(void)

{
  code *pcVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  longlong *plVar7;
  undefined1 *puVar8;
  
  puVar5 = (undefined1 *)0x0;
  DAT_140029a30 = 0;
  puVar6 = puVar5;
  if (DAT_140029a34 < 0xe) {
    lVar3 = (ulonglong)DAT_140029a34 * 4;
    plVar7 = &DAT_140029878;
    if (DAT_140029a20 != (longlong *)0x0) {
      plVar7 = DAT_140029a20;
    }
    if ((DAT_140029a28 == (undefined1 *)0x0) ||
       (DAT_140029a28 + lVar3 != (undefined1 *)(*plVar7 + plVar7[2]))) {
      puVar8 = puVar5;
      if (DAT_140029a34 < 0xe) {
        uVar4 = plVar7[2] + 3U & 0xfffffffffffffffc;
        puVar8 = (undefined1 *)(*plVar7 + uVar4);
        plVar7[2] = uVar4;
        puVar6 = puVar8;
        if (DAT_140029a28 != (undefined1 *)0x0) {
          for (; lVar3 != 0; lVar3 = lVar3 + -1) {
            *puVar6 = *DAT_140029a28;
            DAT_140029a28 = DAT_140029a28 + 1;
            puVar6 = puVar6 + 1;
          }
        }
        plVar7[2] = plVar7[2] + 0x38;
        goto LAB_14000bda5;
      }
    }
    else {
      plVar7[2] = plVar7[2] + (ulonglong)(0xe - DAT_140029a34) * 4;
      puVar8 = DAT_140029a28;
LAB_14000bda5:
      puVar6 = (undefined1 *)(ulonglong)DAT_140029a30;
    }
    DAT_140029a34 = 0xe;
    DAT_140029a28 = puVar8;
  }
  lVar3 = (ulonglong)(0xe - (int)puVar6) << 2;
  puVar6 = DAT_140029a28 + (longlong)puVar6 * 4;
  for (; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  uVar4 = (ulonglong)DAT_14002956c;
  DAT_140029568 = 0;
  DAT_140029a30 = 0xe;
  puVar6 = puVar5;
  if (0xd < DAT_14002956c) goto LAB_14000be8c;
  plVar7 = &DAT_140029878;
  if (PTR_DAT_140029558 != (undefined *)0x0) {
    plVar7 = (longlong *)PTR_DAT_140029558;
  }
  if ((DAT_140029560 == (undefined1 *)0x0) ||
     (DAT_140029560 + uVar4 != (undefined1 *)(*plVar7 + plVar7[2]))) {
    puVar8 = puVar5;
    if (DAT_14002956c < 0xe) {
      puVar8 = (undefined1 *)(*plVar7 + plVar7[2]);
      plVar7[2] = plVar7[2];
      puVar6 = puVar8;
      if (DAT_140029560 != (undefined1 *)0x0) {
        for (; uVar4 != 0; uVar4 = uVar4 - 1) {
          *puVar6 = *DAT_140029560;
          DAT_140029560 = DAT_140029560 + 1;
          puVar6 = puVar6 + 1;
        }
      }
      plVar7[2] = plVar7[2] + 0xe;
      goto LAB_14000be6c;
    }
  }
  else {
    plVar7[2] = (ulonglong)(0xe - DAT_14002956c) + plVar7[2];
    puVar8 = DAT_140029560;
LAB_14000be6c:
    puVar6 = (undefined1 *)(ulonglong)DAT_140029568;
  }
  DAT_14002956c = 0xe;
  DAT_140029560 = puVar8;
LAB_14000be8c:
  uVar4 = (ulonglong)(0xe - (int)puVar6);
  puVar6 = puVar6 + (longlong)DAT_140029560;
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  DAT_140029568 = 0xe;
  *DAT_140029560 = 0xff;
  if (DAT_140029568 < 2) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  DAT_140029560[1] = 0xff;
  if (DAT_140029568 < 3) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  DAT_140029560[2] = 0xff;
  if (DAT_140029568 < 4) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  DAT_140029560[3] = 0xff;
  if (DAT_140029568 < 5) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  DAT_140029560[4] = 0xff;
  if (DAT_140029568 < 6) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  DAT_140029560[5] = 0xff;
  if (DAT_140029568 < 7) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  DAT_140029560[6] = 0xff;
  if (7 < DAT_140029568) {
    DAT_140029560[7] = 0xff;
    if (DAT_140029568 < 9) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    DAT_140029560[8] = 0xff;
    if (DAT_140029568 < 10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    DAT_140029560[9] = 0xff;
    if (DAT_140029568 < 0xb) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    DAT_140029560[10] = 0xff;
    if (0xb < DAT_140029568) {
      DAT_140029560[0xb] = 0xff;
      if (DAT_140029568 < 0xd) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      DAT_140029560[0xc] = 0xff;
      if (0xd < DAT_140029568) {
        DAT_140029560[0xd] = 0xff;
        if (DAT_140029a30 != 0) {
          do {
            if ((undefined1 *)(ulonglong)DAT_140029a30 <= puVar5) {
              pcVar1 = (code *)swi(3);
              (*pcVar1)();
              return;
            }
            uVar2 = (int)puVar5 + 1;
            *(undefined4 *)(DAT_140029a28 + (longlong)puVar5 * 4) = 0;
            puVar5 = (undefined1 *)(ulonglong)uVar2;
          } while (uVar2 < DAT_140029a30);
        }
        DAT_140029024 = 0xe;
        DAT_1400299b0 = &DAT_1400eb020;
        _DAT_1400299b8 = &DAT_1400eb040;
        _DAT_1400299c0 = &DAT_1400eb060;
        _DAT_1400299c8 = &DAT_1400eb080;
        _DAT_1400299d0 = &DAT_1400eb0a0;
        _DAT_1400299d8 = &DAT_1400eb0c0;
        _DAT_1400299e0 = &DAT_1400eb0e0;
        _DAT_1400299e8 = &DAT_1400eb100;
        _DAT_1400299f0 = &DAT_1400eb120;
        _DAT_1400299f8 = &DAT_1400eb140;
        _DAT_140029a00 = &DAT_1400eb160;
        DAT_140029a08 = &DAT_1400eb1a0;
        DAT_140029a10 = &DAT_1400eb1c0;
        _DAT_140029a18 = &DAT_1400eb200;
        DAT_140029025 = 0xff;
        return;
      }
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ===== FUN_14000c0e0 @ 14000c0e0 size=115

undefined8 FUN_14000c0e0(ulonglong *param_1,ulonglong param_2)

{
  LPVOID pvVar1;
  ulonglong uVar2;
  
  pvVar1 = VirtualAlloc((LPVOID)0x0,(param_2 + 0xfff & 0xfffffffffffff000) + 0x20000,0x2000,4);
  uVar2 = (longlong)pvVar1 + 0x1ffffU & 0xfffffffffffe0000;
  *param_1 = uVar2;
  if (uVar2 == 0) {
    return 0;
  }
  param_1[1] = param_2;
  param_1[2] = 0;
  return 1;
}


// ===== FUN_14000c160 @ 14000c160 size=1456

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14000c160(void)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  undefined1 (*pauVar12) [16];
  undefined8 *puVar13;
  ulonglong uVar14;
  undefined1 auVar15 [16];
  undefined1 auVar16 [16];
  undefined1 auVar17 [16];
  undefined1 auVar18 [16];
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined8 *puStack_a0;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  uint uStack_84;
  undefined8 uStack_80;
  undefined8 *local_78;
  undefined8 *puStack_70;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined8 *local_58;
  undefined8 *puStack_50;
  undefined8 local_48;
  undefined8 *local_38;
  undefined8 uStack_30;
  undefined8 uStack_28;
  undefined8 uStack_10;
  
  _DAT_1400eb8c0 = 0;
  uRam00000001400eb8c8 = 0;
  uRam00000001400eb8d0 = 0;
  uRam00000001400eb8d8 = 0;
  _DAT_1400eb920 = 1;
  uRam00000001400eb928 = 2;
  uRam00000001400eb930 = 0;
  uRam00000001400eb938 = 0x400000000;
  _DAT_1400eb980 = 0x100000001;
  uRam00000001400eb988 = 3;
  uRam00000001400eb990 = 0;
  uRam00000001400eb998 = 0x300000000;
  _DAT_1400eb950 = 0x400000001;
  uRam00000001400eb958 = 5;
  uRam00000001400eb960 = 0;
  uRam00000001400eb968 = 0x800000000;
  _DAT_1400eb8e0 = vinsertps_avx(ZEXT416(uStack_84) << 0x20,ZEXT416((0.800000012f)),0x10);
  uStack_84 = DAT_1400eb8e0._4_4_;
  auVar1._4_4_ = uStack_84;
  auVar1._0_4_ = 1;
  auVar1._8_8_ = &DAT_1400eb0a0;
  _DAT_1400eb940 = vinsertps_avx(auVar1,ZEXT416((7f)),0x10);
  uStack_84 = DAT_1400eb940._4_4_;
  auVar2._4_4_ = uStack_84;
  auVar2._0_4_ = 1;
  auVar2._8_8_ = &DAT_1400eb080;
  _DAT_1400eb9a0 = vinsertps_avx(auVar2,ZEXT416((4f)),0x10);
  uStack_84 = DAT_1400eb9a0._4_4_;
  auVar3._4_4_ = uStack_84;
  auVar3._0_4_ = 3;
  auVar3._8_8_ = &DAT_1400eb120;
  _DAT_1400eb970 = vinsertps_avx(auVar3,ZEXT416((2f)),0x10);
  uStack_84 = DAT_1400eb970._4_4_;
  auVar4._4_4_ = uStack_84;
  auVar4._0_4_ = 2;
  auVar4._8_8_ = &DAT_1400eb0c0;
  _DAT_1400eb9d0 = vinsertps_avx(auVar4,ZEXT416((8f)),0x10);
  _DAT_1400eb9b0 = 0x300000001;
  uRam00000001400eb9b8 = 4;
  uRam00000001400eb9c0 = 0;
  uRam00000001400eb9c8 = 0x500000000;
  uStack_84 = DAT_1400eb9d0._4_4_;
  _DAT_1400eb9e0 = 0x400000003;
  uRam00000001400eb9e8 = 0xa00000005;
  uRam00000001400eb9f0 = 0x500000003;
  uRam00000001400eb9f8 = 0x900000001;
  uVar14 = DAT_140029888 + 7U & 0xfffffffffffffff8;
  puStack_70 = (undefined8 *)(DAT_140029878 + uVar14);
  _DAT_1400eba10 = 0x400000003;
  uRam00000001400eba18 = 0x800000002;
  uRam00000001400eba20 = 0x500000008;
  uRam00000001400eba28 = 0x600000002;
  auVar5._4_4_ = uStack_84;
  auVar5._0_4_ = 1;
  auVar5._8_8_ = &DAT_1400eb140;
  _DAT_1400eba00 = vinsertps_avx(auVar5,ZEXT416((20f)),0x10);
  uStack_84 = DAT_1400eba00._4_4_;
  auVar6._4_4_ = uStack_84;
  auVar6._0_4_ = 1;
  auVar6._8_8_ = &DAT_1400eb0e0;
  _DAT_1400eba30 = vinsertps_avx(auVar6,ZEXT416((15f)),0x10);
  uStack_84 = DAT_1400eba30._4_4_;
  DAT_140029888 = uVar14 + 0x40;
  auVar7._4_4_ = uStack_84;
  auVar7._0_4_ = 1;
  auVar7._8_8_ = &DAT_1400eb200;
  _DAT_1400eba60 = vinsertps_avx(auVar7,ZEXT416((15f)),0x10);
  uStack_88 = (undefined4)DAT_1400eba60;
  uStack_84 = DAT_1400eba60._4_4_;
  uStack_80 = DAT_1400eba60._8_8_;
  uStack_90 = 1;
  uStack_8c = 0xd;
  _DAT_1400eba40 = 0x900000003;
  uRam00000001400eba48 = 0x600000001;
  uRam00000001400eba50 = 0x200000002;
  uRam00000001400eba58 = 0xd00000001;
  local_78 = &DAT_140029878;
  local_68 = 1;
  uStack_64 = 8;
  local_48 = 0x800000001;
  *puStack_70 = &DAT_1400eb8c0;
  local_a8 = 0x40029878;
  uStack_a4 = 1;
  uStack_98 = 1;
  uStack_94 = 8;
  local_58 = &DAT_140029878;
  puStack_50 = puStack_70;
  puStack_a0 = puStack_70;
  pauVar12 = FUN_14001c060((undefined1 (*) [16])&local_78,(longlong)&local_58);
  uRam00000001400eba88 = *(undefined8 *)*pauVar12;
  auVar15._8_8_ = 0;
  auVar15._0_8_ = *(ulonglong *)pauVar12[1];
  uStack_90 = (undefined4)uRam00000001400eba88;
  uStack_8c = (undefined4)((ulonglong)uRam00000001400eba88 >> 0x20);
  auVar8._8_8_ = uStack_80;
  auVar8._0_8_ = *(undefined8 *)(*pauVar12 + 8);
  _DAT_1400eba70 = CONCAT44(uStack_a4,local_a8);
  puRam00000001400eba78 = puStack_a0;
  uRam00000001400eba80 = CONCAT44(uStack_94,uStack_98);
  _DAT_1400eba90 = vunpcklpd_avx(auVar8,auVar15);
  uStack_88 = (undefined4)DAT_1400eba90;
  uStack_84 = DAT_1400eba90._4_4_;
  uStack_80 = DAT_1400eba90._8_8_;
  uVar14 = DAT_140029888 + 7U & 0xfffffffffffffff8;
  puStack_70 = (undefined8 *)(DAT_140029878 + uVar14);
  local_78 = &DAT_140029878;
  DAT_140029888 = uVar14 + 0x40;
  local_68 = 2;
  uStack_64 = 8;
  local_48 = 0x800000002;
  *puStack_70 = &DAT_1400eb920;
  puStack_70[1] = &DAT_1400eb980;
  local_a8 = 0x40029878;
  uStack_a4 = 1;
  uStack_98 = 2;
  uStack_94 = 8;
  local_58 = &DAT_140029878;
  puStack_50 = puStack_70;
  puStack_a0 = puStack_70;
  pauVar12 = FUN_14001c060((undefined1 (*) [16])&local_78,(longlong)&local_58);
  uVar14 = DAT_140029888 + 7U & 0xfffffffffffffff8;
  uRam00000001400ebab8 = *(undefined8 *)*pauVar12;
  auVar16._8_8_ = 0;
  auVar16._0_8_ = *(ulonglong *)pauVar12[1];
  uStack_90 = (undefined4)uRam00000001400ebab8;
  uStack_8c = (undefined4)((ulonglong)uRam00000001400ebab8 >> 0x20);
  _DAT_1400ebaa0 = CONCAT44(uStack_a4,local_a8);
  puRam00000001400ebaa8 = puStack_a0;
  uRam00000001400ebab0 = CONCAT44(uStack_94,uStack_98);
  auVar9._8_8_ = uStack_80;
  auVar9._0_8_ = *(undefined8 *)(*pauVar12 + 8);
  puStack_70 = (undefined8 *)(DAT_140029878 + uVar14);
  local_78 = &DAT_140029878;
  auVar1 = vunpcklpd_avx(auVar9,auVar16);
  DAT_140029888 = uVar14 + 0x40;
  local_68 = 2;
  _DAT_1400ebac0 = auVar1;
  *puStack_70 = &DAT_1400eb950;
  uStack_88 = auVar1._0_4_;
  uStack_84 = auVar1._4_4_;
  uStack_80 = auVar1._8_8_;
  uStack_64 = 8;
  local_48 = 0x800000002;
  puStack_70[1] = &DAT_1400eb9b0;
  local_a8 = 0x40029878;
  uStack_a4 = 1;
  uStack_98 = 2;
  uStack_94 = 8;
  local_58 = &DAT_140029878;
  puStack_50 = puStack_70;
  puStack_a0 = puStack_70;
  pauVar12 = FUN_14001c060((undefined1 (*) [16])&local_78,(longlong)&local_58);
  uRam00000001400ebae8 = *(undefined8 *)*pauVar12;
  auVar17._8_8_ = 0;
  auVar17._0_8_ = *(ulonglong *)pauVar12[1];
  uStack_90 = (undefined4)uRam00000001400ebae8;
  uStack_8c = (undefined4)((ulonglong)uRam00000001400ebae8 >> 0x20);
  auVar10._8_8_ = uStack_80;
  auVar10._0_8_ = *(undefined8 *)(*pauVar12 + 8);
  _DAT_1400ebad0 = CONCAT44(uStack_a4,local_a8);
  puRam00000001400ebad8 = puStack_a0;
  uRam00000001400ebae0 = CONCAT44(uStack_94,uStack_98);
  _DAT_1400ebaf0 = vunpcklpd_avx(auVar10,auVar17);
  uStack_88 = (undefined4)DAT_1400ebaf0;
  uStack_84 = DAT_1400ebaf0._4_4_;
  uStack_80 = DAT_1400ebaf0._8_8_;
  puVar13 = FUN_140001000(&local_78,&DAT_140029878,&DAT_1400eb9e0,&DAT_1400eba10,&DAT_1400eba40);
  local_58 = (undefined8 *)*puVar13;
  puStack_50 = (undefined8 *)puVar13[1];
  local_48 = puVar13[2];
  local_38 = local_58;
  uStack_30 = puStack_50;
  uStack_28 = local_48;
  pauVar12 = FUN_14001c060((undefined1 (*) [16])&local_a8,(longlong)&local_58);
  auVar18._8_8_ = 0;
  auVar18._0_8_ = *(ulonglong *)pauVar12[1];
  auVar11._8_8_ = uStack_10;
  auVar11._0_8_ = *(undefined8 *)(*pauVar12 + 8);
  _DAT_1400ebb20 = vunpcklpd_avx(auVar11,auVar18);
  _DAT_1400ebb00 = local_38;
  uRam00000001400ebb08 = uStack_30;
  uRam00000001400ebb10 = uStack_28;
  uRam00000001400ebb18 = *(undefined8 *)*pauVar12;
  return;
}


// ===== FUN_14000c710 @ 14000c710 size=557

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_14000c710(int param_1,int param_2,undefined8 param_3,undefined8 param_4)

{
  ATOM AVar1;
  BOOL BVar2;
  HDC hdc;
  undefined8 uVar3;
  tagRECT local_98;
  RAWINPUTDEVICE local_88;
  undefined8 local_78;
  HWND local_70;
  undefined1 local_68 [64];
  char *local_28;
  HICON local_20;
  
  uVar3 = 1;
  DAT_140029808 = param_3;
  DAT_140029810 = param_4;
  DAT_140029678 = GetModuleHandleA((LPCSTR)0x0);
  local_68._32_8_ = LoadImageA(DAT_140029678,(LPCSTR)0x65,1,0,0,0x8000);
  local_68._16_4_ = 0;
  local_68._20_4_ = 0;
  local_68._40_8_ = (HCURSOR)0x0;
  local_68._8_8_ = FUN_14001f900;
  local_68._24_8_ = DAT_140029678;
  local_68._48_16_ = (undefined1  [16])0x0;
  local_68._0_4_ = 0x50;
  local_68._4_4_ = 0x23;
  local_28 = "Cyber5eagull";
  local_20 = (HICON)local_68._32_8_;
  AVar1 = RegisterClassExA((WNDCLASSEXA *)local_68);
  if (AVar1 != 0) {
    DAT_140029680 =
         CreateWindowExA(0,"Cyber5eagull","Cyber5eagull",0xcf0000,-0x80000000,-0x80000000,param_1,
                         param_2,(HWND)0x0,(HMENU)0x0,DAT_140029678,(LPVOID)0x0);
    if (DAT_140029680 != (HWND)0x0) {
      _DAT_14002966c = param_1;
      _DAT_1400296bc = param_2;
      BVar2 = GetClientRect(DAT_140029680,&local_98);
      if (BVar2 != 0) {
        DAT_1400296d0 = local_98.right - local_98.left;
        DAT_1400296d4 = local_98.bottom - local_98.top;
      }
      goto LAB_14000c86b;
    }
  }
  uVar3 = 0;
LAB_14000c86b:
  local_88.hwndTarget = DAT_140029680;
  local_70 = DAT_140029680;
  local_88.usUsagePage = 1;
  local_88.usUsage = 2;
  local_88.dwFlags = 0;
  local_78 = 0x60001;
  RegisterRawInputDevices(&local_88,2,0x10);
  SetProcessDPIAware();
  hdc = GetDC(DAT_140029680);
  _DAT_140029690 = 0x28;
  _DAT_140029694 = DAT_1400296d0;
  _DAT_140029698 = -DAT_1400296d4;
  _DAT_14002969c = 0x200001;
  DAT_140029688 = CreateCompatibleDC(hdc);
  ReleaseDC(DAT_140029680,hdc);
  _DAT_1400296e8 = 0xffffffff;
  DAT_1400296e4 = 0xffffffff;
  return uVar3;
}


// ===== FUN_14000c940 @ 14000c940 size=1251

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14000c940(void)

{
  uint uVar1;
  undefined8 *puVar2;
  longlong lVar3;
  uint local_res8;
  uint local_38;
  uint uStack_10;
  
  uVar1 = local_res8;
  if (DAT_14004a9e8 == 0) {
    lVar3 = 0xc;
    puVar2 = (undefined8 *)&DAT_140029290;
    do {
      local_38 = local_38 & 0xffffff00;
      uStack_10 = CONCAT31(uStack_10._1_3_,0xe);
      *puVar2 = CONCAT44(0xc,local_38);
      puVar2[1] = 0xc00000000;
      puVar2[2] = 0xc00000000;
      puVar2[3] = 0xc00000000;
      puVar2[4] = 0;
      puVar2[5] = (ulonglong)uStack_10;
      lVar3 = lVar3 + -1;
      puVar2 = puVar2 + 6;
    } while (lVar3 != 0);
    DAT_1400294f0 = 0;
    DAT_140029290 = 10;
    DAT_1400292c0 = 0xb;
    DAT_1400294d0 = 0xc;
    _DAT_1400294d8 = 0xc;
    uRam00000001400294e0 = 0xc;
    uRam00000001400294e8 = 0xc;
    if (DAT_1400292e4 < 4) {
      local_res8 = local_res8 & 0xffffff00;
      *(ulonglong *)(&DAT_1400292c4 + (ulonglong)DAT_1400292e4 * 8) = CONCAT44(4,local_res8);
      DAT_1400292e4 = DAT_1400292e4 + 1;
      if (DAT_1400292e4 < 4) {
        local_res8._1_3_ = SUB43(uVar1,1);
        local_res8 = CONCAT31(local_res8._1_3_,1);
        *(ulonglong *)(&DAT_1400292c4 + (ulonglong)DAT_1400292e4 * 8) = CONCAT44(2,local_res8);
        DAT_1400292e4 = DAT_1400292e4 + 1;
      }
    }
    DAT_1400292f0 = 0xc;
    if (DAT_140029314 < 4) {
      local_res8 = CONCAT31(local_res8._1_3_,4);
      *(ulonglong *)(&DAT_1400292f4 + (ulonglong)DAT_140029314 * 8) = CONCAT44(2,local_res8);
      DAT_140029314 = DAT_140029314 + 1;
      if (DAT_140029314 < 4) {
        local_res8 = CONCAT31(local_res8._1_3_,3);
        *(ulonglong *)(&DAT_1400292f4 + (ulonglong)DAT_140029314 * 8) = CONCAT44(1,local_res8);
        DAT_140029314 = DAT_140029314 + 1;
      }
    }
    uVar1 = local_res8;
    DAT_140029320 = 0xe;
    if (DAT_140029344 < 4) {
      local_res8 = local_res8 & 0xffffff00;
      *(ulonglong *)(&DAT_140029324 + (ulonglong)DAT_140029344 * 8) = CONCAT44(3,local_res8);
      DAT_140029344 = DAT_140029344 + 1;
      if (DAT_140029344 < 4) {
        local_res8._1_3_ = SUB43(uVar1,1);
        local_res8 = CONCAT31(local_res8._1_3_,1);
        *(ulonglong *)(&DAT_140029324 + (ulonglong)DAT_140029344 * 8) = CONCAT44(1,local_res8);
        DAT_140029344 = DAT_140029344 + 1;
      }
    }
    DAT_140029350 = 0xd;
    if (DAT_140029374 < 4) {
      local_res8 = CONCAT31(local_res8._1_3_,4);
      *(ulonglong *)(&DAT_140029354 + (ulonglong)DAT_140029374 * 8) = CONCAT44(2,local_res8);
      DAT_140029374 = DAT_140029374 + 1;
      if (DAT_140029374 < 4) {
        local_res8 = CONCAT31(local_res8._1_3_,5);
        *(ulonglong *)(&DAT_140029354 + (ulonglong)DAT_140029374 * 8) = CONCAT44(1,local_res8);
        DAT_140029374 = DAT_140029374 + 1;
        if (DAT_140029374 < 4) {
          local_res8 = CONCAT31(local_res8._1_3_,10);
          *(ulonglong *)(&DAT_140029354 + (ulonglong)DAT_140029374 * 8) = CONCAT44(1,local_res8);
          DAT_140029374 = DAT_140029374 + 1;
        }
      }
    }
    DAT_140029380 = 0x14;
    if (DAT_1400293a4 < 4) {
      local_res8 = CONCAT31(local_res8._1_3_,0xc);
      *(ulonglong *)(&DAT_140029384 + (ulonglong)DAT_1400293a4 * 8) = CONCAT44(0xc,local_res8);
      DAT_1400293a4 = DAT_1400293a4 + 1;
      if (DAT_1400293a4 < 4) {
        local_res8 = CONCAT31(local_res8._1_3_,1);
        *(ulonglong *)(&DAT_140029384 + (ulonglong)DAT_1400293a4 * 8) = CONCAT44(3,local_res8);
        DAT_1400293a4 = DAT_1400293a4 + 1;
      }
    }
    DAT_1400293b0 = 0x15;
    if (DAT_1400293d4 < 4) {
      local_res8 = CONCAT31(local_res8._1_3_,0xc);
      *(ulonglong *)(&DAT_1400293b4 + (ulonglong)DAT_1400293d4 * 8) = CONCAT44(0x18,local_res8);
      DAT_1400293d4 = DAT_1400293d4 + 1;
      if (DAT_1400293d4 < 4) {
        local_res8 = CONCAT31(local_res8._1_3_,4);
        *(ulonglong *)(&DAT_1400293b4 + (ulonglong)DAT_1400293d4 * 8) = CONCAT44(2,local_res8);
        DAT_1400293d4 = DAT_1400293d4 + 1;
        if (DAT_1400293d4 < 4) {
          local_res8 = CONCAT31(local_res8._1_3_,1);
          *(ulonglong *)(&DAT_1400293b4 + (ulonglong)DAT_1400293d4 * 8) = CONCAT44(6,local_res8);
          DAT_1400293d4 = DAT_1400293d4 + 1;
        }
      }
    }
    uVar1 = local_res8;
    DAT_1400293e0 = 0xf;
    if (DAT_140029404 < 4) {
      local_res8 = local_res8 & 0xffffff00;
      *(ulonglong *)(&DAT_1400293e4 + (ulonglong)DAT_140029404 * 8) = CONCAT44(2,local_res8);
      DAT_140029404 = DAT_140029404 + 1;
      if (DAT_140029404 < 4) {
        local_res8._1_3_ = SUB43(uVar1,1);
        local_res8 = CONCAT31(local_res8._1_3_,3);
        *(ulonglong *)(&DAT_1400293e4 + (ulonglong)DAT_140029404 * 8) = CONCAT44(1,local_res8);
        DAT_140029404 = DAT_140029404 + 1;
      }
    }
    DAT_140029410 = 0x10;
    if (DAT_140029434 < 4) {
      local_res8 = local_res8 & 0xffffff00;
      *(ulonglong *)(&DAT_140029414 + (ulonglong)DAT_140029434 * 8) = CONCAT44(2,local_res8);
      DAT_140029434 = DAT_140029434 + 1;
    }
    uVar1 = local_res8;
    DAT_140029440 = 0x11;
    if (DAT_140029464 < 4) {
      local_res8 = local_res8 & 0xffffff00;
      *(ulonglong *)(&DAT_140029444 + (ulonglong)DAT_140029464 * 8) = CONCAT44(2,local_res8);
      DAT_140029464 = DAT_140029464 + 1;
      if (DAT_140029464 < 4) {
        local_res8._1_3_ = SUB43(uVar1,1);
        local_res8 = CONCAT31(local_res8._1_3_,3);
        *(ulonglong *)(&DAT_140029444 + (ulonglong)DAT_140029464 * 8) = CONCAT44(1,local_res8);
        DAT_140029464 = DAT_140029464 + 1;
      }
    }
    DAT_140029470 = 0x12;
    if (DAT_140029494 < 4) {
      local_res8 = local_res8 & 0xffffff00;
      *(ulonglong *)(&DAT_140029474 + (ulonglong)DAT_140029494 * 8) = CONCAT44(2,local_res8);
      DAT_140029494 = DAT_140029494 + 1;
    }
    DAT_1400294a0 = 0x13;
    if (DAT_1400294c4 < 4) {
      local_res8 = CONCAT31(local_res8._1_3_,4);
      *(ulonglong *)(&DAT_1400294a4 + (ulonglong)DAT_1400294c4 * 8) = CONCAT44(2,local_res8);
      DAT_1400294c4 = DAT_1400294c4 + 1;
      if (DAT_1400294c4 < 4) {
        local_res8 = CONCAT31(local_res8._1_3_,6);
        *(ulonglong *)(&DAT_1400294a4 + (ulonglong)DAT_1400294c4 * 8) = CONCAT44(1,local_res8);
        DAT_1400294c4 = DAT_1400294c4 + 1;
      }
    }
    local_res8 = CONCAT31(local_res8._1_3_,0xc);
    (&DAT_1400294d0)[DAT_1400294f0] = CONCAT44(4,local_res8);
    DAT_1400294f0 = DAT_1400294f0 + 1;
    DAT_14004a9e8 = 1;
  }
  return;
}


// ===== FUN_14000ce30 @ 14000ce30 size=1232

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14000ce30(void)

{
  byte bVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong lVar4;
  ushort uVar5;
  ulonglong uVar6;
  longlong lVar7;
  byte *pbVar8;
  uint uVar9;
  byte *pbVar11;
  undefined1 *puVar12;
  ulonglong uVar13;
  uint *puVar14;
  byte local_198 [4];
  byte local_194;
  byte local_193;
  byte local_192;
  byte local_191;
  byte local_190;
  byte local_18f;
  byte local_18e;
  byte local_18d;
  byte local_18c;
  byte local_18b;
  byte local_18a;
  byte local_189;
  byte local_188;
  byte local_187;
  byte local_186;
  byte local_185;
  byte local_184;
  byte local_183;
  byte local_182;
  byte local_181;
  byte local_180;
  byte local_17f;
  byte local_17e;
  byte local_17d;
  byte local_17c;
  byte local_17b;
  uint local_178 [4];
  int local_168;
  int local_164;
  int local_160;
  int local_15c;
  int local_158;
  int local_154;
  int local_150;
  int local_14c;
  int local_148;
  int local_144;
  int local_140;
  int local_13c;
  int local_138;
  byte local_128 [144];
  undefined1 local_98 [112];
  undefined1 local_28 [24];
  undefined1 local_10 [8];
  ulonglong uVar10;
  
  pbVar8 = local_198;
  uVar13 = 0;
  uVar10 = uVar13;
  puVar14 = &DAT_140029b00;
  do {
    uVar6 = (ulonglong)((uint)(uVar10 >> 1) ^ 0xedb88320);
    if ((uVar10 & 1) == 0) {
      uVar6 = uVar10 >> 1;
    }
    uVar3 = (ulonglong)((uint)(uVar6 >> 1) ^ 0xedb88320);
    if ((uVar6 & 1) == 0) {
      uVar3 = uVar6 >> 1;
    }
    uVar6 = (ulonglong)((uint)(uVar3 >> 1) ^ 0xedb88320);
    if ((uVar3 & 1) == 0) {
      uVar6 = uVar3 >> 1;
    }
    uVar3 = (ulonglong)((uint)(uVar6 >> 1) ^ 0xedb88320);
    if ((uVar6 & 1) == 0) {
      uVar3 = uVar6 >> 1;
    }
    uVar6 = (ulonglong)((uint)(uVar3 >> 1) ^ 0xedb88320);
    if ((uVar3 & 1) == 0) {
      uVar6 = uVar3 >> 1;
    }
    uVar3 = (ulonglong)((uint)(uVar6 >> 1) ^ 0xedb88320);
    if ((uVar6 & 1) == 0) {
      uVar3 = uVar6 >> 1;
    }
    uVar6 = (ulonglong)((uint)(uVar3 >> 1) ^ 0xedb88320);
    if ((uVar3 & 1) == 0) {
      uVar6 = uVar3 >> 1;
    }
    uVar9 = (uint)(uVar6 >> 1);
    uVar2 = uVar9 ^ 0xedb88320;
    if ((uVar6 & 1) == 0) {
      uVar2 = uVar9;
    }
    uVar9 = (int)uVar10 + 1;
    uVar10 = (ulonglong)uVar9;
    *puVar14 = uVar2;
    puVar14 = puVar14 + 1;
  } while (uVar9 < 0x100);
  pbVar11 = local_128;
  for (lVar4 = 0x90; lVar4 != 0; lVar4 = lVar4 + -1) {
    *pbVar11 = 8;
    pbVar11 = pbVar11 + 1;
  }
  lVar7 = 0x30;
  puVar12 = local_98;
  for (lVar4 = 0x70; lVar4 != 0; lVar4 = lVar4 + -1) {
    *puVar12 = 9;
    puVar12 = puVar12 + 1;
  }
  puVar12 = local_28;
  for (lVar4 = 0x18; lVar4 != 0; lVar4 = lVar4 + -1) {
    *puVar12 = 7;
    puVar12 = puVar12 + 1;
  }
  puVar12 = local_10;
  for (lVar4 = 8; lVar4 != 0; lVar4 = lVar4 + -1) {
    *puVar12 = 8;
    puVar12 = puVar12 + 1;
  }
  puVar12 = &DAT_140029f00;
  for (lVar4 = 0x20; lVar4 != 0; lVar4 = lVar4 + -1) {
    *puVar12 = 0;
    puVar12 = puVar12 + 1;
  }
  pbVar11 = local_128 + 1;
  do {
    *(short *)(&DAT_140029f00 + (ulonglong)pbVar11[-1] * 2) =
         *(short *)(&DAT_140029f00 + (ulonglong)pbVar11[-1] * 2) + 1;
    *(short *)(&DAT_140029f00 + (ulonglong)*pbVar11 * 2) =
         *(short *)(&DAT_140029f00 + (ulonglong)*pbVar11 * 2) + 1;
    *(short *)(&DAT_140029f00 + (ulonglong)pbVar11[1] * 2) =
         *(short *)(&DAT_140029f00 + (ulonglong)pbVar11[1] * 2) + 1;
    *(short *)(&DAT_140029f00 + (ulonglong)pbVar11[2] * 2) =
         *(short *)(&DAT_140029f00 + (ulonglong)pbVar11[2] * 2) + 1;
    *(short *)(&DAT_140029f00 + (ulonglong)pbVar11[3] * 2) =
         *(short *)(&DAT_140029f00 + (ulonglong)pbVar11[3] * 2) + 1;
    *(short *)(&DAT_140029f00 + (ulonglong)pbVar11[4] * 2) =
         *(short *)(&DAT_140029f00 + (ulonglong)pbVar11[4] * 2) + 1;
    lVar7 = lVar7 + -1;
    pbVar11 = pbVar11 + 6;
  } while (lVar7 != 0);
  pbVar11 = local_128;
  local_178[3] = (uint)DAT_140029f04 + (uint)DAT_140029f02;
  local_178[2] = (uint)DAT_140029f02;
  local_168 = DAT_140029f06 + local_178[3];
  uVar5 = 0;
  _DAT_140029f00 = 0;
  local_164 = (uint)DAT_140029f08 + local_168;
  local_160 = (uint)DAT_140029f0a + local_164;
  local_15c = (uint)DAT_140029f0c + local_160;
  local_158 = (uint)DAT_140029f0e + local_15c;
  local_154 = (uint)DAT_140029f10 + local_158;
  local_150 = (uint)DAT_140029f12 + local_154;
  local_14c = (uint)DAT_140029f14 + local_150;
  local_148 = (uint)DAT_140029f16 + local_14c;
  local_144 = (uint)DAT_140029f18 + local_148;
  local_140 = (uint)DAT_140029f1a + local_144;
  local_13c = (uint)DAT_140029f1c + local_140;
  local_178[0] = 0;
  local_178[1] = 0;
  local_138 = (uint)DAT_140029f1e + local_13c;
  do {
    bVar1 = *pbVar11;
    if (bVar1 != 0) {
      uVar9 = local_178[bVar1];
      *(ushort *)(&DAT_140029f20 + (ulonglong)uVar9 * 2) = uVar5;
      local_178[bVar1] = uVar9 + 1;
    }
    uVar5 = uVar5 + 1;
    pbVar11 = pbVar11 + 1;
  } while (uVar5 < 0x120);
  local_178[0] = 0;
  local_178[1] = 0;
  pbVar11 = local_198;
  for (lVar4 = 0x1e; lVar4 != 0; lVar4 = lVar4 + -1) {
    *pbVar11 = 5;
    pbVar11 = pbVar11 + 1;
  }
  puVar12 = &DAT_14002a3a0;
  for (lVar4 = 0x20; lVar4 != 0; lVar4 = lVar4 + -1) {
    *puVar12 = 0;
    puVar12 = puVar12 + 1;
  }
  *(short *)(&DAT_14002a3a0 + (ulonglong)local_198[0] * 2) =
       *(short *)(&DAT_14002a3a0 + (ulonglong)local_198[0] * 2) + 1;
  *(short *)(&DAT_14002a3a0 + (ulonglong)local_198[1] * 2) =
       *(short *)(&DAT_14002a3a0 + (ulonglong)local_198[1] * 2) + 1;
  *(short *)(&DAT_14002a3a0 + (ulonglong)local_198[2] * 2) =
       *(short *)(&DAT_14002a3a0 + (ulonglong)local_198[2] * 2) + 1;
  *(short *)(&DAT_14002a3a0 + (ulonglong)local_198[3] * 2) =
       *(short *)(&DAT_14002a3a0 + (ulonglong)local_198[3] * 2) + 1;
  *(short *)(&DAT_14002a3a0 + (ulonglong)local_194 * 2) =
       *(short *)(&DAT_14002a3a0 + (ulonglong)local_194 * 2) + 1;
  *(short *)(&DAT_14002a3a0 + (ulonglong)local_193 * 2) =
       *(short *)(&DAT_14002a3a0 + (ulonglong)local_193 * 2) + 1;
  *(short *)(&DAT_14002a3a0 + (ulonglong)local_192 * 2) =
       *(short *)(&DAT_14002a3a0 + (ulonglong)local_192 * 2) + 1;
  *(short *)(&DAT_14002a3a0 + (ulonglong)local_191 * 2) =
       *(short *)(&DAT_14002a3a0 + (ulonglong)local_191 * 2) + 1;
  *(short *)(&DAT_14002a3a0 + (ulonglong)local_190 * 2) =
       *(short *)(&DAT_14002a3a0 + (ulonglong)local_190 * 2) + 1;
  *(short *)(&DAT_14002a3a0 + (ulonglong)local_18f * 2) =
       *(short *)(&DAT_14002a3a0 + (ulonglong)local_18f * 2) + 1;
  *(short *)(&DAT_14002a3a0 + (ulonglong)local_18e * 2) =
       *(short *)(&DAT_14002a3a0 + (ulonglong)local_18e * 2) + 1;
  *(short *)(&DAT_14002a3a0 + (ulonglong)local_18d * 2) =
       *(short *)(&DAT_14002a3a0 + (ulonglong)local_18d * 2) + 1;
  *(short *)(&DAT_14002a3a0 + (ulonglong)local_18c * 2) =
       *(short *)(&DAT_14002a3a0 + (ulonglong)local_18c * 2) + 1;
  *(short *)(&DAT_14002a3a0 + (ulonglong)local_18b * 2) =
       *(short *)(&DAT_14002a3a0 + (ulonglong)local_18b * 2) + 1;
  *(short *)(&DAT_14002a3a0 + (ulonglong)local_18a * 2) =
       *(short *)(&DAT_14002a3a0 + (ulonglong)local_18a * 2) + 1;
  *(short *)(&DAT_14002a3a0 + (ulonglong)local_189 * 2) =
       *(short *)(&DAT_14002a3a0 + (ulonglong)local_189 * 2) + 1;
  *(short *)(&DAT_14002a3a0 + (ulonglong)local_188 * 2) =
       *(short *)(&DAT_14002a3a0 + (ulonglong)local_188 * 2) + 1;
  *(short *)(&DAT_14002a3a0 + (ulonglong)local_187 * 2) =
       *(short *)(&DAT_14002a3a0 + (ulonglong)local_187 * 2) + 1;
  *(short *)(&DAT_14002a3a0 + (ulonglong)local_186 * 2) =
       *(short *)(&DAT_14002a3a0 + (ulonglong)local_186 * 2) + 1;
  *(short *)(&DAT_14002a3a0 + (ulonglong)local_185 * 2) =
       *(short *)(&DAT_14002a3a0 + (ulonglong)local_185 * 2) + 1;
  *(short *)(&DAT_14002a3a0 + (ulonglong)local_184 * 2) =
       *(short *)(&DAT_14002a3a0 + (ulonglong)local_184 * 2) + 1;
  *(short *)(&DAT_14002a3a0 + (ulonglong)local_183 * 2) =
       *(short *)(&DAT_14002a3a0 + (ulonglong)local_183 * 2) + 1;
  *(short *)(&DAT_14002a3a0 + (ulonglong)local_182 * 2) =
       *(short *)(&DAT_14002a3a0 + (ulonglong)local_182 * 2) + 1;
  *(short *)(&DAT_14002a3a0 + (ulonglong)local_181 * 2) =
       *(short *)(&DAT_14002a3a0 + (ulonglong)local_181 * 2) + 1;
  *(short *)(&DAT_14002a3a0 + (ulonglong)local_180 * 2) =
       *(short *)(&DAT_14002a3a0 + (ulonglong)local_180 * 2) + 1;
  *(short *)(&DAT_14002a3a0 + (ulonglong)local_17f * 2) =
       *(short *)(&DAT_14002a3a0 + (ulonglong)local_17f * 2) + 1;
  *(short *)(&DAT_14002a3a0 + (ulonglong)local_17e * 2) =
       *(short *)(&DAT_14002a3a0 + (ulonglong)local_17e * 2) + 1;
  *(short *)(&DAT_14002a3a0 + (ulonglong)local_17d * 2) =
       *(short *)(&DAT_14002a3a0 + (ulonglong)local_17d * 2) + 1;
  *(short *)(&DAT_14002a3a0 + (ulonglong)local_17c * 2) =
       *(short *)(&DAT_14002a3a0 + (ulonglong)local_17c * 2) + 1;
  *(short *)(&DAT_14002a3a0 + (ulonglong)local_17b * 2) =
       *(short *)(&DAT_14002a3a0 + (ulonglong)local_17b * 2) + 1;
  local_178[3] = (uint)DAT_14002a3a4 + (uint)DAT_14002a3a2;
  local_178[2] = (uint)DAT_14002a3a2;
  local_168 = DAT_14002a3a6 + local_178[3];
  local_164 = (uint)DAT_14002a3a8 + local_168;
  _DAT_14002a3a0 = 0;
  local_160 = (uint)DAT_14002a3aa + local_164;
  local_15c = (uint)DAT_14002a3ac + local_160;
  local_158 = (uint)DAT_14002a3ae + local_15c;
  local_154 = (uint)DAT_14002a3b0 + local_158;
  local_150 = (uint)DAT_14002a3b2 + local_154;
  local_14c = (uint)DAT_14002a3b4 + local_150;
  local_148 = (uint)DAT_14002a3b6 + local_14c;
  local_144 = (uint)DAT_14002a3b8 + local_148;
  local_140 = (uint)DAT_14002a3ba + local_144;
  local_13c = (uint)DAT_14002a3bc + local_140;
  local_138 = (uint)DAT_14002a3be + local_13c;
  do {
    bVar1 = *pbVar8;
    if (bVar1 != 0) {
      uVar9 = local_178[bVar1];
      *(short *)(&DAT_14002a3c0 + (ulonglong)uVar9 * 2) = (short)uVar13;
      local_178[bVar1] = uVar9 + 1;
    }
    uVar5 = (short)uVar13 + 1;
    uVar13 = (ulonglong)uVar5;
    pbVar8 = pbVar8 + 1;
  } while (uVar5 < 0x1e);
  return;
}


// ===== FUN_14000d300 @ 14000d300 size=1482

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14000d300(undefined8 param_1)

{
  char cVar1;
  code *pcVar2;
  int iVar3;
  INT_PTR IVar4;
  undefined8 *puVar5;
  char *pcVar6;
  HANDLE hHeap;
  longlong lVar7;
  longlong lVar8;
  uint uVar9;
  ulonglong uVar10;
  int *piVar11;
  undefined1 *puVar12;
  ulonglong uVar13;
  undefined4 local_res8 [4];
  
  DAT_14002a9c0 = param_1;
  _DAT_14002a918 = LoadLibraryA("ole32.dll");
  if (_DAT_14002a918 == (HMODULE)0x0) {
    FUN_140012c60("ole32.dll");
    FUN_140012cd0(" failed to load, exiting");
                    /* WARNING: Subroutine does not return */
    ExitProcess(1);
  }
  DAT_14002a928 = GetProcAddress(_DAT_14002a918,"CoInitialize");
  if (DAT_14002a928 == (FARPROC)0x0) {
    FUN_140012c60("CoInitialize");
    FUN_140012cd0(" failed to load, exiting");
                    /* WARNING: Subroutine does not return */
    ExitProcess(1);
  }
  DAT_14002a910 = LoadLibraryA("combase.dll");
  if (DAT_14002a910 == (HMODULE)0x0) {
    FUN_140012c60("combase.dll");
    FUN_140012cd0(" failed to load, exiting");
                    /* WARNING: Subroutine does not return */
    ExitProcess(1);
  }
  DAT_14002a930 = GetProcAddress(DAT_14002a910,"CoCreateInstance");
  if (DAT_14002a930 == (FARPROC)0x0) {
    FUN_140012c60("CoCreateInstance");
    FUN_140012cd0(" failed to load, exiting");
                    /* WARNING: Subroutine does not return */
    ExitProcess(1);
  }
  _DAT_14002a938 = GetProcAddress(DAT_14002a910,"CoTaskMemFree");
  if (_DAT_14002a938 == (FARPROC)0x0) {
    FUN_140012c60("CoTaskMemFree");
    FUN_140012cd0(" failed to load, exiting");
                    /* WARNING: Subroutine does not return */
    ExitProcess(1);
  }
  _DAT_14002a920 = LoadLibraryA("avrt.dll");
  if (_DAT_14002a920 == (HMODULE)0x0) {
    FUN_140012c60("avrt.dll");
    FUN_140012cd0(" failed to load, exiting");
                    /* WARNING: Subroutine does not return */
    ExitProcess(1);
  }
  DAT_14002a950 = GetProcAddress(_DAT_14002a920,"AvSetMmThreadCharacteristicsA");
  if (DAT_14002a950 == (FARPROC)0x0) {
    FUN_140012c60("AvSetMmThreadCharacteristicsA");
    FUN_140012cd0(" failed to load, exiting");
                    /* WARNING: Subroutine does not return */
    ExitProcess(1);
  }
  IVar4 = (*DAT_14002a928)(0);
  if ((int)IVar4 != 0) {
    FUN_14001f8e0();
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  IVar4 = (*DAT_14002a930)(&DAT_1400248b0,0,0x17,&DAT_1400248c0,&DAT_14002a958);
  if ((int)IVar4 != 0) {
    FUN_14001f8e0();
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  iVar3 = (**(code **)(*DAT_14002a958 + 0x20))(DAT_14002a958,0,0,&DAT_14002a960);
  if (iVar3 != 0) {
    FUN_14001f8e0();
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  iVar3 = (**(code **)(*DAT_14002a960 + 0x18))(DAT_14002a960,&DAT_1400248d0,0x17,0,&DAT_14002a968);
  if (iVar3 != 0) {
    FUN_14001f8e0();
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  uVar10 = 0;
  piVar11 = &DAT_140029248;
  uVar13 = uVar10;
  while( true ) {
    DAT_14002a978 = *piVar11;
    lVar8 = (longlong)DAT_14002a978;
    puVar12 = &DAT_14002a980;
    for (lVar7 = 0x28; lVar7 != 0; lVar7 = lVar7 + -1) {
      *puVar12 = 0;
      puVar12 = puVar12 + 1;
    }
    DAT_14002a984 = *(int *)(&DAT_140023fa0 + lVar8 * 4);
    _DAT_14002a992 = (ushort)*(int *)(&DAT_140023f20 + lVar8 * 4);
    _DAT_14002a980 = 0x2fffe;
    _DAT_14002a98e = _DAT_14002a992;
    if (*(int *)(&DAT_140023f20 + lVar8 * 4) == 0x18) {
      _DAT_14002a98e = 0x20;
    }
    _DAT_14002a990 = 0x16;
    _DAT_14002a994 = 3;
    _DAT_14002a98c = 1 << (-(char)LZCOUNT((uint)(_DAT_14002a98e >> 3) * 2 + -1) & 0x1fU);
    puVar5 = (undefined8 *)&DAT_1400248a0;
    _DAT_14002a988 = (uint)_DAT_14002a98c * DAT_14002a984;
    if (*(int *)(&DAT_140023f60 + lVar8 * 4) != 0) {
      puVar5 = (undefined8 *)&DAT_140024890;
    }
    _DAT_14002a998 = *puVar5;
    uRam000000014002a9a0 = puVar5[1];
    iVar3 = (**(code **)(*DAT_14002a968 + 0x38))(DAT_14002a968,0,&DAT_14002a980);
    if (iVar3 == 0) break;
    uVar9 = (int)uVar13 + 1;
    uVar13 = (ulonglong)uVar9;
    piVar11 = piVar11 + 1;
    if (0xe < uVar9) {
      FUN_140012cd0("Failed to find suitable format for audio engine, exiting");
                    /* WARNING: Subroutine does not return */
      ExitProcess(1);
    }
  }
  pcVar6 = "Using audio format ";
  uVar13 = uVar10;
  do {
    pcVar6 = pcVar6 + 1;
    uVar13 = uVar13 + 1;
  } while (*pcVar6 != '\0');
  WriteFile(DAT_1400299a0,"Using audio format ",(DWORD)uVar13,(LPDWORD)0x0,(LPOVERLAPPED)0x0);
  pcVar6 = (&PTR_s_AUDIO_FORMAT_8BIT_INTEGER_44_1_K_140029150)[DAT_14002a978];
  uVar13 = uVar10;
  if (pcVar6 != (char *)0x0) {
    cVar1 = *pcVar6;
    while (cVar1 != '\0') {
      uVar13 = uVar13 + 1;
      cVar1 = pcVar6[uVar13];
    }
  }
  WriteFile(DAT_1400299a0,pcVar6,(DWORD)uVar13,(LPDWORD)0x0,(LPOVERLAPPED)0x0);
  do {
    uVar13 = uVar10 + 1;
    pcVar6 = &DAT_140024265 + uVar10;
    uVar10 = uVar13;
  } while (*pcVar6 != '\0');
  WriteFile(DAT_1400299a0,&DAT_140024264,(DWORD)uVar13,(LPDWORD)0x0,(LPOVERLAPPED)0x0);
  local_res8[0] = 0;
  (*DAT_14002a950)("Pro Audio",local_res8);
  _DAT_14002a9a8 = 200000;
  iVar3 = (**(code **)(*DAT_14002a968 + 0x18))(DAT_14002a968,0,0,200000,0,&DAT_14002a980,0);
  if (iVar3 != 0) {
    FUN_14001f8e0();
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  iVar3 = (**(code **)(*DAT_14002a968 + 0x20))(DAT_14002a968,&DAT_14002a97c);
  if (iVar3 != 0) {
    FUN_14001f8e0();
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  iVar3 = (**(code **)(*DAT_14002a968 + 0x70))(DAT_14002a968,&DAT_1400248e0,&DAT_14002a970);
  if (iVar3 != 0) {
    FUN_14001f8e0();
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  uVar9 = (_DAT_14002a980 >> 0x10) * DAT_14002a97c;
  hHeap = GetProcessHeap();
  DAT_14002a9b0 = HeapAlloc(hHeap,0,(ulonglong)uVar9 << 2);
  if (DAT_14002a9b0 == (LPVOID)0x0) {
    FUN_140002010("Failed to alloc audio buffer");
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  iVar3 = (**(code **)(*DAT_14002a968 + 0x50))();
  if (iVar3 != 0) {
    FUN_14001f8e0();
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  DAT_14002a9b8 = CreateWaitableTimerA((LPSECURITY_ATTRIBUTES)0x0,1,(LPCSTR)0x0);
  return;
}


// ===== FUN_14000d8e0 @ 14000d8e0 size=109

undefined8 FUN_14000d8e0(ulonglong *param_1)

{
  float fVar1;
  float fVar2;
  undefined1 auVar3 [16];
  
  if (((*(char *)((longlong)param_1 + 0x34) == '\0') && ((int)param_1[0xb] == 0)) &&
     (auVar3._8_8_ = 0, auVar3._0_8_ = *param_1, auVar3 = vshufps_avx(auVar3,auVar3,0x55),
     fVar1 = (float)*param_1 - ((float)(param_1[2] & 0xffffffff) + *(float *)(param_1 + 3)),
     fVar2 = auVar3._0_4_ - ((float)(param_1[2] >> 0x20) + *(float *)((longlong)param_1 + 0x1c)),
     fVar2 * fVar2 + fVar1 * fVar1 <= (9.99999975e-05f))) {
    return 1;
  }
  return 0;
}


// ===== FUN_14000d950 @ 14000d950 size=1032

void FUN_14000d950(int param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  undefined8 uVar4;
  undefined4 *puVar5;
  char cVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  tagPOINT local_res18 [2];
  
  uVar7 = 0;
  if (param_1 == 0x11) {
    DAT_140029980 = (uint)(param_2 == 1);
  }
  if (param_2 != 1) {
    return;
  }
  if (param_1 - 0x31U < 9) {
    uVar2 = param_1 - 0x31;
    if (uVar2 < 0xc) {
      if ((int)uVar2 < 0) {
        return;
      }
      goto LAB_14000d9be;
    }
  }
  else {
    if (param_1 == 0x30) {
      uVar2 = 9;
LAB_14000d9be:
      if ((&DAT_140029058)[(longlong)(int)uVar2 * 2] == '\x01') {
        FUN_140005040();
        return;
      }
      cVar6 = (&DAT_140029059)[(longlong)(int)uVar2 * 2];
      DAT_140029024 = 0xe;
      cVar1 = cVar6;
      if (DAT_14002962c == cVar6) {
        cVar1 = '\0';
      }
      DAT_140029660 = 0;
      DAT_14002962c = cVar1;
      pcVar3 = &DAT_140029028;
      do {
        if (*pcVar3 == cVar6) {
          DAT_140029660 = 0;
          DAT_140029658 = (int)uVar7;
          DAT_140029024 = 0xe;
          DAT_140029664 = 0;
          return;
        }
        uVar2 = (int)uVar7 + 1;
        uVar7 = (ulonglong)uVar2;
        pcVar3 = pcVar3 + 1;
      } while (uVar2 < 0x16);
      DAT_140029664 = 0;
      return;
    }
    if (param_1 == 0xbd) {
      uVar2 = 10;
      goto LAB_14000d9be;
    }
    if (param_1 == 0xbb) {
      uVar2 = 0xb;
      goto LAB_14000d9be;
    }
  }
  if (param_1 == 0x52) {
    if (DAT_140029714 != '\0') {
      FUN_14000b290(DAT_140029638);
      FUN_1400056b0(DAT_140029638);
      DAT_1400296ec = 0;
      pcVar3 = &DAT_140029028;
      DAT_1400296f8 = 0;
      DAT_1400296fc = 0;
      DAT_1400298a8 = 0;
      DAT_140029054 = 0xffffffff;
      DAT_1400298b8 = 0;
      DAT_14002962c = 0;
      DAT_140029660 = 0;
      do {
        if (*pcVar3 == '\0') {
          DAT_140029024 = 0xe;
          DAT_140029054 = 0xffffffff;
          DAT_14002962c = 0;
          DAT_140029658 = (int)uVar7;
          DAT_14002965c = 0;
          DAT_140029660 = 0;
          DAT_140029664 = 0;
          DAT_1400296ec = 0;
          DAT_1400296f8 = 0;
          DAT_1400296fc = 0;
          DAT_1400298a8 = 0;
          DAT_1400298ac = 0;
          DAT_1400298b8 = 0;
          DAT_140029af0 = 0;
          DAT_14002a890 = 0;
          return;
        }
        uVar2 = (int)uVar7 + 1;
        uVar7 = (ulonglong)uVar2;
        pcVar3 = pcVar3 + 1;
      } while (uVar2 < 0x16);
      DAT_140029024 = 0xe;
      DAT_140029664 = 0;
      DAT_14002965c = 0;
      DAT_140029af0 = 0;
      DAT_14002a890 = 0;
      DAT_1400298ac = 0;
      return;
    }
    if ((((DAT_14002962c != '\n') && (DAT_14002962c != '\v')) && (DAT_14002962c != '\f')) &&
       ((DAT_14002962c != '\r' && (DAT_14002962c != '\x12')))) {
      return;
    }
    if (DAT_140029710 != '\0') {
      if (DAT_140029664 == 0) {
        DAT_140029664 = 3;
        return;
      }
      if (DAT_140029664 == 1) {
        DAT_140029664 = 0;
        return;
      }
      if (DAT_140029664 == 2) {
        DAT_140029664 = 1;
        return;
      }
      DAT_140029664 = 2;
      return;
    }
    if (DAT_140029664 == 0) {
      DAT_140029664 = 1;
      return;
    }
    if (DAT_140029664 != 1) {
      if (DAT_140029664 == 2) {
        DAT_140029664 = 3;
        return;
      }
      DAT_140029664 = 0;
      return;
    }
    DAT_140029664 = 2;
    return;
  }
  if (param_1 == 9) {
    DAT_14002a890 = 0;
    if (DAT_140029714 == '\0') {
      if (DAT_1400298ac != 0) {
        DAT_1400296f8 = 0;
        DAT_1400296fc = 0;
        DAT_1400298a8 = 0;
        DAT_1400298ac = 0;
        DAT_14002a890 = 0;
        return;
      }
      DAT_1400298ac = 1;
      DAT_140029af0 = 0;
    }
    else {
      DAT_1400298ac = 0;
      if (DAT_14002965c == 0) {
        DAT_14002965c = 1;
        DAT_1400296f8 = 0;
        DAT_1400296fc = 0;
        DAT_1400298a8 = 0;
        DAT_1400298ac = 0;
        DAT_140029af0 = 0;
        DAT_14002a890 = 0;
        return;
      }
    }
    DAT_14002965c = 0;
    DAT_1400296fc = 0;
    DAT_1400296f8 = 0;
    DAT_1400298a8 = 0;
    return;
  }
  if (param_1 == 0x45) {
    if (DAT_140029714 == '\0') {
      return;
    }
    uVar8 = (ulonglong)DAT_140029a30;
    if (DAT_140029a28 + DAT_140029a30 < DAT_140029a28) {
      uVar8 = uVar7;
    }
    puVar5 = DAT_140029a28;
    if (uVar8 == 0) {
      return;
    }
    for (; uVar8 != 0; uVar8 = uVar8 - 1) {
      *puVar5 = 0x32;
      puVar5 = puVar5 + 1;
    }
    return;
  }
  if (param_1 == 0x1b) {
    DAT_14002965c = 0;
    pcVar3 = &DAT_140029028;
    DAT_140029af0 = 0;
    DAT_14002a890 = 0;
    DAT_1400298ac = 0;
    DAT_1400296f8 = 0;
    DAT_14002962c = 0;
    DAT_140029660 = 0;
    do {
      if (*pcVar3 == '\0') {
        DAT_140029024 = 0xe;
        DAT_14002962c = 0;
        DAT_140029658 = (int)uVar7;
        DAT_14002965c = 0;
        DAT_140029660 = 0;
        DAT_140029664 = 0;
        DAT_1400296f8 = 0;
        DAT_1400298a8 = 0;
        DAT_1400298ac = 0;
        DAT_140029af0 = 0;
        DAT_14002a890 = 0;
        return;
      }
      uVar2 = (int)uVar7 + 1;
      uVar7 = (ulonglong)uVar2;
      pcVar3 = pcVar3 + 1;
    } while (uVar2 < 0x16);
    DAT_140029024 = 0xe;
    DAT_140029664 = 0;
    DAT_1400298a8 = 0;
    return;
  }
  if (param_1 != 0x51) {
    return;
  }
  local_res18[0].x = 0;
  local_res18[0].y = 0;
  uVar4 = FUN_140011060(local_res18);
  if ((int)uVar4 == 0) {
    return;
  }
  puVar5 = (undefined4 *)FUN_140009990((longlong)local_res18[0],DAT_140029980);
  if ((puVar5 == (undefined4 *)0x0) || (*(longlong *)(puVar5 + 2) == 0)) {
switchD_14000dce7_default:
    cVar6 = '\0';
  }
  else {
    switch(*puVar5) {
    case 1:
      cVar6 = '\n';
      break;
    case 2:
      cVar6 = '\v';
      break;
    case 3:
      cVar6 = '\f';
      break;
    case 4:
      cVar6 = '\r';
      break;
    case 5:
      cVar6 = '\x0e';
      break;
    case 6:
      cVar6 = '\x0f';
      break;
    case 7:
      cVar6 = '\x10';
      break;
    case 8:
      cVar6 = '\x11';
      break;
    case 9:
      cVar6 = '\x12';
      break;
    case 10:
      cVar6 = '\x13';
      break;
    default:
      goto switchD_14000dce7_default;
    }
  }
  cVar1 = cVar6;
  if (DAT_14002962c == cVar6) {
    cVar1 = '\0';
  }
  DAT_140029660 = 0;
  DAT_14002962c = cVar1;
  pcVar3 = &DAT_140029028;
  DAT_140029664 = 0;
  do {
    if (*pcVar3 == cVar6) {
      DAT_140029664 = 0;
      DAT_140029660 = 0;
      DAT_140029658 = (int)uVar7;
      return;
    }
    uVar2 = (int)uVar7 + 1;
    uVar7 = (ulonglong)uVar2;
    pcVar3 = pcVar3 + 1;
  } while (uVar2 < 0x16);
  return;
}


// ===== FUN_14000dd80 @ 14000dd80 size=8179

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14000dd80(void)

{
  undefined8 uVar1;
  undefined1 (*pauVar2) [16];
  ulonglong uVar3;
  longlong lVar4;
  undefined8 *puVar5;
  char *local_58;
  undefined8 local_50;
  longlong local_48 [2];
  longlong local_38 [2];
  undefined1 local_28 [28];
  undefined4 local_c;
  
  local_50 = 0xb;
  local_58 = "tileset.png";
  pauVar2 = FUN_1400101e0((undefined1 (*) [16])local_38,&local_58);
  uVar3 = 0;
  _DAT_140029890 = *(undefined8 *)*pauVar2;
  uRam0000000140029898 = *(undefined8 *)(*pauVar2 + 8);
  _DAT_1400eaa3c = local_c;
  _DAT_1400eaa5c = local_c;
  _DAT_1400eaa7c = local_c;
  _DAT_1400eaa9c = local_c;
  _DAT_1400eaabc = local_c;
  _DAT_1400eaadc = local_c;
  _DAT_1400eaafc = local_c;
  _DAT_1400eab1c = local_c;
  _DAT_1400eab3c = local_c;
  _DAT_1400eaa20 = &DAT_140029890;
  _DAT_1400eaa28 = 0;
  DAT_1400eaa30 = 0x10;
  DAT_1400eaa34 = 0x10;
  _DAT_1400eaa38 = 1;
  _DAT_1400eaa40 = &DAT_140029890;
  _DAT_1400eaa48 = 0x10;
  _DAT_1400eaa50 = 0x10;
  _DAT_1400eaa54 = 0x10;
  _DAT_1400eaa58 = 1;
  _DAT_1400eaa60 = &DAT_140029890;
  _DAT_1400eaa68 = 0xf0;
  _DAT_1400eaa6c = 0x20;
  _DAT_1400eaa70 = 0x10;
  _DAT_1400eaa74 = 0x10;
  _DAT_1400eaa78 = 4;
  _DAT_1400eaa80 = &DAT_140029890;
  _DAT_1400eaa88 = 0xf0;
  _DAT_1400eaa8c = 0x10;
  _DAT_1400eaa90 = 0x10;
  _DAT_1400eaa94 = 0x10;
  _DAT_1400eaa98 = 4;
  _DAT_1400eaaa0 = &DAT_140029890;
  _DAT_1400eaaa8 = 0xf0;
  _DAT_1400eaab0 = 0x10;
  _DAT_1400eaab4 = 0x10;
  _DAT_1400eaab8 = 4;
  _DAT_1400eaac0 = &DAT_140029890;
  _DAT_1400eaac8 = 0;
  _DAT_1400eaacc = 0x10;
  _DAT_1400eaad0 = 0x10;
  _DAT_1400eaad4 = 0x10;
  _DAT_1400eaad8 = 1;
  _DAT_1400eaae0 = &DAT_140029890;
  _DAT_1400eaae8 = 0x10;
  _DAT_1400eaaec = 0x10;
  _DAT_1400eaaf0 = 0x10;
  _DAT_1400eaaf4 = 0x10;
  _DAT_1400eaaf8 = 1;
  _DAT_1400eab00 = &DAT_140029890;
  _DAT_1400eab08 = 0;
  _DAT_1400eab0c = 0x80;
  _DAT_1400eab10 = 0x10;
  _DAT_1400eab14 = 0x10;
  _DAT_1400eab18 = 2;
  _DAT_1400eab20 = &DAT_140029890;
  _DAT_1400eab28 = 0xb0;
  _DAT_1400eab2c = 0xd0;
  _DAT_1400eab30 = 0x10;
  _DAT_1400eab34 = 0x10;
  _DAT_1400eab38 = 1;
  _DAT_1400eab40 = &DAT_140029890;
  _DAT_1400eab48 = 0x30;
  _DAT_1400eab5c = local_c;
  _DAT_1400eab7c = local_c;
  _DAT_1400eab9c = local_c;
  _DAT_1400eabbc = local_c;
  _DAT_1400eabdc = local_c;
  _DAT_1400eabfc = local_c;
  _DAT_1400eac1c = local_c;
  _DAT_1400eac3c = local_c;
  _DAT_1400eac5c = local_c;
  _DAT_1400eac7c = local_c;
  _DAT_1400eab4c = 0x50;
  _DAT_1400eab50 = 0x10;
  _DAT_1400eab54 = 0x10;
  _DAT_1400eab58 = 2;
  _DAT_1400eab60 = &DAT_140029890;
  _DAT_1400eab68 = 0x10;
  _DAT_1400eab6c = 0x30;
  _DAT_1400eab70 = 0x10;
  _DAT_1400eab74 = 0x10;
  _DAT_1400eab78 = 1;
  _DAT_1400eab80 = &DAT_140029890;
  _DAT_1400eab88 = 0;
  _DAT_1400eab8c = 0x60;
  _DAT_1400eab90 = 0x20;
  _DAT_1400eab94 = 0x20;
  _DAT_1400eab98 = 1;
  _DAT_1400eaba0 = &DAT_140029890;
  _DAT_1400eaba8 = 0x10;
  _DAT_1400eabac = 0x20;
  DAT_1400eabb0 = 0x10;
  DAT_1400eabb4 = 0x10;
  DAT_1400eabb8 = 1;
  DAT_1400eabc0 = &DAT_140029890;
  DAT_1400eabc8 = 0;
  DAT_1400eabcc = 0x40;
  DAT_1400eabd0 = 0x20;
  DAT_1400eabd4 = 0x20;
  DAT_1400eabd8 = 1;
  _DAT_1400eabe0 = &DAT_140029890;
  _DAT_1400eabe8 = 0x30;
  _DAT_1400eabec = 0x60;
  DAT_1400eabf0 = 0x10;
  DAT_1400eabf4 = 0x10;
  DAT_1400eabf8 = 1;
  _DAT_1400eac00 = &DAT_140029890;
  _DAT_1400eac08 = 0x30;
  _DAT_1400eac0c = 0x70;
  DAT_1400eac10 = 0x10;
  DAT_1400eac14 = 0x10;
  DAT_1400eac18 = 1;
  _DAT_1400eac20 = &DAT_140029890;
  _DAT_1400eac28 = 0x20;
  _DAT_1400eac2c = 0x40;
  _DAT_1400eac30 = 0x10;
  _DAT_1400eac34 = 0x10;
  _DAT_1400eac38 = 1;
  _DAT_1400eac40 = &DAT_140029890;
  _DAT_1400eac48 = 0;
  _DAT_1400eac4c = 0xa0;
  DAT_1400eac50 = 0x10;
  _DAT_1400eac54 = 0x10;
  DAT_1400eac58 = 4;
  _DAT_1400eac60 = &DAT_140029890;
  _DAT_1400eac68 = 0;
  _DAT_1400eac6c = 0x90;
  DAT_1400eac70 = 0x10;
  DAT_1400eac74 = 0x10;
  DAT_1400eac78 = 4;
  _DAT_1400eac80 = &DAT_140029890;
  _DAT_1400eac88 = 0;
  _DAT_1400eac8c = 0xb0;
  _DAT_1400eac9c = local_c;
  _DAT_1400ead1c = local_c;
  _DAT_1400ead7c = local_c;
  _DAT_1400eacbc = local_c;
  _DAT_1400eaddc = local_c;
  _DAT_1400eacdc = local_c;
  _DAT_1400eacfc = local_c;
  _DAT_1400ead3c = local_c;
  _DAT_1400ead5c = local_c;
  _DAT_1400ead9c = local_c;
  DAT_1400eac90 = 0x10;
  _DAT_1400eac94 = 0x10;
  DAT_1400eac98 = 4;
  _DAT_1400ead00 = &DAT_140029890;
  _DAT_1400ead08 = 0x40;
  DAT_1400ead10 = 0x10;
  DAT_1400ead14 = 0x10;
  DAT_1400ead18 = 3;
  _DAT_1400ead60 = &DAT_140029890;
  _DAT_1400ead68 = 0x40;
  _DAT_1400ead6c = 0xa0;
  DAT_1400ead70 = 0x10;
  DAT_1400ead74 = 0x10;
  DAT_1400ead78 = 3;
  _DAT_1400eaca0 = &DAT_140029890;
  _DAT_1400eaca8 = 0x40;
  _DAT_1400eacac = 0x10;
  DAT_1400eacb0 = 0x10;
  DAT_1400eacb4 = 0x10;
  DAT_1400eacb8 = 3;
  _DAT_1400eadc0 = &DAT_140029890;
  _DAT_1400eadc8 = 0x40;
  _DAT_1400eadcc = 0xb0;
  DAT_1400eadd0 = 0x10;
  DAT_1400eadd4 = 0x10;
  DAT_1400eadd8 = 3;
  _DAT_1400eacc0 = &DAT_140029890;
  _DAT_1400eacc8 = 0x40;
  _DAT_1400eaccc = 0x20;
  _DAT_1400eacd0 = 0x10;
  _DAT_1400eacd4 = 0x10;
  _DAT_1400eacd8 = 3;
  _DAT_1400eace0 = &DAT_140029890;
  _DAT_1400eace8 = 0x40;
  _DAT_1400eacec = 0x40;
  _DAT_1400eacf0 = 0x10;
  _DAT_1400eacf4 = 0x10;
  _DAT_1400eacf8 = 3;
  _DAT_1400ead20 = &DAT_140029890;
  _DAT_1400ead28 = 0x40;
  _DAT_1400ead2c = 0x50;
  _DAT_1400ead30 = 0x10;
  _DAT_1400ead34 = 0x10;
  _DAT_1400ead38 = 3;
  _DAT_1400ead40 = &DAT_140029890;
  _DAT_1400ead48 = 0x40;
  _DAT_1400ead4c = 0x60;
  _DAT_1400ead50 = 0x10;
  _DAT_1400ead54 = 0x10;
  _DAT_1400ead58 = 3;
  _DAT_1400ead80 = &DAT_140029890;
  _DAT_1400ead88 = 0x40;
  _DAT_1400ead8c = 0x30;
  _DAT_1400ead90 = 0x10;
  _DAT_1400ead94 = 0x10;
  _DAT_1400ead98 = 3;
  _DAT_1400eada0 = &DAT_140029890;
  _DAT_1400eada8 = 0x40;
  _DAT_1400eadac = 0x80;
  _DAT_1400eadb0 = 0x10;
  _DAT_1400eadb4 = 0x10;
  _DAT_1400eadbc = local_c;
  _DAT_1400eadfc = local_c;
  _DAT_1400eae1c = local_c;
  _DAT_1400eae3c = local_c;
  _DAT_1400eae5c = local_c;
  _DAT_1400eae7c = local_c;
  _DAT_1400eae9c = local_c;
  _DAT_1400eaebc = local_c;
  _DAT_1400eaedc = local_c;
  _DAT_1400eaefc = local_c;
  _DAT_1400eadb8 = 3;
  _DAT_1400eade0 = &DAT_140029890;
  _DAT_1400eade8 = 0x40;
  _DAT_1400eadec = 0x70;
  _DAT_1400eadf0 = 0x10;
  _DAT_1400eadf4 = 0x10;
  _DAT_1400eadf8 = 3;
  _DAT_1400eae00 = &DAT_140029890;
  _DAT_1400eae08 = 0x40;
  _DAT_1400eae0c = 0x90;
  _DAT_1400eae10 = 0x10;
  _DAT_1400eae14 = 0x10;
  _DAT_1400eae18 = 3;
  _DAT_1400eae20 = &DAT_140029890;
  _DAT_1400eae28 = 0x100;
  _DAT_1400eae2c = 0x110;
  DAT_1400eae30 = 0x10;
  DAT_1400eae34 = 0x10;
  DAT_1400eae38 = 1;
  _DAT_1400eae40 = &DAT_140029890;
  _DAT_1400eae48 = 0xf0;
  _DAT_1400eae4c = 0x110;
  DAT_1400eae50 = 0x10;
  DAT_1400eae54 = 0x10;
  DAT_1400eae58 = 1;
  _DAT_1400eae60 = &DAT_140029890;
  _DAT_1400eae68 = 0x100;
  _DAT_1400eae6c = 0x70;
  DAT_1400eae70 = 0x10;
  DAT_1400eae74 = 0x10;
  DAT_1400eae78 = 3;
  _DAT_1400eae80 = &DAT_140029890;
  _DAT_1400eae88 = 0x100;
  _DAT_1400eae8c = 0x80;
  DAT_1400eae90 = 0x10;
  DAT_1400eae94 = 0x10;
  DAT_1400eae98 = 3;
  _DAT_1400eaea0 = &DAT_140029890;
  _DAT_1400eaea8 = 0x100;
  _DAT_1400eaeac = 0x90;
  DAT_1400eaeb0 = 0x10;
  DAT_1400eaeb4 = 0x10;
  DAT_1400eaeb8 = 3;
  _DAT_1400eaec0 = &DAT_140029890;
  _DAT_1400eaec8 = 0x100;
  _DAT_1400eaecc = 0xa0;
  DAT_1400eaed0 = 0x10;
  DAT_1400eaed4 = 0x10;
  DAT_1400eaed8 = 3;
  _DAT_1400eaee0 = &DAT_140029890;
  _DAT_1400eaee8 = 0;
  _DAT_1400eaeec = 0xc0;
  _DAT_1400eaef0 = 0x10;
  _DAT_1400eaef4 = 0x10;
  _DAT_1400eaef8 = 1;
  _DAT_1400eaf00 = &DAT_140029890;
  _DAT_1400eaf08 = 0x10;
  _DAT_1400eaf0c = 0xc0;
  _DAT_1400eaf10 = 0x10;
  _DAT_1400eaf14 = 0x10;
  _DAT_1400eaf18 = 1;
  _DAT_1400eaf1c = local_c;
  _DAT_1400eaf3c = local_c;
  _DAT_1400eaf5c = local_c;
  _DAT_1400eaf7c = local_c;
  _DAT_1400eaf9c = local_c;
  _DAT_1400eafbc = local_c;
  _DAT_1400eafdc = local_c;
  _DAT_1400eaffc = local_c;
  _DAT_1400eb01c = local_c;
  _DAT_1400eb03c = local_c;
  _DAT_1400eb05c = local_c;
  _DAT_1400eb07c = local_c;
  _DAT_1400eaf20 = &DAT_140029890;
  _DAT_1400eaf28 = 0x20;
  _DAT_1400eaf2c = 0xc0;
  _DAT_1400eaf30 = 0x10;
  _DAT_1400eaf34 = 0x10;
  _DAT_1400eaf38 = 1;
  _DAT_1400eaf40 = &DAT_140029890;
  _DAT_1400eaf48 = 0x30;
  _DAT_1400eaf4c = 0xc0;
  _DAT_1400eaf50 = 0x10;
  _DAT_1400eaf54 = 0x10;
  _DAT_1400eaf58 = 1;
  _DAT_1400eaf60 = &DAT_140029890;
  _DAT_1400eaf68 = 0x40;
  _DAT_1400eaf6c = 0xc0;
  _DAT_1400eaf70 = 0x10;
  _DAT_1400eaf74 = 0x10;
  _DAT_1400eaf78 = 1;
  _DAT_1400eaf80 = &DAT_140029890;
  _DAT_1400eaf88 = 0x50;
  _DAT_1400eaf8c = 0xc0;
  _DAT_1400eaf90 = 0x10;
  _DAT_1400eaf94 = 0x10;
  _DAT_1400eaf98 = 1;
  _DAT_1400eafa0 = &DAT_140029890;
  _DAT_1400eafa8 = 0x60;
  _DAT_1400eafac = 0xc0;
  _DAT_1400eafb0 = 0x10;
  _DAT_1400eafb4 = 0x10;
  _DAT_1400eafb8 = 1;
  _DAT_1400eafc0 = &DAT_140029890;
  _DAT_1400eafc8 = 0x70;
  _DAT_1400eafcc = 0xc0;
  _DAT_1400eafd0 = 0x10;
  _DAT_1400eafd4 = 0x10;
  _DAT_1400eafd8 = 1;
  _DAT_1400eafe0 = &DAT_140029890;
  _DAT_1400eafe8 = 0x80;
  _DAT_1400eafec = 0xc0;
  _DAT_1400eaff0 = 0x10;
  _DAT_1400eaff4 = 0x10;
  _DAT_1400eaff8 = 1;
  _DAT_1400eb000 = &DAT_140029890;
  _DAT_1400eb008 = 0x90;
  _DAT_1400eb00c = 0xc0;
  _DAT_1400eb010 = 0x10;
  _DAT_1400eb014 = 0x10;
  _DAT_1400eb018 = 1;
  _DAT_1400eb020 = &DAT_140029890;
  _DAT_1400eb028 = 0;
  _DAT_1400eb02c = 0xd0;
  _DAT_1400eb030 = 0x10;
  _DAT_1400eb034 = 0x10;
  _DAT_1400eb038 = 1;
  _DAT_1400eb040 = &DAT_140029890;
  _DAT_1400eb048 = 0x10;
  _DAT_1400eb04c = 0xd0;
  _DAT_1400eb050 = 0x10;
  _DAT_1400eb054 = 0x10;
  _DAT_1400eb058 = 1;
  _DAT_1400eb060 = &DAT_140029890;
  _DAT_1400eb068 = 0x20;
  _DAT_1400eb06c = 0xd0;
  _DAT_1400eb070 = 0x10;
  _DAT_1400eb074 = 0x10;
  _DAT_1400eb078 = 1;
  _DAT_1400eb09c = local_c;
  _DAT_1400eb0bc = local_c;
  _DAT_1400eb0dc = local_c;
  _DAT_1400eb0fc = local_c;
  _DAT_1400eb11c = local_c;
  _DAT_1400eb13c = local_c;
  _DAT_1400eb15c = local_c;
  _DAT_1400eb17c = local_c;
  _DAT_1400eb19c = local_c;
  _DAT_1400eb1bc = local_c;
  _DAT_1400eb080 = &DAT_140029890;
  _DAT_1400eb088 = 0x30;
  _DAT_1400eb08c = 0xd0;
  _DAT_1400eb090 = 0x10;
  _DAT_1400eb094 = 0x10;
  _DAT_1400eb098 = 1;
  _DAT_1400eb0a0 = &DAT_140029890;
  _DAT_1400eb0a8 = 0x40;
  _DAT_1400eb0ac = 0xd0;
  _DAT_1400eb0b0 = 0x10;
  _DAT_1400eb0b4 = 0x10;
  _DAT_1400eb0b8 = 1;
  _DAT_1400eb0c0 = &DAT_140029890;
  _DAT_1400eb0c8 = 0x50;
  _DAT_1400eb0cc = 0xd0;
  _DAT_1400eb0d0 = 0x10;
  _DAT_1400eb0d4 = 0x10;
  _DAT_1400eb0d8 = 1;
  _DAT_1400eb0e0 = &DAT_140029890;
  _DAT_1400eb0e8 = 0x60;
  _DAT_1400eb0ec = 0xd0;
  _DAT_1400eb0f0 = 0x10;
  _DAT_1400eb0f4 = 0x10;
  _DAT_1400eb0f8 = 1;
  _DAT_1400eb100 = &DAT_140029890;
  _DAT_1400eb108 = 0x70;
  _DAT_1400eb10c = 0xd0;
  _DAT_1400eb110 = 0x10;
  _DAT_1400eb114 = 0x10;
  _DAT_1400eb118 = 1;
  _DAT_1400eb120 = &DAT_140029890;
  _DAT_1400eb128 = 0x80;
  _DAT_1400eb12c = 0xd0;
  _DAT_1400eb130 = 0x10;
  _DAT_1400eb134 = 0x10;
  _DAT_1400eb138 = 1;
  _DAT_1400eb140 = &DAT_140029890;
  _DAT_1400eb148 = 0x90;
  _DAT_1400eb14c = 0xd0;
  _DAT_1400eb150 = 0x10;
  _DAT_1400eb154 = 0x10;
  _DAT_1400eb158 = 1;
  _DAT_1400eb160 = &DAT_140029890;
  _DAT_1400eb168 = 0xa0;
  _DAT_1400eb16c = 0xd0;
  _DAT_1400eb170 = 0x10;
  _DAT_1400eb174 = 0x10;
  _DAT_1400eb178 = 1;
  _DAT_1400eb180 = &DAT_140029890;
  _DAT_1400eb188 = 0xb0;
  _DAT_1400eb18c = 0xd0;
  _DAT_1400eb190 = 0x10;
  _DAT_1400eb194 = 0x10;
  _DAT_1400eb198 = 1;
  _DAT_1400eb1a0 = &DAT_140029890;
  _DAT_1400eb1a8 = 0xc0;
  _DAT_1400eb1ac = 0xd0;
  _DAT_1400eb1b0 = 0x10;
  _DAT_1400eb1b4 = 0x10;
  _DAT_1400eb1b8 = 1;
  _DAT_1400eb1c0 = &DAT_140029890;
  _DAT_1400eb1dc = local_c;
  _DAT_1400eb1fc = local_c;
  _DAT_1400eb21c = local_c;
  _DAT_1400eb33c = local_c;
  _DAT_1400eb35c = local_c;
  _DAT_1400eb37c = local_c;
  _DAT_1400eb39c = local_c;
  _DAT_1400eb3bc = local_c;
  _DAT_1400eb3dc = local_c;
  _DAT_1400eb3fc = local_c;
  _DAT_1400eb1c8 = 0xd0;
  _DAT_1400eb1cc = 0xd0;
  _DAT_1400eb1d0 = 0x10;
  _DAT_1400eb1d4 = 0x10;
  _DAT_1400eb1d8 = 1;
  _DAT_1400eb1e0 = &DAT_140029890;
  _DAT_1400eb1e8 = 0xe0;
  _DAT_1400eb1ec = 0xd0;
  _DAT_1400eb1f0 = 0x10;
  _DAT_1400eb1f4 = 0x10;
  _DAT_1400eb1f8 = 1;
  _DAT_1400eb200 = &DAT_140029890;
  _DAT_1400eb208 = 0xf0;
  _DAT_1400eb20c = 0xd0;
  _DAT_1400eb210 = 0x10;
  _DAT_1400eb214 = 0x10;
  _DAT_1400eb218 = 1;
  _DAT_1400eb320 = &DAT_140029890;
  _DAT_1400eb328 = 0;
  _DAT_1400eb32c = 0xe0;
  _DAT_1400eb330 = 0x10;
  _DAT_1400eb334 = 0x10;
  _DAT_1400eb338 = 1;
  _DAT_1400eb340 = &DAT_140029890;
  _DAT_1400eb348 = 0x10;
  _DAT_1400eb34c = 0xe0;
  _DAT_1400eb350 = 0x10;
  _DAT_1400eb354 = 0x10;
  _DAT_1400eb358 = 1;
  _DAT_1400eb360 = &DAT_140029890;
  _DAT_1400eb368 = 0x20;
  _DAT_1400eb36c = 0xe0;
  _DAT_1400eb370 = 0x10;
  _DAT_1400eb374 = 0x10;
  _DAT_1400eb378 = 1;
  _DAT_1400eb380 = &DAT_140029890;
  _DAT_1400eb388 = 0x30;
  _DAT_1400eb38c = 0xe0;
  _DAT_1400eb390 = 0x10;
  _DAT_1400eb394 = 0x10;
  _DAT_1400eb398 = 1;
  _DAT_1400eb3a0 = &DAT_140029890;
  _DAT_1400eb3a8 = 0x40;
  _DAT_1400eb3ac = 0xe0;
  _DAT_1400eb3b0 = 0x10;
  _DAT_1400eb3b4 = 0x10;
  _DAT_1400eb3b8 = 1;
  _DAT_1400eb3c0 = &DAT_140029890;
  _DAT_1400eb3c8 = 0x50;
  _DAT_1400eb3cc = 0xe0;
  DAT_1400eb3d0 = 0x10;
  DAT_1400eb3d4 = 0x10;
  _DAT_1400eb3d8 = 1;
  _DAT_1400eb3e0 = &DAT_140029890;
  _DAT_1400eb3e8 = 0x60;
  _DAT_1400eb3ec = 0xe0;
  _DAT_1400eb3f0 = 0x10;
  _DAT_1400eb3f4 = 0x10;
  _DAT_1400eb3f8 = 1;
  _DAT_1400eb400 = &DAT_140029890;
  _DAT_1400eb408 = 0x70;
  _DAT_1400eb41c = local_c;
  _DAT_1400eb43c = local_c;
  _DAT_1400eb47c = local_c;
  _DAT_1400eb45c = local_c;
  _DAT_1400eb49c = local_c;
  _DAT_1400eb4bc = local_c;
  _DAT_1400eb55c = local_c;
  _DAT_1400eb4fc = local_c;
  _DAT_1400eb57c = local_c;
  _DAT_1400eb51c = local_c;
  _DAT_1400eb40c = 0xe0;
  _DAT_1400eb410 = 0x10;
  _DAT_1400eb414 = 0x10;
  _DAT_1400eb418 = 1;
  _DAT_1400eb420 = &DAT_140029890;
  _DAT_1400eb428 = 0x80;
  _DAT_1400eb42c = 0xe0;
  _DAT_1400eb430 = 0x10;
  _DAT_1400eb434 = 0x10;
  _DAT_1400eb438 = 1;
  _DAT_1400eb460 = &DAT_140029890;
  _DAT_1400eb468 = 0x90;
  _DAT_1400eb46c = 0xe0;
  _DAT_1400eb470 = 0x10;
  _DAT_1400eb474 = 0x10;
  _DAT_1400eb478 = 1;
  _DAT_1400eb440 = &DAT_140029890;
  _DAT_1400eb448 = 0xa0;
  _DAT_1400eb44c = 0xe0;
  _DAT_1400eb450 = 0x10;
  _DAT_1400eb454 = 0x10;
  _DAT_1400eb458 = 1;
  _DAT_1400eb480 = &DAT_140029890;
  _DAT_1400eb488 = 0xb0;
  _DAT_1400eb48c = 0xe0;
  _DAT_1400eb490 = 0x10;
  _DAT_1400eb494 = 0x10;
  _DAT_1400eb498 = 1;
  _DAT_1400eb4a0 = &DAT_140029890;
  _DAT_1400eb4a8 = 0xc0;
  _DAT_1400eb4ac = 0xe0;
  _DAT_1400eb4b0 = 0x10;
  _DAT_1400eb4b4 = 0x10;
  _DAT_1400eb4b8 = 1;
  _DAT_1400eb540 = &DAT_140029890;
  _DAT_1400eb548 = 0xa0;
  _DAT_1400eb54c = 0xb0;
  _DAT_1400eb550 = 0x10;
  _DAT_1400eb554 = 0x10;
  _DAT_1400eb558 = 1;
  _DAT_1400eb4e0 = &DAT_140029890;
  _DAT_1400eb4e8 = 0xb0;
  _DAT_1400eb4ec = 0xb0;
  _DAT_1400eb4f0 = 0x10;
  _DAT_1400eb4f4 = 0x10;
  _DAT_1400eb4f8 = 1;
  _DAT_1400eb560 = &DAT_140029890;
  _DAT_1400eb568 = 0xc0;
  _DAT_1400eb56c = 0xb0;
  _DAT_1400eb570 = 0x10;
  _DAT_1400eb574 = 0x10;
  _DAT_1400eb578 = 1;
  _DAT_1400eb500 = &DAT_140029890;
  _DAT_1400eb508 = 0xa0;
  _DAT_1400eb50c = 0xc0;
  _DAT_1400eb510 = 0x10;
  _DAT_1400eb514 = 0x10;
  _DAT_1400eb518 = 1;
  _DAT_1400eb4c0 = &DAT_140029890;
  _DAT_1400eb4c8 = 0xb0;
  _DAT_1400eb4cc = 0xc0;
  _DAT_1400eb4dc = local_c;
  _DAT_1400eb53c = local_c;
  _DAT_1400eb23c = local_c;
  _DAT_1400eb25c = local_c;
  _DAT_1400eb27c = local_c;
  _DAT_1400eb29c = local_c;
  _DAT_1400eb2bc = local_c;
  _DAT_1400eb2dc = local_c;
  _DAT_1400eb2fc = local_c;
  _DAT_1400eb31c = local_c;
  _DAT_1400eb4d0 = 0x10;
  _DAT_1400eb4d4 = 0x10;
  _DAT_1400eb4d8 = 1;
  _DAT_1400eb520 = &DAT_140029890;
  _DAT_1400eb528 = 0xc0;
  _DAT_1400eb52c = 0xc0;
  _DAT_1400eb530 = 0x10;
  _DAT_1400eb534 = 0x10;
  _DAT_1400eb538 = 1;
  _DAT_1400eb220 = &DAT_140029890;
  _DAT_1400eb228 = 0x80;
  _DAT_1400eb22c = 0x70;
  DAT_1400eb230 = 0x20;
  DAT_1400eb234 = 0x20;
  DAT_1400eb238 = 1;
  _DAT_1400eb240 = &DAT_140029890;
  _DAT_1400eb248 = 0xa0;
  _DAT_1400eb24c = 0x70;
  _DAT_1400eb250 = 0x20;
  _DAT_1400eb254 = 0x20;
  _DAT_1400eb258 = 1;
  _DAT_1400eb260 = &DAT_140029890;
  _DAT_1400eb268 = 0xc0;
  _DAT_1400eb26c = 0x70;
  DAT_1400eb270 = 0x20;
  DAT_1400eb274 = 0x20;
  DAT_1400eb278 = 1;
  _DAT_1400eb280 = &DAT_140029890;
  _DAT_1400eb288 = 0xe0;
  _DAT_1400eb28c = 0x70;
  _DAT_1400eb290 = 0x20;
  _DAT_1400eb294 = 0x20;
  _DAT_1400eb298 = 1;
  _DAT_1400eb2a0 = &DAT_140029890;
  _DAT_1400eb2a8 = 0x80;
  _DAT_1400eb2ac = 0x90;
  DAT_1400eb2b0 = 0x20;
  DAT_1400eb2b4 = 0x20;
  DAT_1400eb2b8 = 1;
  _DAT_1400eb2c0 = &DAT_140029890;
  _DAT_1400eb2c8 = 0xa0;
  _DAT_1400eb2cc = 0x90;
  _DAT_1400eb2d0 = 0x20;
  _DAT_1400eb2d4 = 0x20;
  _DAT_1400eb2d8 = 1;
  _DAT_1400eb2e0 = &DAT_140029890;
  _DAT_1400eb2e8 = 0xc0;
  _DAT_1400eb2ec = 0x90;
  DAT_1400eb2f0 = 0x20;
  DAT_1400eb2f4 = 0x20;
  DAT_1400eb2f8 = 1;
  _DAT_1400eb300 = &DAT_140029890;
  _DAT_1400eb308 = 0xe0;
  _DAT_1400eb30c = 0x90;
  _DAT_1400eb310 = 0x20;
  _DAT_1400eb314 = 0x20;
  _DAT_1400eb318 = 1;
  _DAT_1400eb580 = &DAT_140029890;
  _DAT_1400eb588 = 0;
  _DAT_1400eb58c = 0xf0;
  DAT_1400eb590 = 0x30;
  _DAT_1400eb59c = local_c;
  _DAT_1400eb5bc = local_c;
  _DAT_1400eb5dc = local_c;
  _DAT_1400eb5fc = local_c;
  _DAT_1400eb61c = local_c;
  _DAT_1400eb63c = local_c;
  _DAT_1400eb65c = local_c;
  _DAT_1400eb67c = local_c;
  _DAT_1400eb69c = local_c;
  _DAT_1400eb6bc = local_c;
  DAT_1400eb594 = 0x20;
  DAT_1400eb598 = 3;
  _DAT_1400eb5a0 = &DAT_140029890;
  _DAT_1400eb5a8 = 0;
  _DAT_1400eb5ac = 0x110;
  _DAT_1400eb5b0 = 0x30;
  _DAT_1400eb5b4 = 0x20;
  _DAT_1400eb5b8 = 3;
  _DAT_1400eb5c0 = &DAT_140029890;
  _DAT_1400eb5c8 = 0;
  _DAT_1400eb5cc = 0x130;
  DAT_1400eb5d0 = 0x30;
  DAT_1400eb5d4 = 0x20;
  DAT_1400eb5d8 = 3;
  _DAT_1400eb5e0 = &DAT_140029890;
  _DAT_1400eb5e8 = 0;
  _DAT_1400eb5ec = 0x150;
  _DAT_1400eb5f0 = 0x30;
  _DAT_1400eb5f4 = 0x20;
  _DAT_1400eb5f8 = 3;
  _DAT_1400eb600 = &DAT_140029890;
  _DAT_1400eb608 = 0x90;
  _DAT_1400eb60c = 0xf0;
  DAT_1400eb610 = 0x20;
  DAT_1400eb614 = 0x30;
  DAT_1400eb618 = 3;
  _DAT_1400eb620 = &DAT_140029890;
  _DAT_1400eb628 = 0x90;
  _DAT_1400eb62c = 0x120;
  _DAT_1400eb630 = 0x20;
  _DAT_1400eb634 = 0x30;
  _DAT_1400eb638 = 3;
  _DAT_1400eb640 = &DAT_140029890;
  _DAT_1400eb648 = 0x90;
  _DAT_1400eb64c = 0x150;
  DAT_1400eb650 = 0x20;
  DAT_1400eb654 = 0x30;
  DAT_1400eb658 = 3;
  _DAT_1400eb660 = &DAT_140029890;
  _DAT_1400eb668 = 0x90;
  _DAT_1400eb66c = 0x180;
  _DAT_1400eb670 = 0x20;
  _DAT_1400eb674 = 0x30;
  _DAT_1400eb678 = 3;
  _DAT_1400eb680 = &DAT_140029890;
  _DAT_1400eb688 = 0x110;
  _DAT_1400eb68c = 0xb0;
  DAT_1400eb690 = 0x10;
  DAT_1400eb694 = 0x20;
  DAT_1400eb698 = 1;
  _DAT_1400eb6a0 = &DAT_140029890;
  _DAT_1400eb6a8 = 0x120;
  _DAT_1400eb6ac = 0xb0;
  _DAT_1400eb6b0 = 0x10;
  _DAT_1400eb6b4 = 0x20;
  _DAT_1400eb6b8 = 1;
  _DAT_1400eb6c0 = &DAT_140029890;
  _DAT_1400eb6c8 = 0x110;
  _DAT_1400eb6cc = 0x110;
  DAT_1400eb6d0 = 0x10;
  DAT_1400eb6d4 = 0x10;
  _DAT_1400eb6dc = local_c;
  _DAT_1400eb6fc = local_c;
  _DAT_1400eb71c = local_c;
  _DAT_1400eb6e0 = &DAT_140029890;
  _DAT_1400eb700 = &DAT_140029890;
  local_58 = "tooltip_assembler.png";
  DAT_1400eb6d8 = 1;
  _DAT_1400eb6e8 = 0xf0;
  _DAT_1400eb6ec = 0xe0;
  _DAT_1400eb6f0 = 0x10;
  _DAT_1400eb6f4 = 0x30;
  _DAT_1400eb6f8 = 1;
  _DAT_1400eb708 = 0x100;
  _DAT_1400eb70c = 0xd0;
  DAT_1400eb710 = 0x30;
  DAT_1400eb714 = 0x40;
  _DAT_1400eb718 = 1;
  local_50 = 0x15;
  pauVar2 = FUN_1400101e0((undefined1 (*) [16])local_38,&local_58);
  local_50 = 0x19;
  _DAT_1400eb720 = *(undefined8 *)*pauVar2;
  uRam00000001400eb728 = *(undefined8 *)(*pauVar2 + 8);
  local_58 = "tooltip_assembler_big.png";
  pauVar2 = FUN_1400101e0((undefined1 (*) [16])local_38,&local_58);
  local_50 = 0xf;
  _DAT_1400eb730 = *(undefined8 *)*pauVar2;
  uRam00000001400eb738 = *(undefined8 *)(*pauVar2 + 8);
  local_58 = "tooltip_bee.png";
  pauVar2 = FUN_1400101e0((undefined1 (*) [16])local_38,&local_58);
  local_50 = 0x14;
  _DAT_1400eb740 = *(undefined8 *)*pauVar2;
  _DAT_1400eb748 = *(undefined8 *)(*pauVar2 + 8);
  local_58 = "tooltip_cam_lens.png";
  pauVar2 = FUN_1400101e0((undefined1 (*) [16])local_38,&local_58);
  local_50 = 0x12;
  _DAT_1400eb750 = *(undefined8 *)*pauVar2;
  uRam00000001400eb758 = *(undefined8 *)(*pauVar2 + 8);
  local_58 = "tooltip_camera.png";
  pauVar2 = FUN_1400101e0((undefined1 (*) [16])local_38,&local_58);
  local_50 = 0x11;
  _DAT_1400eb760 = *(undefined8 *)*pauVar2;
  uRam00000001400eb768 = *(undefined8 *)(*pauVar2 + 8);
  local_58 = "tooltip_chute.png";
  pauVar2 = FUN_1400101e0((undefined1 (*) [16])local_38,&local_58);
  local_50 = 0x13;
  _DAT_1400eb770 = *(undefined8 *)*pauVar2;
  uRam00000001400eb778 = *(undefined8 *)(*pauVar2 + 8);
  local_58 = "tooltip_circuit.png";
  pauVar2 = FUN_1400101e0((undefined1 (*) [16])local_38,&local_58);
  local_50 = 0x14;
  _DAT_1400eb780 = *(undefined8 *)*pauVar2;
  uRam00000001400eb788 = *(undefined8 *)(*pauVar2 + 8);
  local_58 = "tooltip_conveyor.png";
  pauVar2 = FUN_1400101e0((undefined1 (*) [16])local_38,&local_58);
  _DAT_1400eb790 = *(undefined8 *)*pauVar2;
  uRam00000001400eb798 = *(undefined8 *)(*pauVar2 + 8);
  local_50 = 0x16;
  local_58 = "tooltip_copper_ore.png";
  pauVar2 = FUN_1400101e0((undefined1 (*) [16])local_38,&local_58);
  local_50 = 0x17;
  _DAT_1400eb7a0 = *(undefined8 *)*pauVar2;
  uRam00000001400eb7a8 = *(undefined8 *)(*pauVar2 + 8);
  local_58 = "tooltip_copper_wire.png";
  pauVar2 = FUN_1400101e0((undefined1 (*) [16])local_38,&local_58);
  local_50 = 0x19;
  _DAT_1400eb7b0 = *(undefined8 *)*pauVar2;
  uRam00000001400eb7b8 = *(undefined8 *)(*pauVar2 + 8);
  local_58 = "tooltip_cyber_seagull.png";
  pauVar2 = FUN_1400101e0((undefined1 (*) [16])local_38,&local_58);
  local_50 = 0x14;
  _DAT_1400eb7c0 = *(undefined8 *)*pauVar2;
  uRam00000001400eb7c8 = *(undefined8 *)(*pauVar2 + 8);
  local_58 = "tooltip_elevator.png";
  pauVar2 = FUN_1400101e0((undefined1 (*) [16])local_38,&local_58);
  local_50 = 0x13;
  _DAT_1400eb7d0 = *(undefined8 *)*pauVar2;
  uRam00000001400eb7d8 = *(undefined8 *)(*pauVar2 + 8);
  local_58 = "tooltip_feather.png";
  pauVar2 = FUN_1400101e0((undefined1 (*) [16])local_38,&local_58);
  local_50 = 0x13;
  _DAT_1400eb7e0 = *(undefined8 *)*pauVar2;
  uRam00000001400eb7e8 = *(undefined8 *)(*pauVar2 + 8);
  local_58 = "tooltip_furnace.png";
  pauVar2 = FUN_1400101e0((undefined1 (*) [16])local_38,&local_58);
  local_50 = 0x10;
  _DAT_1400eb7f0 = *(undefined8 *)*pauVar2;
  uRam00000001400eb7f8 = *(undefined8 *)(*pauVar2 + 8);
  local_58 = "tooltip_gear.png";
  pauVar2 = FUN_1400101e0((undefined1 (*) [16])local_38,&local_58);
  local_50 = 0x10;
  _DAT_1400eb800 = *(undefined8 *)*pauVar2;
  uRam00000001400eb808 = *(undefined8 *)(*pauVar2 + 8);
  local_58 = "tooltip_hive.png";
  pauVar2 = FUN_1400101e0((undefined1 (*) [16])local_38,&local_58);
  local_50 = 0x14;
  _DAT_1400eb810 = *(undefined8 *)*pauVar2;
  uRam00000001400eb818 = *(undefined8 *)(*pauVar2 + 8);
  local_58 = "tooltip_hive_big.png";
  pauVar2 = FUN_1400101e0((undefined1 (*) [16])local_38,&local_58);
  local_50 = 0x11;
  _DAT_1400eb820 = *(undefined8 *)*pauVar2;
  uRam00000001400eb828 = *(undefined8 *)(*pauVar2 + 8);
  local_58 = "tooltip_honey.png";
  pauVar2 = FUN_1400101e0((undefined1 (*) [16])local_38,&local_58);
  _DAT_1400eb830 = *(undefined8 *)*pauVar2;
  uRam00000001400eb838 = *(undefined8 *)(*pauVar2 + 8);
  local_50 = 0x14;
  local_58 = "tooltip_iron_ore.png";
  pauVar2 = FUN_1400101e0((undefined1 (*) [16])local_38,&local_58);
  local_50 = 0x16;
  _DAT_1400eb840 = *(undefined8 *)*pauVar2;
  uRam00000001400eb848 = *(undefined8 *)(*pauVar2 + 8);
  local_58 = "tooltip_iron_plate.png";
  pauVar2 = FUN_1400101e0((undefined1 (*) [16])local_38,&local_58);
  local_50 = 0x13;
  _DAT_1400eb850 = *(undefined8 *)*pauVar2;
  uRam00000001400eb858 = *(undefined8 *)(*pauVar2 + 8);
  local_58 = "tooltip_landing.png";
  pauVar2 = FUN_1400101e0((undefined1 (*) [16])local_38,&local_58);
  local_50 = 0x12;
  _DAT_1400eb860 = *(undefined8 *)*pauVar2;
  uRam00000001400eb868 = *(undefined8 *)(*pauVar2 + 8);
  local_58 = "tooltip_pollen.png";
  pauVar2 = FUN_1400101e0((undefined1 (*) [16])local_38,&local_58);
  local_50 = 0x16;
  _DAT_1400eb870 = *(undefined8 *)*pauVar2;
  uRam00000001400eb878 = *(undefined8 *)(*pauVar2 + 8);
  local_58 = "tooltip_power_core.png";
  pauVar2 = FUN_1400101e0((undefined1 (*) [16])local_38,&local_58);
  local_50 = 0x13;
  _DAT_1400eb880 = *(undefined8 *)*pauVar2;
  uRam00000001400eb888 = *(undefined8 *)(*pauVar2 + 8);
  local_58 = "tooltip_seagull.png";
  pauVar2 = FUN_1400101e0((undefined1 (*) [16])local_38,&local_58);
  local_50 = 0x14;
  _DAT_1400eb890 = *(undefined8 *)*pauVar2;
  uRam00000001400eb898 = *(undefined8 *)(*pauVar2 + 8);
  local_58 = "tooltip_splitter.png";
  pauVar2 = FUN_1400101e0((undefined1 (*) [16])local_38,&local_58);
  local_50 = 0x13;
  _DAT_1400eb8a0 = *(undefined8 *)*pauVar2;
  uRam00000001400eb8a8 = *(undefined8 *)(*pauVar2 + 8);
  local_58 = "tooltip_uranium.png";
  pauVar2 = FUN_1400101e0((undefined1 (*) [16])local_38,&local_58);
  lVar4 = 9;
  _DAT_1400eb8b0 = *(undefined8 *)*pauVar2;
  uRam00000001400eb8b8 = *(undefined8 *)(*pauVar2 + 8);
  puVar5 = (undefined8 *)&DAT_1400298c0;
  do {
    local_58 = "tutorial_%.png";
    local_50 = 0xe;
    FUN_140001d10(local_48,&DAT_140029878,(longlong *)&local_58,uVar3);
    local_38[0] = local_48[0];
    local_38[1] = local_48[1];
    pauVar2 = FUN_1400101e0((undefined1 (*) [16])local_28,local_38);
    uVar3 = uVar3 + 1;
    uVar1 = *(undefined8 *)(*pauVar2 + 8);
    *puVar5 = *(undefined8 *)*pauVar2;
    puVar5[1] = uVar1;
    lVar4 = lVar4 + -1;
    puVar5 = puVar5 + 2;
  } while (lVar4 != 0);
  local_50 = 0xc;
  local_58 = "controls.png";
  pauVar2 = FUN_1400101e0((undefined1 (*) [16])local_28,&local_58);
  local_50 = 0xf;
  _DAT_140029950 = *(undefined8 *)*pauVar2;
  _DAT_140029958 = *(undefined8 *)(*pauVar2 + 8);
  local_58 = "win_message.png";
  pauVar2 = FUN_1400101e0((undefined1 (*) [16])local_28,&local_58);
  _DAT_140029960 = *(undefined8 *)*pauVar2;
  _DAT_140029968 = *(undefined8 *)(*pauVar2 + 8);
  return;
}


// ===== FUN_14000fd80 @ 14000fd80 size=1115

void FUN_14000fd80(undefined1 (*param_1) [16],longlong *param_2,float param_3)

{
  short *psVar1;
  short sVar2;
  undefined1 auVar3 [16];
  code *pcVar4;
  float fVar5;
  uint uVar6;
  uint uVar7;
  undefined1 *puVar8;
  longlong *plVar9;
  longlong lVar10;
  float *pfVar11;
  ulonglong uVar12;
  short *psVar13;
  undefined1 *puVar14;
  undefined8 *puVar15;
  int *piVar16;
  uint *puVar17;
  ulonglong uVar18;
  uint uVar19;
  longlong lVar20;
  longlong lVar21;
  uint local_res20;
  uint local_res24;
  longlong local_88;
  longlong lStack_80;
  undefined8 local_78;
  longlong lStack_70;
  int local_68;
  int local_64;
  short local_60;
  ushort local_5e;
  uint local_5c;
  undefined8 local_58;
  short sStack_52;
  
  local_88 = DAT_140029828;
  if (DAT_140029828 == -1) {
    return;
  }
  local_78 = (char *)*param_2;
  lStack_70 = param_2[1];
  puVar8 = (undefined1 *)FUN_1400015f0(&local_res20,&DAT_140029818,&local_78);
  uVar6 = local_res20;
  fVar5 = (32767f);
  if (puVar8 == (undefined1 *)0x0) {
    local_88 = *param_2;
    lStack_80 = param_2[1];
    lStack_70 = 0x1b;
    local_78 = "Failed to load audio file: ";
    plVar9 = FUN_140001ca0((undefined8 *)&local_68,&DAT_140029818,&local_78,&local_88);
    local_78 = (char *)*plVar9;
    lStack_70 = plVar9[1];
    FUN_140002030(&local_78);
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  if (local_res20 < 0x2d) {
    lStack_70 = 0x17;
    local_78 = "Wav file not big enough";
    FUN_140002030(&local_78);
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  puVar14 = puVar8;
  puVar15 = &local_78;
  for (lVar10 = 0xc; lVar10 != 0; lVar10 = lVar10 + -1) {
    *(undefined1 *)puVar15 = *puVar14;
    puVar14 = puVar14 + 1;
    puVar15 = (undefined8 *)((longlong)puVar15 + 1);
  }
  if (local_res20 != local_78._4_4_ + 8U) {
    lStack_70 = 0x17;
    local_78 = "Wav length didn\'t match";
    FUN_140002030(&local_78);
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  if (((int)local_78 != 0x46464952) || ((int)lStack_70 != 0x45564157)) {
    lStack_70 = 0x11;
    local_78 = "WAV magic invalid";
    FUN_140002030(&local_78);
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  puVar14 = puVar8 + 0xc;
  piVar16 = &local_68;
  for (lVar10 = 0x18; lVar10 != 0; lVar10 = lVar10 + -1) {
    *(undefined1 *)piVar16 = *puVar14;
    puVar14 = puVar14 + 1;
    piVar16 = (int *)((longlong)piVar16 + 1);
  }
  if (local_68 != 0x20746d66) {
    lStack_70 = 0x14;
    local_78 = "Fmt chunk id invalid";
    FUN_140002030(&local_78);
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  if (local_64 != 0x10) {
    lStack_70 = 0x19;
    local_78 = "Format chunk size invalid";
    FUN_140002030(&local_78);
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  if (local_60 != 1) {
    lStack_70 = 0x26;
    local_78 = "Formats other than pcm int unsupported";
    FUN_140002030(&local_78);
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  if (sStack_52 != 0x10) {
    lStack_70 = 0xe;
    local_78 = "Must be 16 bit";
    FUN_140002030(&local_78);
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  puVar14 = puVar8 + 0x24;
  puVar17 = &local_res20;
  for (lVar10 = 8; lVar10 != 0; lVar10 = lVar10 + -1) {
    *(undefined1 *)puVar17 = *puVar14;
    puVar14 = puVar14 + 1;
    puVar17 = (uint *)((longlong)puVar17 + 1);
  }
  if (local_res20 != 0x61746164) {
    lStack_70 = 0x15;
    local_78 = "Data chunk id invalid";
    FUN_140002030(&local_78);
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  if (uVar6 + 0x14 < local_res24) {
    lStack_70 = 0x1d;
    local_78 = "Not enough audio data in file";
    FUN_140002030(&local_78);
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  uVar18 = CONCAT62(0,local_5e);
  auVar3._8_8_ = 0;
  auVar3._0_8_ = uVar18;
  auVar3 = (ZEXT416(0) << 0x40 | ZEXT416(local_res24 >> 1)) / auVar3;
  lVar10 = auVar3._0_8_;
  uVar6 = auVar3._0_4_;
  if (uVar6 == 0) {
    *param_1 = (undefined1  [16])0x0;
    *(undefined8 *)param_1[1] = 0;
    DAT_140029828 = local_88;
    return;
  }
  lVar20 = 0;
  uVar19 = 0;
  uVar12 = DAT_140029888 + 3U & 0xfffffffffffffffc;
  lVar21 = DAT_140029878 + uVar12;
  DAT_140029888 = uVar12 + lVar10 * 4;
  if (3 < uVar6) {
    psVar13 = (short *)(puVar8 + (uVar18 + 0xb) * 4);
    uVar7 = (uVar6 - 4 >> 2) + 1;
    uVar12 = (ulonglong)uVar7;
    uVar19 = uVar7 * 4;
    lVar20 = (ulonglong)uVar7 * 4;
    pfVar11 = (float *)(lVar21 + 8);
    do {
      pfVar11[-2] = ((float)(int)psVar13[(ulonglong)(uint)local_5e * -2] / fVar5) * param_3;
      pfVar11[-1] = ((float)(int)psVar13[-(ulonglong)(uint)local_5e] / fVar5) * param_3;
      *pfVar11 = ((float)(int)*psVar13 / fVar5) * param_3;
      psVar1 = psVar13 + uVar18;
      psVar13 = psVar13 + uVar18 * 4;
      pfVar11[1] = ((float)(int)*psVar1 / fVar5) * param_3;
      uVar12 = uVar12 - 1;
      pfVar11 = pfVar11 + 4;
    } while (uVar12 != 0);
    if (uVar6 <= uVar19) goto LAB_140010017;
  }
  psVar13 = (short *)(puVar8 + uVar18 * lVar20 * 2 + 0x2c);
  uVar12 = (ulonglong)(uVar6 - uVar19);
  pfVar11 = (float *)(lVar20 * 4 + lVar21);
  do {
    sVar2 = *psVar13;
    psVar13 = psVar13 + uVar18;
    *pfVar11 = ((float)(int)sVar2 / fVar5) * param_3;
    uVar12 = uVar12 - 1;
    pfVar11 = pfVar11 + 1;
  } while (uVar12 != 0);
LAB_140010017:
  *(longlong *)*param_1 = lVar21;
  *(uint *)(*param_1 + 8) = uVar6;
  *(uint *)(*param_1 + 0xc) = local_5c;
  *(double *)param_1[1] = (double)((float)lVar10 / (float)local_5c);
  DAT_140029828 = local_88;
  return;
}


// ===== FUN_1400101e0 @ 1400101e0 size=280

undefined1 (*) [16] FUN_1400101e0(undefined1 (*param_1) [16],undefined8 *param_2)

{
  ulonglong uVar1;
  undefined1 uVar2;
  code *pcVar3;
  ulonglong uVar4;
  undefined1 (*pauVar5) [16];
  longlong lVar6;
  uint uVar7;
  char *pcVar8;
  char *pcVar9;
  ulonglong uVar10;
  char *pcVar11;
  char *local_18;
  longlong local_10;
  
  pcVar9 = (char *)*param_2;
  local_10 = param_2[1] + 0x13;
  *param_1 = (undefined1  [16])0x0;
  local_18 = (char *)(DAT_140029878 + DAT_140029888);
  DAT_140029888 = DAT_140029888 + local_10;
  pcVar8 = "resources/textures/";
  pcVar11 = local_18;
  for (lVar6 = 0x13; lVar6 != 0; lVar6 = lVar6 + -1) {
    *pcVar11 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar11 = pcVar11 + 1;
  }
  pcVar8 = local_18 + 0x13;
  for (lVar6 = param_2[1]; lVar6 != 0; lVar6 = lVar6 + -1) {
    *pcVar8 = *pcVar9;
    pcVar9 = pcVar9 + 1;
    pcVar8 = pcVar8 + 1;
  }
  FUN_140013b30(&DAT_140029878,(undefined8 *)param_1,(uint *)(*param_1 + 8),(int *)(*param_1 + 0xc),
                &local_18);
  if (*(longlong *)*param_1 == 0) {
    local_10 = 0x15;
    local_18 = "Failed to read image\n";
    FUN_140002030(&local_18);
    pcVar3 = (code *)swi(3);
    pauVar5 = (undefined1 (*) [16])(*pcVar3)();
    return pauVar5;
  }
  uVar4 = 0;
  uVar10 = uVar4;
  if (*(int *)(*param_1 + 0xc) * *(int *)(*param_1 + 8) != 0) {
    do {
      lVar6 = *(longlong *)*param_1;
      uVar1 = uVar4 + 4;
      uVar7 = (int)uVar10 + 1;
      uVar2 = *(undefined1 *)(lVar6 + -4 + uVar1);
      *(undefined1 *)(lVar6 + -4 + uVar1) = *(undefined1 *)(lVar6 + -2 + uVar1);
      *(undefined1 *)(uVar4 + 2 + *(longlong *)*param_1) = uVar2;
      uVar4 = uVar1;
      uVar10 = (ulonglong)uVar7;
    } while (uVar7 < (uint)(*(int *)(*param_1 + 0xc) * *(int *)(*param_1 + 8)));
  }
  return param_1;
}


// ===== FUN_140010300 @ 140010300 size=724

void FUN_140010300(float *param_1,uint param_2,uint param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined8 uVar5;
  uint uVar6;
  HWND pHVar7;
  uint uVar8;
  longlong lVar9;
  float *pfVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  uint uVar13;
  undefined1 auVar14 [16];
  float fVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  undefined1 auVar19 [64];
  undefined1 auVar20 [64];
  uint local_res10;
  
  pfVar10 = param_1;
  for (lVar9 = (ulonglong)(param_2 * param_3) << 2; lVar9 != 0; lVar9 = lVar9 + -1) {
    *(undefined1 *)pfVar10 = 0;
    pfVar10 = (float *)((longlong)pfVar10 + 1);
  }
  uVar11 = 0;
  local_res10 = 0;
  if (DAT_14002a8b8 != 0) {
    auVar19 = ZEXT464((0.5f));
    auVar20 = ZEXT464((20f));
    dVar18 = DAT_14002a8a0;
    uVar8 = DAT_14002a8b8;
    do {
      lVar9 = DAT_14002a8b0;
      if (dVar18 < *(double *)(*(longlong *)(DAT_14002a8b0 + uVar11 * 0x18) + 0x10) +
                   *(double *)(DAT_14002a8b0 + 8 + uVar11 * 0x18)) {
        uVar13 = 0;
        if (param_2 != 0) {
          dVar16 = (double)param_2;
          dVar17 = (double)(float)param_4;
          pfVar10 = param_1;
          do {
            lVar4 = *(longlong *)(lVar9 + uVar11 * 0x18);
            uVar12 = (ulonglong)
                     (((((double)uVar13 / dVar16) * dVar17 + dVar18) -
                      *(double *)(lVar9 + 8 + uVar11 * 0x18)) * (double)*(uint *)(lVar4 + 0xc));
            if ((uint)uVar12 < *(uint *)(lVar4 + 8)) {
              auVar19 = ZEXT1664(auVar19._0_16_);
              auVar20 = ZEXT1664(auVar20._0_16_);
              pHVar7 = GetForegroundWindow();
              auVar14._0_8_ = -(ulonglong)(pHVar7 == DAT_140029680);
              auVar14._8_8_ = 0xffffffffffffffff;
              auVar14 = vblendvps_avx(auVar20._0_16_,auVar19._0_16_,auVar14);
              fVar15 = *(float *)(**(longlong **)(lVar9 + uVar11 * 0x18) + (uVar12 & 0xffffffff) * 4
                                 ) * *(float *)(lVar9 + 0x10 + uVar11 * 0x18) * auVar14._0_4_;
            }
            else {
              fVar15 = 0.0;
            }
            uVar8 = 0;
            if (param_3 != 0) {
              if (0x1f < param_3) {
                do {
                  *pfVar10 = fVar15 + *pfVar10;
                  pfVar10[1] = fVar15 + pfVar10[1];
                  pfVar10[2] = fVar15 + pfVar10[2];
                  pfVar10[3] = fVar15 + pfVar10[3];
                  pfVar10[4] = fVar15 + pfVar10[4];
                  pfVar10[5] = fVar15 + pfVar10[5];
                  pfVar10[6] = fVar15 + pfVar10[6];
                  pfVar10[7] = fVar15 + pfVar10[7];
                  pfVar10[8] = fVar15 + pfVar10[8];
                  pfVar10[9] = fVar15 + pfVar10[9];
                  pfVar10[10] = fVar15 + pfVar10[10];
                  pfVar10[0xb] = fVar15 + pfVar10[0xb];
                  pfVar10[0xc] = fVar15 + pfVar10[0xc];
                  pfVar10[0xd] = fVar15 + pfVar10[0xd];
                  pfVar10[0xe] = fVar15 + pfVar10[0xe];
                  pfVar10[0xf] = fVar15 + pfVar10[0xf];
                  pfVar10[0x10] = fVar15 + pfVar10[0x10];
                  pfVar10[0x11] = fVar15 + pfVar10[0x11];
                  pfVar10[0x12] = fVar15 + pfVar10[0x12];
                  pfVar10[0x13] = fVar15 + pfVar10[0x13];
                  pfVar10[0x14] = fVar15 + pfVar10[0x14];
                  pfVar10[0x15] = fVar15 + pfVar10[0x15];
                  pfVar10[0x16] = fVar15 + pfVar10[0x16];
                  pfVar10[0x17] = fVar15 + pfVar10[0x17];
                  pfVar10[0x18] = fVar15 + pfVar10[0x18];
                  pfVar10[0x19] = fVar15 + pfVar10[0x19];
                  pfVar10[0x1a] = fVar15 + pfVar10[0x1a];
                  pfVar10[0x1b] = fVar15 + pfVar10[0x1b];
                  pfVar10[0x1c] = fVar15 + pfVar10[0x1c];
                  pfVar10[0x1d] = fVar15 + pfVar10[0x1d];
                  pfVar10[0x1e] = fVar15 + pfVar10[0x1e];
                  pfVar10[0x1f] = fVar15 + pfVar10[0x1f];
                  pfVar10 = pfVar10 + 0x20;
                  uVar8 = uVar8 + 0x20;
                } while (uVar8 < (param_3 & 0xffffffe0));
                if (param_3 <= uVar8) goto LAB_14001054c;
              }
              if (3 < param_3 - uVar8) {
                uVar6 = ((param_3 - uVar8) - 4 >> 2) + 1;
                uVar12 = (ulonglong)uVar6;
                uVar8 = uVar8 + uVar6 * 4;
                do {
                  *pfVar10 = fVar15 + *pfVar10;
                  pfVar10[1] = fVar15 + pfVar10[1];
                  pfVar10[2] = fVar15 + pfVar10[2];
                  pfVar10[3] = fVar15 + pfVar10[3];
                  pfVar10 = pfVar10 + 4;
                  uVar12 = uVar12 - 1;
                } while (uVar12 != 0);
                if (param_3 <= uVar8) goto LAB_14001054c;
              }
              uVar12 = (ulonglong)(param_3 - uVar8);
              do {
                *pfVar10 = fVar15 + *pfVar10;
                pfVar10 = pfVar10 + 1;
                uVar12 = uVar12 - 1;
              } while (uVar12 != 0);
            }
LAB_14001054c:
            uVar13 = uVar13 + 1;
          } while (uVar13 < param_2);
          goto LAB_140010567;
        }
      }
      else {
        DAT_14002a8b8 = uVar8 - 1;
        local_res10 = (int)uVar11 - 1;
        puVar1 = (undefined8 *)(DAT_14002a8b0 + (ulonglong)DAT_14002a8b8 * 0x18);
        uVar5 = puVar1[1];
        uVar3 = *(undefined8 *)(DAT_14002a8b0 + 0x10 + (ulonglong)DAT_14002a8b8 * 0x18);
        puVar2 = (undefined8 *)(DAT_14002a8b0 + uVar11 * 0x18);
        *puVar2 = *puVar1;
        puVar2[1] = uVar5;
        *(undefined8 *)(lVar9 + 0x10 + uVar11 * 0x18) = uVar3;
LAB_140010567:
        uVar11 = (ulonglong)local_res10;
        uVar8 = DAT_14002a8b8;
      }
      local_res10 = (int)uVar11 + 1;
      uVar11 = (ulonglong)local_res10;
    } while (local_res10 < uVar8);
  }
  return;
}


// ===== FUN_1400105e0 @ 1400105e0 size=495

void FUN_1400105e0(int param_1,float param_2)

{
  int iVar1;
  undefined8 uVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float local_res18;
  float fStackX_1c;
  
  if ((DAT_1400298bc < 9) && (param_2 == 0.0)) {
    iVar1 = (DAT_1400296d0 -
            *(int *)(&DAT_1400298c8 + (ulonglong)DAT_1400298bc * 0x10) * DAT_140029070) / 2;
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    fVar3 = (float)iVar1;
    fVar6 = (float)(uint)(*(int *)(&DAT_1400298c8 + (ulonglong)DAT_1400298bc * 0x10) * DAT_140029070
                         ) + fVar3;
    iVar1 = DAT_1400296d4 -
            DAT_140029070 * *(int *)(&DAT_1400298cc + (ulonglong)DAT_1400298bc * 0x10);
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    fVar4 = (float)iVar1;
    fVar5 = (float)(uint)(DAT_140029070 * *(int *)(&DAT_1400298cc + (ulonglong)DAT_1400298bc * 0x10)
                         ) + fVar4;
    uVar2 = FUN_140009a10();
    local_res18 = (float)uVar2;
    if ((((fVar3 <= local_res18) && (local_res18 <= fVar6)) &&
        (fStackX_1c = (float)((ulonglong)uVar2 >> 0x20), fVar4 <= fStackX_1c)) &&
       (fStackX_1c <= fVar5)) {
      DAT_1400298bc = DAT_1400298bc + 1;
    }
  }
  if (((DAT_14002998c != 0) && (DAT_140029970 == 0)) && (param_2 == 0.0)) {
    iVar1 = (DAT_1400296d0 -
            *(int *)(&DAT_1400298c8 + (ulonglong)DAT_1400298bc * 0x10) * DAT_140029070) / 2;
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    fVar3 = (float)iVar1;
    fVar6 = (float)(uint)(*(int *)(&DAT_1400298c8 + (ulonglong)DAT_1400298bc * 0x10) * DAT_140029070
                         ) + fVar3;
    iVar1 = DAT_1400296d4 -
            DAT_140029070 * *(int *)(&DAT_1400298cc + (ulonglong)DAT_1400298bc * 0x10);
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    fVar4 = (float)iVar1;
    fVar5 = (float)(uint)(DAT_140029070 * *(int *)(&DAT_1400298cc + (ulonglong)DAT_1400298bc * 0x10)
                         ) + fVar4;
    uVar2 = FUN_140009a10();
    local_res18 = (float)uVar2;
    if (((fVar3 <= local_res18) && (local_res18 <= fVar6)) &&
       ((fStackX_1c = (float)((ulonglong)uVar2 >> 0x20), fVar4 <= fStackX_1c &&
        (fStackX_1c <= fVar5)))) {
      DAT_140029970 = DAT_140029970 + 1;
    }
  }
  FUN_1400107d0(param_1,param_2);
  return;
}


// ===== FUN_1400107d0 @ 1400107d0 size=1822

void FUN_1400107d0(int param_1,float param_2)

{
  char cVar1;
  int *piVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined8 uVar7;
  int *piVar8;
  int iVar9;
  uint uVar10;
  char *pcVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  float fVar15;
  undefined1 auVar16 [16];
  undefined8 uVar17;
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  tagPOINT local_res18;
  
  if (param_1 == 0) {
    if (param_2 <= 0.0) {
      uVar6 = (uint)(param_2 < 0.0);
      if (uVar6 == 0) {
        return;
      }
    }
    else {
      uVar6 = 0xffffffff;
    }
    if (DAT_140029710 == '\0') {
      uVar7 = FUN_140009a10();
      iVar9 = DAT_140029020 - uVar6;
      if (iVar9 < 1) {
        iVar9 = 1;
      }
      if (200 < iVar9) {
        iVar9 = 200;
      }
      if (iVar9 == DAT_140029020) {
        return;
      }
      local_res18.y = (LONG)((ulonglong)uVar7 >> 0x20);
      local_res18.x = (LONG)uVar7;
      fVar15 = (1f) / (float)(DAT_140029020 << 4);
      DAT_140029020 = iVar9;
      auVar16 = ZEXT416((-250f));
      auVar18 = vmaxss_avx(ZEXT416((uint)((float)(iVar9 * (int)DAT_140029a88 * 0x10 - DAT_1400296d0)
                                         + (250f))),auVar16);
      auVar19 = vmaxss_avx(auVar16,ZEXT416((uint)((float)(iVar9 << 4) *
                                                  ((float)local_res18.x + DAT_140029630) * fVar15 -
                                                 (float)local_res18.x)));
      auVar18 = vminss_avx(auVar18,auVar19);
      DAT_140029630 = (float)auVar18._0_4_;
      auVar18 = vmaxss_avx(ZEXT416((uint)((float)(iVar9 * DAT_140029a88._4_4_ * 0x10 - DAT_1400296d4
                                                 ) + (250f))),auVar16);
      auVar19 = vmaxss_avx(auVar16,ZEXT416((uint)((float)(iVar9 << 4) *
                                                  ((float)local_res18.y + DAT_140029634) * fVar15 -
                                                 (float)local_res18.y)));
      auVar18 = vminss_avx(auVar18,auVar19);
      DAT_140029634 = (float)auVar18._0_4_;
      return;
    }
    auVar16 = ZEXT416((-250f));
    auVar18 = vmaxss_avx(ZEXT416((uint)((float)((int)DAT_140029a88 * DAT_140029020 * 0x10 -
                                               DAT_1400296d0) + (250f))),auVar16);
    auVar19 = vmaxss_avx(auVar16,ZEXT416((uint)((float)(DAT_140029020 << 4) * (float)(int)uVar6 *
                                                (2.5f) + DAT_140029630)));
    auVar18 = vminss_avx(auVar18,auVar19);
    DAT_140029630 = (float)auVar18._0_4_;
    auVar18 = vmaxss_avx(auVar16,ZEXT416((uint)DAT_140029634));
    auVar19 = vmaxss_avx(ZEXT416((uint)((float)(DAT_140029a88._4_4_ * DAT_140029020 * 0x10 -
                                               DAT_1400296d4) + (250f))),auVar16);
    auVar18 = vminss_avx(auVar19,auVar18);
    DAT_140029634 = (float)auVar18._0_4_;
    return;
  }
  uVar6 = 0;
  local_res18.x = 0;
  local_res18.y = 0;
  GetCursorPos(&local_res18);
  ScreenToClient(DAT_140029680,&local_res18);
  auVar18._0_4_ = (float)local_res18.x;
  auVar18._4_8_ = SUB128(ZEXT812(0),4);
  auVar18._12_4_ = 0;
  auVar19._0_4_ = (float)local_res18.y;
  auVar19._4_8_ = SUB128(ZEXT812(0),4);
  auVar19._12_4_ = 0;
  if (param_1 == 2) {
    if (param_2 == 1.4013e-45) {
      if (DAT_1400298ac != 0) {
        iVar9 = 1;
        if (1 < DAT_140029044 * DAT_140029040) {
          iVar9 = DAT_140029044 * DAT_140029040;
        }
        iVar12 = 0x60;
        if (0x60 < iVar9 + 0x18) {
          iVar12 = iVar9 + 0x18;
        }
        uVar4 = (DAT_1400296d0 + (DAT_140029048 + DAT_14002904c) * -2) / iVar12;
        uVar6 = 1;
        if (1 < (int)uVar4) {
          uVar6 = uVar4;
        }
        if ((int)uVar6 < 1) {
          uVar6 = 1;
        }
        if (0xc < (int)uVar6) {
          uVar6 = 0xc;
        }
        uVar4 = (uint)((int)(0xc % (ulonglong)uVar6) != 0) + (int)(0xc / (ulonglong)uVar6);
        iVar9 = uVar6 * iVar12 + DAT_14002904c * 2;
        uVar6 = 1;
        if (1 < uVar4) {
          uVar6 = uVar4;
        }
        iVar13 = (DAT_1400296d0 - iVar9) - DAT_140029048;
        iVar14 = 0;
        if (0 < iVar13) {
          iVar14 = iVar13;
        }
        if (((((int)auVar18._0_4_ < iVar14) || (iVar14 + iVar9 <= (int)auVar18._0_4_)) ||
            ((int)auVar19._0_4_ < DAT_140029048)) ||
           ((int)(DAT_140029048 + uVar6 * iVar12 + DAT_14002904c * 2) <= (int)auVar19._0_4_)) {
          DAT_14002a890 = (int *)0x0;
          DAT_1400298ac = 0;
        }
      }
      if (DAT_14002965c != 0) {
        return;
      }
      local_res18.x = 0;
      local_res18.y = 0;
      uVar7 = FUN_140011060(&local_res18);
      if ((int)uVar7 == 0) {
        return;
      }
      piVar8 = (int *)FUN_140009990((longlong)local_res18,0);
      piVar2 = DAT_14002a890;
      if (DAT_140029980 != 0) {
        return;
      }
      if (piVar8 == (int *)0x0) {
        return;
      }
      if (*(longlong *)(piVar8 + 2) == 0) {
        return;
      }
      if (*piVar8 == 1) {
        return;
      }
      if (*(longlong *)(piVar8 + 0x48) == 0) {
        return;
      }
      if (*(uint *)(*(longlong *)(piVar8 + 0x48) + 0x10) < 2) {
        return;
      }
      DAT_14002a890 = (int *)0x0;
      DAT_1400298ac = 0;
      DAT_14002965c = 0;
      DAT_140029024 = 0xe;
      if (piVar2 == piVar8) {
        DAT_140029024 = 0xe;
        DAT_14002965c = 0;
        DAT_1400298ac = 0;
        DAT_14002a890 = (int *)0x0;
        return;
      }
      FUN_140012280(piVar8);
      DAT_1400296f8 = 1;
      DAT_1400296fc = 0;
      DAT_1400298a8 = 0;
      DAT_1400298b8 = 1;
      return;
    }
  }
  else {
    if (param_1 != 1) {
      return;
    }
    if (param_2 == 1.4013e-45) {
      auVar16 = vunpcklps_avx(auVar18,auVar19);
      uVar17 = auVar16._0_8_;
      uVar7 = FUN_140005fe0(uVar17);
      DAT_1400296f8 = (int)uVar7;
      if (DAT_1400296f8 != 0) {
        return;
      }
      iVar9 = 0;
      if (DAT_1400298ac != 0) {
        uVar7 = FUN_140009fe0(uVar17);
        iVar9 = (int)uVar7;
        if (iVar9 != 0) {
          DAT_1400296f8 = iVar9;
          return;
        }
      }
      DAT_1400296f8 = iVar9;
      if (DAT_14002965c != 0) {
        iVar9 = 1;
        if (1 < DAT_140029044 * DAT_140029040) {
          iVar9 = DAT_140029044 * DAT_140029040;
        }
        uVar5 = (DAT_1400296d0 + (DAT_140029048 + DAT_14002904c) * -2) / iVar9;
        uVar4 = 1;
        if (1 < (int)uVar5) {
          uVar4 = uVar5;
        }
        auVar16 = ZEXT816(0) << 0x40 | ZEXT816(0x16);
        uVar5 = (uint)(SUB168(auVar16 % ZEXT416(uVar4),0) != 0) + SUB164(auVar16 / ZEXT416(uVar4),0)
        ;
        iVar14 = ((DAT_1400296d0 + DAT_14002904c * -2) - uVar4 * iVar9) - DAT_140029048;
        iVar12 = 0;
        if (0 < iVar14) {
          iVar12 = iVar14;
        }
        iVar14 = ((int)auVar19._0_4_ - DAT_140029048) - DAT_14002904c;
        iVar12 = ((int)auVar18._0_4_ - iVar12) - DAT_14002904c;
        if (iVar12 < 0) {
          DAT_1400296f8 = 0;
          return;
        }
        if ((int)(uVar4 * iVar9) <= iVar12) {
          DAT_1400296f8 = 0;
          return;
        }
        if (iVar14 < 0) {
          DAT_1400296f8 = 0;
          return;
        }
        uVar10 = 1;
        if (1 < uVar5) {
          uVar10 = uVar5;
        }
        if ((int)(uVar10 * iVar9) <= iVar14) {
          DAT_1400296f8 = 0;
          return;
        }
        uVar4 = (iVar14 / iVar9) * uVar4 + iVar12 / iVar9;
        if ((int)uVar4 < 0) {
          DAT_1400296f8 = 1;
          return;
        }
        if (0x15 < uVar4) {
          DAT_1400296f8 = 1;
          return;
        }
        pcVar11 = &DAT_140029028;
        cVar1 = (&DAT_140029028)[uVar4];
        cVar3 = cVar1;
        if (DAT_14002962c == cVar1) {
          cVar3 = '\0';
        }
        do {
          if (*pcVar11 == cVar1) {
            DAT_14002962c = cVar3;
            DAT_140029658 = uVar6;
            DAT_14002965c = 0;
            DAT_140029660 = 1;
            DAT_140029664 = 0;
            DAT_1400296f8 = 1;
            return;
          }
          uVar6 = uVar6 + 1;
          pcVar11 = pcVar11 + 1;
        } while (uVar6 < 0x16);
        DAT_14002962c = cVar3;
        DAT_14002965c = 0;
        DAT_140029660 = 1;
        DAT_140029664 = 0;
        DAT_1400296f8 = 1;
        return;
      }
      if (DAT_140029af0 != 0) {
        uVar7 = FUN_140006170(uVar17);
        if ((int)uVar7 != 0) {
          DAT_1400296f8 = (int)uVar7;
          return;
        }
        DAT_1400296f8 = 0;
        if (DAT_14002a890 != (int *)0x0) {
          DAT_14002a890 = (int *)0x0;
          DAT_1400298ac = 0;
        }
      }
      if (DAT_140029024 != 0xe) {
        local_res18.x = 0;
        local_res18.y = 0;
        uVar7 = FUN_140011060(&local_res18);
        if ((int)uVar7 == 0) {
          return;
        }
        uVar7 = FUN_140013380((longlong)local_res18,DAT_140029024,1);
        if ((int)uVar7 == 0) {
          return;
        }
        if (DAT_140029710 == '\0') {
          DAT_140029024 = 0xe;
        }
        DAT_1400296f8 = 1;
        return;
      }
      if (DAT_14002965c != 0) {
        return;
      }
      if (DAT_140029af0 != 0) {
        return;
      }
      if (DAT_140029710 != '\0') {
        return;
      }
      local_res18.x = 0;
      local_res18.y = 0;
      uVar7 = FUN_140011060(&local_res18);
      if ((int)uVar7 == 0) {
        return;
      }
      uVar7 = FUN_140013030((longlong)local_res18,1);
      if ((int)uVar7 == 0) {
        return;
      }
      DAT_1400296fc = 0;
      DAT_1400298a8 = 0;
      DAT_1400298b8 = 1;
      return;
    }
  }
  if (param_2 == 0.0) {
    DAT_1400296fc = 0;
    DAT_1400298a8 = 0;
    if (param_1 == 1) {
      DAT_1400296ec = 0;
      DAT_1400296f8 = 0;
    }
    else {
      DAT_1400298b8 = 0;
    }
  }
  return;
}


// ===== FUN_140010ef0 @ 140010ef0 size=368

undefined8 FUN_140010ef0(longlong param_1,int param_2)

{
  longlong lVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined8 uVar4;
  int iVar5;
  int iVar6;
  float local_res8;
  float fStackX_c;
  
  if ((param_1 != 0) && (*(longlong *)(param_1 + 8) != 0)) {
    uVar4 = FUN_140009a10();
    auVar2 = vroundps_avx(ZEXT416(DAT_140029630),1);
    auVar3 = vroundps_avx(ZEXT416(DAT_140029634),1);
    fStackX_c = (float)((ulonglong)uVar4 >> 0x20);
    iVar6 = (int)*(undefined8 *)(param_1 + 0x20) * DAT_140029020 * 0x10 - (int)auVar2._0_4_;
    local_res8 = (float)uVar4;
    iVar5 = (int)((ulonglong)*(undefined8 *)(param_1 + 0x20) >> 0x20) * DAT_140029020 * 0x10 -
            (int)auVar3._0_4_;
    if (((float)iVar6 <= local_res8) &&
       (((local_res8 < (float)(param_2 * *(int *)(param_1 + 0x2c) * 0x10 + iVar6) &&
         ((float)iVar5 <= fStackX_c)) &&
        (fStackX_c < (float)(param_2 * *(int *)(param_1 + 0x30) * 0x10 + iVar5))))) {
      return 1;
    }
    lVar1 = *(longlong *)(param_1 + 0x10);
    if (lVar1 != 0) {
      iVar6 = ((*(int *)(param_1 + 0x2c) * 0x10 - *(int *)(lVar1 + 0x10)) * param_2) / 2 + iVar6;
      iVar5 = (*(int *)(param_1 + 0x30) * 0x10 - *(int *)(lVar1 + 0x14)) * param_2 + iVar5;
      if ((((float)iVar6 <= local_res8) &&
          (local_res8 < (float)(*(int *)(lVar1 + 0x10) * param_2 + iVar6))) &&
         (((float)iVar5 <= fStackX_c &&
          (fStackX_c < (float)(*(int *)(lVar1 + 0x14) * param_2 + iVar5))))) {
        return 1;
      }
    }
  }
  return 0;
}


// ===== FUN_140011060 @ 140011060 size=211

undefined8 FUN_140011060(tagPOINT *param_1)

{
  undefined1 auVar1 [16];
  float fVar2;
  tagPOINT local_res10 [3];
  
  local_res10[0].x = 0;
  local_res10[0].y = 0;
  GetCursorPos(local_res10);
  ScreenToClient(DAT_140029680,local_res10);
  fVar2 = (1f) / (float)(DAT_140029020 << 4);
  auVar1 = vroundps_avx(ZEXT416((uint)(fVar2 * ((float)local_res10[0].x + DAT_140029630))),1);
  local_res10[0].x = (LONG)auVar1._0_4_;
  auVar1 = vroundps_avx(ZEXT416((uint)(fVar2 * ((float)local_res10[0].y + DAT_140029634))),1);
  local_res10[0].y = (LONG)auVar1._0_4_;
  if ((((-1 < local_res10[0].x) && (-1 < local_res10[0].y)) &&
      (local_res10[0].x < (int)DAT_140029a88)) && (local_res10[0].y < DAT_140029a88._4_4_)) {
    *param_1 = local_res10[0];
    return 1;
  }
  return 0;
}


// ===== FUN_140011140 @ 140011140 size=2903

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140011140(ulonglong *param_1,ulonglong param_2,float param_3,int param_4)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined8 uVar3;
  uint uVar4;
  float *pfVar6;
  ulonglong uVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  undefined1 auVar14 [16];
  undefined1 auVar15 [16];
  undefined1 auVar16 [16];
  undefined1 auVar17 [16];
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  float fVar20;
  undefined1 auVar21 [16];
  undefined1 auVar22 [16];
  undefined1 auVar23 [16];
  undefined1 auVar24 [16];
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  ulonglong uVar29;
  undefined1 auVar30 [16];
  float fVar31;
  undefined1 auVar32 [64];
  float fVar33;
  float fVar34;
  float local_res8;
  float fStackX_c;
  undefined8 local_148;
  float fStack_12c;
  float local_128 [5];
  float local_114;
  float local_110;
  float local_10c;
  float local_108;
  float local_104;
  ulonglong local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  ulonglong uVar5;
  
  auVar12 = _DAT_140025040;
  auVar13._8_8_ = 0;
  auVar13._0_8_ = *param_1;
  auVar13 = vshufps_avx(auVar13,auVar13,0x55);
  fVar25 = (float)param_2 - (float)*param_1;
  fStack_12c = (float)(param_2 >> 0x20);
  fVar27 = fStack_12c - auVar13._0_4_;
  fVar10 = fVar27 * fVar27 + fVar25 * fVar25;
  if (fVar10 <= (9.99999975e-05f)) {
    *param_1 = param_2;
LAB_1400111a6:
    param_1[1] = 0;
    return;
  }
  if (param_3 <= 0.0) goto LAB_1400111a6;
  auVar1 = vsqrtps_avx(ZEXT416((uint)fVar10));
  fVar20 = auVar1._0_4_;
  fVar25 = ((1f) / fVar20) * fVar25;
  fVar27 = ((1f) / fVar20) * fVar27;
  fVar10 = param_3 + *(float *)((longlong)param_1 + 0x2c);
  *(float *)((longlong)param_1 + 0x2c) = fVar10;
  fVar11 = (1f);
  fVar33 = (9.99999905e-09f);
  auVar30 = ZEXT816(0) << 0x40;
  fVar10 = *(float *)(param_1 + 0x40f) + fVar10;
  fVar9 = fVar10 * (0.239999995f) + *(float *)(param_1 + 6);
  fVar26 = (*(float *)(param_1 + 0x40f) * (0.709999979f) + fVar9) - (0.25f);
  auVar21._4_4_ = fVar26;
  auVar21._0_4_ = fVar26;
  auVar21._8_4_ = fVar26;
  auVar21._12_4_ = fVar26;
  auVar13 = vroundps_avx(auVar21,9);
  auVar13 = vsubps_avx(auVar21,auVar13);
  auVar21 = vcmpps_avx(_DAT_140025030,auVar13,2);
  auVar22 = vsubps_avx(auVar13,_DAT_140025030);
  auVar13 = vblendvps_avx(auVar13,auVar22,auVar21);
  auVar22 = vfmadd231ps_fma(_DAT_140025050,auVar13,_DAT_1400250b0);
  auVar22 = vfmadd231ps_fma(_DAT_140025090,auVar13,auVar22);
  auVar22 = vfmadd231ps_fma(_DAT_1400250a0,auVar13,auVar22);
  auVar22 = vfmadd231ps_fma(_DAT_140025080,auVar13,auVar22);
  auVar12 = vfmadd231ps_fma(auVar12,auVar13,auVar22);
  auVar13 = vsubps_avx(auVar30,auVar12);
  auVar13 = vblendvps_avx(auVar12,auVar13,auVar21);
  fVar9 = (fVar9 * (1.61000001f) + *(float *)((longlong)param_1 + 0x207c) * (1.37f)) -
          (0.25f);
  auVar22._4_4_ = fVar9;
  auVar22._0_4_ = fVar9;
  auVar22._8_4_ = fVar9;
  auVar22._12_4_ = fVar9;
  auVar12 = vroundps_avx(auVar22,9);
  auVar12 = vsubps_avx(auVar22,auVar12);
  auVar21 = vcmpps_avx(_DAT_140025030,auVar12,2);
  auVar22 = vsubps_avx(auVar12,_DAT_140025030);
  auVar12 = vblendvps_avx(auVar12,auVar22,auVar21);
  auVar22 = vfmadd231ps_fma(_DAT_140025050,auVar12,_DAT_1400250b0);
  auVar22 = vfmadd231ps_fma(_DAT_140025090,auVar12,auVar22);
  auVar22 = vfmadd231ps_fma(_DAT_1400250a0,auVar12,auVar22);
  auVar22 = vfmadd231ps_fma(_DAT_140025080,auVar12,auVar22);
  auVar22 = vfmadd231ps_fma(_DAT_140025040,auVar12,auVar22);
  auVar12 = vsubps_avx(auVar30,auVar22);
  auVar12 = vblendvps_avx(auVar22,auVar12,auVar21);
  fVar9 = (*(float *)((longlong)param_1 + 0x207c) * (3.1099999f) + fVar10 * (0.50999999f)) -
          (0.25f);
  auVar23._4_4_ = fVar9;
  auVar23._0_4_ = fVar9;
  auVar23._8_4_ = fVar9;
  auVar23._12_4_ = fVar9;
  auVar21 = vroundps_avx(auVar23,9);
  auVar21 = vsubps_avx(auVar23,auVar21);
  auVar22 = vcmpps_avx(_DAT_140025030,auVar21,2);
  auVar14 = vsubps_avx(auVar21,_DAT_140025030);
  auVar21 = vblendvps_avx(auVar21,auVar14,auVar22);
  auVar14 = vfmadd231ps_fma(_DAT_140025050,auVar21,_DAT_1400250b0);
  auVar14 = vfmadd231ps_fma(_DAT_140025090,auVar21,auVar14);
  auVar14 = vfmadd231ps_fma(_DAT_1400250a0,auVar21,auVar14);
  auVar14 = vfmadd231ps_fma(_DAT_140025080,auVar21,auVar14);
  auVar14 = vfmadd231ps_fma(_DAT_140025040,auVar21,auVar14);
  auVar21 = vsubps_avx(auVar30,auVar14);
  auVar21 = vblendvps_avx(auVar14,auVar21,auVar22);
  fVar10 = (fVar10 * (0.930000007f) + *(float *)(param_1 + 0x40f) * (1.28999996f)) - (0.25f);
  auVar24._4_4_ = fVar10;
  auVar24._0_4_ = fVar10;
  auVar24._8_4_ = fVar10;
  auVar24._12_4_ = fVar10;
  auVar22 = vroundps_avx(auVar24,9);
  auVar22 = vsubps_avx(auVar24,auVar22);
  auVar14 = vcmpps_avx(_DAT_140025030,auVar22,2);
  auVar23 = vsubps_avx(auVar22,_DAT_140025030);
  auVar22 = vblendvps_avx(auVar22,auVar23,auVar14);
  auVar23 = vfmadd231ps_fma(_DAT_140025050,auVar22,_DAT_1400250b0);
  auVar23 = vfmadd231ps_fma(_DAT_140025090,auVar22,auVar23);
  auVar23 = vfmadd231ps_fma(_DAT_1400250a0,auVar22,auVar23);
  auVar23 = vfmadd231ps_fma(_DAT_140025080,auVar22,auVar23);
  auVar23 = vfmadd231ps_fma(_DAT_140025040,auVar22,auVar23);
  auVar22 = vsubps_avx(auVar30,auVar23);
  auVar22 = vblendvps_avx(auVar23,auVar22,auVar14);
  fVar34 = (float)((uint)fVar27 ^ _DAT_140025070);
  auVar14._0_4_ = fVar20 / (1.20000005f);
  auVar14._4_12_ = auVar1._4_12_;
  auVar30 = ZEXT816(0) << 0x40;
  fVar26 = 0.0;
  auVar14 = vmaxss_avx(auVar30,auVar14);
  auVar24 = ZEXT416((uint)(1f));
  auVar14 = vminss_avx(auVar24,auVar14);
  auVar23 = vminss_avx(ZEXT416((0.0500000007f)),ZEXT416((uint)(fVar20 * (0.180000007f))));
  fVar10 = (auVar14._0_4_ * (0.850000024f) + (0.150000006f)) * auVar23._0_4_ *
           (auVar13._0_4_ * (0.720000029f) + auVar12._0_4_ * (0.280000001f));
  local_148._0_4_ = fVar10 * fVar34 + fVar25;
  fVar10 = fVar10 * fVar25 + fVar27;
  fVar9 = fVar10 * fVar10 + (float)local_148 * (float)local_148;
  if ((9.99999905e-09f) < fVar9) {
    auVar13 = vsqrtps_avx(ZEXT416((uint)fVar9));
    fVar9 = (1f) / auVar13._0_4_;
    local_148._0_4_ = (float)local_148 * fVar9;
    fVar10 = fVar10 * fVar9;
  }
  else {
    local_148._0_4_ = 0.0;
    auVar13 = vshufps_avx(ZEXT816(0),ZEXT816(0),0x55);
    fVar10 = auVar13._0_4_;
  }
  fVar9 = (auVar21._0_4_ * (0.699999988f) + auVar22._0_4_ * (0.300000012f)) * (0.0799999982f) +
          (1f);
  if ((param_4 != 0) && (fVar20 < (0.600000024f))) {
    auVar12._0_4_ = fVar20 / (0.600000024f);
    auVar12._4_12_ = auVar1._4_12_;
    auVar13 = vmaxss_avx(auVar30,auVar12);
    auVar13 = vminss_avx(auVar24,auVar13);
    fVar9 = fVar9 * (auVar13._0_4_ * (0.300000012f) + (0.699999988f));
  }
  auVar13 = vmaxss_avx(auVar30,ZEXT416((uint)(param_3 * (7f))));
  auVar13 = vminss_avx(auVar24,auVar13);
  fVar20 = auVar13._0_4_ *
           (fVar9 * *(float *)(param_1 + 4) * (float)local_148 - *(float *)(param_1 + 1)) +
           *(float *)(param_1 + 1);
  fVar10 = auVar13._0_4_ *
           (fVar9 * *(float *)(param_1 + 4) * fVar10 - *(float *)((longlong)param_1 + 0xc)) +
           *(float *)((longlong)param_1 + 0xc);
  *(float *)((longlong)param_1 + 0xc) = fVar10;
  auVar13 = vunpcklps_avx(ZEXT416((uint)fVar20),ZEXT416((uint)fVar10));
  *(float *)(param_1 + 1) = fVar20;
  fVar9 = *(float *)(param_1 + 4) * (1.08000004f);
  local_148 = auVar13._0_8_;
  if (fVar9 * fVar9 < fVar10 * fVar10 + fVar20 * fVar20) {
    auVar12 = vshufps_avx(auVar13,auVar13,0x55);
    local_148._0_4_ = auVar13._0_4_;
    fVar20 = auVar12._0_4_;
    fVar10 = fVar20 * fVar20 + (float)local_148 * (float)local_148;
    if (fVar33 < fVar10) {
      auVar30._8_8_ = 0;
      auVar30._0_8_ = SUB648(ZEXT6064((undefined1  [60])0x0),4);
      auVar15._4_12_ = SUB1612(auVar30 << 0x40,4);
      auVar15._0_4_ = fVar10;
      auVar13 = vsqrtps_avx(auVar15);
      fVar11 = fVar11 / auVar13._0_4_;
      local_148._0_4_ = (float)local_148 * fVar11;
      fVar20 = fVar20 * fVar11;
    }
    else {
      local_148._0_4_ = 0.0;
      auVar13 = vshufps_avx(ZEXT816(0),ZEXT816(0),0x55);
      fVar20 = auVar13._0_4_;
    }
    fVar10 = (float)local_148 * fVar9;
    *(float *)((longlong)param_1 + 0xc) = fVar20 * fVar9;
    auVar13 = vunpcklps_avx(ZEXT416((uint)fVar10),ZEXT416((uint)(fVar20 * fVar9)));
    local_148 = auVar13._0_8_;
    *(float *)(param_1 + 1) = fVar10;
  }
  fVar9 = param_3 * local_148._4_4_;
  fVar20 = (float)param_2 - (float)*param_1;
  local_148._4_4_ = (float)(*param_1 >> 0x20);
  fVar28 = fStack_12c - local_148._4_4_;
  fVar10 = fVar28 * fVar28 + fVar20 * fVar20;
  auVar12 = ZEXT416((uint)(fVar28 * fVar9 + fVar20 * param_3 * (float)local_148));
  auVar13 = vcmpss_avx(ZEXT416((uint)fVar10),auVar12,1);
  auVar13 = vblendvps_avx(ZEXT416((uint)fVar9),ZEXT416((uint)fVar28),auVar13);
  fVar31 = auVar13._0_4_;
  auVar13 = vcmpss_avx(ZEXT416((uint)fVar10),auVar12,1);
  auVar13 = vblendvps_avx(ZEXT416((uint)(param_3 * (float)local_148)),ZEXT416((uint)fVar20),auVar13)
  ;
  fVar8 = auVar13._0_4_;
  fVar9 = (float)*param_1 + fVar8;
  local_148._4_4_ = fVar31 + local_148._4_4_;
  auVar13 = vunpcklps_avx(ZEXT416((uint)fVar9),ZEXT416((uint)local_148._4_4_));
  uStack_f0 = auVar1._8_8_;
  local_f8 = auVar13._0_8_;
  uVar3 = FUN_140012bb0(param_1,auVar13._0_8_);
  fVar11 = auVar24._0_4_;
  if ((int)uVar3 == 0) {
    *param_1 = local_f8;
    fVar10 = (0.550000012f);
    fVar9 = fVar9 - (float)param_2;
    local_148._4_4_ = local_148._4_4_ - fStack_12c;
    if ((9.99999975e-05f) < local_148._4_4_ * local_148._4_4_ + fVar9 * fVar9) {
      return;
    }
    *param_1 = param_2;
    *(float *)((longlong)param_1 + 0xc) = fVar10 * *(float *)((longlong)param_1 + 0xc);
    *(float *)(param_1 + 1) = fVar10 * *(float *)(param_1 + 1);
    return;
  }
  auVar13 = vsqrtps_avx(ZEXT416((uint)(fVar31 * fVar31 + fVar8 * fVar8)));
  auVar32 = ZEXT1664(auVar13);
  if (fVar26 < auVar13._0_4_) {
    local_res8 = fVar34 * (0.850000024f) + fVar25;
    local_128[3] = fVar25 * (0.850000024f) + fVar27;
    local_e8 = _DAT_140025020;
    uStack_e0 = _UNK_140025028;
    fVar9 = local_128[3] * local_128[3] + local_res8 * local_res8;
    local_128[0] = fVar25;
    local_128[1] = fVar27;
    if (fVar33 < fVar9) {
      auVar13 = vsqrtps_avx(ZEXT416((uint)fVar9));
      fVar9 = fVar11 / auVar13._0_4_;
      local_res8 = local_res8 * fVar9;
      local_128[3] = local_128[3] * fVar9;
    }
    else {
      local_res8 = 0.0;
      auVar13 = vshufps_avx(ZEXT816(0),ZEXT816(0),0x55);
      local_128[3] = auVar13._0_4_;
    }
    fVar26 = fVar25 - fVar34 * (0.850000024f);
    fVar27 = fVar27 - fVar25 * (0.850000024f);
    local_128[2] = local_res8;
    fVar9 = fVar27 * fVar27 + fVar26 * fVar26;
    if (fVar33 < fVar9) {
      auVar13 = vsqrtps_avx(ZEXT416((uint)fVar9));
      local_114 = fVar11 / auVar13._0_4_;
      local_res8 = local_114 * fVar26;
      local_114 = local_114 * fVar27;
    }
    else {
      local_res8 = 0.0;
      auVar13 = vshufps_avx(ZEXT816(0),ZEXT816(0),0x55);
      local_114 = auVar13._0_4_;
    }
    local_128[4] = local_res8;
    fVar27 = fVar34 * fVar34 + fVar25 * fVar25;
    if (fVar33 < fVar27) {
      auVar1._8_8_ = 0;
      auVar1._0_8_ = SUB648(ZEXT6064((undefined1  [60])0x0),4);
      auVar16._4_12_ = SUB1612(auVar1 << 0x40,4);
      auVar16._0_4_ = fVar27;
      auVar13 = vsqrtps_avx(auVar16);
      local_10c = fVar11 / auVar13._0_4_;
      local_res8 = local_10c * fVar34;
      local_10c = local_10c * fVar25;
    }
    else {
      local_res8 = 0.0;
      auVar13 = vshufps_avx(ZEXT816(0),ZEXT816(0),0x55);
      local_10c = auVar13._0_4_;
    }
    fVar34 = (float)((uint)fVar34 ^ _DAT_140025070);
    fVar25 = (float)((uint)fVar25 ^ _DAT_140025070);
    local_110 = local_res8;
    fVar27 = fVar25 * fVar25 + fVar34 * fVar34;
    if (fVar33 < fVar27) {
      auVar2._8_8_ = 0;
      auVar2._0_8_ = SUB648(ZEXT6064((undefined1  [60])0x0),4);
      auVar17._4_12_ = SUB1612(auVar2 << 0x40,4);
      auVar17._0_4_ = fVar27;
      auVar13 = vsqrtps_avx(auVar17);
      fVar11 = fVar11 / auVar13._0_4_;
      local_res8 = fVar11 * fVar34;
      local_104 = fVar11 * fVar25;
    }
    else {
      local_res8 = 0.0;
      auVar13 = vshufps_avx(ZEXT816(0),ZEXT816(0),0x55);
      local_104 = auVar13._0_4_;
    }
    local_108 = local_res8;
    uVar7 = 0;
    fVar25 = (9.99999997e-07f);
    do {
      fVar27 = local_128[uVar7 * 2];
      fVar9 = local_128[uVar7 * 2 + 1];
      if (fVar25 < fVar9 * fVar9 + fVar27 * fVar27) {
        pfVar6 = (float *)&local_e8;
        uVar5 = 0;
        do {
          fVar11 = auVar32._0_4_ * *pfVar6;
          fVar26 = fVar9 * fVar11;
          fVar11 = fVar27 * fVar11;
          if (fVar10 < fVar26 * fVar28 + fVar11 * fVar20) {
            fVar11 = fVar20;
            fVar26 = fVar28;
          }
          auVar18._8_8_ = 0;
          auVar18._0_8_ = *param_1;
          auVar13 = vshufps_avx(auVar18,auVar18,0x55);
          auVar13 = vunpcklps_avx(ZEXT416((uint)(fVar11 + (float)*param_1)),
                                  ZEXT416((uint)(fVar26 + auVar13._0_4_)));
          uVar29 = auVar13._0_8_;
          uVar3 = FUN_140012bb0(param_1,uVar29);
          if ((int)uVar3 == 0) {
            fVar10 = *(float *)(param_1 + 4) * (0.449999988f);
            *(float *)((longlong)param_1 + 0xc) = fVar9 * fVar10;
            *(float *)(param_1 + 1) = fVar27 * fVar10;
            *param_1 = uVar29;
            return;
          }
          uVar4 = (int)uVar5 + 1;
          uVar5 = (ulonglong)uVar4;
          pfVar6 = pfVar6 + 1;
        } while (uVar4 < 4);
      }
      uVar4 = (int)uVar7 + 1;
      uVar7 = (ulonglong)uVar4;
      fVar11 = (1f);
    } while (uVar4 < 5);
  }
  fVar27 = (float)*param_1;
  auVar19._4_8_ = SUB128(ZEXT812(0),4);
  auVar19._0_4_ = fVar27;
  auVar19._12_4_ = 0;
  auVar13 = vroundps_avx(auVar19,1);
  fStackX_c = (float)(*param_1 >> 0x20);
  auVar12 = vroundps_avx(ZEXT416((uint)fStackX_c),1);
  fVar25 = ((float)((longlong)auVar12._0_4_ & 0xffffffff) + (0.5f)) - fStackX_c;
  local_res8 = ((float)((longlong)auVar13._0_4_ & 0xffffffff) + (0.5f)) - fVar27;
  fVar10 = fVar25 * fVar25 + local_res8 * local_res8;
  if ((9.99999975e-05f) < fVar10) {
    auVar12 = vsqrtps_avx(ZEXT416((uint)fVar10));
    auVar13 = vminss_avx(auVar12,ZEXT416((uint)(param_3 * *(float *)(param_1 + 4) * (0.600000024f))))
    ;
    if (fVar33 < fVar10) {
      fVar10 = fVar11 / auVar12._0_4_;
      local_res8 = fVar10 * local_res8;
      fVar10 = fVar10 * fVar25;
    }
    else {
      local_res8 = 0.0;
      auVar12 = vshufps_avx(ZEXT816(0),ZEXT816(0),0x55);
      fVar10 = auVar12._0_4_;
    }
    local_res8 = auVar13._0_4_ * local_res8;
    fVar10 = auVar13._0_4_ * fVar10;
    auVar13 = vunpcklps_avx(ZEXT416((uint)(local_res8 + fVar27)),ZEXT416((uint)(fVar10 + fStackX_c))
                           );
    uVar7 = auVar13._0_8_;
    uVar3 = FUN_140012bb0(param_1,uVar7);
    if ((int)uVar3 == 0) {
      fVar27 = *(float *)(param_1 + 4) * (0.25f);
      fVar25 = fVar10 * fVar10 + local_res8 * local_res8;
      *param_1 = uVar7;
      if (fVar33 < fVar25) {
        auVar13 = vsqrtps_avx(ZEXT416((uint)fVar25));
        fVar11 = fVar11 / auVar13._0_4_;
        local_res8 = fVar11 * local_res8;
        fVar11 = fVar11 * fVar10;
      }
      else {
        local_res8 = 0.0;
        auVar13 = vshufps_avx(ZEXT816(0),ZEXT816(0),0x55);
        fVar11 = auVar13._0_4_;
      }
      *(float *)(param_1 + 1) = local_res8 * fVar27;
      *(float *)((longlong)param_1 + 0xc) = fVar11 * fVar27;
      goto LAB_140011c19;
    }
  }
  param_1[1] = 0;
LAB_140011c19:
  *(undefined8 *)((longlong)param_1 + 0x2064) = 0;
  *(undefined8 *)((longlong)param_1 + 0x206c) = 0;
  *(undefined4 *)((longlong)param_1 + 0x2074) = 0;
  return;
}


// ===== FUN_140011ca0 @ 140011ca0 size=402

undefined8 FUN_140011ca0(float *param_1,undefined8 param_2,ulonglong param_3,float param_4)

{
  float fVar1;
  undefined8 uVar2;
  float fVar3;
  uint uVar4;
  bool bVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  float fVar11;
  float fStackX_c;
  
  auVar9._8_8_ = 0;
  auVar9._0_8_ = *(ulonglong *)param_1;
  auVar10._8_8_ = 0;
  auVar10._0_8_ = param_3;
  auVar9 = vshufps_avx(auVar9,auVar9,0x55);
  fVar11 = (float)*(ulonglong *)param_1 - (float)param_3;
  fStackX_c = (float)(param_3 >> 0x20);
  fVar1 = auVar9._0_4_ - fStackX_c;
  if ((9.99999975e-05f) < fVar1 * fVar1 + fVar11 * fVar11) {
    fVar11 = (9.99999975e-05f);
    uVar2 = FUN_140007c90((ulonglong *)param_1,param_2);
    if ((int)uVar2 == 0) {
      uVar2 = 0;
      param_1[2] = 0.0;
      param_1[3] = 0.0;
    }
    else {
      FUN_140002380(param_1,auVar10._0_8_);
      fVar1 = param_1[0x819];
      uVar4 = 1;
      uVar6 = auVar10._0_8_;
      uVar7 = uVar6;
      if (1 < (uint)fVar1) {
        fVar3 = (float)((int)param_1[0x81a] + 1);
        if ((uint)fVar3 < (uint)fVar1) {
          bVar5 = (int)param_1[0x81a] + 2U < (uint)fVar1;
          uVar4 = (uint)!bVar5;
          fVar1 = fStackX_c;
          if (bVar5) {
            auVar10 = ZEXT416((uint)((float)(*(ulonglong *)
                                              (param_1 + (ulonglong)(uint)fVar3 * 2 + 0x19) &
                                            0xffffffff) + (0.5f)));
            fVar1 = (float)(*(ulonglong *)(param_1 + (ulonglong)(uint)fVar3 * 2 + 0x19) >> 0x20) +
                    (0.5f);
          }
          auVar9 = vunpcklps_avx(auVar10,ZEXT416((uint)fVar1));
          uVar7 = auVar9._0_8_;
        }
      }
      FUN_140011140((ulonglong *)param_1,uVar7,param_4,uVar4);
      FUN_140002380(param_1,uVar6);
      auVar8._8_8_ = 0;
      auVar8._0_8_ = *(ulonglong *)param_1;
      auVar9 = vshufps_avx(auVar8,auVar8,0x55);
      fStackX_c = auVar9._0_4_ - fStackX_c;
      fVar1 = (float)*(ulonglong *)param_1 - (float)uVar6;
      if (fVar11 < fStackX_c * fStackX_c + fVar1 * fVar1) {
        uVar2 = 0;
      }
      else {
        uVar2 = 1;
        param_1[2] = 0.0;
        param_1[3] = 0.0;
        *(ulonglong *)param_1 = uVar6;
      }
    }
  }
  else {
    uVar2 = 1;
    param_1[2] = 0.0;
    param_1[3] = 0.0;
    *(ulonglong *)param_1 = param_3;
  }
  return uVar2;
}


// ===== FUN_140011e40 @ 140011e40 size=563

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 (*) [16] FUN_140011e40(undefined1 (*param_1) [16],ulonglong param_2)

{
  code *pcVar1;
  float fVar2;
  float fVar3;
  undefined1 auVar4 [16];
  float fVar5;
  float fVar6;
  undefined8 uVar7;
  undefined1 (*pauVar8) [16];
  ulonglong uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  uint uVar12;
  ulonglong uVar13;
  uint uVar14;
  undefined1 auVar15 [64];
  undefined8 uStack_40;
  
  uVar7 = _DAT_140029228;
  if (DAT_14002a9d8 == 0) {
    *(undefined8 *)*param_1 = _DAT_140029220;
    *(undefined8 *)(*param_1 + 8) = uVar7;
    return param_1;
  }
  uVar14 = 0;
  fVar2 = (float)(param_2 >> 0x20) + (0.5f);
  fVar3 = (float)(param_2 & 0xffffffff) + (0.5f);
  if (DAT_14002a9d8 == 0) {
    pcVar1 = (code *)swi(3);
    pauVar8 = (undefined1 (*) [16])(*pcVar1)();
    return pauVar8;
  }
  uVar11 = 0x200000002;
  uVar9 = 0x200000002;
  if ((int)DAT_14002a9d0[1] == 0) {
    uVar9 = 0x100000001;
  }
  uVar13 = 1;
  fVar5 = ((float)(uVar9 & 0xffffffff) * (0.5f) + (float)(*DAT_14002a9d0 & 0xffffffff)) -
          fVar3;
  fVar6 = ((float)(uVar9 >> 0x20) * (0.5f) + (float)(*DAT_14002a9d0 >> 0x20)) - fVar2;
  auVar15 = ZEXT464((uint)(fVar6 * fVar6 + fVar5 * fVar5));
  if (1 < DAT_14002a9d8) {
    do {
      if (DAT_14002a9d8 <= uVar13) {
        pcVar1 = (code *)swi(3);
        pauVar8 = (undefined1 (*) [16])(*pcVar1)();
        return pauVar8;
      }
      uVar10 = 0x200000002;
      uVar9 = *(ulonglong *)((longlong)DAT_14002a9d0 + uVar13 * 0xc);
      if (*(int *)((longlong)DAT_14002a9d0 + uVar13 * 0xc + 8) == 0) {
        uVar10 = 0x100000001;
      }
      fVar5 = ((float)(uVar10 >> 0x20) * (0.5f) + (float)(uVar9 >> 0x20)) - fVar2;
      fVar6 = ((float)(uVar10 & 0xffffffff) * (0.5f) + (float)(uVar9 & 0xffffffff)) - fVar3;
      fVar5 = fVar5 * fVar5 + fVar6 * fVar6;
      auVar4 = vcmpss_avx(ZEXT416((uint)fVar5),auVar15._0_16_,1);
      uVar12 = (uint)uVar13;
      if (auVar15._0_4_ <= fVar5) {
        uVar12 = uVar14;
      }
      uVar14 = uVar12;
      uVar12 = (uint)uVar13 + 1;
      uVar13 = (ulonglong)uVar12;
      auVar4 = vblendvps_avx(auVar15._0_16_,ZEXT416((uint)fVar5),auVar4);
      auVar15 = ZEXT1664(auVar4);
    } while (uVar12 < DAT_14002a9d8);
  }
  uVar9 = (ulonglong)uVar14;
  if (DAT_14002a9d8 <= uVar9) {
    pcVar1 = (code *)swi(3);
    pauVar8 = (undefined1 (*) [16])(*pcVar1)();
    return pauVar8;
  }
  if (*(int *)((longlong)DAT_14002a9d0 + uVar9 * 0xc + 8) == 0) {
    uVar11 = 0x100000001;
  }
  fVar2 = (float)(uVar11 & 0xffffffff) * (0.5f);
  fVar3 = (float)(uVar11 >> 0x20) * (0.5f);
  if ((uVar11 & 1) == 0) {
    fVar2 = fVar2 + (-0.0500000007f);
  }
  if ((uVar11 >> 0x20 & 1) == 0) {
    fVar3 = fVar3 + (-0.0500000007f);
  }
  auVar4._8_8_ = uStack_40;
  auVar4._0_8_ = *(undefined8 *)((longlong)DAT_14002a9d0 + uVar9 * 0xc);
  auVar4 = vinsertps_avx(auVar4,ZEXT416((uint)fVar2),0x20);
  auVar4 = vinsertps_avx(auVar4,ZEXT416((uint)fVar3),0x30);
  *param_1 = auVar4;
  return param_1;
}


// ===== FUN_140012080 @ 140012080 size=131

ulonglong FUN_140012080(ulonglong param_1,char param_2)

{
  int iVar1;
  ulonglong uVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = (int)param_1;
  iVar1 = (int)(param_1 >> 0x20);
  if (param_2 == '\0') {
    uVar2 = (ulonglong)(iVar1 - 1);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    return uVar2 << 0x20 | param_1 & 0xffffffff;
  }
  if (param_2 == '\x01') {
    return (ulonglong)(iVar3 + 1) | param_1 & 0xffffffff00000000;
  }
  if (param_2 == '\x02') {
    return (ulonglong)(iVar1 + 1) << 0x20 | param_1 & 0xffffffff;
  }
  if (param_2 != '\x03') {
    return param_1;
  }
  if (iVar3 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = iVar3 - 1;
  }
  return (ulonglong)uVar4 | param_1 & 0xffffffff00000000;
}


// ===== FUN_140012110 @ 140012110 size=354

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_140012110(uint param_1)

{
  undefined1 auVar1 [32];
  undefined1 auVar2 [32];
  undefined1 auVar3 [32];
  undefined1 auVar4 [32];
  undefined1 auVar5 [32];
  undefined1 auVar6 [16];
  undefined1 auVar7 [32];
  undefined1 auVar8 [32];
  
  if (999 < param_1) {
    auVar8._0_4_ = (float)param_1;
    auVar8._4_4_ = auVar8._0_4_;
    auVar8._8_4_ = auVar8._0_4_;
    auVar8._12_4_ = auVar8._0_4_;
    auVar8._16_4_ = auVar8._0_4_;
    auVar8._20_4_ = auVar8._0_4_;
    auVar8._24_4_ = auVar8._0_4_;
    auVar8._28_4_ = auVar8._0_4_;
    auVar7 = vpsrld_avx2(auVar8,0x17);
    auVar7 = vpand_avx2(auVar7,_DAT_140025140);
    auVar5 = vpsubd_avx2(auVar7,_DAT_140025100);
    auVar4 = vpcmpeqd_avx2(auVar5,_DAT_140025120);
    auVar7 = vpand_avx2(_DAT_140025160,auVar8);
    auVar7 = vpor_avx2(auVar7,_DAT_140025200);
    auVar3 = vsubps_avx(auVar7,_DAT_140025200);
    auVar1 = vcmpps_avx(auVar8,ZEXT832(0) << 0x20,0x11);
    auVar2 = vcmpps_avx(auVar8,ZEXT832(0) << 0x20,0);
    auVar6 = vfmadd231ps_fma(_DAT_140025180,auVar3,_DAT_140025320);
    auVar6 = vfmadd231ps_fma(_DAT_140025340,ZEXT1632(auVar6),auVar3);
    auVar7 = vcvtdq2ps_avx(auVar5);
    auVar6 = vfmadd231ps_fma(_DAT_1400251c0,ZEXT1632(auVar6),auVar3);
    auVar6 = vfmadd231ps_fma(_DAT_140025360,ZEXT1632(auVar6),auVar3);
    auVar6 = vfmadd231ps_fma(_DAT_140025220,ZEXT1632(auVar6),auVar3);
    auVar6 = vfmadd231ps_fma(auVar7,ZEXT1632(auVar6),auVar3);
    auVar7 = vblendvps_avx(ZEXT1632(auVar6),auVar8,auVar4);
    auVar7 = vblendvps_avx(auVar7,_DAT_140025420,auVar2);
    auVar7 = vblendvps_avx(auVar7,_DAT_1400252e0,auVar1);
    auVar6 = vroundps_avx(ZEXT416((uint)(auVar7._0_4_ * _DAT_1400251a0)),1);
    return (longlong)auVar6._0_4_;
  }
  if (99 < param_1) {
    return 2;
  }
  return (ulonglong)(9 < param_1);
}


// ===== FUN_140012280 @ 140012280 size=299

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140012280(int *param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  tagPOINT local_res8 [4];
  
  DAT_14002a890 = (int *)0x0;
  if ((((param_1 != (int *)0x0) && (*(longlong *)(param_1 + 2) != 0)) && (*param_1 != 1)) &&
     ((*(longlong *)(param_1 + 0x48) != 0 && (1 < *(uint *)(*(longlong *)(param_1 + 0x48) + 0x10))))
     ) {
    lVar1 = *(longlong *)(param_1 + 0x48);
    _DAT_140029ad0 = *(undefined8 *)(lVar1 + 0x18);
    DAT_140029ad8 = *(undefined8 *)(lVar1 + 0x20);
    _DAT_140029ae0 = *(undefined8 *)(lVar1 + 0x28);
    DAT_140029128 = 0xffffffff;
    DAT_140029ae8 = FUN_140014750;
    DAT_140029af0 = 1;
    DAT_14002a890 = param_1;
    DAT_14002a898 = *(longlong *)(param_1 + 2);
    uVar2 = FUN_14001b810(param_1);
    DAT_140029128 = (uint)uVar2;
    if (((int)DAT_140029128 < 0) || (DAT_140029ae0 <= DAT_140029128)) {
      DAT_140029128 = 0xffffffff;
    }
    local_res8[0].x = 0;
    local_res8[0].y = 0;
    GetCursorPos(local_res8);
    ScreenToClient(DAT_140029680,local_res8);
    DAT_140029af8 = (int)(float)local_res8[0].x;
    DAT_140029afc = (int)(float)local_res8[0].y;
    DAT_140029af0 = 1;
    DAT_140029af4 = 1;
    return;
  }
  DAT_140029af0 = 0;
  DAT_140029af4 = 0;
  return;
}


// ===== FUN_1400123b0 @ 1400123b0 size=211

undefined4 FUN_1400123b0(undefined8 *param_1)

{
  LPVOID pvVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (*(int *)*param_1 == -0x3ffffffb) {
    pvVar1 = (LPVOID)(*(ulonglong *)((int *)*param_1 + 10) & 0xfffffffffffe0000);
    if ((((((DAT_140029818 <= pvVar1) &&
           ((ulonglong)((longlong)pvVar1 - (longlong)DAT_140029818) < DAT_140029820)) ||
          ((DAT_140029830 <= pvVar1 &&
           ((ulonglong)((longlong)pvVar1 - (longlong)DAT_140029830) < DAT_140029838)))) ||
         ((DAT_140029848 <= pvVar1 &&
          ((ulonglong)((longlong)pvVar1 - (longlong)DAT_140029848) < DAT_140029850)))) ||
        ((DAT_140029860 <= pvVar1 &&
         ((ulonglong)((longlong)pvVar1 - (longlong)DAT_140029860) < DAT_140029868)))) ||
       ((uVar2 = 0, DAT_140029878 <= pvVar1 &&
        ((ulonglong)((longlong)pvVar1 - (longlong)DAT_140029878) < DAT_140029880)))) {
      pvVar1 = VirtualAlloc(pvVar1,0x20000,0x1000,4);
      uVar2 = 0;
      if (pvVar1 != (LPVOID)0x0) {
        uVar2 = 0xffffffff;
      }
    }
  }
  return uVar2;
}


// ===== FUN_140012490 @ 140012490 size=132

bool FUN_140012490(ulonglong param_1,uint param_2,int param_3)

{
  bool bVar1;
  int *piVar2;
  
  piVar2 = (int *)FUN_140009990(param_1,param_2);
  if (piVar2 == (int *)0x0) {
    bVar1 = FUN_14001b880(param_1,param_2,
                          *(int *)(&DAT_140029000 +
                                  (longlong)*(int *)(&DAT_140029010 + (longlong)param_3 * 4) * 4),
                          *(int *)(&DAT_140029010 + (longlong)param_3 * 4));
    return bVar1;
  }
  if ((*(longlong *)(piVar2 + 2) != 0) && (*piVar2 == 1)) {
    return true;
  }
  return false;
}


// ===== FUN_140012520 @ 140012520 size=644

undefined8 FUN_140012520(ulonglong param_1,int param_2,int param_3)

{
  bool bVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong *plVar5;
  undefined8 uVar6;
  undefined1 *puVar7;
  uint uVar8;
  undefined1 *puVar9;
  longlong lVar10;
  
  uVar6 = 0x200000002;
  if (param_2 == 0) {
    uVar6 = 0x100000001;
  }
  uVar2 = FUN_1400052a0(param_1,uVar6);
  if (((int)uVar2 != 0) && ((param_3 == 0 || (uVar2 = FUN_14001c8c0(param_1), (int)uVar2 != 0)))) {
    FUN_140005f00(param_1,uVar6);
    FUN_140005d80(param_1,0,uVar6);
    FUN_140005be0(param_1,uVar6);
    puVar9 = DAT_14002a9d0;
    if (DAT_14002a9d8 == DAT_14002a9dc) {
      uVar4 = 8;
      if (8 < DAT_14002a9dc * 2) {
        uVar4 = (ulonglong)(DAT_14002a9dc * 2);
      }
      uVar8 = (uint)uVar4;
      if (DAT_14002a9dc < uVar8) {
        plVar5 = &DAT_140029878;
        if (DAT_14002a9c8 != (longlong *)0x0) {
          plVar5 = DAT_14002a9c8;
        }
        lVar10 = (ulonglong)DAT_14002a9dc * 0xc;
        if ((DAT_14002a9d0 == (undefined1 *)0x0) ||
           (DAT_14002a9d0 + lVar10 != (undefined1 *)(*plVar5 + plVar5[2]))) {
          bVar1 = DAT_14002a9dc < uVar8;
          puVar9 = (undefined1 *)0x0;
          DAT_14002a9dc = uVar8;
          if (bVar1) {
            uVar3 = plVar5[2] + 3U & 0xfffffffffffffffc;
            plVar5[2] = uVar3;
            puVar9 = (undefined1 *)(uVar3 + *plVar5);
            puVar7 = puVar9;
            if (DAT_14002a9d0 != (undefined1 *)0x0) {
              for (; lVar10 != 0; lVar10 = lVar10 + -1) {
                *puVar7 = *DAT_14002a9d0;
                DAT_14002a9d0 = DAT_14002a9d0 + 1;
                puVar7 = puVar7 + 1;
              }
            }
            plVar5[2] = plVar5[2] + uVar4 * 0xc;
          }
        }
        else {
          plVar5[2] = plVar5[2] + (ulonglong)(uVar8 - DAT_14002a9dc) * 0xc;
          DAT_14002a9dc = uVar8;
        }
      }
    }
    DAT_14002a9d0 = puVar9;
    puVar9 = DAT_14002a9d0;
    uVar4 = (ulonglong)DAT_14002a9d8;
    *(ulonglong *)(DAT_14002a9d0 + uVar4 * 0xc) = param_1;
    *(int *)(puVar9 + uVar4 * 0xc + 8) = param_2;
    DAT_14002a9d8 = DAT_14002a9d8 + 1;
    puVar9 = DAT_1400ea9f8;
    if (DAT_1400eaa00 == DAT_1400eaa04) {
      uVar8 = 8;
      if (8 < DAT_1400eaa04 * 2) {
        uVar8 = DAT_1400eaa04 * 2;
      }
      if (DAT_1400eaa04 < uVar8) {
        plVar5 = &DAT_140029878;
        if (DAT_1400ea9f0 != (longlong *)0x0) {
          plVar5 = DAT_1400ea9f0;
        }
        lVar10 = (ulonglong)DAT_1400eaa04 * 4;
        if ((DAT_1400ea9f8 == (undefined1 *)0x0) ||
           (DAT_1400ea9f8 + lVar10 != (undefined1 *)(*plVar5 + plVar5[2]))) {
          bVar1 = DAT_1400eaa04 < uVar8;
          puVar9 = (undefined1 *)0x0;
          DAT_1400eaa04 = uVar8;
          if (bVar1) {
            uVar4 = plVar5[2] + 3U & 0xfffffffffffffffc;
            puVar9 = (undefined1 *)(*plVar5 + uVar4);
            plVar5[2] = uVar4;
            puVar7 = puVar9;
            if (DAT_1400ea9f8 != (undefined1 *)0x0) {
              for (; lVar10 != 0; lVar10 = lVar10 + -1) {
                *puVar7 = *DAT_1400ea9f8;
                DAT_1400ea9f8 = DAT_1400ea9f8 + 1;
                puVar7 = puVar7 + 1;
              }
            }
            plVar5[2] = plVar5[2] + (ulonglong)uVar8 * 4;
          }
        }
        else {
          plVar5[2] = plVar5[2] + (ulonglong)(uVar8 - DAT_1400eaa04) * 4;
          DAT_1400eaa04 = uVar8;
        }
      }
    }
    DAT_1400ea9f8 = puVar9;
    *(int *)(DAT_1400ea9f8 + (ulonglong)DAT_1400eaa00 * 4) = param_3;
    DAT_1400eaa00 = DAT_1400eaa00 + 1;
    return 1;
  }
  return 0;
}


// ===== FUN_1400127b0 @ 1400127b0 size=655

undefined8 FUN_1400127b0(ulonglong param_1,uint param_2,uint param_3,undefined8 param_4,int param_5)

{
  bool bVar1;
  undefined8 uVar2;
  undefined7 extraout_var;
  longlong *plVar3;
  uint *puVar4;
  undefined7 extraout_var_00;
  longlong lVar5;
  int iVar6;
  uint uVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  int iVar10;
  uint uVar11;
  uint uStackX_c;
  undefined8 local_150;
  longlong lStack_148;
  longlong lStack_140;
  longlong lStack_138;
  longlong local_128;
  longlong lStack_120;
  longlong lStack_118;
  longlong lStack_110;
  longlong local_108;
  longlong lStack_100;
  longlong lStack_f8;
  longlong lStack_f0;
  longlong local_e8;
  longlong lStack_e0;
  longlong lStack_d8;
  longlong lStack_d0;
  longlong local_c8;
  longlong lStack_c0;
  longlong local_b8;
  undefined8 local_a8 [16];
  
  switch(param_3) {
  default:
    uVar8 = 0x100000001;
    break;
  case 3:
    uVar8 = 0x200000002;
    break;
  case 4:
    uVar8 = 0x200000003;
  }
  uVar2 = FUN_1400054e0(param_1,param_2,param_3,param_4,param_5);
  if ((int)uVar2 == 0) {
LAB_140012a1e:
    uVar8 = 0;
  }
  else {
    if (param_2 == 0) {
      FUN_140005f00(param_1,uVar8);
      FUN_140005be0(param_1,uVar8);
    }
    FUN_140005d80(param_1,param_2,uVar8);
    if (param_3 == 1) {
      bVar1 = FUN_140012490(param_1,param_2,(int)param_4);
      uVar11 = (uint)CONCAT71(extraout_var,bVar1);
LAB_1400129d0:
      if (uVar11 == 0) goto LAB_140012a1e;
    }
    else {
      plVar3 = FUN_140009a60(local_a8,param_3,(int)param_4);
      local_150 = *plVar3;
      lStack_148 = plVar3[1];
      lStack_140 = plVar3[2];
      lStack_138 = plVar3[3];
      local_108 = plVar3[4];
      lStack_100 = plVar3[5];
      lStack_f8 = plVar3[6];
      lStack_f0 = plVar3[7];
      local_e8 = plVar3[8];
      lStack_e0 = plVar3[9];
      lStack_d8 = plVar3[10];
      lStack_d0 = plVar3[0xb];
      local_c8 = plVar3[0xc];
      lStack_c0 = plVar3[0xd];
      local_b8 = plVar3[0xe];
      if (lStack_140 == 0) goto LAB_140012a1e;
      local_128 = local_150;
      lStack_120 = lStack_148;
      lStack_118 = lStack_140;
      lStack_110 = lStack_138;
      puVar4 = (uint *)FUN_140009990(param_1,param_2);
      uVar11 = (uint)param_1;
      uStackX_c = (uint)(param_1 >> 0x20);
      if (puVar4 == (uint *)0x0) {
        iVar10 = (int)lStack_148 + uStackX_c;
        if ((int)uStackX_c < iVar10) {
          iVar6 = local_150._4_4_ + uVar11;
          do {
            uVar9 = param_1 & 0xffffffff;
            uVar7 = uVar11;
            while ((int)uVar7 < iVar6) {
              bVar1 = FUN_14001c590(CONCAT44(uStackX_c,(int)uVar9),param_2);
              if ((int)CONCAT71(extraout_var_00,bVar1) == 0) {
                local_150 = 0;
                lStack_148 = 0;
                goto LAB_1400129ab;
              }
              uVar7 = (int)uVar9 + 1;
              uVar9 = (ulonglong)uVar7;
            }
            uStackX_c = uStackX_c + 1;
          } while ((int)uStackX_c < iVar10);
        }
        FUN_140008800(&local_150,param_1,param_2,(int *)&local_128);
LAB_1400129ab:
        if (((local_150 == 0) || (*(longlong *)(local_150 + 8) == 0)) ||
           (lVar5 = local_150, *(longlong *)(local_150 + 8) != lStack_148)) {
          lVar5 = 0;
        }
        uVar11 = (uint)(lVar5 != 0);
        goto LAB_1400129d0;
      }
      if (((*puVar4 != param_3) || (puVar4[8] != uVar11)) || (puVar4[9] != uStackX_c))
      goto LAB_140012a1e;
      FUN_140002dc0((int *)puVar4,(int *)&local_128);
    }
    lVar5 = FUN_140009990(param_1,param_2);
    if (((lVar5 != 0) && (*(longlong *)(lVar5 + 8) != 0)) && (*(uint *)(lVar5 + 0x34) < 0x10000)) {
      *(int *)(&DAT_1400aa9f0 + (ulonglong)*(uint *)(lVar5 + 0x34) * 4) = param_5;
    }
    uVar8 = 1;
  }
  return uVar8;
}


// ===== FUN_140012a70 @ 140012a70 size=319

void FUN_140012a70(undefined8 param_1,undefined4 param_2)

{
  undefined8 *puVar1;
  bool bVar2;
  uint uVar3;
  undefined8 uVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  longlong *plVar9;
  undefined4 uStack_14;
  
  uVar4 = DAT_14002a8a0;
  puVar8 = DAT_14002a8b0;
  if (DAT_14002a8b8 == DAT_14002a8bc) {
    uVar3 = 8;
    if (8 < DAT_14002a8bc * 2) {
      uVar3 = DAT_14002a8bc * 2;
    }
    if (DAT_14002a8bc < uVar3) {
      plVar9 = &DAT_140029878;
      if (DAT_14002a8a8 != (longlong *)0x0) {
        plVar9 = DAT_14002a8a8;
      }
      if ((DAT_14002a8b0 == (undefined1 *)0x0) ||
         (DAT_14002a8b0 + (ulonglong)DAT_14002a8bc * 0x18 != (undefined1 *)(*plVar9 + plVar9[2]))) {
        lVar5 = (ulonglong)DAT_14002a8bc * 0x18;
        bVar2 = DAT_14002a8bc < uVar3;
        puVar8 = (undefined1 *)0x0;
        DAT_14002a8bc = uVar3;
        if (bVar2) {
          uVar6 = plVar9[2] + 7U & 0xfffffffffffffff8;
          puVar8 = (undefined1 *)(*plVar9 + uVar6);
          plVar9[2] = uVar6;
          puVar7 = puVar8;
          if (DAT_14002a8b0 != (undefined1 *)0x0) {
            for (; lVar5 != 0; lVar5 = lVar5 + -1) {
              *puVar7 = *DAT_14002a8b0;
              DAT_14002a8b0 = DAT_14002a8b0 + 1;
              puVar7 = puVar7 + 1;
            }
          }
          plVar9[2] = plVar9[2] + (ulonglong)uVar3 * 0x18;
        }
      }
      else {
        plVar9[2] = plVar9[2] + (ulonglong)(uVar3 - DAT_14002a8bc) * 0x18;
        DAT_14002a8bc = uVar3;
      }
    }
  }
  DAT_14002a8b0 = puVar8;
  puVar8 = DAT_14002a8b0;
  uVar6 = (ulonglong)DAT_14002a8b8;
  puVar1 = (undefined8 *)(DAT_14002a8b0 + uVar6 * 0x18);
  *puVar1 = param_1;
  puVar1[1] = uVar4;
  *(ulonglong *)(puVar8 + uVar6 * 0x18 + 0x10) = CONCAT44(uStack_14,param_2);
  DAT_14002a8b8 = DAT_14002a8b8 + 1;
  return;
}


// ===== FUN_140012bb0 @ 140012bb0 size=163

undefined8 FUN_140012bb0(ulonglong *param_1,undefined8 param_2)

{
  undefined8 uVar1;
  longlong lVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  
  if (DAT_14002a900 == (code *)0x0) {
    return 0;
  }
  if (*(char *)((longlong)param_1 + 0x34) != '\x01') {
    if (*(char *)((longlong)param_1 + 0x34) != '\x03') {
      auVar5._8_8_ = 0;
      auVar5._0_8_ = *param_1;
      auVar3._4_12_ = ZEXT812(0) << 0x20;
      auVar3._0_4_ = (int)*param_1;
      auVar5 = vshufps_avx(auVar5,auVar5,0x55);
      auVar3 = vroundps_avx(auVar3,1);
      auVar4._4_12_ = ZEXT812(0) << 0x20;
      auVar4._0_4_ = auVar5._0_4_;
      auVar5 = vroundps_avx(auVar4,1);
                    /* WARNING: Could not recover jumptable at 0x000140012c18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (*DAT_14002a900)(0,(longlong)auVar5._0_4_ << 0x20 |
                                 (longlong)auVar3._0_4_ & 0xffffffffU,auVar5._0_8_,DAT_14002a908);
      return uVar1;
    }
    lVar2 = 0x39;
    if ((int)param_1[0xb] == 0) {
      lVar2 = 0x10;
    }
                    /* WARNING: Could not recover jumptable at 0x000140012c3d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*DAT_14002a900)(param_2,*(undefined8 *)(lVar2 + (longlong)param_1));
    return uVar1;
  }
                    /* WARNING: Could not recover jumptable at 0x000140012c50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*DAT_14002a900)(param_2,param_1[2]);
  return uVar1;
}


// ===== FUN_140012c60 @ 140012c60 size=60

void FUN_140012c60(char *param_1)

{
  char cVar1;
  longlong lVar2;
  
  lVar2 = 0;
  if (param_1 != (char *)0x0) {
    cVar1 = *param_1;
    while (cVar1 != '\0') {
      lVar2 = lVar2 + 1;
      cVar1 = param_1[lVar2];
    }
  }
  WriteFile(DAT_1400299a0,param_1,(DWORD)lVar2,(LPDWORD)0x0,(LPOVERLAPPED)0x0);
  return;
}


// ===== FUN_140012ca0 @ 140012ca0 size=41

void FUN_140012ca0(undefined8 *param_1)

{
  WriteFile(DAT_1400299a0,(LPCVOID)*param_1,*(DWORD *)(param_1 + 1),(LPDWORD)0x0,(LPOVERLAPPED)0x0);
  return;
}


// ===== FUN_140012cd0 @ 140012cd0 size=105

void FUN_140012cd0(char *param_1)

{
  char *pcVar1;
  char cVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar3 = 0;
  if (param_1 != (char *)0x0) {
    cVar2 = *param_1;
    while (cVar2 != '\0') {
      lVar3 = lVar3 + 1;
      cVar2 = param_1[lVar3];
    }
  }
  WriteFile(DAT_1400299a0,param_1,(DWORD)lVar3,(LPDWORD)0x0,(LPOVERLAPPED)0x0);
  lVar3 = 0;
  do {
    lVar4 = lVar3 + 1;
    pcVar1 = &DAT_140024265 + lVar3;
    lVar3 = lVar4;
  } while (*pcVar1 != '\0');
  WriteFile(DAT_1400299a0,&DAT_140024264,(DWORD)lVar4,(LPDWORD)0x0,(LPOVERLAPPED)0x0);
  return;
}


// ===== FUN_140012d40 @ 140012d40 size=354

/* WARNING: Removing unreachable block (ram,0x000140012e74) */

void FUN_140012d40(undefined8 param_1)

{
  undefined8 *puVar1;
  ulonglong uVar2;
  uint uVar3;
  longlong lVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  int iStackX_c;
  
  lVar4 = DAT_140029ac8;
  uVar5 = (ulonglong)DAT_1400299ac;
  uVar2 = 0;
  if (DAT_1400299ac != 0) {
    iStackX_c = (int)((ulonglong)param_1 >> 0x20);
    do {
      if ((*(int *)(uVar2 * 0x40 + DAT_140029ac8) == (int)param_1) &&
         (*(int *)(uVar2 * 0x40 + 4 + DAT_140029ac8) == iStackX_c)) {
        if (-1 < (int)uVar2) {
          return;
        }
        break;
      }
      uVar3 = (int)uVar2 + 1;
      uVar2 = (ulonglong)uVar3;
    } while (uVar3 < DAT_1400299ac);
  }
  puVar1 = (undefined8 *)(uVar5 * 0x40 + DAT_140029ac8);
  *puVar1 = param_1;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1 = (undefined8 *)(uVar5 * 0x40 + 0x20 + lVar4);
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  lVar4 = (ulonglong)DAT_1400299ac * 0x40 + DAT_140029ac8;
  *(undefined4 *)(lVar4 + 0xc) = 0;
  uVar2 = DAT_140029ab8 ^ DAT_140029aa8;
  uVar6 = ((DAT_140029ac0 + DAT_140029aa8) * 0x800000 | DAT_140029ac0 + DAT_140029aa8 >> 0x1f) +
          DAT_140029aa8;
  DAT_140029ab8 = uVar2 ^ DAT_140029ab0 << 0x11;
  uVar5 = DAT_140029ab0 ^ DAT_140029ac0;
  DAT_140029aa8 = DAT_140029aa8 ^ uVar5;
  DAT_140029ac0 = uVar5 >> 0x13 | uVar5 << 0x2d;
  DAT_140029ab0 = DAT_140029ab0 ^ uVar2;
  *(float *)(lVar4 + 8) = (float)(uVar6 % 0xdd + 0x1e);
  DAT_1400299ac = DAT_1400299ac + 1;
  return;
}


// ===== FUN_140012eb0 @ 140012eb0 size=380

void FUN_140012eb0(longlong param_1,undefined1 param_2,undefined4 param_3,undefined8 *param_4)

{
  ulonglong *puVar1;
  undefined8 *puVar2;
  uint uVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  longlong lVar8;
  ulonglong uVar9;
  undefined1 *puVar10;
  longlong *plVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  uint local_48;
  
  uVar3 = *(uint *)(param_1 + 0x4c);
  if (*(uint *)(param_1 + 0x48) != uVar3) goto LAB_140012f98;
  uVar4 = 8;
  if (8 < uVar3 * 2) {
    uVar4 = uVar3 * 2;
  }
  if (uVar4 <= uVar3) goto LAB_140012f98;
  puVar12 = *(undefined1 **)(param_1 + 0x40);
  plVar11 = &DAT_140029878;
  if (*(longlong **)(param_1 + 0x38) != (longlong *)0x0) {
    plVar11 = *(longlong **)(param_1 + 0x38);
  }
  puVar1 = (ulonglong *)(plVar11 + 2);
  if (puVar12 == (undefined1 *)0x0) {
    uVar9 = *puVar1 + 3 & 0xfffffffffffffffc;
    *puVar1 = uVar9;
    puVar10 = (undefined1 *)(*plVar11 + uVar9);
LAB_140012f7b:
    *puVar1 = *puVar1 + (ulonglong)uVar4 * 0x28;
  }
  else {
    uVar9 = *puVar1;
    lVar8 = (ulonglong)uVar3 * 0x28;
    if (puVar12 + lVar8 != (undefined1 *)(*plVar11 + uVar9)) {
      uVar9 = uVar9 + 3 & 0xfffffffffffffffc;
      *puVar1 = uVar9;
      puVar10 = (undefined1 *)(uVar9 + *plVar11);
      puVar13 = puVar10;
      for (; lVar8 != 0; lVar8 = lVar8 + -1) {
        *puVar13 = *puVar12;
        puVar12 = puVar12 + 1;
        puVar13 = puVar13 + 1;
      }
      goto LAB_140012f7b;
    }
    *puVar1 = uVar9 + (ulonglong)(uVar4 - uVar3) * 0x28;
    puVar10 = puVar12;
  }
  *(undefined1 **)(param_1 + 0x40) = puVar10;
  *(uint *)(param_1 + 0x4c) = uVar4;
LAB_140012f98:
  local_48 = local_48 & 0xffffff00;
  uVar3 = *(uint *)(param_1 + 0x48);
  lVar8 = *(longlong *)(param_1 + 0x40);
  puVar1 = (ulonglong *)(lVar8 + (ulonglong)uVar3 * 0x28);
  *puVar1 = (ulonglong)local_48;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  *(undefined8 *)(lVar8 + 0x20 + (ulonglong)uVar3 * 0x28) = 0x100000000;
  uVar9 = (ulonglong)*(uint *)(param_1 + 0x48);
  *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) + 1;
  lVar8 = *(longlong *)(param_1 + 0x40);
  *(undefined1 *)(lVar8 + uVar9 * 0x28) = param_2;
  *(undefined4 *)(lVar8 + 4 + uVar9 * 0x28) = param_3;
  uVar5 = param_4[1];
  uVar6 = param_4[2];
  uVar7 = param_4[3];
  puVar2 = (undefined8 *)(lVar8 + 8 + uVar9 * 0x28);
  *puVar2 = *param_4;
  puVar2[1] = uVar5;
  puVar2[2] = uVar6;
  puVar2[3] = uVar7;
  return;
}


// ===== FUN_140013030 @ 140013030 size=842

undefined8 FUN_140013030(longlong param_1,uint param_2)

{
  undefined8 *puVar1;
  bool bVar2;
  code *pcVar3;
  int iVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  uint uVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  longlong lVar13;
  longlong *plVar14;
  char local_48;
  undefined7 uStack_47;
  uint uStack_40;
  undefined4 uStack_3c;
  undefined1 uStack_38;
  undefined2 uStack_37;
  undefined1 uStack_35;
  undefined4 uStack_34;
  undefined8 uStack_30;
  
  uVar7 = (uint)param_1;
  if (((uVar7 < (uint)DAT_140029a88) &&
      (uVar8 = (uint)((ulonglong)param_1 >> 0x20), uVar8 < DAT_140029a88._4_4_)) && (param_2 != 0))
  {
    uVar6 = 0;
    if (DAT_1400eaa18 != 0) {
      do {
        if (DAT_1400eaa18 <= uVar6) {
          pcVar3 = (code *)swi(3);
          uVar5 = (*pcVar3)();
          return uVar5;
        }
        if ((*(uint *)(DAT_1400eaa10 + uVar6 * 0x18) == uVar7) &&
           (*(uint *)(DAT_1400eaa10 + uVar6 * 0x18 + 4) == uVar8)) {
          if (-1 < (int)uVar6) {
            return 0;
          }
          break;
        }
        uVar10 = (int)uVar6 + 1;
        uVar6 = (ulonglong)uVar10;
      } while (uVar10 < DAT_1400eaa18);
    }
    uVar6 = 0;
    if (DAT_140029200 != 0) {
      do {
        if (DAT_140029200 <= uVar6) {
          pcVar3 = (code *)swi(3);
          uVar5 = (*pcVar3)();
          return uVar5;
        }
        if (((*(int *)(DAT_1400291f8 + 0x24 + uVar6 * 0x28) != 0) &&
            (*(uint *)(DAT_1400291f8 + 1 + uVar6 * 0x28) == uVar7)) &&
           (*(uint *)(DAT_1400291f8 + 5 + uVar6 * 0x28) == uVar8)) {
          if (-1 < (int)uVar6) {
            return 0;
          }
          break;
        }
        uVar10 = (int)uVar6 + 1;
        uVar6 = (ulonglong)uVar10;
      } while (uVar10 < DAT_140029200);
    }
    if ((((uVar7 < (uint)DAT_140029a88) && (uVar8 < DAT_140029a88._4_4_)) && (DAT_1400299a8 != 0))
       && ((-1 < (int)uVar7 && (-1 < param_1)))) {
      uVar7 = *(uint *)(DAT_140029a98 + (ulonglong)(uVar8 * (uint)DAT_140029a88 + uVar7) * 4);
      if ((uVar7 != 0) && (uVar7 < DAT_14002a870)) {
        if ((ulonglong)DAT_14002a870 <= (ulonglong)uVar7) {
          pcVar3 = (code *)swi(3);
          uVar5 = (*pcVar3)();
          return uVar5;
        }
        piVar9 = *(int **)(DAT_14002a868 + (ulonglong)uVar7 * 8);
        if (((piVar9 != (int *)0x0) && (*(longlong *)(piVar9 + 2) != 0)) && (*piVar9 == 1)) {
          if (piVar9[0x16] == 0) {
            piVar9 = piVar9 + 0xf;
          }
          else {
            piVar9 = piVar9 + 0x15;
          }
          uVar7 = piVar9[1];
          if (uVar7 != 0) {
            iVar4 = *piVar9;
            uStack_47 = (undefined7)param_1;
            if (param_2 < uVar7) {
              uVar7 = param_2;
            }
            uStack_40 = (uint)(byte)((ulonglong)param_1 >> 0x38);
            uStack_3c = 0;
            uStack_30 = 0x100000000;
            local_48 = '\x05';
            uStack_38 = 0;
            uStack_37 = 0;
            uStack_35 = 0;
            uStack_34 = (0.150000006f);
            uVar6 = FUN_140013530(0x1400291d0,&local_48);
            if (-1 < (int)uVar6) {
              puVar12 = DAT_1400eaa10;
              if (DAT_1400eaa18 == DAT_1400eaa1c) {
                uVar8 = 8;
                if (8 < DAT_1400eaa1c * 2) {
                  uVar8 = DAT_1400eaa1c * 2;
                }
                if (DAT_1400eaa1c < uVar8) {
                  plVar14 = &DAT_140029878;
                  if (DAT_1400eaa08 != (longlong *)0x0) {
                    plVar14 = DAT_1400eaa08;
                  }
                  lVar13 = (ulonglong)DAT_1400eaa1c * 0x18;
                  if ((DAT_1400eaa10 == (undefined1 *)0x0) ||
                     (DAT_1400eaa10 + lVar13 != (undefined1 *)(*plVar14 + plVar14[2]))) {
                    bVar2 = DAT_1400eaa1c < uVar8;
                    puVar12 = (undefined1 *)0x0;
                    DAT_1400eaa1c = uVar8;
                    if (bVar2) {
                      uVar6 = plVar14[2] + 3U & 0xfffffffffffffffc;
                      puVar12 = (undefined1 *)(*plVar14 + uVar6);
                      plVar14[2] = uVar6;
                      puVar11 = puVar12;
                      if (DAT_1400eaa10 != (undefined1 *)0x0) {
                        for (; lVar13 != 0; lVar13 = lVar13 + -1) {
                          *puVar11 = *DAT_1400eaa10;
                          DAT_1400eaa10 = DAT_1400eaa10 + 1;
                          puVar11 = puVar11 + 1;
                        }
                      }
                      plVar14[2] = plVar14[2] + (ulonglong)uVar8 * 0x18;
                    }
                  }
                  else {
                    plVar14[2] = plVar14[2] + (ulonglong)(uVar8 - DAT_1400eaa1c) * 0x18;
                    DAT_1400eaa1c = uVar8;
                  }
                }
              }
              DAT_1400eaa10 = puVar12;
              puVar12 = DAT_1400eaa10;
              uStack_40 = CONCAT31(uStack_40._1_3_,0xc);
              uVar6 = (ulonglong)DAT_1400eaa18;
              puVar1 = (undefined8 *)(DAT_1400eaa10 + uVar6 * 0x18);
              *puVar1 = 0;
              puVar1[1] = (ulonglong)uStack_40;
              *(ulonglong *)(puVar12 + uVar6 * 0x18 + 0x10) =
                   CONCAT44(uStack_34,0xffffffff) & 0xffffff00ffffffff;
              puVar12 = DAT_1400eaa10;
              uVar6 = (ulonglong)DAT_1400eaa18;
              DAT_1400eaa18 = DAT_1400eaa18 + 1;
              *(longlong *)(DAT_1400eaa10 + uVar6 * 0x18) = param_1;
              puVar12[uVar6 * 0x18 + 8] = (char)iVar4;
              *(uint *)(puVar12 + uVar6 * 0x18 + 0xc) = uVar7;
              *(undefined4 *)(puVar12 + uVar6 * 0x18 + 0x10) = 0xffffffff;
              puVar12[uVar6 * 0x18 + 0x14] = 1;
              return 1;
            }
          }
        }
      }
    }
  }
  return 0;
}


// ===== FUN_140013380 @ 140013380 size=422

undefined8 FUN_140013380(longlong param_1,byte param_2,int param_3)

{
  int *piVar1;
  code *pcVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  char local_28;
  undefined7 uStack_27;
  undefined1 uStack_20;
  undefined7 uStack_1f;
  undefined1 uStack_18;
  byte bStack_17;
  undefined1 uStack_16;
  undefined1 uStack_15;
  undefined4 uStack_14;
  undefined8 uStack_10;
  
  uVar5 = (uint)param_1;
  if ((((uVar5 < (uint)DAT_140029a88) &&
       (uVar7 = (uint)((ulonglong)param_1 >> 0x20), uVar7 < DAT_140029a88._4_4_)) && (param_3 != 0))
     && (((uVar7 < DAT_140029a88._4_4_ && (DAT_1400299a8 != 0)) &&
         ((-1 < (int)uVar5 && ((-1 < param_1 && (uVar7 < DAT_140029a88._4_4_)))))))) {
    uVar6 = *(uint *)(DAT_140029a98 + (ulonglong)(uVar7 * (uint)DAT_140029a88 + uVar5) * 4);
    if ((uVar6 != 0) && (uVar6 < DAT_14002a870)) {
      if ((ulonglong)DAT_14002a870 <= (ulonglong)uVar6) {
        pcVar2 = (code *)swi(3);
        uVar3 = (*pcVar2)();
        return uVar3;
      }
      piVar1 = *(int **)(DAT_14002a868 + (ulonglong)uVar6 * 8);
      if (((piVar1 != (int *)0x0) && (*(longlong *)(piVar1 + 2) != 0)) && (*piVar1 == 1)) {
        uVar4 = 0;
        if (DAT_140029200 != 0) {
          do {
            if (DAT_140029200 <= uVar4) {
              pcVar2 = (code *)swi(3);
              uVar3 = (*pcVar2)();
              return uVar3;
            }
            if (((*(int *)(DAT_1400291f8 + 0x24 + uVar4 * 0x28) != 0) &&
                (*(uint *)(DAT_1400291f8 + 1 + uVar4 * 0x28) == uVar5)) &&
               (*(uint *)(DAT_1400291f8 + 5 + uVar4 * 0x28) == uVar7)) {
              if (-1 < (int)uVar4) {
                return 0;
              }
              break;
            }
            uVar6 = (int)uVar4 + 1;
            uVar4 = (ulonglong)uVar6;
          } while (uVar6 < DAT_140029200);
        }
        uStack_27 = (undefined7)param_1;
        uStack_20 = (undefined1)((ulonglong)param_1 >> 0x38);
        local_28 = '\x06';
        uStack_18 = uStack_20;
        uStack_16 = 0;
        uStack_15 = 0;
        uStack_14 = (0.150000006f);
        uStack_10 = 1;
        uStack_1f = uStack_27;
        bStack_17 = param_2;
        uVar4 = FUN_140013530(0x1400291d0,&local_28);
        if (-1 < (int)uVar4) {
          return 1;
        }
        if (param_2 < DAT_140029a30) {
          if ((ulonglong)DAT_140029a30 <= (ulonglong)param_2) {
            pcVar2 = (code *)swi(3);
            uVar3 = (*pcVar2)();
            return uVar3;
          }
          piVar1 = (int *)(DAT_140029a28 + (ulonglong)param_2 * 4);
          *piVar1 = *piVar1 + param_3;
        }
      }
    }
  }
  return 0;
}


// ===== FUN_140013530 @ 140013530 size=562

ulonglong FUN_140013530(longlong param_1,char *param_2)

{
  ulonglong *puVar1;
  undefined8 *puVar2;
  uint uVar3;
  code *pcVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  longlong lVar10;
  int iVar11;
  undefined1 *puVar12;
  longlong *plVar13;
  undefined1 *puVar14;
  longlong lVar15;
  undefined1 *puVar16;
  int iStackX_14;
  
  if (*param_2 == '\0') {
    return 0xffffffff;
  }
  uVar9 = 0;
  uVar3 = *(uint *)(param_1 + 0x30);
  if (uVar3 != 0) {
    iStackX_14 = (int)((ulonglong)*(undefined8 *)(param_2 + 1) >> 0x20);
    do {
      iVar11 = (int)uVar9;
      if (uVar3 <= uVar9) {
        pcVar4 = (code *)swi(3);
        uVar9 = (*pcVar4)();
        return uVar9;
      }
      lVar10 = *(longlong *)(param_1 + 0x28);
      if (((*(int *)(lVar10 + 0x24 + uVar9 * 0x28) != 0) &&
          (*(int *)(lVar10 + 1 + uVar9 * 0x28) == (int)*(undefined8 *)(param_2 + 1))) &&
         (*(int *)(lVar10 + 5 + uVar9 * 0x28) == iStackX_14)) {
        if (-1 < iVar11) {
          uVar6 = *(undefined8 *)(param_2 + 8);
          uVar7 = *(undefined8 *)(param_2 + 0x10);
          uVar8 = *(undefined8 *)(param_2 + 0x18);
          lVar15 = (longlong)iVar11;
          if ((longlong)(ulonglong)*(uint *)(param_1 + 0x30) <= lVar15) {
            pcVar4 = (code *)swi(3);
            uVar9 = (*pcVar4)();
            return uVar9;
          }
          if (iVar11 < 0) {
            puVar2 = (undefined8 *)(lVar10 + ((ulonglong)*(uint *)(param_1 + 0x30) + lVar15) * 0x28)
            ;
            *puVar2 = *(undefined8 *)param_2;
            puVar2[1] = uVar6;
            puVar2[2] = uVar7;
            puVar2[3] = uVar8;
            return uVar9;
          }
          puVar2 = (undefined8 *)(lVar10 + lVar15 * 0x28);
          *puVar2 = *(undefined8 *)param_2;
          puVar2[1] = uVar6;
          puVar2[2] = uVar7;
          puVar2[3] = uVar8;
          return uVar9;
        }
        break;
      }
      uVar3 = *(uint *)(param_1 + 0x30);
      uVar9 = (ulonglong)(iVar11 + 1U);
    } while (iVar11 + 1U < uVar3);
  }
  uVar3 = *(uint *)(param_1 + 0x34);
  if (*(uint *)(param_1 + 0x30) != uVar3) goto LAB_1400136b2;
  uVar5 = 8;
  if (8 < uVar3 * 2) {
    uVar5 = uVar3 * 2;
  }
  if (uVar5 <= uVar3) goto LAB_1400136b2;
  puVar14 = *(undefined1 **)(param_1 + 0x28);
  plVar13 = &DAT_140029878;
  if (*(longlong **)(param_1 + 0x20) != (longlong *)0x0) {
    plVar13 = *(longlong **)(param_1 + 0x20);
  }
  puVar1 = (ulonglong *)(plVar13 + 2);
  if (puVar14 == (undefined1 *)0x0) {
    uVar9 = *puVar1 + 3 & 0xfffffffffffffffc;
    *puVar1 = uVar9;
    puVar12 = (undefined1 *)(*plVar13 + uVar9);
LAB_14001369a:
    *puVar1 = *puVar1 + (ulonglong)uVar5 * 0x28;
  }
  else {
    uVar9 = *puVar1;
    if (puVar14 + (ulonglong)uVar3 * 0x28 != (undefined1 *)(uVar9 + *plVar13)) {
      uVar9 = uVar9 + 3 & 0xfffffffffffffffc;
      *puVar1 = uVar9;
      puVar12 = (undefined1 *)(uVar9 + *plVar13);
      puVar16 = puVar12;
      for (lVar10 = (ulonglong)uVar3 * 0x28; lVar10 != 0; lVar10 = lVar10 + -1) {
        *puVar16 = *puVar14;
        puVar14 = puVar14 + 1;
        puVar16 = puVar16 + 1;
      }
      goto LAB_14001369a;
    }
    *puVar1 = uVar9 + (ulonglong)(uVar5 - uVar3) * 0x28;
    puVar12 = puVar14;
  }
  *(undefined1 **)(param_1 + 0x28) = puVar12;
  *(uint *)(param_1 + 0x34) = uVar5;
LAB_1400136b2:
  uVar3 = *(uint *)(param_1 + 0x30);
  lVar10 = *(longlong *)(param_1 + 0x28);
  puVar2 = (undefined8 *)(lVar10 + (ulonglong)uVar3 * 0x28);
  *puVar2 = 0;
  puVar2[1] = 0;
  puVar2[2] = 0;
  puVar2[3] = 0x100000000;
  *(undefined8 *)(lVar10 + 0x20 + (ulonglong)uVar3 * 0x28) = 0xffffffff;
  uVar9 = (ulonglong)*(uint *)(param_1 + 0x30);
  *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) + 1;
  uVar6 = *(undefined8 *)(param_2 + 8);
  uVar7 = *(undefined8 *)(param_2 + 0x10);
  uVar8 = *(undefined8 *)(param_2 + 0x18);
  lVar10 = *(longlong *)(param_1 + 0x28);
  puVar2 = (undefined8 *)(lVar10 + uVar9 * 0x28);
  *puVar2 = *(undefined8 *)param_2;
  puVar2[1] = uVar6;
  puVar2[2] = uVar7;
  puVar2[3] = uVar8;
  *(undefined4 *)(lVar10 + 0x20 + uVar9 * 0x28) = 0xffffffff;
  *(undefined4 *)(lVar10 + 0x24 + uVar9 * 0x28) = 1;
  FUN_1400036d0(param_1);
  return (ulonglong)(*(int *)(param_1 + 0x30) - 1);
}


// ===== FUN_140013770 @ 140013770 size=419

void FUN_140013770(ulonglong param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  uint uVar3;
  ulonglong uVar4;
  char cVar5;
  uint uVar6;
  uint uStackX_c;
  char local_28;
  undefined7 uStack_27;
  undefined1 uStack_20;
  undefined7 uStack_1f;
  undefined1 uStack_18;
  undefined2 uStack_17;
  undefined1 uStack_15;
  undefined4 uStack_14;
  undefined8 uStack_10;
  
  uVar2 = FUN_14001cac0(param_1);
  if ((int)uVar2 == 0) {
    return;
  }
  uVar4 = 0;
  uStackX_c = (uint)(param_1 >> 0x20);
  uVar6 = (uint)param_1;
  if (DAT_140029200 != 0) {
    do {
      if (DAT_140029200 <= uVar4) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      if (((*(int *)(DAT_1400291f8 + 0x24 + uVar4 * 0x28) != 0) &&
          (*(uint *)(DAT_1400291f8 + 1 + uVar4 * 0x28) == uVar6)) &&
         (*(uint *)(DAT_1400291f8 + 5 + uVar4 * 0x28) == uStackX_c)) {
        if (-1 < (int)uVar4) {
          return;
        }
        break;
      }
      uVar3 = (int)uVar4 + 1;
      uVar4 = (ulonglong)uVar3;
    } while (uVar3 < DAT_140029200);
  }
  uVar2 = FUN_14001cac0(param_1);
  if ((int)uVar2 == 0) {
    uStack_27 = 0;
    uStack_20 = 0;
    uStack_10 = 0x100000000;
    uStack_14 = 0;
  }
  else {
    if ((uVar6 < (uint)DAT_140029a88) && (uStackX_c < DAT_140029a88._4_4_)) {
      cVar5 = *(char *)((ulonglong)(uStackX_c * (uint)DAT_140029a88 + uVar6) + DAT_140029a90);
    }
    else {
      cVar5 = '\0';
    }
    if ((cVar5 == '\x02') || (cVar5 == '\x03')) {
      uStack_10 = 1;
      uVar2 = 2;
      uStack_14 = (8f);
    }
    else if (cVar5 == '\x04') {
      uStack_10 = 0x100000001;
      uVar2 = 3;
      uStack_14 = (6f);
    }
    else {
      if (cVar5 != '\x06') {
        uVar2 = 0;
        uStack_27 = 0;
        uStack_20 = 0;
        uStack_10 = 0x100000000;
        uStack_14 = 0;
        goto LAB_1400138d7;
      }
      uStack_10 = 0x100000001;
      uVar2 = 1;
      uStack_14 = (1.5f);
    }
    uStack_27 = (undefined7)param_1;
    uStack_20 = (undefined1)(param_1 >> 0x38);
  }
LAB_1400138d7:
  uStack_1f = 0;
  local_28 = (char)uVar2;
  uStack_18 = 0;
  uStack_17 = 0;
  uStack_15 = 0;
  if (local_28 != '\0') {
    FUN_140013530(0x1400291d0,&local_28);
  }
  return;
}


// ===== FUN_140013920 @ 140013920 size=528

void FUN_140013920(longlong *param_1,undefined4 *param_2)

{
  char cVar1;
  code *pcVar2;
  undefined1 uVar3;
  byte bVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  ulonglong uVar8;
  uint uVar10;
  char local_res8 [32];
  ulonglong uVar9;
  
  uVar6 = *(uint *)(param_1 + 1);
  if (*(int *)((longlong)param_1 + 0xc) - uVar6 < 4) {
    uVar5 = 0;
    *(undefined4 *)(param_1 + 2) = 1;
  }
  else {
    uVar5 = swap_bytes(*(undefined4 *)((ulonglong)uVar6 + *param_1));
    *(uint *)(param_1 + 1) = uVar6 + 4;
  }
  *param_2 = uVar5;
  uVar6 = *(uint *)(param_1 + 1);
  if (*(int *)((longlong)param_1 + 0xc) - uVar6 < 4) {
    uVar5 = 0;
    *(undefined4 *)(param_1 + 2) = 1;
  }
  else {
    uVar5 = swap_bytes(*(undefined4 *)((ulonglong)uVar6 + *param_1));
    *(uint *)(param_1 + 1) = uVar6 + 4;
  }
  param_2[1] = uVar5;
  uVar6 = *(uint *)(param_1 + 1);
  if (*(uint *)((longlong)param_1 + 0xc) == uVar6) {
    uVar3 = 0;
    *(undefined4 *)(param_1 + 2) = 1;
  }
  else {
    uVar3 = *(undefined1 *)((ulonglong)uVar6 + *param_1);
    *(uint *)(param_1 + 1) = uVar6 + 1;
  }
  *(undefined1 *)(param_2 + 2) = uVar3;
  uVar6 = *(uint *)(param_1 + 1);
  if (*(uint *)((longlong)param_1 + 0xc) == uVar6) {
    bVar4 = 0;
    *(undefined4 *)(param_1 + 2) = 1;
  }
  else {
    bVar4 = *(byte *)((ulonglong)uVar6 + *param_1);
    *(uint *)(param_1 + 1) = uVar6 + 1;
  }
  uVar7 = 5;
  builtin_strncpy(local_res8,"\x01\x02\x04\b\x10",5);
  uVar10 = (uint)bVar4;
  uVar6 = 0;
  if (bVar4 != 0) {
    if (bVar4 != 2) {
      if (bVar4 == 3) {
        uVar7 = 4;
        uVar6 = 0;
        goto LAB_140013a27;
      }
      if ((bVar4 != 4) && (bVar4 != 6)) {
        FUN_140002010("Color type is wrong!");
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
    }
    uVar6 = 3;
  }
LAB_140013a27:
  while (*(char *)(param_2 + 2) != local_res8[uVar6]) {
    uVar6 = uVar6 + 1;
    if (uVar7 <= uVar6) {
      FUN_140002010("Bit depth not acceptable for color type!");
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
  }
  param_2[3] = uVar10 & 1;
  param_2[4] = uVar10 & 2;
  param_2[5] = uVar10 & 4;
  uVar6 = *(uint *)((longlong)param_1 + 0xc);
  uVar7 = *(uint *)(param_1 + 1);
  uVar8 = (ulonglong)uVar7;
  if (uVar6 == uVar7) {
    *(undefined4 *)(param_1 + 2) = 1;
  }
  else {
    cVar1 = *(char *)(uVar8 + *param_1);
    *(uint *)(param_1 + 1) = uVar7 + 1;
    uVar8 = (ulonglong)(uVar7 + 1);
    if (cVar1 != '\0') {
      FUN_140002010("Compression method isn\'t deflate!");
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
  }
  if (uVar6 == (uint)uVar8) {
    *(undefined4 *)(param_1 + 2) = 1;
    uVar9 = uVar8;
  }
  else {
    uVar7 = (uint)uVar8 + 1;
    uVar9 = (ulonglong)uVar7;
    cVar1 = *(char *)(uVar8 + *param_1);
    *(uint *)(param_1 + 1) = uVar7;
    if (cVar1 != '\0') {
      FUN_140002010("Filter method isn\'t recognized!");
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
  }
  if (uVar6 != (uint)uVar9) {
    bVar4 = *(byte *)(uVar9 + *param_1);
    *(uint *)(param_1 + 1) = (uint)uVar9 + 1;
    param_2[6] = (uint)bVar4;
    return;
  }
  *(undefined4 *)(param_1 + 2) = 1;
  param_2[6] = 0;
  return;
}


// ===== FUN_140013b30 @ 140013b30 size=2199

void FUN_140013b30(longlong *param_1,undefined8 *param_2,uint *param_3,int *param_4,
                  undefined8 *param_5)

{
  char *pcVar1;
  char cVar2;
  byte bVar3;
  code *pcVar4;
  uint uVar5;
  char *pcVar6;
  byte *pbVar7;
  int iVar8;
  longlong lVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  longlong *plVar12;
  byte *pbVar13;
  int iVar14;
  byte *pbVar15;
  uint uVar16;
  ulonglong uVar17;
  longlong lVar18;
  int iVar19;
  byte *pbVar20;
  int iVar21;
  ulonglong uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  ulonglong uVar26;
  uint local_108;
  uint local_104;
  char local_f8 [8];
  byte *local_f0;
  byte *local_e8;
  byte *local_e0;
  longlong *local_d8;
  undefined1 local_d0 [16];
  undefined8 local_c0;
  undefined1 local_b0 [16];
  undefined1 local_98 [16];
  undefined8 local_88;
  char *local_78;
  undefined8 uStack_70;
  longlong local_68;
  undefined1 local_60 [16];
  
  plVar12 = &DAT_140029818;
  *param_2 = 0;
  *param_3 = 0;
  if (param_1 == &DAT_140029818) {
    plVar12 = &DAT_140029830;
  }
  *param_4 = 0;
  local_68 = plVar12[2];
  local_78 = (char *)*param_5;
  uStack_70 = param_5[1];
  local_d8 = plVar12;
  local_78 = (char *)FUN_1400015f0((DWORD *)&param_5,plVar12,(longlong *)&local_78);
  uVar25 = (uint)param_5;
  local_f8[0] = -0x77;
  local_f8[1] = 'P';
  local_f8[2] = 'N';
  local_f8[3] = 'G';
  local_f8[4] = '\r';
  local_f8[5] = '\n';
  local_f8[6] = '\x1a';
  local_f8[7] = '\n';
  if ((local_78 != (char *)0x0) && (uVar26 = (ulonglong)param_5 & 0xffffffff, 8 < (uint)param_5)) {
    uVar23 = 8;
    lVar9 = 8;
    pcVar6 = local_78;
    do {
      pcVar1 = pcVar6 + (longlong)(local_f8 + -(longlong)local_78);
      lVar9 = lVar9 + -1;
      cVar2 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      if (cVar2 != *pcVar1) goto LAB_1400142c1;
    } while (lVar9 != 0);
    local_e0 = (byte *)0x0;
    local_104 = 0;
    param_5._0_4_ = 0;
    local_108 = 0;
    local_c0 = 0;
    local_b0 = (undefined1  [16])0x0;
    local_b0._12_4_ = 0;
    local_b0._0_8_ = (byte *)0x0;
    local_98 = (undefined1  [16])0x0;
    local_60 = (undefined1  [16])0x0;
    local_d0 = (undefined1  [16])0x0;
    pbVar13 = (byte *)local_b0._0_8_;
    uVar24 = local_b0._12_4_;
    if (0xf < uVar25) {
      local_e8 = (byte *)0x0;
      local_f0 = (byte *)0x0;
      uVar11 = 0;
LAB_140013c71:
      local_88 = 0;
      if (uVar25 - uVar23 < 4) {
        uVar17 = 0;
      }
      else {
        uVar17 = (ulonglong)uVar23;
        uVar23 = uVar23 + 4;
        uVar5 = swap_bytes(*(undefined4 *)(local_78 + uVar17));
        uVar17 = (ulonglong)uVar5;
      }
      pbVar20 = (byte *)(local_78 + uVar23);
      lVar9 = 4;
      pbVar7 = pbVar20;
      do {
        pbVar15 = pbVar7 + ((longlong)&DAT_1400244f8 - (longlong)pbVar20);
        lVar9 = lVar9 + -1;
        bVar3 = *pbVar7;
        pbVar7 = pbVar7 + 1;
        uVar5 = (uint)uVar17;
        plVar12 = local_d8;
        uVar22 = uVar11;
        if (bVar3 != *pbVar15) {
          lVar9 = 4;
          pbVar7 = pbVar20;
          goto LAB_140013d20;
        }
      } while (lVar9 != 0);
      if (pbVar13 != (byte *)0x0) {
        FUN_140002010("IDAT appeared before IHDR!");
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      if (local_e8 != (byte *)0x0) {
        FUN_140002010("PLTE appeared before IHDR!");
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      if (local_f0 != (byte *)0x0) {
        FUN_140002010("tRNS appeared before IHDR!");
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      local_98._8_4_ = 0;
      local_98._0_8_ = pbVar20 + 4;
      local_98._12_4_ = (uVar25 - uVar23) + -4;
      goto LAB_140013ec5;
    }
    local_e8 = (byte *)0x0;
    local_f0 = (byte *)0x0;
LAB_140013f8c:
    pbVar20 = local_e8;
    pbVar7 = local_f0;
    uVar25 = local_104;
    local_88 = 0;
    if (local_98._0_8_ == 0) {
      FUN_140002010("No header!");
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    if (pbVar13 == (byte *)0x0) {
      FUN_140002010("No data!");
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    FUN_140013920((longlong *)local_98,(undefined4 *)local_d0);
    if (local_d0._12_4_ == 0) {
      if (pbVar7 != (byte *)0x0) {
        if ((int)local_c0 == 0) {
          if ((uint)param_5 != 2) {
            FUN_140002010("Transparency not a 2 byte single value!");
            pcVar4 = (code *)swi(3);
            (*pcVar4)();
            return;
          }
        }
        else if ((uint)param_5 != 6) {
          FUN_140002010("Transparency not a 6 byte RGB triplet!");
          pcVar4 = (code *)swi(3);
          (*pcVar4)();
          return;
        }
      }
    }
    else {
      if (pbVar20 == (byte *)0x0) {
        FUN_140002010("Palette required in header, but none provided!");
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      if (uVar25 < (uint)param_5) {
        FUN_140002010("tRNS has more entries than PLTE!");
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
    }
    if (uVar24 != 0) {
      local_108 = 1;
      if ((*pbVar13 & 0xf) == 8) {
        if (0xf < (byte)((*pbVar13 >> 4) + 8)) {
          FUN_140002010("Window bits was greater than 15! This is illegal");
          pcVar4 = (code *)swi(3);
          (*pcVar4)();
          return;
        }
        if ((uVar24 != 1) && (local_108 = 2, (pbVar13[1] & 0x20) != 0)) {
          FUN_140002010("Unknown dictionary!");
          pcVar4 = (code *)swi(3);
          (*pcVar4)();
          return;
        }
        uVar25 = local_108;
        uVar26 = (ulonglong)local_108;
        uVar23 = local_d0._0_4_;
        iVar14 = local_d0._4_4_;
        lVar9 = FUN_14000a860(plVar12,(ulonglong *)(pbVar13 + uVar26),&local_e0,&local_108,
                              ((((local_c0._4_4_ != 0) + 1 + (-(uint)((int)local_c0 != 0) & 2)) *
                                (uint)local_d0[8] * local_d0._0_4_ + 7 >> 3) + 1) * local_d0._4_4_,
                              (undefined2 *)&DAT_140029f00,(undefined2 *)&DAT_14002a3a0);
        uVar5 = ((int)lVar9 - (int)pbVar13) - uVar25;
        if (uVar5 <= uVar24 - uVar25) {
          uVar26 = (ulonglong)(uVar25 + uVar5);
        }
        if (uVar24 - (int)uVar26 < 4) {
          uVar25 = 0;
        }
        else {
          uVar25 = swap_bytes(*(undefined4 *)(pbVar13 + uVar26));
        }
        uVar16 = 0;
        uVar5 = 1;
        pbVar13 = local_e0;
        uVar24 = local_108;
        if (0x15af < local_108) {
          pbVar7 = local_e0 + 2;
          uVar26 = (ulonglong)local_108 / 0x15b0;
          do {
            iVar14 = 0;
            iVar19 = 0;
            iVar21 = 0;
            lVar9 = 0x56c;
            pbVar20 = pbVar7;
            do {
              uVar16 = uVar16 + uVar5 + pbVar20[-2];
              iVar8 = uVar5 + pbVar20[-2] + (uint)pbVar20[-1];
              iVar21 = iVar21 + iVar8;
              iVar8 = iVar8 + (uint)*pbVar20;
              iVar19 = iVar19 + iVar8;
              uVar5 = iVar8 + (uint)pbVar20[1];
              iVar14 = iVar14 + uVar5;
              lVar9 = lVar9 + -1;
              pbVar20 = pbVar20 + 4;
            } while (lVar9 != 0);
            pbVar13 = pbVar13 + 0x15b0;
            pbVar7 = pbVar7 + 0x15b0;
            uVar24 = uVar24 - 0x15b0;
            uVar5 = uVar5 % 0xfff1;
            uVar16 = (uVar16 + iVar21 + iVar19 + iVar14) % 0xfff1;
            uVar26 = uVar26 - 1;
          } while (uVar26 != 0);
          iVar14 = local_d0._4_4_;
          uVar23 = local_d0._0_4_;
        }
        for (; uVar24 != 0; uVar24 = uVar24 - 1) {
          uVar5 = uVar5 + *pbVar13;
          uVar16 = uVar16 + uVar5;
          pbVar13 = pbVar13 + 1;
        }
        if (uVar25 != (uVar5 % 0xfff1 | ((uVar16 / 0xfff1) * 0xf + uVar16) * 0x10000)) {
          FUN_140002010("Data checksums don\'t match!");
          pcVar4 = (code *)swi(3);
          (*pcVar4)();
          return;
        }
        uVar26 = param_1[2] + 3U & 0xfffffffffffffffc;
        pbVar13 = (byte *)(uVar26 + *param_1);
        param_1[2] = uVar26 + (ulonglong)(iVar14 * uVar23) * 4;
        FUN_14001cff0((uint *)local_d0,local_e0,local_108,pbVar13,(longlong)local_e8,local_104,
                      local_f0,(uint)param_5);
        *param_2 = pbVar13;
        *param_3 = uVar23;
        *param_4 = iVar14;
        plVar12 = local_d8;
        goto LAB_1400142c1;
      }
    }
    FUN_140002010("Compression wasn\'t deflate, this is not supported");
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
LAB_1400142c1:
  plVar12[2] = local_68;
  return;
  while (lVar9 != 0) {
LAB_140013d20:
    pbVar15 = pbVar7 + ((longlong)&DAT_14002455c - (longlong)pbVar20);
    lVar9 = lVar9 + -1;
    bVar3 = *pbVar7;
    pbVar7 = pbVar7 + 1;
    if (bVar3 != *pbVar15) {
      lVar9 = 4;
      pbVar7 = pbVar20;
      goto LAB_140013e30;
    }
  }
  if (pbVar13 == (byte *)0x0) {
    uVar24 = (uVar25 - uVar23) - 4;
    local_108 = (int)uVar11 + uVar5;
    uVar22 = (ulonglong)local_108;
    pbVar13 = pbVar20 + 4;
  }
  else {
    uVar24 = uVar5 + (int)uVar11;
    uVar22 = (ulonglong)uVar24;
    lVar9 = local_d8[2];
    if (local_e0 == (byte *)0x0) {
      local_d8[2] = (ulonglong)uVar24 + lVar9;
      local_e0 = (byte *)(*local_d8 + lVar9);
      pbVar7 = local_e0;
      for (uVar10 = uVar11; uVar10 != 0; uVar10 = uVar10 - 1) {
        *pbVar7 = *pbVar13;
        pbVar13 = pbVar13 + 1;
        pbVar7 = pbVar7 + 1;
      }
      pbVar7 = local_e0 + uVar11;
    }
    else {
      pbVar13 = (byte *)0x0;
      if (local_e0 + uVar11 == (byte *)(lVar9 + *local_d8)) {
        pbVar7 = local_e0 + uVar11;
        local_d8[2] = uVar17 + lVar9;
      }
      else {
        if (local_108 < uVar24) {
          pbVar13 = (byte *)(*local_d8 + lVar9);
          local_d8[2] = lVar9;
          pbVar7 = pbVar13;
          for (uVar10 = uVar11; uVar10 != 0; uVar10 = uVar10 - 1) {
            *pbVar7 = *local_e0;
            local_e0 = local_e0 + 1;
            pbVar7 = pbVar7 + 1;
          }
          local_d8[2] = local_d8[2] + (ulonglong)uVar24;
        }
        pbVar7 = pbVar13 + uVar11;
        local_e0 = pbVar13;
      }
    }
    pbVar15 = pbVar20 + 4;
    for (; pbVar13 = local_e0, local_108 = uVar24, uVar17 != 0; uVar17 = uVar17 - 1) {
      *pbVar7 = *pbVar15;
      pbVar15 = pbVar15 + 1;
      pbVar7 = pbVar7 + 1;
    }
  }
  goto LAB_140013ec5;
  while (lVar9 != 0) {
LAB_140013e30:
    bVar3 = *pbVar7;
    lVar9 = lVar9 + -1;
    pbVar15 = pbVar7 + ((longlong)&DAT_140024564 - (longlong)pbVar20);
    pbVar7 = pbVar7 + 1;
    if (bVar3 != *pbVar15) {
      lVar9 = 4;
      pbVar7 = pbVar20;
      goto LAB_140013e71;
    }
  }
  if (pbVar13 != (byte *)0x0) {
    FUN_140002010("IDAT appeared before tRNS!");
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  local_f0 = pbVar20 + 4;
  param_5._0_4_ = uVar5;
  goto LAB_140013ec5;
  while (lVar9 != 0) {
LAB_140013e71:
    pbVar15 = pbVar7 + ((longlong)&DAT_14002458c - (longlong)pbVar20);
    lVar9 = lVar9 + -1;
    bVar3 = *pbVar7;
    pbVar7 = pbVar7 + 1;
    if (bVar3 != *pbVar15) {
      lVar9 = 4;
      lVar18 = (longlong)&DAT_140024620 - (longlong)pbVar20;
      goto LAB_140013f60;
    }
  }
  if (local_f0 != (byte *)0x0) {
    FUN_140002010("tRNS appeared before PLTE!");
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  local_104 = (uint)(uVar17 / 3);
  if (uVar5 != local_104 * 3) {
    FUN_140002010("Pallet length not given in RGB triplets!");
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  if (0x100 < local_104) {
    FUN_140002010("Palette length is greater than max allowed size of 256!");
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  local_e8 = pbVar20 + 4;
LAB_140013ec5:
  local_88 = 0;
  uVar11 = 0xffffffff;
  if (uVar5 + 4 != 0) {
    uVar17 = (ulonglong)(uVar5 + 4);
    do {
      bVar3 = *pbVar20;
      pbVar20 = pbVar20 + 1;
      uVar11 = uVar11 >> 8 ^ (ulonglong)(uint)(&DAT_140029b00)[(byte)(bVar3 ^ (byte)uVar11)];
      uVar17 = uVar17 - 1;
    } while (uVar17 != 0);
    uVar22 = (ulonglong)local_108;
  }
  if (3 < uVar25 - uVar23) {
    uVar23 = uVar23 + 4;
  }
  if (uVar5 <= uVar25 - uVar23) {
    uVar23 = uVar23 + uVar5;
  }
  if (uVar25 - uVar23 < 4) {
    uVar5 = 0;
  }
  else {
    uVar17 = (ulonglong)uVar23;
    uVar23 = uVar23 + 4;
    uVar5 = swap_bytes(*(undefined4 *)(local_78 + uVar17));
  }
  if (~(uint)uVar11 != uVar5) {
    FUN_140002010("Block CRC32 doesn\'t match! Data corruption?");
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
LAB_140013fc4:
  uVar11 = uVar22;
  if ((longlong)(uVar26 - uVar23) < 8) goto LAB_140013f8c;
  goto LAB_140013c71;
LAB_140013f60:
  pbVar7 = pbVar20 + lVar18;
  lVar9 = lVar9 + -1;
  bVar3 = *pbVar20;
  pbVar20 = pbVar20 + 1;
  if (bVar3 != *pbVar7) goto LAB_140013f99;
  if (lVar9 == 0) goto LAB_140013f8c;
  goto LAB_140013f60;
LAB_140013f99:
  if (3 < uVar25 - uVar23) {
    uVar23 = uVar23 + 4;
  }
  if (uVar5 <= uVar25 - uVar23) {
    uVar23 = uVar23 + uVar5;
  }
  if (3 < uVar25 - uVar23) {
    uVar23 = uVar23 + 4;
  }
  goto LAB_140013fc4;
}


// ===== FUN_1400143d0 @ 1400143d0 size=246

ulonglong FUN_1400143d0(longlong param_1,ulonglong *param_2)

{
  ushort uVar1;
  code *pcVar2;
  sbyte sVar3;
  int iVar4;
  ulonglong uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  ushort *puVar10;
  int iVar11;
  int iVar12;
  
  puVar10 = (ushort *)(param_1 + 2);
  uVar5 = *param_2;
  iVar12 = (int)param_2[2] + -0xf;
  *param_2 = *param_2 >> 0xf;
  uVar8 = (uint)uVar5 & 0x7fff;
  iVar11 = 0;
  *(int *)(param_2 + 2) = iVar12;
  iVar4 = 0;
  uVar9 = 0;
  uVar7 = 1;
  do {
    uVar1 = *puVar10;
    uVar6 = uVar8 & 1;
    uVar8 = uVar8 >> 1;
    uVar9 = uVar9 * 2 | uVar6;
    if ((int)(uVar9 - uVar1) < iVar4) {
      uVar7 = 0xf - uVar7;
      sVar3 = ((byte)uVar7 < 0x21) * (' ' - (byte)uVar7);
      uVar6 = iVar12 + uVar7;
      uVar5 = (ulonglong)((uVar8 << sVar3) >> sVar3) | *param_2 << ((ulonglong)uVar7 & 0x3f);
      *(uint *)(param_2 + 2) = uVar6;
      *param_2 = uVar5;
      if (uVar6 < 0x21) {
        uVar7 = *(uint *)param_2[1];
        param_2[1] = (ulonglong)((uint *)param_2[1] + 1);
        *param_2 = (ulonglong)uVar7 << ((ulonglong)uVar6 & 0x3f) | uVar5;
        *(uint *)(param_2 + 2) = uVar6 + 0x20;
      }
      return (ulonglong)*(ushort *)(param_1 + 0x20 + (longlong)(int)((uVar9 - iVar4) + iVar11) * 2);
    }
    iVar11 = iVar11 + (uint)uVar1;
    iVar4 = (iVar4 + (uint)uVar1) * 2;
    uVar7 = uVar7 + 1;
    puVar10 = puVar10 + 1;
  } while (uVar7 < 0x10);
  FUN_140002010("Huffman decode failed");
  pcVar2 = (code *)swi(3);
  uVar5 = (*pcVar2)();
  return uVar5;
}


// ===== FUN_1400144d0 @ 1400144d0 size=631

void FUN_1400144d0(ulonglong *param_1,longlong param_2,uint param_3,longlong param_4)

{
  byte bVar1;
  undefined1 uVar2;
  ushort uVar3;
  code *pcVar4;
  sbyte sVar5;
  ulonglong uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  ushort *puVar10;
  uint uVar11;
  uint uVar12;
  ulonglong uVar13;
  uint uVar14;
  
  if (param_3 != 0) {
    uVar6 = 0;
    do {
      puVar10 = (ushort *)(param_2 + 2);
      *(int *)(param_1 + 2) = (int)param_1[2] + -0xf;
      uVar12 = (uint)*param_1 & 0x7fff;
      *param_1 = *param_1 >> 0xf;
      iVar9 = 0;
      iVar8 = 0;
      uVar11 = 0;
      uVar14 = 1;
      while( true ) {
        if (0xf < uVar14) {
          FUN_140002010("Huffman decode failed");
          pcVar4 = (code *)swi(3);
          (*pcVar4)();
          return;
        }
        uVar3 = *puVar10;
        uVar7 = uVar12 & 1;
        uVar12 = uVar12 >> 1;
        uVar11 = uVar11 * 2 | uVar7;
        if ((int)(uVar11 - uVar3) < iVar8) break;
        iVar9 = iVar9 + (uint)uVar3;
        iVar8 = (iVar8 + (uint)uVar3) * 2;
        uVar14 = uVar14 + 1;
        puVar10 = puVar10 + 1;
      }
      uVar14 = 0xf - uVar14;
      sVar5 = ((byte)uVar14 < 0x21) * (' ' - (byte)uVar14);
      uVar7 = (int)param_1[2] + uVar14;
      uVar13 = (ulonglong)((uVar12 << sVar5) >> sVar5) | *param_1 << ((ulonglong)uVar14 & 0x3f);
      *(uint *)(param_1 + 2) = uVar7;
      *param_1 = uVar13;
      if (uVar7 < 0x21) {
        uVar13 = (ulonglong)*(uint *)param_1[1] << ((ulonglong)uVar7 & 0x3f) | uVar13;
        param_1[1] = (ulonglong)((uint *)param_1[1] + 1);
        uVar7 = uVar7 + 0x20;
        *param_1 = uVar13;
        *(uint *)(param_1 + 2) = uVar7;
      }
      bVar1 = *(byte *)(param_2 + 0x20 + (longlong)(int)((uVar11 - iVar8) + iVar9) * 2);
      if (bVar1 < 0x10) {
        *(byte *)(uVar6 + param_4) = bVar1;
        uVar6 = (ulonglong)((int)uVar6 + 1);
      }
      else {
        uVar14 = (uint)uVar13;
        if (bVar1 == 0x10) {
          uVar2 = *(undefined1 *)((ulonglong)((int)uVar6 - 1) + param_4);
          uVar11 = uVar7 - 2;
          *(uint *)(param_1 + 2) = uVar11;
          *param_1 = uVar13 >> 2;
          if (uVar11 < 0x21) {
            uVar12 = *(uint *)param_1[1];
            param_1[1] = (ulonglong)((uint *)param_1[1] + 1);
            *param_1 = (ulonglong)uVar12 << ((ulonglong)uVar11 & 0x3f) | uVar13 >> 2;
            *(uint *)(param_1 + 2) = uVar7 + 0x1e;
          }
          uVar14 = (uVar14 & 3) + 3;
          if (uVar14 != 0) {
            uVar13 = (ulonglong)uVar14;
            do {
              *(undefined1 *)(uVar6 + param_4) = uVar2;
              uVar6 = (ulonglong)((int)uVar6 + 1);
              uVar13 = uVar13 - 1;
            } while (uVar13 != 0);
          }
        }
        else if (bVar1 == 0x11) {
          uVar11 = uVar7 - 3;
          *(uint *)(param_1 + 2) = uVar11;
          *param_1 = uVar13 >> 3;
          if (uVar11 < 0x21) {
            uVar12 = *(uint *)param_1[1];
            param_1[1] = (ulonglong)((uint *)param_1[1] + 1);
            *param_1 = (ulonglong)uVar12 << ((ulonglong)uVar11 & 0x3f) | uVar13 >> 3;
            *(uint *)(param_1 + 2) = uVar7 + 0x1d;
          }
          uVar14 = (uVar14 & 7) + 3;
          if (uVar14 != 0) {
            uVar13 = (ulonglong)uVar14;
            do {
              *(undefined1 *)(uVar6 + param_4) = 0;
              uVar6 = (ulonglong)((int)uVar6 + 1);
              uVar13 = uVar13 - 1;
            } while (uVar13 != 0);
          }
        }
        else {
          if (bVar1 != 0x12) {
            FUN_140002010("Bad length!");
            pcVar4 = (code *)swi(3);
            (*pcVar4)();
            return;
          }
          uVar11 = uVar7 - 7;
          *(uint *)(param_1 + 2) = uVar11;
          *param_1 = uVar13 >> 7;
          if (uVar11 < 0x21) {
            uVar12 = *(uint *)param_1[1];
            param_1[1] = (ulonglong)((uint *)param_1[1] + 1);
            *param_1 = (ulonglong)uVar12 << ((ulonglong)uVar11 & 0x3f) | uVar13 >> 7;
            *(uint *)(param_1 + 2) = uVar7 + 0x19;
          }
          uVar14 = (uVar14 & 0x7f) + 0xb;
          if (uVar14 != 0) {
            uVar13 = (ulonglong)uVar14;
            do {
              *(undefined1 *)(uVar6 + param_4) = 0;
              uVar6 = (ulonglong)((int)uVar6 + 1);
              uVar13 = uVar13 - 1;
            } while (uVar13 != 0);
          }
        }
      }
    } while ((uint)uVar6 < param_3);
  }
  return;
}


// ===== FUN_140014750 @ 140014750 size=386

void FUN_140014750(uint param_1)

{
  int *piVar1;
  longlong lVar2;
  code *pcVar3;
  undefined1 auVar4 [16];
  longlong lVar5;
  uint local_res10;
  undefined8 uStack_10;
  
  lVar5 = DAT_14002a890;
  if (((((DAT_14002a890 != 0) && (*(longlong *)(DAT_14002a890 + 8) != 0)) &&
       (*(longlong *)(DAT_14002a890 + 8) == DAT_14002a898)) &&
      ((DAT_14002a890 = 0, lVar5 != 0 && (lVar2 = *(longlong *)(lVar5 + 0x120), lVar2 != 0)))) &&
     (param_1 < *(uint *)(lVar2 + 0x10))) {
    if ((ulonglong)*(uint *)(lVar2 + 0x10) <= (ulonglong)param_1) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    lVar2 = *(longlong *)(*(longlong *)(lVar2 + 8) + (ulonglong)param_1 * 8);
    if (lVar2 != *(longlong *)(lVar5 + 0x128)) {
      if (*(int *)(lVar5 + 0x40) != 0) {
        if ((ulonglong)DAT_140029a30 <= (ulonglong)*(byte *)(lVar5 + 0x3c)) {
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        piVar1 = (int *)(DAT_140029a28 + (ulonglong)*(byte *)(lVar5 + 0x3c) * 4);
        *piVar1 = *piVar1 + *(int *)(lVar5 + 0x40);
      }
      local_res10 = CONCAT31(local_res10._1_3_,*(undefined1 *)(lVar2 + 4));
      *(ulonglong *)(lVar5 + 0x3c) = (ulonglong)local_res10;
      if (*(int *)(lVar5 + 0x48) != 0) {
        if ((ulonglong)DAT_140029a30 <= (ulonglong)*(byte *)(lVar5 + 0x44)) {
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        piVar1 = (int *)(DAT_140029a28 + (ulonglong)*(byte *)(lVar5 + 0x44) * 4);
        *piVar1 = *piVar1 + *(int *)(lVar5 + 0x48);
      }
      local_res10 = CONCAT31(local_res10._1_3_,*(undefined1 *)(lVar2 + 4));
      *(ulonglong *)(lVar5 + 0x44) = (ulonglong)local_res10;
      if (*(int *)(lVar5 + 0x50) != 0) {
        if ((ulonglong)DAT_140029a30 <= (ulonglong)*(byte *)(lVar5 + 0x4c)) {
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        piVar1 = (int *)(DAT_140029a28 + (ulonglong)*(byte *)(lVar5 + 0x4c) * 4);
        *piVar1 = *piVar1 + *(int *)(lVar5 + 0x50);
      }
      local_res10 = CONCAT31(local_res10._1_3_,*(undefined1 *)(lVar2 + 4));
      *(ulonglong *)(lVar5 + 0x4c) = (ulonglong)local_res10;
      auVar4._8_8_ = uStack_10;
      auVar4._0_8_ = lVar2;
      auVar4 = vinsertps_avx(auVar4,ZEXT416(*(uint *)(lVar2 + 0x24)),0x20);
      *(undefined1 (*) [16])(lVar5 + 0x128) = auVar4;
    }
    if (((int)param_1 < 0) || (DAT_140029ae0 <= param_1)) {
      param_1 = 0xffffffff;
    }
    DAT_140029128 = param_1;
    DAT_140029af0 = 0;
    DAT_140029af4 = 0;
    return;
  }
  DAT_14002a890 = 0;
  DAT_140029af0 = 0;
  DAT_140029af4 = 0;
  return;
}


// ===== FUN_1400148e0 @ 1400148e0 size=194

void FUN_1400148e0(char param_1)

{
  int *piVar1;
  byte bVar2;
  code *pcVar3;
  uint uVar4;
  longlong lVar6;
  ulonglong uVar7;
  char *pcVar8;
  ulonglong uVar5;
  
  FUN_14000c940();
  uVar7 = 0;
  pcVar8 = &DAT_140029290;
  uVar5 = uVar7;
  while (*pcVar8 != param_1) {
    uVar4 = (int)uVar5 + 1;
    uVar5 = (ulonglong)uVar4;
    pcVar8 = pcVar8 + 0x30;
    if (0xb < uVar4) {
      return;
    }
  }
  lVar6 = uVar5 * 0x30;
  if (lVar6 != -0x140029290) {
    bVar2 = (&DAT_1400292b8)[lVar6];
    if ((bVar2 != 0xe) && (*(int *)(&DAT_1400292bc + lVar6) != 0)) {
      if (DAT_140029a30 <= bVar2) {
        return;
      }
      if ((ulonglong)bVar2 < (ulonglong)DAT_140029a30) {
        piVar1 = (int *)(DAT_140029a28 + (ulonglong)bVar2 * 4);
        *piVar1 = *piVar1 + *(int *)(&DAT_1400292bc + lVar6);
        return;
      }
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    if (*(int *)(&DAT_1400292b4 + lVar6) != 0) {
      uVar5 = (ulonglong)DAT_140029a30;
      do {
        if ((*(int *)(&DAT_140029298 + uVar7 * 8 + lVar6) != 0) &&
           (bVar2 = (&DAT_140029294)[uVar7 * 8 + lVar6], (uint)bVar2 < (uint)uVar5)) {
          if (uVar5 <= bVar2) {
            pcVar3 = (code *)swi(3);
            (*pcVar3)();
            return;
          }
          piVar1 = (int *)(DAT_140029a28 + (ulonglong)bVar2 * 4);
          *piVar1 = *piVar1 + *(int *)(&DAT_140029298 + uVar7 * 8 + lVar6);
          uVar5 = (ulonglong)DAT_140029a30;
        }
        uVar4 = (int)uVar7 + 1;
        uVar7 = (ulonglong)uVar4;
      } while (uVar4 < *(uint *)(&DAT_1400292b4 + lVar6));
    }
  }
  return;
}


// ===== FUN_1400149b0 @ 1400149b0 size=116

void FUN_1400149b0(undefined8 param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  longlong lVar6;
  uint uVar7;
  longlong lVar8;
  int iStackX_c;
  
  lVar6 = DAT_140029ac8;
  uVar7 = 0;
  if (DAT_1400299ac != 0) {
    iStackX_c = (int)((ulonglong)param_1 >> 0x20);
    while ((*(int *)((ulonglong)uVar7 * 0x40 + DAT_140029ac8) != (int)param_1 ||
           (*(int *)((ulonglong)uVar7 * 0x40 + 4 + DAT_140029ac8) != iStackX_c))) {
      uVar7 = uVar7 + 1;
      if (DAT_1400299ac <= uVar7) {
        return;
      }
    }
    if (-1 < (int)uVar7) {
      lVar8 = (ulonglong)(DAT_1400299ac - 1) * 0x40;
      puVar1 = (undefined8 *)(lVar8 + DAT_140029ac8);
      uVar3 = puVar1[1];
      uVar4 = puVar1[2];
      uVar5 = puVar1[3];
      puVar2 = (undefined8 *)((ulonglong)uVar7 * 0x40 + DAT_140029ac8);
      *puVar2 = *puVar1;
      puVar2[1] = uVar3;
      puVar2[2] = uVar4;
      puVar2[3] = uVar5;
      puVar1 = (undefined8 *)(lVar8 + 0x20 + lVar6);
      uVar3 = puVar1[1];
      uVar4 = puVar1[2];
      uVar5 = puVar1[3];
      puVar2 = (undefined8 *)((ulonglong)uVar7 * 0x40 + 0x20 + lVar6);
      *puVar2 = *puVar1;
      puVar2[1] = uVar3;
      puVar2[2] = uVar4;
      puVar2[3] = uVar5;
      DAT_1400299ac = DAT_1400299ac - 1;
    }
  }
  return;
}


// ===== FUN_140014a30 @ 140014a30 size=88

void FUN_140014a30(uint param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  longlong lVar4;
  uint uVar5;
  
  if ((param_1 < DAT_1400eaa18) && (DAT_1400eaa18 = DAT_1400eaa18 - 1, param_1 < DAT_1400eaa18)) {
    do {
      lVar4 = DAT_1400eaa10;
      uVar5 = param_1 + 1;
      puVar1 = (undefined8 *)(DAT_1400eaa10 + (ulonglong)uVar5 * 0x18);
      uVar3 = puVar1[1];
      puVar2 = (undefined8 *)(DAT_1400eaa10 + (ulonglong)param_1 * 0x18);
      *puVar2 = *puVar1;
      puVar2[1] = uVar3;
      *(undefined8 *)(lVar4 + 0x10 + (ulonglong)param_1 * 0x18) =
           *(undefined8 *)(lVar4 + 0x10 + (ulonglong)uVar5 * 0x18);
      param_1 = uVar5;
    } while (uVar5 < DAT_1400eaa18);
  }
  return;
}


// ===== FUN_140014a90 @ 140014a90 size=246

void FUN_140014a90(undefined8 param_1)

{
  undefined8 *puVar1;
  code *pcVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  uint uVar6;
  uint uVar7;
  ulonglong uVar8;
  
  uVar4 = FUN_1400086a0(param_1);
  uVar6 = (uint)uVar4;
  uVar5 = uVar4 & 0xffffffff;
  if (-1 < (int)uVar6) {
    if (uVar6 < DAT_1400eaa00) {
      if (DAT_1400eaa00 <= uVar5) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      if (*(int *)(DAT_1400ea9f8 + uVar5 * 4) != 0) {
        if (DAT_14002a9d8 <= uVar5) {
          pcVar2 = (code *)swi(3);
          (*pcVar2)();
          return;
        }
        FUN_1400148e0((*(int *)(DAT_14002a9d0 + 8 + uVar5 * 0xc) != 0) + '\x14');
      }
    }
    uVar4 = uVar4 & 0xffffffff;
    DAT_14002a9d8 = DAT_14002a9d8 - 1;
    if (uVar6 < DAT_14002a9d8) {
      do {
        lVar3 = DAT_14002a9d0;
        uVar7 = (int)uVar4 + 1;
        uVar8 = (ulonglong)uVar7;
        puVar1 = (undefined8 *)(DAT_14002a9d0 + uVar4 * 0xc);
        *puVar1 = *(undefined8 *)(DAT_14002a9d0 + uVar8 * 0xc);
        *(undefined4 *)(puVar1 + 1) = *(undefined4 *)(lVar3 + 8 + uVar8 * 0xc);
        uVar4 = uVar8;
      } while (uVar7 < DAT_14002a9d8);
    }
    if ((uVar6 < DAT_1400eaa00) && (DAT_1400eaa00 = DAT_1400eaa00 - 1, uVar6 < DAT_1400eaa00)) {
      do {
        uVar6 = (int)uVar5 + 1;
        *(undefined4 *)(DAT_1400ea9f8 + uVar5 * 4) =
             *(undefined4 *)(DAT_1400ea9f8 + (ulonglong)uVar6 * 4);
        uVar5 = (ulonglong)uVar6;
      } while (uVar6 < DAT_1400eaa00);
    }
  }
  return;
}


// ===== FUN_140014b90 @ 140014b90 size=1074

void FUN_140014b90(undefined8 *param_1)

{
  ulonglong *puVar1;
  undefined4 uVar2;
  bool bVar3;
  code *pcVar4;
  uint uVar5;
  ulonglong uVar6;
  int *piVar7;
  uint uVar8;
  ulonglong uVar9;
  uint uVar10;
  longlong *plVar11;
  undefined1 *puVar12;
  int *piVar13;
  undefined1 *puVar14;
  longlong lVar15;
  longlong lVar16;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  
  if ((param_1 != (undefined8 *)0x0) && (param_1[1] != 0)) {
    uVar6 = 0;
    if (*(int *)param_1[0x25] != 0) {
      do {
        uVar9 = (ulonglong)*(byte *)((longlong)param_1 + uVar6 * 8 + 0x3c);
        lVar16 = uVar6 + 8;
        if (DAT_140029a30 <= uVar9) {
          pcVar4 = (code *)swi(3);
          (*pcVar4)();
          return;
        }
        uVar5 = (int)uVar6 + 1;
        uVar6 = (ulonglong)uVar5;
        piVar13 = (int *)(DAT_140029a28 + uVar9 * 4);
        *piVar13 = *piVar13 + *(int *)(param_1 + lVar16);
      } while (uVar5 < *(uint *)param_1[0x25]);
    }
    if ((ulonglong)DAT_140029a30 <= (ulonglong)*(byte *)((longlong)param_1 + 0x54)) {
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    piVar13 = (int *)(DAT_140029a28 + (ulonglong)*(byte *)((longlong)param_1 + 0x54) * 4);
    *piVar13 = *piVar13 + *(int *)(param_1 + 0xb);
    if ((ulonglong)DAT_14002a870 <= (ulonglong)*(uint *)((longlong)param_1 + 0x34)) {
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    lVar16 = 8;
    *(undefined8 *)(DAT_14002a868 + (ulonglong)*(uint *)((longlong)param_1 + 0x34) * 8) = 0;
    uVar2 = *(undefined4 *)((longlong)param_1 + 0x34);
    puVar14 = DAT_14002a850;
    if (DAT_14002a858 == DAT_14002a85c) {
      uVar6 = 8;
      if (8 < DAT_14002a85c * 2) {
        uVar6 = (ulonglong)(DAT_14002a85c * 2);
      }
      uVar5 = (uint)uVar6;
      if (DAT_14002a85c < uVar5) {
        plVar11 = &DAT_140029878;
        if (DAT_14002a848 != (longlong *)0x0) {
          plVar11 = DAT_14002a848;
        }
        lVar15 = (ulonglong)DAT_14002a85c * 4;
        puVar1 = (ulonglong *)(plVar11 + 2);
        if ((DAT_14002a850 == (undefined1 *)0x0) ||
           (DAT_14002a850 + lVar15 != (undefined1 *)(*plVar11 + *puVar1))) {
          bVar3 = DAT_14002a85c < uVar5;
          puVar14 = (undefined1 *)0x0;
          DAT_14002a85c = uVar5;
          if (bVar3) {
            uVar9 = *puVar1 + 3 & 0xfffffffffffffffc;
            puVar14 = (undefined1 *)(*plVar11 + uVar9);
            *puVar1 = uVar9;
            puVar12 = puVar14;
            if (DAT_14002a850 != (undefined1 *)0x0) {
              for (; lVar15 != 0; lVar15 = lVar15 + -1) {
                *puVar12 = *DAT_14002a850;
                DAT_14002a850 = DAT_14002a850 + 1;
                puVar12 = puVar12 + 1;
              }
            }
            *puVar1 = *puVar1 + uVar6 * 4;
          }
        }
        else {
          *puVar1 = *puVar1 + (ulonglong)(uVar5 - DAT_14002a85c) * 4;
          DAT_14002a85c = uVar5;
        }
      }
    }
    DAT_14002a850 = puVar14;
    *(undefined4 *)(DAT_14002a850 + (ulonglong)DAT_14002a858 * 4) = uVar2;
    DAT_14002a858 = DAT_14002a858 + 1;
    local_28 = *(int *)(param_1 + 4);
    local_24 = *(int *)((longlong)param_1 + 0x24);
    local_20 = local_28 + *(int *)((longlong)param_1 + 0x2c) + -1;
    local_1c = local_24 + -1 + *(int *)(param_1 + 6);
    FUN_14001ba90(&local_28,*(uint *)(param_1 + 5),0);
    uVar6 = 0;
    if (DAT_14002a888 != 0) {
      do {
        if (*(undefined8 **)(DAT_14002a880 + uVar6 * 8) == param_1) break;
        uVar5 = (int)uVar6 + 1;
        uVar6 = (ulonglong)uVar5;
      } while (uVar5 < DAT_14002a888);
    }
    if ((uint)uVar6 != DAT_14002a888) {
      DAT_14002a888 = DAT_14002a888 - 1;
      *(undefined8 *)(DAT_14002a880 + uVar6 * 8) =
           *(undefined8 *)(DAT_14002a880 + (ulonglong)DAT_14002a888 * 8);
    }
    param_1[1] = 0;
    piVar13 = (int *)(param_1 + 0x1b);
    do {
      if ((char)piVar13[2] != '\0') {
        uVar10 = *(int *)(param_1 + 4) + 1 + *piVar13;
        uVar8 = piVar13[1] + *(int *)((longlong)param_1 + 0x24);
        uVar5 = *(uint *)(param_1 + 5);
        if (((((uVar10 < (uint)DAT_140029a88) && (uVar8 < DAT_140029a88._4_4_)) &&
             (uVar5 < DAT_1400299a8)) && ((-1 < (int)uVar10 && (-1 < (int)uVar8)))) &&
           (-1 < (int)uVar5)) {
          uVar5 = *(uint *)(DAT_140029a98 +
                           (ulonglong)
                           ((uVar5 * DAT_140029a88._4_4_ + uVar8) * (uint)DAT_140029a88 + uVar10) *
                           4);
          if ((uVar5 == 0) || (DAT_14002a870 <= uVar5)) goto LAB_140014e1b;
          if ((ulonglong)DAT_14002a870 <= (ulonglong)uVar5) {
            pcVar4 = (code *)swi(3);
            (*pcVar4)();
            return;
          }
          piVar7 = *(int **)(DAT_14002a868 + (ulonglong)uVar5 * 8);
        }
        else {
LAB_140014e1b:
          piVar7 = (int *)0x0;
        }
        FUN_14001f1e0(piVar7);
        uVar10 = *(int *)(param_1 + 4) + -1 + *piVar13;
        uVar8 = *(int *)((longlong)param_1 + 0x24) + piVar13[1];
        uVar5 = *(uint *)(param_1 + 5);
        if ((((uVar10 < (uint)DAT_140029a88) && (uVar8 < DAT_140029a88._4_4_)) &&
            (uVar5 < DAT_1400299a8)) &&
           (((-1 < (int)uVar10 && (-1 < (int)uVar8)) && (-1 < (int)uVar5)))) {
          uVar5 = *(uint *)(DAT_140029a98 +
                           (ulonglong)
                           ((uVar5 * DAT_140029a88._4_4_ + uVar8) * (uint)DAT_140029a88 + uVar10) *
                           4);
          if ((uVar5 == 0) || (DAT_14002a870 <= uVar5)) goto LAB_140014e93;
          if ((ulonglong)DAT_14002a870 <= (ulonglong)uVar5) {
            pcVar4 = (code *)swi(3);
            (*pcVar4)();
            return;
          }
          piVar7 = *(int **)(DAT_14002a868 + (ulonglong)uVar5 * 8);
        }
        else {
LAB_140014e93:
          piVar7 = (int *)0x0;
        }
        FUN_14001f1e0(piVar7);
        uVar8 = *piVar13 + *(int *)(param_1 + 4);
        uVar10 = piVar13[1] + *(int *)((longlong)param_1 + 0x24) + 1;
        uVar5 = *(uint *)(param_1 + 5);
        if ((((uVar8 < (uint)DAT_140029a88) && (uVar10 < DAT_140029a88._4_4_)) &&
            (uVar5 < DAT_1400299a8)) &&
           (((-1 < (int)uVar8 && (-1 < (int)uVar10)) && (-1 < (int)uVar5)))) {
          uVar5 = *(uint *)(DAT_140029a98 +
                           (ulonglong)
                           ((uVar5 * DAT_140029a88._4_4_ + uVar10) * (uint)DAT_140029a88 + uVar8) *
                           4);
          if ((uVar5 == 0) || (DAT_14002a870 <= uVar5)) goto LAB_140014f0d;
          if ((ulonglong)DAT_14002a870 <= (ulonglong)uVar5) {
            pcVar4 = (code *)swi(3);
            (*pcVar4)();
            return;
          }
          piVar7 = *(int **)(DAT_14002a868 + (ulonglong)uVar5 * 8);
        }
        else {
LAB_140014f0d:
          piVar7 = (int *)0x0;
        }
        FUN_14001f1e0(piVar7);
        uVar8 = *piVar13 + *(int *)(param_1 + 4);
        uVar10 = piVar13[1] + *(int *)((longlong)param_1 + 0x24) + -1;
        uVar5 = *(uint *)(param_1 + 5);
        if (((((uVar8 < (uint)DAT_140029a88) && (uVar10 < DAT_140029a88._4_4_)) &&
             (uVar5 < DAT_1400299a8)) && ((-1 < (int)uVar8 && (-1 < (int)uVar10)))) &&
           (-1 < (int)uVar5)) {
          uVar5 = *(uint *)(DAT_140029a98 +
                           (ulonglong)
                           ((uVar5 * DAT_140029a88._4_4_ + uVar10) * (uint)DAT_140029a88 + uVar8) *
                           4);
          if ((uVar5 == 0) || (DAT_14002a870 <= uVar5)) goto LAB_140014f87;
          if ((ulonglong)DAT_14002a870 <= (ulonglong)uVar5) {
            pcVar4 = (code *)swi(3);
            (*pcVar4)();
            return;
          }
          piVar7 = *(int **)(DAT_14002a868 + (ulonglong)uVar5 * 8);
        }
        else {
LAB_140014f87:
          piVar7 = (int *)0x0;
        }
        FUN_14001f1e0(piVar7);
      }
      piVar13 = (int *)((longlong)piVar13 + 9);
      lVar16 = lVar16 + -1;
    } while (lVar16 != 0);
    *param_1 = DAT_14002a840;
    DAT_14002a840 = param_1;
  }
  return;
}


// ===== FUN_140014fd0 @ 140014fd0 size=194

void FUN_140014fd0(longlong param_1,uint param_2)

{
  undefined8 *puVar1;
  char cVar2;
  
  puVar1 = (undefined8 *)FUN_140009990(param_1,param_2);
  if (puVar1 != (undefined8 *)0x0) {
    if (((puVar1[1] != 0) && (*(uint *)((longlong)puVar1 + 0x34) < 0x10000)) &&
       (*(int *)(&DAT_1400aa9f0 + (ulonglong)*(uint *)((longlong)puVar1 + 0x34) * 4) != 0)) {
      switch(*(undefined4 *)puVar1) {
      case 1:
        cVar2 = '\n';
        break;
      case 2:
        cVar2 = '\v';
        break;
      case 3:
        cVar2 = '\f';
        break;
      case 4:
        cVar2 = '\r';
        break;
      case 5:
        cVar2 = '\x0e';
        break;
      case 6:
        cVar2 = '\x0f';
        break;
      case 7:
        cVar2 = '\x10';
        break;
      case 8:
        cVar2 = '\x11';
        break;
      case 9:
        cVar2 = '\x12';
        break;
      case 10:
        cVar2 = '\x13';
        break;
      default:
        cVar2 = '\0';
      }
      FUN_1400148e0(cVar2);
    }
    if ((puVar1[1] != 0) && (*(uint *)((longlong)puVar1 + 0x34) < 0x10000)) {
      *(undefined4 *)(&DAT_1400aa9f0 + (ulonglong)*(uint *)((longlong)puVar1 + 0x34) * 4) = 0;
    }
    FUN_140014b90(puVar1);
  }
  return;
}


// ===== FUN_1400150c0 @ 1400150c0 size=1526

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400150c0(void)

{
  code *pcVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  int iVar4;
  int iVar5;
  longlong lVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  uint uVar10;
  undefined1 *puVar11;
  int iVar12;
  int iVar13;
  longlong *plVar14;
  int iVar15;
  int iVar16;
  undefined1 extraout_var [56];
  float fVar17;
  float fVar18;
  tagPOINT tVar19;
  float fVar20;
  float fVar21;
  double dVar22;
  undefined1 auVar23 [64];
  tagPOINT local_res8;
  undefined *local_a8;
  undefined8 local_a0;
  int local_98;
  int local_94;
  undefined4 local_90;
  
  auVar23._0_8_ = FUN_1400066d0();
  auVar23._8_56_ = extraout_var;
  uVar9 = 0;
  auVar23 = ZEXT1664(auVar23._0_16_);
  puVar11 = DAT_1400296c8;
  for (lVar6 = (longlong)(DAT_1400296d4 * DAT_1400296d0) << 2; lVar6 != 0; lVar6 = lVar6 + -1) {
    *puVar11 = 0;
    puVar11 = puVar11 + 1;
  }
  DAT_140029990 = (undefined *)0x0;
  _DAT_140029998 = 0xffffffffffffffff;
  FUN_1400161b0(_DAT_140029630,DAT_140029020);
  FUN_1400156c0(DAT_140029020,DAT_140029980);
  FUN_140018dd0(_DAT_140029630,DAT_140029020,auVar23._0_8_);
  iVar15 = DAT_140029020;
  uVar7 = (ulonglong)DAT_14002a9d8;
  iVar16 = 0;
  if ((DAT_140029720 != '\0') && (uVar8 = uVar9, tVar19 = _DAT_140029630, DAT_14002a9d8 != 0)) {
    do {
      if (uVar7 <= uVar8) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      FUN_140016a50((ulonglong *)(DAT_14002a9d0 + uVar8 * 0xc),tVar19,iVar15);
      uVar7 = (ulonglong)DAT_14002a9d8;
      uVar10 = (int)uVar8 + 1;
      uVar8 = (ulonglong)uVar10;
    } while (uVar10 < DAT_14002a9d8);
  }
  iVar15 = DAT_140029020;
  uVar8 = (ulonglong)DAT_140029200;
  local_res8 = _DAT_140029630;
  tVar19 = local_res8;
  fVar17 = (0.5f);
  if (DAT_140029200 != 0) {
    local_res8.y = DAT_140029630._4_4_;
    local_res8.x = DAT_140029630;
    uVar7 = uVar9;
    fVar18 = (float)local_res8.y;
    fVar20 = (float)local_res8.x;
    local_res8 = tVar19;
    do {
      if (uVar8 <= uVar7) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      if (*(int *)(DAT_1400291f8 + 0x24 + uVar7 * 0x28) != 0) {
        uVar8 = *(ulonglong *)(DAT_1400291f8 + 1 + uVar7 * 0x28);
        iVar12 = iVar15 << 4;
        auVar2 = vroundps_avx(ZEXT416((uint)(((float)(uVar8 >> 0x20) * (float)iVar12 - fVar18) +
                                            fVar17)),1);
        auVar3 = vroundps_avx(ZEXT416((uint)(((float)(uVar8 & 0xffffffff) * (float)iVar12 - fVar20)
                                            + fVar17)),1);
        local_res8.x = 0x48d7d7d7;
        FUN_140008090((int)auVar3._0_4_,(int)auVar2._0_4_,iVar12,iVar12,0x48d7d7d7);
        uVar8 = (ulonglong)DAT_140029200;
      }
      uVar10 = (int)uVar7 + 1;
      uVar7 = (ulonglong)uVar10;
    } while (uVar10 < (uint)uVar8);
    uVar7 = (ulonglong)DAT_14002a9d8;
  }
  iVar15 = DAT_140029020;
  dVar22 = auVar23._0_8_;
  local_res8 = _DAT_140029630;
  tVar19 = local_res8;
  if ((int)uVar7 != 0) {
    local_res8.y = DAT_140029630._4_4_;
    local_res8.x = DAT_140029630;
    fVar21 = (float)(DAT_140029020 << 4);
    fVar18 = (float)local_res8.y;
    fVar20 = (float)local_res8.x;
    local_res8 = tVar19;
    do {
      if (uVar7 <= uVar9) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      iVar12 = 2;
      plVar14 = (longlong *)&DAT_1400eaba0;
      if (*(int *)(DAT_14002a9d0 + 8 + uVar9 * 0xc) == 0) {
        iVar12 = 1;
      }
      else {
        plVar14 = &DAT_1400eabc0;
      }
      iVar4 = (iVar12 * iVar15 * 0x10) / (int)plVar14[2];
      uVar7 = *(ulonglong *)(DAT_14002a9d0 + uVar9 * 0xc);
      auVar2 = vroundps_avx(ZEXT416((uint)(((float)(uVar7 >> 0x20) * fVar21 - fVar18) + fVar17)),1);
      auVar3 = vroundps_avx(ZEXT416((uint)(((float)(uVar7 & 0xffffffff) * fVar21 - fVar20) + fVar17)
                                   ),1);
      iVar12 = 1;
      if (1 < iVar4) {
        iVar12 = iVar4;
      }
      FUN_140004550(plVar14,(int)auVar3._0_4_,(int)auVar2._0_4_,iVar12,0);
      dVar22 = auVar23._0_8_;
      uVar7 = (ulonglong)DAT_14002a9d8;
      uVar10 = (int)uVar9 + 1;
      uVar9 = (ulonglong)uVar10;
    } while (uVar10 < DAT_14002a9d8);
  }
  FUN_140017ef0(tVar19,iVar15);
  FUN_140016830(_DAT_140029630,DAT_140029020,dVar22);
  FUN_140018be0(DAT_140029020);
  FUN_140007150();
  FUN_140016dd0();
  FUN_1400187b0();
  FUN_140006dd0();
  if (DAT_140029990 != (undefined *)0x0) {
    local_res8.x = 0;
    local_res8.y = 0;
    GetCursorPos(&local_res8);
    ScreenToClient(DAT_140029680,&local_res8);
    if (DAT_140029998 == -1) {
      _DAT_140029998 = CONCAT44((int)(float)local_res8.y + 0x10,(int)(float)local_res8.x + 0x10);
      iVar15 = (int)(float)local_res8.x + 0x10;
      iVar12 = (int)(float)local_res8.y + 0x10;
    }
    else {
      iVar15 = DAT_140029998;
      iVar12 = DAT_14002999c;
    }
    local_a8 = DAT_140029990;
    local_a0 = 0;
    local_90 = 1;
    local_94 = *(int *)(DAT_140029990 + 0xc);
    local_98 = *(int *)(DAT_140029990 + 8);
    iVar4 = (local_98 * 2 - DAT_1400296d0) + iVar15;
    if (iVar4 < 0) {
      iVar4 = iVar16;
    }
    iVar5 = (local_94 * 2 - DAT_1400296d4) + iVar12;
    if (iVar5 < 0) {
      iVar5 = iVar16;
    }
    iVar13 = iVar12 - iVar5;
    if (iVar12 - iVar5 < 0) {
      iVar13 = 0;
    }
    iVar12 = iVar15 - iVar4;
    if (iVar15 - iVar4 < 0) {
      iVar12 = 0;
    }
    FUN_140004550((longlong *)&local_a8,iVar12,iVar13,2,0);
  }
  if (DAT_1400298bc < 9) {
    lVar6 = (ulonglong)DAT_1400298bc * 0x10;
    local_a8 = &DAT_1400298c0 + lVar6;
    local_a0 = 0;
    local_90 = 1;
    local_94 = *(int *)(&DAT_1400298cc + lVar6);
    local_98 = *(int *)(&DAT_1400298c8 + lVar6);
    iVar15 = DAT_1400296d4 - local_94 * DAT_140029070;
    if (iVar15 < 0) {
      iVar15 = 0;
    }
    iVar12 = (DAT_1400296d0 - local_98 * DAT_140029070) / 2;
    if (iVar12 < 0) {
      iVar12 = iVar16;
    }
    FUN_140004550((longlong *)&local_a8,iVar12,iVar15,DAT_140029070,0);
  }
  if ((DAT_14002998c != 0) && (DAT_140029970 == 0)) {
    local_a0 = 0;
    local_98 = DAT_140029968;
    local_94 = DAT_14002996c;
    iVar15 = DAT_1400296d4 - DAT_14002996c * DAT_140029070;
    local_90 = 1;
    local_a8 = &DAT_140029960;
    if (iVar15 < 0) {
      iVar15 = 0;
    }
    iVar12 = (DAT_1400296d0 - DAT_140029968 * DAT_140029070) / 2;
    if (iVar12 < 0) {
      iVar12 = iVar16;
    }
    FUN_140004550((longlong *)&local_a8,iVar12,iVar15,DAT_140029070,0);
  }
  if (DAT_140029743 != '\0') {
    local_a0 = 0;
    local_98 = DAT_140029958;
    local_90 = 1;
    local_a8 = &DAT_140029950;
    iVar15 = (DAT_1400296d0 - DAT_140029958 * DAT_140029070) / 2;
    local_94 = DAT_14002995c;
    if (iVar15 < 0) {
      iVar15 = iVar16;
    }
    FUN_140004550((longlong *)&local_a8,iVar15,0,DAT_140029070,0);
  }
  DAT_140029620 = dVar22;
  return;
}


// ===== FUN_1400156c0 @ 1400156c0 size=2791

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400156c0(int param_1,int param_2)

{
  longlong *plVar1;
  byte bVar2;
  int *piVar3;
  undefined *puVar4;
  uint *puVar5;
  code *pcVar6;
  float fVar7;
  undefined1 auVar8 [16];
  longlong lVar9;
  int iVar10;
  longlong *plVar11;
  longlong lVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  ulonglong uVar16;
  longlong lVar17;
  int iVar18;
  byte *pbVar19;
  longlong *plVar20;
  undefined1 auVar21 [16];
  undefined1 auVar22 [16];
  float fVar23;
  undefined1 auVar24 [16];
  undefined1 auVar25 [16];
  float fVar26;
  undefined1 auVar27 [64];
  undefined1 auVar28 [64];
  float fVar29;
  
  plVar1 = DAT_14002a880 + (_DAT_14002a888 & 0xffffffff);
  plVar20 = DAT_14002a880;
  if (DAT_14002a880 != plVar1) {
    do {
      piVar3 = (int *)*plVar20;
      if (((piVar3 != (int *)0x0) &&
          (puVar4 = *(undefined **)(piVar3 + 4), puVar4 != (undefined *)0x0)) && (piVar3[10] == 0))
      {
        auVar25 = vroundps_avx(ZEXT416(DAT_140029634),1);
        auVar24 = vroundps_avx(ZEXT416(DAT_140029630),1);
        iVar10 = (int)((ulonglong)*(undefined8 *)(piVar3 + 8) >> 0x20) * DAT_140029020 * 0x10 -
                 (int)auVar25._0_4_;
        iVar13 = (int)*(undefined8 *)(piVar3 + 8) * DAT_140029020 * 0x10 - (int)auVar24._0_4_;
        if (*piVar3 == 3) {
          uVar14 = (DAT_14002a39c >> 3) % DAT_1400eacb8;
          if (puVar4 == &DAT_1400eb220) {
            iVar18 = param_1 * 0x10;
            FUN_140004550((longlong *)&DAT_1400eaca0,iVar13,iVar10 + iVar18,param_1,uVar14);
            iVar13 = iVar18 + iVar13;
            iVar10 = iVar10 + iVar18;
            plVar11 = (longlong *)&DAT_1400eadc0;
          }
          else {
            if (puVar4 == &DAT_1400eb2a0) {
              FUN_140004550((longlong *)&DAT_1400ead00,iVar13,iVar10,param_1,uVar14);
              FUN_140004550((longlong *)&DAT_1400ead60,iVar13,param_1 * 0x10 + iVar10,param_1,uVar14
                           );
              goto LAB_140015836;
            }
            if (puVar4 == &DAT_1400eb2e0) {
              FUN_140004550((longlong *)&DAT_1400ead00,iVar13 + param_1 * 0x10,iVar10,param_1,uVar14
                           );
              iVar10 = iVar10 + param_1 * 0x10;
              iVar13 = iVar13 + param_1 * 0x10;
              plVar11 = (longlong *)&DAT_1400ead60;
            }
            else {
              if (puVar4 != &DAT_1400eb260) goto LAB_140015836;
              FUN_140004550((longlong *)&DAT_1400eadc0,param_1 * 0x10 + iVar13,iVar10,param_1,uVar14
                           );
              plVar11 = (longlong *)&DAT_1400eaca0;
            }
          }
          FUN_140004550(plVar11,iVar13,iVar10,param_1,uVar14);
        }
        else if (*piVar3 == 2) {
          uVar14 = (DAT_14002a39c >> 3) % DAT_1400eacb8;
          bVar2 = *(byte *)(piVar3 + 0x38);
          if ((bVar2 & 2) == 0) {
            if ((bVar2 & 4) == 0) {
              if ((bVar2 & 1) == 0) {
                if ((bVar2 & 8) != 0) {
                  FUN_140004550((longlong *)&DAT_1400ead60,iVar13,iVar10,param_1,uVar14);
                }
              }
              else {
                FUN_140004550((longlong *)&DAT_1400eadc0,iVar13,iVar10,param_1,uVar14);
              }
            }
            else {
              FUN_140004550((longlong *)&DAT_1400ead00,iVar13,iVar10,param_1,uVar14);
            }
          }
          else {
            FUN_140004550((longlong *)&DAT_1400eaca0,iVar13,iVar10,param_1,uVar14);
          }
        }
LAB_140015836:
        iVar10 = 0;
        iVar13 = 0;
        plVar11 = *(longlong **)(piVar3 + 6);
        if (plVar11 == (longlong *)0x0) {
LAB_140015850:
          plVar11 = *(longlong **)(piVar3 + 4);
          if (plVar11 != (longlong *)0x0) goto LAB_14001585d;
        }
        else {
          puVar5 = *(uint **)(piVar3 + 0x4a);
          if (puVar5 == (uint *)0x0) {
            pcVar6 = (code *)swi(3);
            (*pcVar6)();
            return;
          }
          uVar14 = *puVar5;
          if (uVar14 == 0) {
            if ((piVar3[0x10] == 0) && (piVar3[0x12] == 0)) goto LAB_140015850;
          }
          else {
            uVar16 = 0;
            if (uVar14 != 0) {
              do {
                if ((uint)piVar3[uVar16 * 2 + 0x10] < puVar5[uVar16 * 2 + 2]) goto LAB_140015850;
                uVar15 = (int)uVar16 + 1;
                uVar16 = (ulonglong)uVar15;
              } while (uVar15 < uVar14);
            }
          }
LAB_14001585d:
          auVar25 = vroundps_avx(ZEXT416(DAT_140029634),1);
          auVar24 = vroundps_avx(ZEXT416(DAT_140029630),1);
          iVar13 = ((piVar3[0xc] * 0x10 - *(int *)((longlong)plVar11 + 0x14)) * param_1 +
                   (int)((ulonglong)*(undefined8 *)(piVar3 + 8) >> 0x20) * DAT_140029020 * 0x10) -
                   (int)auVar25._0_4_;
          iVar10 = (((piVar3[0xb] * 0x10 - (int)plVar11[2]) * param_1) / 2 +
                   (int)*(undefined8 *)(piVar3 + 8) * DAT_140029020 * 0x10) - (int)auVar24._0_4_;
        }
        FUN_140004550(plVar11,iVar10,iVar13,param_1,piVar3[0xe]);
      }
      plVar20 = plVar20 + 1;
    } while (plVar20 != plVar1);
  }
  lVar17 = 0;
  auVar28 = ZEXT464((1f));
  auVar27 = ZEXT1664(ZEXT816(0) << 0x40);
  plVar1 = DAT_14002a880 + (_DAT_14002a888 & 0xffffffff);
  fVar26 = (0.5f);
  fVar29 = (16f);
  for (plVar20 = DAT_14002a880; plVar20 != plVar1; plVar20 = plVar20 + 1) {
    piVar3 = (int *)*plVar20;
    if (((piVar3 != (int *)0x0) && (piVar3[10] == 0)) && (*piVar3 == 1)) {
      if (piVar3[0x10] == 0) {
        if (piVar3[0x16] == 0) goto LAB_140015d40;
        uVar14 = piVar3[0x16];
        pbVar19 = (byte *)(piVar3 + 0x15);
      }
      else {
        uVar14 = piVar3[0x16];
        if (uVar14 == 0) {
          pbVar19 = (byte *)(piVar3 + 0xf);
        }
        else {
          pbVar19 = (byte *)(piVar3 + 0x15);
        }
      }
      auVar25 = auVar27._0_16_;
      if (*(longlong *)(piVar3 + 0x4a) == 0) {
        fVar23 = auVar27._0_4_;
        auVar24 = auVar25;
      }
      else {
        fVar23 = *(float *)(*(longlong *)(piVar3 + 0x4a) + 0x24);
        auVar24 = ZEXT416((uint)piVar3[0x4c]);
      }
      auVar21._0_4_ = auVar24._0_4_ / fVar23;
      auVar21._4_12_ = auVar24._4_12_;
      auVar24 = vmaxss_avx(auVar25,auVar21);
      bVar2 = *(byte *)(piVar3 + 0x38);
      auVar24 = vminss_avx(auVar28._0_16_,auVar24);
      auVar21 = vpcmpgtq_avx(ZEXT416(uVar14),ZEXT416(0));
      auVar25 = vblendvps_avx(auVar24,auVar25,auVar21);
      if ((bVar2 & 2) == 0) {
        if ((bVar2 & 1) == 0) {
          if ((bVar2 & 8) == 0) {
            lVar12 = -8;
            if ((bVar2 & 4) != 0) {
              lVar12 = lVar17;
            }
          }
          else {
            lVar12 = 8;
          }
        }
        else {
          lVar12 = 0x10;
        }
      }
      else {
        lVar12 = 0x18;
      }
      if ((bVar2 & 0x20) == 0) {
        if ((bVar2 & 0x10) == 0) {
          if ((char)bVar2 < '\0') {
            lVar9 = 8;
          }
          else {
            lVar9 = -8;
            if ((bVar2 & 0x40) != 0) {
              lVar9 = lVar17;
            }
          }
        }
        else {
          lVar9 = 0x10;
        }
      }
      else {
        lVar9 = 0x18;
      }
      fVar23 = fVar26 * *(float *)((longlong)&DAT_14002951c + lVar9) + fVar26;
      fVar7 = fVar26 * *(float *)((longlong)&DAT_140029518 + lVar9) + fVar26;
      auVar24 = vroundps_avx(ZEXT416(DAT_140029634),1);
      auVar21 = vroundps_avx(ZEXT416(DAT_140029630),1);
      FUN_140004550((longlong *)(&DAT_1400299b0)[*pbVar19],
                    ((int)*(undefined8 *)(piVar3 + 8) * DAT_140029020 * 0x10 - (int)auVar21._0_4_) +
                    (int)((float)param_1 *
                          (((fVar26 * *(float *)((longlong)&DAT_140029518 + lVar12) + fVar26) -
                           fVar7) * auVar25._0_4_ + fVar7) * fVar29 - (float)(param_1 * 8)),
                    ((int)((ulonglong)*(undefined8 *)(piVar3 + 8) >> 0x20) * DAT_140029020 * 0x10 -
                    (int)auVar24._0_4_) +
                    (int)((float)param_1 *
                          (((fVar26 * *(float *)((longlong)&DAT_14002951c + lVar12) + fVar26) -
                           fVar23) * auVar25._0_4_ + fVar23) * fVar29 - (float)(param_1 * 8)),
                    param_1,0);
    }
LAB_140015d40:
  }
  if (param_2 != 0) {
    plVar1 = DAT_14002a880 + (_DAT_14002a888 & 0xffffffff);
    for (plVar20 = DAT_14002a880; plVar20 != plVar1; plVar20 = plVar20 + 1) {
      lVar12 = *plVar20;
      if ((lVar12 != 0) && (*(int *)(lVar12 + 0x28) == param_2)) {
        plVar11 = *(longlong **)(lVar12 + 0x10);
        lVar9 = lVar17;
        if (plVar11 != (longlong *)0x0) {
          auVar25 = vroundps_avx(ZEXT416(DAT_140029634),1);
          auVar24 = vroundps_avx(ZEXT416(DAT_140029630),1);
          lVar9 = CONCAT44(((*(int *)(lVar12 + 0x30) * 0x10 - *(int *)((longlong)plVar11 + 0x14)) *
                            param_1 +
                           (int)((ulonglong)*(undefined8 *)(lVar12 + 0x20) >> 0x20) * DAT_140029020
                           * 0x10) - (int)auVar25._0_4_,
                           (((*(int *)(lVar12 + 0x2c) * 0x10 - (int)plVar11[2]) * param_1) / 2 +
                           (int)*(undefined8 *)(lVar12 + 0x20) * DAT_140029020 * 0x10) -
                           (int)auVar24._0_4_);
        }
        FUN_1400046a0(plVar11,(int)lVar9,(int)((ulonglong)lVar9 >> 0x20),param_1,
                      *(int *)(lVar12 + 0x38));
      }
    }
    plVar1 = DAT_14002a880 + (_DAT_14002a888 & 0xffffffff);
    for (plVar20 = DAT_14002a880; plVar20 != plVar1; plVar20 = plVar20 + 1) {
      piVar3 = (int *)*plVar20;
      if (((piVar3 != (int *)0x0) && (piVar3[10] == param_2)) && (*piVar3 == 1)) {
        if (piVar3[0x10] == 0) {
          if (piVar3[0x16] == 0) goto LAB_14001603f;
          uVar14 = piVar3[0x16];
          pbVar19 = (byte *)(piVar3 + 0x15);
        }
        else {
          uVar14 = piVar3[0x16];
          if (uVar14 == 0) {
            pbVar19 = (byte *)(piVar3 + 0xf);
          }
          else {
            pbVar19 = (byte *)(piVar3 + 0x15);
          }
        }
        auVar25 = auVar27._0_16_;
        if (*(longlong *)(piVar3 + 0x4a) == 0) {
          fVar23 = auVar27._0_4_;
          auVar24 = auVar25;
        }
        else {
          fVar23 = *(float *)(*(longlong *)(piVar3 + 0x4a) + 0x24);
          auVar24 = ZEXT416((uint)piVar3[0x4c]);
        }
        auVar22._0_4_ = auVar24._0_4_ / fVar23;
        auVar22._4_12_ = auVar24._4_12_;
        auVar24 = vmaxss_avx(auVar25,auVar22);
        bVar2 = *(byte *)(piVar3 + 0x38);
        auVar24 = vminss_avx(auVar28._0_16_,auVar24);
        auVar21 = vpcmpgtq_avx(ZEXT416(uVar14),ZEXT416(0));
        auVar25 = vblendvps_avx(auVar24,auVar25,auVar21);
        if ((bVar2 & 2) == 0) {
          if ((bVar2 & 1) == 0) {
            if ((bVar2 & 8) == 0) {
              lVar12 = -8;
              if ((bVar2 & 4) != 0) {
                lVar12 = lVar17;
              }
            }
            else {
              lVar12 = 8;
            }
          }
          else {
            lVar12 = 0x10;
          }
        }
        else {
          lVar12 = 0x18;
        }
        if ((bVar2 & 0x20) == 0) {
          if ((bVar2 & 0x10) == 0) {
            if ((char)bVar2 < '\0') {
              lVar9 = 8;
            }
            else {
              lVar9 = -8;
              if ((bVar2 & 0x40) != 0) {
                lVar9 = lVar17;
              }
            }
          }
          else {
            lVar9 = 0x10;
          }
        }
        else {
          lVar9 = 0x18;
        }
        fVar23 = fVar26 * *(float *)((longlong)&DAT_14002951c + lVar9) + fVar26;
        fVar7 = fVar26 * *(float *)((longlong)&DAT_140029518 + lVar9) + fVar26;
        auVar24 = vroundps_avx(ZEXT416(DAT_140029634),1);
        auVar21 = vroundps_avx(ZEXT416(DAT_140029630),1);
        FUN_1400046a0((longlong *)(&DAT_1400299b0)[*pbVar19],
                      ((int)*(undefined8 *)(piVar3 + 8) * DAT_140029020 * 0x10 - (int)auVar21._0_4_)
                      + (int)((float)param_1 *
                              (((fVar26 * *(float *)((longlong)&DAT_140029518 + lVar12) + fVar26) -
                               fVar7) * auVar25._0_4_ + fVar7) * fVar29 - (float)(param_1 * 8)),
                      ((int)((ulonglong)*(undefined8 *)(piVar3 + 8) >> 0x20) * DAT_140029020 * 0x10
                      - (int)auVar24._0_4_) +
                      (int)((float)param_1 *
                            (((fVar26 * *(float *)((longlong)&DAT_14002951c + lVar12) + fVar26) -
                             fVar23) * auVar25._0_4_ + fVar23) * fVar29 - (float)(param_1 * 8)),
                      param_1,0);
      }
LAB_14001603f:
    }
  }
  auVar24 = vroundps_avx(ZEXT416(DAT_140029630),1);
  auVar25 = vroundps_avx(ZEXT416(DAT_140029634),1);
  auVar8._8_8_ = 0;
  auVar8._0_8_ = SUB648(ZEXT6064((undefined1  [60])0x0),4);
  iVar10 = ((DAT_140029a88._4_4_ >> 1) - 1) * DAT_140029020 * 0x10 - (int)auVar25._0_4_;
  auVar25._0_4_ = (float)DAT_1400eb710;
  auVar25._4_12_ = SUB1612(auVar8 << 0x40,4);
  auVar25 = vminss_avx(ZEXT416(DAT_140029988),auVar25);
  iVar13 = -(int)auVar24._0_4_;
  FUN_140004550((longlong *)&DAT_1400eb700,iVar13 - (int)(auVar25._0_4_ * (float)param_1),iVar10,
                param_1,0);
  if (DAT_14002998c != 0) {
    FUN_140004bc0(iVar13 - DAT_1400eb710 * param_1,iVar10,DAT_1400eb710 * param_1,
                  DAT_1400eb714 * param_1,0,0,0xff000000);
    return;
  }
  FUN_140006d00(DAT_140029984,iVar13,iVar10 + param_1 * 0x18,param_1 << 4);
  return;
}


// ===== FUN_1400161b0 @ 1400161b0 size=1244

void FUN_1400161b0(undefined8 param_1,int param_2)

{
  byte bVar1;
  float fVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  ulonglong uVar5;
  ushort uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  ulonglong uVar10;
  int iVar11;
  uint uVar12;
  longlong *plVar13;
  ulonglong uVar14;
  uint uVar15;
  ulonglong uVar16;
  ulonglong uVar17;
  int iVar18;
  int iVar19;
  longlong lVar20;
  int iVar21;
  ulonglong uVar22;
  longlong *plVar23;
  uint uVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  int iVar28;
  bool bVar29;
  bool bVar30;
  bool bVar31;
  float fVar32;
  float local_res18;
  float fStackX_1c;
  
  uVar16 = 0;
  iVar19 = param_2 * 0x10;
  local_res18 = (float)param_1;
  auVar3 = vroundps_avx(ZEXT416((uint)local_res18),1);
  fStackX_1c = (float)((ulonglong)param_1 >> 0x20);
  iVar27 = (int)auVar3._0_4_;
  auVar3 = vroundps_avx(ZEXT416((uint)fStackX_1c),1);
  iVar25 = (int)auVar3._0_4_;
  auVar3 = vroundps_avx(ZEXT416((uint)((float)DAT_1400296d0 + local_res18)),2);
  uVar17 = (longlong)(iVar19 + -1 + (int)auVar3._0_4_) / (longlong)iVar19;
  auVar3 = vroundps_avx(ZEXT416((uint)((float)DAT_1400296d4 + fStackX_1c)),2);
  uVar7 = (iVar19 + -1 + (int)auVar3._0_4_) / iVar19;
  if (0 < (int)((longlong)iVar25 / (longlong)iVar19)) {
    uVar16 = (longlong)iVar25 / (longlong)iVar19 & 0xffffffff;
  }
  uVar15 = DAT_140029a88._4_4_;
  if ((int)uVar7 < (int)DAT_140029a88._4_4_) {
    uVar15 = uVar7;
  }
  iVar11 = (int)uVar16;
  uVar24 = DAT_140029a88._4_4_;
  if (iVar11 < (int)uVar15) {
    uVar10 = CONCAT44(DAT_140029a88._4_4_,(uint)DAT_140029a88);
    iVar28 = iVar11 + -1;
    uVar22 = 0;
    if (0 < (int)((longlong)iVar27 / (longlong)iVar19)) {
      uVar22 = (longlong)iVar27 / (longlong)iVar19 & 0xffffffff;
    }
    uVar14 = uVar10;
    if ((int)uVar17 < (int)(uint)DAT_140029a88) {
      uVar14 = uVar17;
    }
    uVar14 = uVar14 & 0xffffffff;
    iVar11 = iVar11 * iVar19 - iVar25;
    do {
      iVar9 = (int)uVar22;
      uVar15 = (uint)uVar16;
      if (iVar9 < (int)uVar14) {
        iVar26 = iVar9 * iVar19 - iVar27;
        uVar16 = uVar22;
        do {
          iVar18 = iVar9 + 1;
          uVar8 = (uint)uVar10;
          iVar21 = uVar15 * uVar8;
          uVar12 = (uint)uVar16;
          bVar1 = *(byte *)((ulonglong)(iVar21 + uVar12) + DAT_140029a90);
          uVar16 = (ulonglong)bVar1;
          uVar10 = (ulonglong)(iVar21 + uVar12);
          if (bVar1 == 8) {
            if (((((int)uVar12 < 0) || (iVar28 < 0)) || ((int)uVar8 <= (int)uVar12)) ||
               ((int)uVar24 <= iVar28)) {
              bVar29 = false;
            }
            else {
              bVar29 = *(char *)((ulonglong)(iVar28 * uVar8 + uVar12) + DAT_140029a90) == '\b';
            }
            if (((iVar9 + -1 < 0) || (iVar28 < -1)) ||
               (((int)uVar8 <= iVar9 + -1 || ((int)uVar24 <= (int)uVar15)))) {
              bVar30 = false;
            }
            else {
              bVar30 = *(char *)((ulonglong)(uint)(iVar21 + -2 + iVar18) + DAT_140029a90) == '\b';
            }
            if (((iVar18 < 0) || (iVar28 < -1)) ||
               (((int)uVar8 <= iVar18 || ((int)uVar24 <= (int)uVar15)))) {
              bVar31 = false;
            }
            else {
              bVar31 = *(char *)((ulonglong)(uint)(iVar18 + iVar21) + DAT_140029a90) == '\b';
            }
            if (bVar29) {
              if (bVar30) {
                plVar13 = (longlong *)&DAT_1400eb520;
                plVar23 = (longlong *)&DAT_1400eb4c0;
                goto LAB_1400163fb;
              }
              plVar13 = (longlong *)&DAT_1400eb4c0;
              if (bVar31) {
                plVar13 = (longlong *)&DAT_1400eb500;
              }
            }
            else if (bVar30) {
              plVar13 = (longlong *)&DAT_1400eb560;
              plVar23 = (longlong *)&DAT_1400eb4e0;
LAB_1400163fb:
              if (bVar31) {
                plVar13 = plVar23;
              }
            }
            else {
              plVar13 = (longlong *)&DAT_1400eb4e0;
              if (bVar31) {
                plVar13 = (longlong *)&DAT_1400eb540;
              }
            }
          }
          else {
            plVar13 = *(longlong **)(&DAT_140029a40 + uVar16 * 8);
          }
          if ((uVar8 <= uVar12) || (uVar24 <= uVar15)) {
            uVar16 = 0;
          }
          iVar9 = (int)uVar16;
          if (iVar9 == 2) {
            uVar6 = *(ushort *)(&DAT_14004a9f0 + uVar10 * 2);
LAB_140016465:
            if (uVar6 < 0x14) goto LAB_14001646b;
            if (uVar6 < 0x5a) {
              iVar9 = 1;
            }
            else {
              iVar9 = 3 - (uint)(uVar6 < 200);
            }
          }
          else {
            if (iVar9 == 3) {
              uVar6 = *(ushort *)(&DAT_14006a9f0 + uVar10 * 2);
              goto LAB_140016465;
            }
            if (iVar9 == 4) {
              uVar6 = *(ushort *)(&DAT_14008a9f0 + uVar10 * 2);
              goto LAB_140016465;
            }
LAB_14001646b:
            iVar9 = 0;
          }
          FUN_140004410(plVar13,iVar26,iVar11,param_2,iVar9);
          uVar10 = CONCAT44(DAT_140029a88._4_4_,(uint)DAT_140029a88);
          uVar16 = (ulonglong)(uVar12 + 1);
          iVar26 = iVar26 + iVar19;
          uVar5 = (ulonglong)(uint)DAT_140029a88;
          if ((int)uVar17 < (int)(uint)DAT_140029a88) {
            uVar5 = uVar17;
          }
          uVar14 = uVar5 & 0xffffffff;
          uVar24 = DAT_140029a88._4_4_;
          iVar9 = iVar18;
        } while ((int)(uVar12 + 1) < (int)uVar5);
      }
      iVar11 = iVar11 + iVar19;
      uVar16 = (ulonglong)(uVar15 + 1);
      iVar28 = iVar28 + 1;
      uVar12 = uVar24;
      if ((int)uVar7 < (int)uVar24) {
        uVar12 = uVar7;
      }
    } while ((int)(uVar15 + 1) < (int)uVar12);
  }
  uVar17 = 0;
  fVar2 = (float)param_2 * (16f);
  lVar20 = DAT_140029ac8;
  uVar7 = DAT_1400299ac;
  if (DAT_1400299ac != 0) {
    do {
      uVar16 = 0;
      if (*(int *)(uVar17 * 0x40 + 0xc + lVar20) != 0) {
        fVar32 = (float)(int)fVar2;
        do {
          auVar3 = *(undefined1 (*) [16])(lVar20 + (uVar16 + 1 + uVar17 * 4) * 0x10);
          auVar4 = vshufps_avx(auVar3,auVar3,0x55);
          FUN_140004550((longlong *)(&DAT_1400299b0)[auVar3[0]],
                        (int)(fVar32 * auVar3._0_4_) - iVar27,(int)(fVar32 * auVar4._0_4_) - iVar25,
                        param_2,0);
          uVar15 = (int)uVar16 + 1;
          uVar16 = (ulonglong)uVar15;
          lVar20 = DAT_140029ac8;
          uVar7 = DAT_1400299ac;
        } while (uVar15 < *(uint *)(uVar17 * 0x40 + 0xc + DAT_140029ac8));
      }
      uVar15 = (int)uVar17 + 1;
      uVar17 = (ulonglong)uVar15;
      uVar24 = DAT_140029a88._4_4_;
    } while (uVar15 < uVar7);
  }
  iVar27 = -iVar27;
  lVar20 = 6;
  do {
    iVar27 = iVar19 + iVar27;
    FUN_140004550((longlong *)&DAT_1400eb6e0,iVar27,(uVar24 >> 1) * iVar19 - iVar25,param_2,0);
    lVar20 = lVar20 + -1;
    uVar24 = DAT_140029a88._4_4_;
  } while (lVar20 != 0);
  return;
}


// ===== FUN_140016690 @ 140016690 size=406

void FUN_140016690(ulonglong *param_1,undefined8 param_2,int param_3)

{
  undefined1 auVar1 [16];
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 auVar6 [16];
  float fVar7;
  float local_38;
  float fStack_34;
  
  if ((*(char *)((longlong)param_1 + 0x34) == '\x02') && ((int)param_1[0xb] != 0)) {
    if (0.0 < *(float *)((longlong)param_1 + 0x4c)) {
      auVar1 = vmaxss_avx(ZEXT816(0) << 0x40,
                          ZEXT416((uint)(*(float *)((longlong)param_1 + 0x24) /
                                        *(float *)((longlong)param_1 + 0x4c))));
      auVar6._8_8_ = 0;
      auVar6._0_8_ = *param_1;
      iVar2 = (int)(param_3 * 0x12 + (param_3 * 0x12 >> 0x1f & 3U)) >> 2;
      auVar1 = vminss_avx(ZEXT416((1f)),auVar1);
      fVar7 = auVar1._0_4_;
      iVar4 = 0xc;
      if (0xc < iVar2) {
        iVar4 = iVar2;
      }
      auVar1 = vshufps_avx(auVar6,auVar6,0x55);
      iVar2 = 3;
      if (3 < param_3) {
        iVar2 = param_3;
      }
      local_38 = (float)param_2;
      fStack_34 = (float)((ulonglong)param_2 >> 0x20);
      auVar6 = vroundps_avx(ZEXT416((uint)(((float)*param_1 * (float)(param_3 << 4) - local_38) +
                                          (0.5f))),1);
      iVar5 = (int)auVar6._0_4_ - iVar4 / 2;
      iVar3 = 10;
      if (10 < param_3 * 3) {
        iVar3 = param_3 * 3;
      }
      auVar1 = vroundps_avx(ZEXT416((uint)((auVar1._0_4_ * (float)(param_3 << 4) - fStack_34) +
                                          (0.5f))),1);
      iVar3 = (int)auVar1._0_4_ - iVar3;
      FUN_140007ff0(iVar5 + -1,iVar3 + -1,iVar4 + 2,iVar2 + 2,0xff000000);
      FUN_140007ff0(iVar5,iVar3,iVar4,iVar2,0xff3c3c3c);
      auVar1 = vroundps_avx(ZEXT416((uint)((float)iVar4 * fVar7 + (0.5f))),1);
      FUN_140007ff0(iVar5,iVar3,(int)auVar1._0_4_,iVar2,0xff50dc28);
    }
  }
  return;
}


// ===== FUN_140016830 @ 140016830 size=529

void FUN_140016830(undefined8 param_1,int param_2,double param_3)

{
  code *pcVar1;
  double dVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined8 uVar5;
  longlong *plVar6;
  uint uVar7;
  ulonglong uVar8;
  uint uVar9;
  float *pfVar10;
  undefined1 auVar11 [16];
  float fVar12;
  double dVar13;
  undefined8 uVar14;
  
  uVar8 = 0;
  uVar9 = DAT_1400291e8;
  fVar12 = (0.5f);
  dVar13 = (6.0);
  uVar14 = param_1;
  if (DAT_1400291e8 != 0) {
    do {
      if (uVar9 <= uVar8) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      pfVar10 = (float *)(uVar8 * 0x2080 + DAT_1400291e0);
      uVar5 = FUN_14000d8e0((ulonglong *)pfVar10);
      if ((int)uVar5 == 0) {
        if (*(char *)(pfVar10 + 0xd) == '\x02') {
          plVar6 = (longlong *)&DAT_1400eac60;
        }
        else {
          plVar6 = (longlong *)&DAT_1400eac80;
          if (pfVar10[0x18] == 0.0) {
            plVar6 = (longlong *)&DAT_1400eac40;
          }
        }
        dVar2 = (double)pfVar10[0xc] + param_3 * dVar13;
        auVar11._8_8_ = 0;
        auVar11._0_8_ = dVar2;
        auVar3 = vroundps_avx(ZEXT416((uint)((((float)(param_2 << 4) * *pfVar10 - (float)uVar14) -
                                             (float)(uint)(param_2 * (int)plVar6[2]) * fVar12) +
                                            fVar12)),1);
        auVar11 = vroundpd_avx(auVar11,3);
        auVar4 = vroundps_avx(ZEXT416((uint)((((float)(param_2 << 4) * pfVar10[1] -
                                              (float)((ulonglong)uVar14 >> 0x20)) -
                                             (float)(uint)(param_2 *
                                                          *(int *)((longlong)plVar6 + 0x14)) *
                                             fVar12) + fVar12)),1);
        FUN_140004550(plVar6,(int)auVar3._0_4_,(int)auVar4._0_4_,param_2,
                      (int)(((longlong)
                             ((float)(dVar2 - auVar11._0_8_) * (float)*(uint *)(plVar6 + 3)) &
                            0xffffffffU) % (ulonglong)*(uint *)(plVar6 + 3)));
        FUN_140016690((ulonglong *)pfVar10,param_1,param_2);
        uVar9 = DAT_1400291e8;
      }
      uVar7 = (int)uVar8 + 1;
      uVar8 = (ulonglong)uVar7;
    } while (uVar7 < uVar9);
  }
  return;
}


// ===== FUN_140016a50 @ 140016a50 size=892

void FUN_140016a50(ulonglong *param_1,undefined8 param_2,int param_3)

{
  float fVar1;
  undefined1 auVar2 [16];
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  ulonglong uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  undefined1 auVar13 [16];
  float fVar14;
  float fVar15;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  undefined1 auVar23 [64];
  float local_res8;
  float fStackX_c;
  undefined1 auVar16 [64];
  undefined1 auVar22 [64];
  
  uVar11 = (uint)param_1[1];
  iVar12 = param_3 << 4;
  local_res8 = (float)param_2;
  fVar18 = (float)iVar12;
  fStackX_c = (float)((ulonglong)param_2 >> 0x20);
  auVar2 = vroundps_avx(ZEXT416((uint)(local_res8 / fVar18)),1);
  uVar5 = (int)auVar2._0_4_ - 1;
  uVar3 = 0;
  if (0 < (int)uVar5) {
    uVar3 = uVar5;
  }
  auVar2 = vroundps_avx(ZEXT416((uint)(fStackX_c / fVar18)),1);
  uVar6 = (int)auVar2._0_4_ - 1;
  uVar5 = 0;
  if (0 < (int)uVar6) {
    uVar5 = uVar6;
  }
  auVar2 = vroundps_avx(ZEXT416((uint)((((float)DAT_1400296d0 + local_res8) - (1f)) /
                                      fVar18)),1);
  iVar7 = (int)auVar2._0_4_ + 1;
  iVar4 = (int)DAT_140029a88 + -1;
  if (iVar7 < (int)DAT_140029a88 + -1) {
    iVar4 = iVar7;
  }
  auVar2 = vroundps_avx(ZEXT416((uint)((((float)DAT_1400296d4 + fStackX_c) - (1f)) / fVar18
                                      )),1);
  iVar8 = (int)auVar2._0_4_ + 1;
  iVar7 = DAT_140029a88._4_4_ + -1;
  if (iVar8 < DAT_140029a88._4_4_ + -1) {
    iVar7 = iVar8;
  }
  uVar9 = 0x200000002;
  if (uVar11 == 0) {
    uVar9 = 0x100000001;
  }
  iVar8 = 9;
  if (uVar11 != 0) {
    iVar8 = 0x14;
  }
  uVar6 = ((int)*param_1 - iVar8) - 1;
  if ((int)uVar3 < (int)uVar6) {
    uVar3 = uVar6;
  }
  uVar6 = (*(int *)((longlong)param_1 + 4) - iVar8) - 1;
  if ((int)uVar5 < (int)uVar6) {
    uVar5 = uVar6;
  }
  iVar10 = (int)*param_1 + (int)uVar9 + iVar8;
  if (iVar10 < iVar4) {
    iVar4 = iVar10;
  }
  iVar10 = (int)(uVar9 >> 0x20) + *(int *)((longlong)param_1 + 4) + iVar8;
  if (iVar10 < iVar7) {
    iVar7 = iVar10;
  }
  if (((int)uVar3 <= iVar4) && ((int)uVar5 <= iVar7)) {
    fVar21 = (float)(*param_1 & 0xffffffff);
    auVar22 = ZEXT1264(CONCAT84(SUB128(ZEXT812(0),4),fVar21));
    auVar23 = ZEXT464((uint)((float)(uVar9 & 0xffffffff) + fVar21));
    fVar15 = (float)(*param_1 >> 0x20);
    auVar16 = ZEXT1264(CONCAT84(SUB128(ZEXT812(0),4),fVar15));
    auVar2 = vpcmpeqd_avx(ZEXT416(uVar11),ZEXT416(0));
    auVar2 = vblendvps_avx(ZEXT416((1.10000002f)),ZEXT416((0.899999976f)),auVar2);
    fVar14 = (float)iVar8;
    auVar2 = vmaxss_avx(ZEXT416((uint)(fVar14 - auVar2._0_4_)),ZEXT816(0));
    fVar21 = auVar2._0_4_ * auVar2._0_4_;
    fVar14 = fVar14 * fVar14;
    fVar17 = (0.5f);
    do {
      fVar19 = (float)uVar5;
      auVar2 = vmaxss_avx(auVar16._0_16_,ZEXT416((uint)(fVar19 + fVar17)));
      auVar2 = vminss_avx(ZEXT416((uint)((float)(uVar9 >> 0x20) + fVar15)),auVar2);
      fVar20 = (fVar19 + fVar17) - auVar2._0_4_;
      fVar20 = fVar20 * fVar20;
      uVar11 = uVar3;
      do {
        fVar1 = (float)uVar11 + fVar17;
        auVar2 = vmaxss_avx(auVar22._0_16_,ZEXT416((uint)fVar1));
        auVar2 = vminss_avx(auVar23._0_16_,auVar2);
        fVar1 = fVar1 - auVar2._0_4_;
        fVar1 = fVar1 * fVar1 + fVar20;
        if ((fVar1 <= fVar14) && (fVar21 <= fVar1)) {
          auVar2._8_8_ = 0;
          auVar2._0_8_ = SUB648(ZEXT6064((undefined1  [60])0x0),4);
          auVar13._4_12_ = SUB1612(auVar2 << 0x40,4);
          auVar13._0_4_ = (fVar19 * fVar18 - (float)((ulonglong)param_2 >> 0x20)) + fVar17;
          auVar2 = vroundps_avx(auVar13,1);
          auVar13 = vroundps_avx(ZEXT416((uint)(((float)uVar11 * fVar18 - (float)param_2) + fVar17))
                                 ,1);
          FUN_140008090((int)auVar13._0_4_,(int)auVar2._0_4_,iVar12,iVar12,0x685aff28);
        }
        uVar11 = uVar11 + 1;
      } while ((int)uVar11 <= iVar4);
      auVar16 = ZEXT464((uint)fVar15);
      uVar5 = uVar5 + 1;
    } while ((int)uVar5 <= iVar7);
  }
  return;
}


// ===== FUN_140016dd0 @ 140016dd0 size=3398

void FUN_140016dd0(void)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  ulonglong uVar8;
  undefined8 *puVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  ulonglong uVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  byte bVar21;
  int iVar22;
  undefined1 *puVar23;
  uint *puVar24;
  byte bVar25;
  int iVar26;
  longlong lVar27;
  int iVar28;
  int iVar29;
  longlong *plVar30;
  uint uVar31;
  uint uVar32;
  uint uVar33;
  longlong lVar34;
  tagPOINT local_res8;
  undefined4 local_res10;
  uint local_res18;
  uint local_res20;
  undefined4 uVar35;
  uint local_108;
  uint local_fc;
  char *local_e8;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  uint local_a8;
  undefined8 local_a0 [5];
  undefined8 local_78 [7];
  
  if (DAT_1400298ac == 0) {
    return;
  }
  iVar13 = 1;
  if (1 < DAT_140029044 * DAT_140029040) {
    iVar13 = DAT_140029044 * DAT_140029040;
  }
  iVar15 = DAT_140029048 + DAT_14002904c;
  local_res20 = 0x60;
  if (0x60 < (int)(iVar13 + 0x18U)) {
    local_res20 = iVar13 + 0x18U;
  }
  uVar2 = (DAT_1400296d0 + iVar15 * -2) / (int)local_res20;
  uVar32 = 1;
  if (1 < (int)uVar2) {
    uVar32 = uVar2;
  }
  if ((int)uVar32 < 1) {
    uVar32 = 1;
  }
  if (0xc < (int)uVar32) {
    uVar32 = 0xc;
  }
  uVar8 = 0;
  uVar2 = (uint)((int)(0xc % (ulonglong)uVar32) != 0) + (int)(0xc / (ulonglong)uVar32);
  uVar19 = uVar32 * local_res20 + DAT_14002904c * 2;
  iVar22 = (DAT_1400296d0 - uVar19) - DAT_140029048;
  iVar13 = 0;
  if (0 < iVar22) {
    iVar13 = iVar22;
  }
  uVar33 = 1;
  uVar31 = uVar33;
  if (1 < uVar2) {
    uVar31 = uVar2;
  }
  iVar22 = iVar13 + DAT_14002904c;
  FUN_140004bc0(iVar13,DAT_140029048,uVar19,uVar31 * local_res20 + DAT_14002904c * 2,DAT_14002904c,
                DAT_14002957c,DAT_140029580);
  local_res8.x = 0;
  local_res8.y = 0;
  GetCursorPos(&local_res8);
  ScreenToClient(DAT_140029680,&local_res8);
  if (DAT_1400298ac != 0) {
    uVar2 = uVar33;
    if (1 < DAT_140029044 * DAT_140029040) {
      uVar2 = DAT_140029044 * DAT_140029040;
    }
    iVar13 = 0x60;
    if (0x60 < (int)(uVar2 + 0x18)) {
      iVar13 = uVar2 + 0x18;
    }
    uVar19 = (int)(DAT_1400296d0 + (DAT_140029048 + DAT_14002904c) * -2) / iVar13;
    uVar2 = 1;
    if (1 < (int)uVar19) {
      uVar2 = uVar19;
    }
    if ((int)uVar2 < 1) {
      uVar2 = 1;
    }
    if (0xc < (int)uVar2) {
      uVar2 = 0xc;
    }
    iVar11 = (int)(float)local_res8.x;
    uVar19 = (uint)((int)(0xc % (ulonglong)uVar2) != 0) + (int)(0xc / (ulonglong)uVar2);
    if (1 < uVar19) {
      uVar33 = uVar19;
    }
    iVar17 = uVar2 * iVar13 + DAT_14002904c * 2;
    iVar20 = (DAT_1400296d0 - iVar17) - DAT_140029048;
    iVar10 = (int)(float)local_res8.y;
    iVar3 = 0;
    if (0 < iVar20) {
      iVar3 = iVar20;
    }
    if ((((iVar3 <= iVar11) && (iVar11 < iVar3 + iVar17)) && (DAT_140029048 <= iVar10)) &&
       (iVar10 < (int)(uVar33 * iVar13 + DAT_14002904c * 2 + DAT_140029048))) {
      iVar10 = (iVar10 - DAT_140029048) - DAT_14002904c;
      iVar11 = (iVar11 - iVar3) - DAT_14002904c;
      if ((-1 < iVar11) && (-1 < iVar10)) {
        iVar11 = iVar11 / iVar13;
        iVar10 = iVar10 / iVar13;
        if (((-1 < iVar11) && ((iVar11 < (int)uVar2 && (-1 < iVar10)))) && (iVar10 < (int)uVar33)) {
          local_108 = uVar2 * iVar10 + iVar11;
          uVar16 = (ulonglong)local_108;
          if ((-1 < (int)local_108) && (local_108 < 0xc)) goto LAB_140017049;
        }
      }
    }
  }
  uVar16 = 0xffffffff;
  local_108 = 0xffffffff;
LAB_140017049:
  local_e8 = &DAT_140029058;
  local_fc = 0;
  iVar11 = (int)local_res20 / 3 + ((int)local_res20 >> 0x1f) +
           (int)(((longlong)(int)local_res20 / 3 + ((longlong)(int)local_res20 >> 0x3f) &
                 0xffffffffU) >> 0x1f);
  iVar13 = 0x18;
  if (0x18 < iVar11) {
    iVar13 = iVar11;
  }
  iVar10 = local_res20 - iVar13;
  iVar3 = (int)(local_res20 + ((int)local_res20 >> 0x1f & 3U)) >> 2;
  uVar2 = local_res20;
  iVar11 = 0x12;
  if (0x12 < iVar3) {
    iVar11 = iVar3;
  }
  do {
    iVar17 = (int)(uVar8 % (ulonglong)uVar32) * uVar2 + iVar22;
    iVar3 = (int)(uVar8 / uVar32) * uVar2 + iVar15;
    if (*local_e8 == '\x01') {
      uVar8 = FUN_140004300();
      iVar20 = (int)uVar8;
    }
    else {
      uVar8 = FUN_140004e70(local_e8[1]);
      iVar20 = (int)uVar8;
    }
    uVar19 = DAT_1400291e8;
    if (*local_e8 != '\x01') {
      uVar8 = FUN_140004e70(local_e8[1]);
      uVar19 = (uint)uVar8;
    }
    if (iVar20 == 0) {
      bVar25 = 0x50;
      bVar21 = 0x82;
      local_res8.x._0_1_ = 0x50;
    }
    else {
      bVar21 = 100;
      local_res8.x._0_1_ = 0xaa;
      bVar25 = 0x82;
    }
    local_res10 = CONCAT31(local_res10._1_3_,bVar21);
    uVar31 = 0x3c;
    if (iVar20 == 0) {
      uVar31 = 0x5a;
    }
    if (local_fc == (uint)uVar16) {
      uVar33 = 0x5adcbea0;
      if (iVar20 == 0) {
        uVar33 = 0x6e6464aa;
      }
      local_res10._2_1_ = (undefined1)(uVar33 >> 0x10);
      local_res10._1_1_ = (byte)(uVar33 >> 8);
      local_res10._0_1_ = (byte)uVar33;
      local_res8.x._0_1_ = local_res10._2_1_;
      uVar31 = uVar33 >> 0x18;
      bVar25 = local_res10._1_1_;
      bVar21 = (byte)local_res10;
      local_res10 = uVar33;
    }
    local_res18 = CONCAT31(local_res18._1_3_,bVar25);
    iVar5 = iVar3 + 1;
    iVar6 = 0;
    if (0 < iVar17 + 1) {
      iVar6 = iVar17 + 1;
    }
    iVar14 = 0;
    if (0 < iVar5) {
      iVar14 = iVar5;
    }
    iVar4 = iVar17 + -1 + uVar2;
    iVar26 = DAT_1400296d0;
    if (iVar4 < DAT_1400296d0) {
      iVar26 = iVar4;
    }
    iVar5 = (uVar2 - 2) + iVar5;
    iVar4 = DAT_1400296d4;
    if (iVar5 < DAT_1400296d4) {
      iVar4 = iVar5;
    }
    iVar5 = DAT_1400296d0;
    if ((iVar6 < iVar26) && (iVar14 < iVar4)) {
      iVar28 = 0xff - uVar31;
      lVar34 = (longlong)iVar6;
      do {
        if (lVar34 < iVar26) {
          lVar27 = iVar26 - lVar34;
          puVar23 = (undefined1 *)(lVar34 * 4 + 2 + DAT_1400296c8 + (longlong)(iVar14 * iVar5) * 4);
          do {
            uVar2 = *(uint *)(puVar23 + -2);
            puVar23[1] = 0xff;
            puVar23[-2] = (char)((ulonglong)((uVar2 & 0xff) * iVar28 + bVar21 * uVar31) / 0xff);
            puVar23[-1] = (char)((ulonglong)((uVar2 >> 8 & 0xff) * iVar28 + bVar25 * uVar31) / 0xff)
            ;
            *puVar23 = (char)((ulonglong)
                              ((uVar2 >> 0x10 & 0xff) * iVar28 + (byte)local_res8.x * uVar31) / 0xff
                             );
            lVar27 = lVar27 + -1;
            puVar23 = puVar23 + 4;
          } while (lVar27 != 0);
          bVar21 = (byte)local_res10;
          iVar5 = DAT_1400296d0;
        }
        iVar14 = iVar14 + 1;
      } while (iVar14 < iVar4);
    }
    iVar6 = DAT_1400296d4;
    if (*local_e8 == '\x01') {
      plVar30 = (longlong *)&DAT_1400eb3c0;
LAB_14001732e:
      iVar5 = (int)plVar30[2];
      iVar6 = *(int *)((longlong)plVar30 + 0x14);
      iVar26 = local_res20 - 8;
      iVar14 = 1;
      if (1 < iVar5) {
        iVar14 = iVar5;
      }
      iVar4 = 1;
      if (1 < iVar26 / iVar14) {
        iVar4 = iVar26 / iVar14;
      }
      iVar14 = 1;
      if (1 < iVar6) {
        iVar14 = iVar6;
      }
      iVar28 = 1;
      if (1 < iVar26 / iVar14) {
        iVar28 = iVar26 / iVar14;
      }
      if (iVar4 < iVar28) {
        iVar28 = iVar4;
      }
      iVar14 = 1;
      if (1 < iVar28) {
        iVar14 = iVar28;
      }
      iVar6 = iVar26 - iVar6 * iVar14;
      if (iVar6 < 0) {
        iVar6 = iVar6 + 1;
      }
      iVar26 = iVar26 - iVar5 * iVar14;
      if (iVar26 < 0) {
        iVar26 = iVar26 + 1;
      }
      FUN_140004550(plVar30,(iVar26 >> 1) + 4 + iVar17,iVar3 + 4 + (iVar6 >> 1),iVar14,0);
      iVar5 = DAT_1400296d0;
      iVar6 = DAT_1400296d4;
    }
    else {
      if (local_e8[1] == '\x01') {
        plVar30 = (longlong *)&DAT_1400eaa20;
      }
      else {
        plVar30 = (longlong *)FUN_1400065a0(local_e8[1]);
      }
      if (plVar30 != (longlong *)0x0) goto LAB_14001732e;
    }
    iVar28 = iVar17 + iVar10;
    iVar4 = iVar3 + 4;
    iVar14 = iVar28 + -4;
    iVar26 = 0;
    if (0 < iVar14) {
      iVar26 = iVar14;
    }
    iVar29 = 0;
    if (0 < iVar4) {
      iVar29 = iVar4;
    }
    iVar12 = iVar5;
    if (iVar14 + iVar13 < iVar5) {
      iVar12 = iVar14 + iVar13;
    }
    if (iVar11 + iVar4 < iVar6) {
      iVar6 = iVar11 + iVar4;
    }
    if ((iVar26 < iVar12) && (iVar29 < iVar6)) {
      lVar34 = (longlong)iVar26;
      do {
        if (lVar34 < iVar12) {
          lVar27 = iVar12 - lVar34;
          puVar23 = (undefined1 *)(lVar34 * 4 + 2 + DAT_1400296c8 + (longlong)(iVar29 * iVar5) * 4);
          do {
            uVar2 = *(uint *)(puVar23 + -2);
            puVar23[1] = 0xff;
            puVar23[-2] = (char)((ulonglong)((uVar2 & 0xff) * 0x4b + 0x10e0) / 0xff);
            puVar23[-1] = (char)((ulonglong)((uVar2 >> 8 & 0xff) * 0x4b + 0x10e0) / 0xff);
            *puVar23 = (char)((ulonglong)((uVar2 >> 0x10 & 0xff) * 0x4b + 0x10e0) / 0xff);
            lVar27 = lVar27 + -1;
            puVar23 = puVar23 + 4;
            iVar5 = DAT_1400296d0;
          } while (lVar27 != 0);
        }
        iVar29 = iVar29 + 1;
      } while (iVar29 < iVar6);
    }
    FUN_140006d00(uVar19,iVar28,iVar3 + 5,0x10);
    iVar14 = iVar3 + (local_res20 - 0x16);
    iVar5 = iVar17 + 4;
    iVar6 = 0;
    if (0 < iVar5) {
      iVar6 = iVar5;
    }
    iVar26 = 0;
    if (0 < iVar14) {
      iVar26 = iVar14;
    }
    uVar8 = FUN_140012110(local_fc + 1);
    iVar5 = iVar5 + ((int)uVar8 + 1) * 0x12;
    iVar4 = DAT_1400296d0;
    if (iVar5 < DAT_1400296d0) {
      iVar4 = iVar5;
    }
    iVar5 = DAT_1400296d4;
    if (iVar14 + 0x12 < DAT_1400296d4) {
      iVar5 = iVar14 + 0x12;
    }
    if ((iVar6 < iVar4) && (iVar26 < iVar5)) {
      lVar34 = (longlong)iVar6;
      iVar6 = DAT_1400296d0;
      do {
        if (lVar34 < iVar4) {
          lVar27 = iVar4 - lVar34;
          puVar23 = (undefined1 *)(lVar34 * 4 + 2 + DAT_1400296c8 + (longlong)(iVar26 * iVar6) * 4);
          do {
            uVar2 = *(uint *)(puVar23 + -2);
            puVar23[1] = 0xff;
            puVar23[-2] = (char)((ulonglong)((uVar2 & 0xff) * 0x4b + 0x10e0) / 0xff);
            puVar23[-1] = (char)((ulonglong)((uVar2 >> 8 & 0xff) * 0x4b + 0x10e0) / 0xff);
            *puVar23 = (char)((ulonglong)((uVar2 >> 0x10 & 0xff) * 0x4b + 0x10e0) / 0xff);
            lVar27 = lVar27 + -1;
            puVar23 = puVar23 + 4;
            iVar6 = DAT_1400296d0;
          } while (lVar27 != 0);
        }
        iVar26 = iVar26 + 1;
      } while (iVar26 < iVar5);
    }
    FUN_140006d00(local_fc + 1,iVar17 + 5,iVar14 + 1,0x10);
    uVar2 = local_res20;
    if ((*local_e8 == '\0') &&
       (uVar19 = DAT_140029050, uVar35 = DAT_140029578, DAT_14002962c == local_e8[1])) {
LAB_140017682:
      FUN_140004940(iVar17,iVar3,local_res20,local_res20,uVar19,uVar35);
    }
    else if (iVar20 == 0) {
      uVar19 = 2;
      uVar35 = 0xff5a5ab4;
      goto LAB_140017682;
    }
    uVar16 = (ulonglong)(int)local_108;
    local_fc = local_fc + 1;
    uVar8 = (ulonglong)local_fc;
    local_e8 = local_e8 + 2;
    if (0xb < local_fc) {
      if ((-1 < (int)local_108) && (local_108 < 0xc)) {
        if ((&DAT_140029058)[uVar16 * 2] == '\x01') {
          puVar9 = FUN_1400043b0(local_a0);
        }
        else {
          puVar9 = FUN_140004f90(local_78,(&DAT_140029059)[uVar16 * 2]);
        }
        uVar32 = *(uint *)(puVar9 + 4);
        local_c8 = *puVar9;
        uStack_c0 = puVar9[1];
        uStack_b8 = puVar9[2];
        uStack_b0 = puVar9[3];
        local_a8 = uVar32;
        iVar13 = 1;
        if (1 < DAT_140029044 * DAT_140029040) {
          iVar13 = DAT_140029044 * DAT_140029040;
        }
        iVar15 = 0x60;
        if (0x60 < iVar13 + 0x18) {
          iVar15 = iVar13 + 0x18;
        }
        iVar22 = (int)(DAT_1400296d0 + (DAT_140029048 + DAT_14002904c) * -2) / iVar15;
        iVar13 = 1;
        if (1 < iVar22) {
          iVar13 = iVar22;
        }
        if (iVar13 < 1) {
          iVar13 = 1;
        }
        if (0xc < iVar13) {
          iVar13 = 0xc;
        }
        iVar11 = ((DAT_14002904c * -2 - iVar13 * iVar15) - DAT_140029048) + DAT_1400296d0;
        iVar22 = 0;
        if (0 < iVar11) {
          iVar22 = iVar11;
        }
        iVar11 = 0;
        iVar3 = ((int)local_108 / iVar13) * iVar15 + DAT_140029048 + DAT_14002904c;
        if (uVar32 != 0) {
          puVar24 = (uint *)((longlong)&local_c8 + 4);
          uVar8 = (ulonglong)uVar32;
          do {
            iVar10 = 1;
            for (uVar2 = *puVar24; 9 < uVar2; uVar2 = uVar2 / 10) {
              iVar10 = iVar10 + 1;
            }
            iVar10 = iVar10 * 0x20 + 0x28;
            if (iVar10 < iVar11) {
              iVar10 = iVar11;
            }
            iVar11 = iVar10;
            puVar24 = puVar24 + 2;
            uVar8 = uVar8 - 1;
          } while (uVar8 != 0);
        }
        iVar10 = 0x40;
        if (0x40 < iVar11) {
          iVar10 = iVar11;
        }
        uVar19 = iVar10 + 0x10;
        uVar2 = uVar32 * 0x28 + 0x10;
        if (uVar32 == 0) {
          uVar2 = 0;
        }
        uVar33 = iVar15 + 8 + iVar3;
        uVar31 = ((int)local_108 % iVar13) * iVar15 + iVar22 + DAT_14002904c +
                 (int)(iVar15 - uVar19) / 2;
        if (DAT_1400296d4 < (int)(uVar33 + uVar2)) {
          uVar33 = (iVar3 - uVar2) - 8;
        }
        uVar18 = 0;
        local_res8.x = -0x1493b3c6;
        uVar7 = uVar18;
        if (0 < (int)(DAT_1400296d0 - uVar19)) {
          uVar7 = DAT_1400296d0 - uVar19;
        }
        if ((int)uVar31 < 0) {
          uVar31 = uVar18;
        }
        if ((int)uVar7 < (int)uVar31) {
          uVar31 = uVar7;
        }
        uVar7 = uVar18;
        if (0 < (int)(DAT_1400296d4 - uVar2)) {
          uVar7 = DAT_1400296d4 - uVar2;
        }
        if ((int)uVar33 < 0) {
          uVar33 = uVar18;
        }
        if ((int)uVar7 < (int)uVar33) {
          uVar33 = uVar7;
        }
        local_res18 = uVar33;
        local_res20 = uVar2;
        FUN_140004bc0(uVar31,uVar33,uVar19,uVar2,2,DAT_14002957c,0xeb6c4c3a);
        if (uVar32 != 0) {
          iVar13 = uVar31 + 8;
          iVar15 = uVar33 + 0xc;
          local_res10 = uVar31 + 0x30;
          local_res8.x = iVar13;
          uVar19 = local_res10;
          do {
            uVar2 = 0;
            bVar25 = *(byte *)(&local_c8 + uVar18);
            uVar8 = (ulonglong)bVar25;
            FUN_140004550((longlong *)(&DAT_1400299b0)[uVar8],iVar13,iVar15,2,0);
            if (bVar25 < DAT_140029a30) {
              if (DAT_140029a30 <= uVar8) {
                pcVar1 = (code *)swi(3);
                (*pcVar1)();
                return;
              }
              uVar2 = *(uint *)(DAT_140029a28 + uVar8 * 4);
            }
            uVar31 = *(uint *)((longlong)&local_c8 + (ulonglong)uVar18 * 8 + 4);
            if (uVar2 < uVar31) {
              if (uVar31 == 0) {
                FUN_1400047f0((longlong *)&DAT_1400eaee0,uVar19,iVar15,2,0);
              }
              else {
                uVar8 = FUN_140012110(uVar31);
                iVar22 = (int)uVar8 * 0x20 + uVar19;
                do {
                  FUN_1400047f0((longlong *)(&DAT_1400eaee0 + (ulonglong)(uVar31 % 10) * 0x20),
                                iVar22,iVar15,2,0);
                  iVar22 = iVar22 + -0x20;
                  uVar2 = uVar31 / 10;
                  iVar13 = local_res8.x;
                  uVar31 = uVar31 / 10;
                  uVar19 = local_res10;
                } while (uVar2 != 0);
              }
            }
            else {
              FUN_140006d00(uVar31,uVar19,iVar15,0x20);
            }
            uVar18 = uVar18 + 1;
            iVar15 = iVar15 + 0x28;
            uVar33 = local_res18;
            uVar2 = local_res20;
          } while (uVar18 < uVar32);
        }
        DAT_140029990 = FUN_140009f00((&DAT_140029059)[uVar16 * 2]);
        if ((&DAT_140029058)[uVar16 * 2] == '\x01') {
          DAT_140029990 = &DAT_1400eb740;
        }
        else if (DAT_140029990 == (undefined *)0x0) {
          return;
        }
        local_res8.x = 0;
        local_res8.y = 0;
        GetCursorPos(&local_res8);
        ScreenToClient(DAT_140029680,&local_res8);
        iVar13 = 0;
        if (uVar32 != 0) {
          iVar13 = 8;
        }
        DAT_14002999c = iVar13 + uVar33 + uVar2;
        DAT_140029998 =
             (int)((float)local_res8.x - (float)(*(uint *)(DAT_140029990 + 8) & 0x7fffffff));
      }
      return;
    }
  } while( true );
}


// ===== FUN_140017b20 @ 140017b20 size=577

void FUN_140017b20(int *param_1,int param_2)

{
  undefined1 auVar1 [16];
  uint uVar2;
  undefined8 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  float fVar9;
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  float fVar12;
  undefined1 auVar13 [16];
  
  if ((((param_1 != (int *)0x0) && (*(longlong *)(param_1 + 0x4a) != 0)) && (*param_1 != 1)) &&
     (4 < *param_1 - 5U)) {
    fVar12 = *(float *)(*(longlong *)(param_1 + 0x4a) + 0x24);
    auVar11 = ZEXT816(0) << 0x40;
    if ((0.0 < fVar12) && (uVar3 = FUN_140007b10((longlong)param_1), (int)uVar3 != 0)) {
      if (*(longlong *)(param_1 + 0x4a) == 0) {
        fVar9 = 0.0;
      }
      else {
        fVar9 = (float)param_1[0x4c];
      }
      if (fVar9 < fVar12) {
        if (*(longlong *)(param_1 + 0x4a) == 0) {
          auVar13 = ZEXT816(0) << 0x40;
        }
        else {
          auVar13 = ZEXT416((uint)param_1[0x4c]);
        }
        auVar10 = vroundps_avx(ZEXT416(DAT_140029630),1);
        auVar1 = vroundps_avx(ZEXT416(DAT_140029634),1);
        uVar2 = param_2 * param_1[0xb] * 0x10;
        uVar5 = 0x14;
        if (0x14 < (int)uVar2) {
          uVar5 = uVar2;
        }
        uVar8 = 6;
        if (6 < (int)(param_2 + 4U)) {
          uVar8 = param_2 + 4U;
        }
        iVar7 = ((int)*(undefined8 *)(param_1 + 8) * DAT_140029020 * 0x10 + (int)(uVar2 - uVar5) / 2
                ) - (int)auVar10._0_4_;
        iVar4 = 1;
        if (1 < param_2) {
          iVar4 = param_2;
        }
        iVar6 = 2;
        if (2 < param_2 / 2) {
          iVar6 = param_2 / 2;
        }
        iVar6 = (((((int)((ulonglong)*(undefined8 *)(param_1 + 8) >> 0x20) * DAT_140029020 - iVar4)
                   * 8 - iVar6) * 2 + -10) - (int)auVar1._0_4_) - uVar8;
        FUN_140004bc0(iVar7,iVar6,uVar5,uVar8,1,0xff000000,0xff282828);
        auVar10._0_4_ = auVar13._0_4_ / fVar12;
        auVar10._4_12_ = auVar13._4_12_;
        auVar11 = vmaxss_avx(auVar11,auVar10);
        auVar11 = vminss_avx(ZEXT416((uint)(1f)),auVar11);
        iVar4 = 0;
        if (0 < (int)(uVar5 - 2)) {
          iVar4 = uVar5 - 2;
        }
        auVar11 = vroundps_avx(ZEXT416((uint)(((1f) - auVar11._0_4_) * (float)iVar4 +
                                             (0.5f))),1);
        if (0 < (int)auVar11._0_4_) {
          uVar5 = 1;
          if (1 < (int)(uVar8 - 2)) {
            uVar5 = uVar8 - 2;
          }
          FUN_140004bc0(iVar7 + 1,iVar6 + 1,(int)auVar11._0_4_,uVar5,0,0xff5ad2ff,0xff5ad2ff);
        }
      }
    }
  }
  return;
}


// ===== FUN_140017d70 @ 140017d70 size=383

void FUN_140017d70(int *param_1,int param_2)

{
  int iVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined8 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  if (((((param_1 != (int *)0x0) && (*(longlong *)(param_1 + 0x4a) != 0)) &&
       (*(longlong *)(*(longlong *)(param_1 + 0x4a) + 0x28) != 0)) && (*param_1 != 1)) &&
     ((uVar4 = FUN_140010ef0((longlong)param_1,param_2), (int)uVar4 != 0 ||
      (((DAT_140029af0 != 0 && (DAT_14002a890 != (int *)0x0)) &&
       ((*(longlong *)(DAT_14002a890 + 2) != 0 &&
        ((*(longlong *)(DAT_14002a890 + 2) == DAT_14002a898 && (DAT_14002a890 == param_1)))))))))) {
    iVar7 = 1;
    if (1 < param_2) {
      iVar7 = param_2;
    }
    auVar2 = vroundps_avx(ZEXT416(DAT_140029634),1);
    iVar8 = 2;
    if (2 < param_2 / 2) {
      iVar8 = param_2 / 2;
    }
    auVar3 = vroundps_avx(ZEXT416(DAT_140029630),1);
    iVar1 = iVar8 + iVar7 * 8;
    iVar5 = ((int)*(undefined8 *)(param_1 + 8) * DAT_140029020 * 0x10 +
            (param_2 * param_1[0xb] * 0x10 + iVar1 * -2) / 2) - (int)auVar3._0_4_;
    iVar6 = ((int)((ulonglong)*(undefined8 *)(param_1 + 8) >> 0x20) * DAT_140029020 * 0x10 -
            (int)auVar2._0_4_) + iVar1 * -2 + -6;
    FUN_140004bc0(iVar5,iVar6,iVar1 * 2,iVar1 * 2,2,0xff000000,0xff485c48);
    FUN_140004550(*(longlong **)(*(longlong *)(param_1 + 0x4a) + 0x28),iVar5 + iVar8,iVar8 + iVar6,
                  iVar7,0);
  }
  return;
}


// ===== FUN_140017ef0 @ 140017ef0 size=1345

void FUN_140017ef0(undefined8 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  undefined1 auVar3 [16];
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  ulonglong uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  undefined4 *puVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  float fVar22;
  float local_58;
  float fStack_54;
  
  if ((DAT_14002a9d8 != 0) && (DAT_14002a9d0 != (ulonglong *)0x0)) {
    iVar13 = 2;
    if ((int)DAT_14002a9d0[1] == 0) {
      iVar13 = 1;
    }
    iVar20 = 0x78;
    if (0x78 < param_2 * 0x20) {
      iVar20 = param_2 * 0x20;
    }
    iVar8 = 0x14;
    if (0x14 < param_2 * 8) {
      iVar8 = param_2 * 8;
    }
    iVar7 = iVar8 * 3 + 0x26;
    local_58 = (float)param_1;
    fStack_54 = (float)((ulonglong)param_1 >> 0x20);
    auVar3 = vroundps_avx(ZEXT416((uint)(((float)(param_2 << 4) *
                                          (float)(*DAT_14002a9d0 & 0xffffffff) - local_58) +
                                        (0.5f))),1);
    iVar16 = (iVar13 * param_2 * 8 - iVar20 / 2) + (int)auVar3._0_4_;
    auVar3 = vroundps_avx(ZEXT416((uint)(((float)(param_2 << 4) * (float)(*DAT_14002a9d0 >> 0x20) -
                                         fStack_54) + (0.5f))),1);
    iVar12 = (int)auVar3._0_4_ - iVar7;
    iVar13 = iVar12 + -8;
    fVar22 = (0.5f);
    FUN_140008090(iVar16,iVar13,iVar20,iVar7,0xd2121212);
    FUN_140007ff0(iVar16,iVar13,iVar20,1,0xff46b4d2);
    iVar9 = iVar13 + iVar7;
    FUN_140007ff0(iVar16,iVar9 + -1,iVar20,1,0xff46b4d2);
    FUN_140007ff0(iVar16,iVar13,1,iVar7,0xff46b4d2);
    FUN_140007ff0(iVar20 + -1 + iVar16,iVar13,1,iVar7,0xff46b4d2);
    iVar13 = iVar12 + -2;
    iVar7 = iVar16 + 4;
    iVar6 = (int)(param_2 * 3 + (param_2 * 3 >> 0x1f & 3U)) >> 2;
    iVar19 = 1;
    if (1 < iVar6) {
      iVar19 = iVar6;
    }
    iVar6 = iVar13 + iVar8 * 2;
    iVar14 = iVar20 + -4;
    iVar21 = iVar19 * 0x10 + 4 + iVar7;
    FUN_140008090(iVar16 + 2,iVar12 + -3,iVar14,iVar8,0x465aa05a);
    FUN_140008090(iVar16 + 2,iVar12 + -3 + iVar8,iVar14,iVar8,0x463c96be);
    FUN_140008090(iVar16 + 2,iVar6 + -1,iVar14,iVar8,0x46be785a);
    uVar15 = 0;
    FUN_140004550(DAT_140029a08,iVar7,iVar13,iVar19,0);
    uVar11 = uVar15;
    if (0xb < DAT_140029a30) {
      uVar11 = *(uint *)(DAT_140029a28 + 0x2c);
    }
    FUN_140006d00(uVar11,iVar21,iVar13,0x10);
    FUN_140004550(DAT_140029a10,iVar7,iVar13 + iVar8,iVar19,0);
    uVar11 = uVar15;
    if (0xc < DAT_140029a30) {
      uVar11 = *(uint *)(DAT_140029a28 + 0x30);
    }
    FUN_140006d00(uVar11,iVar21,iVar13 + iVar8,0x10);
    FUN_140004550((longlong *)&DAT_1400eac40,iVar7,iVar6,iVar19,0);
    FUN_140006d00(DAT_1400291e8,iVar21,iVar6,0x10);
    iVar13 = param_2 * 4;
    uVar17 = iVar16 + 6;
    uVar11 = iVar9 - 0x16;
    if (iVar13 < 0x10) {
      iVar13 = 0x10;
    }
    uVar1 = iVar9 - 0x15;
    uVar2 = iVar16 + 7;
    uVar4 = uVar15;
    if (0 < (int)uVar17) {
      uVar4 = uVar17;
    }
    uVar5 = uVar15;
    if (0 < (int)uVar11) {
      uVar5 = uVar11;
    }
    iVar7 = iVar20 + -0xc + uVar17;
    auVar3 = vmaxss_avx(ZEXT816(0) << 0x40,ZEXT416((uint)(DAT_14004a9e4 / (10f))));
    iVar8 = DAT_1400296d0;
    if (iVar7 < DAT_1400296d0) {
      iVar8 = iVar7;
    }
    auVar3 = vminss_avx(ZEXT416((1f)),auVar3);
    iVar7 = DAT_1400296d4;
    if ((int)(iVar13 + uVar11) < DAT_1400296d4) {
      iVar7 = iVar13 + uVar11;
    }
    if (((int)uVar4 < iVar8) && ((int)uVar5 < iVar7)) {
      do {
        uVar11 = uVar5 + 1;
        puVar18 = (undefined4 *)
                  (DAT_1400296c8 + (longlong)(int)(uVar5 * DAT_1400296d0) * 4 +
                  (longlong)(int)uVar4 * 4);
        for (uVar10 = (longlong)(int)(iVar8 - uVar4) & 0x3fffffffffffffff; uVar10 != 0;
            uVar10 = uVar10 - 1) {
          *puVar18 = 0xff0f0f0f;
          puVar18 = puVar18 + 1;
        }
        uVar5 = uVar11;
      } while ((int)uVar11 < iVar7);
    }
    iVar8 = iVar20 + -0xe + uVar2;
    uVar11 = uVar15;
    if (0 < (int)uVar2) {
      uVar11 = uVar2;
    }
    if (0 < (int)uVar1) {
      uVar15 = uVar1;
    }
    iVar7 = DAT_1400296d0;
    if (iVar8 < DAT_1400296d0) {
      iVar7 = iVar8;
    }
    iVar9 = iVar13 + -2 + uVar1;
    iVar8 = DAT_1400296d4;
    if (iVar9 < DAT_1400296d4) {
      iVar8 = iVar9;
    }
    if (((int)uVar11 < iVar7) && ((int)uVar15 < iVar8)) {
      do {
        uVar17 = uVar15 + 1;
        puVar18 = (undefined4 *)
                  (DAT_1400296c8 + (longlong)(int)(uVar15 * DAT_1400296d0) * 4 +
                  (longlong)(int)uVar11 * 4);
        for (uVar10 = (longlong)(int)(iVar7 - uVar11) & 0x3fffffffffffffff; uVar10 != 0;
            uVar10 = uVar10 - 1) {
          *puVar18 = 0xff1e2d37;
          puVar18 = puVar18 + 1;
        }
        uVar15 = uVar17;
      } while ((int)uVar17 < iVar8);
    }
    auVar3 = vroundps_avx(ZEXT416((uint)((float)(iVar20 + -0xe) * auVar3._0_4_ + fVar22)),1);
    FUN_140007ff0(uVar2,uVar1,(int)auVar3._0_4_,iVar13 + -2,0xff46c8ff);
  }
  return;
}


// ===== FUN_140018440 @ 140018440 size=870

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140018440(uint *param_1)

{
  uint uVar1;
  ulonglong uVar2;
  uint uVar3;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  tagPOINT local_res8;
  undefined4 local_res10;
  int iStack_64;
  ulonglong uVar4;
  
  uVar3 = *param_1 * 0x28 + 0x10;
  if (*param_1 == 0) {
    uVar3 = 0x38;
  }
  if (DAT_140029af0 == 0) {
    local_res8.x = 0;
    local_res8.y = 0;
    GetCursorPos(&local_res8);
    ScreenToClient(DAT_140029680,&local_res8);
    iVar9 = (int)(float)local_res8.x + 0x10;
    iVar8 = (int)(float)local_res8.y + 0x10;
  }
  else {
    iVar9 = 1;
    if (1 < DAT_140029124 * DAT_140029120) {
      iVar9 = DAT_140029124 * DAT_140029120;
    }
    if (DAT_140029af4 == 0) {
      uVar1 = (DAT_1400296d0 + (DAT_14002912c + DAT_140029130) * -2) / iVar9;
      uVar6 = 1;
      if (1 < (int)uVar1) {
        uVar6 = uVar1;
      }
    }
    else {
      uVar6 = DAT_140029ae0;
      if ((int)DAT_140029ae0 < 1) {
        uVar6 = 1;
      }
      if (4 < (int)uVar6) {
        uVar6 = 4;
      }
    }
    if (DAT_140029af4 == 0) {
      uVar2 = 1;
      uVar4 = (longlong)(DAT_1400296d0 + (DAT_14002912c + DAT_140029130) * -2) / (longlong)iVar9;
      if (1 < (int)uVar4) {
        uVar2 = uVar4 & 0xffffffff;
      }
    }
    else {
      uVar1 = DAT_140029ae0;
      if ((int)DAT_140029ae0 < 1) {
        uVar1 = 1;
      }
      if (4 < (int)uVar1) {
        uVar1 = 4;
      }
      uVar2 = (ulonglong)uVar1;
    }
    iVar5 = (uint)((int)((ulonglong)DAT_140029ae0 % uVar2) != 0) + (int)(DAT_140029ae0 / uVar2);
    iVar7 = uVar6 * iVar9 + DAT_140029130 * 2;
    iVar8 = 1;
    if (1 < iVar5) {
      iVar8 = iVar5;
    }
    iVar8 = iVar8 * iVar9 + DAT_140029130 * 2;
    if (DAT_140029af4 == 0) {
      iStack_64 = DAT_14002912c;
      iVar9 = DAT_14002912c;
    }
    else {
      iVar9 = DAT_140029af8 - iVar7 / 2;
      iVar5 = 0;
      if (0 < DAT_1400296d0 - iVar7) {
        iVar5 = DAT_1400296d0 - iVar7;
      }
      if (iVar9 < 0) {
        iVar9 = 0;
      }
      if (iVar5 < iVar9) {
        iVar9 = iVar5;
      }
      iVar5 = 0;
      if (0 < DAT_1400296d4 - iVar8) {
        iVar5 = DAT_1400296d4 - iVar8;
      }
      iStack_64 = (DAT_140029afc - iVar8) - _DAT_140029138;
      if (iStack_64 < 0) {
        iStack_64 = 0;
      }
      if (iVar5 < iStack_64) {
        iStack_64 = iVar5;
      }
    }
    iVar8 = iStack_64 + 8 + iVar8;
    iVar9 = iVar9 + (iVar7 + -0x50) / 2;
  }
  uVar4 = 0;
  if ((DAT_1400296d4 < (int)(iVar8 + uVar3)) && (iVar8 = 0, 0 < (int)(DAT_1400296d4 - uVar3))) {
    iVar8 = DAT_1400296d4 - uVar3;
  }
  local_res8.x = -0x1493b3c6;
  local_res10 = 0xff000000;
  iVar7 = 0;
  iVar5 = iVar7;
  if (0 < DAT_1400296d0 + -0x50) {
    iVar5 = DAT_1400296d0 + -0x50;
  }
  if (iVar9 < 0) {
    iVar9 = iVar7;
  }
  if (iVar5 < iVar9) {
    iVar9 = iVar5;
  }
  iVar5 = iVar7;
  if (0 < (int)(DAT_1400296d4 - uVar3)) {
    iVar5 = DAT_1400296d4 - uVar3;
  }
  if (iVar8 < 0) {
    iVar8 = iVar7;
  }
  if (iVar5 < iVar8) {
    iVar8 = iVar5;
  }
  FUN_140004bc0(iVar9,iVar8,0x50,uVar3,2,0xff000000,0xeb6c4c3a);
  if (*param_1 == 0) {
    if (((byte)param_1[7] < 0xe) &&
       ((longlong *)(&DAT_1400299b0)[(byte)param_1[7]] != (longlong *)0x0)) {
      FUN_140004550((longlong *)(&DAT_1400299b0)[(byte)param_1[7]],iVar9 + 8,iVar8 + 0xc,2,0);
      FUN_140006d00(param_1[8],iVar9 + 0x30,iVar8 + 0xc,0x20);
    }
  }
  else if (*param_1 != 0) {
    iVar8 = iVar8 + 0xc;
    do {
      if (((byte)param_1[uVar4 * 2 + 1] < 0xe) &&
         ((longlong *)(&DAT_1400299b0)[(byte)param_1[uVar4 * 2 + 1]] != (longlong *)0x0)) {
        FUN_140004550((longlong *)(&DAT_1400299b0)[(byte)param_1[uVar4 * 2 + 1]],iVar9 + 8,iVar8,2,0
                     );
        FUN_140006d00(param_1[uVar4 * 2 + 2],iVar9 + 0x30,iVar8,0x20);
      }
      uVar3 = (int)uVar4 + 1;
      uVar4 = (ulonglong)uVar3;
      iVar8 = iVar8 + 0x28;
    } while (uVar3 < *param_1);
  }
  return;
}


// ===== FUN_1400187b0 @ 1400187b0 size=1058

void FUN_1400187b0(void)

{
  int iVar1;
  int iVar2;
  longlong *plVar3;
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  code *pcVar6;
  LONG LVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  ulonglong uVar11;
  int iVar12;
  ulonglong uVar13;
  uint uVar14;
  char *pcVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  int iVar19;
  ulonglong uVar20;
  int iVar21;
  uint uVar22;
  float fVar23;
  float fVar24;
  tagPOINT local_res8;
  int local_res10;
  int local_res18;
  int local_res20;
  
  iVar1 = DAT_140029048;
  if (DAT_14002965c != 0) {
    iVar2 = DAT_14002904c * 2;
    uVar14 = 1;
    if (1 < DAT_140029044 * DAT_140029040) {
      uVar14 = DAT_140029044 * DAT_140029040;
    }
    local_res20 = DAT_140029048;
    local_res8.x = 0;
    local_res8.y = 0;
    uVar8 = (int)(DAT_1400296d0 + (DAT_140029048 + DAT_14002904c) * -2) / (int)uVar14;
    uVar9 = 1;
    if (1 < (int)uVar8) {
      uVar9 = uVar8;
    }
    uVar20 = CONCAT44(0,uVar9);
    auVar4._8_8_ = 0;
    auVar4._0_8_ = uVar20;
    auVar5 = ZEXT816(0) << 0x40 | ZEXT816(0x16);
    uVar8 = (uint)(SUB168(auVar5 % auVar4,0) != 0) + SUB164(auVar5 / auVar4,0);
    uVar22 = uVar9 * uVar14 + iVar2;
    iVar16 = (DAT_1400296d0 - DAT_140029048) - uVar22;
    iVar12 = 0;
    if (0 < iVar16) {
      iVar12 = iVar16;
    }
    local_res18 = DAT_14002904c + iVar12;
    local_res10 = DAT_14002904c + DAT_140029048;
    GetCursorPos(&local_res8);
    ScreenToClient(DAT_140029680,&local_res8);
    uVar18 = 1;
    if (1 < uVar8) {
      uVar18 = uVar8;
    }
    fVar23 = (float)local_res8.x;
    fVar24 = (float)local_res8.y;
    FUN_140004bc0(iVar12,iVar1,uVar22,uVar18 * uVar14 + iVar2,DAT_14002904c,DAT_14002957c,
                  DAT_140029580);
    uVar13 = 0;
    pcVar15 = &DAT_140029028;
    uVar11 = 0;
    do {
      if (DAT_140029650 <= uVar11) {
        pcVar6 = (code *)swi(3);
        (*pcVar6)();
        return;
      }
      plVar3 = *(longlong **)(DAT_140029648 + uVar11 * 8);
      if (plVar3 != (longlong *)0x0) {
        iVar1 = (int)plVar3[2];
        iVar2 = *(int *)((longlong)plVar3 + 0x14);
        iVar19 = (int)(uVar13 % uVar20) * uVar14 + local_res18;
        iVar21 = (int)(uVar13 / uVar20) * uVar14 + local_res10;
        iVar16 = 1;
        if (1 < iVar1) {
          iVar16 = iVar1;
        }
        iVar17 = 1;
        if (1 < (int)uVar14 / iVar16) {
          iVar17 = (int)uVar14 / iVar16;
        }
        iVar16 = 1;
        if (1 < iVar2) {
          iVar16 = iVar2;
        }
        iVar10 = 1;
        if (1 < (int)uVar14 / iVar16) {
          iVar10 = (int)uVar14 / iVar16;
        }
        if (iVar17 < iVar10) {
          iVar10 = iVar17;
        }
        iVar16 = 1;
        if (1 < iVar10) {
          iVar16 = iVar10;
        }
        FUN_140004550(plVar3,iVar19 + (int)(uVar14 - iVar1 * iVar16) / 2,
                      iVar21 + (int)(uVar14 - iVar2 * iVar16) / 2,iVar16,0);
        if ((((iVar19 <= (int)fVar23) && ((int)fVar23 <= (int)(iVar19 + uVar14))) &&
            (iVar21 <= (int)fVar24)) && ((int)fVar24 <= (int)(iVar21 + uVar14))) {
          DAT_140029990 = FUN_140009f00(*pcVar15);
        }
        if (*pcVar15 == '\x01') {
          local_res8.x = -0xafaf4c;
          FUN_140004940(iVar19,iVar21,uVar14,uVar14,2,0xff5050b4);
        }
      }
      uVar8 = (int)uVar13 + 1;
      uVar13 = (ulonglong)uVar8;
      uVar11 = uVar11 + 1;
      pcVar15 = pcVar15 + 1;
    } while (uVar8 < 0x16);
    FUN_140004940((DAT_140029658 % (int)uVar9) * uVar14 + local_res18,
                  (DAT_140029658 / (int)uVar9) * uVar14 + local_res10,uVar14,uVar14,DAT_140029050,
                  DAT_140029578);
    if (((DAT_14002962c == '\n') || (DAT_14002962c == '\v')) ||
       ((DAT_14002962c == '\f' || ((DAT_14002962c == '\r' || (DAT_14002962c == '\x12')))))) {
      local_res8.x = -0xaf2324;
      if (DAT_140029664 == 0) {
        local_res8.x = -0xaf2324;
      }
      else if (DAT_140029664 == 1) {
        local_res8.x = -0x2323b0;
      }
      else if (DAT_140029664 == 2) {
        local_res8.x = -0xaf8724;
      }
      else if (DAT_140029664 == 3) {
        local_res8.x = -0x23af4c;
      }
      LVar7 = local_res8.x;
      local_res8.x = -0x1000000;
      FUN_140004bc0(iVar12 + (uVar22 - 0xe),local_res20 + 4,10,10,1,0xff000000,LVar7);
    }
  }
  return;
}


// ===== FUN_140018be0 @ 140018be0 size=495

void FUN_140018be0(int param_1)

{
  undefined8 *puVar1;
  int *piVar2;
  longlong lVar3;
  code *pcVar4;
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  uint uVar7;
  ulonglong uVar8;
  longlong lVar9;
  undefined8 *puVar10;
  
  uVar7 = 0xffffffff;
  if (DAT_140029af0 != 0) {
    if ((((DAT_14002a890 == (int *)0x0) || (*(longlong *)(DAT_14002a890 + 2) == 0)) ||
        (*(longlong *)(DAT_14002a890 + 2) != DAT_14002a898)) || (DAT_14002a890 == (int *)0x0)) {
      DAT_140029af0 = 0;
      DAT_140029af4 = 0;
    }
    else {
      auVar5 = vroundps_avx(ZEXT416(DAT_140029630),1);
      auVar6 = vroundps_avx(ZEXT416(DAT_140029634),1);
      DAT_140029af4 = 1;
      DAT_140029af8 =
           (param_1 * DAT_14002a890[0xb] +
           (int)*(undefined8 *)(DAT_14002a890 + 8) * DAT_140029020 * 2) * 8 - (int)auVar5._0_4_;
      DAT_140029afc =
           ((int)((ulonglong)*(undefined8 *)(DAT_14002a890 + 8) >> 0x20) * DAT_140029020 * 0x10 -
           (int)auVar6._0_4_) + -6;
      uVar8 = FUN_14001b810(DAT_14002a890);
      DAT_140029128 = (uint)uVar8;
      if (((int)DAT_140029128 < 0) || (DAT_140029ae0 <= DAT_140029128)) {
        DAT_140029128 = 0xffffffff;
      }
      uVar7 = FUN_14000a650();
    }
  }
  puVar1 = DAT_14002a880 + DAT_14002a888;
  for (puVar10 = DAT_14002a880; puVar10 != puVar1; puVar10 = puVar10 + 1) {
    piVar2 = (int *)*puVar10;
    if ((piVar2 != (int *)0x0) && (*(longlong *)(piVar2 + 4) != 0)) {
      FUN_140017d70(piVar2,param_1);
      FUN_140017b20(piVar2,param_1);
    }
  }
  if ((((DAT_140029af0 != 0) && (DAT_14002a890 != (int *)0x0)) &&
      (*(longlong *)(DAT_14002a890 + 2) != 0)) &&
     (((*(longlong *)(DAT_14002a890 + 2) == DAT_14002a898 && (DAT_14002a890 != (int *)0x0)) &&
      ((-1 < (int)uVar7 &&
       ((lVar3 = *(longlong *)(DAT_14002a890 + 0x48), lVar3 != 0 &&
        (uVar7 < *(uint *)(lVar3 + 0x10))))))))) {
    lVar9 = (longlong)(int)uVar7;
    if ((-1 < (int)uVar7) && (lVar9 < (longlong)(ulonglong)*(uint *)(lVar3 + 0x10))) {
      if ((int)uVar7 < 0) {
        FUN_140018440(*(uint **)(*(longlong *)(lVar3 + 8) +
                                ((ulonglong)*(uint *)(lVar3 + 0x10) + lVar9) * 8));
        return;
      }
      FUN_140018440(*(uint **)(*(longlong *)(lVar3 + 8) + lVar9 * 8));
      return;
    }
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  return;
}


// ===== FUN_140018dd0 @ 140018dd0 size=4495

void FUN_140018dd0(undefined8 param_1,int param_2,double param_3)

{
  code *pcVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  longlong lVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  undefined8 uVar8;
  longlong *plVar9;
  ulonglong uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  longlong lVar14;
  longlong lVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  undefined1 *puVar19;
  ulonglong uVar20;
  int iVar21;
  uint uVar22;
  int iVar23;
  int iVar24;
  bool bVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  undefined4 local_res20;
  tagPOINT local_e8;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  uint local_d0;
  uint uStack_cc;
  ulonglong local_c8;
  int local_c0;
  int local_bc;
  uint local_b8;
  longlong local_b0;
  longlong local_a8;
  undefined8 local_a0;
  ulonglong local_98;
  
  if (DAT_14002965c != 0) {
    return;
  }
  if (DAT_140029af0 != 0) {
    return;
  }
  if (DAT_14002962c == '\0') {
    return;
  }
  local_e8.x = 0;
  local_e8.y = 0;
  local_a0 = param_1;
  uVar8 = FUN_140011060(&local_e8);
  if ((int)uVar8 == 0) {
    return;
  }
  uVar8 = 0x200000002;
  uVar22 = 3;
  if (DAT_14002962c == '\v') {
LAB_140018edd:
    local_d0 = 1;
    uStack_cc = 1;
  }
  else {
    if (DAT_14002962c != '\f') {
      if (DAT_14002962c == '\r') {
        local_d0 = 3;
        uStack_cc = 2;
        if ((DAT_140029664 == 1) || (DAT_140029664 == 3)) {
          uStack_cc = 3;
          local_d0 = 2;
        }
        goto LAB_140018ee5;
      }
      if (DAT_14002962c != '\x15') goto LAB_140018edd;
    }
    local_d0 = 2;
    uStack_cc = 2;
  }
LAB_140018ee5:
  uVar17 = uStack_cc;
  uVar13 = local_d0;
  iVar23 = param_2 * 0x10;
  local_98 = (ulonglong)uStack_cc;
  local_c0 = local_d0 * iVar23;
  local_d4 = uStack_cc * iVar23;
  fVar26 = (float)iVar23;
  auVar2 = vroundps_avx(ZEXT416((uint)((fVar26 * (float)((ulonglong)local_e8 & 0xffffffff) -
                                       (float)local_a0) + (0.5f))),1);
  iVar11 = (int)auVar2._0_4_;
  auVar2 = vroundps_avx(ZEXT416((uint)((fVar26 * (float)((ulonglong)local_e8 >> 0x20) -
                                       local_a0._4_4_) + (0.5f))),1);
  iVar21 = (int)auVar2._0_4_;
  if (DAT_14002962c == '\x01') {
    uVar18 = 0x305050dc;
    local_res20 = 0xdc7878ff;
  }
  else if ((((DAT_14002962c == '\n') || (DAT_14002962c == '\v')) || (DAT_14002962c == '\f')) ||
          ((DAT_14002962c == '\r' || (DAT_14002962c == '\x12')))) {
    uVar18 = 0x28ffb478;
    local_res20 = 0xdcffdca0;
  }
  else {
    uVar18 = 0x24ffffff;
    local_res20 = 0xb4a0ffff;
  }
  fVar27 = (0.5f);
  fVar28 = (float)local_a0;
  fVar29 = local_a0._4_4_;
  local_d8 = iVar11;
  local_bc = iVar21;
  FUN_140008090(iVar11,iVar21,local_c0,local_d4,uVar18);
  iVar12 = local_c0;
  iVar16 = local_d8;
  iVar24 = iVar21;
  if (1 < uVar17) {
    uVar20 = (ulonglong)(uStack_cc - 1);
    do {
      iVar21 = iVar23 + iVar21;
      FUN_140007ff0(iVar16,iVar21,iVar12,1,0x78ffffff);
      uVar20 = uVar20 - 1;
      iVar11 = local_d8;
      iVar24 = local_bc;
      uVar13 = local_d0;
    } while (uVar20 != 0);
  }
  iVar21 = local_d4;
  if (1 < uVar13) {
    uVar20 = (ulonglong)(uVar13 - 1);
    do {
      iVar11 = iVar23 + iVar11;
      FUN_140007ff0(iVar11,iVar24,1,iVar21,0x78ffffff);
      uVar20 = uVar20 - 1;
      uVar13 = local_d0;
    } while (uVar20 != 0);
  }
  uVar17 = DAT_140029664;
  cVar5 = DAT_14002962c;
  switch(DAT_14002962c) {
  case '\0':
  case '\x01':
    goto switchD_14001916a_caseD_0;
  default:
    plVar9 = (longlong *)FUN_1400065a0(DAT_14002962c);
    if (plVar9 != (longlong *)0x0) break;
    goto switchD_14001916a_caseD_0;
  case '\n':
    if (DAT_140029664 == 1) {
      plVar9 = (longlong *)&DAT_1400ead00;
    }
    else if (DAT_140029664 == 2) {
      plVar9 = (longlong *)&DAT_1400eadc0;
    }
    else if (DAT_140029664 == 3) {
      plVar9 = (longlong *)&DAT_1400ead60;
    }
    else {
      plVar9 = (longlong *)&DAT_1400eaca0;
    }
    break;
  case '\v':
    plVar9 = (longlong *)&DAT_1400eb680;
    break;
  case '\f':
    if (DAT_140029664 == 1) {
      plVar9 = (longlong *)&DAT_1400eb2a0;
    }
    else if (DAT_140029664 == 2) {
      plVar9 = (longlong *)&DAT_1400eb260;
    }
    else if (DAT_140029664 == 3) {
      plVar9 = (longlong *)&DAT_1400eb2e0;
    }
    else {
      plVar9 = (longlong *)&DAT_1400eb220;
    }
    break;
  case '\r':
    if (DAT_140029664 == 1) {
      plVar9 = (longlong *)&DAT_1400eb600;
    }
    else if (DAT_140029664 == 2) {
      plVar9 = (longlong *)&DAT_1400eb5c0;
    }
    else if (DAT_140029664 == 3) {
      plVar9 = (longlong *)&DAT_1400eb640;
    }
    else {
      plVar9 = (longlong *)&DAT_1400eb580;
    }
    break;
  case '\x0e':
    plVar9 = (longlong *)&DAT_1400eabe0;
    break;
  case '\x0f':
    plVar9 = (longlong *)&DAT_1400eac00;
    break;
  case '\x10':
    plVar9 = (longlong *)&DAT_1400eae40;
    break;
  case '\x11':
    plVar9 = (longlong *)&DAT_1400eae20;
    break;
  case '\x12':
    if (DAT_140029664 == 1) {
      plVar9 = (longlong *)&DAT_1400eae60;
    }
    else if (DAT_140029664 == 2) {
      plVar9 = (longlong *)&DAT_1400eaec0;
    }
    else if (DAT_140029664 == 3) {
      plVar9 = (longlong *)&DAT_1400eaea0;
    }
    else {
      plVar9 = (longlong *)&DAT_1400eae80;
    }
    break;
  case '\x13':
    plVar9 = (longlong *)&DAT_1400eb6c0;
    break;
  case '\x14':
    plVar9 = (longlong *)&DAT_1400eaba0;
    break;
  case '\x15':
    plVar9 = &DAT_1400eabc0;
  }
  iVar21 = 0;
  if (1 < *(uint *)(plVar9 + 3)) {
    iVar21 = (int)(param_3 * (6.0)) % (int)*(uint *)(plVar9 + 3);
  }
  local_dc = (local_c0 - param_2 * (int)plVar9[2]) / 2 + local_d8;
  iVar11 = (local_d4 - param_2 * *(int *)((longlong)plVar9 + 0x14)) + local_bc;
  bVar25 = DAT_140029711 != '\0';
  if (cVar5 == '\x14') {
    uVar8 = 0x100000001;
LAB_1400193de:
    uVar8 = FUN_1400052a0((ulonglong)local_e8,uVar8);
    iVar16 = (int)uVar8;
  }
  else {
    if (cVar5 == '\x15') goto LAB_1400193de;
    switch(cVar5) {
    case '\n':
      uVar22 = 1;
      break;
    case '\v':
      uVar22 = 2;
      break;
    case '\f':
      break;
    case '\r':
      uVar22 = 4;
      break;
    case '\x0e':
      uVar22 = 5;
      break;
    case '\x0f':
      uVar22 = 6;
      break;
    case '\x10':
      uVar22 = 7;
      break;
    case '\x11':
      uVar22 = 8;
      break;
    case '\x12':
      uVar22 = 9;
      break;
    case '\x13':
      uVar22 = 10;
      break;
    default:
      uVar22 = 0;
    }
    uVar8 = FUN_1400054e0((ulonglong)local_e8,(uint)bVar25,uVar22,(ulonglong)uVar17,DAT_140029660);
    iVar16 = (int)uVar8;
  }
  uVar20 = FUN_140004e70(DAT_14002962c);
  if (((int)uVar20 == 0) || (iVar16 == 0)) {
    local_e0 = 0;
    iVar16 = local_e0;
    if (0 < local_dc) {
      iVar16 = local_dc;
    }
    iVar12 = 0;
    if (0 < iVar11) {
      iVar12 = iVar11;
    }
    if (local_dc < 0) {
      local_e0 = -local_dc;
    }
    local_e0 = ((int)plVar9[2] * iVar21 + (int)plVar9[1]) * param_2 + local_e0;
    if (iVar11 < 0) {
      iVar21 = -iVar11;
    }
    else {
      iVar21 = 0;
    }
    iVar6 = (int)plVar9[2] * param_2 + local_dc;
    iVar24 = DAT_1400296d0;
    if (iVar6 < DAT_1400296d0) {
      iVar24 = iVar6;
    }
    iVar24 = iVar24 - iVar16;
    iVar7 = param_2 * *(int *)((longlong)plVar9 + 0x14) + iVar11;
    iVar6 = DAT_1400296d4;
    if (iVar7 < DAT_1400296d4) {
      iVar6 = iVar7;
    }
    if ((0 < iVar24) && (0 < iVar6 - iVar12)) {
      local_b8 = (param_2 * *(int *)((longlong)plVar9 + 0xc) + iVar21) - iVar12;
      local_b0 = (longlong)iVar16;
      local_c8 = (ulonglong)(uint)(iVar6 - iVar12);
      iVar21 = DAT_1400296d0;
      do {
        lVar4 = ((longlong *)*plVar9)[1];
        lVar15 = *(longlong *)*plVar9;
        if (0 < (longlong)iVar24) {
          puVar19 = (undefined1 *)(DAT_1400296c8 + 2 + (iVar12 * iVar21 + local_b0) * 4);
          lVar14 = (longlong)iVar24;
          iVar16 = local_e0;
          do {
            uVar22 = *(uint *)(lVar15 + (ulonglong)
                                        (uint)(((int)(local_b8 + iVar12) / param_2) * (int)lVar4) *
                                        4 + (longlong)(iVar16 / param_2) * 4);
            uVar13 = ((uVar22 >> 0x10 & 0xff) * 0xff) / 0xff;
            local_e8.x = uVar13;
            uVar20 = (ulonglong)((uVar22 >> 0x18) * 0xaf) / 0xff;
            if ((char)uVar20 != '\0') {
              uVar17 = *(uint *)(puVar19 + -2);
              uVar18 = (uint)uVar20 & 0xff;
              iVar21 = 0xff - uVar18;
              puVar19[1] = 0xff;
              puVar19[-2] = (char)((ulonglong)
                                   ((((uVar22 & 0xff) * 0xaf) / 0xff & 0xff) * uVar18 +
                                   (uVar17 & 0xff) * iVar21) / 0xff);
              puVar19[-1] = (char)((ulonglong)
                                   ((uVar17 >> 8 & 0xff) * iVar21 +
                                   (((uVar22 >> 8 & 0xff) * 0x32) / 0xff) * uVar18) / 0xff);
              *puVar19 = (char)((ulonglong)
                                ((uVar17 >> 0x10 & 0xff) * iVar21 + (uVar13 & 0xff) * uVar18) / 0xff
                               );
            }
            iVar16 = iVar16 + 1;
            puVar19 = puVar19 + 4;
            lVar14 = lVar14 + -1;
            iVar21 = DAT_1400296d0;
          } while (lVar14 != 0);
        }
        iVar12 = iVar12 + 1;
        local_c8 = local_c8 - 1;
        uVar13 = local_d0;
      } while (local_c8 != 0);
    }
  }
  else {
    iVar16 = 0;
    if (bVar25 == 1) {
      iVar12 = 0;
      if (0 < local_dc) {
        iVar12 = local_dc;
      }
      iVar24 = 0;
      if (0 < iVar11) {
        iVar24 = iVar11;
      }
      local_e0 = iVar16;
      if (local_dc < 0) {
        local_e0 = -local_dc;
      }
      local_e0 = ((int)plVar9[2] * iVar21 + (int)plVar9[1]) * param_2 + local_e0;
      if (iVar11 < 0) {
        iVar16 = -iVar11;
      }
      iVar6 = (int)plVar9[2] * param_2 + local_dc;
      iVar21 = DAT_1400296d0;
      if (iVar6 < DAT_1400296d0) {
        iVar21 = iVar6;
      }
      iVar21 = iVar21 - iVar12;
      iVar7 = param_2 * *(int *)((longlong)plVar9 + 0x14) + iVar11;
      iVar6 = DAT_1400296d4;
      if (iVar7 < DAT_1400296d4) {
        iVar6 = iVar7;
      }
      if ((0 < iVar21) && (0 < iVar6 - iVar24)) {
        iVar7 = (param_2 * *(int *)((longlong)plVar9 + 0xc) + iVar16) - iVar24;
        local_b0 = (longlong)iVar12;
        uVar20 = (ulonglong)(uint)(iVar6 - iVar24);
        local_e8.x = iVar7;
        iVar16 = DAT_1400296d0;
        do {
          lVar4 = ((longlong *)*plVar9)[1];
          lVar15 = *(longlong *)*plVar9;
          if (0 < (longlong)iVar21) {
            puVar19 = (undefined1 *)(DAT_1400296c8 + 2 + (iVar24 * iVar16 + local_b0) * 4);
            lVar14 = (longlong)iVar21;
            iVar12 = local_e0;
            do {
              uVar22 = *(uint *)(lVar15 + (ulonglong)
                                          (uint)(((iVar7 + iVar24) / param_2) * (int)lVar4) * 4 +
                                (longlong)(iVar12 / param_2) * 4);
              local_b8 = ((uVar22 >> 0x10 & 0xff) * 0x32) / 0xff;
              uVar10 = (ulonglong)((uVar22 >> 0x18) * 0xaf) / 0xff;
              if ((char)uVar10 != '\0') {
                uVar13 = *(uint *)(puVar19 + -2);
                uVar17 = (uint)uVar10 & 0xff;
                iVar16 = 0xff - uVar17;
                puVar19[1] = 0xff;
                puVar19[-2] = (char)((ulonglong)
                                     ((((uVar22 & 0xff) * 0xaf) / 0xff & 0xff) * uVar17 +
                                     (uVar13 & 0xff) * iVar16) / 0xff);
                puVar19[-1] = (char)((ulonglong)
                                     ((uVar13 >> 8 & 0xff) * iVar16 +
                                     (((uVar22 >> 8 & 0xff) * 0x32) / 0xff) * uVar17) / 0xff);
                *puVar19 = (char)((ulonglong)((uVar13 >> 0x10 & 0xff) * iVar16 + local_b8 * uVar17)
                                 / 0xff);
              }
              iVar12 = iVar12 + 1;
              puVar19 = puVar19 + 4;
              lVar14 = lVar14 + -1;
              iVar16 = DAT_1400296d0;
            } while (lVar14 != 0);
          }
          iVar24 = iVar24 + 1;
          uVar20 = uVar20 - 1;
        } while (uVar20 != 0);
        local_c8 = 0;
        uVar13 = local_d0;
      }
    }
    else {
      iVar12 = 0;
      if (0 < local_dc) {
        iVar12 = local_dc;
      }
      iVar24 = 0;
      if (0 < iVar11) {
        iVar24 = iVar11;
      }
      local_e0 = iVar16;
      if (local_dc < 0) {
        local_e0 = -local_dc;
      }
      local_e0 = ((int)plVar9[2] * iVar21 + (int)plVar9[1]) * param_2 + local_e0;
      if (iVar11 < 0) {
        iVar16 = -iVar11;
      }
      iVar6 = (int)plVar9[2] * param_2 + local_dc;
      iVar21 = DAT_1400296d0;
      if (iVar6 < DAT_1400296d0) {
        iVar21 = iVar6;
      }
      iVar21 = iVar21 - iVar12;
      iVar7 = param_2 * *(int *)((longlong)plVar9 + 0x14) + iVar11;
      iVar6 = DAT_1400296d4;
      if (iVar7 < DAT_1400296d4) {
        iVar6 = iVar7;
      }
      if ((0 < iVar21) && (0 < iVar6 - iVar24)) {
        local_b8 = (param_2 * *(int *)((longlong)plVar9 + 0xc) + iVar16) - iVar24;
        local_a8 = (longlong)iVar12;
        uVar20 = (ulonglong)(uint)(iVar6 - iVar24);
        iVar16 = DAT_1400296d0;
        do {
          lVar4 = ((longlong *)*plVar9)[1];
          lVar15 = *(longlong *)*plVar9;
          if (0 < (longlong)iVar21) {
            puVar19 = (undefined1 *)(DAT_1400296c8 + 2 + (iVar24 * iVar16 + local_a8) * 4);
            lVar14 = (longlong)iVar21;
            iVar12 = local_e0;
            do {
              uVar22 = *(uint *)(lVar15 + (ulonglong)
                                          (uint)(((int)(iVar24 + local_b8) / param_2) * (int)lVar4)
                                          * 4 + (longlong)(iVar12 / param_2) * 4);
              uVar13 = ((uVar22 >> 0x10 & 0xff) * 0xff) / 0xff;
              local_e8.x = uVar13;
              uVar10 = (ulonglong)((uVar22 >> 0x18) * 0xaf) / 0xff;
              if ((char)uVar10 != '\0') {
                uVar17 = *(uint *)(puVar19 + -2);
                uVar18 = (uint)uVar10 & 0xff;
                iVar16 = 0xff - uVar18;
                puVar19[1] = 0xff;
                puVar19[-2] = (char)((ulonglong)
                                     ((uVar17 & 0xff) * iVar16 +
                                     (((uVar22 & 0xff) * 0xaf) / 0xff & 0xff) * uVar18) / 0xff);
                puVar19[-1] = (char)((ulonglong)
                                     ((uVar17 >> 8 & 0xff) * iVar16 +
                                     (((uVar22 >> 8 & 0xff) * 0xff) / 0xff & 0xff) * uVar18) / 0xff)
                ;
                *puVar19 = (char)((ulonglong)
                                  ((uVar17 >> 0x10 & 0xff) * iVar16 + (uVar13 & 0xff) * uVar18) /
                                 0xff);
              }
              iVar12 = iVar12 + 1;
              puVar19 = puVar19 + 4;
              lVar14 = lVar14 + -1;
              iVar16 = DAT_1400296d0;
            } while (lVar14 != 0);
          }
          iVar24 = iVar24 + 1;
          uVar20 = uVar20 - 1;
        } while (uVar20 != 0);
        local_c8 = 0;
        uVar13 = local_d0;
      }
    }
  }
  uVar20 = 0;
  if (DAT_14002962c == '\x13') {
    FUN_140008090(local_dc + param_2 * -0x40,iVar11 + param_2 * -0x20,param_2 * 0x40,param_2 * 0x50,
                  0x6400ff00);
    uVar10 = (ulonglong)DAT_14002a888;
    lVar15 = DAT_14002a880;
    if (DAT_14002a888 != 0) {
      do {
        if (uVar10 <= uVar20) {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
        if (**(int **)(lVar15 + uVar20 * 8) == 10) {
          if (uVar10 <= uVar20) {
            pcVar1 = (code *)swi(3);
            (*pcVar1)();
            return;
          }
          uVar10 = *(ulonglong *)(*(longlong *)(lVar15 + uVar20 * 8) + 0x20);
          auVar2 = vroundps_avx(ZEXT416((uint)((fVar26 * (float)(uVar10 & 0xffffffff) - fVar28) +
                                              fVar27)),1);
          auVar3 = vroundps_avx(ZEXT416((uint)((fVar26 * (float)(uVar10 >> 0x20) - fVar29) + fVar27)
                                       ),1);
          FUN_140008090((int)auVar2._0_4_ + param_2 * -0x40,(int)auVar3._0_4_ + param_2 * -0x20,
                        param_2 * 0x40,param_2 * 0x50,0x6400ff00);
          uVar10 = (ulonglong)DAT_14002a888;
          lVar15 = DAT_14002a880;
        }
        uVar22 = (int)uVar20 + 1;
        uVar20 = (ulonglong)uVar22;
      } while (uVar22 < (uint)uVar10);
    }
  }
switchD_14001916a_caseD_0:
  iVar21 = local_bc;
  iVar12 = local_c0;
  iVar11 = local_d8;
  FUN_140007ff0(local_d8,local_bc,local_c0,1,local_res20);
  FUN_140007ff0(iVar11,iVar21 + -1 + local_d4,iVar12,1,local_res20);
  FUN_140007ff0(iVar11,iVar21,1,local_d4,local_res20);
  iVar16 = local_d4;
  FUN_140007ff0(iVar11 + -1 + iVar12,iVar21,1,local_d4,local_res20);
  uVar22 = DAT_140029664;
  if ((((DAT_14002962c != '\n') && (DAT_14002962c != '\v')) && (DAT_14002962c != '\f')) &&
     ((DAT_14002962c != '\r' && (DAT_14002962c != '\x12')))) {
    return;
  }
  uVar17 = (uint)local_98;
  if (iVar12 < iVar16) {
    uVar17 = uVar13;
  }
  iVar23 = uVar17 * iVar23;
  iVar24 = 2;
  if (2 < iVar23 / 10) {
    iVar24 = iVar23 / 10;
  }
  iVar6 = iVar23 / 3 + (iVar23 >> 0x1f) +
          (int)(((longlong)iVar23 / 3 + ((longlong)iVar23 >> 0x3f) & 0xffffffffU) >> 0x1f);
  iVar23 = iVar24 + 2;
  if (iVar24 + 2 < iVar6) {
    iVar23 = iVar6;
  }
  FUN_140008090(iVar24 + iVar11,iVar24 + iVar21,iVar12 + iVar24 * -2,iVar16 + iVar24 * -2,0xaffffff)
  ;
  iVar6 = iVar23;
  if (uVar22 == 0) {
    FUN_140008090((iVar12 / 2 - iVar24 / 2) + iVar11,(iVar16 - iVar23) + iVar21,iVar24,
                  iVar23 - iVar24,0xd25aebff);
    iVar21 = (iVar16 - iVar24) + iVar21;
  }
  else {
    if (uVar22 == 1) {
      FUN_140008090(iVar11,(iVar16 / 2 - iVar23 / 2) + iVar21,iVar24,iVar23,0xd25aebff);
      iVar21 = iVar21 + (iVar16 / 2 - iVar24 / 2);
      goto LAB_140019f0c;
    }
    if (uVar22 != 2) {
      if (uVar22 != 3) {
        return;
      }
      FUN_140008090((iVar12 - iVar23) + iVar11,(iVar16 / 2 - iVar24 / 2) + iVar21,iVar23,iVar24,
                    0xd25aebff);
      iVar21 = iVar21 + (iVar16 / 2 - iVar23 / 2);
      iVar11 = iVar11 + (iVar12 - iVar24);
      iVar6 = iVar24;
      iVar24 = iVar23;
      goto LAB_140019f0c;
    }
    FUN_140008090((iVar12 / 2 - iVar24 / 2) + iVar11,iVar21,iVar24,iVar23,0xd25aebff);
  }
  iVar11 = iVar11 + (iVar12 / 2 - iVar23 / 2);
LAB_140019f0c:
  FUN_140008090(iVar11,iVar21,iVar6,iVar24,0xd25aebff);
  return;
}


// ===== FUN_140019fe0 @ 140019fe0 size=1170

void FUN_140019fe0(int *param_1,longlong param_2,longlong param_3,ulonglong param_4,uint param_5,
                  undefined8 param_6,undefined8 param_7,longlong param_8,uint param_9,
                  undefined8 *param_10,uint param_11)

{
  char cVar1;
  int iVar2;
  code *pcVar3;
  byte bVar4;
  byte bVar5;
  uint uVar6;
  byte bVar7;
  ulonglong uVar8;
  longlong lVar9;
  int iVar10;
  longlong lVar11;
  undefined1 uVar12;
  uint uVar13;
  ulonglong uVar14;
  uint uVar15;
  uint *puVar16;
  undefined8 *puVar17;
  bool bVar18;
  undefined4 local_res20;
  uint local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  uint local_88;
  uint local_84;
  int local_80;
  int local_7c;
  int local_78;
  uint local_74;
  uint local_70;
  uint local_6c;
  uint local_68;
  uint local_64;
  int local_60;
  undefined8 local_58 [3];
  
  local_58[0] = 0;
  lVar9 = (param_4 & 0xffffffff) * 4;
  uVar13 = *(uint *)(&DAT_140023ee0 + lVar9);
  local_80 = *(int *)(&DAT_140023ea0 + lVar9);
  local_64 = *(uint *)(&DAT_140023f00 + lVar9);
  local_60 = *(int *)(&DAT_140023ec0 + lVar9);
  iVar2 = param_1[3];
  uVar14 = (ulonglong)(*param_1 + -1 + (uVar13 - local_80)) / (ulonglong)uVar13;
  local_74 = (uint)uVar14;
  local_68 = ((local_64 - 1) + (param_1[1] - local_60)) / local_64;
  uVar15 = *(byte *)(param_1 + 2) * local_74 * param_5 + 7 >> 3;
  puVar17 = local_58;
  if (param_10 != (undefined8 *)0x0) {
    puVar17 = param_10;
  }
  local_84 = 0;
  uVar6 = local_98;
  local_70 = uVar13;
  local_6c = uVar15;
  if (local_68 != 0) {
    do {
      local_78 = local_64 * local_84 + local_60;
      lVar9 = (ulonglong)(local_84 * uVar15) + param_2;
      local_88 = 0;
      if ((int)uVar14 != 0) {
        do {
          bVar4 = 1;
          local_7c = uVar13 * local_88 + local_80;
          if (param_5 != 0) {
            cVar1 = (char)param_1[2];
            puVar16 = &local_98;
            uVar13 = local_88 * param_5;
            lVar11 = (longlong)puVar17 - (longlong)&local_98;
            iVar10 = -uVar13;
            do {
              bVar5 = (byte)uVar13;
              if (cVar1 == '\x01') {
                bVar7 = *(byte *)((ulonglong)(uVar13 >> 3) + lVar9) >> (7 - (bVar5 & 7) & 0x1f) & 1;
                bVar5 = *(byte *)((longlong)puVar16 + lVar11);
                if (iVar2 == 0) {
                  bVar7 = -bVar7;
                }
                *(byte *)puVar16 = bVar7;
                bVar18 = (bVar7 != 0) == (bool)bVar5;
                goto LAB_14001a2a2;
              }
              if (cVar1 == '\x02') {
                bVar7 = *(byte *)((ulonglong)(uVar13 >> 2) + lVar9) >>
                        (('\x03' - (bVar5 & 3)) * '\x02' & 0x1f) & 3;
                bVar4 = bVar4 & bVar7 == *(byte *)((longlong)puVar16 + lVar11);
                bVar5 = bVar7 << 4;
                if (iVar2 != 0) {
                  bVar5 = 0;
                }
                *(byte *)puVar16 = bVar5 | bVar7;
              }
              else if (cVar1 == '\x04') {
                bVar7 = *(byte *)((ulonglong)(uVar13 >> 1) + lVar9) >> ((1 - (bVar5 & 1) & 7) << 2);
                bVar4 = bVar4 & (bVar7 & 0xf) == *(byte *)((longlong)puVar16 + lVar11);
                bVar5 = bVar7 & 0xf ^ bVar7 << 4;
                if (iVar2 != 0) {
                  bVar5 = bVar7 & 0xf;
                }
                *(byte *)puVar16 = bVar5;
              }
              else {
                if (cVar1 == '\b') {
                  bVar18 = *(byte *)((ulonglong)uVar13 + lVar9) ==
                           *(byte *)((longlong)puVar16 + lVar11);
                  *(byte *)puVar16 = *(byte *)((ulonglong)uVar13 + lVar9);
                }
                else {
                  if (cVar1 != '\x10') goto LAB_14001a2a5;
                  uVar15 = (iVar10 + uVar13) * 2;
                  bVar5 = *(byte *)((ulonglong)(uVar13 * 2) + lVar9);
                  *(byte *)puVar16 = bVar5;
                  if ((bVar5 != *(byte *)((ulonglong)uVar15 + (longlong)puVar17)) ||
                     (bVar18 = true,
                     *(char *)((ulonglong)(uVar13 * 2 + 1) + lVar9) !=
                     *(char *)((ulonglong)(uVar15 + 1) + (longlong)puVar17))) {
                    bVar18 = false;
                  }
                }
LAB_14001a2a2:
                bVar4 = bVar4 & bVar18;
              }
LAB_14001a2a5:
              uVar13 = uVar13 + 1;
              puVar16 = (uint *)((longlong)puVar16 + 1);
              uVar6 = local_98;
            } while (iVar10 + uVar13 < param_5);
          }
          uVar14 = (ulonglong)(uint)(local_78 * *param_1 + local_7c);
          if (param_1[3] == 0) {
            iVar10 = (param_10 != (undefined8 *)0x0) + param_5;
            if (param_10 != (undefined8 *)0x0) {
              *(byte *)((longlong)&local_98 + (ulonglong)(iVar10 - 1)) = -bVar4;
              uVar6 = local_98;
            }
            uVar12 = (undefined1)uVar6;
            if (iVar10 == 1) {
              local_8c = CONCAT13(0xff,CONCAT12(uVar12,CONCAT11(uVar12,uVar12)));
              local_res20 = local_8c;
              goto LAB_14001a400;
            }
            if (iVar10 == 2) {
              local_90._3_1_ = (undefined1)(local_98 >> 8);
              local_90._0_3_ = CONCAT12(uVar12,CONCAT11(uVar12,uVar12));
              local_res20 = local_90;
              goto LAB_14001a400;
            }
            if (iVar10 == 3) {
              local_94 = CONCAT13(0xff,CONCAT21((short)(local_98 >> 8),uVar12));
              local_res20 = local_94;
              goto LAB_14001a400;
            }
            if (iVar10 == 4) {
              *(uint *)(param_3 + uVar14 * 4) = uVar6;
            }
          }
          else {
            if (param_9 <= (uVar6 & 0xff)) {
              FUN_140002010("Palette index was out of range");
              pcVar3 = (code *)swi(3);
              (*pcVar3)();
              return;
            }
            uVar8 = (ulonglong)(uVar6 & 0xff);
            lVar11 = param_8 + uVar8 * 2;
            if ((uVar6 & 0xff) < param_11) {
              uVar12 = *(undefined1 *)(uVar8 + (longlong)param_10);
            }
            else {
              uVar12 = 0xff;
            }
            local_res20 = CONCAT13(uVar12,CONCAT12(*(undefined1 *)(uVar8 + 2 + lVar11),
                                                   *(undefined2 *)(uVar8 + lVar11)));
LAB_14001a400:
            *(undefined4 *)(param_3 + uVar14 * 4) = local_res20;
          }
          uVar14 = (ulonglong)local_74;
          local_88 = local_88 + 1;
          uVar13 = local_70;
          uVar15 = local_6c;
        } while (local_88 < local_74);
      }
      local_84 = local_84 + 1;
    } while (local_84 < local_68);
  }
  return;
}


// ===== FUN_14001a480 @ 14001a480 size=99

void FUN_14001a480(void)

{
  uint uVar1;
  ulonglong uVar2;
  
  uVar1 = 0;
  DAT_1400299ac = 0;
  if (DAT_1400299a8 * DAT_140029a88._4_4_ * (int)DAT_140029a88 != 0) {
    do {
      uVar2 = (ulonglong)uVar1;
      uVar1 = uVar1 + 1;
      *(undefined4 *)(DAT_140029a98 + uVar2 * 4) = 0;
      *(undefined1 *)(uVar2 + DAT_140029aa0) = 0;
    } while (uVar1 < (uint)(DAT_1400299a8 * DAT_140029a88._4_4_ * (int)DAT_140029a88));
  }
  return;
}


// ===== FUN_14001a4f0 @ 14001a4f0 size=285

void FUN_14001a4f0(ulonglong param_1)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  ulonglong uVar5;
  
  uVar1 = (uint)DAT_140029a88;
  uVar3 = (uint)(param_1 >> 0x20);
  uVar4 = (uint)param_1;
  uVar5 = (ulonglong)(uVar3 * (uint)DAT_140029a88 + uVar4);
  *(undefined2 *)(&DAT_14004a9f0 + uVar5 * 2) = 0;
  *(undefined2 *)(&DAT_14006a9f0 + uVar5 * 2) = 0;
  *(undefined2 *)(&DAT_14008a9f0 + uVar5 * 2) = 0;
  if ((uVar4 < uVar1) && (uVar3 < DAT_140029a88._4_4_)) {
    cVar2 = *(char *)(uVar5 + DAT_140029a90);
  }
  else {
    cVar2 = '\0';
  }
  if (cVar2 == '\x02') {
    uVar5 = FUN_140002310(param_1);
    *(short *)(&DAT_14004a9f0 + (ulonglong)(uVar3 * (uint)DAT_140029a88 + uVar4) * 2) =
         (short)(int)((float)uVar5 * (1.5f)) + 10;
  }
  else {
    if (cVar2 == '\x03') {
      uVar5 = FUN_140002310(param_1);
      *(short *)(&DAT_14006a9f0 + (ulonglong)(uVar3 * (uint)DAT_140029a88 + uVar4) * 2) =
           (short)(int)(float)uVar5 + 10;
      return;
    }
    if (cVar2 == '\x04') {
      uVar5 = FUN_140002310(param_1);
      *(short *)(&DAT_14008a9f0 + (ulonglong)(uVar3 * (uint)DAT_140029a88 + uVar4) * 2) =
           (short)(int)((float)uVar5 * (0.5f)) + 0x10;
      return;
    }
  }
  return;
}


// ===== FUN_14001a610 @ 14001a610 size=723

undefined8 * FUN_14001a610(undefined8 *param_1,undefined8 *param_2,undefined8 param_3,int param_4)

{
  byte bVar1;
  byte bVar2;
  undefined8 uVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  byte bVar7;
  int iVar8;
  
  bVar7 = 0;
  if (param_4 == 0) {
    bVar7 = *(byte *)(param_2 + 1);
    uVar3 = *param_2;
    goto LAB_14001a8c7;
  }
  iVar6 = (int)((ulonglong)param_3 >> 0x20);
  if (param_4 == 1) {
    bVar1 = *(byte *)(param_2 + 1);
    bVar2 = (bVar1 & 1) << 3;
    bVar7 = bVar2 | 4;
    if ((bVar1 & 2) == 0) {
      bVar7 = bVar2;
    }
    bVar2 = bVar7 | 1;
    if ((bVar1 & 4) == 0) {
      bVar2 = bVar7;
    }
    bVar7 = bVar2 | 2;
    if ((bVar1 & 8) == 0) {
      bVar7 = bVar2;
    }
    bVar2 = bVar7 | 0x80;
    if ((bVar1 & 0x10) == 0) {
      bVar2 = bVar7;
    }
    bVar7 = bVar2 | 0x40;
    if ((bVar1 & 0x20) == 0) {
      bVar7 = bVar2;
    }
    bVar2 = bVar7 | 0x10;
    if ((bVar1 & 0x40) == 0) {
      bVar2 = bVar7;
    }
    uVar3 = *param_2;
    bVar7 = bVar2 | 0x20;
    if (-1 < (char)bVar1) {
      bVar7 = bVar2;
    }
    iVar5 = (int)((ulonglong)uVar3 >> 0x20);
LAB_14001a8ac:
    uVar3 = CONCAT44((int)uVar3,(iVar6 - iVar5) + -1);
  }
  else {
    if (param_4 == 2) {
      bVar1 = *(byte *)(param_2 + 1);
      bVar7 = (bVar1 & 1) * '\x02';
      bVar2 = bVar7 | 1;
      if ((bVar1 & 2) == 0) {
        bVar2 = bVar7;
      }
      bVar7 = bVar2 | 8;
      if ((bVar1 & 4) == 0) {
        bVar7 = bVar2;
      }
      bVar2 = bVar7 | 4;
      if ((bVar1 & 8) == 0) {
        bVar2 = bVar7;
      }
      bVar7 = bVar2 | 0x20;
      if ((bVar1 & 0x10) == 0) {
        bVar7 = bVar2;
      }
      bVar2 = bVar7 | 0x10;
      if ((bVar1 & 0x20) == 0) {
        bVar2 = bVar7;
      }
      bVar4 = bVar2 | 0x80;
      if ((bVar1 & 0x40) == 0) {
        bVar4 = bVar2;
      }
      iVar8 = (int)*param_2;
      bVar7 = bVar4 | 0x40;
      if (-1 < (char)bVar1) {
        bVar7 = bVar4;
      }
      iVar5 = (int)((ulonglong)*param_2 >> 0x20);
LAB_14001a7e7:
      uVar3 = CONCAT44((iVar6 - iVar5) + -1,((int)param_3 - iVar8) + -1);
      goto LAB_14001a8c7;
    }
    if (param_4 == 3) {
      bVar1 = *(byte *)(param_2 + 1);
      bVar2 = (bVar1 & 1) << 2;
      bVar7 = bVar2 | 8;
      if ((bVar1 & 2) == 0) {
        bVar7 = bVar2;
      }
      bVar2 = bVar7 | 2;
      if ((bVar1 & 4) == 0) {
        bVar2 = bVar7;
      }
      bVar7 = bVar2 | 1;
      if ((bVar1 & 8) == 0) {
        bVar7 = bVar2;
      }
      bVar2 = bVar7 | 0x40;
      if ((bVar1 & 0x10) == 0) {
        bVar2 = bVar7;
      }
      bVar4 = bVar2 | 0x80;
      if ((bVar1 & 0x20) == 0) {
        bVar4 = bVar2;
      }
      bVar7 = bVar4 | 0x20;
      if ((bVar1 & 0x40) == 0) {
        bVar7 = bVar4;
      }
      if (-1 < (char)bVar1) goto LAB_14001a6f6;
      uVar3 = *param_2;
      bVar7 = bVar7 | 0x10;
      iVar8 = (int)uVar3;
    }
    else {
LAB_14001a6f6:
      uVar3 = *param_2;
      iVar8 = (int)uVar3;
      iVar5 = (int)((ulonglong)uVar3 >> 0x20);
      if (param_4 == 1) goto LAB_14001a8ac;
      if (param_4 == 2) goto LAB_14001a7e7;
      if (param_4 != 3) goto LAB_14001a8c7;
    }
    uVar3 = CONCAT44(((int)param_3 - iVar8) + -1,(int)((ulonglong)uVar3 >> 0x20));
  }
LAB_14001a8c7:
  *param_1 = uVar3;
  *(byte *)(param_1 + 1) = bVar7;
  return param_1;
}


// ===== FUN_14001a8f0 @ 14001a8f0 size=2789

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_14001a8f0(void)

{
  code *pcVar1;
  undefined1 auVar2 [16];
  undefined8 uVar3;
  DWORD DVar4;
  int iVar5;
  undefined8 uVar6;
  undefined *puVar7;
  longlong lVar8;
  uint uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  undefined1 *puVar12;
  longlong *plVar13;
  undefined1 *puVar14;
  longlong lVar15;
  char *pcVar16;
  undefined *puVar17;
  bool bVar18;
  double dVar19;
  undefined1 auVar20 [16];
  undefined1 auVar21 [16];
  undefined1 auVar22 [64];
  float fVar23;
  undefined1 auVar24 [64];
  float fVar25;
  undefined1 auVar26 [64];
  undefined1 auVar27 [64];
  undefined1 auVar28 [64];
  undefined1 auVar29 [16];
  undefined1 auVar30 [64];
  undefined1 auVar31 [64];
  tagPOINT local_res8;
  char *local_d8;
  undefined8 local_d0;
  undefined1 local_c8 [32];
  undefined1 local_a8 [16];
  
  timeBeginPeriod(1);
  uVar6 = FUN_14000c710(0x3c0,0x21c,FUN_14000d950,FUN_1400105e0);
  if ((char)uVar6 == '\0') {
    local_d0 = 0x12;
    local_d8 = "Window init failed";
    FUN_140002030(&local_d8);
    pcVar1 = (code *)swi(3);
    uVar6 = (*pcVar1)();
    return uVar6;
  }
  DAT_140029620 = FUN_1400066d0();
  FUN_14000dd80();
  local_d0 = 0x1b;
  local_d8 = "./resources/sounds/bees.wav";
  FUN_14000fd80((undefined1 (*) [16])&DAT_14002a8c0,(longlong *)&local_d8,(0.5f));
  local_d0 = 0x1e;
  local_d8 = "./resources/sounds/pickaxe.wav";
  FUN_14000fd80((undefined1 (*) [16])&DAT_14002a8d8,(longlong *)&local_d8,(1f));
  uVar11 = 0;
  DAT_140029978 =
       CreateThread((LPSECURITY_ATTRIBUTES)0x0,0x10000,FUN_140003a40,(LPVOID)0x0,0,(LPDWORD)0x0);
  if (DAT_140029978 == (HANDLE)0x0) {
    DVar4 = GetLastError();
    local_d0 = 0x27;
    local_d8 = "Failed to create audio thread, code: %\n";
    FUN_140001400((longlong *)&local_d8,DVar4);
    return 1;
  }
  FUN_14000c160();
  FUN_14000bcf0();
  DAT_140029a88._0_4_ = 0x40;
  DAT_140029a88._4_4_ = 0x40;
  DAT_1400299a8 = 2;
  DAT_140029a90 = (undefined1 *)(DAT_140029878 + DAT_140029888);
  uVar10 = DAT_140029888 + 0x1003 & 0xfffffffffffffffc;
  DAT_140029ac8 = uVar10 + DAT_140029878;
  do {
    DAT_140029aa8 = rdrand();
    bVar18 = (bool)rdrandIsValid();
  } while (!bVar18);
  do {
    DAT_140029ab0 = rdrand();
    bVar18 = (bool)rdrandIsValid();
  } while (!bVar18);
  do {
    DAT_140029ab8 = rdrand();
    bVar18 = (bool)rdrandIsValid();
  } while (!bVar18);
  do {
    DAT_140029ac0 = rdrand();
    bVar18 = (bool)rdrandIsValid();
  } while (!bVar18);
  DAT_140029a98 = uVar10 + 0x40000 + DAT_140029878;
  DAT_140029888 = uVar10 + 0x4a000;
  DAT_140029aa0 = DAT_140029878 + 0x8000 + uVar10 + 0x40000;
  FUN_1400200d0(DAT_140029a90,1,0x1000);
  DAT_1400299ac = 0;
  uVar10 = uVar11;
  if (DAT_1400299a8 * DAT_140029a88._4_4_ * (uint)DAT_140029a88 != 0) {
    do {
      uVar9 = (int)uVar10 + 1;
      *(undefined4 *)(DAT_140029a98 + uVar10 * 4) = 0;
      *(undefined1 *)(uVar10 + DAT_140029aa0) = 0;
      uVar10 = (ulonglong)uVar9;
    } while (uVar9 < DAT_1400299a8 * DAT_140029a88._4_4_ * (uint)DAT_140029a88);
  }
  _DAT_14002a838 = &DAT_140029878;
  _DAT_140029a48 = &DAT_1400eaa40;
  _DAT_140029a40 = &DAT_1400eaa20;
  _DAT_140029a50 = &DAT_1400eaa60;
  DAT_14002a848 = &DAT_140029878;
  _DAT_140029a58 = &DAT_1400eaa80;
  DAT_14002a860 = &DAT_140029878;
  _DAT_140029a60 = &DAT_1400eaaa0;
  _DAT_140029a68 = &DAT_1400eaac0;
  _DAT_140029a70 = &DAT_1400eaae0;
  _DAT_140029a78 = &DAT_1400eab00;
  _DAT_140029a80 = &DAT_1400eab20;
  DAT_14002a878 = &DAT_140029878;
  DAT_14002a858 = 0;
  DAT_14002a870 = 0;
  DAT_14002a888 = 0;
  uVar10 = uVar11;
  if (DAT_14002a874 == 0) {
    if ((DAT_14002a868 == (undefined1 *)0x0) ||
       (puVar14 = DAT_14002a868, DAT_14002a868 != (undefined1 *)(DAT_140029888 + DAT_140029878))) {
      DAT_140029888 = DAT_140029888 + 7 & 0xfffffffffffffff8;
      puVar14 = (undefined1 *)(DAT_140029878 + DAT_140029888);
      if (DAT_14002a868 != (undefined1 *)0x0) {
        puVar12 = puVar14;
        for (lVar15 = 0; lVar15 != 0; lVar15 = lVar15 + -1) {
          *puVar12 = *DAT_14002a868;
          DAT_14002a868 = DAT_14002a868 + 1;
          puVar12 = puVar12 + 1;
        }
        uVar10 = (ulonglong)DAT_14002a870;
      }
    }
    DAT_140029888 = DAT_140029888 + 0x40;
    DAT_14002a874 = 8;
    DAT_14002a868 = puVar14;
  }
  pcVar16 = &DAT_140029028;
  lVar15 = 0xb;
  *(undefined8 *)(DAT_14002a868 + uVar10 * 8) = 0;
  DAT_14002a870 = DAT_14002a870 + 1;
  DAT_140029140 = 1;
  _DAT_14002a398 = 0;
  DAT_140029650 = 0;
  do {
    if (*pcVar16 == '\x01') {
      puVar17 = &DAT_1400eaa20;
    }
    else {
      puVar17 = FUN_1400065a0(*pcVar16);
    }
    puVar14 = DAT_140029648;
    if ((uint)uVar11 == DAT_140029654) {
      uVar9 = 8;
      if (8 < DAT_140029654 * 2) {
        uVar9 = DAT_140029654 * 2;
      }
      if (DAT_140029654 < uVar9) {
        lVar8 = (ulonglong)DAT_140029654 * 8;
        plVar13 = &DAT_140029878;
        if (DAT_140029640 != (longlong *)0x0) {
          plVar13 = DAT_140029640;
        }
        if ((DAT_140029648 == (undefined1 *)0x0) ||
           (DAT_140029648 + lVar8 != (undefined1 *)(*plVar13 + plVar13[2]))) {
          bVar18 = uVar9 <= DAT_140029654;
          puVar14 = (undefined1 *)0x0;
          DAT_140029654 = uVar9;
          if (bVar18) goto LAB_14001add7;
          uVar11 = plVar13[2] + 7U & 0xfffffffffffffff8;
          puVar14 = (undefined1 *)(*plVar13 + uVar11);
          plVar13[2] = uVar11;
          puVar12 = puVar14;
          if (DAT_140029648 != (undefined1 *)0x0) {
            for (; lVar8 != 0; lVar8 = lVar8 + -1) {
              *puVar12 = *DAT_140029648;
              DAT_140029648 = DAT_140029648 + 1;
              puVar12 = puVar12 + 1;
            }
          }
          plVar13[2] = plVar13[2] + (ulonglong)uVar9 * 8;
        }
        else {
          plVar13[2] = plVar13[2] + (ulonglong)(uVar9 - DAT_140029654) * 8;
        }
        uVar11 = (ulonglong)DAT_140029650;
        DAT_140029654 = uVar9;
      }
    }
LAB_14001add7:
    DAT_140029648 = puVar14;
    puVar7 = &DAT_1400eaa20;
    *(undefined **)(DAT_140029648 + uVar11 * 8) = puVar17;
    uVar9 = DAT_140029650 + 1;
    DAT_140029650 = uVar9;
    if (pcVar16[1] != '\x01') {
      puVar7 = FUN_1400065a0(pcVar16[1]);
    }
    puVar14 = DAT_140029648;
    if (uVar9 == DAT_140029654) {
      uVar11 = 8;
      if (8 < DAT_140029654 * 2) {
        uVar11 = (ulonglong)(DAT_140029654 * 2);
      }
      uVar9 = (uint)uVar11;
      if (DAT_140029654 < uVar9) {
        lVar8 = (ulonglong)DAT_140029654 * 8;
        plVar13 = &DAT_140029878;
        if (DAT_140029640 != (longlong *)0x0) {
          plVar13 = DAT_140029640;
        }
        if ((DAT_140029648 == (undefined1 *)0x0) ||
           (DAT_140029648 + lVar8 != (undefined1 *)(*plVar13 + plVar13[2]))) {
          bVar18 = DAT_140029654 < uVar9;
          puVar14 = (undefined1 *)0x0;
          DAT_140029654 = uVar9;
          if (bVar18) {
            uVar10 = plVar13[2] + 7U & 0xfffffffffffffff8;
            plVar13[2] = uVar10;
            puVar14 = (undefined1 *)(*plVar13 + uVar10);
            puVar12 = puVar14;
            if (DAT_140029648 != (undefined1 *)0x0) {
              for (; lVar8 != 0; lVar8 = lVar8 + -1) {
                *puVar12 = *DAT_140029648;
                DAT_140029648 = DAT_140029648 + 1;
                puVar12 = puVar12 + 1;
              }
            }
            plVar13[2] = plVar13[2] + uVar11 * 8;
          }
        }
        else {
          plVar13[2] = plVar13[2] + (ulonglong)(uVar9 - DAT_140029654) * 8;
          DAT_140029654 = uVar9;
        }
      }
    }
    DAT_140029648 = puVar14;
    pcVar16 = pcVar16 + 2;
    *(undefined **)(DAT_140029648 + (ulonglong)DAT_140029650 * 8) = puVar7;
    DAT_140029650 = DAT_140029650 + 1;
    uVar11 = (ulonglong)DAT_140029650;
    lVar15 = lVar15 + -1;
    if (lVar15 == 0) {
      DAT_14002962c = DAT_140029028;
      DAT_140029658 = 0;
      DAT_140029660 = 0;
      DAT_140029664 = 0;
      DAT_14002965c = 0;
      DAT_140029020 = 4;
      if ((uint)DAT_140029a88 < 3) {
        local_res8.x = 0;
      }
      else {
        local_res8.x = (uint)DAT_140029a88 - 2;
        if (8 < (uint)local_res8.x) {
          local_res8.x = 8;
        }
      }
      local_res8.y = DAT_140029a88._4_4_ >> 1;
      DAT_140029638 = local_res8;
      FUN_14000b290((ulonglong)local_res8);
      FUN_1400056b0((ulonglong)DAT_140029638);
      ShowWindow(DAT_140029680,10);
      if (DAT_1400296d8 == 0) {
        auVar22 = ZEXT464((1000f));
        auVar24 = ZEXT464((20f));
        auVar26 = ZEXT464((500f));
        auVar27 = ZEXT464((5f));
        auVar28 = ZEXT464((0.100000001f));
        auVar30 = ZEXT464((-250f));
        auVar31 = ZEXT464((250f));
        do {
          uVar3 = DAT_140029868;
          uVar6 = DAT_140029860;
          DAT_140029860 = DAT_140029848;
          DAT_140029868 = DAT_140029850;
          local_c8._0_8_ = (HWND)0x0;
          local_c8._8_8_ = 0;
          local_c8._16_8_ = 0;
          local_c8._24_8_ = 0;
          local_a8 = (undefined1  [16])0x0;
          _DAT_140029870 = DAT_140029858;
          DAT_140029848 = uVar6;
          DAT_140029850 = uVar3;
          DAT_140029858 = 0;
          auVar22 = ZEXT1664(auVar22._0_16_);
          auVar24 = ZEXT1664(auVar24._0_16_);
          auVar26 = ZEXT1664(auVar26._0_16_);
          auVar27 = ZEXT1664(auVar27._0_16_);
          auVar28 = ZEXT1664(auVar28._0_16_);
          auVar30 = ZEXT1664(auVar30._0_16_);
          auVar31 = ZEXT1664(auVar31._0_16_);
          iVar5 = PeekMessageA((LPMSG)local_c8,(HWND)0x0,0,0,1);
          while (iVar5 != 0) {
            TranslateMessage((MSG *)local_c8);
            DispatchMessageA((MSG *)local_c8);
            iVar5 = PeekMessageA((LPMSG)local_c8,(HWND)0x0,0,0,1);
          }
          dVar19 = FUN_1400066d0();
          auVar20._0_4_ = (float)(dVar19 - DAT_140029620);
          auVar20._4_4_ = (int)((ulonglong)(dVar19 - DAT_140029620) >> 0x20);
          auVar20._8_8_ = 0;
          auVar20 = vminss_avx(auVar20,auVar28._0_16_);
          DAT_140029628 = auVar20._0_4_;
          FUN_14001ebb0(DAT_140029628);
          FUN_140003c20(DAT_140029628);
          FUN_14001e410((ulonglong)(uint)DAT_140029628);
          FUN_14001efa0();
          if (0x13 < DAT_140029984) {
            DAT_140029988 = auVar27._0_4_ * DAT_140029628 + DAT_140029988;
            DAT_14002998c = 1;
          }
          local_res8.x = 0;
          local_res8.y = 0;
          GetCursorPos(&local_res8);
          ScreenToClient(DAT_140029680,&local_res8);
          if (DAT_1400296ec == 0) {
            fVar23 = auVar24._0_4_;
            fVar25 = auVar26._0_4_;
            if ((float)local_res8.x < fVar23) {
              DAT_140029630 = DAT_140029630 - DAT_140029628 * fVar25;
            }
            if ((float)DAT_1400296d0 - fVar23 < (float)local_res8.x) {
              DAT_140029630 = DAT_140029630 + DAT_140029628 * fVar25;
            }
            auVar21 = ZEXT416((uint)DAT_140029630);
            if ((float)local_res8.y < fVar23) {
              DAT_140029634 = DAT_140029634 - DAT_140029628 * fVar25;
            }
            auVar20 = ZEXT416((uint)DAT_140029634);
            if ((float)DAT_1400296d4 - fVar23 < (float)local_res8.y) {
              auVar20 = ZEXT416((uint)(DAT_140029634 + DAT_140029628 * fVar25));
            }
          }
          else {
            auVar20 = ZEXT416((uint)DAT_140029634);
            auVar21 = ZEXT416((uint)DAT_140029630);
          }
          fVar23 = auVar22._0_4_;
          if (DAT_140029757 != '\0') {
            auVar20 = ZEXT416((uint)(auVar20._0_4_ - DAT_140029628 * fVar23));
          }
          if (DAT_140029741 != '\0') {
            auVar21 = ZEXT416((uint)(auVar21._0_4_ - DAT_140029628 * fVar23));
          }
          if (DAT_140029753 != '\0') {
            auVar20 = ZEXT416((uint)(auVar20._0_4_ + DAT_140029628 * fVar23));
          }
          if (DAT_140029744 != '\0') {
            auVar21 = ZEXT416((uint)(auVar21._0_4_ + DAT_140029628 * fVar23));
          }
          auVar29 = auVar30._0_16_;
          auVar2 = vmaxss_avx(ZEXT416((uint)((float)(int)((uint)DAT_140029a88 * DAT_140029020 * 0x10
                                                         - DAT_1400296d0) + auVar31._0_4_)),auVar29)
          ;
          auVar21 = vmaxss_avx(auVar29,auVar21);
          auVar21 = vminss_avx(auVar2,auVar21);
          DAT_140029630 = auVar21._0_4_;
          auVar21 = vmaxss_avx(ZEXT416((uint)((float)(int)(DAT_140029a88._4_4_ * DAT_140029020 *
                                                           0x10 - DAT_1400296d4) + auVar31._0_4_)),
                               auVar29);
          auVar20 = vmaxss_avx(auVar29,auVar20);
          auVar20 = vminss_avx(auVar21,auVar20);
          DAT_140029634 = auVar20._0_4_;
          FUN_1400150c0();
          InvalidateRect(DAT_140029680,(RECT *)0x0,0);
          UpdateWindow(DAT_140029680);
        } while (DAT_1400296d8 == 0);
      }
      DAT_140029974 = 1;
      DVar4 = WaitForSingleObject(DAT_140029978,0xffffffff);
      if (DVar4 == 0xffffffff) {
        DVar4 = GetLastError();
        local_d0 = 0x26;
        local_d8 = "Failed to join audio thread, code:  %\n";
        FUN_140001400((longlong *)&local_d8,DVar4);
      }
      else {
        CloseHandle(DAT_140029978);
      }
      DestroyWindow(DAT_140029680);
      timeEndPeriod(1);
      return 0;
    }
  } while( true );
}


// ===== FUN_14001b3e0 @ 14001b3e0 size=405

void FUN_14001b3e0(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar5 = 0;
  uVar7 = DAT_140029a88._4_4_;
  uVar1 = (uint)DAT_140029a88;
  if (DAT_140029a88._4_4_ != 0) {
    do {
      uVar3 = uVar5 >> 1 ^ *param_1 ^ 0xa511e9b3;
      uVar3 = (uVar3 >> 0x10 ^ uVar3) * 0x45d9f3b;
      uVar4 = (uVar3 >> 0x10 ^ uVar3) * 0x45d9f3b;
      uVar4 = uVar4 >> 0x10 ^ uVar4;
      uVar2 = (uVar4 & 1) + 3;
      uVar3 = uVar1;
      if (uVar2 < uVar1) {
        uVar3 = uVar2;
      }
      uVar2 = uVar1;
      if (uVar3 + 1 < uVar1) {
        uVar2 = uVar3 + 1;
      }
      uVar6 = (uVar4 >> 5 & 1) + ((uVar4 >> 10 & 1) != 0) + 1 + uVar2;
      uVar4 = uVar1;
      if (uVar6 < uVar1) {
        uVar4 = uVar6;
      }
      uVar6 = 0;
      if (uVar1 != 0) {
        do {
          if (uVar6 < uVar3) {
            if ((uVar6 < uVar1) && (uVar5 < uVar7)) {
              *(undefined1 *)((ulonglong)(uVar5 * uVar1 + uVar6) + DAT_140029a90) = 7;
              uVar7 = DAT_140029a88._4_4_;
              uVar1 = (uint)DAT_140029a88;
            }
          }
          else if (uVar6 < uVar2) {
            if ((uVar6 < uVar1) && (uVar5 < uVar7)) {
              *(undefined1 *)((ulonglong)(uVar5 * uVar1 + uVar6) + DAT_140029a90) = 6;
            }
            FUN_140012d40(CONCAT44(uVar5,uVar6));
            uVar7 = DAT_140029a88._4_4_;
            uVar1 = (uint)DAT_140029a88;
          }
          else if (uVar6 < uVar4) {
            if ((uVar6 < uVar1) && (uVar5 < uVar7)) {
              *(undefined1 *)((ulonglong)(uVar5 * uVar1 + uVar6) + DAT_140029a90) = 5;
              uVar7 = DAT_140029a88._4_4_;
              uVar1 = (uint)DAT_140029a88;
            }
          }
          else if ((uVar6 < uVar1) && (uVar5 < uVar7)) {
            *(undefined1 *)((ulonglong)(uVar5 * uVar1 + uVar6) + DAT_140029a90) = 1;
            uVar7 = DAT_140029a88._4_4_;
            uVar1 = (uint)DAT_140029a88;
          }
          uVar6 = uVar6 + 1;
        } while (uVar6 < uVar1);
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar7);
  }
  return;
}


// ===== FUN_14001b580 @ 14001b580 size=496

void FUN_14001b580(uint *param_1,longlong param_2,undefined8 param_3)

{
  ulonglong uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  ulonglong uVar7;
  int iVar8;
  
  uVar6 = (int)param_3 + 5;
  uVar7 = (ulonglong)uVar6;
  if ((int)uVar6 < 0) {
    uVar7 = 0;
  }
  iVar3 = (int)((ulonglong)param_3 >> 0x20);
  uVar6 = iVar3 - 2;
  if ((int)uVar6 < 0) {
    uVar6 = 0;
  }
  if ((int)(DAT_140029a88._4_4_ - 1U) < (int)uVar6) {
    uVar6 = DAT_140029a88._4_4_ - 1U;
  }
  uVar1 = uVar7;
  if ((int)((int)DAT_140029a88 - 1U) < (int)uVar7) {
    uVar1 = (ulonglong)((int)DAT_140029a88 - 1U);
  }
  FUN_14001d610((longlong)param_1,param_2,(ulonglong)uVar6 << 0x20 | uVar1,2,7,*param_1 ^ 0x11111111
                ,0,1);
  uVar6 = iVar3 + 2;
  if ((int)uVar6 < 0) {
    uVar6 = 0;
  }
  if ((int)(DAT_140029a88._4_4_ - 1U) < (int)uVar6) {
    uVar6 = DAT_140029a88._4_4_ - 1U;
  }
  if ((int)((int)DAT_140029a88 - 1U) < (int)uVar7) {
    uVar7 = (ulonglong)((int)DAT_140029a88 - 1U);
  }
  FUN_14001d610((longlong)param_1,param_2,(ulonglong)uVar6 << 0x20 | uVar7,3,7,*param_1 ^ 0x22222222
                ,0,1);
  uVar6 = 0;
  do {
    uVar2 = uVar6 * -0x61c88647 ^ *param_1 ^ 0x33333333;
    uVar2 = (uVar2 >> 0x10 ^ uVar2) * 0x45d9f3b;
    uVar2 = (uVar2 >> 0x10 ^ uVar2) * 0x45d9f3b;
    uVar2 = uVar2 >> 0x10 ^ uVar2;
    uVar4 = uVar2 >> 7 & 3;
    iVar8 = (uVar2 >> 3 & 3) + 6 + (int)param_3;
    if (iVar8 < 0) {
      iVar8 = 0;
    }
    iVar5 = uVar4 + 2;
    if ((uVar2 & 1) == 0) {
      iVar5 = -2 - uVar4;
    }
    iVar5 = iVar5 + iVar3;
    if (iVar5 < 0) {
      iVar5 = 0;
    }
    if (DAT_140029a88._4_4_ + -1 < iVar5) {
      iVar5 = DAT_140029a88._4_4_ + -1;
    }
    if ((int)DAT_140029a88 + -1 < iVar8) {
      iVar8 = (int)DAT_140029a88 + -1;
    }
    uVar7 = FUN_14001d610((longlong)param_1,param_2,CONCAT44(iVar5,iVar8),4,(uVar2 >> 0xc & 3) + 10,
                          uVar2,0,1);
  } while (((int)uVar7 == 0) && (uVar6 = uVar6 + 1, uVar6 < 8));
  return;
}


// ===== FUN_14001b770 @ 14001b770 size=118

ulonglong FUN_14001b770(uint param_1)

{
  int *piVar1;
  byte bVar2;
  char cVar3;
  undefined8 uVar4;
  code *pcVar5;
  uint uVar6;
  uint uVar7;
  ulonglong uVar8;
  ulonglong in_RAX;
  byte *pbVar9;
  char *pcVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  longlong lVar13;
  bool bVar14;
  int iStack_28;
  undefined4 uStack_24;
  float fStack_20;
  float fStack_1c;
  undefined8 uStack_18;
  
  if ((-1 < (int)param_1) && (param_1 < 0xc)) {
    if ((&DAT_140029058)[(longlong)(int)param_1 * 2] == '\x01') {
      FUN_14000c940();
      uVar8 = (ulonglong)DAT_1400294f0;
      uVar11 = 0;
      if (DAT_1400294f0 != 0) {
        uVar12 = (ulonglong)DAT_140029a30;
        pbVar9 = (byte *)&DAT_1400294d0;
        do {
          uVar7 = *(uint *)((longlong)&DAT_1400294d0 + uVar11 * 8 + 4);
          if (uVar7 != 0) {
            bVar2 = *(byte *)(&DAT_1400294d0 + uVar11);
            if (bVar2 < DAT_140029a30) {
              if (uVar12 <= bVar2) {
                pcVar5 = (code *)swi(3);
                uVar8 = (*pcVar5)();
                return uVar8;
              }
              uVar6 = *(uint *)(DAT_140029a28 + (ulonglong)bVar2 * 4);
            }
            else {
              uVar6 = 0;
            }
            if (uVar6 < uVar7) {
              return 0;
            }
          }
          uVar7 = (int)uVar11 + 1;
          uVar11 = (ulonglong)uVar7;
          lVar13 = DAT_140029a28;
        } while (uVar7 < DAT_1400294f0);
        do {
          uVar7 = *(uint *)(pbVar9 + 4);
          if ((uVar7 != 0) && (uVar11 = (ulonglong)*pbVar9, (uint)*pbVar9 < (uint)uVar12)) {
            if (uVar12 <= uVar11) {
              pcVar5 = (code *)swi(3);
              uVar8 = (*pcVar5)();
              return uVar8;
            }
            if (uVar7 <= *(uint *)(lVar13 + uVar11 * 4)) {
              if (uVar12 <= uVar11) {
                pcVar5 = (code *)swi(3);
                uVar8 = (*pcVar5)();
                return uVar8;
              }
              piVar1 = (int *)(lVar13 + uVar11 * 4);
              *piVar1 = *piVar1 - uVar7;
              uVar12 = (ulonglong)DAT_140029a30;
              lVar13 = DAT_140029a28;
            }
          }
          pbVar9 = pbVar9 + 8;
          uVar8 = uVar8 - 1;
        } while (uVar8 != 0);
      }
      if ((DAT_14002a9d8 != 0) && (DAT_14002a9d0 != (undefined8 *)0x0)) {
        uVar4 = *DAT_14002a9d0;
        uVar8 = 0x200000002;
        if (*(int *)(DAT_14002a9d0 + 1) == 0) {
          uVar8 = 0x100000001;
        }
        fStack_20 = (float)(uVar8 & 0xffffffff) * (0.5f);
        fStack_1c = (float)(uVar8 >> 0x20) * (0.5f);
        if ((uVar8 & 1) == 0) {
          fStack_20 = fStack_20 + (-0.0500000007f);
        }
        if ((uVar8 >> 0x20 & 1) == 0) {
          fStack_1c = fStack_1c + (-0.0500000007f);
        }
        uStack_18._0_4_ = (int)uVar4;
        uStack_18._4_4_ = (undefined4)((ulonglong)uVar4 >> 0x20);
        iStack_28 = (int)uStack_18;
        uStack_24 = uStack_18._4_4_;
        uStack_18 = uVar4;
        FUN_140002060(0x1400291d0,&iStack_28);
        return 1;
      }
      FUN_1400021c0(0x1400291d0);
      return 1;
    }
    cVar3 = (&DAT_140029059)[(longlong)(int)param_1 * 2];
    pcVar10 = &DAT_140029028;
    DAT_140029024 = 0xe;
    bVar14 = DAT_14002962c == cVar3;
    DAT_140029660 = 0;
    DAT_14002962c = cVar3;
    if (bVar14) {
      DAT_14002962c = '\0';
    }
    in_RAX = 0;
    while (*pcVar10 != cVar3) {
      uVar7 = (int)in_RAX + 1;
      in_RAX = (ulonglong)uVar7;
      pcVar10 = pcVar10 + 1;
      if (0x15 < uVar7) {
        DAT_140029664 = 0;
        return in_RAX;
      }
    }
    DAT_140029664 = 0;
    DAT_140029658 = (int)in_RAX;
  }
  return in_RAX;
}


// ===== FUN_14001b7f0 @ 14001b7f0 size=23

undefined1 (*) [16] FUN_14001b7f0(undefined1 (*param_1) [16],ulonglong param_2)

{
  FUN_140011e40(param_1,param_2);
  return param_1;
}


// ===== FUN_14001b810 @ 14001b810 size=98

ulonglong FUN_14001b810(int *param_1)

{
  code *pcVar1;
  ulonglong uVar2;
  longlong lVar3;
  uint uVar4;
  
  if (*(longlong *)(param_1 + 0x4a) == 0) {
    pcVar1 = (code *)swi(3);
    uVar2 = (*pcVar1)();
    return uVar2;
  }
  if ((((*(longlong *)(param_1 + 2) != 0) && (*param_1 != 1)) &&
      (lVar3 = *(longlong *)(param_1 + 0x48), lVar3 != 0)) && (1 < *(uint *)(lVar3 + 0x10))) {
    uVar2 = 0;
    if (*(int *)(lVar3 + 0x10) == 0) {
      pcVar1 = (code *)swi(3);
      uVar2 = (*pcVar1)();
      return uVar2;
    }
    do {
      if (*(longlong *)(*(longlong *)(lVar3 + 8) + uVar2 * 8) == *(longlong *)(param_1 + 0x4a)) {
        return uVar2;
      }
      lVar3 = *(longlong *)(param_1 + 0x48);
      uVar4 = (int)uVar2 + 1;
      uVar2 = (ulonglong)uVar4;
    } while (uVar4 < *(uint *)(lVar3 + 0x10));
    return 0xffffffff;
  }
  return 0xffffffff;
}


// ===== FUN_14001b880 @ 14001b880 size=513

bool FUN_14001b880(ulonglong param_1,uint param_2,int param_3,int param_4)

{
  bool bVar1;
  longlong *plVar2;
  int *piVar3;
  undefined7 extraout_var;
  longlong lVar4;
  longlong lVar5;
  int iVar6;
  uint uVar7;
  ulonglong uVar8;
  int iVar9;
  longlong lVar10;
  int iStackX_c;
  undefined8 local_150;
  longlong lStack_148;
  longlong lStack_140;
  longlong lStack_138;
  longlong local_128;
  longlong lStack_120;
  longlong lStack_118;
  longlong lStack_110;
  longlong local_108;
  longlong lStack_100;
  longlong lStack_f8;
  longlong lStack_f0;
  longlong local_e8;
  longlong lStack_e0;
  longlong lStack_d8;
  longlong lStack_d0;
  longlong local_c8;
  longlong lStack_c0;
  longlong local_b8;
  undefined4 local_a8 [32];
  
  if (((param_3 != -1) && (param_4 != -1)) && (param_3 != param_4)) {
    plVar2 = (longlong *)FUN_140009470(local_a8,param_3,param_4);
    local_150 = *plVar2;
    lStack_148 = plVar2[1];
    lStack_140 = plVar2[2];
    lStack_138 = plVar2[3];
    local_108 = plVar2[4];
    lStack_100 = plVar2[5];
    lStack_f8 = plVar2[6];
    lStack_f0 = plVar2[7];
    local_e8 = plVar2[8];
    lStack_e0 = plVar2[9];
    lStack_d8 = plVar2[10];
    lStack_d0 = plVar2[0xb];
    local_c8 = plVar2[0xc];
    lStack_c0 = plVar2[0xd];
    local_b8 = plVar2[0xe];
    if (lStack_140 != 0) {
      local_128 = local_150;
      lStack_120 = lStack_148;
      lStack_118 = lStack_140;
      lStack_110 = lStack_138;
      piVar3 = (int *)FUN_140009990(param_1,param_2);
      if (piVar3 == (int *)0x0) {
        iStackX_c = (int)(param_1 >> 0x20);
        iVar9 = (int)lStack_148 + iStackX_c;
        lVar10 = 0;
        if (iStackX_c < iVar9) {
          iVar6 = local_150._4_4_ + (uint)param_1;
          do {
            uVar8 = param_1 & 0xffffffff;
            uVar7 = (uint)param_1;
            while ((int)uVar7 < iVar6) {
              bVar1 = FUN_14001c590(CONCAT44(iStackX_c,(int)uVar8),param_2);
              lVar4 = lVar10;
              lVar5 = lVar10;
              if ((int)CONCAT71(extraout_var,bVar1) == 0) goto LAB_14001ba0b;
              uVar7 = (int)uVar8 + 1;
              uVar8 = (ulonglong)uVar7;
            }
            iStackX_c = iStackX_c + 1;
          } while (iStackX_c < iVar9);
        }
        FUN_140008800(&local_150,param_1,param_2,(int *)&local_128);
        lVar4 = local_150;
        lVar5 = lStack_148;
LAB_14001ba0b:
        if (((lVar4 == 0) || (*(longlong *)(lVar4 + 8) == 0)) || (*(longlong *)(lVar4 + 8) != lVar5)
           ) {
          lVar4 = lVar10;
        }
        return lVar4 != 0;
      }
      if ((*(longlong *)(piVar3 + 2) != 0) && (*piVar3 == 1)) {
        FUN_140002dc0(piVar3,(int *)&local_128);
        return true;
      }
    }
  }
  return false;
}


// ===== FUN_14001ba90 @ 14001ba90 size=283

void FUN_14001ba90(int *param_1,uint param_2,undefined4 param_3)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  longlong lVar7;
  ulonglong uVar8;
  undefined1 local_18 [16];
  
  if ((-1 < (int)param_2) && (param_2 < DAT_1400299a8)) {
    uVar8 = (ulonglong)(DAT_140029a88._4_4_ * (int)DAT_140029a88 * param_2);
    lVar7 = DAT_140029aa0 + uVar8;
    lVar1 = DAT_140029a98 + uVar8 * 4;
    local_18._0_4_ = 0;
    if (0 < *param_1) {
      local_18._0_4_ = *param_1;
    }
    local_18._4_4_ = 0;
    if (0 < param_1[1]) {
      local_18._4_4_ = param_1[1];
    }
    local_18._8_4_ = (int)DAT_140029a88 + -1;
    if (param_1[2] < (int)DAT_140029a88 + -1) {
      local_18._8_4_ = param_1[2];
    }
    local_18._12_4_ = DAT_140029a88._4_4_ + -1;
    if (param_1[3] < DAT_140029a88._4_4_ + -1) {
      local_18._12_4_ = param_1[3];
    }
    if (((int)local_18._8_4_ < (int)local_18._0_4_) || ((int)local_18._12_4_ < (int)local_18._4_4_))
    {
      local_18 = (undefined1  [16])0x0;
    }
    else {
    }
    *(undefined8 *)param_1 = local_18._0_8_;
    *(undefined8 *)(param_1 + 2) = local_18._8_8_;
    iVar6 = param_1[1];
    iVar2 = param_1[3];
    if (iVar6 <= iVar2) {
      iVar3 = *param_1;
      iVar4 = param_1[2];
      iVar5 = iVar3;
      do {
        for (; iVar5 <= iVar4; iVar5 = iVar5 + 1) {
          *(undefined4 *)(lVar1 + (ulonglong)(uint)(iVar6 * (int)DAT_140029a88 + iVar5) * 4) =
               param_3;
          *(undefined1 *)((ulonglong)(uint)(iVar6 * (int)DAT_140029a88 + iVar5) + lVar7) = 0;
        }
        iVar6 = iVar6 + 1;
        iVar5 = iVar3;
      } while (iVar6 <= iVar2);
    }
  }
  return;
}


// ===== FUN_14001bbb0 @ 14001bbb0 size=703

void FUN_14001bbb0(longlong param_1,longlong param_2)

{
  uint uVar1;
  ulonglong uVar2;
  bool bVar3;
  bool bVar4;
  uint uVar5;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  uint uVar6;
  ulonglong uVar7;
  ulonglong *puVar8;
  uint uVar9;
  uint uVar10;
  ulonglong uVar11;
  char cVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  ulonglong auStack_80038 [65536];
  
  FUN_1400200d0((undefined1 *)auStack_80038,0,0x80000);
  uVar7 = 0;
  if (2 < DAT_140029a88._4_4_) {
    iVar16 = -1;
    uVar10 = DAT_140029a88._4_4_;
    uVar15 = 1;
    uVar5 = (uint)DAT_140029a88;
    do {
      uVar9 = 1;
      if (2 < uVar5) {
        do {
          bVar4 = FUN_140005430(param_2,CONCAT44(uVar15,uVar9));
          if ((int)CONCAT71(extraout_var,bVar4) != 0) {
            uVar10 = uVar15 - 1;
            uVar5 = uVar9 - 1;
            uVar14 = 0;
            uVar1 = uVar9 + 1;
            uVar6 = uVar10;
            do {
              if ((uVar5 < (uint)DAT_140029a88) && (uVar6 < DAT_140029a88._4_4_)) {
                cVar12 = *(char *)((ulonglong)(uVar6 * (uint)DAT_140029a88 + uVar5) + DAT_140029a90)
                ;
              }
              else {
                cVar12 = '\0';
              }
              iVar13 = uVar14 + (cVar12 == '\b');
              if (iVar16 + uVar6 != 0) {
                if ((uVar9 < (uint)DAT_140029a88) && (uVar6 < DAT_140029a88._4_4_)) {
                  cVar12 = *(char *)((ulonglong)(uVar6 * (uint)DAT_140029a88 + uVar9) +
                                    DAT_140029a90);
                }
                else {
                  cVar12 = '\0';
                }
                iVar13 = iVar13 + (uint)(cVar12 == '\b');
              }
              if ((uVar1 < (uint)DAT_140029a88) && (uVar6 < DAT_140029a88._4_4_)) {
                cVar12 = *(char *)((ulonglong)(uVar6 * (uint)DAT_140029a88 + uVar1) + DAT_140029a90)
                ;
              }
              else {
                cVar12 = '\0';
              }
              uVar6 = uVar6 + 1;
              uVar14 = iVar13 + (uint)(cVar12 == '\b');
            } while ((int)(iVar16 + uVar6) < 2);
            if ((((uVar5 < (uint)DAT_140029a88) && (uVar15 < DAT_140029a88._4_4_)) &&
                (*(char *)((ulonglong)(uVar15 * (uint)DAT_140029a88 + uVar5) + DAT_140029a90) ==
                 '\b')) &&
               ((uVar1 < (uint)DAT_140029a88 &&
                (*(char *)((ulonglong)(uVar15 * (uint)DAT_140029a88 + uVar1) + DAT_140029a90) ==
                 '\b')))) {
              bVar4 = true;
            }
            else {
              bVar4 = false;
            }
            if (((uVar9 < (uint)DAT_140029a88) && (uVar10 < DAT_140029a88._4_4_)) &&
               ((*(char *)((ulonglong)(uVar10 * (uint)DAT_140029a88 + uVar9) + DAT_140029a90) ==
                 '\b' && ((uVar15 + 1 < DAT_140029a88._4_4_ &&
                          (*(char *)((ulonglong)((uVar15 + 1) * (uint)DAT_140029a88 + uVar9) +
                                    DAT_140029a90) == '\b')))))) {
              bVar3 = true;
            }
            else {
              bVar3 = false;
            }
            if ((4 < uVar14) || (((bVar4 || (bVar3)) && (2 < uVar14)))) {
              auStack_80038[uVar7] = CONCAT44(uVar15,uVar9);
              uVar7 = (ulonglong)((int)uVar7 + 1);
            }
          }
          uVar1 = uVar9 + 2;
          uVar10 = DAT_140029a88._4_4_;
          uVar9 = uVar9 + 1;
          uVar5 = (uint)DAT_140029a88;
        } while (uVar1 < (uint)DAT_140029a88);
      }
      iVar16 = iVar16 + -1;
      uVar9 = uVar15 + 2;
      uVar15 = uVar15 + 1;
    } while (uVar9 < uVar10);
    if ((int)uVar7 != 0) {
      puVar8 = auStack_80038;
      do {
        uVar2 = *puVar8;
        bVar4 = FUN_140005430(param_2,uVar2);
        if ((int)CONCAT71(extraout_var_00,bVar4) != 0) {
          uVar10 = (uint)(uVar2 >> 0x20);
          uVar11 = (ulonglong)(uVar10 * (uint)DAT_140029a88 + (uint)uVar2);
          if (((uint)uVar2 < (uint)DAT_140029a88) && (uVar10 < DAT_140029a88._4_4_)) {
            *(undefined1 *)(uVar11 + DAT_140029a90) = 8;
          }
          *(undefined1 *)(uVar11 + 4 + param_1) = 1;
          *(undefined1 *)(uVar11 + 0x10004 + param_1) = 1;
        }
        puVar8 = puVar8 + 1;
        uVar7 = uVar7 - 1;
      } while (uVar7 != 0);
    }
  }
  return;
}


// ===== FUN_14001be70 @ 14001be70 size=484

ulonglong FUN_14001be70(char param_1)

{
  int *piVar1;
  byte bVar2;
  code *pcVar3;
  uint uVar4;
  ulonglong uVar5;
  char *pcVar6;
  ulonglong uVar7;
  longlong lVar8;
  longlong lVar9;
  byte *pbVar10;
  uint uVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  
  FUN_14000c940();
  uVar13 = 0;
  pcVar6 = &DAT_140029290;
  uVar5 = uVar13;
  while (*pcVar6 != param_1) {
    uVar4 = (int)uVar5 + 1;
    uVar5 = (ulonglong)uVar4;
    pcVar6 = pcVar6 + 0x30;
    if (0xb < uVar4) {
      return 0;
    }
  }
  lVar9 = uVar5 * 0x30;
  if (lVar9 == -0x140029290) {
    return 0;
  }
  bVar2 = (&DAT_1400292b8)[lVar9];
  uVar5 = (ulonglong)DAT_140029a30;
  if ((bVar2 != 0xe) && (uVar4 = *(uint *)(&DAT_1400292bc + lVar9), uVar4 != 0)) {
    uVar11 = 0;
    if (bVar2 < DAT_140029a30) {
      if (uVar5 <= bVar2) {
        pcVar3 = (code *)swi(3);
        uVar5 = (*pcVar3)();
        return uVar5;
      }
      uVar11 = *(uint *)(DAT_140029a28 + (ulonglong)bVar2 * 4);
    }
    if (uVar4 <= uVar11) {
      uVar13 = (ulonglong)(byte)(&DAT_1400292b8)[lVar9];
      if (DAT_140029a30 <= (byte)(&DAT_1400292b8)[lVar9]) {
        return 0;
      }
      if (uVar4 == 0) {
        return 0;
      }
      if (uVar5 <= uVar13) {
        pcVar3 = (code *)swi(3);
        uVar5 = (*pcVar3)();
        return uVar5;
      }
      if (uVar4 <= *(uint *)(DAT_140029a28 + uVar13 * 4)) {
        if (uVar5 <= uVar13) {
          pcVar3 = (code *)swi(3);
          uVar5 = (*pcVar3)();
          return uVar5;
        }
        piVar1 = (int *)(DAT_140029a28 + uVar13 * 4);
        *piVar1 = *piVar1 - uVar4;
        return 1;
      }
      return 0;
    }
  }
  uVar4 = *(uint *)(&DAT_1400292b4 + lVar9);
  uVar12 = (ulonglong)uVar4;
  pbVar10 = &DAT_140029294 + lVar9;
  lVar8 = DAT_140029a28;
  uVar7 = uVar13;
  if (uVar4 != 0) {
    do {
      if (*(uint *)(&DAT_140029298 + uVar7 * 8 + lVar9) != 0) {
        bVar2 = pbVar10[uVar7 * 8];
        uVar11 = 0;
        if (bVar2 < DAT_140029a30) {
          if (uVar5 <= bVar2) {
            pcVar3 = (code *)swi(3);
            uVar5 = (*pcVar3)();
            return uVar5;
          }
          uVar11 = *(uint *)(DAT_140029a28 + (ulonglong)bVar2 * 4);
        }
        if (uVar11 < *(uint *)(&DAT_140029298 + uVar7 * 8 + lVar9)) {
          return 0;
        }
      }
      uVar11 = (int)uVar7 + 1;
      uVar7 = (ulonglong)uVar11;
    } while (uVar11 < uVar4);
    if (uVar4 != 0) {
      do {
        uVar4 = *(uint *)(pbVar10 + 4);
        if ((uVar4 != 0) && (uVar7 = (ulonglong)*pbVar10, (uint)*pbVar10 < (uint)uVar5)) {
          if (uVar5 <= uVar7) {
            pcVar3 = (code *)swi(3);
            uVar5 = (*pcVar3)();
            return uVar5;
          }
          if (uVar4 <= *(uint *)(lVar8 + uVar7 * 4)) {
            if (uVar5 <= uVar7) {
              pcVar3 = (code *)swi(3);
              uVar5 = (*pcVar3)();
              return uVar5;
            }
            piVar1 = (int *)(lVar8 + uVar7 * 4);
            *piVar1 = *piVar1 - uVar4;
            uVar5 = (ulonglong)DAT_140029a30;
            lVar8 = DAT_140029a28;
          }
        }
        pbVar10 = pbVar10 + 8;
        uVar12 = uVar12 - 1;
      } while (uVar12 != 0);
    }
  }
  bVar2 = (&DAT_1400292b8)[lVar9];
  if ((bVar2 == 0xe) || (*(int *)(&DAT_1400292bc + lVar9) == 0)) {
    uVar13 = 1;
  }
  else {
    if ((uint)bVar2 < (uint)uVar5) {
      if (uVar5 <= bVar2) {
        pcVar3 = (code *)swi(3);
        uVar5 = (*pcVar3)();
        return uVar5;
      }
      piVar1 = (int *)(lVar8 + (ulonglong)bVar2 * 4);
      *piVar1 = *piVar1 + *(int *)(&DAT_1400292bc + lVar9);
      uVar5 = (ulonglong)DAT_140029a30;
      lVar8 = DAT_140029a28;
    }
    uVar7 = (ulonglong)(byte)(&DAT_1400292b8)[lVar9];
    uVar4 = *(uint *)(&DAT_1400292bc + lVar9);
    if (((uint)(byte)(&DAT_1400292b8)[lVar9] < (uint)uVar5) && (uVar4 != 0)) {
      if (uVar5 <= uVar7) {
        pcVar3 = (code *)swi(3);
        uVar5 = (*pcVar3)();
        return uVar5;
      }
      if (uVar4 <= *(uint *)(lVar8 + uVar7 * 4)) {
        if (uVar5 <= uVar7) {
          pcVar3 = (code *)swi(3);
          uVar5 = (*pcVar3)();
          return uVar5;
        }
        piVar1 = (int *)(lVar8 + uVar7 * 4);
        *piVar1 = *piVar1 - uVar4;
        uVar13 = 1;
      }
    }
  }
  return uVar13;
}


// ===== FUN_14001c060 @ 14001c060 size=355

undefined1 (*) [16] FUN_14001c060(undefined1 (*param_1) [16],longlong param_2)

{
  ulonglong *puVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  longlong lVar5;
  code *pcVar6;
  undefined1 (*pauVar7) [16];
  undefined1 *puVar8;
  longlong lVar9;
  ulonglong uVar10;
  uint uVar11;
  longlong *plVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  uint uVar15;
  uint uVar16;
  
  puVar8 = (undefined1 *)0x0;
  *param_1 = (undefined1  [16])0x0;
  *(undefined8 *)param_1[1] = 0;
  uVar11 = 0;
  uVar2 = *(uint *)(param_2 + 0x10);
  if (uVar2 != 0) {
    uVar16 = 0;
    do {
      if ((ulonglong)uVar2 <= (ulonglong)uVar11) {
        pcVar6 = (code *)swi(3);
        pauVar7 = (undefined1 (*) [16])(*pcVar6)();
        return pauVar7;
      }
      uVar3 = *(uint *)(param_1[1] + 4);
      uVar4 = *(undefined8 *)
               (*(longlong *)(*(longlong *)(param_2 + 8) + (ulonglong)uVar11 * 8) + 0x28);
      if (uVar16 == uVar3) {
        uVar15 = 8;
        if (8 < uVar3 * 2) {
          uVar15 = uVar3 * 2;
        }
        if (uVar3 < uVar15) {
          puVar13 = *(undefined1 **)(*param_1 + 8);
          plVar12 = &DAT_140029878;
          if (*(longlong **)*param_1 != (longlong *)0x0) {
            plVar12 = *(longlong **)*param_1;
          }
          lVar5 = *plVar12;
          puVar1 = (ulonglong *)(plVar12 + 2);
          if (puVar13 == (undefined1 *)0x0) {
            uVar10 = *puVar1 + 7 & 0xfffffffffffffff8;
            *puVar1 = uVar10;
            puVar8 = (undefined1 *)(lVar5 + uVar10);
LAB_14001c174:
            *puVar1 = *puVar1 + (ulonglong)uVar15 * 8;
          }
          else {
            uVar10 = *puVar1;
            lVar9 = (ulonglong)uVar3 * 8;
            if (puVar13 + lVar9 != (undefined1 *)(uVar10 + lVar5)) {
              uVar10 = uVar10 + 7 & 0xfffffffffffffff8;
              puVar8 = (undefined1 *)(lVar5 + uVar10);
              *puVar1 = uVar10;
              puVar14 = puVar8;
              for (; lVar9 != 0; lVar9 = lVar9 + -1) {
                *puVar14 = *puVar13;
                puVar13 = puVar13 + 1;
                puVar14 = puVar14 + 1;
              }
              goto LAB_14001c174;
            }
            *puVar1 = uVar10 + (ulonglong)(uVar15 - uVar3) * 8;
            puVar8 = puVar13;
          }
          *(undefined1 **)(*param_1 + 8) = puVar8;
          *(uint *)(param_1[1] + 4) = uVar15;
        }
      }
      uVar11 = uVar11 + 1;
      uVar10 = (ulonglong)uVar16;
      uVar16 = uVar16 + 1;
      *(uint *)param_1[1] = uVar16;
      *(undefined8 *)(puVar8 + uVar10 * 8) = uVar4;
    } while (uVar11 < uVar2);
  }
  return param_1;
}


// ===== FUN_14001c1d0 @ 14001c1d0 size=690

void FUN_14001c1d0(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4,
                  float param_5,uint param_6)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  uint uVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  undefined7 extraout_var;
  uint uVar7;
  ulonglong uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  float fVar13;
  float fVar14;
  undefined1 in_ZMM3 [64];
  undefined1 auVar15 [64];
  undefined1 auVar16 [64];
  float fVar17;
  float fVar18;
  undefined1 auVar19 [64];
  undefined1 auVar20 [64];
  undefined8 local_c8;
  
  local_c8._0_4_ = (float)param_3;
  auVar1 = vroundps_avx(ZEXT416((uint)(((float)local_c8 - in_ZMM3._0_4_) - (1f))),1);
  uVar3 = 0;
  if (0 < (int)auVar1._0_4_) {
    uVar3 = (int)auVar1._0_4_;
  }
  auVar1 = vroundps_avx(ZEXT416((uint)((float)local_c8 + in_ZMM3._0_4_ + (1f))),2);
  auVar20 = ZEXT464((uint)param_5);
  local_c8._4_4_ = (float)((ulonglong)param_3 >> 0x20);
  iVar4 = (uint)DAT_140029a88 - 1;
  if ((int)auVar1._0_4_ < (int)((uint)DAT_140029a88 - 1)) {
    iVar4 = (int)auVar1._0_4_;
  }
  auVar1 = vroundps_avx(ZEXT416((uint)((local_c8._4_4_ - param_5) - (1f))),1);
  auVar2 = vroundps_avx(ZEXT416((uint)(local_c8._4_4_ + param_5 + (1f))),2);
  auVar19 = ZEXT1664(in_ZMM3._0_16_);
  iVar5 = DAT_140029a88._4_4_ - 1;
  if ((int)auVar2._0_4_ < (int)(DAT_140029a88._4_4_ - 1)) {
    iVar5 = (int)auVar2._0_4_;
  }
  uVar11 = 0;
  if (0 < (int)auVar1._0_4_) {
    uVar11 = (int)auVar1._0_4_;
  }
  if ((int)uVar11 <= iVar5) {
    auVar15 = ZEXT464((0.5f));
    uVar12 = uVar11 * -0x7a143595;
    fVar17 = (0.0799999982f);
    fVar18 = (0.959999979f);
    do {
      if ((int)uVar3 <= iVar4) {
        auVar1 = vmaxss_avx(auVar20._0_16_,auVar15._0_16_);
        fVar13 = (((float)uVar11 + auVar15._0_4_) - (float)((ulonglong)param_3 >> 0x20)) /
                 auVar1._0_4_;
        fVar13 = fVar13 * fVar13;
        local_c8 = (ulonglong)uVar11 << 0x20;
        auVar1 = vmaxss_avx(auVar19._0_16_,auVar15._0_16_);
        auVar16 = ZEXT1664(auVar1);
        uVar10 = uVar3 * -0x61c88647;
        uVar9 = uVar3;
        do {
          local_c8 = CONCAT44(local_c8._4_4_,uVar9);
          uVar7 = uVar12 ^ uVar10 ^ param_6;
          uVar7 = (uVar7 >> 0x10 ^ uVar7) * 0x45d9f3b;
          fVar14 = (((float)uVar9 + auVar15._0_4_) - (float)param_3) / auVar16._0_4_;
          if ((fVar14 * fVar14 + fVar13 <=
               (float)((uVar7 >> 0x10 ^ uVar7) * 0x5d9f3b >> 0x18 & 3) * fVar17 + fVar18) &&
             (bVar6 = FUN_140005430(param_2,local_c8), (int)CONCAT71(extraout_var,bVar6) != 0)) {
            uVar8 = (ulonglong)(uVar11 * (uint)DAT_140029a88 + uVar9);
            if ((uVar9 < (uint)DAT_140029a88) && (uVar11 < DAT_140029a88._4_4_)) {
              *(undefined1 *)(uVar8 + DAT_140029a90) = 8;
            }
            *(undefined1 *)(uVar8 + 4 + param_1) = 1;
            *(undefined1 *)(uVar8 + 0x10004 + param_1) = 1;
          }
          uVar9 = uVar9 + 1;
          uVar10 = uVar10 + 0x9e3779b9;
        } while ((int)uVar9 <= iVar4);
      }
      uVar11 = uVar11 + 1;
      uVar12 = uVar12 + 0x85ebca6b;
    } while ((int)uVar11 <= iVar5);
  }
  return;
}


// ===== FUN_14001c490 @ 14001c490 size=166

undefined8 FUN_14001c490(longlong *param_1,longlong *param_2)

{
  undefined1 *puVar1;
  char cVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  
  lVar3 = param_1[2];
  uVar6 = 0;
  lVar4 = *param_1;
  uVar7 = param_2[1];
  lVar5 = *param_2;
  uVar9 = uVar6;
  uVar8 = uVar6;
  if (uVar7 != 0) {
    do {
      cVar2 = *(char *)(lVar5 + uVar6);
      if (cVar2 == '%') {
        *param_2 = *param_2 + uVar6 + 1;
        param_2[1] = uVar7 - (uVar6 + 1);
        param_1[2] = param_1[2] + uVar8;
        return 1;
      }
      if ((cVar2 == '\\') && (uVar6 = uVar6 + 1, uVar9 = uVar8, uVar6 == uVar7)) break;
      puVar1 = (undefined1 *)(lVar5 + uVar6);
      uVar6 = uVar6 + 1;
      uVar9 = (ulonglong)((int)uVar8 + 1);
      *(undefined1 *)(uVar8 + lVar3 + lVar4) = *puVar1;
      uVar7 = param_2[1];
      uVar8 = uVar9;
    } while (uVar6 < uVar7);
  }
  *param_2 = *param_2 + uVar6;
  param_2[1] = uVar7 - uVar6;
  param_1[2] = param_1[2] + uVar9;
  return 0;
}


// ===== FUN_14001c540 @ 14001c540 size=72

void FUN_14001c540(undefined8 param_1)

{
  uint uVar1;
  
  uVar1 = (uint)((ulonglong)param_1 >> 0x20);
  if ((((uint)param_1 < (uint)DAT_140029a88) && (uVar1 < DAT_140029a88._4_4_)) &&
     (*(char *)((ulonglong)(uVar1 * (uint)DAT_140029a88 + (uint)param_1) + DAT_140029a90) == '\x06')
     ) {
    FUN_140012d40(param_1);
    return;
  }
  FUN_1400149b0(param_1);
  return;
}


// ===== FUN_14001c590 @ 14001c590 size=156

bool FUN_14001c590(longlong param_1,uint param_2)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  
  uVar1 = (uint)param_1;
  if ((((uint)DAT_140029a88 <= uVar1) ||
      (uVar3 = (uint)((ulonglong)param_1 >> 0x20), DAT_140029a88._4_4_ <= uVar3)) ||
     (DAT_1400299a8 <= param_2)) {
    return false;
  }
  if ((((int)uVar1 < 0) || (param_1 < 0)) || (((int)param_2 < 0 || (DAT_140029a88._4_4_ <= uVar3))))
  {
    cVar2 = '\0';
  }
  else {
    cVar2 = *(char *)((ulonglong)(uVar3 * (uint)DAT_140029a88 + uVar1) + DAT_140029a90);
    if (*(int *)(DAT_140029a98 +
                (ulonglong)((DAT_140029a88._4_4_ * param_2 + uVar3) * (uint)DAT_140029a88 + uVar1) *
                4) != 0) {
      return false;
    }
  }
  if (cVar2 != '\x01') {
    if (((cVar2 == '\x02') || (cVar2 == '\x03')) || (cVar2 == '\x04')) {
      return param_2 != 0;
    }
    if (cVar2 != '\x05') {
      return false;
    }
  }
  return true;
}


// ===== FUN_14001c630 @ 14001c630 size=357

undefined8 FUN_14001c630(ulonglong param_1)

{
  code *pcVar1;
  bool bVar2;
  undefined8 uVar3;
  undefined7 extraout_var;
  uint uVar4;
  uint uVar6;
  longlong lVar7;
  uint local_res10 [2];
  undefined8 local_2048 [1028];
  ulonglong uVar5;
  
  uVar6 = DAT_14002a9d8;
  if (DAT_14002a9d8 != 0) {
    FUN_1400200d0((undefined1 *)local_2048,0,0x2000);
    uVar5 = 0;
    lVar7 = DAT_14002a9d0;
    if (uVar6 != 0) {
      do {
        if (uVar6 <= uVar5) {
          pcVar1 = (code *)swi(3);
          uVar3 = (*pcVar1)();
          return uVar3;
        }
        uVar4 = 9;
        if (*(int *)(lVar7 + 8 + uVar5 * 0xc) != 0) {
          uVar4 = 0x14;
        }
        if (uVar6 <= uVar5) {
          pcVar1 = (code *)swi(3);
          uVar3 = (*pcVar1)();
          return uVar3;
        }
        bVar2 = FUN_14001c9e0(param_1,(ulonglong *)(lVar7 + uVar5 * 0xc),uVar4);
        if ((int)CONCAT71(extraout_var,bVar2) != 0) {
          if (uVar6 <= uVar5) {
            pcVar1 = (code *)swi(3);
            uVar3 = (*pcVar1)();
            return uVar3;
          }
          uVar3 = FUN_140008210(*(undefined8 *)(lVar7 + uVar5 * 0xc),param_1,local_2048,local_res10,
                                0x400);
          lVar7 = DAT_14002a9d0;
          uVar6 = DAT_14002a9d8;
          if ((int)uVar3 != 0) {
            return 1;
          }
        }
        uVar4 = (int)uVar5 + 1;
        uVar5 = (ulonglong)uVar4;
      } while (uVar4 < uVar6);
    }
  }
  return 0;
}


// ===== FUN_14001c7a0 @ 14001c7a0 size=273

uint FUN_14001c7a0(undefined8 param_1)

{
  longlong lVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  
  uVar2 = (uint)param_1;
  if ((uVar2 < (uint)DAT_140029a88) &&
     (uVar6 = (uint)((ulonglong)param_1 >> 0x20), uVar6 < DAT_140029a88._4_4_)) {
    uVar7 = (ulonglong)((uint)DAT_140029a88 * uVar6 + uVar2);
    if (uVar6 < DAT_140029a88._4_4_) {
      cVar3 = *(char *)(uVar7 + DAT_140029a90);
    }
    else {
      cVar3 = '\0';
    }
    if (cVar3 == '\x02') {
      return (uint)(*(short *)(&DAT_14004a9f0 + uVar7 * 2) != 0);
    }
    if (cVar3 == '\x03') {
      return (uint)(*(short *)(&DAT_14006a9f0 + uVar7 * 2) != 0);
    }
    if (cVar3 == '\x04') {
      return (uint)(*(short *)(&DAT_14008a9f0 + uVar7 * 2) != 0);
    }
    if (cVar3 == '\x06') {
      uVar5 = 0;
      uVar4 = uVar5;
      if (DAT_1400299ac != 0) {
        while ((*(uint *)((ulonglong)uVar4 * 0x40 + DAT_140029ac8) != uVar2 ||
               (*(uint *)((ulonglong)uVar4 * 0x40 + 4 + DAT_140029ac8) != uVar6))) {
          uVar4 = uVar4 + 1;
          if (DAT_1400299ac <= uVar4) {
            return 0;
          }
        }
        if (((-1 < (int)uVar4) && (lVar1 = (ulonglong)uVar4 * 0x40 + DAT_140029ac8, lVar1 != 0)) &&
           (uVar5 = 0, *(int *)(lVar1 + 0xc) != 0)) {
          uVar5 = 1;
        }
      }
      return uVar5;
    }
  }
  return 0;
}


// ===== FUN_14001c8c0 @ 14001c8c0 size=152

undefined8 FUN_14001c8c0(ulonglong param_1)

{
  code *pcVar1;
  longlong lVar2;
  uint uVar3;
  bool bVar4;
  undefined8 uVar5;
  undefined7 extraout_var;
  ulonglong uVar6;
  uint uVar7;
  ulonglong uVar8;
  
  uVar3 = DAT_14002a9d8;
  lVar2 = DAT_14002a9d0;
  uVar6 = (ulonglong)DAT_14002a9d8;
  uVar8 = 0;
  if (DAT_14002a9d8 != 0) {
    do {
      if (uVar6 <= uVar8) {
        pcVar1 = (code *)swi(3);
        uVar5 = (*pcVar1)();
        return uVar5;
      }
      uVar7 = 9;
      if (*(int *)(uVar8 * 0xc + 8 + lVar2) != 0) {
        uVar7 = 0x14;
      }
      if (uVar6 <= uVar8) {
        pcVar1 = (code *)swi(3);
        uVar5 = (*pcVar1)();
        return uVar5;
      }
      bVar4 = FUN_14001c9e0(param_1,(ulonglong *)(uVar8 * 0xc + lVar2),uVar7);
      if ((int)CONCAT71(extraout_var,bVar4) != 0) {
        return 1;
      }
      uVar7 = (int)uVar8 + 1;
      uVar8 = (ulonglong)uVar7;
    } while (uVar7 < uVar3);
  }
  return 0;
}


// ===== FUN_14001c960 @ 14001c960 size=118

undefined8 FUN_14001c960(ulonglong param_1,longlong param_2)

{
  uint uVar1;
  code *pcVar2;
  bool bVar3;
  undefined8 uVar4;
  undefined7 extraout_var;
  uint uVar5;
  ulonglong uVar6;
  
  uVar1 = *(uint *)(param_2 + 0x10);
  uVar6 = 0;
  if (uVar1 != 0) {
    do {
      if (uVar1 <= uVar6) {
        pcVar2 = (code *)swi(3);
        uVar4 = (*pcVar2)();
        return uVar4;
      }
      bVar3 = FUN_14001c9e0(param_1,(ulonglong *)(*(longlong *)(param_2 + 8) + uVar6 * 0xc),4);
      if ((int)CONCAT71(extraout_var,bVar3) != 0) {
        return 1;
      }
      uVar1 = *(uint *)(param_2 + 0x10);
      uVar5 = (int)uVar6 + 1;
      uVar6 = (ulonglong)uVar5;
    } while (uVar5 < uVar1);
  }
  return 0;
}


// ===== FUN_14001c9e0 @ 14001c9e0 size=219

bool FUN_14001c9e0(ulonglong param_1,ulonglong *param_2,uint param_3)

{
  float fVar1;
  float fVar2;
  undefined1 auVar3 [16];
  ulonglong uVar4;
  float fVar5;
  float fVar6;
  
  fVar1 = (float)(param_1 & 0xffffffff) + (0.5f);
  fVar2 = (float)(param_1 >> 0x20) + (0.5f);
  uVar4 = 0x200000002;
  if ((int)param_2[1] == 0) {
    uVar4 = 0x100000001;
  }
  fVar5 = (float)(*param_2 & 0xffffffff);
  auVar3 = vmaxss_avx(ZEXT416((uint)fVar5),ZEXT416((uint)fVar1));
  fVar6 = (float)(*param_2 >> 0x20);
  auVar3 = vminss_avx(ZEXT416((uint)((float)(uVar4 & 0xffffffff) + fVar5)),auVar3);
  fVar1 = fVar1 - auVar3._0_4_;
  auVar3 = vmaxss_avx(ZEXT416((uint)fVar6),ZEXT416((uint)fVar2));
  auVar3 = vminss_avx(ZEXT416((uint)((float)(uVar4 >> 0x20) + fVar6)),auVar3);
  fVar2 = fVar2 - auVar3._0_4_;
  return fVar2 * fVar2 + fVar1 * fVar1 <= (float)param_3 * (float)param_3;
}


// ===== FUN_14001cac0 @ 14001cac0 size=210

undefined8 FUN_14001cac0(ulonglong param_1)

{
  code *pcVar1;
  uint uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  uint uVar5;
  
  uVar2 = (uint)param_1;
  if ((uVar2 < (uint)DAT_140029a88) &&
     (uVar5 = (uint)(param_1 >> 0x20), uVar5 < DAT_140029a88._4_4_)) {
    if ((DAT_1400299a8 != 0) &&
       (((-1 < (int)uVar2 && (-1 < (longlong)param_1)) && (uVar5 < DAT_140029a88._4_4_)))) {
      uVar2 = *(uint *)(DAT_140029a98 + (ulonglong)(uVar5 * (uint)DAT_140029a88 + uVar2) * 4);
      if ((uVar2 != 0) && (uVar2 < DAT_14002a870)) {
        if ((ulonglong)DAT_14002a870 <= (ulonglong)uVar2) {
          pcVar1 = (code *)swi(3);
          uVar3 = (*pcVar1)();
          return uVar3;
        }
        if (*(longlong *)(DAT_14002a868 + (ulonglong)uVar2 * 8) != 0) {
          return 0;
        }
      }
    }
    uVar3 = FUN_14001c8c0(param_1);
    if (((int)uVar3 != 0) && (uVar4 = FUN_1400086a0(param_1), (int)uVar4 < 0)) {
      uVar4 = FUN_140009fb0(param_1);
      uVar2 = (uint)uVar4 & 0xff;
      if (((uVar2 == 2) || (((uVar2 == 3 || (uVar2 == 4)) || (uVar2 == 6)))) &&
         ((uVar2 = FUN_14001c7a0(param_1), uVar2 != 0 &&
          (uVar3 = FUN_14001c630(param_1), (int)uVar3 != 0)))) {
        return 1;
      }
    }
  }
  return 0;
}


// ===== FUN_14001cba0 @ 14001cba0 size=161

undefined8 FUN_14001cba0(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  code *pcVar3;
  undefined8 uVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined4 uStackX_c;
  
  uVar1 = *(uint *)(param_2 + 0x10);
  uVar6 = 0;
  if (uVar1 != 0) {
    uStackX_c = (uint)((ulonglong)param_1 >> 0x20);
    do {
      if (uVar1 <= uVar6) {
        pcVar3 = (code *)swi(3);
        uVar4 = (*pcVar3)();
        return uVar4;
      }
      lVar2 = *(longlong *)(param_2 + 8);
      uVar1 = *(uint *)(lVar2 + uVar6 * 0xc);
      uVar4 = 0x200000002;
      if (*(int *)(lVar2 + 8 + uVar6 * 0xc) == 0) {
        uVar4 = 0x100000001;
      }
      if ((((uVar1 <= (uint)param_1) &&
           (uVar5 = *(uint *)(lVar2 + uVar6 * 0xc + 4), uVar5 <= uStackX_c)) &&
          ((uint)param_1 < uVar1 + (int)uVar4)) &&
         (uStackX_c < (int)((ulonglong)uVar4 >> 0x20) + uVar5)) {
        return 1;
      }
      uVar1 = *(uint *)(param_2 + 0x10);
      uVar5 = (int)uVar6 + 1;
      uVar6 = (ulonglong)uVar5;
    } while (uVar5 < uVar1);
  }
  return 0;
}


// ===== FUN_14001cc50 @ 14001cc50 size=240

void FUN_14001cc50(longlong param_1,char *param_2,int param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  code *pcVar5;
  uint uVar6;
  ulonglong uVar7;
  uint uVar8;
  
  uVar2 = *(uint *)(param_2 + 4);
  if (uVar2 != 0) {
    puVar4 = *(uint **)(param_1 + 0x128);
    if (puVar4 == (uint *)0x0) {
      pcVar5 = (code *)swi(3);
      (*pcVar5)();
      return;
    }
    uVar8 = *puVar4;
    if (uVar8 == 0) {
      if (param_3 == 0) {
        if ((*(int *)(param_1 + 0x58) == 0) && (*(int *)(param_1 + 0x40) == 0)) {
          *(undefined8 *)(param_1 + 0x3c) = *(undefined8 *)param_2;
          *(int *)(param_2 + 4) = *(int *)(param_2 + 4) + -1;
          *(undefined4 *)(param_1 + 0x40) = 1;
          return;
        }
      }
      else if ((*(int *)(param_1 + 0x60) == 0) && (*(int *)(param_1 + 0x48) == 0)) {
        *(undefined8 *)(param_1 + 0x44) = *(undefined8 *)param_2;
        *(int *)(param_2 + 4) = *(int *)(param_2 + 4) + -1;
        *(undefined4 *)(param_1 + 0x48) = 1;
        return;
      }
    }
    else {
      uVar7 = 0;
      if (uVar8 != 0) {
        while( true ) {
          if ((char)puVar4[uVar7 * 2 + 1] == *param_2) break;
          uVar6 = (int)uVar7 + 1;
          uVar7 = (ulonglong)uVar6;
          if (uVar8 <= uVar6) {
            return;
          }
        }
        if ((int)uVar7 != -1) {
          iVar3 = *(int *)(param_1 + 0x40 + uVar7 * 8);
          uVar8 = puVar4[uVar7 * 2 + 2] - iVar3;
          if (uVar8 != 0) {
            *(char *)(param_1 + 0x3c + uVar7 * 8) = *param_2;
            if (uVar8 < uVar2) {
              *(uint *)(param_2 + 4) = *(int *)(param_2 + 4) - uVar8;
              piVar1 = (int *)(param_1 + 0x40 + uVar7 * 8);
              *piVar1 = *piVar1 + uVar8;
              return;
            }
            *(int *)(param_1 + 0x40 + uVar7 * 8) = *(int *)(param_2 + 4) + iVar3;
            param_2[4] = '\0';
            param_2[5] = '\0';
            param_2[6] = '\0';
            param_2[7] = '\0';
          }
        }
      }
    }
  }
  return;
}


// ===== FUN_14001cd50 @ 14001cd50 size=662

byte * FUN_14001cd50(int *param_1,byte *param_2,undefined8 param_3,byte *param_4,uint param_5,
                    uint param_6,int param_7)

{
  longlong lVar1;
  byte bVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  uint uVar9;
  byte *pbVar10;
  uint uVar11;
  byte *pbVar12;
  byte bVar13;
  byte bVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  
  pbVar8 = (byte *)0x0;
  lVar1 = (ulonglong)param_5 * 4;
  uVar5 = ((param_1[1] - *(int *)(&DAT_140023ec0 + lVar1)) + -1 + *(uint *)(&DAT_140023f00 + lVar1))
          / *(uint *)(&DAT_140023f00 + lVar1);
  iVar17 = ((*param_1 + -1 + (*(uint *)(&DAT_140023ee0 + lVar1) - *(int *)(&DAT_140023ea0 + lVar1)))
           / *(uint *)(&DAT_140023ee0 + lVar1)) * (uint)*(byte *)(param_1 + 2) * param_6;
  param_6 = 0;
  uVar18 = iVar17 + 7;
  uVar19 = uVar18 >> 3;
  if (uVar5 != 0) {
    do {
      pbVar12 = param_4;
      bVar2 = *param_2;
      if (4 < bVar2) {
        FUN_140002010("Filter mode out of range");
        pcVar3 = (code *)swi(3);
        pbVar8 = (byte *)(*pcVar3)();
        return pbVar8;
      }
      uVar11 = 0;
      if (uVar18 >> 3 != 0) {
        pbVar10 = pbVar8;
        do {
          bVar13 = pbVar10[(longlong)(param_2 + (1 - (longlong)pbVar8))];
          if (bVar2 == 1) {
            if ((pbVar12 == (byte *)0x0) || (uVar19 <= uVar11 - param_7)) {
              bVar14 = 0;
            }
            else {
              bVar14 = pbVar12[uVar11 - param_7];
            }
LAB_14001cf73:
            bVar13 = bVar13 + bVar14;
          }
          else {
            if (bVar2 != 2) {
              if (bVar2 == 3) {
                if ((pbVar12 == (byte *)0x0) || (uVar19 <= uVar11 - param_7)) {
                  bVar14 = 0;
                }
                else {
                  bVar14 = pbVar12[uVar11 - param_7];
                }
                if (pbVar8 == (byte *)0x0) {
                  bVar14 = bVar14 >> 1;
                }
                else {
                  bVar14 = (byte)((uint)*pbVar10 + (uint)bVar14 >> 1);
                }
                goto LAB_14001cf73;
              }
              if (bVar2 != 4) goto LAB_14001cf7a;
              uVar9 = uVar11 - param_7;
              if ((pbVar12 == (byte *)0x0) || (uVar19 <= uVar9)) {
                uVar15 = 0;
              }
              else {
                uVar15 = (uint)pbVar12[uVar9];
              }
              if (pbVar8 == (byte *)0x0) {
                uVar16 = 0;
LAB_14001ce9b:
                uVar9 = 0;
              }
              else {
                uVar16 = (uint)*pbVar10;
                if (uVar19 <= uVar9) goto LAB_14001ce9b;
                uVar9 = (uint)pbVar8[uVar9];
              }
              iVar6 = uVar16 - uVar9;
              iVar17 = -iVar6;
              if (0 < iVar6) {
                iVar17 = iVar6;
              }
              iVar7 = (uVar15 + iVar6) - uVar16;
              iVar4 = -iVar7;
              if (0 < iVar7) {
                iVar4 = iVar7;
              }
              iVar7 = (uVar15 + iVar6) - uVar9;
              iVar6 = -iVar7;
              if (0 < iVar7) {
                iVar6 = iVar7;
              }
              if (((iVar4 < iVar17) || (iVar6 < iVar17)) && (uVar15 = uVar9, iVar4 <= iVar6)) {
                uVar15 = uVar16;
              }
              bVar14 = (byte)uVar15;
              goto LAB_14001cf73;
            }
            if (pbVar8 != (byte *)0x0) {
              bVar13 = bVar13 + *pbVar10;
            }
          }
LAB_14001cf7a:
          uVar11 = uVar11 + 1;
          pbVar10[(longlong)pbVar12 - (longlong)pbVar8] = bVar13;
          pbVar10 = pbVar10 + 1;
        } while (uVar11 < uVar19);
      }
      param_2 = param_2 + (ulonglong)uVar19 + 1;
      param_6 = param_6 + 1;
      param_4 = pbVar12 + uVar19;
      pbVar8 = pbVar12;
    } while (param_6 < uVar5);
  }
  return param_2;
}


// ===== FUN_14001cff0 @ 14001cff0 size=1563

void FUN_14001cff0(uint *param_1,byte *param_2,uint param_3,byte *param_4,longlong param_5,
                  uint param_6,byte *param_7,uint param_8)

{
  longlong lVar1;
  uint uVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 in_stack_ffffffffffffff9c;
  undefined8 in_stack_ffffffffffffffa0;
  undefined4 uVar9;
  undefined8 uVar8;
  undefined4 in_stack_ffffffffffffffac;
  
  lVar1 = DAT_140029828;
  uVar9 = (undefined4)((ulonglong)in_stack_ffffffffffffffa0 >> 0x20);
  uVar4 = 1;
  if (param_1[4] != 0) {
    uVar4 = 3;
  }
  if ((param_1[5] != 0) && (uVar4 = 2, param_1[4] != 0)) {
    uVar4 = 4;
  }
  if (param_1[3] != 0) {
    uVar4 = 1;
  }
  uVar5 = (byte)param_1[2] * uVar4;
  uVar6 = uVar5 + 7 >> 3;
  uVar2 = (uint)(8 / (ulonglong)uVar5);
  uVar7 = 1;
  if (1 < uVar2) {
    uVar7 = uVar2;
  }
  if ((((byte)param_1[2] != 8) || (param_1[6] != 0)) || (pbVar3 = param_4, uVar4 != 4)) {
    pbVar3 = (byte *)(DAT_140029818 + DAT_140029828);
    DAT_140029828 = (ulonglong)((uVar5 * *param_1 + 7 >> 3) * param_1[1]) + DAT_140029828;
  }
  if (param_1[6] == 0) {
    FUN_14001cd50((int *)param_1,param_2,(ulonglong)param_3,pbVar3,0,uVar4,uVar6);
    if ((char)param_1[2] == '\b') {
      if (uVar4 != 4) {
        if (uVar4 == 3) {
          FUN_140001af0((int *)param_1,pbVar3,(undefined4 *)param_4,param_5,
                        CONCAT44(in_stack_ffffffffffffff9c,param_6),param_7,param_8);
        }
        else if (uVar4 == 2) {
          FUN_140001980((int *)param_1,pbVar3,(undefined4 *)param_4,param_5,
                        CONCAT44(in_stack_ffffffffffffff9c,param_6),(undefined2 *)param_7,param_8);
        }
        else if (uVar4 == 1) {
          FUN_140001800((int *)param_1,pbVar3,(undefined4 *)param_4,param_5,
                        CONCAT44(in_stack_ffffffffffffff9c,param_6),param_7,param_8);
        }
      }
    }
    else {
      FUN_140019fe0((int *)param_1,(longlong)pbVar3,(longlong)param_4,0,uVar4,CONCAT44(uVar9,uVar6),
                    CONCAT44(in_stack_ffffffffffffffac,uVar7),param_5,param_6,(undefined8 *)param_7,
                    param_8);
    }
  }
  else {
    if ((*param_1 != 0) && (param_1[1] != 0)) {
      param_2 = FUN_14001cd50((int *)param_1,param_2,(ulonglong)param_3,pbVar3,1,uVar4,uVar6);
      uVar8 = CONCAT44(uVar9,uVar6);
      FUN_140019fe0((int *)param_1,(longlong)pbVar3,(longlong)param_4,1,uVar4,uVar8,
                    CONCAT44(in_stack_ffffffffffffffac,uVar7),param_5,param_6,(undefined8 *)param_7,
                    param_8);
      uVar9 = (undefined4)((ulonglong)uVar8 >> 0x20);
    }
    if ((4 < *param_1) && (param_1[1] != 0)) {
      param_2 = FUN_14001cd50((int *)param_1,param_2,(ulonglong)param_3,pbVar3,2,uVar4,uVar6);
      uVar8 = CONCAT44(uVar9,uVar6);
      FUN_140019fe0((int *)param_1,(longlong)pbVar3,(longlong)param_4,2,uVar4,uVar8,
                    CONCAT44(in_stack_ffffffffffffffac,uVar7),param_5,param_6,(undefined8 *)param_7,
                    param_8);
      uVar9 = (undefined4)((ulonglong)uVar8 >> 0x20);
    }
    if ((*param_1 != 0) && (4 < param_1[1])) {
      param_2 = FUN_14001cd50((int *)param_1,param_2,(ulonglong)param_3,pbVar3,3,uVar4,uVar6);
      uVar8 = CONCAT44(uVar9,uVar6);
      FUN_140019fe0((int *)param_1,(longlong)pbVar3,(longlong)param_4,3,uVar4,uVar8,
                    CONCAT44(in_stack_ffffffffffffffac,uVar7),param_5,param_6,(undefined8 *)param_7,
                    param_8);
      uVar9 = (undefined4)((ulonglong)uVar8 >> 0x20);
    }
    if ((2 < *param_1) && (param_1[1] != 0)) {
      param_2 = FUN_14001cd50((int *)param_1,param_2,(ulonglong)param_3,pbVar3,4,uVar4,uVar6);
      uVar8 = CONCAT44(uVar9,uVar6);
      FUN_140019fe0((int *)param_1,(longlong)pbVar3,(longlong)param_4,4,uVar4,uVar8,
                    CONCAT44(in_stack_ffffffffffffffac,uVar7),param_5,param_6,(undefined8 *)param_7,
                    param_8);
      uVar9 = (undefined4)((ulonglong)uVar8 >> 0x20);
    }
    if ((*param_1 != 0) && (2 < param_1[1])) {
      param_2 = FUN_14001cd50((int *)param_1,param_2,(ulonglong)param_3,pbVar3,5,uVar4,uVar6);
      uVar8 = CONCAT44(uVar9,uVar6);
      FUN_140019fe0((int *)param_1,(longlong)pbVar3,(longlong)param_4,5,uVar4,uVar8,
                    CONCAT44(in_stack_ffffffffffffffac,uVar7),param_5,param_6,(undefined8 *)param_7,
                    param_8);
      uVar9 = (undefined4)((ulonglong)uVar8 >> 0x20);
    }
    if ((1 < *param_1) && (param_1[1] != 0)) {
      param_2 = FUN_14001cd50((int *)param_1,param_2,(ulonglong)param_3,pbVar3,6,uVar4,uVar6);
      uVar8 = CONCAT44(uVar9,uVar6);
      FUN_140019fe0((int *)param_1,(longlong)pbVar3,(longlong)param_4,6,uVar4,uVar8,
                    CONCAT44(in_stack_ffffffffffffffac,uVar7),param_5,param_6,(undefined8 *)param_7,
                    param_8);
      uVar9 = (undefined4)((ulonglong)uVar8 >> 0x20);
    }
    if ((*param_1 != 0) && (1 < param_1[1])) {
      FUN_14001cd50((int *)param_1,param_2,(ulonglong)param_3,pbVar3,7,uVar4,uVar6);
      FUN_140019fe0((int *)param_1,(longlong)pbVar3,(longlong)param_4,7,uVar4,CONCAT44(uVar9,uVar6),
                    CONCAT44(in_stack_ffffffffffffffac,uVar7),param_5,param_6,(undefined8 *)param_7,
                    param_8);
    }
  }
  DAT_140029828 = lVar1;
  return;
}


// ===== FUN_14001d610 @ 14001d610 size=1085

/* WARNING: Type propagation algorithm not settling */

ulonglong FUN_14001d610(longlong param_1,longlong param_2,ulonglong param_3,undefined1 param_4,
                       uint param_5,uint param_6,int param_7,int param_8)

{
  ulonglong uVar1;
  int iVar2;
  int iVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  ulonglong *puVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  uint uVar19;
  uint uVar20;
  bool bVar21;
  uint uStackX_1c;
  uint local_868;
  uint local_864;
  int iStack_844;
  ulonglong local_838;
  undefined1 local_830 [1016];
  ulonglong local_438 [128];
  
  uVar4 = FUN_1400051f0(param_1,param_2,param_3,param_7);
  if ((int)uVar4 == 0) {
    return uVar4;
  }
  FUN_1400200d0(local_830,0,0x3f8);
  FUN_1400200d0((undefined1 *)(local_438 + 1),0,0x3f8);
  uStackX_1c = (uint)(param_3 >> 0x20);
  uVar11 = (uint)param_3;
  if ((uVar11 < (uint)DAT_140029a88) && (uStackX_1c < DAT_140029a88._4_4_)) {
    *(undefined1 *)((ulonglong)(uStackX_1c * (uint)DAT_140029a88 + uVar11) + DAT_140029a90) =
         param_4;
  }
  uVar4 = 1;
  local_838 = param_3;
  local_438[0] = param_3;
  uVar19 = 1;
  local_868 = 1;
  *(undefined1 *)((ulonglong)(uStackX_1c * (uint)DAT_140029a88 + uVar11) + 4 + param_1) = 1;
  uVar11 = 0x18;
  if (0x18 < param_5 * 10) {
    uVar11 = param_5 * 10;
  }
  local_864 = 0;
  uVar7 = (uint)DAT_140029a88;
  if (uVar11 != 0) {
    do {
      if (((int)uVar4 == 0) || (param_5 <= uVar19)) break;
      uVar8 = local_864 * -0x61c88647 ^ param_6;
      uVar8 = (uVar8 >> 0x10 ^ uVar8) * 0x45d9f3b;
      uVar8 = (uVar8 >> 0x10 ^ uVar8) * 0x45d9f3b;
      uVar15 = uVar8 >> 0x10 ^ uVar8;
      uVar1 = (ulonglong)uVar15 % uVar4;
      if (((uVar8 >> 0x1d & 1) == 0) || (uVar19 == 0)) {
        puVar13 = &local_838;
        uVar4 = uVar1;
      }
      else {
        puVar13 = local_438;
        uVar4 = (ulonglong)(uVar8 >> 0x10) % (ulonglong)uVar19;
      }
      uVar8 = 0;
      uVar4 = puVar13[uVar4];
      do {
        iStack_844 = (int)(uVar4 >> 0x20);
        uVar9 = uVar8 * -0x7a143595 ^ uVar15;
        uVar9 = (uVar9 >> 0x10 ^ uVar9) * 0x45d9f3b;
        uVar9 = (uVar9 >> 0x10 ^ uVar9) * 0x45d9f3b;
        uVar9 = uVar9 >> 0x10 ^ uVar9;
        uVar5 = (ulonglong)(uVar9 & 7);
        uVar12 = iStack_844 + *(int *)(&DAT_140024dd4 + uVar5 * 8);
        uVar20 = *(int *)(&DAT_140024dd0 + uVar5 * 8) + (int)uVar4;
        if ((((-1 < (int)uVar20) && (-1 < (int)uVar12)) && ((int)uVar20 < (int)uVar7)) &&
           ((int)uVar12 < (int)DAT_140029a88._4_4_)) {
          uVar5 = CONCAT44(uVar12,uVar20);
          uVar6 = FUN_1400051f0(param_1,param_2,uVar5,param_7);
          uVar7 = (uint)DAT_140029a88;
          if (((int)uVar6 != 0) && ((uVar19 < 3 || ((uVar9 & 0x600) != 0)))) {
            if ((uVar20 < (uint)DAT_140029a88) && (uVar12 < DAT_140029a88._4_4_)) {
              *(undefined1 *)((ulonglong)(uVar12 * (uint)DAT_140029a88 + uVar20) + DAT_140029a90) =
                   param_4;
            }
            *(undefined1 *)((ulonglong)(uVar12 * (uint)DAT_140029a88 + uVar20) + 4 + param_1) = 1;
            if (uVar19 < 0x80) {
              uVar4 = (ulonglong)uVar19;
              uVar19 = uVar19 + 1;
              local_438[uVar4] = uVar5;
            }
            uVar4 = (ulonglong)local_868;
            uVar7 = (uint)DAT_140029a88;
            if (0x7f < local_868) goto LAB_14001d898;
            *(ulonglong *)(local_830 + uVar4 * 8 + -8) = uVar5;
            uVar4 = (ulonglong)(local_868 + 1);
            goto LAB_14001d893;
          }
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 < 8);
      uVar4 = (ulonglong)(local_868 - 1);
      *(undefined8 *)(local_830 + uVar1 * 8 + -8) = *(undefined8 *)(local_830 + uVar4 * 8 + -8);
LAB_14001d893:
      local_868 = (uint)uVar4;
LAB_14001d898:
      local_864 = local_864 + 1;
    } while (local_864 < uVar11);
    bVar21 = uVar19 == 0;
    if (bVar21) goto LAB_14001d9a5;
  }
  puVar13 = local_438;
  uVar4 = (ulonglong)uVar19;
  do {
    iVar18 = (int)(*puVar13 >> 0x20);
    iVar17 = 0;
    if (0 < iVar18 - param_8) {
      iVar17 = iVar18 - param_8;
    }
    iVar10 = DAT_140029a88._4_4_ - 1;
    if (iVar18 + param_8 < (int)(DAT_140029a88._4_4_ - 1)) {
      iVar10 = iVar18 + param_8;
    }
    if (iVar17 <= iVar10) {
      iVar16 = (int)*puVar13;
      iVar14 = uVar7 - 1;
      iVar2 = iVar16 - param_8;
      iVar10 = 0;
      if (0 < iVar2) {
        iVar10 = iVar2;
      }
      iVar16 = iVar16 + param_8;
      do {
        iVar2 = iVar14;
        if (iVar16 < iVar14) {
          iVar2 = iVar16;
        }
        iVar3 = iVar10;
        if (iVar10 <= iVar2) {
          do {
            uVar11 = iVar17 * uVar7 + iVar3;
            iVar3 = iVar3 + 1;
            *(undefined1 *)((ulonglong)uVar11 + 0x10004 + param_1) = 1;
            iVar14 = (uint)DAT_140029a88 - 1;
            iVar2 = iVar14;
            if (iVar16 < iVar14) {
              iVar2 = iVar16;
            }
            uVar7 = (uint)DAT_140029a88;
          } while (iVar3 <= iVar2);
        }
        iVar17 = iVar17 + 1;
        iVar2 = DAT_140029a88._4_4_ - 1;
        if (iVar18 + param_8 < (int)(DAT_140029a88._4_4_ - 1)) {
          iVar2 = iVar18 + param_8;
        }
      } while (iVar17 <= iVar2);
    }
    puVar13 = puVar13 + 1;
    uVar4 = uVar4 - 1;
  } while (uVar4 != 0);
  bVar21 = uVar19 == 0;
LAB_14001d9a5:
  return (ulonglong)!bVar21;
}


// ===== FUN_14001da50 @ 14001da50 size=489

undefined8 FUN_14001da50(ulonglong param_1,char param_2,int param_3)

{
  int *piVar1;
  uint *puVar2;
  code *pcVar3;
  uint uVar4;
  undefined8 uVar5;
  uint uVar6;
  ulonglong uVar7;
  uint uVar8;
  ulonglong uVar9;
  uint uVar10;
  undefined4 local_res20;
  ulonglong local_28 [4];
  
  if (param_3 != 0) {
    local_28[0] = FUN_140012080(param_1,'\0');
    local_28[1] = FUN_140012080(param_1,'\x01');
    local_28[2] = FUN_140012080(param_1,'\x02');
    local_28[3] = FUN_140012080(param_1,'\x03');
    uVar9 = 0;
    uVar10 = DAT_14002a870;
    uVar4 = (uint)DAT_140029a88;
    do {
      uVar7 = local_28[uVar9];
      uVar8 = (uint)uVar7;
      if ((((uVar8 < uVar4) && (uVar6 = (uint)(uVar7 >> 0x20), uVar6 < DAT_140029a88._4_4_)) &&
          (DAT_1400299a8 != 0)) && ((-1 < (int)uVar8 && (-1 < (longlong)uVar7)))) {
        uVar8 = *(uint *)(DAT_140029a98 + (ulonglong)(uVar8 + uVar6 * uVar4) * 4);
        if ((uVar8 != 0) && (uVar8 < uVar10)) {
          if ((ulonglong)uVar10 <= (ulonglong)uVar8) {
            pcVar3 = (code *)swi(3);
            uVar5 = (*pcVar3)();
            return uVar5;
          }
          piVar1 = *(int **)(DAT_14002a868 + (ulonglong)uVar8 * 8);
          if (((piVar1 != (int *)0x0) && (*(longlong *)(piVar1 + 2) != 0)) && (*piVar1 == 1)) {
            puVar2 = *(uint **)(piVar1 + 0x4a);
            local_res20 = CONCAT31(local_res20._1_3_,param_2);
            if (puVar2 == (uint *)0x0) {
              pcVar3 = (code *)swi(3);
              uVar5 = (*pcVar3)();
              return uVar5;
            }
            uVar8 = *puVar2;
            if (uVar8 == 0) {
              if ((piVar1[0x16] == 0) && (piVar1[0x10] == 0)) {
                *(ulonglong *)(piVar1 + 0xf) = CONCAT44(1,local_res20);
                piVar1[0x10] = 1;
                return 1;
              }
            }
            else {
              uVar7 = 0;
              if (uVar8 != 0) {
                do {
                  if ((char)puVar2[uVar7 * 2 + 1] == param_2) {
                    if ((int)uVar7 == -1) break;
                    uVar8 = puVar2[uVar7 * 2 + 2];
                    uVar6 = piVar1[uVar7 * 2 + 0x10];
                    if (uVar8 == uVar6) break;
                    *(char *)(piVar1 + uVar7 * 2 + 0xf) = param_2;
                    if (uVar8 == uVar6) {
                      piVar1[uVar7 * 2 + 0x10] = uVar8;
                      uVar10 = DAT_14002a870;
                      uVar4 = (uint)DAT_140029a88;
                      if (uVar8 == uVar6) break;
                    }
                    else {
                      piVar1[uVar7 * 2 + 0x10] = uVar6 + 1;
                    }
                    return 1;
                  }
                  uVar6 = (int)uVar7 + 1;
                  uVar7 = (ulonglong)uVar6;
                } while (uVar6 < uVar8);
              }
            }
          }
        }
      }
      uVar8 = (int)uVar9 + 1;
      uVar9 = (ulonglong)uVar8;
    } while (uVar8 < 4);
  }
  return 0;
}


// ===== FUN_14001dc40 @ 14001dc40 size=254

undefined8 FUN_14001dc40(longlong param_1,char param_2,uint param_3)

{
  int *piVar1;
  code *pcVar2;
  undefined8 uVar3;
  uint uVar4;
  longlong lVar5;
  char *pcVar6;
  uint uVar7;
  
  uVar4 = (uint)param_1;
  if (uVar4 < (uint)DAT_140029a88) {
    uVar7 = (uint)((ulonglong)param_1 >> 0x20);
    if ((((uVar7 < DAT_140029a88._4_4_) && (DAT_1400299a8 != 0)) && (-1 < (int)uVar4)) &&
       ((-1 < param_1 && (uVar7 < DAT_140029a88._4_4_)))) {
      uVar4 = *(uint *)(DAT_140029a98 + (ulonglong)(uVar7 * (uint)DAT_140029a88 + uVar4) * 4);
      if ((uVar4 != 0) && (uVar4 < DAT_14002a870)) {
        if ((ulonglong)DAT_14002a870 <= (ulonglong)uVar4) {
          pcVar2 = (code *)swi(3);
          uVar3 = (*pcVar2)();
          return uVar3;
        }
        piVar1 = *(int **)(DAT_14002a868 + (ulonglong)uVar4 * 8);
        if (((piVar1 != (int *)0x0) && (*(longlong *)(piVar1 + 2) != 0)) &&
           ((*piVar1 == 1 && (param_3 != 0)))) {
          lVar5 = 0x54;
          if (piVar1[0x16] == 0) {
            lVar5 = 0x3c;
          }
          pcVar6 = (char *)(lVar5 + (longlong)piVar1);
          uVar4 = *(uint *)(pcVar6 + 4);
          if ((uVar4 == 0) || (*pcVar6 == param_2)) {
            uVar7 = 0;
            if (uVar4 < (uint)piVar1[0x19]) {
              uVar7 = piVar1[0x19] - uVar4;
            }
            if (param_3 <= uVar7) {
              if (uVar4 == 0) {
                *pcVar6 = param_2;
              }
              *(uint *)(pcVar6 + 4) = uVar4 + param_3;
              return 1;
            }
          }
        }
      }
    }
  }
  return 0;
}


// ===== FUN_14001dd40 @ 14001dd40 size=501

void FUN_14001dd40(longlong param_1,uint param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  float fVar3;
  longlong lVar4;
  bool bVar5;
  code *pcVar6;
  float fVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  longlong lVar11;
  ulonglong uVar12;
  uint uVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  int iStack_37;
  undefined4 uStack_33;
  uint local_18;
  
  uVar15 = (ulonglong)param_2;
  if (param_2 < *(uint *)(param_1 + 0x30)) {
    uVar14 = 0;
    puVar1 = (undefined8 *)(*(longlong *)(param_1 + 0x28) + uVar15 * 0x28);
    uVar8 = *puVar1;
    local_18 = (uint)*(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x20 + uVar15 * 0x28);
    lVar11 = (longlong)(int)local_18;
    iStack_37 = (int)((ulonglong)uVar8 >> 8);
    uStack_33._0_3_ = (undefined3)((ulonglong)uVar8 >> 0x28);
    uStack_33._3_1_ = (undefined1)puVar1[1];
    if ((-1 < (int)local_18) && (local_18 < *(uint *)(param_1 + 0x18))) {
      if (((int)local_18 < 0) || ((longlong)(ulonglong)*(uint *)(param_1 + 0x18) <= lVar11)) {
        pcVar6 = (code *)swi(3);
        (*pcVar6)();
        return;
      }
      lVar4 = *(longlong *)(param_1 + 0x10);
      if (lVar11 < 0) {
        lVar11 = (ulonglong)*(uint *)(param_1 + 0x18) + lVar11;
      }
      lVar11 = lVar11 * 0x2080;
      uVar12 = *(ulonglong *)(lVar11 + 0x10 + lVar4);
      fVar3 = *(float *)(lVar11 + 0x1c + lVar4);
      fVar7 = *(float *)(lVar11 + lVar4) -
              ((float)(uVar12 & 0xffffffff) + *(float *)(lVar11 + 0x18 + lVar4));
      puVar1 = (undefined8 *)(lVar11 + 0x38 + lVar4);
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1[2] = 0;
      puVar1[3] = 0x100000000;
      *(undefined8 *)(lVar11 + 8 + lVar4) = 0;
      fVar3 = *(float *)(lVar11 + 4 + lVar4) - ((float)(uVar12 >> 0x20) + fVar3);
      bVar5 = fVar3 * fVar3 + fVar7 * fVar7 <= (9.99999975e-05f);
      *(undefined4 *)(lVar11 + 0x58 + lVar4) = 0;
      uVar12 = 3;
      if (bVar5) {
        uVar12 = uVar14;
      }
      *(undefined4 *)(lVar11 + 0x24 + lVar4) = 0;
      *(char *)(lVar11 + 0x34 + lVar4) = (char)uVar12;
      *(undefined4 *)(lVar11 + 0x2c + lVar4) = 0;
      *(undefined8 *)(lVar11 + 0x2064 + lVar4) = 0;
      *(undefined8 *)(lVar11 + 0x206c + lVar4) = 0;
      *(undefined4 *)(lVar11 + 0x2074 + lVar4) = 0;
    }
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + -1;
    if (param_2 < *(uint *)(param_1 + 0x30)) {
      do {
        lVar11 = *(longlong *)(param_1 + 0x28);
        uVar13 = (int)uVar15 + 1;
        puVar1 = (undefined8 *)(lVar11 + (ulonglong)uVar13 * 0x28);
        uVar8 = puVar1[1];
        uVar9 = puVar1[2];
        uVar10 = puVar1[3];
        puVar2 = (undefined8 *)(lVar11 + uVar15 * 0x28);
        *puVar2 = *puVar1;
        puVar2[1] = uVar8;
        puVar2[2] = uVar9;
        puVar2[3] = uVar10;
        *(undefined8 *)(lVar11 + 0x20 + uVar15 * 0x28) =
             *(undefined8 *)(lVar11 + 0x20 + (ulonglong)uVar13 * 0x28);
        uVar15 = (ulonglong)uVar13;
      } while (uVar13 < *(uint *)(param_1 + 0x30));
    }
    if (DAT_1400eaa18 != 0) {
      while( true ) {
        uVar13 = (uint)uVar14;
        if (DAT_1400eaa18 <= uVar14) {
          pcVar6 = (code *)swi(3);
          (*pcVar6)();
          return;
        }
        if ((*(int *)(DAT_1400eaa10 + uVar14 * 0x18) == iStack_37) &&
           (*(int *)(DAT_1400eaa10 + 4 + uVar14 * 0x18) == uStack_33)) break;
        uVar14 = (ulonglong)(uVar13 + 1);
        if (DAT_1400eaa18 <= uVar13 + 1) {
          return;
        }
      }
      if (-1 < (int)uVar13) {
        FUN_140014a30(uVar13);
      }
    }
  }
  return;
}


// ===== FUN_14001df40 @ 14001df40 size=111

void FUN_14001df40(longlong param_1,undefined8 param_2)

{
  uint uVar1;
  longlong lVar2;
  code *pcVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined4 uStackX_14;
  
  uVar1 = *(uint *)(param_1 + 0x30);
  uVar5 = 0;
  if (uVar1 != 0) {
    uStackX_14 = (int)((ulonglong)param_2 >> 0x20);
    while( true ) {
      uVar4 = (uint)uVar5;
      if (uVar1 <= uVar5) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      lVar2 = *(longlong *)(param_1 + 0x28);
      if (((*(int *)(lVar2 + 0x24 + uVar5 * 0x28) != 0) &&
          (*(int *)(lVar2 + 1 + uVar5 * 0x28) == (int)param_2)) &&
         (*(int *)(lVar2 + 5 + uVar5 * 0x28) == uStackX_14)) break;
      uVar1 = *(uint *)(param_1 + 0x30);
      uVar5 = (ulonglong)(uVar4 + 1);
      if (uVar1 <= uVar4 + 1) {
        return;
      }
    }
    if (-1 < (int)uVar4) {
      FUN_14001dd40(param_1,uVar4);
      return;
    }
  }
  return;
}


// ===== FUN_14001dfb0 @ 14001dfb0 size=107

void FUN_14001dfb0(undefined8 param_1)

{
  code *pcVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined4 uStackX_c;
  
  uVar3 = 0;
  if (DAT_140029200 != 0) {
    uStackX_c = (int)((ulonglong)param_1 >> 0x20);
    while( true ) {
      uVar2 = (uint)uVar3;
      if (DAT_140029200 <= uVar3) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      if (((*(int *)(DAT_1400291f8 + 0x24 + uVar3 * 0x28) != 0) &&
          (*(int *)(DAT_1400291f8 + 1 + uVar3 * 0x28) == (int)param_1)) &&
         (*(int *)(DAT_1400291f8 + 5 + uVar3 * 0x28) == uStackX_c)) break;
      uVar3 = (ulonglong)(uVar2 + 1);
      if (DAT_140029200 <= uVar2 + 1) {
        return;
      }
    }
    if (-1 < (int)uVar2) {
      FUN_14001dd40(0x1400291d0,uVar2);
      return;
    }
  }
  return;
}


// ===== FUN_14001e020 @ 14001e020 size=1002

undefined8 * FUN_14001e020(float *param_1,undefined8 *param_2)

{
  char cVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined8 uVar4;
  undefined1 (*pauVar5) [16];
  uint uVar6;
  bool bVar7;
  double dVar8;
  undefined1 in_ZMM2 [64];
  ulonglong uVar9;
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  float fVar12;
  float fVar13;
  undefined1 local_68 [96];
  
  *param_2 = 0;
  param_2[1] = 0;
  *(undefined4 *)(param_2 + 2) = 0;
  cVar1 = *(char *)(param_1 + 0xd);
  fVar12 = 0.0;
  auVar2 = vmaxss_avx(in_ZMM2._0_16_,ZEXT816(0) << 0x40);
  fVar13 = auVar2._0_4_;
  if (cVar1 == '\0') {
    param_1[2] = 0.0;
    param_1[3] = 0.0;
    return param_2;
  }
  if (cVar1 == '\x01') {
    if (param_1[0x16] == 0.0) goto LAB_14001e2cf;
    if ((*(char *)(param_1 + 0xe) == '\x06') && (param_1[0x18] == 0.0)) {
      uVar9 = *(ulonglong *)((longlong)param_1 + 0x41);
      if (((int)uVar9 == (int)*(undefined8 *)((longlong)param_1 + 0x39)) &&
         ((int)(uVar9 >> 0x20) ==
          (int)((ulonglong)*(undefined8 *)((longlong)param_1 + 0x39) >> 0x20))) {
        pauVar5 = FUN_140011e40((undefined1 (*) [16])local_68,uVar9);
        *(undefined8 *)((longlong)param_1 + 0x39) = *(undefined8 *)*pauVar5;
        param_1[0x819] = 0.0;
        param_1[0x81a] = 0.0;
        param_1[0x81b] = 0.0;
        param_1[0x81c] = 0.0;
        param_1[0x81d] = 0.0;
      }
    }
    auVar2 = vunpcklps_avx(ZEXT416((uint)((float)(*(ulonglong *)((longlong)param_1 + 0x39) &
                                                 0xffffffff) + (0.5f))),
                           ZEXT416((uint)((float)(*(ulonglong *)((longlong)param_1 + 0x39) >> 0x20)
                                         + (0.5f))));
    uVar9 = auVar2._0_8_;
    uVar4 = FUN_140011ca0(param_1,*(undefined8 *)((longlong)param_1 + 0x39),uVar9,fVar13);
    if ((int)uVar4 == 0) {
      return param_2;
    }
    *(undefined1 *)(param_1 + 0xd) = 2;
    *(ulonglong *)param_1 = uVar9;
    param_1[9] = 0.0;
    param_1[2] = 0.0;
    param_1[3] = 0.0;
    *(undefined4 *)param_2 = 1;
    *(undefined4 *)((longlong)param_2 + 4) = 1;
    bVar7 = fVar12 < param_1[0x13];
  }
  else {
    if (cVar1 != '\x02') {
      if (cVar1 != '\x03') {
        return param_2;
      }
      auVar10 = ZEXT416((uint)((float)(*(ulonglong *)(param_1 + 4) >> 0x20) + param_1[7]));
      auVar2 = vroundps_avx(auVar10,1);
      auVar11 = ZEXT416((uint)((float)(*(ulonglong *)(param_1 + 4) & 0xffffffff) + param_1[6]));
      auVar3 = vroundps_avx(auVar11,1);
      auVar10 = vunpcklps_avx(auVar11,auVar10);
      uVar9 = auVar10._0_8_;
      uVar4 = FUN_140011ca0(param_1,(longlong)auVar2._0_4_ << 0x20 |
                                    (longlong)auVar3._0_4_ & 0xffffffffU,uVar9,fVar13);
      if ((int)uVar4 == 0) {
        return param_2;
      }
      param_1[2] = 0.0;
      param_1[3] = 0.0;
      *(ulonglong *)param_1 = uVar9;
      *(undefined4 *)((longlong)param_2 + 0xc) = 1;
      param_1[0x819] = 0.0;
      param_1[0x81a] = 0.0;
      param_1[0x81b] = 0.0;
      param_1[0x81c] = 0.0;
      param_1[0x81d] = 0.0;
      if ((param_1[0x16] != 0.0) && (param_1[0x14] != 0.0)) {
        FUN_140012a70(&DAT_14002a8c0,(1f));
        *(undefined1 *)(param_1 + 0xd) = 1;
        return param_2;
      }
      param_1[0xe] = 0.0;
      param_1[0xf] = 0.0;
      param_1[0x10] = 0.0;
      param_1[0x11] = 0.0;
      *(ulonglong *)(param_1 + 0x12) = (ulonglong)(uint)fVar12 << 0x20;
      param_1[0x14] = 0.0;
      param_1[0x15] = 1.4013e-45;
      *(undefined1 *)(param_1 + 0xd) = 0;
      param_1[0x16] = 0.0;
      *(undefined4 *)(param_2 + 2) = 1;
      return param_2;
    }
    param_1[2] = 0.0;
    param_1[3] = 0.0;
    if (param_1[0x16] == 0.0) {
LAB_14001e2cf:
      *(undefined1 *)(param_1 + 0xd) = 3;
      param_1[0x819] = 0.0;
      param_1[0x81a] = 0.0;
      param_1[0x81b] = 0.0;
      param_1[0x81c] = 0.0;
      param_1[0x81d] = 0.0;
      return param_2;
    }
    param_1[9] = fVar13 + param_1[9];
    param_1[10] = param_1[10] - fVar13;
    dVar8 = FUN_1400066d0();
    if ((param_1[10] <= fVar12) && (DAT_1400ebb30 < dVar8 - (0.1))) {
      DAT_1400ebb30 = dVar8;
      FUN_140012a70(&DAT_14002a8d8,(0.200000003f));
      uVar6 = rdrand();
      rdrandIsValid();
      param_1[10] = ((float)(uVar6 % 10000) / (10000f)) * (0.25f) + (0.5f);
      DAT_1400ebb30 =
           (double)(((float)(uVar6 % 100000) / (100000f)) * (0.100000001f) - (0.0500000007f)) +
           DAT_1400ebb30;
    }
    bVar7 = param_1[9] < param_1[0x13];
  }
  if (!bVar7) {
    FUN_140008760((longlong)param_1,(longlong)param_2);
  }
  return param_2;
}


// ===== FUN_14001e410 @ 14001e410 size=493

void FUN_14001e410(undefined8 param_1)

{
  char *pcVar1;
  int *piVar2;
  char cVar3;
  byte bVar4;
  undefined4 uVar5;
  code *pcVar6;
  longlong lVar7;
  longlong lVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  uint uVar11;
  ulonglong uVar12;
  float fVar13;
  int iStackX_14;
  
  FUN_140005840();
  FUN_14001e600(0x1400291d0);
  fVar13 = (float)param_1;
  uVar12 = 0;
  if (DAT_140029218 != 0) {
    uVar9 = (ulonglong)DAT_1400eaa18;
    do {
      lVar8 = DAT_1400eaa10;
      if (DAT_140029218 <= uVar12) {
        pcVar6 = (code *)swi(3);
        (*pcVar6)();
        return;
      }
      uVar11 = *(uint *)(DAT_140029210 + 4 + uVar12 * 0x28);
      pcVar1 = (char *)(DAT_140029210 + uVar12 * 0x28);
      if (uVar11 < DAT_1400291e8) {
        cVar3 = *pcVar1;
        if (cVar3 == '\x01') {
          uVar10 = 0;
          if ((uint)uVar9 != 0) {
            iStackX_14 = (int)((ulonglong)*(undefined8 *)(pcVar1 + 9) >> 0x20);
            do {
              if (uVar9 <= uVar10) {
                pcVar6 = (code *)swi(3);
                (*pcVar6)();
                return;
              }
              if ((*(int *)(DAT_1400eaa10 + uVar10 * 0x18) == (int)*(undefined8 *)(pcVar1 + 9)) &&
                 (*(int *)(DAT_1400eaa10 + 4 + uVar10 * 0x18) == iStackX_14)) {
                if (-1 < (int)uVar10) {
                  if (uVar9 <= uVar10) {
                    pcVar6 = (code *)swi(3);
                    (*pcVar6)();
                    return;
                  }
                  *(undefined4 *)(DAT_1400eaa10 + 0x10 + uVar10 * 0x18) =
                       *(undefined4 *)(pcVar1 + 4);
                  lVar7 = DAT_1400291e0;
                  uVar9 = (ulonglong)*(uint *)(pcVar1 + 4);
                  if (*(char *)(lVar8 + 0x14 + uVar10 * 0x18) == '\0') {
                    if (DAT_1400291e8 <= uVar9) {
                      pcVar6 = (code *)swi(3);
                      (*pcVar6)();
                      return;
                    }
                    uVar5 = *(undefined4 *)(lVar8 + 0xc + uVar10 * 0x18);
                    *(undefined1 *)(uVar9 * 0x2080 + 0x5c + DAT_1400291e0) =
                         *(undefined1 *)(lVar8 + 8 + uVar10 * 0x18);
                    *(undefined4 *)(uVar9 * 0x2080 + 0x60 + lVar7) = uVar5;
                  }
                  else {
                    if (DAT_1400291e8 <= uVar9) {
                      pcVar6 = (code *)swi(3);
                      (*pcVar6)();
                      return;
                    }
                    lVar8 = uVar9 * 0x2080 + DAT_1400291e0;
                    *(undefined1 *)(lVar8 + 0x5c) = 0xc;
                    *(undefined4 *)(lVar8 + 0x60) = 0;
                  }
                  goto LAB_14001e5ca;
                }
                break;
              }
              uVar11 = (int)uVar10 + 1;
              uVar10 = (ulonglong)uVar11;
            } while (uVar11 < (uint)uVar9);
          }
        }
        else if (cVar3 == '\x03') {
          FUN_14000a170((longlong)pcVar1);
LAB_14001e5ca:
          uVar9 = (ulonglong)DAT_1400eaa18;
        }
        else if (cVar3 == '\x04') {
          if (DAT_1400291e8 <= uVar11) {
            pcVar6 = (code *)swi(3);
            (*pcVar6)();
            return;
          }
          lVar8 = (ulonglong)uVar11 * 0x2080 + DAT_1400291e0;
          if (*(int *)(lVar8 + 0x60) != 0) {
            bVar4 = *(byte *)(lVar8 + 0x5c);
            if (bVar4 < DAT_140029a30) {
              if ((ulonglong)DAT_140029a30 <= (ulonglong)bVar4) {
                pcVar6 = (code *)swi(3);
                (*pcVar6)();
                return;
              }
              piVar2 = (int *)(DAT_140029a28 + (ulonglong)bVar4 * 4);
              *piVar2 = *piVar2 + *(int *)(lVar8 + 0x60);
            }
            *(undefined1 *)(lVar8 + 0x5c) = 0xc;
            *(undefined4 *)(lVar8 + 0x60) = 0;
            goto LAB_14001e5ca;
          }
        }
      }
      fVar13 = (float)param_1;
      uVar11 = (int)uVar12 + 1;
      uVar12 = (ulonglong)uVar11;
    } while (uVar11 < DAT_140029218);
  }
  FUN_14001f730(fVar13);
  return;
}


// ===== FUN_14001e600 @ 14001e600 size=1441

void FUN_14001e600(longlong param_1)

{
  undefined8 *puVar1;
  ulonglong *puVar2;
  undefined8 *puVar3;
  code *pcVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  uint uVar10;
  longlong lVar11;
  longlong lVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  undefined1 *puVar15;
  longlong *plVar16;
  undefined1 *puVar17;
  undefined1 *puVar18;
  uint uVar19;
  int iVar20;
  undefined8 uVar21;
  undefined8 uVar22;
  undefined8 uVar23;
  uint uVar24;
  undefined8 local_88;
  int local_80;
  int local_7c;
  int local_78;
  uint local_70;
  undefined4 uStack_6c;
  undefined1 uStack_68;
  undefined7 uStack_67;
  undefined1 uStack_60;
  undefined2 uStack_5f;
  undefined1 uStack_5d;
  uint uStack_5c;
  undefined1 uStack_58;
  undefined2 uStack_57;
  undefined1 uStack_55;
  uint uStack_54;
  undefined4 local_50;
  undefined4 uStack_4c;
  
  uVar19 = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  if (*(int *)(param_1 + 0x18) != 0) {
    uVar24 = 0;
    do {
      uVar10 = *(uint *)(param_1 + 0x30);
      uVar14 = 0;
      if (uVar10 != 0) {
        do {
          iVar20 = (int)uVar14;
          if (uVar10 <= uVar14) {
            pcVar4 = (code *)swi(3);
            (*pcVar4)();
            return;
          }
          if (*(uint *)(*(longlong *)(param_1 + 0x28) + 0x20 + uVar14 * 0x28) == uVar19)
          goto LAB_14001e689;
          uVar10 = *(uint *)(param_1 + 0x30);
          uVar14 = (ulonglong)(iVar20 + 1U);
        } while (iVar20 + 1U < uVar10);
      }
      iVar20 = -1;
LAB_14001e689:
      if ((ulonglong)*(uint *)(param_1 + 0x18) <= (ulonglong)uVar19) {
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      FUN_14001e020((float *)((ulonglong)uVar19 * 0x2080 + *(longlong *)(param_1 + 0x10)),&local_88)
      ;
      if (iVar20 < 0) {
        local_70 = 0;
        uStack_6c = 0;
        uStack_68 = 0;
        uStack_67 = 0;
        uStack_60 = 0;
        uStack_5f = 0;
        uStack_5d = 0;
        uStack_58 = 0;
        uStack_57 = 0;
        uStack_55 = 0;
        uStack_54 = 1;
        uVar21 = 0;
        uVar22 = 0;
        lVar11 = (ulonglong)uVar24 << 0x20;
        uVar23 = 0x100000000;
        uStack_5c = uVar24;
      }
      else {
        lVar11 = (longlong)iVar20;
        if ((longlong)(ulonglong)*(uint *)(param_1 + 0x30) <= lVar11) {
          pcVar4 = (code *)swi(3);
          (*pcVar4)();
          return;
        }
        if (iVar20 < 0) {
          puVar1 = (undefined8 *)
                   (*(longlong *)(param_1 + 0x28) +
                   ((ulonglong)*(uint *)(param_1 + 0x30) + lVar11) * 0x28);
          uVar21 = *puVar1;
          uVar22 = puVar1[1];
          lVar11 = puVar1[2];
          uVar23 = puVar1[3];
        }
        else {
          puVar1 = (undefined8 *)(*(longlong *)(param_1 + 0x28) + lVar11 * 0x28);
          uVar21 = *puVar1;
          uVar22 = puVar1[1];
          lVar11 = puVar1[2];
          uVar23 = puVar1[3];
        }
      }
      if ((local_80 != 0) && (-1 < iVar20)) {
        uVar10 = *(uint *)(param_1 + 0x4c);
        if (*(uint *)(param_1 + 0x48) == uVar10) {
          uVar5 = 8;
          if (8 < uVar10 * 2) {
            uVar5 = uVar10 * 2;
          }
          if (uVar10 < uVar5) {
            puVar17 = *(undefined1 **)(param_1 + 0x40);
            plVar16 = &DAT_140029878;
            if (*(longlong **)(param_1 + 0x38) != (longlong *)0x0) {
              plVar16 = *(longlong **)(param_1 + 0x38);
            }
            puVar2 = (ulonglong *)(plVar16 + 2);
            if (puVar17 == (undefined1 *)0x0) {
              uVar14 = *puVar2 + 3 & 0xfffffffffffffffc;
              *puVar2 = uVar14;
              puVar15 = (undefined1 *)(*plVar16 + uVar14);
LAB_14001e7cb:
              *puVar2 = *puVar2 + (ulonglong)uVar5 * 0x28;
            }
            else {
              uVar14 = *puVar2;
              if (puVar17 + (ulonglong)uVar10 * 0x28 != (undefined1 *)(uVar14 + *plVar16)) {
                uVar14 = uVar14 + 3 & 0xfffffffffffffffc;
                *puVar2 = uVar14;
                puVar15 = (undefined1 *)(uVar14 + *plVar16);
                puVar18 = puVar15;
                for (lVar12 = (ulonglong)uVar10 * 0x28; lVar12 != 0; lVar12 = lVar12 + -1) {
                  *puVar18 = *puVar17;
                  puVar17 = puVar17 + 1;
                  puVar18 = puVar18 + 1;
                }
                goto LAB_14001e7cb;
              }
              *puVar2 = uVar14 + (ulonglong)(uVar5 - uVar10) * 0x28;
              puVar15 = puVar17;
            }
            *(undefined1 **)(param_1 + 0x40) = puVar15;
            *(uint *)(param_1 + 0x4c) = uVar5;
          }
        }
        local_70 = local_70 & 0xffffff00;
        uStack_67 = 0;
        uStack_60 = 0;
        uStack_5f = 0;
        uStack_5d = 0;
        uStack_5c = 0;
        uStack_58 = 0;
        uStack_57 = 0;
        uStack_55 = 0;
        uVar10 = *(uint *)(param_1 + 0x48);
        uStack_6c = 0;
        uStack_68 = 0;
        local_50 = 0;
        lVar12 = *(longlong *)(param_1 + 0x40);
        uStack_4c = 1;
        puVar2 = (ulonglong *)(lVar12 + (ulonglong)uVar10 * 0x28);
        *puVar2 = (ulonglong)local_70;
        puVar2[1] = 0;
        puVar2[2] = 0;
        puVar2[3] = (ulonglong)uVar24 << 0x20;
        *(undefined8 *)(lVar12 + 0x20 + (ulonglong)uVar10 * 0x28) = 0x100000000;
        uVar14 = (ulonglong)*(uint *)(param_1 + 0x48);
        *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) + 1;
        lVar12 = *(longlong *)(param_1 + 0x40);
        *(undefined1 *)(lVar12 + uVar14 * 0x28) = 3;
        *(uint *)(lVar12 + 4 + uVar14 * 0x28) = uVar19;
        puVar1 = (undefined8 *)(lVar12 + 8 + uVar14 * 0x28);
        *puVar1 = uVar21;
        puVar1[1] = uVar22;
        puVar1[2] = lVar11;
        puVar1[3] = uVar23;
        uStack_54 = uVar24;
      }
      if (local_7c != 0) {
        uVar10 = *(uint *)(param_1 + 0x4c);
        if (*(uint *)(param_1 + 0x48) == uVar10) {
          uVar5 = 8;
          if (8 < uVar10 * 2) {
            uVar5 = uVar10 * 2;
          }
          if (uVar10 < uVar5) {
            puVar17 = *(undefined1 **)(param_1 + 0x40);
            plVar16 = &DAT_140029878;
            if (*(longlong **)(param_1 + 0x38) != (longlong *)0x0) {
              plVar16 = *(longlong **)(param_1 + 0x38);
            }
            puVar2 = (ulonglong *)(plVar16 + 2);
            if (puVar17 == (undefined1 *)0x0) {
              uVar14 = *puVar2 + 3 & 0xfffffffffffffffc;
              *puVar2 = uVar14;
              puVar15 = (undefined1 *)(*plVar16 + uVar14);
LAB_14001e8fa:
              *puVar2 = *puVar2 + (ulonglong)uVar5 * 0x28;
            }
            else {
              uVar14 = *puVar2;
              if (puVar17 + (ulonglong)uVar10 * 0x28 != (undefined1 *)(uVar14 + *plVar16)) {
                uVar14 = uVar14 + 3 & 0xfffffffffffffffc;
                *puVar2 = uVar14;
                puVar15 = (undefined1 *)(uVar14 + *plVar16);
                puVar18 = puVar15;
                for (lVar12 = (ulonglong)uVar10 * 0x28; lVar12 != 0; lVar12 = lVar12 + -1) {
                  *puVar18 = *puVar17;
                  puVar17 = puVar17 + 1;
                  puVar18 = puVar18 + 1;
                }
                goto LAB_14001e8fa;
              }
              *puVar2 = uVar14 + (ulonglong)(uVar5 - uVar10) * 0x28;
              puVar15 = puVar17;
            }
            *(undefined1 **)(param_1 + 0x40) = puVar15;
            *(uint *)(param_1 + 0x4c) = uVar5;
          }
        }
        local_70 = local_70 & 0xffffff00;
        uStack_67 = 0;
        uStack_60 = 0;
        uStack_5f = 0;
        uStack_5d = 0;
        uStack_5c = 0;
        uStack_58 = 0;
        uStack_57 = 0;
        uStack_55 = 0;
        uVar10 = *(uint *)(param_1 + 0x48);
        uStack_6c = 0;
        uStack_68 = 0;
        local_50 = 0;
        lVar12 = *(longlong *)(param_1 + 0x40);
        uStack_4c = 1;
        puVar2 = (ulonglong *)(lVar12 + (ulonglong)uVar10 * 0x28);
        *puVar2 = (ulonglong)local_70;
        puVar2[1] = 0;
        puVar2[2] = 0;
        puVar2[3] = (ulonglong)uVar24 << 0x20;
        *(undefined8 *)(lVar12 + 0x20 + (ulonglong)uVar10 * 0x28) = 0x100000000;
        uVar14 = (ulonglong)*(uint *)(param_1 + 0x48);
        *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) + 1;
        lVar12 = *(longlong *)(param_1 + 0x40);
        *(undefined1 *)(lVar12 + uVar14 * 0x28) = 4;
        *(uint *)(lVar12 + 4 + uVar14 * 0x28) = uVar19;
        puVar1 = (undefined8 *)(lVar12 + 8 + uVar14 * 0x28);
        *puVar1 = uVar21;
        puVar1[1] = uVar22;
        puVar1[2] = lVar11;
        puVar1[3] = uVar23;
        uStack_54 = uVar24;
      }
      if ((local_78 != 0) && (-1 < iVar20)) {
        uVar14 = (ulonglong)*(uint *)(param_1 + 0x30);
        lVar11 = (longlong)iVar20;
        if ((longlong)uVar14 <= lVar11) {
          pcVar4 = (code *)swi(3);
          (*pcVar4)();
          return;
        }
        if (iVar20 < 0) {
          lVar11 = uVar14 + lVar11;
        }
        uVar13 = 0;
        puVar1 = (undefined8 *)(*(longlong *)(param_1 + 0x28) + lVar11 * 0x28);
        uVar21 = *puVar1;
        uVar22 = puVar1[1];
        uVar23 = puVar1[2];
        uVar6 = puVar1[3];
        if (*(uint *)(param_1 + 0x30) != 0) {
          do {
            if (uVar14 <= uVar13) {
              pcVar4 = (code *)swi(3);
              (*pcVar4)();
              return;
            }
            lVar11 = *(longlong *)(param_1 + 0x28);
            if (*(uint *)(lVar11 + 0x20 + uVar13 * 0x28) == uVar19) {
              *(undefined4 *)(lVar11 + 0x20 + uVar13 * 0x28) = 0xffffffff;
              if ((*(int *)(lVar11 + 0x18 + uVar13 * 0x28) == 0) &&
                 (*(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + -1,
                 (uint)uVar13 < *(uint *)(param_1 + 0x30))) {
                do {
                  lVar11 = *(longlong *)(param_1 + 0x28);
                  uVar10 = (int)uVar13 + 1;
                  uVar14 = (ulonglong)uVar10;
                  puVar1 = (undefined8 *)(lVar11 + uVar14 * 0x28);
                  uVar7 = puVar1[1];
                  uVar8 = puVar1[2];
                  uVar9 = puVar1[3];
                  puVar3 = (undefined8 *)(lVar11 + uVar13 * 0x28);
                  *puVar3 = *puVar1;
                  puVar3[1] = uVar7;
                  puVar3[2] = uVar8;
                  puVar3[3] = uVar9;
                  *(undefined8 *)(lVar11 + 0x20 + uVar13 * 0x28) =
                       *(undefined8 *)(lVar11 + 0x20 + uVar14 * 0x28);
                  uVar13 = uVar14;
                } while (uVar10 < *(uint *)(param_1 + 0x30));
              }
              break;
            }
            uVar14 = (ulonglong)*(uint *)(param_1 + 0x30);
            uVar10 = (uint)uVar13 + 1;
            uVar13 = (ulonglong)uVar10;
          } while (uVar10 < *(uint *)(param_1 + 0x30));
        }
        uVar10 = *(uint *)(param_1 + 0x4c);
        if (*(uint *)(param_1 + 0x48) == uVar10) {
          uVar5 = 8;
          if (8 < uVar10 * 2) {
            uVar5 = uVar10 * 2;
          }
          if (uVar10 < uVar5) {
            puVar17 = *(undefined1 **)(param_1 + 0x40);
            plVar16 = &DAT_140029878;
            if (*(longlong **)(param_1 + 0x38) != (longlong *)0x0) {
              plVar16 = *(longlong **)(param_1 + 0x38);
            }
            puVar2 = (ulonglong *)(plVar16 + 2);
            if (puVar17 == (undefined1 *)0x0) {
              uVar14 = *puVar2 + 3 & 0xfffffffffffffffc;
              *puVar2 = uVar14;
              puVar15 = (undefined1 *)(*plVar16 + uVar14);
LAB_14001ead3:
              *puVar2 = *puVar2 + (ulonglong)uVar5 * 0x28;
            }
            else {
              uVar14 = *puVar2;
              if (puVar17 + (ulonglong)uVar10 * 0x28 != (undefined1 *)(uVar14 + *plVar16)) {
                uVar14 = uVar14 + 3 & 0xfffffffffffffffc;
                *puVar2 = uVar14;
                puVar15 = (undefined1 *)(uVar14 + *plVar16);
                puVar18 = puVar15;
                for (lVar11 = (ulonglong)uVar10 * 0x28; lVar11 != 0; lVar11 = lVar11 + -1) {
                  *puVar18 = *puVar17;
                  puVar17 = puVar17 + 1;
                  puVar18 = puVar18 + 1;
                }
                goto LAB_14001ead3;
              }
              *puVar2 = uVar14 + (ulonglong)(uVar5 - uVar10) * 0x28;
              puVar15 = puVar17;
            }
            *(undefined1 **)(param_1 + 0x40) = puVar15;
            *(uint *)(param_1 + 0x4c) = uVar5;
          }
        }
        local_70 = local_70 & 0xffffff00;
        uStack_67 = 0;
        uStack_60 = 0;
        uStack_5f = 0;
        uStack_5d = 0;
        uStack_5c = 0;
        uStack_58 = 0;
        uStack_57 = 0;
        uStack_55 = 0;
        uVar10 = *(uint *)(param_1 + 0x48);
        uStack_6c = 0;
        uStack_68 = 0;
        local_50 = 0;
        lVar11 = *(longlong *)(param_1 + 0x40);
        uStack_4c = 1;
        puVar2 = (ulonglong *)(lVar11 + (ulonglong)uVar10 * 0x28);
        *puVar2 = (ulonglong)local_70;
        puVar2[1] = 0;
        puVar2[2] = 0;
        puVar2[3] = (ulonglong)uVar24 << 0x20;
        *(undefined8 *)(lVar11 + 0x20 + (ulonglong)uVar10 * 0x28) = 0x100000000;
        uVar14 = (ulonglong)*(uint *)(param_1 + 0x48);
        *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) + 1;
        lVar11 = *(longlong *)(param_1 + 0x40);
        *(undefined1 *)(lVar11 + uVar14 * 0x28) = 5;
        *(uint *)(lVar11 + 4 + uVar14 * 0x28) = uVar19;
        puVar1 = (undefined8 *)(lVar11 + 8 + uVar14 * 0x28);
        *puVar1 = uVar21;
        puVar1[1] = uVar22;
        puVar1[2] = uVar23;
        puVar1[3] = uVar6;
        uStack_54 = uVar24;
      }
      uVar19 = uVar19 + 1;
    } while (uVar19 < *(uint *)(param_1 + 0x18));
  }
  FUN_1400036d0(param_1);
  return;
}


// ===== FUN_14001ebb0 @ 14001ebb0 size=1001

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_14001ebb0(float param_1)

{
  undefined8 *puVar1;
  float fVar2;
  int *piVar3;
  code *pcVar4;
  uint uVar5;
  ulonglong uVar6;
  uint *puVar8;
  ulonglong uVar9;
  int *piVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  ulonglong uVar14;
  undefined8 *puVar15;
  double dVar16;
  undefined1 auVar17 [16];
  float fVar18;
  ulonglong uVar7;
  
  dVar16 = FUN_1400066d0();
  auVar17._8_8_ = 0;
  auVar17._0_8_ = dVar16;
  auVar17 = vroundpd_avx(auVar17,3);
  DAT_14002a39c = (uint)(longlong)((dVar16 - auVar17._0_8_) * (100.0));
  uVar6 = (ulonglong)DAT_14002a888;
  puVar1 = DAT_14002a880 + uVar6;
  if (DAT_14002a880 == puVar1) {
LAB_14001eef5:
    _DAT_14002a398 = _DAT_14002a398 + 1;
    return uVar6;
  }
  dVar16 = dVar16 * (10.0);
  uVar14 = 0;
  fVar18 = 0.0;
  puVar15 = DAT_14002a880;
LAB_14001ec40:
  piVar3 = (int *)*puVar15;
  puVar8 = *(uint **)(piVar3 + 0x4a);
  piVar3[0xe] = (int)(((longlong)dVar16 & 0xffffffffU) %
                     (ulonglong)*(uint *)(*(longlong *)(piVar3 + 4) + 0x18));
  if (puVar8 == (uint *)0x0) goto LAB_14001ed88;
  uVar5 = *puVar8;
  if (uVar5 == 0) {
    if ((piVar3[0x10] != 0) || (piVar3[0x12] != 0)) goto LAB_14001ec9c;
  }
  else {
    uVar6 = uVar14;
    if (uVar5 != 0) {
      do {
        if ((uint)piVar3[uVar6 * 2 + 0x10] < puVar8[uVar6 * 2 + 2]) goto LAB_14001ed89;
        uVar12 = (int)uVar6 + 1;
        uVar6 = (ulonglong)uVar12;
      } while (uVar12 < uVar5);
    }
LAB_14001ec9c:
    fVar2 = (float)piVar3[0x4c];
    piVar3[0x4c] = (int)(fVar2 - param_1);
    if ((fVar2 - param_1 <= fVar18) && (piVar3[0x4c] = 0, !NAN(fVar18))) {
      if (puVar8 == (uint *)0x0) {
LAB_14001ed88:
        pcVar4 = (code *)swi(3);
        uVar6 = (*pcVar4)();
        return uVar6;
      }
      if (*puVar8 == 0) {
        if (*piVar3 == 6) {
          if (piVar3[0x10] != 0) {
            *(undefined8 *)(piVar3 + 0x15) = *(undefined8 *)(piVar3 + 0xf);
            piVar3[0x10] = 0;
          }
          if (piVar3[0x12] != 0) {
            *(undefined8 *)(piVar3 + 0x17) = *(undefined8 *)(piVar3 + 0x11);
            piVar3[0x12] = 0;
            piVar3[0x4c] = puVar8[9];
            goto LAB_14001ed89;
          }
        }
        else {
          *(undefined8 *)(piVar3 + 0x15) = *(undefined8 *)(piVar3 + 0xf);
          piVar3[0x10] = 0;
        }
        piVar3[0x4c] = puVar8[9];
      }
      else if ((((char)piVar3[0x15] == (char)puVar8[7]) || (piVar3[0x16] == 0)) &&
              ((uint)piVar3[0x16] < (uint)piVar3[0x19])) {
        uVar6 = uVar14;
        if (*puVar8 != 0) {
          do {
            uVar5 = (int)uVar6 + 1;
            piVar3[uVar6 * 2 + 0x10] = piVar3[uVar6 * 2 + 0x10] - puVar8[uVar6 * 2 + 2];
            puVar8 = *(uint **)(piVar3 + 0x4a);
            uVar6 = (ulonglong)uVar5;
          } while (uVar5 < *puVar8);
        }
        *(char *)(piVar3 + 0x15) = (char)puVar8[7];
        piVar3[0x16] = piVar3[0x16] + puVar8[8];
        if (puVar8 == (uint *)0x0) goto LAB_14001ed88;
        piVar3[0x4c] = puVar8[9];
      }
    }
  }
LAB_14001ed89:
  if ((piVar3[0x16] != 0) || (piVar3[0x18] != 0)) {
    if ((((*piVar3 == 1) && (((*(byte *)(piVar3 + 0x38) & 0x40) != 0 && (piVar3[8] == 1)))) &&
        (DAT_140029984 < 0x14)) && (piVar3[0x16] = piVar3[0x16] + -1, (char)piVar3[0x15] == '\r')) {
      DAT_140029984 = DAT_140029984 + 1;
    }
    uVar5 = piVar3[0x34];
    uVar6 = uVar14;
    if (uVar5 != 0) {
      do {
        uVar9 = (ulonglong)(uint)(piVar3[0x35] + (int)uVar6) % (ulonglong)uVar5;
        piVar10 = *(int **)(piVar3 + uVar9 * 4 + 0x1a);
        if (((piVar10 != (int *)0x0) && (*(longlong *)(piVar10 + 2) != 0)) &&
           (*(longlong *)(piVar10 + 2) == *(longlong *)(piVar3 + uVar9 * 4 + 0x1c))) {
          if (piVar3[0x16] != 0) {
            puVar8 = *(uint **)(piVar10 + 0x4a);
            if (puVar8 == (uint *)0x0) {
              pcVar4 = (code *)swi(3);
              uVar6 = (*pcVar4)();
              return uVar6;
            }
            if (*puVar8 != 0) {
              uVar7 = uVar14;
              do {
                if ((char)puVar8[uVar7 * 2 + 1] == (char)piVar3[0x15]) {
                  if (((int)uVar7 != -1) && (puVar8[uVar7 * 2 + 2] != piVar10[uVar7 * 2 + 0x10]))
                  goto LAB_14001ef09;
                  break;
                }
                uVar5 = (int)uVar7 + 1;
                uVar7 = (ulonglong)uVar5;
              } while (uVar5 < *puVar8);
              goto LAB_14001ee66;
            }
          }
LAB_14001ef09:
          piVar3[0x35] = (int)uVar9 + 1;
          uVar6 = uVar14;
          iVar13 = 0;
          if (piVar3[0x34] != 0) goto LAB_14001ef30;
          goto LAB_14001ef5b;
        }
LAB_14001ee66:
        uVar5 = piVar3[0x34];
        uVar12 = (int)uVar6 + 1;
        uVar6 = (ulonglong)uVar12;
      } while (uVar12 < uVar5);
    }
    piVar3[0x35] = piVar3[0x35] + 1;
  }
  goto LAB_14001ee7e;
  while (uVar5 = (int)uVar6 + 1, uVar6 = (ulonglong)uVar5, iVar13 = 0, uVar5 < (uint)piVar3[0x34]) {
LAB_14001ef30:
    if ((*(int **)(piVar3 + uVar6 * 4 + 0x1a) == piVar10) &&
       ((*(char *)(uVar6 + 200 + (longlong)piVar3) - 0x10U & 0xef) == 0)) {
      iVar13 = 1;
      break;
    }
  }
LAB_14001ef5b:
  iVar11 = 0;
  if (*piVar3 == 6) {
    if (iVar13 != 0) {
      if (*piVar10 == 6) {
        iVar11 = iVar13;
      }
      FUN_14001cc50((longlong)piVar10,(char *)(piVar3 + 0x17),iVar11);
      goto LAB_14001ee7e;
    }
  }
  else if (*piVar10 == 6) {
    iVar11 = iVar13;
  }
  FUN_14001cc50((longlong)piVar10,(char *)(piVar3 + 0x15),iVar11);
LAB_14001ee7e:
  uVar6 = (ulonglong)(DAT_14002a39c >> 3) / (ulonglong)*(uint *)(*(longlong *)(piVar3 + 4) + 0x18);
  piVar3[0xe] = (DAT_14002a39c >> 3) % *(uint *)(*(longlong *)(piVar3 + 4) + 0x18);
  if ((*piVar3 == 10) && (piVar3[0x58] != 0)) {
    piVar10 = piVar3 + 0x4e;
    uVar9 = uVar14;
    do {
      uVar6 = FUN_140013770(**(ulonglong **)piVar10);
      uVar5 = (int)uVar9 + 1;
      uVar9 = (ulonglong)uVar5;
      piVar10 = piVar10 + 2;
    } while (uVar5 < (uint)piVar3[0x58]);
  }
  puVar15 = puVar15 + 1;
  if (puVar15 == puVar1) goto LAB_14001eef5;
  goto LAB_14001ec40;
}


// ===== FUN_14001efa0 @ 14001efa0 size=570

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14001efa0(void)

{
  undefined8 uVar1;
  bool bVar2;
  bool bVar3;
  float fVar4;
  float fVar5;
  tagPOINT local_res8 [4];
  
  bVar2 = DAT_140029801 != '\0';
  fVar4 = (float)_DAT_1400296dc;
  _DAT_1400296dc = 0;
  bVar3 = DAT_140029802 != '\0';
  fVar5 = (float)_DAT_1400296e0;
  _DAT_1400296e0 = 0;
  if (DAT_140029801 == '\0') {
    DAT_1400296f8 = 0;
  }
  if (DAT_1400298b8 == 0) {
    if (((((DAT_140029710 != '\0') && (bVar2)) || (DAT_140029803 != '\0')) &&
        ((DAT_1400296f8 == 0 && (DAT_14002965c == 0)))) && (DAT_140029af0 == 0)) {
      DAT_140029630 = DAT_140029630 - fVar4;
      DAT_140029634 = DAT_140029634 - fVar5;
      DAT_1400296ec = 1;
      DAT_1400296fc = 0;
      DAT_1400298a8 = 0;
      FUN_1400057b0();
      return;
    }
    DAT_1400296ec = 0;
    if (((DAT_140029710 != '\0') || (DAT_14002965c != 0)) ||
       ((DAT_140029af0 != 0 || (DAT_1400296f8 != 0)))) {
      if (bVar2) {
        _DAT_1400296dc = 0;
        _DAT_1400296e0 = 0;
        DAT_1400296ec = 0;
        return;
      }
      if (bVar3) {
        _DAT_1400296dc = 0;
        _DAT_1400296e0 = 0;
        DAT_1400296ec = 0;
        return;
      }
    }
    else {
      if (bVar2) {
        FUN_140002d30(DAT_14002962c);
        return;
      }
      DAT_1400298a8 = 0;
      if (bVar3) {
        local_res8[0].x = 0;
        local_res8[0].y = 0;
        if (DAT_14002962c != '\0') {
          uVar1 = FUN_140011060(local_res8);
          if ((int)uVar1 == 0) {
            return;
          }
          if (DAT_1400296fc != 0) {
            if (local_res8[0].x == DAT_1400298a0) {
              if (local_res8[0].y == DAT_1400298a4) {
                return;
              }
            }
          }
          _DAT_1400298a0 = local_res8[0];
          DAT_1400296fc = 1;
          FUN_1400029d0('\x01',(ulonglong)local_res8[0],DAT_140029980,DAT_140029664,DAT_140029660);
          return;
        }
        uVar1 = FUN_140011060(local_res8);
        if ((int)uVar1 == 0) {
          return;
        }
        if (DAT_1400296fc != 0) {
          if (local_res8[0].x == DAT_1400298a0) {
            if (local_res8[0].y == DAT_1400298a4) {
              return;
            }
          }
        }
        _DAT_1400298a0 = local_res8[0];
        DAT_1400296fc = 1;
        FUN_14001dfb0(local_res8[0]);
        return;
      }
    }
    DAT_1400298a8 = 0;
    DAT_1400296fc = 0;
  }
  else if (!bVar3) {
    DAT_1400298b8 = 0;
    DAT_1400298a8 = 0;
    DAT_1400296fc = 0;
    return;
  }
  return;
}


// ===== FUN_14001f1e0 @ 14001f1e0 size=1355

void FUN_14001f1e0(int *param_1)

{
  byte bVar1;
  undefined8 uVar2;
  code *pcVar3;
  uint uVar4;
  uint uVar5;
  longlong lVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int *piVar13;
  uint local_res10;
  int local_60;
  
  if (param_1 == (int *)0x0) {
    return;
  }
  piVar13 = param_1 + 0x1a;
  for (lVar6 = 0x60; lVar6 != 0; lVar6 = lVar6 + -1) {
    *(undefined1 *)piVar13 = 0;
    piVar13 = (int *)((longlong)piVar13 + 1);
  }
  uVar5 = param_1[10];
  piVar13 = param_1 + 0x36;
  uVar9 = 0;
  param_1[0x34] = 0;
  local_res10 = 0;
  uVar12 = DAT_140029a88._4_4_;
  uVar8 = DAT_1400299a8;
  uVar4 = (uint)DAT_140029a88;
  do {
    if (5 < uVar9) break;
    bVar1 = *(byte *)(piVar13 + 2);
    if (bVar1 != 0) {
      local_60 = (int)*(undefined8 *)piVar13;
      iVar7 = (int)((ulonglong)*(undefined8 *)piVar13 >> 0x20);
      if ((bVar1 & 0x20) != 0) {
        uVar11 = param_1[8] + local_60;
        uVar10 = param_1[9] + iVar7 + 1;
        if ((((uVar11 < uVar4) && (uVar10 < uVar12)) && ((uint)param_1[10] < uVar8)) &&
           ((*(byte *)((ulonglong)(param_1[10] * uVar12 * uVar4) +
                      (ulonglong)(uVar10 * uVar4 + uVar11) + DAT_140029aa0) & 1) != 0)) {
          lVar6 = FUN_140009990(CONCAT44(uVar10,uVar11),uVar5);
          *(undefined1 *)((ulonglong)(uint)param_1[0x34] + 200 + (longlong)param_1) = 0x20;
          uVar9 = param_1[0x34];
          uVar2 = *(undefined8 *)(lVar6 + 8);
          *(longlong *)(param_1 + (ulonglong)uVar9 * 4 + 0x1a) = lVar6;
          *(undefined8 *)(param_1 + (ulonglong)uVar9 * 4 + 0x1c) = uVar2;
          param_1[0x34] = param_1[0x34] + 1;
          uVar9 = param_1[0x34];
          uVar12 = DAT_140029a88._4_4_;
          uVar8 = DAT_1400299a8;
          uVar4 = (uint)DAT_140029a88;
        }
      }
      if ((uVar9 < 6) && ((bVar1 & 0x10) != 0)) {
        uVar10 = param_1[9] + -1 + iVar7;
        uVar11 = param_1[8] + local_60;
        if ((uVar11 < uVar4) && ((uVar10 < uVar12 && ((uint)param_1[10] < uVar8)))) {
          if ((*(byte *)((ulonglong)(param_1[10] * uVar12 * uVar4) +
                        (ulonglong)(uVar10 * uVar4 + uVar11) + DAT_140029aa0) >> 1 & 1) != 0) {
            lVar6 = FUN_140009990(CONCAT44(uVar10,uVar11),uVar5);
            *(undefined1 *)((ulonglong)(uint)param_1[0x34] + 200 + (longlong)param_1) = 0x10;
            uVar9 = param_1[0x34];
            uVar2 = *(undefined8 *)(lVar6 + 8);
            *(longlong *)(param_1 + (ulonglong)uVar9 * 4 + 0x1a) = lVar6;
            *(undefined8 *)(param_1 + (ulonglong)uVar9 * 4 + 0x1c) = uVar2;
            param_1[0x34] = param_1[0x34] + 1;
            uVar9 = param_1[0x34];
            uVar12 = DAT_140029a88._4_4_;
            uVar8 = DAT_1400299a8;
            uVar4 = (uint)DAT_140029a88;
          }
          goto LAB_14001f42f;
        }
LAB_14001f43f:
        if ((bVar1 & 0x40) == 0) goto LAB_14001f50f;
        uVar11 = param_1[8] + -1 + local_60;
        uVar10 = param_1[9] + iVar7;
        if (((uVar11 < uVar4) && (uVar10 < uVar12)) && ((uint)param_1[10] < uVar8)) {
          if ((*(byte *)((ulonglong)(param_1[10] * uVar12 * uVar4) +
                        (ulonglong)(uVar10 * uVar4 + uVar11) + DAT_140029aa0) >> 3 & 1) != 0) {
            lVar6 = FUN_140009990(CONCAT44(uVar10,uVar11),uVar5);
            *(undefined1 *)((ulonglong)(uint)param_1[0x34] + 200 + (longlong)param_1) = 0x40;
            uVar9 = param_1[0x34];
            uVar2 = *(undefined8 *)(lVar6 + 8);
            *(longlong *)(param_1 + (ulonglong)uVar9 * 4 + 0x1a) = lVar6;
            *(undefined8 *)(param_1 + (ulonglong)uVar9 * 4 + 0x1c) = uVar2;
            param_1[0x34] = param_1[0x34] + 1;
            uVar9 = param_1[0x34];
            uVar12 = DAT_140029a88._4_4_;
            uVar8 = DAT_1400299a8;
            uVar4 = (uint)DAT_140029a88;
          }
          goto LAB_14001f50f;
        }
      }
      else {
LAB_14001f42f:
        if (uVar9 < 6) goto LAB_14001f43f;
LAB_14001f50f:
        if (5 < uVar9) goto LAB_14001f5e7;
      }
      if ((char)bVar1 < '\0') {
        uVar10 = param_1[8] + 1 + local_60;
        uVar11 = param_1[9] + iVar7;
        if (((uVar10 < uVar4) && (uVar11 < uVar12)) &&
           (((uint)param_1[10] < uVar8 &&
            ((*(byte *)((ulonglong)(param_1[10] * uVar12 * uVar4) +
                       (ulonglong)(uVar11 * uVar4 + uVar10) + DAT_140029aa0) >> 2 & 1) != 0)))) {
          lVar6 = FUN_140009990(CONCAT44(uVar11,uVar10),uVar5);
          *(undefined1 *)((ulonglong)(uint)param_1[0x34] + 200 + (longlong)param_1) = 0x80;
          uVar9 = param_1[0x34];
          uVar2 = *(undefined8 *)(lVar6 + 8);
          *(longlong *)(param_1 + (ulonglong)uVar9 * 4 + 0x1a) = lVar6;
          *(undefined8 *)(param_1 + (ulonglong)uVar9 * 4 + 0x1c) = uVar2;
          param_1[0x34] = param_1[0x34] + 1;
          uVar9 = param_1[0x34];
          uVar12 = DAT_140029a88._4_4_;
          uVar8 = DAT_1400299a8;
          uVar4 = (uint)DAT_140029a88;
        }
      }
    }
LAB_14001f5e7:
    piVar13 = (int *)((longlong)piVar13 + 9);
    local_res10 = local_res10 + 1;
  } while (local_res10 < 8);
  if (*param_1 == 7) {
    lVar6 = *(longlong *)(param_1 + 8);
    uVar9 = param_1[10] + 1;
    uVar5 = (uint)lVar6;
    if (uVar4 <= uVar5) {
      return;
    }
    uVar10 = (uint)((ulonglong)lVar6 >> 0x20);
    if (uVar12 <= uVar10) {
      return;
    }
    if (uVar8 <= uVar9) {
      return;
    }
    if ((int)uVar5 < 0) {
      return;
    }
    if (lVar6 < 0) {
      return;
    }
    if ((int)uVar9 < 0) {
      return;
    }
    if (uVar4 <= uVar5) {
      return;
    }
    if (uVar12 <= uVar10) {
      return;
    }
    uVar5 = *(uint *)(DAT_140029a98 + (ulonglong)((uVar9 * uVar12 + uVar10) * uVar4 + uVar5) * 4);
    if (uVar5 == 0) {
      return;
    }
    if (DAT_14002a870 <= uVar5) {
      return;
    }
    if ((ulonglong)DAT_14002a870 <= (ulonglong)uVar5) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    piVar13 = *(int **)(DAT_14002a868 + (ulonglong)uVar5 * 8);
    if (piVar13 == (int *)0x0) {
      return;
    }
    if (*piVar13 != 9) {
      return;
    }
    uVar5 = param_1[0x34];
    uVar2 = *(undefined8 *)(piVar13 + 2);
    *(int **)(param_1 + (ulonglong)uVar5 * 4 + 0x1a) = piVar13;
    *(undefined8 *)(param_1 + (ulonglong)uVar5 * 4 + 0x1c) = uVar2;
  }
  else {
    if (*param_1 != 8) {
      return;
    }
    piVar13 = (int *)FUN_140009990(*(longlong *)(param_1 + 8),param_1[10] - 1);
    if (piVar13 == (int *)0x0) {
      return;
    }
    if (*piVar13 != 9) {
      return;
    }
    uVar5 = param_1[0x34];
    uVar2 = *(undefined8 *)(piVar13 + 2);
    *(int **)(param_1 + (ulonglong)uVar5 * 4 + 0x1a) = piVar13;
    *(undefined8 *)(param_1 + (ulonglong)uVar5 * 4 + 0x1c) = uVar2;
  }
  param_1[0x34] = param_1[0x34] + 1;
  return;
}


// ===== FUN_14001f730 @ 14001f730 size=425

void FUN_14001f730(float param_1)

{
  ulonglong uVar1;
  code *pcVar2;
  float fVar3;
  float fVar4;
  bool bVar5;
  float fVar6;
  float fVar7;
  longlong lVar8;
  uint uVar9;
  ulonglong uVar10;
  uint uVar11;
  
  fVar7 = (-10f);
  fVar6 = (10f);
  if (0.0 < param_1) {
    uVar11 = 0;
    uVar10 = 0;
    if (DAT_1400291e8 != 0) {
      do {
        if (DAT_1400291e8 <= uVar10) {
          pcVar2 = (code *)swi(3);
          (*pcVar2)();
          return;
        }
        lVar8 = uVar10 * 0x2080;
        if (((*(char *)(lVar8 + 0x34 + DAT_1400291e0) != '\0') ||
            (*(int *)(lVar8 + 0x58 + DAT_1400291e0) != 0)) ||
           (uVar1 = *(ulonglong *)(lVar8 + 0x10 + DAT_1400291e0),
           fVar3 = *(float *)(lVar8 + DAT_1400291e0) -
                   ((float)(uVar1 & 0xffffffff) + *(float *)(lVar8 + 0x18 + DAT_1400291e0)),
           fVar4 = *(float *)(lVar8 + 4 + DAT_1400291e0) -
                   ((float)(uVar1 >> 0x20) + *(float *)(lVar8 + 0x1c + DAT_1400291e0)),
           (9.99999975e-05f) < fVar4 * fVar4 + fVar3 * fVar3)) {
          bVar5 = false;
        }
        else {
          bVar5 = true;
        }
        uVar9 = uVar11 + 1;
        if (!bVar5) {
          uVar9 = uVar11;
        }
        uVar11 = uVar9;
        uVar9 = (int)uVar10 + 1;
        uVar10 = (ulonglong)uVar9;
      } while (uVar9 < DAT_1400291e8);
      if (((uVar11 != 0) && (0xb < DAT_140029a30)) && (2 < *(uint *)(DAT_140029a28 + 0x2c))) {
        DAT_14004a9e4 = (float)uVar11 * param_1 + DAT_14004a9e4;
        uVar11 = DAT_140029a30;
        lVar8 = DAT_140029a28;
        while (((fVar6 <= DAT_14004a9e4 && (0xb < uVar11)) && (2 < *(uint *)(lVar8 + 0x2c)))) {
          DAT_14004a9e4 = DAT_14004a9e4 + fVar7;
          if ((0xb < uVar11) && (2 < *(uint *)(lVar8 + 0x2c))) {
            if (uVar11 < 0xc) {
              pcVar2 = (code *)swi(3);
              (*pcVar2)();
              return;
            }
            *(int *)(lVar8 + 0x2c) = *(int *)(lVar8 + 0x2c) + -3;
            lVar8 = DAT_140029a28;
            uVar11 = DAT_140029a30;
          }
          if (0xc < uVar11) {
            *(int *)(lVar8 + 0x30) = *(int *)(lVar8 + 0x30) + 1;
            uVar11 = DAT_140029a30;
            lVar8 = DAT_140029a28;
          }
        }
      }
    }
  }
  return;
}


// ===== FUN_14001f8e0 @ 14001f8e0 size=17

void FUN_14001f8e0(void)

{
  code *pcVar1;
  
  FUN_140012c60("WASAPI function failed!\n");
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ===== FUN_14001f900 @ 14001f900 size=1342

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

LRESULT FUN_14001f900(HWND param_1,uint param_2,ulonglong param_3,HRAWINPUT param_4)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  HDC hdc;
  LRESULT LVar5;
  HWND pHVar6;
  ulonglong uVar7;
  int *pData;
  undefined1 auVar8 [16];
  undefined1 auVar9 [64];
  uint local_res10 [2];
  tagPOINT local_98;
  float local_90;
  undefined8 local_78;
  tagPAINTSTRUCT local_68;
  
  if (param_2 < 0x15) {
    if (param_2 == 0x14) {
      return 1;
    }
    if (param_2 == 2) {
      PostQuitMessage(0);
      return 0;
    }
    if (param_2 == 5) {
      _DAT_14002966c = (uint)param_4 & 0xffff;
      _DAT_1400296bc = (uint)((ulonglong)param_4 >> 0x10) & 0xffff;
      _DAT_140029698 = -_DAT_1400296bc;
      _DAT_140029694 = _DAT_14002966c;
      DAT_1400296d0 = _DAT_14002966c;
      DAT_1400296d4 = _DAT_1400296bc;
      if (DAT_1400296c0 != (HBITMAP)0x0) {
        DeleteObject(DAT_1400296c0);
      }
      DAT_1400296c0 =
           CreateDIBSection(DAT_140029688,(BITMAPINFO *)&DAT_140029690,0,(void **)&local_98,
                            (HANDLE)0x0,0);
      DAT_1400296c8 = local_98;
      SelectObject(DAT_140029688,DAT_1400296c0);
      return 0;
    }
    if (param_2 == 0xf) {
      hdc = BeginPaint(DAT_140029680,&local_68);
      BitBlt(hdc,0,0,DAT_1400296d0,DAT_1400296d4,DAT_140029688,0,0,0xcc0020);
      EndPaint(DAT_140029680,&local_68);
      return 0;
    }
    if (param_2 == 0x10) {
      DAT_1400296d8 = 1;
      return 0;
    }
  }
  else {
    if (param_2 == 0xff) {
      pHVar6 = GetForegroundWindow();
      if (pHVar6 != DAT_140029680) {
        return 0;
      }
      local_res10[0] = 0x30;
      GetRawInputData(param_4,0x10000003,(LPVOID)0x0,local_res10,0x18);
      lVar1 = DAT_140029828;
      if (DAT_140029828 == -1) {
        return 0;
      }
      uVar7 = DAT_140029828 + 7U & 0xfffffffffffffff8;
      pData = (int *)(DAT_140029818 + uVar7);
      DAT_140029828 = local_res10[0] + uVar7;
      GetRawInputData(param_4,0x10000003,pData,local_res10,0x18);
      if (*pData != 0) {
        DAT_140029828 = lVar1;
        return 0;
      }
      local_78 = *(undefined8 *)(pData + 10);
      auVar8 = *(undefined1 (*) [16])(pData + 6);
      auVar9 = ZEXT1664(auVar8);
      if ((auVar8 & (undefined1  [16])0x1) == (undefined1  [16])0x0) {
        _DAT_1400296dc = _DAT_1400296dc + auVar8._12_4_;
        _DAT_1400296e0 = _DAT_1400296e0 + (int)local_78;
        iVar2 = DAT_1400296e4;
        iVar3 = _DAT_1400296e8;
      }
      else {
        iVar2 = GetSystemMetrics(-(uint)((auVar8 & (undefined1  [16])0x2) != (undefined1  [16])0x0)
                                 & 0x4e);
        iVar2 = (int)((float)iVar2 * ((float)auVar9._12_4_ / (65535f)));
        iVar3 = 1;
        if ((auVar8 & (undefined1  [16])0x2) != (undefined1  [16])0x0) {
          iVar3 = 0x4f;
        }
        iVar3 = GetSystemMetrics(iVar3);
        iVar3 = (int)((float)iVar3 * ((float)(int)local_78 / (65535f)));
        if (DAT_1400296e4 != -1) {
          _DAT_1400296dc = _DAT_1400296dc + (iVar2 - DAT_1400296e4);
          _DAT_1400296e0 = _DAT_1400296e0 + (iVar3 - _DAT_1400296e8);
        }
      }
      _DAT_1400296e8 = iVar3;
      DAT_1400296e4 = iVar2;
      local_98.x = 0;
      local_98.y = 0;
      GetCursorPos(&local_98);
      ScreenToClient(DAT_140029680,&local_98);
      auVar8 = auVar9._0_16_;
      if (DAT_140029810 == (code *)0x0) {
        DAT_140029828 = lVar1;
        return 0;
      }
      if ((auVar9 & (undefined1  [64])0x100000000) != (undefined1  [64])0x0) {
        DAT_140029801 = 1;
        (*DAT_140029810)(1);
      }
      if ((auVar9 & (undefined1  [64])0x200000000) != (undefined1  [64])0x0) {
        DAT_140029801 = 0;
        (*DAT_140029810)(1,0);
      }
      if ((auVar9 & (undefined1  [64])0x400000000) != (undefined1  [64])0x0) {
        DAT_140029802 = 1;
        (*DAT_140029810)(2,1);
      }
      if ((auVar9 & (undefined1  [64])0x800000000) != (undefined1  [64])0x0) {
        DAT_140029802 = 0;
        (*DAT_140029810)(2,0);
      }
      if ((auVar9 & (undefined1  [64])0x1000000000) != (undefined1  [64])0x0) {
        DAT_140029803 = 1;
        (*DAT_140029810)(3,1);
      }
      if ((auVar9 & (undefined1  [64])0x2000000000) != (undefined1  [64])0x0) {
        DAT_140029803 = 0;
        (*DAT_140029810)(3,0);
      }
      if ((auVar9 & (undefined1  [64])0x4000000000) != (undefined1  [64])0x0) {
        DAT_140029804 = 1;
        (*DAT_140029810)(4,1);
      }
      if (auVar9[4] < '\0') {
        DAT_140029804 = 0;
        (*DAT_140029810)(4,0);
      }
      if ((auVar9._4_4_ >> 8 & 1) != 0) {
        DAT_140029805 = 1;
        (*DAT_140029810)(5,1);
      }
      if ((auVar9._4_4_ >> 9 & 1) != 0) {
        DAT_140029805 = 0;
        (*DAT_140029810)(5,0);
      }
      if ((auVar9._4_2_ >> 10 & 1) == 0) {
        DAT_140029828 = lVar1;
        return 0;
      }
      uVar4 = vpextrw_avx(auVar8,3);
      local_90 = (float)(int)(short)uVar4;
      (*DAT_140029810)(0,local_90);
      DAT_140029828 = lVar1;
      return 0;
    }
    if (param_2 == 0x100) {
      if (0xfe < param_3) {
        return 0;
      }
      (&DAT_140029700)[param_3] = 1;
      if (DAT_140029808 == (code *)0x0) {
        return 0;
      }
      (*DAT_140029808)(param_3 & 0xffffffff,1);
      return 0;
    }
    if (param_2 == 0x101) {
      if (0xfe < param_3) {
        return 0;
      }
      (&DAT_140029700)[param_3] = 0;
      if (DAT_140029808 == (code *)0x0) {
        return 0;
      }
      (*DAT_140029808)(param_3 & 0xffffffff,0);
      return 0;
    }
  }
  LVar5 = DefWindowProcA(param_1,param_2,param_3,(LPARAM)param_4);
  return LVar5;
}


// ===== _guard_check_icall @ 14001fe40 size=3

void _guard_check_icall(void)

{
                    /* 0x1fe40  1  NoHotPatch */
  return;
}


// ===== FUN_14001fe50 @ 14001fe50 size=590

ulonglong FUN_14001fe50(void)

{
  uint uVar1;
  code *pcVar2;
  BOOL BVar3;
  LPVOID pvVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  LARGE_INTEGER local_b0 [21];
  
  uVar6 = 2;
  BVar3 = QueryPerformanceFrequency(local_b0);
  if (BVar3 != 0) {
    DAT_140029670 = local_b0[0];
    DAT_1400299a0 = CreateFileA("CON",0x40000000,2,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
    AddVectoredExceptionHandler(1,FUN_1400123b0);
    pvVar4 = VirtualAlloc((LPVOID)0x0,0x40020000,0x2000,4);
    DAT_140029818 = (longlong)pvVar4 + 0x1ffffU & 0xfffffffffffe0000;
    if (DAT_140029818 != 0) {
      DAT_140029820 = 0x40000000;
      DAT_140029828 = 0;
      pvVar4 = VirtualAlloc((LPVOID)0x0,0x40020000,0x2000,4);
      DAT_140029830 = (longlong)pvVar4 + 0x1ffffU & 0xfffffffffffe0000;
      if (DAT_140029830 != 0) {
        DAT_140029838 = 0x40000000;
        DAT_140029840 = 0;
        uVar5 = FUN_14000c0e0(&DAT_140029848,0x40000000);
        if ((int)uVar5 != 0) {
          uVar5 = FUN_14000c0e0(&DAT_140029860,0x40000000);
          if ((int)uVar5 != 0) {
            uVar5 = FUN_14000c0e0(&DAT_140029878,0x1000000000);
            if ((int)uVar5 != 0) {
              uVar1 = vstmxcsr_avx();
              vldmxcsr_avx(uVar1 | 0x8000);
              uVar1 = vstmxcsr_avx();
              vldmxcsr_avx(uVar1 | 0x40);
              FUN_14000ce30();
              uVar6 = FUN_14001a8f0();
              uVar6 = uVar6 & 0xffffffff;
            }
          }
        }
      }
    }
    return uVar6;
  }
  FUN_140002010("Could not get performance counter frequency");
  pcVar2 = (code *)swi(3);
  uVar6 = (*pcVar2)();
  return uVar6;
}


// ===== FUN_1400200a0 @ 1400200a0 size=35

undefined1 * FUN_1400200a0(undefined1 *param_1,undefined1 *param_2,longlong param_3)

{
  undefined1 *puVar1;
  
  puVar1 = param_1;
  for (; param_3 != 0; param_3 = param_3 + -1) {
    *puVar1 = *param_2;
    param_2 = param_2 + 1;
    puVar1 = puVar1 + 1;
  }
  return param_1;
}


// ===== FUN_1400200d0 @ 1400200d0 size=28

undefined1 * FUN_1400200d0(undefined1 *param_1,undefined1 param_2,longlong param_3)

{
  undefined1 *puVar1;
  
  puVar1 = param_1;
  for (; param_3 != 0; param_3 = param_3 + -1) {
    *puVar1 = param_2;
    puVar1 = puVar1 + 1;
  }
  return param_1;
}


// ===== FUN_1400200f0 @ 1400200f0 size=29

longlong FUN_1400200f0(char *param_1)

{
  char cVar1;
  longlong lVar2;
  
  lVar2 = 0;
  if (param_1 != (char *)0x0) {
    cVar1 = *param_1;
    while (cVar1 != '\0') {
      param_1 = param_1 + 1;
      lVar2 = lVar2 + 1;
      cVar1 = *param_1;
    }
  }
  return lVar2;
}


// ===== FUN_140020110 @ 140020110 size=182

void FUN_140020110(void)

{
  code *pcVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  undefined8 uVar5;
  undefined4 *puVar6;
  ulonglong uVar7;
  undefined7 extraout_var;
  
  _set_app_type(2);
  uVar5 = FUN_140020674();
  _set_fmode((int)uVar5);
  uVar5 = FUN_140020668();
  puVar6 = (undefined4 *)__p__commode();
  *puVar6 = (int)uVar5;
  uVar5 = __scrt_initialize_onexit_tables(1);
  if ((char)uVar5 != '\0') {
    FUN_14002092c();
    atexit(FUN_140020968);
    uVar7 = FUN_14002066c();
    iVar4 = _configure_narrow_argv(uVar7 & 0xffffffff);
    if (iVar4 == 0) {
      FUN_14002067c();
      bVar2 = FUN_1400206bc();
      if ((int)CONCAT71(extraout_var,bVar2) != 0) {
        __setusermatherr(FUN_140020668);
      }
      _guard_check_icall();
      _guard_check_icall();
      uVar5 = FUN_140020668();
      _configthreadlocale((int)uVar5);
      cVar3 = FUN_14002068c();
      if (cVar3 != '\0') {
        _initialize_narrow_environment();
      }
      FUN_140020668();
      uVar5 = thunk_FUN_140020668();
      if ((int)uVar5 == 0) {
        return;
      }
    }
  }
  FUN_1400206e0(7);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ===== FUN_1400201c8 @ 1400201c8 size=16

undefined8 FUN_1400201c8(void)

{
  FUN_1400206a0();
  return 0;
}


// ===== FUN_1400201d8 @ 1400201d8 size=25

void FUN_1400201d8(void)

{
  ulonglong uVar1;
  
  FUN_1400208c0();
  uVar1 = FUN_140020668();
  _set_new_mode(uVar1 & 0xffffffff);
  return;
}


// ===== FUN_1400201f4 @ 1400201f4 size=335

ulonglong FUN_1400201f4(void)

{
  bool bVar1;
  int iVar2;
  undefined8 uVar3;
  longlong *plVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  IMAGE_DOS_HEADER *pIVar7;
  undefined8 unaff_RBX;
  
  iVar2 = (int)unaff_RBX;
  uVar3 = FUN_1400203b8(1);
  if ((char)uVar3 == '\0') {
    FUN_1400206e0(7);
  }
  else {
    bVar1 = false;
    uVar3 = __scrt_acquire_startup_lock();
    iVar2 = (int)CONCAT71((int7)((ulonglong)unaff_RBX >> 8),(char)uVar3);
    if (DAT_1401bdb40 != 1) {
      if (DAT_1401bdb40 == 0) {
        DAT_1401bdb40 = 1;
        iVar2 = _initterm_e(&DAT_140021370,&DAT_140021388);
        if (iVar2 != 0) {
          return 0xff;
        }
        _initterm(&DAT_140021358);
        DAT_1401bdb40 = 2;
      }
      else {
        bVar1 = true;
      }
      __scrt_release_startup_lock((char)uVar3);
      plVar4 = (longlong *)FUN_1400206c8();
      if ((*plVar4 != 0) && (uVar5 = FUN_140020480((longlong)plVar4), (char)uVar5 != '\0')) {
        (*(code *)PTR__guard_dispatch_icall_140021330)(0);
      }
      plVar4 = (longlong *)FUN_1400206d0();
      if ((*plVar4 != 0) && (uVar5 = FUN_140020480((longlong)plVar4), (char)uVar5 != '\0')) {
        _register_thread_local_exe_atexit_callback(*plVar4);
      }
      __scrt_get_show_window_mode();
      _get_narrow_winmain_command_line();
      pIVar7 = &IMAGE_DOS_HEADER_140000000;
      uVar5 = FUN_14001fe50();
      iVar2 = (int)uVar5;
      uVar6 = FUN_14002086c();
      if ((char)uVar6 != '\0') {
        if (!bVar1) {
          _cexit();
        }
        __scrt_uninitialize_crt(CONCAT71((int7)((ulonglong)pIVar7 >> 8),1),'\0');
        return uVar5 & 0xffffffff;
      }
      goto LAB_140020355;
    }
  }
  FUN_1400206e0(7);
LAB_140020355:
                    /* WARNING: Subroutine does not return */
  exit(iVar2);
}


// ===== entry @ 140020368 size=18

void entry(void)

{
  __security_init_cookie();
  FUN_1400201f4();
  return;
}


// ===== __scrt_acquire_startup_lock @ 14002037c size=57

/* Library Function - Single Match
    __scrt_acquire_startup_lock
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

ulonglong __scrt_acquire_startup_lock(void)

{
  ulonglong uVar1;
  bool bVar2;
  undefined7 extraout_var;
  ulonglong uVar3;
  
  bVar2 = __scrt_is_ucrt_dll_in_use();
  uVar3 = CONCAT71(extraout_var,bVar2);
  if ((int)uVar3 == 0) {
LAB_1400203aa:
    uVar3 = uVar3 & 0xffffffffffffff00;
  }
  else {
    do {
      uVar3 = 0;
      LOCK();
      bVar2 = DAT_1401bdb48 == 0;
      uVar1 = *(ulonglong *)((longlong)Self + 8);
      if (!bVar2) {
        uVar3 = DAT_1401bdb48;
        uVar1 = DAT_1401bdb48;
      }
      DAT_1401bdb48 = uVar1;
      UNLOCK();
      if (bVar2) goto LAB_1400203aa;
    } while (*(ulonglong *)((longlong)Self + 8) != uVar3);
    uVar3 = CONCAT71((int7)(uVar3 >> 8),1);
  }
  return uVar3;
}


// ===== FUN_1400203b8 @ 1400203b8 size=58

longlong FUN_1400203b8(int param_1)

{
  char cVar1;
  uint7 extraout_var;
  uint7 uVar2;
  undefined7 extraout_var_00;
  uint7 extraout_var_01;
  
  if (param_1 == 0) {
    DAT_1401bdb50 = 1;
  }
  FUN_1400209a4();
  cVar1 = FUN_14002068c();
  uVar2 = extraout_var;
  if (cVar1 != '\0') {
    cVar1 = FUN_14002068c();
    if (cVar1 != '\0') {
      return CONCAT71(extraout_var_00,1);
    }
    FUN_14002068c();
    uVar2 = extraout_var_01;
  }
  return (ulonglong)uVar2 << 8;
}


// ===== __scrt_initialize_onexit_tables @ 1400203f4 size=139

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __scrt_initialize_onexit_tables
   
   Library: Visual Studio 2019 Release */

undefined8 __scrt_initialize_onexit_tables(uint param_1)

{
  code *pcVar1;
  bool bVar2;
  ulonglong in_RAX;
  undefined7 extraout_var;
  undefined8 uVar3;
  
  if (DAT_1401bdb51 == '\0') {
    if (1 < param_1) {
      FUN_1400206e0(5);
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
    bVar2 = __scrt_is_ucrt_dll_in_use();
    if (((int)CONCAT71(extraout_var,bVar2) == 0) || (param_1 != 0)) {
      in_RAX = 0xffffffffffffffff;
      DAT_1401bdb58 = _DAT_140025440;
      uRam00000001401bdb60 = _UNK_140025448;
      _DAT_1401bdb68 = 0xffffffffffffffff;
      _DAT_1401bdb70 = _DAT_140025440;
      uRam00000001401bdb78 = _UNK_140025448;
      _DAT_1401bdb80 = 0xffffffffffffffff;
    }
    else {
      in_RAX = _initialize_onexit_table(&DAT_1401bdb58);
      if (((int)in_RAX != 0) ||
         (in_RAX = _initialize_onexit_table(&DAT_1401bdb70), (int)in_RAX != 0)) {
        return in_RAX & 0xffffffffffffff00;
      }
    }
    DAT_1401bdb51 = '\x01';
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}


// ===== FUN_140020480 @ 140020480 size=150

ulonglong FUN_140020480(longlong param_1)

{
  word *pwVar1;
  ulonglong uVar2;
  uint7 uVar3;
  longlong lVar4;
  word *pwVar5;
  
  uVar2 = 0x5a4d;
  if (IMAGE_DOS_HEADER_140000000.e_magic == (char  [2])0x5a4d) {
    lVar4 = (longlong)(int)IMAGE_DOS_HEADER_140000000.e_lfanew;
    if ((*(int *)(IMAGE_DOS_HEADER_140000000.e_magic + lVar4) == 0x4550) &&
       (uVar2 = 0x20b,
       *(short *)((longlong)IMAGE_DOS_HEADER_140000000.e_res_4_ + lVar4 + -4) == 0x20b)) {
      pwVar5 = (word *)(IMAGE_DOS_HEADER_140000000.e_magic + lVar4 +
                       (ulonglong)
                       *(ushort *)((longlong)IMAGE_DOS_HEADER_140000000.e_res_4_ + lVar4 + -8) +
                       0x18);
      uVar2 = (ulonglong)*(ushort *)(IMAGE_DOS_HEADER_140000000.e_magic + lVar4 + 6);
      pwVar1 = pwVar5 + uVar2 * 0x14;
      for (; pwVar5 != pwVar1; pwVar5 = pwVar5 + 0x14) {
        if (((ulonglong)*(uint *)(pwVar5 + 6) <= param_1 - 0x140000000U) &&
           (uVar2 = (ulonglong)(*(int *)(pwVar5 + 4) + *(uint *)(pwVar5 + 6)),
           param_1 - 0x140000000U < uVar2)) goto LAB_1400204f6;
      }
      pwVar5 = (word *)0x0;
LAB_1400204f6:
      if (pwVar5 == (word *)0x0) {
        return uVar2 & 0xffffffffffffff00;
      }
      uVar3 = (uint7)(uVar2 >> 8);
      if (*(int *)(pwVar5 + 0x12) < 0) {
        return (ulonglong)uVar3 << 8;
      }
      return CONCAT71(uVar3,1);
    }
  }
  return uVar2 & 0xffffffffffffff00;
}


// ===== __scrt_release_startup_lock @ 140020518 size=36

/* Library Function - Single Match
    __scrt_release_startup_lock
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void __scrt_release_startup_lock(char param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  
  bVar1 = __scrt_is_ucrt_dll_in_use();
  if ((CONCAT31(extraout_var,bVar1) != 0) && (param_1 == '\0')) {
    LOCK();
    DAT_1401bdb48 = 0;
    UNLOCK();
  }
  return;
}


// ===== __scrt_uninitialize_crt @ 14002053c size=41

/* Library Function - Single Match
    __scrt_uninitialize_crt
   
   Library: Visual Studio 2019 Release */

undefined1 __scrt_uninitialize_crt(undefined8 param_1,char param_2)

{
  if ((DAT_1401bdb50 == '\0') || (param_2 == '\0')) {
    FUN_14002068c();
    FUN_14002068c();
  }
  return 1;
}


// ===== _onexit @ 140020568 size=58

/* Library Function - Single Match
    _onexit
   
   Library: Visual Studio 2019 Release */

_onexit_t __cdecl _onexit(_onexit_t _Func)

{
  int iVar1;
  _onexit_t p_Var2;
  
  if (DAT_1401bdb58 == -1) {
    iVar1 = _crt_atexit();
  }
  else {
    iVar1 = _register_onexit_function(&DAT_1401bdb58);
  }
  p_Var2 = (_onexit_t)0x0;
  if (iVar1 == 0) {
    p_Var2 = _Func;
  }
  return p_Var2;
}


// ===== atexit @ 1400205a4 size=23

/* Library Function - Single Match
    atexit
   
   Library: Visual Studio 2019 Release */

int __cdecl atexit(_func_5014 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = _onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}


// ===== __security_init_cookie @ 1400205bc size=172

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __security_init_cookie
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl __security_init_cookie(void)

{
  DWORD DVar1;
  _FILETIME local_res8;
  LARGE_INTEGER local_res10;
  _FILETIME local_18 [2];
  
  if (DAT_1400295c0 == 0x2b992ddfa232) {
    local_res8.dwLowDateTime = 0;
    local_res8.dwHighDateTime = 0;
    GetSystemTimeAsFileTime(&local_res8);
    local_18[0] = local_res8;
    DVar1 = GetCurrentThreadId();
    local_18[0] = (_FILETIME)((ulonglong)local_18[0] ^ (ulonglong)DVar1);
    DVar1 = GetCurrentProcessId();
    local_18[0] = (_FILETIME)((ulonglong)local_18[0] ^ (ulonglong)DVar1);
    QueryPerformanceCounter(&local_res10);
    DAT_1400295c0 =
         ((ulonglong)local_res10.s.LowPart << 0x20 ^
          CONCAT44(local_res10.s.HighPart,local_res10.s.LowPart) ^ (ulonglong)local_18[0] ^
         (ulonglong)local_18) & 0xffffffffffff;
    if (DAT_1400295c0 == 0x2b992ddfa232) {
      DAT_1400295c0 = 0x2b992ddfa233;
    }
  }
  _DAT_140029600 = ~DAT_1400295c0;
  return;
}


// ===== FUN_140020668 @ 140020668 size=3

undefined8 FUN_140020668(void)

{
  return 0;
}


// ===== FUN_14002066c @ 14002066c size=6

undefined8 FUN_14002066c(void)

{
  return 1;
}


// ===== FUN_140020674 @ 140020674 size=6

undefined8 FUN_140020674(void)

{
  return 0x4000;
}


// ===== FUN_14002067c @ 14002067c size=14

void FUN_14002067c(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140020683. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  InitializeSListHead(&DAT_1401bdb90);
  return;
}


// ===== FUN_14002068c @ 14002068c size=3

undefined1 FUN_14002068c(void)

{
  return 1;
}


// ===== FUN_140020690 @ 140020690 size=8

undefined * FUN_140020690(void)

{
  return &DAT_1401bdba0;
}


// ===== FUN_140020698 @ 140020698 size=8

undefined * FUN_140020698(void)

{
  return &DAT_1401bdba8;
}


// ===== FUN_1400206a0 @ 1400206a0 size=27

void FUN_1400206a0(void)

{
  ulonglong *puVar1;
  
  puVar1 = (ulonglong *)FUN_140020690();
  *puVar1 = *puVar1 | 0x24;
  puVar1 = (ulonglong *)FUN_140020698();
  *puVar1 = *puVar1 | 2;
  return;
}


// ===== FUN_1400206bc @ 1400206bc size=12

bool FUN_1400206bc(void)

{
  return DAT_140029588 == 0;
}


// ===== FUN_1400206c8 @ 1400206c8 size=8

undefined * FUN_1400206c8(void)

{
  return &DAT_1401bdbc8;
}


// ===== FUN_1400206d0 @ 1400206d0 size=8

undefined * FUN_1400206d0(void)

{
  return &DAT_1401bdbc0;
}


// ===== FUN_1400206d8 @ 1400206d8 size=8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400206d8(void)

{
  _DAT_1401bdbb0 = 0;
  return;
}


// ===== FUN_1400206e0 @ 1400206e0 size=328

void FUN_1400206e0(undefined4 param_1)

{
  code *pcVar1;
  BOOL BVar2;
  LONG LVar3;
  PRUNTIME_FUNCTION FunctionEntry;
  undefined1 *puVar4;
  undefined8 unaff_retaddr;
  DWORD64 local_res10;
  undefined1 local_res18 [8];
  undefined1 local_res20 [8];
  undefined1 auStack_5c8 [8];
  undefined1 auStack_5c0 [232];
  undefined1 local_4d8 [152];
  undefined1 *local_440;
  DWORD64 local_3e0;
  
  puVar4 = auStack_5c8;
  BVar2 = IsProcessorFeaturePresent(0x17);
  if (BVar2 != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(param_1);
    puVar4 = auStack_5c0;
  }
  *(undefined8 *)(puVar4 + -8) = 0x140020714;
  FUN_1400206d8();
  *(undefined8 *)(puVar4 + -8) = 0x140020725;
  FUN_1400200d0(local_4d8,0,0x4d0);
  *(undefined8 *)(puVar4 + -8) = 0x14002072f;
  RtlCaptureContext(local_4d8);
  *(undefined8 *)(puVar4 + -8) = 0x140020749;
  FunctionEntry = RtlLookupFunctionEntry(local_3e0,&local_res10,(PUNWIND_HISTORY_TABLE)0x0);
  if (FunctionEntry != (PRUNTIME_FUNCTION)0x0) {
    *(undefined8 *)(puVar4 + 0x38) = 0;
    *(undefined1 **)(puVar4 + 0x30) = local_res18;
    *(undefined1 **)(puVar4 + 0x28) = local_res20;
    *(undefined1 **)(puVar4 + 0x20) = local_4d8;
    *(undefined8 *)(puVar4 + -8) = 0x14002078a;
    RtlVirtualUnwind(0,local_res10,local_3e0,FunctionEntry,*(PCONTEXT *)(puVar4 + 0x20),
                     *(PVOID **)(puVar4 + 0x28),*(PDWORD64 *)(puVar4 + 0x30),
                     *(PKNONVOLATILE_CONTEXT_POINTERS *)(puVar4 + 0x38));
  }
  local_440 = &stack0x00000008;
  *(undefined8 *)(puVar4 + -8) = 0x1400207bc;
  FUN_1400200d0(puVar4 + 0x50,0,0x98);
  *(undefined8 *)(puVar4 + 0x60) = unaff_retaddr;
  *(undefined4 *)(puVar4 + 0x50) = 0x40000015;
  *(undefined4 *)(puVar4 + 0x54) = 1;
  *(undefined8 *)(puVar4 + -8) = 0x1400207de;
  BVar2 = IsDebuggerPresent();
  *(undefined1 **)(puVar4 + 0x40) = puVar4 + 0x50;
  *(undefined1 **)(puVar4 + 0x48) = local_4d8;
  *(undefined8 *)(puVar4 + -8) = 0x1400207fb;
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  *(undefined8 *)(puVar4 + -8) = 0x140020806;
  LVar3 = UnhandledExceptionFilter((_EXCEPTION_POINTERS *)(puVar4 + 0x40));
  if ((LVar3 == 0) && (BVar2 != 1)) {
    *(undefined8 *)(puVar4 + -8) = 0x140020817;
    FUN_1400206d8();
  }
  return;
}


// ===== __scrt_get_show_window_mode @ 140020828 size=58

/* Library Function - Single Match
    __scrt_get_show_window_mode
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

WORD __scrt_get_show_window_mode(void)

{
  WORD WVar1;
  _STARTUPINFOW local_78;
  
  FUN_1400200d0((undefined1 *)&local_78,0,0x68);
  GetStartupInfoW(&local_78);
  WVar1 = 10;
  if (((byte)local_78.dwFlags & 1) != 0) {
    WVar1 = local_78.wShowWindow;
  }
  return WVar1;
}


// ===== FUN_14002086c @ 14002086c size=81

ulonglong FUN_14002086c(void)

{
  HMODULE pHVar1;
  ulonglong uVar2;
  int *piVar3;
  
  pHVar1 = GetModuleHandleW((LPCWSTR)0x0);
  if ((((pHVar1 == (HMODULE)0x0) || ((short)pHVar1->unused != 0x5a4d)) ||
      (piVar3 = (int *)((longlong)&pHVar1->unused + (longlong)pHVar1[0xf].unused), *piVar3 != 0x4550
      )) || ((pHVar1 = (HMODULE)0x20b, (short)piVar3[6] != 0x20b || ((uint)piVar3[0x21] < 0xf)))) {
    uVar2 = (ulonglong)pHVar1 & 0xffffffffffffff00;
  }
  else {
    uVar2 = CONCAT71(2,piVar3[0x3e] != 0);
  }
  return uVar2;
}


// ===== FUN_1400208c0 @ 1400208c0 size=14

void FUN_1400208c0(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001400208c7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetUnhandledExceptionFilter(FUN_1400208d0);
  return;
}


// ===== FUN_1400208d0 @ 1400208d0 size=90

undefined8 FUN_1400208d0(undefined8 *param_1)

{
  int *piVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  
  piVar1 = (int *)*param_1;
  if ((*piVar1 == -0x1f928c9d) && (piVar1[6] == 4)) {
    if ((piVar1[8] + 0xe66cfae0U < 3) || (piVar1[8] == 0x1994000)) {
      puVar3 = (undefined8 *)__current_exception();
      *puVar3 = piVar1;
      uVar2 = param_1[1];
      puVar3 = (undefined8 *)__current_exception_context();
      *puVar3 = uVar2;
                    /* WARNING: Subroutine does not return */
      terminate();
    }
  }
  return 0;
}


// ===== FUN_14002092c @ 14002092c size=60

void FUN_14002092c(void)

{
  longlong *plVar1;
  
  for (plVar1 = &DAT_140025988; plVar1 < &DAT_140025988; plVar1 = plVar1 + 1) {
    if (*plVar1 != 0) {
      (*(code *)PTR__guard_dispatch_icall_140021330)();
    }
  }
  return;
}


// ===== FUN_140020968 @ 140020968 size=60

void FUN_140020968(void)

{
  longlong *plVar1;
  
  for (plVar1 = &DAT_140025998; plVar1 < &DAT_140025998; plVar1 = plVar1 + 1) {
    if (*plVar1 != 0) {
      (*(code *)PTR__guard_dispatch_icall_140021330)();
    }
  }
  return;
}


// ===== FUN_1400209a4 @ 1400209a4 size=714

/* WARNING: Removing unreachable block (ram,0x000140020ac7) */
/* WARNING: Removing unreachable block (ram,0x000140020aaa) */
/* WARNING: Removing unreachable block (ram,0x000140020a79) */
/* WARNING: Removing unreachable block (ram,0x0001400209e0) */
/* WARNING: Removing unreachable block (ram,0x0001400209bd) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_1400209a4(void)

{
  int *piVar1;
  uint *puVar2;
  int *piVar3;
  longlong lVar4;
  uint uVar5;
  ulonglong uVar6;
  byte bVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint in_XCR0;
  
  piVar1 = (int *)cpuid_basic_info(0);
  puVar2 = (uint *)cpuid_Version_info(1);
  uVar5 = puVar2[3];
  if ((piVar1[2] == 0x49656e69 && piVar1[3] == 0x6c65746e) && piVar1[1] == 0x756e6547) {
    _DAT_1400295a8 = 0xffffffffffffffff;
    uVar8 = *puVar2 & 0xfff3ff0;
    _DAT_1400295a0 = 0x8000;
    if ((((uVar8 == 0x106c0) || (uVar8 == 0x20660)) || (uVar8 == 0x20670)) ||
       ((uVar8 - 0x30650 < 0x21 &&
        ((0x100010001U >> ((ulonglong)(uVar8 - 0x30650) & 0x3f) & 1) != 0)))) {
      DAT_1401bdbb8 = DAT_1401bdbb8 | 1;
    }
  }
  uVar10 = 0;
  uVar8 = uVar10;
  uVar9 = uVar10;
  uVar11 = uVar10;
  if (6 < *piVar1) {
    piVar3 = (int *)cpuid_Extended_Feature_Enumeration_info(7);
    uVar8 = piVar3[1];
    uVar9 = piVar3[2];
    if ((uVar8 >> 9 & 1) != 0) {
      DAT_1401bdbb8 = DAT_1401bdbb8 | 2;
    }
    if (0 < *piVar3) {
      lVar4 = cpuid_Extended_Feature_Enumeration_info(7);
      uVar11 = *(uint *)(lVar4 + 8);
    }
    if (0x23 < *piVar1) {
      lVar4 = cpuid(0x24);
      uVar10 = *(uint *)(lVar4 + 4);
    }
  }
  _DAT_140029598 = 1;
  DAT_14002959c = 2;
  uVar6 = DAT_140029590 & 0xfffffffffffffffe;
  if ((uVar5 >> 0x14 & 1) != 0) {
    _DAT_140029598 = 2;
    DAT_14002959c = 6;
    uVar6 = DAT_140029590 & 0xffffffffffffffee;
  }
  DAT_140029590 = uVar6;
  if ((uVar5 >> 0x1b & 1) != 0) {
    if (((uVar5 >> 0x1c & 1) != 0) && (bVar7 = (byte)in_XCR0, (bVar7 & 6) == 6)) {
      _DAT_140029598 = 3;
      uVar6 = DAT_140029590;
      uVar5 = DAT_14002959c | 8;
      if ((uVar8 & 0x20) != 0) {
        _DAT_140029598 = 5;
        uVar6 = DAT_140029590 & 0xfffffffffffffffd;
        uVar5 = DAT_14002959c | 0x28;
        if (((uVar8 & 0xd0030000) == 0xd0030000) && ((bVar7 & 0xe0) == 0xe0)) {
          DAT_14002959c = DAT_14002959c | 0x68;
          _DAT_140029598 = 6;
          uVar6 = DAT_140029590 & 0xffffffffffffffd9;
          uVar5 = DAT_14002959c;
        }
      }
      DAT_14002959c = uVar5;
      DAT_140029590 = uVar6;
      if ((uVar9 >> 0x17 & 1) != 0) {
        DAT_140029590 = DAT_140029590 & 0xfffffffffeffffff;
      }
      if (((uVar11 >> 0x13 & 1) != 0) && ((bVar7 & 0xe0) == 0xe0)) {
        _DAT_1401bdbb4 = uVar10 & 0x400ff;
        DAT_140029590 = ~((ulonglong)(uVar10 >> 0x10 & 7) | 0x1000028) & DAT_140029590;
        if (1 < _DAT_1401bdbb4) {
          DAT_140029590 = DAT_140029590 & 0xffffffffffffffbf;
        }
      }
    }
    if (((uVar11 >> 0x15 & 1) != 0) && ((in_XCR0 >> 0x13 & 1) != 0)) {
      DAT_140029590 = DAT_140029590 & 0xffffffffffffff7f;
    }
  }
  return 0;
}


// ===== __scrt_is_ucrt_dll_in_use @ 140020c70 size=12

/* Library Function - Single Match
    __scrt_is_ucrt_dll_in_use
   
   Library: Visual Studio 2019 Release */

bool __scrt_is_ucrt_dll_in_use(void)

{
  return DAT_140029610 != 0;
}


// ===== _guard_dispatch_icall @ 140020d20 size=2

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140020d20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// ===== FUN_140020d46 @ 140020d46 size=29

void FUN_140020d46(undefined8 *param_1)

{
  _seh_filter_exe(*(undefined4 *)*param_1,param_1);
  return;
}


// ===== FUN_140020d64 @ 140020d64 size=23

bool FUN_140020d64(undefined8 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}


