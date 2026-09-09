# Zygisk-Il2CppDumper
Zygisk版Il2CppDumper，在游戏运行时dump il2cpp数据，可以绕过保护，加密以及混淆。

## 如何食用
1. 安装[Magisk](https://github.com/topjohnwu/Magisk) v24以上版本并开启Zygisk
2. 生成模块
   - GitHub Actions
      1. Fork这个项目
      2. 在你fork的项目中选择**Actions**选项卡
      3. 在左边的侧边栏中，单击**Build**
      4. 选择**Run workflow**
      5. 输入游戏包名和目标库/模块文件名（默认为 `libil2cpp.so`），然后点击**Run workflow**。请输入不含路径的 `.so` 文件名；目标库必须提供 IL2CPP API。
      6. 等待操作完成并下载
   - Android Studio
      1. 下载源码
      2. 编辑`game.h`, 修改`GamePackageName`为游戏包名，修改`GameLibraryName`为目标库文件名（默认为 `libil2cpp.so`）
      3. 使用Android Studio运行gradle任务`:module:assembleRelease`编译，zip包会生成在`out`文件夹下
3. 在Magisk里安装模块
4. 启动游戏，会在`/data/data/GamePackageName/files/`目录下生成`dump.cs`
