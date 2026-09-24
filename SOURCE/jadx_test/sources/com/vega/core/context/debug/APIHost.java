package com.vega.core.context.debug;

import kotlin.jvm.internal.Intrinsics;

/* JADX INFO: loaded from: D:\Decompiler\App\Video\Capcut\extracted\classes20.dex */
public final class APIHost {
    public final String a;
    public final String b;
    public final String c;
    public final String d;
    public final String e;
    public final String f;
    public final String g;
    public final String h;
    public final String i;
    public final String j;
    public final String k;

    public final boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (!(obj instanceof APIHost)) {
            return false;
        }
        APIHost aPIHost = (APIHost) obj;
        return Intrinsics.areEqual(this.a, aPIHost.a) && Intrinsics.areEqual(this.b, aPIHost.b) && Intrinsics.areEqual(this.c, aPIHost.c) && Intrinsics.areEqual(this.d, aPIHost.d) && Intrinsics.areEqual(this.e, aPIHost.e) && Intrinsics.areEqual(this.f, aPIHost.f) && Intrinsics.areEqual(this.g, aPIHost.g) && Intrinsics.areEqual(this.h, aPIHost.h) && Intrinsics.areEqual(this.i, aPIHost.i) && Intrinsics.areEqual(this.j, aPIHost.j) && Intrinsics.areEqual(this.k, aPIHost.k);
    }

    public final int hashCode() {
        return (((((((((((((((((((this.a.hashCode() * 31) + this.b.hashCode()) * 31) + this.c.hashCode()) * 31) + this.d.hashCode()) * 31) + this.e.hashCode()) * 31) + this.f.hashCode()) * 31) + this.g.hashCode()) * 31) + this.h.hashCode()) * 31) + this.i.hashCode()) * 31) + this.j.hashCode()) * 31) + this.k.hashCode();
    }

    public final String toString() {
        return "APIHost(api=" + this.a + ", et=" + this.b + ", boe=" + this.c + ", community=" + this.d + ", upload=" + this.e + ", pay=" + this.f + ", login=" + this.g + ", settings=" + this.h + ", vod=" + this.i + ", vodBOE=" + this.j + ", ug=" + this.k + ')';
    }

    public final String a() {
        return this.a;
    }

    public APIHost(String str, String str2, String str3) {
        Intrinsics.checkNotNullParameter(str, "");
        Intrinsics.checkNotNullParameter(str2, "");
        Intrinsics.checkNotNullParameter(str3, "");
        this.a = str;
        this.b = str2;
        this.c = str3;
        this.d = "feed-api.capcutapi.com";
        this.e = "";
        this.f = "commerce-api.capcutapi.com";
        this.g = "passport-api.capcutapi.com";
        this.h = "editor-api.capcutapi.com";
        this.i = "";
        this.j = "";
        this.k = "";
    }
}
