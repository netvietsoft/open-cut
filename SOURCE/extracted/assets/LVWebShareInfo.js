function lv_getMetaContent(metaName) {
    var metaSel = "meta[name='" + metaName + "']";
    if (document.querySelector(metaSel) != null) {
        return document.querySelector(metaSel).getAttribute("content");
    }
    return null;
}

function lv_getLinkHref(relName) {
    var linkSel = "link[rel='" + relName + "']";
    if (document.querySelector(linkSel) != null) {
        return document.querySelector(linkSel).href;
    }
    return null;
}

function lv_getShareTitle() {
    var shareTitle = lv_getMetaContent("aweme:title");
    if (shareTitle != null && shareTitle.length > 0) {
        return shareTitle;
    }
    return document.title;
}

function lv_getShareURL() {
    var shareURL = lv_getMetaContent("aweme:url");
    if (shareURL != null && shareURL.length > 0) {
        return shareURL;
    }
    return location.href;
}

function lv_getShareDesc() {
    var shareDesc = lv_getMetaContent("aweme:description");
    if (shareDesc != null) {
        return shareDesc;
    }
    shareDesc = lv_getMetaContent("description");
    if (shareDesc != null && shareDesc.length > 0) {
        return shareDesc;
    }
    return "";
}

function lv_getShareImage() {
    var shareImage = lv_getMetaContent("aweme:image");
    if (shareImage != null && shareImage.length > 0) {
        return shareImage;
    }
    shareImage = lv_getLinkHref("shortcut icon");
    if (shareImage != null && shareImage.length > 0) {
        return shareImage;
    }
    shareImage = lv_getLinkHref("icon");
    if (shareImage != null && shareImage.length > 0) {
        return shareImage;
    }
    return "";
}

function lv_share() {
        return {"title": lv_getShareTitle(), "desc": lv_getShareDesc(), "url": lv_getShareURL(), "image": lv_getShareImage()};
}

lv_share()