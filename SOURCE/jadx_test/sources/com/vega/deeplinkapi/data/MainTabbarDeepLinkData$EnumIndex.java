package com.vega.deeplinkapi.data;

import X.06W;

/* JADX WARN: Enum visitor error
jadx.core.utils.exceptions.JadxRuntimeException: Can't remove SSA var: r1v9 com.vega.deeplinkapi.data.MainTabbarDeepLinkData$EnumIndex[], still in use, count: 1, list:
  (r1v9 com.vega.deeplinkapi.data.MainTabbarDeepLinkData$EnumIndex[]) from 0x0079: INVOKE (r1v9 com.vega.deeplinkapi.data.MainTabbarDeepLinkData$EnumIndex[]) STATIC call: X.06W.a(java.lang.Enum[]):X.0Sr (LINE:393337)
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
/* JADX INFO: loaded from: D:\Decompiler\App\Video\Capcut\extracted\classes15.dex */
public final class MainTabbarDeepLinkData$EnumIndex {
    TAB_EDIT("0"),
    /* JADX INFO: Fake field, exist only in values array */
    TAB_TEMPLATE("1"),
    /* JADX INFO: Fake field, exist only in values array */
    TAB_MSG("2"),
    /* JADX INFO: Fake field, exist only in values array */
    TAB_HOME_PAGE("3"),
    /* JADX INFO: Fake field, exist only in values array */
    TAB_TUTORIAL("4"),
    /* JADX INFO: Fake field, exist only in values array */
    TAB_FORMULA("5"),
    /* JADX INFO: Fake field, exist only in values array */
    TAB_ENTERPRISE_TEMPLATE("6"),
    /* JADX INFO: Fake field, exist only in values array */
    TAB_ENTERPRISE_CLOUD("7"),
    /* JADX INFO: Fake field, exist only in values array */
    PROPERTY("8");

    public static final Companion b;
    public final String a;

    public static MainTabbarDeepLinkData$EnumIndex valueOf(String str) {
        return (MainTabbarDeepLinkData$EnumIndex) Enum.valueOf(MainTabbarDeepLinkData$EnumIndex.class, str);
    }

    public static MainTabbarDeepLinkData$EnumIndex[] values() {
        return (MainTabbarDeepLinkData$EnumIndex[]) d.clone();
    }

    /* JADX WARN: Type inference failed for: r0v14, types: [com.vega.deeplinkapi.data.MainTabbarDeepLinkData$EnumIndex$Companion] */
    static {
        06W.a(mainTabbarDeepLinkData$EnumIndexArr);
        b = new Object() { // from class: com.vega.deeplinkapi.data.MainTabbarDeepLinkData$EnumIndex.Companion
        };
    }

    public MainTabbarDeepLinkData$EnumIndex(String str) {
        super(str, i);
        this.a = str;
    }
}
