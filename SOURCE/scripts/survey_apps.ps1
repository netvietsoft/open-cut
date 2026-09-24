$apps = @(
    @{ Name = "YouCut (com.camerasideas.trimmer)"; Path = "D:\Decompiler\App\Video\com.camerasideas.trimmer\Report\06_REUSABLE_RESOURCES_AND_ASSETS.md"; Hierarchy = "D:\Decompiler\App\Video\com.camerasideas.trimmer\Report\14_MENU_AND_TAB_HIERARCHY.md" },
    @{ Name = "VlogU (com.frontrow.vlog)"; Path = "D:\Decompiler\App\Video\com.frontrow.vlog\Report\06_REUSABLE_RESOURCES_AND_ASSETS.md"; Hierarchy = "D:\Decompiler\App\Video\com.frontrow.vlog\Report\14_MENU_AND_TAB_HIERARCHY.md" },
    @{ Name = "Kwai Editor (com.kwai.editor)"; Path = "D:\Decompiler\App\Video\com.kwai.editor\Report\14_TAI_NGUYEN_CO_THE_SU_DUNG.md"; Hierarchy = "D:\Decompiler\App\Video\com.kwai.editor\Report\10_CAU_TRUC_MENU_TAB_HIERARCHY.md" },
    @{ Name = "GlitchCam FX (video.editor.videomaker.effects.fx)"; Path = "D:\Decompiler\App\Video\video.editor.videomaker.effects.fx\Report\06_REUSABLE_RESOURCES_AND_ASSETS.md"; Hierarchy = "D:\Decompiler\App\Video\video.editor.videomaker.effects.fx\Report\14_MENU_AND_TAB_HIERARCHY.md" },
    @{ Name = "Lightroom Mobile (com.adobe.lrmobile)"; Path = "D:\Decompiler\App\Image\com.adobe.lrmobile\Report\04_RESOURCES_AND_ASSETS.md"; Hierarchy = "D:\Decompiler\App\Image\com.adobe.lrmobile\Report\11_UI_UX_FLOW_AND_NAVIGATION.md" },
    @{ Name = "Facetune (com.lightricks.facetune.free)"; Path = "D:\Decompiler\App\Image\com.lightricks.facetune.free\Report\03_SDK_THU_VIEN_VA_TAI_NGUYEN_KHO_ASSETS.md"; Hierarchy = "D:\Decompiler\App\Image\com.lightricks.facetune.free\Report\06_UI_UX_FLOW_MENU_VA_REDESIGN.md" },
    @{ Name = "Meitu (com.mt.mtxx.mtxx)"; Path = "D:\Decompiler\App\Image\com.mt.mtxx.mtxx\Report\03_SDK_Library_Va_Tai_Nguyen.md"; Hierarchy = "D:\Decompiler\App\Image\com.mt.mtxx.mtxx\Report\09_UI_UX_Screen_Flow_Menu_Va_Redesign.md" },
    @{ Name = "FaceApp (io.faceapp)"; Path = "D:\Decompiler\App\Image\io.faceapp\Report\08-TaiNguyen-SuDung.md"; Hierarchy = "D:\Decompiler\App\Image\io.faceapp\Report\16-Menu-Tab-Hierarchy.md" },
    @{ Name = "SnapEdit (snapedit.app.remove)"; Path = "D:\Decompiler\App\Image\snapedit.app.remove\Report\01_Tong_Quan_Kien_Truc_Va_Nen_Tang.md"; Hierarchy = "D:\Decompiler\App\Image\snapedit.app.remove\Report\06_UI_UX_Screen_Flow_Va_Redesign.md" }
)

foreach ($a in $apps) {
    Write-Host "=========================================="
    Write-Host $a.Name
    if (Test-Path $a.Path) {
        Write-Host "--- Resource Preview ---"
        Get-Content $a.Path | Select-Object -First 30
    }
    if (Test-Path $a.Hierarchy) {
        Write-Host "--- Hierarchy Preview ---"
        Get-Content $a.Hierarchy | Select-Object -First 30
    }
}
