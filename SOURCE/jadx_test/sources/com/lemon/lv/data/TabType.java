package com.lemon.lv.data;

import X.C06W;

/* JADX WARN: Enum visitor error
jadx.core.utils.exceptions.JadxRuntimeException: Can't remove SSA var: r0v3 com.lemon.lv.data.TabType[], still in use, count: 1, list:
  (r0v3 com.lemon.lv.data.TabType[]) from 0x001d: INVOKE (r0v3 com.lemon.lv.data.TabType[]) STATIC call: X.06W.a(java.lang.Enum[]):X.0Sr A[MD:(java.lang.Enum[]):X.0Sr (m)] (LINE:262173)
	at jadx.core.utils.InsnRemover.removeSsaVar(InsnRemover.java:164)
	at jadx.core.utils.InsnRemover.unbindResult(InsnRemover.java:129)
	at jadx.core.utils.InsnRemover.lambda$unbindInsns$1(InsnRemover.java:101)
	at java.base/java.util.ArrayList.forEach(ArrayList.java:1596)
	at jadx.core.utils.InsnRemover.unbindInsns(InsnRemover.java:100)
	at jadx.core.utils.InsnRemover.removeAllAndUnbind(InsnRemover.java:257)
	at jadx.core.dex.visitors.EnumVisitor.convertToEnum(EnumVisitor.java:187)
	at jadx.core.dex.visitors.EnumVisitor.visit(EnumVisitor.java:102)
 */
/* JADX WARN: Failed to restore enum class, 'enum' modifier and super class removed */
/* JADX INFO: loaded from: D:\Decompiler\App\Video\Capcut\extracted\classes2.dex */
public final class TabType {
    Album,
    TextAudio;

    public static TabType valueOf(String str) {
        return (TabType) Enum.valueOf(TabType.class, str);
    }

    public static TabType[] values() {
        return (TabType[]) c.clone();
    }

    static {
        C06W.a(tabTypeArr);
    }

    public TabType() {
        super(str, i);
    }
}
