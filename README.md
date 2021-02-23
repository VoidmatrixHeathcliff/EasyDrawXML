# EasyDrawXML

## 1. 关于 EasyDrawXML 

> ~~原想起名为 EasyDraw ，但是无奈之前有一个已经进垃圾场的项目名字叫EasyGame，其下有一个模块便是EasyDraw，于是只好更名为 EasyDrawXML~~

### 1.1 EasyDraw 能干什么？

EasyDrawXML可以用于快速搭建窗口内场景，所以可以用于 UI 或游戏画面设计，或者仅用于 XML 绘图的学习

### 1.2 EasyDraw 优势何在？

比起语法和特性复杂的 HTML 和依赖庞大的 XAML ，使用底层图形接口直接封装的 EasyDrawXML 引擎语法更简单，体积更小，绘图效率更高

### 1.3 其他可能合理的存在意义……

+ EasyDrawXML 是本人在学习尝试使用 C++ 解析 XML（尤其是使用pugixml库）时的副产物
+ 虽然 EasyDrawXML 目前阶段并不支持动态效果，以及类似前端中使用的 JavaScript 脚本控制，但是后续会考虑和 [EtherEngine](https://github.com/VoidmatrixHeathcliff/EtherEngine) 游戏引擎结合，在帮助 [EtherEngine](https://github.com/VoidmatrixHeathcliff/EtherEngine) 更快进行场景布局的同时，引入 Lua 脚本支持，从而达到类似浏览器的 MVC 模式

## 2. 如何使用 EasyDrawXML

编译源码或直接下载[最新的Release版本](https://github.com/VoidmatrixHeathcliff/EasyDrawXML/releases)，在程序根目录下新建 `index.xml` 文件，程序会自动将其内容加载并渲染在窗口上

**注意：程序所使用的第三方库默认使用动态链接库编译，在本地编译源码运行时注意将动态链接库文件复制到合适的位置再进行开发和调试**

### 2.1 属性？标签？内容？

EasyDrawXML 充分借鉴了 XAML 的灵活性，支持将对象标签的属性放置在 **标签行内属性中** 、**对应属性名称的子标签的行内Value属性中** 、**对应属性名称的子标签内** 或 **对应属性名称的子标签的 Value 子标签内**

如下所示的几种类型的 XML 代码，在 EasyDrawXML 看来是等同的：

```xml
<!-- 在标签行内属性中设置对象标签属性 -->
<Rectangle Width="200" />
```

```xml
<!-- 在对应属性名称的子标签的行内Value属性中设置对象标签属性 -->
<Rectangle>
    <Width Value="200" />
</Rectangle>

```

```xml
<!-- 在对应属性名称的子标签内设置对象标签属性 -->
<Rectangle>
    <Width>
        200
    </Width>
</Rectangle>
```

```xml
<!-- 对应属性名称的子标签的 Value 子标签内 -->
<Rectangle>
    <Width>
        <Value>
            200
        </Value>
    </Width>
</Rectangle>
```

不过需要注意的是，当同一属性在以上几种位置同时出现时，EasyDrawXML 将依照以上示例从上至下的顺序优先读取，即：**标签行内属性中** > **对应属性名称的子标签的行内Value属性中** > **对应属性名称的子标签内** > **对应属性名称的子标签的 Value 子标签内**

### 2.2 EasyDrawXML 所支持的标签及属性

**注意：类似HTML将 \<html>\</html> 作为文档的根标签，EasyDrawXML 将 \<EDX>\</EDX> 作为引擎解析的内容根标签，丢失根标签引擎将终止程序并发出警告；同时，可渲染内容需要被 \<Body>\</Body> 标签包裹，丢失此标签引擎不会报错，但是无法渲染任何内容**

+ `Config` 标签：
    
    对窗口大小颜色等样式以及字体图标资源的设置标签 

    其子标签可以为如下内容：

    - `Window` 标签：

        用以配置窗口样式，支持的属性如下：

        * `Title`：窗口标题，默认为 Window
        * `Width`：窗口宽度，默认为 1280
        * `Height`：窗口高度，默认为 720
        * `Color`：窗口背景颜色，默认为 黑色

    - `Resource` 标签：

        用以配置所使用的资源，支持的属性如下：

        * `Type`：资源类型，可以为以下值：

            + `Font`：字体文件
            + `Icon`：图标文件

        * `Path`：资源文件路径

+ `Text` 标签：

    文本，支持的属性有：

    - X：文本左上角顶点坐标 X 分量，默认为 0
    - Y：文本左上角顶点坐标 Y 分量，默认为 0
    - Width：文本宽度，默认为 文本宽度
    - Height：文本高度，默认为 文本高度
    - Content：文本内容
    - Color：文本颜色，默认为 白色
    - ColorBack：文本底色，默认为 透明

+ `Image` 标签：

    图片，支持的属性有：

    - X：图片左上角顶点坐标 X 分量，默认为 0
    - Y：图片左上角顶点坐标 Y 分量，默认为 0
    - Width：图片宽度，默认为 图片宽度
    - Height：图片高度，默认为 图片高度
    - Path：图片文件路径
    - Alpha：图片透明度，取值范围为 0~255，默认为 不透明

+ `Circle` 标签：

    圆形，支持的属性有：

    - X：圆心坐标 X 分量，默认为 0
    - Y：圆心坐标 Y 分量，默认为 0
    - Radius：半径大小，默认为 0
    - IsFilled：是否填充，默认为 不填充
    - Color：绘图颜色，默认为 白色

+ `Ellipse` 标签：

    椭圆形，支持的属性有：

    - X：椭圆圆心坐标 X 分量，默认为 0
    - Y：椭圆圆心坐标 Y 分量，默认为 0
    - RadiusX：X 方向半径大小，默认为 0
    - RadiusY：Y 方向半径大小，默认为 0
    - IsFilled：是否填充，默认为 不填充
    - Color：绘图颜色，默认为 白色

+ `Pie` 标签：

    扇形，支持的属性有：

    - X：扇形所在圆圆心坐标 X 分量，默认为 0
    - Y：扇形所在圆圆心坐标 Y 分量，默认为 0
    - Radius：扇形所在圆半径大小，默认为 0
    - StartAngle：扇形起始角度，默认为 0
    - EndAngle：扇形结束角度，默认为 0
    - IsFilled：是否填充，默认为 不填充
    - Color：绘图颜色，默认为 白色

+ `Rectangle` 标签：

    矩形，支持的属性有：

    - X：矩形左上角顶点坐标 X 分量，默认为 0
    - Y：矩形左上角顶点坐标 Y 分量，默认为 0
    - Width：矩形宽度，默认为 0
    - Height：矩形高度，默认为 0
    - Radius：矩形圆角半径大小，默认为 0
    - IsFilled：是否填充，默认为 不填充
    - Color：绘图颜色，默认为 白色

+ `Triangle` 标签：

    三角形，支持的属性有：

    - PointAX：三角形第一个顶点坐标 X 分量，默认为 0
    - PointAY：三角形第一个顶点坐标 Y 分量，默认为 0
    - PointBX：三角形第二个顶点坐标 X 分量，默认为 0
    - PointBY：三角形第二个顶点坐标 Y 分量，默认为 0
    - PointCX：三角形第三个顶点坐标 X 分量，默认为 0
    - PointCY：三角形第三个顶点坐标 Y 分量，默认为 0
    - IsFilled：是否填充，默认为 不填充
    - Color：绘图颜色，默认为 白色

+ `Line` 标签：

    直线，支持的属性有：

    - StartX：直线起点坐标 X 分量，默认为 0
    - StartY：直线起点坐标 Y 分量，默认为 0
    - EndX：直线终点坐标 X 分量，默认为 0
    - EndY：直线终点坐标 Y 分量，默认为 0
    - Width：直线宽度，默认为 1
    - Color：绘图颜色，默认为 白色

+ `Point` 标签：

    直线，支持的属性有：

    - StartX：直线起点坐标 X 分量，默认为 0
    - StartY：直线起点坐标 Y 分量，默认为 0
    - EndX：直线终点坐标 X 分量，默认为 0
    - EndY：直线终点坐标 Y 分量，默认为 0
    - Width：直线宽度，默认为 1
    - Color：绘图颜色，默认为 白色

### 2.3 关于颜色和字体……

+ 对于 `Color` 属性的表示，EasyDrawXML 支持十六进制和RGBA两种表示方式，即 `Color="#FFFFFF"` 和 `Color="255, 255, 255, 255"` 均代表白色，十六进制颜色表示法不支持透明度的表示，若需要透明度支持请使用RGBA颜色空间；当使用RGBA颜色空间且不指定颜色透明度时，颜色默认使用不透明色

+ 在当前版本的 EasyDrawXML 中，只支持使用单一的全局字体，即只使用最后一次在 `Resource` 标签中出现的字体文件，若字体文件加载失败或未指定字体文件，引擎将尝试从 `C:/Windows/Fonts/msyh.ttc` 目录下加载字体，若此字体仍加载失败，则后续的文本渲染将失效

## 3. 最后

最后，特别感谢以下组织或个人：

+ [SDL2](https://www.libsdl.org/)、[SDL_image](https://www.libsdl.org/projects/SDL_image/)、[SDL_ttf](https://www.libsdl.org/projects/SDL_ttf/)、[SDL_gfx](http://www.ferzkopp.net)：为 EasyDrawXML 提供了跨平台的图形解决方案

+ [pugixml](https://github.com/zeux/pugixml)：为 EasyDrawXML 提供了 XML 解析

+ [快乐的老鼠宝宝](https://github.com/LaoshuBaby)：为 EasyDrawXML 中的 XML 解析提供了建议和成熟的解决方案

+ [PasCal++](https://github.com/volatile-static)：为 EasyDrawXML 开发过程中的调试提供了巨大的帮助

欢迎提交 Issue 或联系作者： Voidmatrix@qq.com

> 本项目如有帮助，不胜荣幸