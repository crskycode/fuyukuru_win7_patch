// dllmain.cpp


#include "util.h"
#include "BugTrap/BugTrap.h"


//=============================================================================
// Hook Code
//=============================================================================


#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dwrite.lib")
#pragma comment(lib, "windowscodecs.lib")

#pragma comment(lib, "BugTrap/BugTrapU.lib")


struct D2D1Factory2Proxy;
struct D2D1Device1Proxy;
struct D2D1DeviceContext1Proxy;
struct D3D11Device2Proxy;
struct DXGIDevice3Proxy;
struct DXGISwapChain1Proxy;
struct DWriteFactory2Proxy;
struct WICImagingFactory2Proxy;


/// <summary>
/// ID2D1DeviceContext1 > [ID2D1DeviceContext] > ID2D1RenderTarget > ID2D1Resource > IUnknown
/// </summary>
struct D2D1DeviceContext1Proxy : public ID2D1DeviceContext1
{

    #pragma region IUnknown Implementation

    virtual HRESULT STDMETHODCALLTYPE QueryInterface(
        REFIID riid,
        _COM_Outptr_ void __RPC_FAR* __RPC_FAR* ppvObject
    )
    {
        return This->QueryInterface(riid, ppvObject);
    }

    virtual ULONG STDMETHODCALLTYPE AddRef(void)
    {
        return This->AddRef();
    }

    virtual ULONG STDMETHODCALLTYPE Release(void)
    {
        return This->Release();
    }

    #pragma endregion

    #pragma region ID2D1Resource Implementation

    STDMETHOD_(void, GetFactory)(
        _Outptr_ ID2D1Factory** factory
        ) CONST
    {
        return This->GetFactory(factory);
    }

    #pragma endregion

    #pragma region ID2D1RenderTarget

    STDMETHOD(CreateBitmap)(
        D2D1_SIZE_U size,
        _In_opt_ CONST void* srcData,
        UINT32 pitch,
        _In_ CONST D2D1_BITMAP_PROPERTIES* bitmapProperties,
        _COM_Outptr_ ID2D1Bitmap** bitmap
        )
    {
        return This->CreateBitmap(size, srcData, pitch, bitmapProperties, bitmap);
    }

    STDMETHOD(CreateBitmapFromWicBitmap)(
        _In_ IWICBitmapSource* wicBitmapSource,
        _In_opt_ CONST D2D1_BITMAP_PROPERTIES* bitmapProperties,
        _COM_Outptr_ ID2D1Bitmap** bitmap
        )
    {
        return This->CreateBitmapFromWicBitmap(wicBitmapSource, bitmapProperties, bitmap);
    }

    STDMETHOD(CreateSharedBitmap)(
        _In_ REFIID riid,
        _Inout_ void* data,
        _In_opt_ CONST D2D1_BITMAP_PROPERTIES* bitmapProperties,
        _COM_Outptr_ ID2D1Bitmap** bitmap
        )
    {
        return This->CreateSharedBitmap(riid, data, bitmapProperties, bitmap);
    }

    STDMETHOD(CreateBitmapBrush)(
        _In_opt_ ID2D1Bitmap* bitmap,
        _In_opt_ CONST D2D1_BITMAP_BRUSH_PROPERTIES* bitmapBrushProperties,
        _In_opt_ CONST D2D1_BRUSH_PROPERTIES* brushProperties,
        _COM_Outptr_ ID2D1BitmapBrush** bitmapBrush
        )
    {
        return This->CreateBitmapBrush(bitmap, bitmapBrushProperties, brushProperties, bitmapBrush);
    }

    STDMETHOD(CreateSolidColorBrush)(
        _In_ CONST D2D1_COLOR_F* color,
        _In_opt_ CONST D2D1_BRUSH_PROPERTIES* brushProperties,
        _COM_Outptr_ ID2D1SolidColorBrush** solidColorBrush
        )
    {
        return This->CreateSolidColorBrush(color, brushProperties, solidColorBrush);
    }

    STDMETHOD(CreateGradientStopCollection)(
        _In_reads_(gradientStopsCount) CONST D2D1_GRADIENT_STOP* gradientStops,
        _In_range_(>= , 1) UINT32 gradientStopsCount,
        D2D1_GAMMA colorInterpolationGamma,
        D2D1_EXTEND_MODE extendMode,
        _COM_Outptr_ ID2D1GradientStopCollection** gradientStopCollection
        )
    {
        return This->CreateGradientStopCollection(gradientStops, gradientStopsCount, colorInterpolationGamma, extendMode, gradientStopCollection);
    }

    STDMETHOD(CreateLinearGradientBrush)(
        _In_ CONST D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES* linearGradientBrushProperties,
        _In_opt_ CONST D2D1_BRUSH_PROPERTIES* brushProperties,
        _In_ ID2D1GradientStopCollection* gradientStopCollection,
        _COM_Outptr_ ID2D1LinearGradientBrush** linearGradientBrush
        )
    {
        return This->CreateLinearGradientBrush(linearGradientBrushProperties, brushProperties, gradientStopCollection, linearGradientBrush);
    }

    STDMETHOD(CreateRadialGradientBrush)(
        _In_ CONST D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES* radialGradientBrushProperties,
        _In_opt_ CONST D2D1_BRUSH_PROPERTIES* brushProperties,
        _In_ ID2D1GradientStopCollection* gradientStopCollection,
        _COM_Outptr_ ID2D1RadialGradientBrush** radialGradientBrush
        )
    {
        return This->CreateRadialGradientBrush(radialGradientBrushProperties, brushProperties, gradientStopCollection, radialGradientBrush);
    }

    STDMETHOD(CreateCompatibleRenderTarget)(
        _In_opt_ CONST D2D1_SIZE_F* desiredSize,
        _In_opt_ CONST D2D1_SIZE_U* desiredPixelSize,
        _In_opt_ CONST D2D1_PIXEL_FORMAT* desiredFormat,
        D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS options,
        _COM_Outptr_ ID2D1BitmapRenderTarget** bitmapRenderTarget
        )
    {
        return This->CreateCompatibleRenderTarget(desiredSize, desiredPixelSize, desiredFormat, options, bitmapRenderTarget);
    }

    STDMETHOD(CreateLayer)(
        _In_opt_ CONST D2D1_SIZE_F* size,
        _COM_Outptr_ ID2D1Layer** layer
        )
    {
        return This->CreateLayer(size, layer);
    }

    STDMETHOD(CreateMesh)(
        _COM_Outptr_ ID2D1Mesh** mesh
        )
    {
        return This->CreateMesh(mesh);
    }

    STDMETHOD_(void, DrawLine)(
        D2D1_POINT_2F point0,
        D2D1_POINT_2F point1,
        _In_ ID2D1Brush* brush,
        FLOAT strokeWidth = 1.0f,
        _In_opt_ ID2D1StrokeStyle* strokeStyle = NULL
        )
    {
        return This->DrawLine(point0, point1, brush, strokeWidth, strokeStyle);
    }

    STDMETHOD_(void, DrawRectangle)(
        _In_ CONST D2D1_RECT_F* rect,
        _In_ ID2D1Brush* brush,
        FLOAT strokeWidth = 1.0f,
        _In_opt_ ID2D1StrokeStyle* strokeStyle = NULL
        )
    {
        return This->DrawRectangle(rect, brush, strokeWidth, strokeStyle);
    }

    STDMETHOD_(void, FillRectangle)(
        _In_ CONST D2D1_RECT_F* rect,
        _In_ ID2D1Brush* brush
        )
    {
        return This->FillRectangle(rect, brush);
    }

    STDMETHOD_(void, DrawRoundedRectangle)(
        _In_ CONST D2D1_ROUNDED_RECT* roundedRect,
        _In_ ID2D1Brush* brush,
        FLOAT strokeWidth = 1.0f,
        _In_opt_ ID2D1StrokeStyle* strokeStyle = NULL
        )
    {
        return This->DrawRoundedRectangle(roundedRect, brush, strokeWidth, strokeStyle);
    }

    STDMETHOD_(void, FillRoundedRectangle)(
        _In_ CONST D2D1_ROUNDED_RECT* roundedRect,
        _In_ ID2D1Brush* brush
        )
    {
        return This->FillRoundedRectangle(roundedRect, brush);
    }

    STDMETHOD_(void, DrawEllipse)(
        _In_ CONST D2D1_ELLIPSE* ellipse,
        _In_ ID2D1Brush* brush,
        FLOAT strokeWidth = 1.0f,
        _In_opt_ ID2D1StrokeStyle* strokeStyle = NULL
        )
    {
        return This->DrawEllipse(ellipse, brush, strokeWidth, strokeStyle);
    }

    STDMETHOD_(void, FillEllipse)(
        _In_ CONST D2D1_ELLIPSE* ellipse,
        _In_ ID2D1Brush* brush
        )
    {
        return This->FillEllipse(ellipse, brush);
    }

    STDMETHOD_(void, DrawGeometry)(
        _In_ ID2D1Geometry* geometry,
        _In_ ID2D1Brush* brush,
        FLOAT strokeWidth = 1.0f,
        _In_opt_ ID2D1StrokeStyle* strokeStyle = NULL
        )
    {
        return This->DrawGeometry(geometry, brush, strokeWidth, strokeStyle);
    }

    STDMETHOD_(void, FillGeometry)(
        _In_ ID2D1Geometry* geometry,
        _In_ ID2D1Brush* brush,
        _In_opt_ ID2D1Brush* opacityBrush = NULL
        )
    {
        return This->FillGeometry(geometry, brush, opacityBrush);
    }

    STDMETHOD_(void, FillMesh)(
        _In_ ID2D1Mesh* mesh,
        _In_ ID2D1Brush* brush
        )
    {
        return This->FillMesh(mesh, brush);
    }

    STDMETHOD_(void, FillOpacityMask)(
        _In_ ID2D1Bitmap* opacityMask,
        _In_ ID2D1Brush* brush,
        D2D1_OPACITY_MASK_CONTENT content,
        _In_opt_ CONST D2D1_RECT_F* destinationRectangle = NULL,
        _In_opt_ CONST D2D1_RECT_F* sourceRectangle = NULL
        )
    {
        return This->FillOpacityMask(opacityMask, brush, content, destinationRectangle, sourceRectangle);
    }

    STDMETHOD_(void, DrawBitmap)(
        _In_ ID2D1Bitmap* bitmap,
        _In_opt_ CONST D2D1_RECT_F* destinationRectangle = NULL,
        FLOAT opacity = 1.0f,
        D2D1_BITMAP_INTERPOLATION_MODE interpolationMode = D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,
        _In_opt_ CONST D2D1_RECT_F* sourceRectangle = NULL
        )
    {
        return This->DrawBitmap(bitmap, destinationRectangle, opacity, interpolationMode, sourceRectangle);
    }

    //#undef DrawText

    STDMETHOD_(void, DrawText)(
        _In_reads_(stringLength) CONST WCHAR* string,
        UINT32 stringLength,
        _In_ IDWriteTextFormat* textFormat,
        _In_ CONST D2D1_RECT_F* layoutRect,
        _In_ ID2D1Brush* defaultFillBrush,
        D2D1_DRAW_TEXT_OPTIONS options = D2D1_DRAW_TEXT_OPTIONS_NONE,
        DWRITE_MEASURING_MODE measuringMode = DWRITE_MEASURING_MODE_NATURAL
        )
    {
        return This->DrawText(string, stringLength, textFormat, layoutRect, defaultFillBrush, options, measuringMode);
    }

    STDMETHOD_(void, DrawTextLayout)(
        D2D1_POINT_2F origin,
        _In_ IDWriteTextLayout* textLayout,
        _In_ ID2D1Brush* defaultFillBrush,
        D2D1_DRAW_TEXT_OPTIONS options = D2D1_DRAW_TEXT_OPTIONS_NONE
        )
    {
        return This->DrawTextLayout(origin, textLayout, defaultFillBrush, options);
    }

    STDMETHOD_(void, DrawGlyphRun)(
        D2D1_POINT_2F baselineOrigin,
        _In_ CONST DWRITE_GLYPH_RUN* glyphRun,
        _In_ ID2D1Brush* foregroundBrush,
        DWRITE_MEASURING_MODE measuringMode = DWRITE_MEASURING_MODE_NATURAL
        )
    {
        return This->DrawGlyphRun(baselineOrigin, glyphRun, foregroundBrush, measuringMode);
    }

    STDMETHOD_(void, SetTransform)(
        _In_ CONST D2D1_MATRIX_3X2_F* transform
        )
    {
        return This->SetTransform(transform);
    }

    STDMETHOD_(void, GetTransform)(
        _Out_ D2D1_MATRIX_3X2_F* transform
        ) CONST
    {
        return This->GetTransform(transform);
    }

    STDMETHOD_(void, SetAntialiasMode)(
        D2D1_ANTIALIAS_MODE antialiasMode
        )
    {
        return This->SetAntialiasMode(antialiasMode);
    }

    STDMETHOD_(D2D1_ANTIALIAS_MODE, GetAntialiasMode)(
        ) CONST
    {
        return This->GetAntialiasMode();
    }

    STDMETHOD_(void, SetTextAntialiasMode)(
        D2D1_TEXT_ANTIALIAS_MODE textAntialiasMode
        )
    {
        return This->SetTextAntialiasMode(textAntialiasMode);
    }

    STDMETHOD_(D2D1_TEXT_ANTIALIAS_MODE, GetTextAntialiasMode)(
        ) CONST
    {
        return This->GetTextAntialiasMode();
    }

    STDMETHOD_(void, SetTextRenderingParams)(
        _In_opt_ IDWriteRenderingParams* textRenderingParams = NULL
        )
    {
        return This->SetTextRenderingParams(textRenderingParams);
    }

    STDMETHOD_(void, GetTextRenderingParams)(
        _Outptr_result_maybenull_ IDWriteRenderingParams** textRenderingParams
        ) CONST
    {
        return This->GetTextRenderingParams(textRenderingParams);
    }

    STDMETHOD_(void, SetTags)(
        D2D1_TAG tag1,
        D2D1_TAG tag2
        )
    {
        return This->SetTags(tag1, tag2);
    }

    STDMETHOD_(void, GetTags)(
        _Out_opt_ D2D1_TAG* tag1 = NULL,
        _Out_opt_ D2D1_TAG* tag2 = NULL
        ) CONST
    {
        return This->GetTags(tag1, tag2);
    }

    STDMETHOD_(void, PushLayer)(
        _In_ CONST D2D1_LAYER_PARAMETERS* layerParameters,
        _In_opt_ ID2D1Layer* layer
        )
    {
        return This->PushLayer(layerParameters, layer);
    }

    STDMETHOD_(void, PopLayer)(
        )
    {
        return This->PopLayer();
    }

    STDMETHOD(Flush)(
        _Out_opt_ D2D1_TAG* tag1 = NULL,
        _Out_opt_ D2D1_TAG* tag2 = NULL
        )
    {
        return This->Flush(tag1, tag2);
    }

    STDMETHOD_(void, SaveDrawingState)(
        _Inout_ ID2D1DrawingStateBlock* drawingStateBlock
        ) CONST
    {
        return This->SaveDrawingState(drawingStateBlock);
    }

    STDMETHOD_(void, RestoreDrawingState)(
        _In_ ID2D1DrawingStateBlock* drawingStateBlock
        )
    {
        return This->RestoreDrawingState(drawingStateBlock);
    }

    STDMETHOD_(void, PushAxisAlignedClip)(
        _In_ CONST D2D1_RECT_F* clipRect,
        D2D1_ANTIALIAS_MODE antialiasMode
        )
    {
        return This->PushAxisAlignedClip(clipRect, antialiasMode);
    }

    STDMETHOD_(void, PopAxisAlignedClip)(
        )
    {
        return This->PopAxisAlignedClip();
    }

    STDMETHOD_(void, Clear)(
        _In_opt_ CONST D2D1_COLOR_F* clearColor = NULL
        )
    {
        return This->Clear(clearColor);
    }

    STDMETHOD_(void, BeginDraw)(
        )
    {
        return This->BeginDraw();
    }

    STDMETHOD(EndDraw)(
        _Out_opt_ D2D1_TAG* tag1 = NULL,
        _Out_opt_ D2D1_TAG* tag2 = NULL
        )
    {
        return This->EndDraw(tag1, tag2);
    }

    STDMETHOD_(D2D1_PIXEL_FORMAT, GetPixelFormat)(
        ) CONST
    {
        return This->GetPixelFormat();
    }

    STDMETHOD_(void, SetDpi)(
        FLOAT dpiX,
        FLOAT dpiY
        )
    {
        return This->SetDpi(dpiX, dpiY);
    }

    STDMETHOD_(void, GetDpi)(
        _Out_ FLOAT* dpiX,
        _Out_ FLOAT* dpiY
        ) CONST
    {
        return This->GetDpi(dpiX, dpiY);
    }

    STDMETHOD_(D2D1_SIZE_F, GetSize)(
        ) CONST
    {
        return This->GetSize();
    }

    STDMETHOD_(D2D1_SIZE_U, GetPixelSize)(
        ) CONST
    {
        return This->GetPixelSize();
    }

    STDMETHOD_(UINT32, GetMaximumBitmapSize)(
        ) CONST
    {
        return This->GetMaximumBitmapSize();
    }

    STDMETHOD_(BOOL, IsSupported)(
        _In_ CONST D2D1_RENDER_TARGET_PROPERTIES* renderTargetProperties
        ) CONST
    {
        return This->IsSupported(renderTargetProperties);
    }

    #pragma endregion

    #pragma region ID2D1DeviceContext Implementation

    STDMETHOD(CreateBitmap)(
        D2D1_SIZE_U size,
        _In_opt_ CONST void* sourceData,
        UINT32 pitch,
        _In_ CONST D2D1_BITMAP_PROPERTIES1* bitmapProperties,
        _COM_Outptr_ ID2D1Bitmap1** bitmap
        )
    {
        return This->CreateBitmap(size, sourceData, pitch, bitmapProperties, bitmap);
    }

    STDMETHOD(CreateBitmapFromWicBitmap)(
        _In_ IWICBitmapSource* wicBitmapSource,
        _In_opt_ CONST D2D1_BITMAP_PROPERTIES1* bitmapProperties,
        _COM_Outptr_ ID2D1Bitmap1** bitmap
        )
    {
        return This->CreateBitmapFromWicBitmap(wicBitmapSource, bitmapProperties, bitmap);
    }

    STDMETHOD(CreateColorContext)(
        D2D1_COLOR_SPACE space,
        _In_reads_opt_(profileSize) CONST BYTE* profile,
        UINT32 profileSize,
        _COM_Outptr_ ID2D1ColorContext** colorContext
        )
    {
        return This->CreateColorContext(space, profile, profileSize, colorContext);
    }

    STDMETHOD(CreateColorContextFromFilename)(
        _In_ PCWSTR filename,
        _COM_Outptr_ ID2D1ColorContext** colorContext
        )
    {
        return This->CreateColorContextFromFilename(filename, colorContext);
    }

    STDMETHOD(CreateColorContextFromWicColorContext)(
        _In_ IWICColorContext* wicColorContext,
        _COM_Outptr_ ID2D1ColorContext** colorContext
        )
    {
        return This->CreateColorContextFromWicColorContext(wicColorContext, colorContext);
    }

    STDMETHOD(CreateBitmapFromDxgiSurface)(
        _In_ IDXGISurface* surface,
        _In_opt_ CONST D2D1_BITMAP_PROPERTIES1* bitmapProperties,
        _COM_Outptr_ ID2D1Bitmap1** bitmap
        )
    {
        return This->CreateBitmapFromDxgiSurface(surface, bitmapProperties, bitmap);
    }

    STDMETHOD(CreateEffect)(
        _In_ REFCLSID effectId,
        _COM_Outptr_ ID2D1Effect** effect
        )
    {
        return This->CreateEffect(effectId, effect);
    }

    STDMETHOD(CreateGradientStopCollection)(
        _In_reads_(straightAlphaGradientStopsCount) CONST D2D1_GRADIENT_STOP* straightAlphaGradientStops,
        _In_range_(>= , 1) UINT32 straightAlphaGradientStopsCount,
        D2D1_COLOR_SPACE preInterpolationSpace,
        D2D1_COLOR_SPACE postInterpolationSpace,
        D2D1_BUFFER_PRECISION bufferPrecision,
        D2D1_EXTEND_MODE extendMode,
        D2D1_COLOR_INTERPOLATION_MODE colorInterpolationMode,
        _COM_Outptr_ ID2D1GradientStopCollection1** gradientStopCollection1
        )
    {
        return This->CreateGradientStopCollection(straightAlphaGradientStops, straightAlphaGradientStopsCount,
            preInterpolationSpace, postInterpolationSpace, bufferPrecision, extendMode, colorInterpolationMode, gradientStopCollection1);
    }

    STDMETHOD(CreateImageBrush)(
        _In_opt_ ID2D1Image* image,
        _In_ CONST D2D1_IMAGE_BRUSH_PROPERTIES* imageBrushProperties,
        _In_opt_ CONST D2D1_BRUSH_PROPERTIES* brushProperties,
        _COM_Outptr_ ID2D1ImageBrush** imageBrush
        )
    {
        return This->CreateImageBrush(image, imageBrushProperties, brushProperties, imageBrush);
    }

    STDMETHOD(CreateBitmapBrush)(
        _In_opt_ ID2D1Bitmap* bitmap,
        _In_opt_ CONST D2D1_BITMAP_BRUSH_PROPERTIES1* bitmapBrushProperties,
        _In_opt_ CONST D2D1_BRUSH_PROPERTIES* brushProperties,
        _COM_Outptr_ ID2D1BitmapBrush1** bitmapBrush
        )
    {
        return This->CreateBitmapBrush(bitmap, bitmapBrushProperties, brushProperties, bitmapBrush);
    }

    STDMETHOD(CreateCommandList)(
        _COM_Outptr_ ID2D1CommandList** commandList
        )
    {
        return This->CreateCommandList(commandList);
    }

    STDMETHOD_(BOOL, IsDxgiFormatSupported)(
        DXGI_FORMAT format
        ) CONST
    {
        return This->IsDxgiFormatSupported(format);
    }

    STDMETHOD_(BOOL, IsBufferPrecisionSupported)(
        D2D1_BUFFER_PRECISION bufferPrecision
        ) CONST
    {
        return This->IsBufferPrecisionSupported(bufferPrecision);
    }

    STDMETHOD(GetImageLocalBounds)(
        _In_ ID2D1Image* image,
        _Out_ D2D1_RECT_F* localBounds
        ) CONST
    {
        return This->GetImageLocalBounds(image, localBounds);
    }

    STDMETHOD(GetImageWorldBounds)(
        _In_ ID2D1Image* image,
        _Out_ D2D1_RECT_F* worldBounds
        ) CONST
    {
        return This->GetImageWorldBounds(image, worldBounds);
    }

    STDMETHOD(GetGlyphRunWorldBounds)(
        D2D1_POINT_2F baselineOrigin,
        _In_ CONST DWRITE_GLYPH_RUN* glyphRun,
        DWRITE_MEASURING_MODE measuringMode,
        _Out_ D2D1_RECT_F* bounds
        ) CONST
    {
        return This->GetGlyphRunWorldBounds(baselineOrigin, glyphRun, measuringMode, bounds);
    }

    STDMETHOD_(void, GetDevice)(
        _Outptr_ ID2D1Device** device
        ) CONST
    {
        return This->GetDevice(device);
    }

    STDMETHOD_(void, SetTarget)(
        _In_opt_ ID2D1Image* image
        )
    {
        return This->SetTarget(image);
    }

    STDMETHOD_(void, GetTarget)(
        _Outptr_result_maybenull_ ID2D1Image** image
        ) CONST
    {
        return This->GetTarget(image);
    }

    STDMETHOD_(void, SetRenderingControls)(
        _In_ CONST D2D1_RENDERING_CONTROLS* renderingControls
        )
    {
        return This->SetRenderingControls(renderingControls);
    }

    STDMETHOD_(void, GetRenderingControls)(
        _Out_ D2D1_RENDERING_CONTROLS* renderingControls
        ) CONST
    {
        return This->GetRenderingControls(renderingControls);
    }

    STDMETHOD_(void, SetPrimitiveBlend)(
        D2D1_PRIMITIVE_BLEND primitiveBlend
        )
    {
        return This->SetPrimitiveBlend(primitiveBlend);
    }

    STDMETHOD_(D2D1_PRIMITIVE_BLEND, GetPrimitiveBlend)(
        ) CONST
    {
        return This->GetPrimitiveBlend();
    }

    STDMETHOD_(void, SetUnitMode)(
        D2D1_UNIT_MODE unitMode
        )
    {
        return This->SetUnitMode(unitMode);
    }

    STDMETHOD_(D2D1_UNIT_MODE, GetUnitMode)(
        ) CONST
    {
        return This->GetUnitMode();
    }

    STDMETHOD_(void, DrawGlyphRun)(
        D2D1_POINT_2F baselineOrigin,
        _In_ CONST DWRITE_GLYPH_RUN* glyphRun,
        _In_opt_ CONST DWRITE_GLYPH_RUN_DESCRIPTION* glyphRunDescription,
        _In_ ID2D1Brush* foregroundBrush,
        DWRITE_MEASURING_MODE measuringMode = DWRITE_MEASURING_MODE_NATURAL
        )
    {
        return This->DrawGlyphRun(baselineOrigin, glyphRun, glyphRunDescription, foregroundBrush, measuringMode);
    }

    STDMETHOD_(void, DrawImage)(
        _In_ ID2D1Image* image,
        _In_opt_ CONST D2D1_POINT_2F* targetOffset = NULL,
        _In_opt_ CONST D2D1_RECT_F* imageRectangle = NULL,
        D2D1_INTERPOLATION_MODE interpolationMode = D2D1_INTERPOLATION_MODE_LINEAR,
        D2D1_COMPOSITE_MODE compositeMode = D2D1_COMPOSITE_MODE_SOURCE_OVER
        )
    {
        return This->DrawImage(image, targetOffset, imageRectangle, interpolationMode, compositeMode);
    }

    STDMETHOD_(void, DrawGdiMetafile)(
        _In_ ID2D1GdiMetafile* gdiMetafile,
        _In_opt_ CONST D2D1_POINT_2F* targetOffset = NULL
        )
    {
        return This->DrawGdiMetafile(gdiMetafile, targetOffset);
    }

    STDMETHOD_(void, DrawBitmap)(
        _In_ ID2D1Bitmap* bitmap,
        _In_opt_ CONST D2D1_RECT_F* destinationRectangle,
        FLOAT opacity,
        D2D1_INTERPOLATION_MODE interpolationMode,
        _In_opt_ CONST D2D1_RECT_F* sourceRectangle = NULL,
        _In_opt_ CONST D2D1_MATRIX_4X4_F* perspectiveTransform = NULL
        )
    {
        return This->DrawBitmap(bitmap, destinationRectangle, opacity, interpolationMode, sourceRectangle, perspectiveTransform);
    }

    STDMETHOD_(void, PushLayer)(
        _In_ CONST D2D1_LAYER_PARAMETERS1* layerParameters,
        _In_opt_ ID2D1Layer* layer
        )
    {
        return This->PushLayer(layerParameters, layer);
    }

    STDMETHOD(InvalidateEffectInputRectangle)(
        _In_ ID2D1Effect* effect,
        UINT32 input,
        _In_ CONST D2D1_RECT_F* inputRectangle
        )
    {
        return This->InvalidateEffectInputRectangle(effect, input, inputRectangle);
    }

    STDMETHOD(GetEffectInvalidRectangleCount)(
        _In_ ID2D1Effect* effect,
        _Out_ UINT32* rectangleCount
        )
    {
        return This->GetEffectInvalidRectangleCount(effect, rectangleCount);
    }

    STDMETHOD(GetEffectInvalidRectangles)(
        _In_ ID2D1Effect* effect,
        _Out_writes_(rectanglesCount) D2D1_RECT_F* rectangles,
        UINT32 rectanglesCount
        )
    {
        return This->GetEffectInvalidRectangles(effect, rectangles, rectanglesCount);
    }

    STDMETHOD(GetEffectRequiredInputRectangles)(
        _In_ ID2D1Effect* renderEffect,
        _In_opt_ CONST D2D1_RECT_F* renderImageRectangle,
        _In_reads_(inputCount) CONST D2D1_EFFECT_INPUT_DESCRIPTION* inputDescriptions,
        _Out_writes_(inputCount) D2D1_RECT_F* requiredInputRects,
        UINT32 inputCount
        )
    {
        return This->GetEffectRequiredInputRectangles(renderEffect, renderImageRectangle, inputDescriptions, requiredInputRects, inputCount);
    }

    STDMETHOD_(void, FillOpacityMask)(
        _In_ ID2D1Bitmap* opacityMask,
        _In_ ID2D1Brush* brush,
        _In_opt_ CONST D2D1_RECT_F* destinationRectangle = NULL,
        _In_opt_ CONST D2D1_RECT_F* sourceRectangle = NULL
        )
    {
        return This->FillOpacityMask(opacityMask, brush, destinationRectangle, sourceRectangle);
    }

    #pragma endregion

    #pragma region ID2D1DeviceContext1 Implementation

    STDMETHOD(CreateFilledGeometryRealization)(
        _In_ ID2D1Geometry* geometry,
        FLOAT flatteningTolerance,
        _COM_Outptr_ ID2D1GeometryRealization** geometryRealization
        )
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
        return E_NOTIMPL;
    }

    STDMETHOD(CreateStrokedGeometryRealization)(
        _In_ ID2D1Geometry* geometry,
        FLOAT flatteningTolerance,
        FLOAT strokeWidth,
        _In_opt_ ID2D1StrokeStyle* strokeStyle,
        _COM_Outptr_ ID2D1GeometryRealization** geometryRealization
        )
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
        return E_NOTIMPL;
    }

    STDMETHOD_(void, DrawGeometryRealization)(
        _In_ ID2D1GeometryRealization* geometryRealization,
        _In_ ID2D1Brush* brush
        )
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
    }

    #pragma endregion

    #pragma region Context

    D2D1DeviceContext1Proxy(ID2D1DeviceContext* pThis)
    {
        This = pThis;
    }

    ID2D1DeviceContext* This;

    #pragma endregion
};

/// <summary>
/// ID2D1Device1 > [ID2D1Device] > ID2D1Resource > IUnknown
/// </summary>
struct D2D1Device1Proxy : public ID2D1Device1
{
    // Hook ID2D1Device1::CreateDeviceContext

    #pragma region IUnknown Implementation

    virtual HRESULT STDMETHODCALLTYPE QueryInterface(
        REFIID riid,
        _COM_Outptr_ void __RPC_FAR* __RPC_FAR* ppvObject
    )
    {
        return This->QueryInterface(riid, ppvObject);
    }

    virtual ULONG STDMETHODCALLTYPE AddRef(void)
    {
        return This->AddRef();
    }

    virtual ULONG STDMETHODCALLTYPE Release(void)
    {
        return This->Release();
    }

    #pragma endregion

    #pragma region ID2D1Resource Implementation

    STDMETHOD_(void, GetFactory)(
        _Outptr_ ID2D1Factory** factory
        ) CONST
    {
        return This->GetFactory(factory);
    }

    #pragma endregion

    #pragma region ID2D1Device Implementation

    STDMETHOD(CreateDeviceContext)(
        D2D1_DEVICE_CONTEXT_OPTIONS options,
        _COM_Outptr_ ID2D1DeviceContext** deviceContext
        )
    {
        return This->CreateDeviceContext(options, deviceContext);
    }

    STDMETHOD(CreatePrintControl)(
        _In_ IWICImagingFactory* wicFactory,
        _In_ IPrintDocumentPackageTarget* documentTarget,
        _In_opt_ CONST D2D1_PRINT_CONTROL_PROPERTIES* printControlProperties,
        _COM_Outptr_ ID2D1PrintControl** printControl
        )
    {
        return This->CreatePrintControl(wicFactory, documentTarget, printControlProperties, printControl);
    }

    STDMETHOD_(void, SetMaximumTextureMemory)(
        UINT64 maximumInBytes
        )
    {
        return This->SetMaximumTextureMemory(maximumInBytes);
    }

    STDMETHOD_(UINT64, GetMaximumTextureMemory)(
        ) CONST
    {
        return This->GetMaximumTextureMemory();
    }

    STDMETHOD_(void, ClearResources)(
        UINT32 millisecondsSinceUse = 0
        )
    {
        return This->ClearResources(millisecondsSinceUse);
    }

    #pragma endregion

    #pragma region ID2D1Device1 Implementation

    STDMETHOD_(D2D1_RENDERING_PRIORITY, GetRenderingPriority)(
        )
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
        return D2D1_RENDERING_PRIORITY_NORMAL;
    }

    STDMETHOD_(void, SetRenderingPriority)(
        D2D1_RENDERING_PRIORITY renderingPriority
        )
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
    }

    STDMETHOD(CreateDeviceContext)(
        D2D1_DEVICE_CONTEXT_OPTIONS options,
        _COM_Outptr_ ID2D1DeviceContext1** deviceContext1
        )
    {
        ID2D1DeviceContext* pD2D1DeviceContext;

        HRESULT result = This->CreateDeviceContext(options, &pD2D1DeviceContext);

        if (result == S_OK)
        {
            LogWrite(L"%s : Using ID2D1Device\n", __FUNCTIONW__);

            *deviceContext1 = new D2D1DeviceContext1Proxy(pD2D1DeviceContext);

            return S_OK;
        }

        LogWrite(L"%s : Failed\n", __FUNCTIONW__);

        return E_NOTIMPL;
    }

    #pragma endregion

    #pragma region Context

    D2D1Device1Proxy(ID2D1Device* pThis)
    {
        This = pThis;
    }

    ID2D1Device* This;

    #pragma endregion
};

/// <summary>
/// ID2D1Factory2 > [ID2D1Factory1] > ID2D1Factory > IUnknown
/// </summary>
struct D2D1Factory2Proxy : public ID2D1Factory2
{
    // Hook ID2D1Factory2::CreateDevice

    #pragma region IUnknown Implementation

    virtual HRESULT STDMETHODCALLTYPE QueryInterface(
        REFIID riid,
        _COM_Outptr_ void __RPC_FAR* __RPC_FAR* ppvObject
        )
    {
        return This->QueryInterface(riid, ppvObject);
    }

    virtual ULONG STDMETHODCALLTYPE AddRef(void)
    {
        return This->AddRef();
    }

    virtual ULONG STDMETHODCALLTYPE Release(void)
    {
        return This->Release();
    }

    #pragma endregion

    #pragma region ID2D1Factory Implementation

    STDMETHOD(ReloadSystemMetrics)(
        )
    {
        return This->ReloadSystemMetrics();
    }

    STDMETHOD_(void, GetDesktopDpi)(
        _Out_ FLOAT* dpiX,
        _Out_ FLOAT* dpiY
        )
    {
        return This->GetDesktopDpi(dpiX, dpiY);
    }

    STDMETHOD(CreateRectangleGeometry)(
        _In_ CONST D2D1_RECT_F* rectangle,
        _COM_Outptr_ ID2D1RectangleGeometry** rectangleGeometry
        )
    {
        return This->CreateRectangleGeometry(rectangle, rectangleGeometry);
    }

    STDMETHOD(CreateRoundedRectangleGeometry)(
        _In_ CONST D2D1_ROUNDED_RECT* roundedRectangle,
        _COM_Outptr_ ID2D1RoundedRectangleGeometry** roundedRectangleGeometry
        )
    {
        return This->CreateRoundedRectangleGeometry(roundedRectangle, roundedRectangleGeometry);
    }

    STDMETHOD(CreateEllipseGeometry)(
        _In_ CONST D2D1_ELLIPSE* ellipse,
        _COM_Outptr_ ID2D1EllipseGeometry** ellipseGeometry
        )
    {
        return This->CreateEllipseGeometry(ellipse, ellipseGeometry);
    }

    STDMETHOD(CreateGeometryGroup)(
        D2D1_FILL_MODE fillMode,
        _In_reads_(geometriesCount) ID2D1Geometry** geometries,
        UINT32 geometriesCount,
        _COM_Outptr_ ID2D1GeometryGroup** geometryGroup
        )
    {
        return This->CreateGeometryGroup(fillMode, geometries, geometriesCount, geometryGroup);
    }

    STDMETHOD(CreateTransformedGeometry)(
        _In_ ID2D1Geometry* sourceGeometry,
        _In_ CONST D2D1_MATRIX_3X2_F* transform,
        _COM_Outptr_ ID2D1TransformedGeometry** transformedGeometry
        )
    {
        return This->CreateTransformedGeometry(sourceGeometry, transform, transformedGeometry);
    }

    STDMETHOD(CreatePathGeometry)(
        _COM_Outptr_ ID2D1PathGeometry** pathGeometry
        )
    {
        return This->CreatePathGeometry(pathGeometry);
    }

    STDMETHOD(CreateStrokeStyle)(
        _In_ CONST D2D1_STROKE_STYLE_PROPERTIES* strokeStyleProperties,
        _In_reads_opt_(dashesCount) CONST FLOAT* dashes,
        UINT32 dashesCount,
        _COM_Outptr_ ID2D1StrokeStyle** strokeStyle
        )
    {
        return This->CreateStrokeStyle(strokeStyleProperties, dashes, dashesCount, strokeStyle);
    }

    STDMETHOD(CreateDrawingStateBlock)(
        _In_opt_ CONST D2D1_DRAWING_STATE_DESCRIPTION* drawingStateDescription,
        _In_opt_ IDWriteRenderingParams* textRenderingParams,
        _COM_Outptr_ ID2D1DrawingStateBlock** drawingStateBlock
        )
    {
        return This->CreateDrawingStateBlock(drawingStateDescription, textRenderingParams, drawingStateBlock);
    }

    STDMETHOD(CreateWicBitmapRenderTarget)(
        _In_ IWICBitmap* target,
        _In_ CONST D2D1_RENDER_TARGET_PROPERTIES* renderTargetProperties,
        _COM_Outptr_ ID2D1RenderTarget** renderTarget
        )
    {
        return This->CreateWicBitmapRenderTarget(target, renderTargetProperties, renderTarget);
    }

    STDMETHOD(CreateHwndRenderTarget)(
        _In_ CONST D2D1_RENDER_TARGET_PROPERTIES* renderTargetProperties,
        _In_ CONST D2D1_HWND_RENDER_TARGET_PROPERTIES* hwndRenderTargetProperties,
        _COM_Outptr_ ID2D1HwndRenderTarget** hwndRenderTarget
        )
    {
        return This->CreateHwndRenderTarget(renderTargetProperties, hwndRenderTargetProperties, hwndRenderTarget);
    }

    STDMETHOD(CreateDxgiSurfaceRenderTarget)(
        _In_ IDXGISurface* dxgiSurface,
        _In_ CONST D2D1_RENDER_TARGET_PROPERTIES* renderTargetProperties,
        _COM_Outptr_ ID2D1RenderTarget** renderTarget
        )
    {
        return This->CreateDxgiSurfaceRenderTarget(dxgiSurface, renderTargetProperties, renderTarget);
    }

    STDMETHOD(CreateDCRenderTarget)(
        _In_ CONST D2D1_RENDER_TARGET_PROPERTIES* renderTargetProperties,
        _COM_Outptr_ ID2D1DCRenderTarget** dcRenderTarget
        )
    {
        return This->CreateDCRenderTarget(renderTargetProperties, dcRenderTarget);
    }

    #pragma endregion

    #pragma region ID2D1Factory1 Implementation

    STDMETHOD(CreateDevice)(
        _In_ IDXGIDevice* dxgiDevice,
        _COM_Outptr_ ID2D1Device** d2dDevice
        )
    {
        return This->CreateDevice(dxgiDevice, d2dDevice);
    }

    STDMETHOD(CreateStrokeStyle)(
        _In_ CONST D2D1_STROKE_STYLE_PROPERTIES1* strokeStyleProperties,
        _In_reads_opt_(dashesCount) CONST FLOAT* dashes,
        UINT32 dashesCount,
        _COM_Outptr_ ID2D1StrokeStyle1** strokeStyle
        )
    {
        return This->CreateStrokeStyle(strokeStyleProperties, dashes, dashesCount, strokeStyle);
    }

    STDMETHOD(CreatePathGeometry)(
        _COM_Outptr_ ID2D1PathGeometry1** pathGeometry
        )
    {
        return This->CreatePathGeometry(pathGeometry);
    }

    STDMETHOD(CreateDrawingStateBlock)(
        _In_opt_ CONST D2D1_DRAWING_STATE_DESCRIPTION1* drawingStateDescription,
        _In_opt_ IDWriteRenderingParams* textRenderingParams,
        _COM_Outptr_ ID2D1DrawingStateBlock1** drawingStateBlock
        )
    {
        return This->CreateDrawingStateBlock(drawingStateDescription, textRenderingParams, drawingStateBlock);
    }

    STDMETHOD(CreateGdiMetafile)(
        _In_ IStream* metafileStream,
        _COM_Outptr_ ID2D1GdiMetafile** metafile
        )
    {
        return This->CreateGdiMetafile(metafileStream, metafile);
    }

    STDMETHOD(RegisterEffectFromStream)(
        _In_ REFCLSID classId,
        _In_ IStream* propertyXml,
        _In_reads_opt_(bindingsCount) CONST D2D1_PROPERTY_BINDING* bindings,
        UINT32 bindingsCount,
        _In_ CONST PD2D1_EFFECT_FACTORY effectFactory
        )
    {
        return This->RegisterEffectFromStream(classId, propertyXml, bindings, bindingsCount, effectFactory);
    }

    STDMETHOD(RegisterEffectFromString)(
        _In_ REFCLSID classId,
        _In_ PCWSTR propertyXml,
        _In_reads_opt_(bindingsCount) CONST D2D1_PROPERTY_BINDING* bindings,
        UINT32 bindingsCount,
        _In_ CONST PD2D1_EFFECT_FACTORY effectFactory
        )
    {
        return This->RegisterEffectFromString(classId, propertyXml, bindings, bindingsCount, effectFactory);
    }

    STDMETHOD(UnregisterEffect)(
        _In_ REFCLSID classId
        )
    {
        return This->UnregisterEffect(classId);
    }

    STDMETHOD(GetRegisteredEffects)(
        _Out_writes_to_opt_(effectsCount, *effectsReturned) CLSID* effects,
        UINT32 effectsCount,
        _Out_opt_ UINT32* effectsReturned,
        _Out_opt_ UINT32* effectsRegistered
        ) CONST
    {
        return This->GetRegisteredEffects(effects, effectsCount, effectsReturned, effectsRegistered);
    }

    STDMETHOD(GetEffectProperties)(
        _In_ REFCLSID effectId,
        _COM_Outptr_ ID2D1Properties** properties
        ) CONST
    {
        return This->GetEffectProperties(effectId, properties);
    }

    #pragma endregion

    #pragma region ID2D1Factory2 Implementation

    STDMETHOD(CreateDevice)(
        _In_ IDXGIDevice* dxgiDevice,
        _COM_Outptr_ ID2D1Device1** d2dDevice1
        )
    {
        ID2D1Device* pD2D1Device;

        HRESULT result = This->CreateDevice(dxgiDevice, &pD2D1Device);

        if (result == S_OK)
        {
            LogWrite(L"%s : Using ID2D1Factory1\n", __FUNCTIONW__);

            *d2dDevice1 = new D2D1Device1Proxy(pD2D1Device);

            return S_OK;
        }

        LogWrite(L"%s : Failed\n", __FUNCTIONW__);

        return E_NOTIMPL;
    }

    #pragma endregion

    #pragma region Context

    D2D1Factory2Proxy(ID2D1Factory1* pThis)
    {
        This = pThis;
    }

    ID2D1Factory1* This;

    #pragma endregion
};

/// <summary>
/// ID3D11DeviceContext2 > ID3D11DeviceContext1 > [ID3D11DeviceContext] > ID3D11DeviceChild > IUnknown
/// </summary>
struct D3D11DeviceContext2Proxy : public ID3D11DeviceContext2
{
    // Hook IUnknown::QueryInterface

    #pragma region IUnknown Implementation

    virtual HRESULT STDMETHODCALLTYPE QueryInterface(
        REFIID riid,
        _COM_Outptr_ void __RPC_FAR* __RPC_FAR* ppvObject
        )
    {
        if (riid == __uuidof(ID3D11DeviceContext2))
        {
            LogWrite(L"%s : Returns this proxy\n", __FUNCTIONW__);
            *ppvObject = this;
            return S_OK;
        }

        return This->QueryInterface(riid, ppvObject);
    }

    virtual ULONG STDMETHODCALLTYPE AddRef(void)
    {
        return This->AddRef();
    }

    virtual ULONG STDMETHODCALLTYPE Release(void)
    {
        return This->Release();
    }

    #pragma endregion

    #pragma region ID3D11DeviceChild Implementation

    virtual void STDMETHODCALLTYPE GetDevice(
        _Outptr_  ID3D11Device** ppDevice)
    {
        return This->GetDevice(ppDevice);
    }

    virtual HRESULT STDMETHODCALLTYPE GetPrivateData(
        _In_  REFGUID guid,
        _Inout_  UINT* pDataSize,
        _Out_writes_bytes_opt_(*pDataSize)  void* pData)
    {
        return This->GetPrivateData(guid, pDataSize, pData);
    }

    virtual HRESULT STDMETHODCALLTYPE SetPrivateData(
        _In_  REFGUID guid,
        _In_  UINT DataSize,
        _In_reads_bytes_opt_(DataSize)  const void* pData)
    {
        return This->SetPrivateData(guid, DataSize, pData);
    }

    virtual HRESULT STDMETHODCALLTYPE SetPrivateDataInterface(
        _In_  REFGUID guid,
        _In_opt_  const IUnknown* pData)
    {
        return This->SetPrivateDataInterface(guid, pData);
    }

    #pragma endregion

    #pragma region ID3D11DeviceContext Implementation

    virtual void STDMETHODCALLTYPE VSSetConstantBuffers(
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
        _In_reads_opt_(NumBuffers)  ID3D11Buffer* const* ppConstantBuffers)
    {
        return This->VSSetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
    }

    virtual void STDMETHODCALLTYPE PSSetShaderResources(
        _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot)  UINT NumViews,
        _In_reads_opt_(NumViews)  ID3D11ShaderResourceView* const* ppShaderResourceViews)
    {
        return This->PSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
    }

    virtual void STDMETHODCALLTYPE PSSetShader(
        _In_opt_  ID3D11PixelShader* pPixelShader,
        _In_reads_opt_(NumClassInstances)  ID3D11ClassInstance* const* ppClassInstances,
        UINT NumClassInstances)
    {
        return This->PSSetShader(pPixelShader, ppClassInstances, NumClassInstances);
    }

    virtual void STDMETHODCALLTYPE PSSetSamplers(
        _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot)  UINT NumSamplers,
        _In_reads_opt_(NumSamplers)  ID3D11SamplerState* const* ppSamplers)
    {
        return This->PSSetSamplers(StartSlot, NumSamplers, ppSamplers);
    }

    virtual void STDMETHODCALLTYPE VSSetShader(
        _In_opt_  ID3D11VertexShader* pVertexShader,
        _In_reads_opt_(NumClassInstances)  ID3D11ClassInstance* const* ppClassInstances,
        UINT NumClassInstances)
    {
        return This->VSSetShader(pVertexShader, ppClassInstances, NumClassInstances);
    }

    virtual void STDMETHODCALLTYPE DrawIndexed(
        _In_  UINT IndexCount,
        _In_  UINT StartIndexLocation,
        _In_  INT BaseVertexLocation)
    {
        return This->DrawIndexed(IndexCount, StartIndexLocation, BaseVertexLocation);
    }

    virtual void STDMETHODCALLTYPE Draw(
        _In_  UINT VertexCount,
        _In_  UINT StartVertexLocation)
    {
        return This->Draw(VertexCount, StartVertexLocation);
    }

    virtual HRESULT STDMETHODCALLTYPE Map(
        _In_  ID3D11Resource* pResource,
        _In_  UINT Subresource,
        _In_  D3D11_MAP MapType,
        _In_  UINT MapFlags,
        _Out_opt_  D3D11_MAPPED_SUBRESOURCE* pMappedResource)
    {
        return This->Map(pResource, Subresource, MapType, MapFlags, pMappedResource);
    }

    virtual void STDMETHODCALLTYPE Unmap(
        _In_  ID3D11Resource* pResource,
        _In_  UINT Subresource)
    {
        return This->Unmap(pResource, Subresource);
    }

    virtual void STDMETHODCALLTYPE PSSetConstantBuffers(
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
        _In_reads_opt_(NumBuffers)  ID3D11Buffer* const* ppConstantBuffers)
    {
        return This->PSSetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
    }

    virtual void STDMETHODCALLTYPE IASetInputLayout(
        _In_opt_  ID3D11InputLayout* pInputLayout)
    {
        return This->IASetInputLayout(pInputLayout);
    }

    virtual void STDMETHODCALLTYPE IASetVertexBuffers(
        _In_range_(0, D3D11_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT - StartSlot)  UINT NumBuffers,
        _In_reads_opt_(NumBuffers)  ID3D11Buffer* const* ppVertexBuffers,
        _In_reads_opt_(NumBuffers)  const UINT* pStrides,
        _In_reads_opt_(NumBuffers)  const UINT* pOffsets)
    {
        return This->IASetVertexBuffers(StartSlot, NumBuffers, ppVertexBuffers, pStrides, pOffsets);
    }

    virtual void STDMETHODCALLTYPE IASetIndexBuffer(
        _In_opt_  ID3D11Buffer* pIndexBuffer,
        _In_  DXGI_FORMAT Format,
        _In_  UINT Offset)
    {
        return This->IASetIndexBuffer(pIndexBuffer, Format, Offset);
    }

    virtual void STDMETHODCALLTYPE DrawIndexedInstanced(
        _In_  UINT IndexCountPerInstance,
        _In_  UINT InstanceCount,
        _In_  UINT StartIndexLocation,
        _In_  INT BaseVertexLocation,
        _In_  UINT StartInstanceLocation)
    {
        return This->DrawIndexedInstanced(IndexCountPerInstance, InstanceCount, StartIndexLocation, BaseVertexLocation, StartInstanceLocation);
    }

    virtual void STDMETHODCALLTYPE DrawInstanced(
        _In_  UINT VertexCountPerInstance,
        _In_  UINT InstanceCount,
        _In_  UINT StartVertexLocation,
        _In_  UINT StartInstanceLocation)
    {
        return This->DrawInstanced(VertexCountPerInstance, InstanceCount, StartVertexLocation, StartInstanceLocation);
    }

    virtual void STDMETHODCALLTYPE GSSetConstantBuffers(
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
        _In_reads_opt_(NumBuffers)  ID3D11Buffer* const* ppConstantBuffers)
    {
        return This->GSSetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
    }

    virtual void STDMETHODCALLTYPE GSSetShader(
        _In_opt_  ID3D11GeometryShader* pShader,
        _In_reads_opt_(NumClassInstances)  ID3D11ClassInstance* const* ppClassInstances,
        UINT NumClassInstances)
    {
        return This->GSSetShader(pShader, ppClassInstances, NumClassInstances);
    }

    virtual void STDMETHODCALLTYPE IASetPrimitiveTopology(
        _In_  D3D11_PRIMITIVE_TOPOLOGY Topology)
    {
        return This->IASetPrimitiveTopology(Topology);
    }

    virtual void STDMETHODCALLTYPE VSSetShaderResources(
        _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot)  UINT NumViews,
        _In_reads_opt_(NumViews)  ID3D11ShaderResourceView* const* ppShaderResourceViews)
    {
        return This->VSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
    }

    virtual void STDMETHODCALLTYPE VSSetSamplers(
        _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot)  UINT NumSamplers,
        _In_reads_opt_(NumSamplers)  ID3D11SamplerState* const* ppSamplers)
    {
        return This->VSSetSamplers(StartSlot, NumSamplers, ppSamplers);
    }

    virtual void STDMETHODCALLTYPE Begin(
        _In_  ID3D11Asynchronous* pAsync)
    {
        return This->Begin(pAsync);
    }

    virtual void STDMETHODCALLTYPE End(
        _In_  ID3D11Asynchronous* pAsync)
    {
        return This->End(pAsync);
    }

    virtual HRESULT STDMETHODCALLTYPE GetData(
        _In_  ID3D11Asynchronous* pAsync,
        _Out_writes_bytes_opt_(DataSize)  void* pData,
        _In_  UINT DataSize,
        _In_  UINT GetDataFlags)
    {
        return This->GetData(pAsync, pData, DataSize, GetDataFlags);
    }

    virtual void STDMETHODCALLTYPE SetPredication(
        _In_opt_  ID3D11Predicate* pPredicate,
        _In_  BOOL PredicateValue)
    {
        return This->SetPredication(pPredicate, PredicateValue);
    }

    virtual void STDMETHODCALLTYPE GSSetShaderResources(
        _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot)  UINT NumViews,
        _In_reads_opt_(NumViews)  ID3D11ShaderResourceView* const* ppShaderResourceViews)
    {
        return This->GSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
    }

    virtual void STDMETHODCALLTYPE GSSetSamplers(
        _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot)  UINT NumSamplers,
        _In_reads_opt_(NumSamplers)  ID3D11SamplerState* const* ppSamplers)
    {
        return This->GSSetSamplers(StartSlot, NumSamplers, ppSamplers);
    }

    virtual void STDMETHODCALLTYPE OMSetRenderTargets(
        _In_range_(0, D3D11_SIMULTANEOUS_RENDER_TARGET_COUNT)  UINT NumViews,
        _In_reads_opt_(NumViews)  ID3D11RenderTargetView* const* ppRenderTargetViews,
        _In_opt_  ID3D11DepthStencilView* pDepthStencilView)
    {
        return This->OMSetRenderTargets(NumViews, ppRenderTargetViews, pDepthStencilView);
    }

    virtual void STDMETHODCALLTYPE OMSetRenderTargetsAndUnorderedAccessViews(
        _In_  UINT NumRTVs,
        _In_reads_opt_(NumRTVs)  ID3D11RenderTargetView* const* ppRenderTargetViews,
        _In_opt_  ID3D11DepthStencilView* pDepthStencilView,
        _In_range_(0, D3D11_1_UAV_SLOT_COUNT - 1)  UINT UAVStartSlot,
        _In_  UINT NumUAVs,
        _In_reads_opt_(NumUAVs)  ID3D11UnorderedAccessView* const* ppUnorderedAccessViews,
        _In_reads_opt_(NumUAVs)  const UINT* pUAVInitialCounts)
    {
        return This->OMSetRenderTargetsAndUnorderedAccessViews(NumRTVs, ppRenderTargetViews,
            pDepthStencilView, UAVStartSlot, NumUAVs, ppUnorderedAccessViews, pUAVInitialCounts);
    }

    virtual void STDMETHODCALLTYPE OMSetBlendState(
        _In_opt_  ID3D11BlendState* pBlendState,
        _In_opt_  const FLOAT BlendFactor[4],
        _In_  UINT SampleMask)
    {
        return This->OMSetBlendState(pBlendState, BlendFactor, SampleMask);
    }

    virtual void STDMETHODCALLTYPE OMSetDepthStencilState(
        _In_opt_  ID3D11DepthStencilState* pDepthStencilState,
        _In_  UINT StencilRef)
    {
        return This->OMSetDepthStencilState(pDepthStencilState, StencilRef);
    }

    virtual void STDMETHODCALLTYPE SOSetTargets(
        _In_range_(0, D3D11_SO_BUFFER_SLOT_COUNT)  UINT NumBuffers,
        _In_reads_opt_(NumBuffers)  ID3D11Buffer* const* ppSOTargets,
        _In_reads_opt_(NumBuffers)  const UINT* pOffsets)
    {
        return This->SOSetTargets(NumBuffers, ppSOTargets, pOffsets);
    }

    virtual void STDMETHODCALLTYPE DrawAuto(void)
    {
        return This->DrawAuto();
    }

    virtual void STDMETHODCALLTYPE DrawIndexedInstancedIndirect(
        _In_  ID3D11Buffer* pBufferForArgs,
        _In_  UINT AlignedByteOffsetForArgs)
    {
        return This->DrawIndexedInstancedIndirect(pBufferForArgs, AlignedByteOffsetForArgs);
    }

    virtual void STDMETHODCALLTYPE DrawInstancedIndirect(
        _In_  ID3D11Buffer* pBufferForArgs,
        _In_  UINT AlignedByteOffsetForArgs)
    {
        return This->DrawInstancedIndirect(pBufferForArgs, AlignedByteOffsetForArgs);
    }

    virtual void STDMETHODCALLTYPE Dispatch(
        _In_  UINT ThreadGroupCountX,
        _In_  UINT ThreadGroupCountY,
        _In_  UINT ThreadGroupCountZ)
    {
        return This->Dispatch(ThreadGroupCountX, ThreadGroupCountY, ThreadGroupCountZ);
    }

    virtual void STDMETHODCALLTYPE DispatchIndirect(
        _In_  ID3D11Buffer* pBufferForArgs,
        _In_  UINT AlignedByteOffsetForArgs)
    {
        return This->DispatchIndirect(pBufferForArgs, AlignedByteOffsetForArgs);
    }

    virtual void STDMETHODCALLTYPE RSSetState(
        _In_opt_  ID3D11RasterizerState* pRasterizerState)
    {
        return This->RSSetState(pRasterizerState);
    }

    virtual void STDMETHODCALLTYPE RSSetViewports(
        _In_range_(0, D3D11_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE)  UINT NumViewports,
        _In_reads_opt_(NumViewports)  const D3D11_VIEWPORT* pViewports)
    {
        return This->RSSetViewports(NumViewports, pViewports);
    }

    virtual void STDMETHODCALLTYPE RSSetScissorRects(
        _In_range_(0, D3D11_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE)  UINT NumRects,
        _In_reads_opt_(NumRects)  const D3D11_RECT* pRects)
    {
        return This->RSSetScissorRects(NumRects, pRects);
    }

    virtual void STDMETHODCALLTYPE CopySubresourceRegion(
        _In_  ID3D11Resource* pDstResource,
        _In_  UINT DstSubresource,
        _In_  UINT DstX,
        _In_  UINT DstY,
        _In_  UINT DstZ,
        _In_  ID3D11Resource* pSrcResource,
        _In_  UINT SrcSubresource,
        _In_opt_  const D3D11_BOX* pSrcBox)
    {
        return This->CopySubresourceRegion(pDstResource, DstSubresource, DstX, DstY, DstZ, pSrcResource, SrcSubresource, pSrcBox);
    }

    virtual void STDMETHODCALLTYPE CopyResource(
        _In_  ID3D11Resource* pDstResource,
        _In_  ID3D11Resource* pSrcResource)
    {
        return This->CopyResource(pDstResource, pSrcResource);
    }

    virtual void STDMETHODCALLTYPE UpdateSubresource(
        _In_  ID3D11Resource* pDstResource,
        _In_  UINT DstSubresource,
        _In_opt_  const D3D11_BOX* pDstBox,
        _In_  const void* pSrcData,
        _In_  UINT SrcRowPitch,
        _In_  UINT SrcDepthPitch)
    {
        return This->UpdateSubresource(pDstResource, DstSubresource, pDstBox, pSrcData, SrcRowPitch, SrcDepthPitch);
    }

    virtual void STDMETHODCALLTYPE CopyStructureCount(
        _In_  ID3D11Buffer* pDstBuffer,
        _In_  UINT DstAlignedByteOffset,
        _In_  ID3D11UnorderedAccessView* pSrcView)
    {
        return This->CopyStructureCount(pDstBuffer, DstAlignedByteOffset, pSrcView);
    }

    virtual void STDMETHODCALLTYPE ClearRenderTargetView(
        _In_  ID3D11RenderTargetView* pRenderTargetView,
        _In_  const FLOAT ColorRGBA[4])
    {
        return This->ClearRenderTargetView(pRenderTargetView, ColorRGBA);
    }

    virtual void STDMETHODCALLTYPE ClearUnorderedAccessViewUint(
        _In_  ID3D11UnorderedAccessView* pUnorderedAccessView,
        _In_  const UINT Values[4])
    {
        return This->ClearUnorderedAccessViewUint(pUnorderedAccessView, Values);
    }

    virtual void STDMETHODCALLTYPE ClearUnorderedAccessViewFloat(
        _In_  ID3D11UnorderedAccessView* pUnorderedAccessView,
        _In_  const FLOAT Values[4])
    {
        return This->ClearUnorderedAccessViewFloat(pUnorderedAccessView, Values);
    }

    virtual void STDMETHODCALLTYPE ClearDepthStencilView(
        _In_  ID3D11DepthStencilView* pDepthStencilView,
        _In_  UINT ClearFlags,
        _In_  FLOAT Depth,
        _In_  UINT8 Stencil)
    {
        return This->ClearDepthStencilView(pDepthStencilView, ClearFlags, Depth, Stencil);
    }

    virtual void STDMETHODCALLTYPE GenerateMips(
        _In_  ID3D11ShaderResourceView* pShaderResourceView)
    {
        return This->GenerateMips(pShaderResourceView);
    }

    virtual void STDMETHODCALLTYPE SetResourceMinLOD(
        _In_  ID3D11Resource* pResource,
        FLOAT MinLOD)
    {
        return This->SetResourceMinLOD(pResource, MinLOD);
    }

    virtual FLOAT STDMETHODCALLTYPE GetResourceMinLOD(
        _In_  ID3D11Resource* pResource)
    {
        return This->GetResourceMinLOD(pResource);
    }

    virtual void STDMETHODCALLTYPE ResolveSubresource(
        _In_  ID3D11Resource* pDstResource,
        _In_  UINT DstSubresource,
        _In_  ID3D11Resource* pSrcResource,
        _In_  UINT SrcSubresource,
        _In_  DXGI_FORMAT Format)
    {
        return This->ResolveSubresource(pDstResource, DstSubresource, pSrcResource, SrcSubresource, Format);
    }

    virtual void STDMETHODCALLTYPE ExecuteCommandList(
        _In_  ID3D11CommandList* pCommandList,
        BOOL RestoreContextState)
    {
        return This->ExecuteCommandList(pCommandList, RestoreContextState);
    }

    virtual void STDMETHODCALLTYPE HSSetShaderResources(
        _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot)  UINT NumViews,
        _In_reads_opt_(NumViews)  ID3D11ShaderResourceView* const* ppShaderResourceViews)
    {
        return This->HSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
    }

    virtual void STDMETHODCALLTYPE HSSetShader(
        _In_opt_  ID3D11HullShader* pHullShader,
        _In_reads_opt_(NumClassInstances)  ID3D11ClassInstance* const* ppClassInstances,
        UINT NumClassInstances)
    {
        return This->HSSetShader(pHullShader, ppClassInstances, NumClassInstances);
    }

    virtual void STDMETHODCALLTYPE HSSetSamplers(
        _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot)  UINT NumSamplers,
        _In_reads_opt_(NumSamplers)  ID3D11SamplerState* const* ppSamplers)
    {
        return This->HSSetSamplers(StartSlot, NumSamplers, ppSamplers);
    }

    virtual void STDMETHODCALLTYPE HSSetConstantBuffers(
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
        _In_reads_opt_(NumBuffers)  ID3D11Buffer* const* ppConstantBuffers)
    {
        return This->HSSetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
    }

    virtual void STDMETHODCALLTYPE DSSetShaderResources(
        _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot)  UINT NumViews,
        _In_reads_opt_(NumViews)  ID3D11ShaderResourceView* const* ppShaderResourceViews)
    {
        return This->DSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
    }

    virtual void STDMETHODCALLTYPE DSSetShader(
        _In_opt_  ID3D11DomainShader* pDomainShader,
        _In_reads_opt_(NumClassInstances)  ID3D11ClassInstance* const* ppClassInstances,
        UINT NumClassInstances)
    {
        return This->DSSetShader(pDomainShader, ppClassInstances, NumClassInstances);
    }

    virtual void STDMETHODCALLTYPE DSSetSamplers(
        _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot)  UINT NumSamplers,
        _In_reads_opt_(NumSamplers)  ID3D11SamplerState* const* ppSamplers)
    {
        return This->DSSetSamplers(StartSlot, NumSamplers, ppSamplers);
    }

    virtual void STDMETHODCALLTYPE DSSetConstantBuffers(
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
        _In_reads_opt_(NumBuffers)  ID3D11Buffer* const* ppConstantBuffers)
    {
        return This->DSSetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
    }

    virtual void STDMETHODCALLTYPE CSSetShaderResources(
        _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot)  UINT NumViews,
        _In_reads_opt_(NumViews)  ID3D11ShaderResourceView* const* ppShaderResourceViews)
    {
        return This->CSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
    }

    virtual void STDMETHODCALLTYPE CSSetUnorderedAccessViews(
        _In_range_(0, D3D11_1_UAV_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_1_UAV_SLOT_COUNT - StartSlot)  UINT NumUAVs,
        _In_reads_opt_(NumUAVs)  ID3D11UnorderedAccessView* const* ppUnorderedAccessViews,
        _In_reads_opt_(NumUAVs)  const UINT* pUAVInitialCounts)
    {
        return This->CSSetUnorderedAccessViews(StartSlot, NumUAVs, ppUnorderedAccessViews, pUAVInitialCounts);
    }

    virtual void STDMETHODCALLTYPE CSSetShader(
        _In_opt_  ID3D11ComputeShader* pComputeShader,
        _In_reads_opt_(NumClassInstances)  ID3D11ClassInstance* const* ppClassInstances,
        UINT NumClassInstances)
    {
        return This->CSSetShader(pComputeShader, ppClassInstances, NumClassInstances);
    }

    virtual void STDMETHODCALLTYPE CSSetSamplers(
        _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot)  UINT NumSamplers,
        _In_reads_opt_(NumSamplers)  ID3D11SamplerState* const* ppSamplers)
    {
        return This->CSSetSamplers(StartSlot, NumSamplers, ppSamplers);
    }

    virtual void STDMETHODCALLTYPE CSSetConstantBuffers(
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
        _In_reads_opt_(NumBuffers)  ID3D11Buffer* const* ppConstantBuffers)
    {
        return This->CSSetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
    }

    virtual void STDMETHODCALLTYPE VSGetConstantBuffers(
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
        _Out_writes_opt_(NumBuffers)  ID3D11Buffer** ppConstantBuffers)
    {
        return This->VSGetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
    }

    virtual void STDMETHODCALLTYPE PSGetShaderResources(
        _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot)  UINT NumViews,
        _Out_writes_opt_(NumViews)  ID3D11ShaderResourceView** ppShaderResourceViews)
    {
        return This->PSGetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
    }

    virtual void STDMETHODCALLTYPE PSGetShader(
        _Outptr_result_maybenull_  ID3D11PixelShader** ppPixelShader,
        _Out_writes_opt_(*pNumClassInstances)  ID3D11ClassInstance** ppClassInstances,
        _Inout_opt_  UINT* pNumClassInstances)
    {
        return This->PSGetShader(ppPixelShader, ppClassInstances, pNumClassInstances);
    }

    virtual void STDMETHODCALLTYPE PSGetSamplers(
        _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot)  UINT NumSamplers,
        _Out_writes_opt_(NumSamplers)  ID3D11SamplerState** ppSamplers)
    {
        return This->PSGetSamplers(StartSlot, NumSamplers, ppSamplers);
    }

    virtual void STDMETHODCALLTYPE VSGetShader(
        _Outptr_result_maybenull_  ID3D11VertexShader** ppVertexShader,
        _Out_writes_opt_(*pNumClassInstances)  ID3D11ClassInstance** ppClassInstances,
        _Inout_opt_  UINT* pNumClassInstances)
    {
        return This->VSGetShader(ppVertexShader, ppClassInstances, pNumClassInstances);
    }

    virtual void STDMETHODCALLTYPE PSGetConstantBuffers(
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
        _Out_writes_opt_(NumBuffers)  ID3D11Buffer** ppConstantBuffers)
    {
        return This->PSGetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
    }

    virtual void STDMETHODCALLTYPE IAGetInputLayout(
        _Outptr_result_maybenull_  ID3D11InputLayout** ppInputLayout)
    {
        return This->IAGetInputLayout(ppInputLayout);
    }

    virtual void STDMETHODCALLTYPE IAGetVertexBuffers(
        _In_range_(0, D3D11_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT - StartSlot)  UINT NumBuffers,
        _Out_writes_opt_(NumBuffers)  ID3D11Buffer** ppVertexBuffers,
        _Out_writes_opt_(NumBuffers)  UINT* pStrides,
        _Out_writes_opt_(NumBuffers)  UINT* pOffsets)
    {
        return This->IAGetVertexBuffers(StartSlot, NumBuffers, ppVertexBuffers, pStrides, pOffsets);
    }

    virtual void STDMETHODCALLTYPE IAGetIndexBuffer(
        _Outptr_opt_result_maybenull_  ID3D11Buffer** pIndexBuffer,
        _Out_opt_  DXGI_FORMAT* Format,
        _Out_opt_  UINT* Offset)
    {
        return This->IAGetIndexBuffer(pIndexBuffer, Format, Offset);
    }

    virtual void STDMETHODCALLTYPE GSGetConstantBuffers(
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
        _Out_writes_opt_(NumBuffers)  ID3D11Buffer** ppConstantBuffers)
    {
        return This->GSGetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
    }

    virtual void STDMETHODCALLTYPE GSGetShader(
        _Outptr_result_maybenull_  ID3D11GeometryShader** ppGeometryShader,
        _Out_writes_opt_(*pNumClassInstances)  ID3D11ClassInstance** ppClassInstances,
        _Inout_opt_  UINT* pNumClassInstances)
    {
        return This->GSGetShader(ppGeometryShader, ppClassInstances, pNumClassInstances);
    }

    virtual void STDMETHODCALLTYPE IAGetPrimitiveTopology(
        _Out_  D3D11_PRIMITIVE_TOPOLOGY* pTopology)
    {
        return This->IAGetPrimitiveTopology(pTopology);
    }

    virtual void STDMETHODCALLTYPE VSGetShaderResources(
        _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot)  UINT NumViews,
        _Out_writes_opt_(NumViews)  ID3D11ShaderResourceView** ppShaderResourceViews)
    {
        return This->VSGetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
    }

    virtual void STDMETHODCALLTYPE VSGetSamplers(
        _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot)  UINT NumSamplers,
        _Out_writes_opt_(NumSamplers)  ID3D11SamplerState** ppSamplers)
    {
        return This->VSGetSamplers(StartSlot, NumSamplers, ppSamplers);
    }

    virtual void STDMETHODCALLTYPE GetPredication(
        _Outptr_opt_result_maybenull_  ID3D11Predicate** ppPredicate,
        _Out_opt_  BOOL* pPredicateValue)
    {
        return This->GetPredication(ppPredicate, pPredicateValue);
    }

    virtual void STDMETHODCALLTYPE GSGetShaderResources(
        _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot)  UINT NumViews,
        _Out_writes_opt_(NumViews)  ID3D11ShaderResourceView** ppShaderResourceViews)
    {
        return This->GSGetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
    }

    virtual void STDMETHODCALLTYPE GSGetSamplers(
        _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot)  UINT NumSamplers,
        _Out_writes_opt_(NumSamplers)  ID3D11SamplerState** ppSamplers)
    {
        return This->GSGetSamplers(StartSlot, NumSamplers, ppSamplers);
    }

    virtual void STDMETHODCALLTYPE OMGetRenderTargets(
        _In_range_(0, D3D11_SIMULTANEOUS_RENDER_TARGET_COUNT)  UINT NumViews,
        _Out_writes_opt_(NumViews)  ID3D11RenderTargetView** ppRenderTargetViews,
        _Outptr_opt_result_maybenull_  ID3D11DepthStencilView** ppDepthStencilView)
    {
        return This->OMGetRenderTargets(NumViews, ppRenderTargetViews, ppDepthStencilView);
    }

    virtual void STDMETHODCALLTYPE OMGetRenderTargetsAndUnorderedAccessViews(
        _In_range_(0, D3D11_SIMULTANEOUS_RENDER_TARGET_COUNT)  UINT NumRTVs,
        _Out_writes_opt_(NumRTVs)  ID3D11RenderTargetView** ppRenderTargetViews,
        _Outptr_opt_result_maybenull_  ID3D11DepthStencilView** ppDepthStencilView,
        _In_range_(0, D3D11_PS_CS_UAV_REGISTER_COUNT - 1)  UINT UAVStartSlot,
        _In_range_(0, D3D11_PS_CS_UAV_REGISTER_COUNT - UAVStartSlot)  UINT NumUAVs,
        _Out_writes_opt_(NumUAVs)  ID3D11UnorderedAccessView** ppUnorderedAccessViews)
    {
        return This->OMGetRenderTargetsAndUnorderedAccessViews(NumRTVs, ppRenderTargetViews,
            ppDepthStencilView, UAVStartSlot, NumUAVs, ppUnorderedAccessViews);
    }

    virtual void STDMETHODCALLTYPE OMGetBlendState(
        _Outptr_opt_result_maybenull_  ID3D11BlendState** ppBlendState,
        _Out_opt_  FLOAT BlendFactor[4],
        _Out_opt_  UINT* pSampleMask)
    {
        return This->OMGetBlendState(ppBlendState, BlendFactor, pSampleMask);
    }

    virtual void STDMETHODCALLTYPE OMGetDepthStencilState(
        _Outptr_opt_result_maybenull_  ID3D11DepthStencilState** ppDepthStencilState,
        _Out_opt_  UINT* pStencilRef)
    {
        return This->OMGetDepthStencilState(ppDepthStencilState, pStencilRef);
    }

    virtual void STDMETHODCALLTYPE SOGetTargets(
        _In_range_(0, D3D11_SO_BUFFER_SLOT_COUNT)  UINT NumBuffers,
        _Out_writes_opt_(NumBuffers)  ID3D11Buffer** ppSOTargets)
    {
        return This->SOGetTargets(NumBuffers, ppSOTargets);
    }

    virtual void STDMETHODCALLTYPE RSGetState(
        _Outptr_result_maybenull_  ID3D11RasterizerState** ppRasterizerState)
    {
        return This->RSGetState(ppRasterizerState);
    }

    virtual void STDMETHODCALLTYPE RSGetViewports(
        _Inout_ /*_range(0, D3D11_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE )*/   UINT* pNumViewports,
        _Out_writes_opt_(*pNumViewports)  D3D11_VIEWPORT* pViewports)
    {
        return This->RSGetViewports(pNumViewports, pViewports);
    }

    virtual void STDMETHODCALLTYPE RSGetScissorRects(
        _Inout_ /*_range(0, D3D11_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE )*/   UINT* pNumRects,
        _Out_writes_opt_(*pNumRects)  D3D11_RECT* pRects)
    {
        return This->RSGetScissorRects(pNumRects, pRects);
    }

    virtual void STDMETHODCALLTYPE HSGetShaderResources(
        _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot)  UINT NumViews,
        _Out_writes_opt_(NumViews)  ID3D11ShaderResourceView** ppShaderResourceViews)
    {
        return This->HSGetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
    }

    virtual void STDMETHODCALLTYPE HSGetShader(
        _Outptr_result_maybenull_  ID3D11HullShader** ppHullShader,
        _Out_writes_opt_(*pNumClassInstances)  ID3D11ClassInstance** ppClassInstances,
        _Inout_opt_  UINT* pNumClassInstances)
    {
        return This->HSGetShader(ppHullShader, ppClassInstances, pNumClassInstances);
    }

    virtual void STDMETHODCALLTYPE HSGetSamplers(
        _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot)  UINT NumSamplers,
        _Out_writes_opt_(NumSamplers)  ID3D11SamplerState** ppSamplers)
    {
        return This->HSGetSamplers(StartSlot, NumSamplers, ppSamplers);
    }

    virtual void STDMETHODCALLTYPE HSGetConstantBuffers(
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
        _Out_writes_opt_(NumBuffers)  ID3D11Buffer** ppConstantBuffers)
    {
        return This->HSGetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
    }

    virtual void STDMETHODCALLTYPE DSGetShaderResources(
        _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot)  UINT NumViews,
        _Out_writes_opt_(NumViews)  ID3D11ShaderResourceView** ppShaderResourceViews)
    {
        return This->DSGetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
    }

    virtual void STDMETHODCALLTYPE DSGetShader(
        _Outptr_result_maybenull_  ID3D11DomainShader** ppDomainShader,
        _Out_writes_opt_(*pNumClassInstances)  ID3D11ClassInstance** ppClassInstances,
        _Inout_opt_  UINT* pNumClassInstances)
    {
        return This->DSGetShader(ppDomainShader, ppClassInstances, pNumClassInstances);
    }

    virtual void STDMETHODCALLTYPE DSGetSamplers(
        _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot)  UINT NumSamplers,
        _Out_writes_opt_(NumSamplers)  ID3D11SamplerState** ppSamplers)
    {
        return This->DSGetSamplers(StartSlot, NumSamplers, ppSamplers);
    }

    virtual void STDMETHODCALLTYPE DSGetConstantBuffers(
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
        _Out_writes_opt_(NumBuffers)  ID3D11Buffer** ppConstantBuffers)
    {
        return This->DSGetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
    }

    virtual void STDMETHODCALLTYPE CSGetShaderResources(
        _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot)  UINT NumViews,
        _Out_writes_opt_(NumViews)  ID3D11ShaderResourceView** ppShaderResourceViews)
    {
        return This->CSGetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
    }

    virtual void STDMETHODCALLTYPE CSGetUnorderedAccessViews(
        _In_range_(0, D3D11_1_UAV_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_1_UAV_SLOT_COUNT - StartSlot)  UINT NumUAVs,
        _Out_writes_opt_(NumUAVs)  ID3D11UnorderedAccessView** ppUnorderedAccessViews)
    {
        return This->CSGetUnorderedAccessViews(StartSlot, NumUAVs, ppUnorderedAccessViews);
    }

    virtual void STDMETHODCALLTYPE CSGetShader(
        _Outptr_result_maybenull_  ID3D11ComputeShader** ppComputeShader,
        _Out_writes_opt_(*pNumClassInstances)  ID3D11ClassInstance** ppClassInstances,
        _Inout_opt_  UINT* pNumClassInstances)
    {
        return This->CSGetShader(ppComputeShader, ppClassInstances, pNumClassInstances);
    }

    virtual void STDMETHODCALLTYPE CSGetSamplers(
        _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot)  UINT NumSamplers,
        _Out_writes_opt_(NumSamplers)  ID3D11SamplerState** ppSamplers)
    {
        return This->CSGetSamplers(StartSlot, NumSamplers, ppSamplers);
    }

    virtual void STDMETHODCALLTYPE CSGetConstantBuffers(
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
        _Out_writes_opt_(NumBuffers)  ID3D11Buffer** ppConstantBuffers)
    {
        return This->CSGetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
    }

    virtual void STDMETHODCALLTYPE ClearState(void)
    {
        return This->ClearState();
    }

    virtual void STDMETHODCALLTYPE Flush(void)
    {
        return This->Flush();
    }

    virtual D3D11_DEVICE_CONTEXT_TYPE STDMETHODCALLTYPE GetType(void)
    {
        return This->GetType();
    }

    virtual UINT STDMETHODCALLTYPE GetContextFlags(void)
    {
        return This->GetContextFlags();
    }

    virtual HRESULT STDMETHODCALLTYPE FinishCommandList(
        BOOL RestoreDeferredContextState,
        _COM_Outptr_opt_  ID3D11CommandList** ppCommandList)
    {
        return This->FinishCommandList(RestoreDeferredContextState, ppCommandList);
    }

    #pragma endregion

    #pragma region ID3D11DeviceContext1 Implementation

    virtual void STDMETHODCALLTYPE CopySubresourceRegion1(
        _In_  ID3D11Resource* pDstResource,
        _In_  UINT DstSubresource,
        _In_  UINT DstX,
        _In_  UINT DstY,
        _In_  UINT DstZ,
        _In_  ID3D11Resource* pSrcResource,
        _In_  UINT SrcSubresource,
        _In_opt_  const D3D11_BOX* pSrcBox,
        _In_  UINT CopyFlags)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
    }

    virtual void STDMETHODCALLTYPE UpdateSubresource1(
        _In_  ID3D11Resource* pDstResource,
        _In_  UINT DstSubresource,
        _In_opt_  const D3D11_BOX* pDstBox,
        _In_  const void* pSrcData,
        _In_  UINT SrcRowPitch,
        _In_  UINT SrcDepthPitch,
        _In_  UINT CopyFlags)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
    }

    virtual void STDMETHODCALLTYPE DiscardResource(
        _In_  ID3D11Resource* pResource)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
    }

    virtual void STDMETHODCALLTYPE DiscardView(
        _In_  ID3D11View* pResourceView)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
    }

    virtual void STDMETHODCALLTYPE VSSetConstantBuffers1(
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
        _In_reads_opt_(NumBuffers)  ID3D11Buffer* const* ppConstantBuffers,
        _In_reads_opt_(NumBuffers)  const UINT* pFirstConstant,
        _In_reads_opt_(NumBuffers)  const UINT* pNumConstants)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
    }

    virtual void STDMETHODCALLTYPE HSSetConstantBuffers1(
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
        _In_reads_opt_(NumBuffers)  ID3D11Buffer* const* ppConstantBuffers,
        _In_reads_opt_(NumBuffers)  const UINT* pFirstConstant,
        _In_reads_opt_(NumBuffers)  const UINT* pNumConstants)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
    }

    virtual void STDMETHODCALLTYPE DSSetConstantBuffers1(
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
        _In_reads_opt_(NumBuffers)  ID3D11Buffer* const* ppConstantBuffers,
        _In_reads_opt_(NumBuffers)  const UINT* pFirstConstant,
        _In_reads_opt_(NumBuffers)  const UINT* pNumConstants)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
    }

    virtual void STDMETHODCALLTYPE GSSetConstantBuffers1(
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
        _In_reads_opt_(NumBuffers)  ID3D11Buffer* const* ppConstantBuffers,
        _In_reads_opt_(NumBuffers)  const UINT* pFirstConstant,
        _In_reads_opt_(NumBuffers)  const UINT* pNumConstants)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
    }

    virtual void STDMETHODCALLTYPE PSSetConstantBuffers1(
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
        _In_reads_opt_(NumBuffers)  ID3D11Buffer* const* ppConstantBuffers,
        _In_reads_opt_(NumBuffers)  const UINT* pFirstConstant,
        _In_reads_opt_(NumBuffers)  const UINT* pNumConstants)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
    }

    virtual void STDMETHODCALLTYPE CSSetConstantBuffers1(
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
        _In_reads_opt_(NumBuffers)  ID3D11Buffer* const* ppConstantBuffers,
        _In_reads_opt_(NumBuffers)  const UINT* pFirstConstant,
        _In_reads_opt_(NumBuffers)  const UINT* pNumConstants)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
    }

    virtual void STDMETHODCALLTYPE VSGetConstantBuffers1(
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
        _Out_writes_opt_(NumBuffers)  ID3D11Buffer** ppConstantBuffers,
        _Out_writes_opt_(NumBuffers)  UINT* pFirstConstant,
        _Out_writes_opt_(NumBuffers)  UINT* pNumConstants)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
    }

    virtual void STDMETHODCALLTYPE HSGetConstantBuffers1(
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
        _Out_writes_opt_(NumBuffers)  ID3D11Buffer** ppConstantBuffers,
        _Out_writes_opt_(NumBuffers)  UINT* pFirstConstant,
        _Out_writes_opt_(NumBuffers)  UINT* pNumConstants)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
    }

    virtual void STDMETHODCALLTYPE DSGetConstantBuffers1(
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
        _Out_writes_opt_(NumBuffers)  ID3D11Buffer** ppConstantBuffers,
        _Out_writes_opt_(NumBuffers)  UINT* pFirstConstant,
        _Out_writes_opt_(NumBuffers)  UINT* pNumConstants)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
    }

    virtual void STDMETHODCALLTYPE GSGetConstantBuffers1(
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
        _Out_writes_opt_(NumBuffers)  ID3D11Buffer** ppConstantBuffers,
        _Out_writes_opt_(NumBuffers)  UINT* pFirstConstant,
        _Out_writes_opt_(NumBuffers)  UINT* pNumConstants)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
    }

    virtual void STDMETHODCALLTYPE PSGetConstantBuffers1(
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
        _Out_writes_opt_(NumBuffers)  ID3D11Buffer** ppConstantBuffers,
        _Out_writes_opt_(NumBuffers)  UINT* pFirstConstant,
        _Out_writes_opt_(NumBuffers)  UINT* pNumConstants)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
    }

    virtual void STDMETHODCALLTYPE CSGetConstantBuffers1(
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
        _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
        _Out_writes_opt_(NumBuffers)  ID3D11Buffer** ppConstantBuffers,
        _Out_writes_opt_(NumBuffers)  UINT* pFirstConstant,
        _Out_writes_opt_(NumBuffers)  UINT* pNumConstants)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
    }

    virtual void STDMETHODCALLTYPE SwapDeviceContextState(
        _In_  ID3DDeviceContextState* pState,
        _Outptr_opt_  ID3DDeviceContextState** ppPreviousState)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
    }

    virtual void STDMETHODCALLTYPE ClearView(
        _In_  ID3D11View* pView,
        _In_  const FLOAT Color[4],
        _In_reads_opt_(NumRects)  const D3D11_RECT* pRect,
        UINT NumRects)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
    }

    virtual void STDMETHODCALLTYPE DiscardView1(
        _In_  ID3D11View* pResourceView,
        _In_reads_opt_(NumRects)  const D3D11_RECT* pRects,
        UINT NumRects)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
    }

    #pragma endregion

    #pragma region ID3D11DeviceContext2 Implementation

    virtual HRESULT STDMETHODCALLTYPE UpdateTileMappings(
        _In_  ID3D11Resource* pTiledResource,
        _In_  UINT NumTiledResourceRegions,
        _In_reads_opt_(NumTiledResourceRegions)  const D3D11_TILED_RESOURCE_COORDINATE* pTiledResourceRegionStartCoordinates,
        _In_reads_opt_(NumTiledResourceRegions)  const D3D11_TILE_REGION_SIZE* pTiledResourceRegionSizes,
        _In_opt_  ID3D11Buffer* pTilePool,
        _In_  UINT NumRanges,
        _In_reads_opt_(NumRanges)  const UINT* pRangeFlags,
        _In_reads_opt_(NumRanges)  const UINT* pTilePoolStartOffsets,
        _In_reads_opt_(NumRanges)  const UINT* pRangeTileCounts,
        _In_  UINT Flags)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
        return E_NOTIMPL;
    }

    virtual HRESULT STDMETHODCALLTYPE CopyTileMappings(
        _In_  ID3D11Resource* pDestTiledResource,
        _In_  const D3D11_TILED_RESOURCE_COORDINATE* pDestRegionStartCoordinate,
        _In_  ID3D11Resource* pSourceTiledResource,
        _In_  const D3D11_TILED_RESOURCE_COORDINATE* pSourceRegionStartCoordinate,
        _In_  const D3D11_TILE_REGION_SIZE* pTileRegionSize,
        _In_  UINT Flags)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
        return E_NOTIMPL;
    }

    virtual void STDMETHODCALLTYPE CopyTiles(
        _In_  ID3D11Resource* pTiledResource,
        _In_  const D3D11_TILED_RESOURCE_COORDINATE* pTileRegionStartCoordinate,
        _In_  const D3D11_TILE_REGION_SIZE* pTileRegionSize,
        _In_  ID3D11Buffer* pBuffer,
        _In_  UINT64 BufferStartOffsetInBytes,
        _In_  UINT Flags)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
    }

    virtual void STDMETHODCALLTYPE UpdateTiles(
        _In_  ID3D11Resource* pDestTiledResource,
        _In_  const D3D11_TILED_RESOURCE_COORDINATE* pDestTileRegionStartCoordinate,
        _In_  const D3D11_TILE_REGION_SIZE* pDestTileRegionSize,
        _In_  const void* pSourceTileData,
        _In_  UINT Flags)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
    }

    virtual HRESULT STDMETHODCALLTYPE ResizeTilePool(
        _In_  ID3D11Buffer* pTilePool,
        _In_  UINT64 NewSizeInBytes)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
        return E_NOTIMPL;
    }

    virtual void STDMETHODCALLTYPE TiledResourceBarrier(
        _In_opt_  ID3D11DeviceChild* pTiledResourceOrViewAccessBeforeBarrier,
        _In_opt_  ID3D11DeviceChild* pTiledResourceOrViewAccessAfterBarrier)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
    }

    virtual BOOL STDMETHODCALLTYPE IsAnnotationEnabled(void)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
        return FALSE;
    }

    virtual void STDMETHODCALLTYPE SetMarkerInt(
        _In_  LPCWSTR pLabel,
        INT Data)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
    }

    virtual void STDMETHODCALLTYPE BeginEventInt(
        _In_  LPCWSTR pLabel,
        INT Data)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
    }

    virtual void STDMETHODCALLTYPE EndEvent(void)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
    }

    #pragma endregion

    #pragma region Context

    D3D11DeviceContext2Proxy(ID3D11DeviceContext* pThis)
    {
        This = pThis;
    }

    ID3D11DeviceContext* This;

    #pragma endregion
};

/// <summary>
/// IDXGIDevice3 > IDXGIDevice2 > IDXGIDevice1 > [IDXGIDevice] > IDXGIObject > IUnknown
/// </summary>
struct DXGIDevice3Proxy : public IDXGIDevice3
{

    #pragma region IUnknown Implementation

    virtual HRESULT STDMETHODCALLTYPE QueryInterface(
        REFIID riid,
        _COM_Outptr_ void __RPC_FAR* __RPC_FAR* ppvObject
    )
    {
        return This->QueryInterface(riid, ppvObject);
    }

    virtual ULONG STDMETHODCALLTYPE AddRef(void)
    {
        return This->AddRef();
    }

    virtual ULONG STDMETHODCALLTYPE Release(void)
    {
        return This->Release();
    }

    #pragma endregion

    #pragma region IDXGIObject Implementation

    virtual HRESULT STDMETHODCALLTYPE SetPrivateData(
        _In_  REFGUID Name,
        UINT DataSize,
        _In_reads_bytes_(DataSize)  const void* pData)
    {
        return This->SetPrivateData(Name, DataSize, pData);
    }

    virtual HRESULT STDMETHODCALLTYPE SetPrivateDataInterface(
        _In_  REFGUID Name,
        _In_opt_  const IUnknown* pUnknown)
    {
        return This->SetPrivateDataInterface(Name, pUnknown);
    }

    virtual HRESULT STDMETHODCALLTYPE GetPrivateData(
        _In_  REFGUID Name,
        _Inout_  UINT* pDataSize,
        _Out_writes_bytes_(*pDataSize)  void* pData)
    {
        return This->GetPrivateData(Name, pDataSize, pData);
    }

    virtual HRESULT STDMETHODCALLTYPE GetParent(
        _In_  REFIID riid,
        _COM_Outptr_  void** ppParent)
    {
        return This->GetParent(riid, ppParent);
    }

    #pragma endregion

    #pragma region IDXGIDevice Implementation

    virtual HRESULT STDMETHODCALLTYPE GetAdapter(
        _COM_Outptr_  IDXGIAdapter** pAdapter)
    {
        return This->GetAdapter(pAdapter);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateSurface(
        _In_  const DXGI_SURFACE_DESC* pDesc,
        UINT NumSurfaces,
        DXGI_USAGE Usage,
        _In_opt_  const DXGI_SHARED_RESOURCE* pSharedResource,
        _Out_writes_(NumSurfaces)  IDXGISurface** ppSurface)
    {
        return This->CreateSurface(pDesc, NumSurfaces, Usage, pSharedResource, ppSurface);
    }

    virtual HRESULT STDMETHODCALLTYPE QueryResourceResidency(
        _In_reads_(NumResources)  IUnknown* const* ppResources,
        _Out_writes_(NumResources)  DXGI_RESIDENCY* pResidencyStatus,
        UINT NumResources)
    {
        return This->QueryResourceResidency(ppResources, pResidencyStatus, NumResources);
    }

    virtual HRESULT STDMETHODCALLTYPE SetGPUThreadPriority(
        INT Priority)
    {
        return This->SetGPUThreadPriority(Priority);
    }

    virtual HRESULT STDMETHODCALLTYPE GetGPUThreadPriority(
        _Out_  INT* pPriority)
    {
        return This->GetGPUThreadPriority(pPriority);
    }

    #pragma endregion

    #pragma region IDXGIDevice1 Implementation

    virtual HRESULT STDMETHODCALLTYPE SetMaximumFrameLatency(
        UINT MaxLatency)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
        return S_OK;
    }

    virtual HRESULT STDMETHODCALLTYPE GetMaximumFrameLatency(
        _Out_  UINT* pMaxLatency)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
        return E_NOTIMPL;
    }

    #pragma endregion

    #pragma region IDXGIDevice2 Implementation

    virtual HRESULT STDMETHODCALLTYPE OfferResources(
        _In_  UINT NumResources,
        _In_reads_(NumResources)  IDXGIResource* const* ppResources,
        _In_  DXGI_OFFER_RESOURCE_PRIORITY Priority)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
        return E_NOTIMPL;
    }

    virtual HRESULT STDMETHODCALLTYPE ReclaimResources(
        _In_  UINT NumResources,
        _In_reads_(NumResources)  IDXGIResource* const* ppResources,
        _Out_writes_all_opt_(NumResources)  BOOL* pDiscarded)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
        return E_NOTIMPL;
    }

    virtual HRESULT STDMETHODCALLTYPE EnqueueSetEvent(
        _In_  HANDLE hEvent)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
        return E_NOTIMPL;
    }

    #pragma endregion

    #pragma region IDXGIDevice3 Implementation

    virtual void STDMETHODCALLTYPE Trim(void)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
    }

    #pragma endregion

    #pragma region Context

    DXGIDevice3Proxy(IDXGIDevice* pThis)
    {
        This = pThis;
    }

    IDXGIDevice* This;

    #pragma endregion
};

/// <summary>
/// ID3D11Device2 > ID3D11Device1 > [ID3D11Device] > IUnknown
/// </summary>
struct D3D11Device2Proxy : public ID3D11Device2
{
    // Hook IUnknown::QueryInterface

    #pragma region IUnknown Implementation

    virtual HRESULT STDMETHODCALLTYPE QueryInterface(
        REFIID riid,
        _COM_Outptr_ void __RPC_FAR* __RPC_FAR* ppvObject
    )
    {
        if (riid == __uuidof(ID3D11Device1) || riid == __uuidof(ID3D11Device2))
        {
            LogWrite(L"%s : Returns this proxy\n", __FUNCTIONW__);
            *ppvObject = this;
            return S_OK;
        }
        else if (riid == __uuidof(IDXGIDevice3))
        {
            HRESULT result = This->QueryInterface(riid, ppvObject);

            if (result == E_NOINTERFACE)
            {
                LogWrite(L"%s : Interface IDXGIDevice3 was not found, try to fall back to IDXGIDevice\n", __FUNCTIONW__);

                IDXGIDevice* pDXGIDevice;

                if (This->QueryInterface(__uuidof(IDXGIDevice), (void**)&pDXGIDevice) == S_OK)
                {
                    LogWrite(L"%s : Using IDXGIDevice\n", __FUNCTIONW__);

                    *ppvObject = new DXGIDevice3Proxy(pDXGIDevice);
                    return S_OK;
                }
            }
        }

        return This->QueryInterface(riid, ppvObject);
    }

    virtual ULONG STDMETHODCALLTYPE AddRef(void)
    {
        return This->AddRef();
    }

    virtual ULONG STDMETHODCALLTYPE Release(void)
    {
        return This->Release();
    }

    #pragma endregion

    #pragma region ID3D11Device Implementation

    virtual HRESULT STDMETHODCALLTYPE CreateBuffer(
        _In_  const D3D11_BUFFER_DESC* pDesc,
        _In_opt_  const D3D11_SUBRESOURCE_DATA* pInitialData,
        _COM_Outptr_opt_  ID3D11Buffer** ppBuffer)
    {
        return This->CreateBuffer(pDesc, pInitialData, ppBuffer);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateTexture1D(
        _In_  const D3D11_TEXTURE1D_DESC* pDesc,
        _In_reads_opt_(_Inexpressible_(pDesc->MipLevels* pDesc->ArraySize))  const D3D11_SUBRESOURCE_DATA* pInitialData,
        _COM_Outptr_opt_  ID3D11Texture1D** ppTexture1D)
    {
        return This->CreateTexture1D(pDesc, pInitialData, ppTexture1D);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateTexture2D(
        _In_  const D3D11_TEXTURE2D_DESC* pDesc,
        _In_reads_opt_(_Inexpressible_(pDesc->MipLevels* pDesc->ArraySize))  const D3D11_SUBRESOURCE_DATA* pInitialData,
        _COM_Outptr_opt_  ID3D11Texture2D** ppTexture2D)
    {
        return This->CreateTexture2D(pDesc, pInitialData, ppTexture2D);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateTexture3D(
        _In_  const D3D11_TEXTURE3D_DESC* pDesc,
        _In_reads_opt_(_Inexpressible_(pDesc->MipLevels))  const D3D11_SUBRESOURCE_DATA* pInitialData,
        _COM_Outptr_opt_  ID3D11Texture3D** ppTexture3D)
    {
        return This->CreateTexture3D(pDesc, pInitialData, ppTexture3D);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateShaderResourceView(
        _In_  ID3D11Resource* pResource,
        _In_opt_  const D3D11_SHADER_RESOURCE_VIEW_DESC* pDesc,
        _COM_Outptr_opt_  ID3D11ShaderResourceView** ppSRView)
    {
        return This->CreateShaderResourceView(pResource, pDesc, ppSRView);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateUnorderedAccessView(
        _In_  ID3D11Resource* pResource,
        _In_opt_  const D3D11_UNORDERED_ACCESS_VIEW_DESC* pDesc,
        _COM_Outptr_opt_  ID3D11UnorderedAccessView** ppUAView)
    {
        return This->CreateUnorderedAccessView(pResource, pDesc, ppUAView);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateRenderTargetView(
        _In_  ID3D11Resource* pResource,
        _In_opt_  const D3D11_RENDER_TARGET_VIEW_DESC* pDesc,
        _COM_Outptr_opt_  ID3D11RenderTargetView** ppRTView)
    {
        return This->CreateRenderTargetView(pResource, pDesc, ppRTView);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateDepthStencilView(
        _In_  ID3D11Resource* pResource,
        _In_opt_  const D3D11_DEPTH_STENCIL_VIEW_DESC* pDesc,
        _COM_Outptr_opt_  ID3D11DepthStencilView** ppDepthStencilView)
    {
        return This->CreateDepthStencilView(pResource, pDesc, ppDepthStencilView);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateInputLayout(
        _In_reads_(NumElements)  const D3D11_INPUT_ELEMENT_DESC* pInputElementDescs,
        _In_range_(0, D3D11_IA_VERTEX_INPUT_STRUCTURE_ELEMENT_COUNT)  UINT NumElements,
        _In_reads_(BytecodeLength)  const void* pShaderBytecodeWithInputSignature,
        _In_  SIZE_T BytecodeLength,
        _COM_Outptr_opt_  ID3D11InputLayout** ppInputLayout)
    {
        return This->CreateInputLayout(pInputElementDescs, NumElements,
            pShaderBytecodeWithInputSignature, BytecodeLength, ppInputLayout);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateVertexShader(
        _In_reads_(BytecodeLength)  const void* pShaderBytecode,
        _In_  SIZE_T BytecodeLength,
        _In_opt_  ID3D11ClassLinkage* pClassLinkage,
        _COM_Outptr_opt_  ID3D11VertexShader** ppVertexShader)
    {
        return This->CreateVertexShader(pShaderBytecode, BytecodeLength, pClassLinkage, ppVertexShader);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateGeometryShader(
        _In_reads_(BytecodeLength)  const void* pShaderBytecode,
        _In_  SIZE_T BytecodeLength,
        _In_opt_  ID3D11ClassLinkage* pClassLinkage,
        _COM_Outptr_opt_  ID3D11GeometryShader** ppGeometryShader)
    {
        return This->CreateGeometryShader(pShaderBytecode, BytecodeLength, pClassLinkage, ppGeometryShader);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateGeometryShaderWithStreamOutput(
        _In_reads_(BytecodeLength)  const void* pShaderBytecode,
        _In_  SIZE_T BytecodeLength,
        _In_reads_opt_(NumEntries)  const D3D11_SO_DECLARATION_ENTRY* pSODeclaration,
        _In_range_(0, D3D11_SO_STREAM_COUNT* D3D11_SO_OUTPUT_COMPONENT_COUNT)  UINT NumEntries,
        _In_reads_opt_(NumStrides)  const UINT* pBufferStrides,
        _In_range_(0, D3D11_SO_BUFFER_SLOT_COUNT)  UINT NumStrides,
        _In_  UINT RasterizedStream,
        _In_opt_  ID3D11ClassLinkage* pClassLinkage,
        _COM_Outptr_opt_  ID3D11GeometryShader** ppGeometryShader)
    {
        return This->CreateGeometryShaderWithStreamOutput(pShaderBytecode, BytecodeLength, pSODeclaration,
            NumEntries, pBufferStrides, NumStrides, RasterizedStream, pClassLinkage, ppGeometryShader);
    }

    virtual HRESULT STDMETHODCALLTYPE CreatePixelShader(
        _In_reads_(BytecodeLength)  const void* pShaderBytecode,
        _In_  SIZE_T BytecodeLength,
        _In_opt_  ID3D11ClassLinkage* pClassLinkage,
        _COM_Outptr_opt_  ID3D11PixelShader** ppPixelShader)
    {
        return This->CreatePixelShader(pShaderBytecode, BytecodeLength, pClassLinkage, ppPixelShader);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateHullShader(
        _In_reads_(BytecodeLength)  const void* pShaderBytecode,
        _In_  SIZE_T BytecodeLength,
        _In_opt_  ID3D11ClassLinkage* pClassLinkage,
        _COM_Outptr_opt_  ID3D11HullShader** ppHullShader)
    {
        return This->CreateHullShader(pShaderBytecode, BytecodeLength, pClassLinkage, ppHullShader);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateDomainShader(
        _In_reads_(BytecodeLength)  const void* pShaderBytecode,
        _In_  SIZE_T BytecodeLength,
        _In_opt_  ID3D11ClassLinkage* pClassLinkage,
        _COM_Outptr_opt_  ID3D11DomainShader** ppDomainShader)
    {
        return This->CreateDomainShader(pShaderBytecode, BytecodeLength, pClassLinkage, ppDomainShader);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateComputeShader(
        _In_reads_(BytecodeLength)  const void* pShaderBytecode,
        _In_  SIZE_T BytecodeLength,
        _In_opt_  ID3D11ClassLinkage* pClassLinkage,
        _COM_Outptr_opt_  ID3D11ComputeShader** ppComputeShader)
    {
        return This->CreateComputeShader(pShaderBytecode, BytecodeLength, pClassLinkage, ppComputeShader);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateClassLinkage(
        _COM_Outptr_  ID3D11ClassLinkage** ppLinkage)
    {
        return This->CreateClassLinkage(ppLinkage);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateBlendState(
        _In_  const D3D11_BLEND_DESC* pBlendStateDesc,
        _COM_Outptr_opt_  ID3D11BlendState** ppBlendState)
    {
        return This->CreateBlendState(pBlendStateDesc, ppBlendState);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateDepthStencilState(
        _In_  const D3D11_DEPTH_STENCIL_DESC* pDepthStencilDesc,
        _COM_Outptr_opt_  ID3D11DepthStencilState** ppDepthStencilState)
    {
        return This->CreateDepthStencilState(pDepthStencilDesc, ppDepthStencilState);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateRasterizerState(
        _In_  const D3D11_RASTERIZER_DESC* pRasterizerDesc,
        _COM_Outptr_opt_  ID3D11RasterizerState** ppRasterizerState)
    {
        return This->CreateRasterizerState(pRasterizerDesc, ppRasterizerState);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateSamplerState(
        _In_  const D3D11_SAMPLER_DESC* pSamplerDesc,
        _COM_Outptr_opt_  ID3D11SamplerState** ppSamplerState)
    {
        return This->CreateSamplerState(pSamplerDesc, ppSamplerState);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateQuery(
        _In_  const D3D11_QUERY_DESC* pQueryDesc,
        _COM_Outptr_opt_  ID3D11Query** ppQuery)
    {
        return This->CreateQuery(pQueryDesc, ppQuery);
    }

    virtual HRESULT STDMETHODCALLTYPE CreatePredicate(
        _In_  const D3D11_QUERY_DESC* pPredicateDesc,
        _COM_Outptr_opt_  ID3D11Predicate** ppPredicate)
    {
        return This->CreatePredicate(pPredicateDesc, ppPredicate);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateCounter(
        _In_  const D3D11_COUNTER_DESC* pCounterDesc,
        _COM_Outptr_opt_  ID3D11Counter** ppCounter)
    {
        return This->CreateCounter(pCounterDesc, ppCounter);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateDeferredContext(
        UINT ContextFlags,
        _COM_Outptr_opt_  ID3D11DeviceContext** ppDeferredContext)
    {
        return This->CreateDeferredContext(ContextFlags, ppDeferredContext);
    }

    virtual HRESULT STDMETHODCALLTYPE OpenSharedResource(
        _In_  HANDLE hResource,
        _In_  REFIID ReturnedInterface,
        _COM_Outptr_opt_  void** ppResource)
    {
        return This->OpenSharedResource(hResource, ReturnedInterface, ppResource);
    }

    virtual HRESULT STDMETHODCALLTYPE CheckFormatSupport(
        _In_  DXGI_FORMAT Format,
        _Out_  UINT* pFormatSupport)
    {
        return This->CheckFormatSupport(Format, pFormatSupport);
    }

    virtual HRESULT STDMETHODCALLTYPE CheckMultisampleQualityLevels(
        _In_  DXGI_FORMAT Format,
        _In_  UINT SampleCount,
        _Out_  UINT* pNumQualityLevels)
    {
        return This->CheckMultisampleQualityLevels(Format, SampleCount, pNumQualityLevels);
    }

    virtual void STDMETHODCALLTYPE CheckCounterInfo(
        _Out_  D3D11_COUNTER_INFO* pCounterInfo)
    {
        return This->CheckCounterInfo(pCounterInfo);
    }

    virtual HRESULT STDMETHODCALLTYPE CheckCounter(
        _In_  const D3D11_COUNTER_DESC* pDesc,
        _Out_  D3D11_COUNTER_TYPE* pType,
        _Out_  UINT* pActiveCounters,
        _Out_writes_opt_(*pNameLength)  LPSTR szName,
        _Inout_opt_  UINT* pNameLength,
        _Out_writes_opt_(*pUnitsLength)  LPSTR szUnits,
        _Inout_opt_  UINT* pUnitsLength,
        _Out_writes_opt_(*pDescriptionLength)  LPSTR szDescription,
        _Inout_opt_  UINT* pDescriptionLength)
    {
        return This->CheckCounter(pDesc, pType, pActiveCounters, szName, pNameLength,
            szUnits, pUnitsLength, szDescription, pDescriptionLength);
    }

    virtual HRESULT STDMETHODCALLTYPE CheckFeatureSupport(
        D3D11_FEATURE Feature,
        _Out_writes_bytes_(FeatureSupportDataSize)  void* pFeatureSupportData,
        UINT FeatureSupportDataSize)
    {
        return This->CheckFeatureSupport(Feature, pFeatureSupportData, FeatureSupportDataSize);
    }

    virtual HRESULT STDMETHODCALLTYPE GetPrivateData(
        _In_  REFGUID guid,
        _Inout_  UINT* pDataSize,
        _Out_writes_bytes_opt_(*pDataSize)  void* pData)
    {
        return This->GetPrivateData(guid, pDataSize, pData);
    }

    virtual HRESULT STDMETHODCALLTYPE SetPrivateData(
        _In_  REFGUID guid,
        _In_  UINT DataSize,
        _In_reads_bytes_opt_(DataSize)  const void* pData)
    {
        return This->SetPrivateData(guid, DataSize, pData);
    }

    virtual HRESULT STDMETHODCALLTYPE SetPrivateDataInterface(
        _In_  REFGUID guid,
        _In_opt_  const IUnknown* pData)
    {
        return This->SetPrivateDataInterface(guid, pData);
    }

    virtual D3D_FEATURE_LEVEL STDMETHODCALLTYPE GetFeatureLevel(void)
    {
        return This->GetFeatureLevel();
    }

    virtual UINT STDMETHODCALLTYPE GetCreationFlags(void)
    {
        return This->GetCreationFlags();
    }

    virtual HRESULT STDMETHODCALLTYPE GetDeviceRemovedReason(void)
    {
        return This->GetDeviceRemovedReason();
    }

    virtual void STDMETHODCALLTYPE GetImmediateContext(
        _Outptr_  ID3D11DeviceContext** ppImmediateContext)
    {
        return This->GetImmediateContext(ppImmediateContext);
    }

    virtual HRESULT STDMETHODCALLTYPE SetExceptionMode(
        UINT RaiseFlags)
    {
        return This->SetExceptionMode(RaiseFlags);
    }

    virtual UINT STDMETHODCALLTYPE GetExceptionMode(void)
    {
        return This->GetExceptionMode();
    }

    #pragma endregion

    #pragma region ID3D11Device1 Implementation

    virtual void STDMETHODCALLTYPE GetImmediateContext1(
        _Outptr_  ID3D11DeviceContext1** ppImmediateContext)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateDeferredContext1(
        UINT ContextFlags,
        _COM_Outptr_opt_  ID3D11DeviceContext1** ppDeferredContext)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
        return E_NOTIMPL;
    }

    virtual HRESULT STDMETHODCALLTYPE CreateBlendState1(
        _In_  const D3D11_BLEND_DESC1* pBlendStateDesc,
        _COM_Outptr_opt_  ID3D11BlendState1** ppBlendState)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
        return E_NOTIMPL;
    }

    virtual HRESULT STDMETHODCALLTYPE CreateRasterizerState1(
        _In_  const D3D11_RASTERIZER_DESC1* pRasterizerDesc,
        _COM_Outptr_opt_  ID3D11RasterizerState1** ppRasterizerState)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
        return E_NOTIMPL;
    }

    virtual HRESULT STDMETHODCALLTYPE CreateDeviceContextState(
        UINT Flags,
        _In_reads_(FeatureLevels)  const D3D_FEATURE_LEVEL* pFeatureLevels,
        UINT FeatureLevels,
        UINT SDKVersion,
        REFIID EmulatedInterface,
        _Out_opt_  D3D_FEATURE_LEVEL* pChosenFeatureLevel,
        _Out_opt_  ID3DDeviceContextState** ppContextState)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
        return E_NOTIMPL;
    }

    virtual HRESULT STDMETHODCALLTYPE OpenSharedResource1(
        _In_  HANDLE hResource,
        _In_  REFIID returnedInterface,
        _COM_Outptr_  void** ppResource)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
        return E_NOTIMPL;
    }

    virtual HRESULT STDMETHODCALLTYPE OpenSharedResourceByName(
        _In_  LPCWSTR lpName,
        _In_  DWORD dwDesiredAccess,
        _In_  REFIID returnedInterface,
        _COM_Outptr_  void** ppResource)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
        return E_NOTIMPL;
    }

    #pragma endregion

    #pragma region ID3D11Device2 Implementation

    virtual void STDMETHODCALLTYPE GetImmediateContext2(
        _Outptr_  ID3D11DeviceContext2** ppImmediateContext)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateDeferredContext2(
        UINT ContextFlags,
        _COM_Outptr_opt_  ID3D11DeviceContext2** ppDeferredContext)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
        return E_NOTIMPL;
    }

    virtual void STDMETHODCALLTYPE GetResourceTiling(
        _In_  ID3D11Resource* pTiledResource,
        _Out_opt_  UINT* pNumTilesForEntireResource,
        _Out_opt_  D3D11_PACKED_MIP_DESC* pPackedMipDesc,
        _Out_opt_  D3D11_TILE_SHAPE* pStandardTileShapeForNonPackedMips,
        _Inout_opt_  UINT* pNumSubresourceTilings,
        _In_  UINT FirstSubresourceTilingToGet,
        _Out_writes_(*pNumSubresourceTilings)  D3D11_SUBRESOURCE_TILING* pSubresourceTilingsForNonPackedMips)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
    }

    virtual HRESULT STDMETHODCALLTYPE CheckMultisampleQualityLevels1(
        _In_  DXGI_FORMAT Format,
        _In_  UINT SampleCount,
        _In_  UINT Flags,
        _Out_  UINT* pNumQualityLevels)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
        return S_OK;
    }

    #pragma endregion

    #pragma region Context

    D3D11Device2Proxy(ID3D11Device* pThis)
    {
        This = pThis;
    }

    ID3D11Device* This;

    #pragma endregion
};

/// <summary>
/// [IDXGISwapChain1] > [IDXGISwapChain] > IDXGIDeviceSubObject > IDXGIObject > IUnknown
/// </summary>
struct DXGISwapChain1Proxy : public IDXGISwapChain1
{
    // Hook IUnknown::QueryInterface

    #pragma region IUnknown Implementation

    virtual HRESULT STDMETHODCALLTYPE QueryInterface(
        REFIID riid,
        _COM_Outptr_ void __RPC_FAR* __RPC_FAR* ppvObject
    )
    {
        if (riid == __uuidof(IDXGISwapChain1))
        {
            LogWrite(L"%s : Returns this proxy\n", __FUNCTIONW__);
            *ppvObject = this;
            return S_OK;
        }

        return This->QueryInterface(riid, ppvObject);
    }

    virtual ULONG STDMETHODCALLTYPE AddRef(void)
    {
        return This->AddRef();
    }

    virtual ULONG STDMETHODCALLTYPE Release(void)
    {
        return This->Release();
    }

    #pragma endregion

    #pragma region IDXGIObject Implementation

    virtual HRESULT STDMETHODCALLTYPE SetPrivateData(
        _In_  REFGUID Name,
        UINT DataSize,
        _In_reads_bytes_(DataSize)  const void* pData)
    {
        return This->SetPrivateData(Name, DataSize, pData);
    }

    virtual HRESULT STDMETHODCALLTYPE SetPrivateDataInterface(
        _In_  REFGUID Name,
        _In_opt_  const IUnknown* pUnknown)
    {
        return This->SetPrivateDataInterface(Name, pUnknown);
    }

    virtual HRESULT STDMETHODCALLTYPE GetPrivateData(
        _In_  REFGUID Name,
        _Inout_  UINT* pDataSize,
        _Out_writes_bytes_(*pDataSize)  void* pData)
    {
        return This->GetPrivateData(Name, pDataSize, pData);
    }

    virtual HRESULT STDMETHODCALLTYPE GetParent(
        _In_  REFIID riid,
        _COM_Outptr_  void** ppParent)
    {
        return This->GetParent(riid, ppParent);
    }

    #pragma endregion

    #pragma region IDXGIDeviceSubObject Implementation

    virtual HRESULT STDMETHODCALLTYPE GetDevice(
        _In_  REFIID riid,
        _COM_Outptr_  void** ppDevice)
    {
        return This->GetDevice(riid, ppDevice);
    }

    #pragma endregion

    #pragma region IDXGISwapChain Implementation

    virtual HRESULT STDMETHODCALLTYPE Present(
        UINT SyncInterval,
        UINT Flags)
    {
        return This->Present(SyncInterval, Flags);
    }

    virtual HRESULT STDMETHODCALLTYPE GetBuffer(
        UINT Buffer,
        _In_  REFIID riid,
        _COM_Outptr_  void** ppSurface)
    {
        return This->GetBuffer(Buffer, riid, ppSurface);
    }

    virtual HRESULT STDMETHODCALLTYPE SetFullscreenState(
        BOOL Fullscreen,
        _In_opt_  IDXGIOutput* pTarget)
    {
        return This->SetFullscreenState(Fullscreen, pTarget);
    }

    virtual HRESULT STDMETHODCALLTYPE GetFullscreenState(
        _Out_opt_  BOOL* pFullscreen,
        _COM_Outptr_opt_result_maybenull_  IDXGIOutput** ppTarget)
    {
        return This->GetFullscreenState(pFullscreen, ppTarget);
    }

    virtual HRESULT STDMETHODCALLTYPE GetDesc(
        _Out_  DXGI_SWAP_CHAIN_DESC* pDesc)
    {
        return This->GetDesc(pDesc);
    }

    virtual HRESULT STDMETHODCALLTYPE ResizeBuffers(
        UINT BufferCount,
        UINT Width,
        UINT Height,
        DXGI_FORMAT NewFormat,
        UINT SwapChainFlags)
    {
        return This->ResizeBuffers(BufferCount, Width, Height, NewFormat, SwapChainFlags);
    }

    virtual HRESULT STDMETHODCALLTYPE ResizeTarget(
        _In_  const DXGI_MODE_DESC* pNewTargetParameters)
    {
        return This->ResizeTarget(pNewTargetParameters);
    }

    virtual HRESULT STDMETHODCALLTYPE GetContainingOutput(
        _COM_Outptr_  IDXGIOutput** ppOutput)
    {
        return This->GetContainingOutput(ppOutput);
    }

    virtual HRESULT STDMETHODCALLTYPE GetFrameStatistics(
        _Out_  DXGI_FRAME_STATISTICS* pStats)
    {
        return This->GetFrameStatistics(pStats);
    }

    virtual HRESULT STDMETHODCALLTYPE GetLastPresentCount(
        _Out_  UINT* pLastPresentCount)
    {
        return This->GetLastPresentCount(pLastPresentCount);
    }

    #pragma endregion

    #pragma region IDXGISwapChain1 Implementation

    virtual HRESULT STDMETHODCALLTYPE GetDesc1(
        _Out_  DXGI_SWAP_CHAIN_DESC1* pDesc)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
        return E_NOTIMPL;
    }

    virtual HRESULT STDMETHODCALLTYPE GetFullscreenDesc(
        _Out_  DXGI_SWAP_CHAIN_FULLSCREEN_DESC* pDesc)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
        return E_NOTIMPL;
    }

    virtual HRESULT STDMETHODCALLTYPE GetHwnd(
        _Out_  HWND* pHwnd)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
        return E_NOTIMPL;
    }

    virtual HRESULT STDMETHODCALLTYPE GetCoreWindow(
        _In_  REFIID refiid,
        _COM_Outptr_  void** ppUnk)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
        return E_NOTIMPL;
    }

    virtual HRESULT STDMETHODCALLTYPE Present1(
        UINT SyncInterval,
        UINT PresentFlags,
        _In_  const DXGI_PRESENT_PARAMETERS* pPresentParameters)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
        return E_NOTIMPL;
    }

    virtual BOOL STDMETHODCALLTYPE IsTemporaryMonoSupported(void)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
        return E_NOTIMPL;
    }

    virtual HRESULT STDMETHODCALLTYPE GetRestrictToOutput(
        _Out_  IDXGIOutput** ppRestrictToOutput)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
        return E_NOTIMPL;
    }

    virtual HRESULT STDMETHODCALLTYPE SetBackgroundColor(
        _In_  const DXGI_RGBA* pColor)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
        return E_NOTIMPL;
    }

    virtual HRESULT STDMETHODCALLTYPE GetBackgroundColor(
        _Out_  DXGI_RGBA* pColor)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
        return E_NOTIMPL;
    }

    virtual HRESULT STDMETHODCALLTYPE SetRotation(
        _In_  DXGI_MODE_ROTATION Rotation)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
        return E_NOTIMPL;
    }

    virtual HRESULT STDMETHODCALLTYPE GetRotation(
        _Out_  DXGI_MODE_ROTATION* pRotation)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
        return E_NOTIMPL;
    }

    #pragma endregion

    #pragma region Context

    DXGISwapChain1Proxy(IDXGISwapChain* pThis)
    {
        This = pThis;
    }

    IDXGISwapChain* This;

    #pragma endregion
};

/// <summary>
/// IDWriteFactory2 > IDWriteFactory1 > [IDWriteFactory] > IUnknown
/// </summary>
struct DWriteFactory2Proxy : public IDWriteFactory2
{

    #pragma region IUnknown Implementation

    virtual HRESULT STDMETHODCALLTYPE QueryInterface(
        REFIID riid,
        _COM_Outptr_ void __RPC_FAR* __RPC_FAR* ppvObject
    )
    {
        return This->QueryInterface(riid, ppvObject);
    }

    virtual ULONG STDMETHODCALLTYPE AddRef(void)
    {
        return This->AddRef();
    }

    virtual ULONG STDMETHODCALLTYPE Release(void)
    {
        return This->Release();
    }

    #pragma endregion

    #pragma region IDWriteFactory Implementation

    STDMETHOD(GetSystemFontCollection)(
        _COM_Outptr_ IDWriteFontCollection** fontCollection,
        BOOL checkForUpdates = FALSE
        )
    {
        return This->GetSystemFontCollection(fontCollection, checkForUpdates);
    }

    STDMETHOD(CreateCustomFontCollection)(
        _In_ IDWriteFontCollectionLoader* collectionLoader,
        _In_reads_bytes_(collectionKeySize) void const* collectionKey,
        UINT32 collectionKeySize,
        _COM_Outptr_ IDWriteFontCollection** fontCollection
        )
    {
        return This->CreateCustomFontCollection(collectionLoader, collectionKey, collectionKeySize, fontCollection);
    }

    STDMETHOD(RegisterFontCollectionLoader)(
        _In_ IDWriteFontCollectionLoader* fontCollectionLoader
        )
    {
        return This->RegisterFontCollectionLoader(fontCollectionLoader);
    }

    STDMETHOD(UnregisterFontCollectionLoader)(
        _In_ IDWriteFontCollectionLoader* fontCollectionLoader
        )
    {
        return This->UnregisterFontCollectionLoader(fontCollectionLoader);
    }

    STDMETHOD(CreateFontFileReference)(
        _In_z_ WCHAR const* filePath,
        _In_opt_ FILETIME const* lastWriteTime,
        _COM_Outptr_ IDWriteFontFile** fontFile
        )
    {
        return This->CreateFontFileReference(filePath, lastWriteTime, fontFile);
    }

    STDMETHOD(CreateCustomFontFileReference)(
        _In_reads_bytes_(fontFileReferenceKeySize) void const* fontFileReferenceKey,
        UINT32 fontFileReferenceKeySize,
        _In_ IDWriteFontFileLoader* fontFileLoader,
        _COM_Outptr_ IDWriteFontFile** fontFile
        )
    {
        return This->CreateCustomFontFileReference(fontFileReferenceKey, fontFileReferenceKeySize,
            fontFileLoader, fontFile);
    }

    STDMETHOD(CreateFontFace)(
        DWRITE_FONT_FACE_TYPE fontFaceType,
        UINT32 numberOfFiles,
        _In_reads_(numberOfFiles) IDWriteFontFile* const* fontFiles,
        UINT32 faceIndex,
        DWRITE_FONT_SIMULATIONS fontFaceSimulationFlags,
        _COM_Outptr_ IDWriteFontFace** fontFace
        )
    {
        return This->CreateFontFace(fontFaceType, numberOfFiles, fontFiles,
            faceIndex, fontFaceSimulationFlags, fontFace);
    }

    STDMETHOD(CreateRenderingParams)(
        _COM_Outptr_ IDWriteRenderingParams** renderingParams
        )
    {
        return This->CreateRenderingParams(renderingParams);
    }

    STDMETHOD(CreateMonitorRenderingParams)(
        HMONITOR monitor,
        _COM_Outptr_ IDWriteRenderingParams** renderingParams
        )
    {
        return This->CreateMonitorRenderingParams(monitor, renderingParams);
    }

    STDMETHOD(CreateCustomRenderingParams)(
        FLOAT gamma,
        FLOAT enhancedContrast,
        FLOAT clearTypeLevel,
        DWRITE_PIXEL_GEOMETRY pixelGeometry,
        DWRITE_RENDERING_MODE renderingMode,
        _COM_Outptr_ IDWriteRenderingParams** renderingParams
        )
    {
        return This->CreateCustomRenderingParams(gamma, enhancedContrast,
            clearTypeLevel, pixelGeometry, renderingMode, renderingParams);
    }

    STDMETHOD(RegisterFontFileLoader)(
        _In_ IDWriteFontFileLoader* fontFileLoader
        )
    {
        return This->RegisterFontFileLoader(fontFileLoader);
    }

    STDMETHOD(UnregisterFontFileLoader)(
        _In_ IDWriteFontFileLoader* fontFileLoader
        )
    {
        return This->UnregisterFontFileLoader(fontFileLoader);
    }

    STDMETHOD(CreateTextFormat)(
        _In_z_ WCHAR const* fontFamilyName,
        _In_opt_ IDWriteFontCollection* fontCollection,
        DWRITE_FONT_WEIGHT fontWeight,
        DWRITE_FONT_STYLE fontStyle,
        DWRITE_FONT_STRETCH fontStretch,
        FLOAT fontSize,
        _In_z_ WCHAR const* localeName,
        _COM_Outptr_ IDWriteTextFormat** textFormat
        )
    {
        return This->CreateTextFormat(fontFamilyName, fontCollection,
            fontWeight, fontStyle, fontStretch, fontSize, localeName, textFormat);
    }

    STDMETHOD(CreateTypography)(
        _COM_Outptr_ IDWriteTypography** typography
        )
    {
        return This->CreateTypography(typography);
    }

    STDMETHOD(GetGdiInterop)(
        _COM_Outptr_ IDWriteGdiInterop** gdiInterop
        )
    {
        return This->GetGdiInterop(gdiInterop);
    }

    STDMETHOD(CreateTextLayout)(
        _In_reads_(stringLength) WCHAR const* string,
        UINT32 stringLength,
        _In_ IDWriteTextFormat* textFormat,
        FLOAT maxWidth,
        FLOAT maxHeight,
        _COM_Outptr_ IDWriteTextLayout** textLayout
        )
    {
        return This->CreateTextLayout(string, stringLength, textFormat, maxWidth, maxHeight, textLayout);
    }

    STDMETHOD(CreateGdiCompatibleTextLayout)(
        _In_reads_(stringLength) WCHAR const* string,
        UINT32 stringLength,
        _In_ IDWriteTextFormat* textFormat,
        FLOAT layoutWidth,
        FLOAT layoutHeight,
        FLOAT pixelsPerDip,
        _In_opt_ DWRITE_MATRIX const* transform,
        BOOL useGdiNatural,
        _COM_Outptr_ IDWriteTextLayout** textLayout
        )
    {
        return This->CreateGdiCompatibleTextLayout(string, stringLength, textFormat,
            layoutWidth, layoutHeight, pixelsPerDip, transform, useGdiNatural, textLayout);
    }

    STDMETHOD(CreateEllipsisTrimmingSign)(
        _In_ IDWriteTextFormat* textFormat,
        _COM_Outptr_ IDWriteInlineObject** trimmingSign
        )
    {
        return This->CreateEllipsisTrimmingSign(textFormat, trimmingSign);
    }

    STDMETHOD(CreateTextAnalyzer)(
        _COM_Outptr_ IDWriteTextAnalyzer** textAnalyzer
        )
    {
        return This->CreateTextAnalyzer(textAnalyzer);
    }

    STDMETHOD(CreateNumberSubstitution)(
        _In_ DWRITE_NUMBER_SUBSTITUTION_METHOD substitutionMethod,
        _In_z_ WCHAR const* localeName,
        _In_ BOOL ignoreUserOverride,
        _COM_Outptr_ IDWriteNumberSubstitution** numberSubstitution
        )
    {
        return This->CreateNumberSubstitution(substitutionMethod, localeName, ignoreUserOverride, numberSubstitution);
    }

    STDMETHOD(CreateGlyphRunAnalysis)(
        _In_ DWRITE_GLYPH_RUN const* glyphRun,
        FLOAT pixelsPerDip,
        _In_opt_ DWRITE_MATRIX const* transform,
        DWRITE_RENDERING_MODE renderingMode,
        DWRITE_MEASURING_MODE measuringMode,
        FLOAT baselineOriginX,
        FLOAT baselineOriginY,
        _COM_Outptr_ IDWriteGlyphRunAnalysis** glyphRunAnalysis
        )
    {
        return This->CreateGlyphRunAnalysis(glyphRun, pixelsPerDip, transform,
            renderingMode, measuringMode, baselineOriginX, baselineOriginY, glyphRunAnalysis);
    }

    #pragma endregion

    #pragma region IDWriteFactory1 Implementation

    STDMETHOD(GetEudcFontCollection)(
        _COM_Outptr_ IDWriteFontCollection** fontCollection,
        BOOL checkForUpdates = FALSE
        )
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
        return E_NOTIMPL;
    }

    STDMETHOD(CreateCustomRenderingParams)(
        FLOAT gamma,
        FLOAT enhancedContrast,
        FLOAT enhancedContrastGrayscale,
        FLOAT clearTypeLevel,
        DWRITE_PIXEL_GEOMETRY pixelGeometry,
        DWRITE_RENDERING_MODE renderingMode,
        _COM_Outptr_ IDWriteRenderingParams1** renderingParams
        )
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
        return E_NOTIMPL;
    }

    #pragma endregion

    #pragma region IDWriteFactory2 Implementation

    STDMETHOD(GetSystemFontFallback)(
        _COM_Outptr_ IDWriteFontFallback** fontFallback
        )
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
        return E_NOTIMPL;
    }

    STDMETHOD(CreateFontFallbackBuilder)(
        _COM_Outptr_ IDWriteFontFallbackBuilder** fontFallbackBuilder
        )
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
        return E_NOTIMPL;
    }

    STDMETHOD(TranslateColorGlyphRun)(
        FLOAT baselineOriginX,
        FLOAT baselineOriginY,
        _In_ DWRITE_GLYPH_RUN const* glyphRun,
        _In_opt_ DWRITE_GLYPH_RUN_DESCRIPTION const* glyphRunDescription,
        DWRITE_MEASURING_MODE measuringMode,
        _In_opt_ DWRITE_MATRIX const* worldToDeviceTransform,
        UINT32 colorPaletteIndex,
        _COM_Outptr_ IDWriteColorGlyphRunEnumerator** colorLayers
        )
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
        return E_NOTIMPL;
    }

    STDMETHOD(CreateCustomRenderingParams)(
        FLOAT gamma,
        FLOAT enhancedContrast,
        FLOAT grayscaleEnhancedContrast,
        FLOAT clearTypeLevel,
        DWRITE_PIXEL_GEOMETRY pixelGeometry,
        DWRITE_RENDERING_MODE renderingMode,
        DWRITE_GRID_FIT_MODE gridFitMode,
        _COM_Outptr_ IDWriteRenderingParams2** renderingParams
        )
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
        return E_NOTIMPL;
    }

    STDMETHOD(CreateGlyphRunAnalysis)(
        _In_ DWRITE_GLYPH_RUN const* glyphRun,
        _In_opt_ DWRITE_MATRIX const* transform,
        DWRITE_RENDERING_MODE renderingMode,
        DWRITE_MEASURING_MODE measuringMode,
        DWRITE_GRID_FIT_MODE gridFitMode,
        DWRITE_TEXT_ANTIALIAS_MODE antialiasMode,
        FLOAT baselineOriginX,
        FLOAT baselineOriginY,
        _COM_Outptr_ IDWriteGlyphRunAnalysis** glyphRunAnalysis
        )
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
        return E_NOTIMPL;
    }

    #pragma endregion

    #pragma region Context

    DWriteFactory2Proxy(IDWriteFactory* pThis)
    {
        This = pThis;
    }

    IDWriteFactory* This;

    #pragma endregion
};

/// <summary>
/// IWICImagingFactory2 > [IWICImagingFactory] > IUnknown
/// </summary>
struct WICImagingFactory2Proxy : public IWICImagingFactory2
{

    #pragma region IUnknown Implementation

    virtual HRESULT STDMETHODCALLTYPE QueryInterface(
        REFIID riid,
        _COM_Outptr_ void __RPC_FAR* __RPC_FAR* ppvObject
    )
    {
        return This->QueryInterface(riid, ppvObject);
    }

    virtual ULONG STDMETHODCALLTYPE AddRef(void)
    {
        return This->AddRef();
    }

    virtual ULONG STDMETHODCALLTYPE Release(void)
    {
        return This->Release();
    }

    #pragma endregion

    #pragma region IWICImagingFactory Implementation

    virtual HRESULT STDMETHODCALLTYPE CreateDecoderFromFilename(
        __RPC__in LPCWSTR wzFilename,
        __RPC__in_opt const GUID* pguidVendor,
        DWORD dwDesiredAccess,
        WICDecodeOptions metadataOptions,
        __RPC__deref_out_opt IWICBitmapDecoder** ppIDecoder)
    {
        return This->CreateDecoderFromFilename(wzFilename, pguidVendor, dwDesiredAccess, metadataOptions, ppIDecoder);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateDecoderFromStream(
        __RPC__in_opt IStream* pIStream,
        __RPC__in_opt const GUID* pguidVendor,
        WICDecodeOptions metadataOptions,
        __RPC__deref_out_opt IWICBitmapDecoder** ppIDecoder)
    {
        return This->CreateDecoderFromStream(pIStream, pguidVendor, metadataOptions, ppIDecoder);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateDecoderFromFileHandle(
        ULONG_PTR hFile,
        __RPC__in_opt const GUID* pguidVendor,
        WICDecodeOptions metadataOptions,
        __RPC__deref_out_opt IWICBitmapDecoder** ppIDecoder)
    {
        return This->CreateDecoderFromFileHandle(hFile, pguidVendor, metadataOptions, ppIDecoder);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateComponentInfo(
        __RPC__in REFCLSID clsidComponent,
        __RPC__deref_out_opt IWICComponentInfo** ppIInfo)
    {
        return This->CreateComponentInfo(clsidComponent, ppIInfo);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateDecoder(
        __RPC__in REFGUID guidContainerFormat,
        __RPC__in_opt const GUID* pguidVendor,
        __RPC__deref_out_opt IWICBitmapDecoder** ppIDecoder)
    {
        return This->CreateDecoder(guidContainerFormat, pguidVendor, ppIDecoder);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateEncoder(
        __RPC__in REFGUID guidContainerFormat,
        __RPC__in_opt const GUID* pguidVendor,
        __RPC__deref_out_opt IWICBitmapEncoder** ppIEncoder)
    {
        return This->CreateEncoder(guidContainerFormat, pguidVendor, ppIEncoder);
    }

    virtual HRESULT STDMETHODCALLTYPE CreatePalette(
        __RPC__deref_out_opt IWICPalette** ppIPalette)
    {
        return This->CreatePalette(ppIPalette);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateFormatConverter(
        __RPC__deref_out_opt IWICFormatConverter** ppIFormatConverter)
    {
        return This->CreateFormatConverter(ppIFormatConverter);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateBitmapScaler(
        __RPC__deref_out_opt IWICBitmapScaler** ppIBitmapScaler)
    {
        return This->CreateBitmapScaler(ppIBitmapScaler);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateBitmapClipper(
        __RPC__deref_out_opt IWICBitmapClipper** ppIBitmapClipper)
    {
        return This->CreateBitmapClipper(ppIBitmapClipper);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateBitmapFlipRotator(
        __RPC__deref_out_opt IWICBitmapFlipRotator** ppIBitmapFlipRotator)
    {
        return This->CreateBitmapFlipRotator(ppIBitmapFlipRotator);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateStream(
        __RPC__deref_out_opt IWICStream** ppIWICStream)
    {
        return This->CreateStream(ppIWICStream);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateColorContext(
        __RPC__deref_out_opt IWICColorContext** ppIWICColorContext)
    {
        return This->CreateColorContext(ppIWICColorContext);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateColorTransformer(
        __RPC__deref_out_opt IWICColorTransform** ppIWICColorTransform)
    {
        return This->CreateColorTransformer(ppIWICColorTransform);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateBitmap(
        UINT uiWidth,
        UINT uiHeight,
        __RPC__in REFWICPixelFormatGUID pixelFormat,
        WICBitmapCreateCacheOption option,
        __RPC__deref_out_opt IWICBitmap** ppIBitmap)
    {
        return This->CreateBitmap(uiWidth, uiHeight, pixelFormat, option, ppIBitmap);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateBitmapFromSource(
        __RPC__in_opt IWICBitmapSource* pIBitmapSource,
        WICBitmapCreateCacheOption option,
        __RPC__deref_out_opt IWICBitmap** ppIBitmap)
    {
        return This->CreateBitmapFromSource(pIBitmapSource, option, ppIBitmap);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateBitmapFromSourceRect(
        __RPC__in_opt IWICBitmapSource* pIBitmapSource,
        UINT x,
        UINT y,
        UINT width,
        UINT height,
        __RPC__deref_out_opt IWICBitmap** ppIBitmap)
    {
        return This->CreateBitmapFromSourceRect(pIBitmapSource, x, y, width, height, ppIBitmap);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateBitmapFromMemory(
        UINT uiWidth,
        UINT uiHeight,
        __RPC__in REFWICPixelFormatGUID pixelFormat,
        UINT cbStride,
        UINT cbBufferSize,
        __RPC__in_ecount_full(cbBufferSize) BYTE* pbBuffer,
        __RPC__deref_out_opt IWICBitmap** ppIBitmap)
    {
        return This->CreateBitmapFromMemory(uiWidth, uiHeight, pixelFormat, cbStride, cbBufferSize, pbBuffer, ppIBitmap);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateBitmapFromHBITMAP(
        __RPC__in HBITMAP hBitmap,
        __RPC__in_opt HPALETTE hPalette,
        WICBitmapAlphaChannelOption options,
        __RPC__deref_out_opt IWICBitmap** ppIBitmap)
    {
        return This->CreateBitmapFromHBITMAP(hBitmap, hPalette, options, ppIBitmap);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateBitmapFromHICON(
        __RPC__in HICON hIcon,
        __RPC__deref_out_opt IWICBitmap** ppIBitmap)
    {
        return This->CreateBitmapFromHICON(hIcon, ppIBitmap);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateComponentEnumerator(
        DWORD componentTypes,
        DWORD options,
        __RPC__deref_out_opt IEnumUnknown** ppIEnumUnknown)
    {
        return This->CreateComponentEnumerator(componentTypes, options, ppIEnumUnknown);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateFastMetadataEncoderFromDecoder(
        __RPC__in_opt IWICBitmapDecoder* pIDecoder,
        __RPC__deref_out_opt IWICFastMetadataEncoder** ppIFastEncoder)
    {
        return This->CreateFastMetadataEncoderFromDecoder(pIDecoder, ppIFastEncoder);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateFastMetadataEncoderFromFrameDecode(
        __RPC__in_opt IWICBitmapFrameDecode* pIFrameDecoder,
        __RPC__deref_out_opt IWICFastMetadataEncoder** ppIFastEncoder)
    {
        return This->CreateFastMetadataEncoderFromFrameDecode(pIFrameDecoder, ppIFastEncoder);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateQueryWriter(
        __RPC__in REFGUID guidMetadataFormat,
        __RPC__in_opt const GUID* pguidVendor,
        __RPC__deref_out_opt IWICMetadataQueryWriter** ppIQueryWriter)
    {
        return This->CreateQueryWriter(guidMetadataFormat, pguidVendor, ppIQueryWriter);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateQueryWriterFromReader(
        __RPC__in_opt IWICMetadataQueryReader* pIQueryReader,
        __RPC__in_opt const GUID* pguidVendor,
        __RPC__deref_out_opt IWICMetadataQueryWriter** ppIQueryWriter)
    {
        return This->CreateQueryWriterFromReader(pIQueryReader, pguidVendor, ppIQueryWriter);
    }

    #pragma endregion

    #pragma region IWICImagingFactory2 Implementation

    virtual HRESULT STDMETHODCALLTYPE CreateImageEncoder(
        ID2D1Device* pD2DDevice,
        IWICImageEncoder** ppWICImageEncoder)
    {
        LogWrite(L"WARNING: Calling %s\n", __FUNCTIONW__);
        return E_NOTIMPL;
    }

    #pragma endregion

    #pragma region Context

    WICImagingFactory2Proxy(IWICImagingFactory* pThis)
    {
        This = pThis;
    }

    IWICImagingFactory* This;

    #pragma endregion
};


#pragma region D2D1CreateFactory Proxy

// Original
typedef HRESULT (WINAPI* PFND2D1CREATEFACTORYPROC)(D2D1_FACTORY_TYPE, REFIID, CONST D2D1_FACTORY_OPTIONS*, void**);
PFND2D1CREATEFACTORYPROC pfnD2D1CreateFactory = NULL;
// Hooked
HRESULT WINAPI Hook_D2D1CreateFactory(D2D1_FACTORY_TYPE factoryType, REFIID riid, CONST D2D1_FACTORY_OPTIONS* pFactoryOptions, void** ppIFactory)
{
    if (riid == __uuidof(ID2D1Factory2))
    {
        HRESULT result = pfnD2D1CreateFactory(factoryType, riid, pFactoryOptions, ppIFactory);

        if (result == E_NOINTERFACE)
        {
            LogWrite(L"%s : Interface ID2D1Factory2 was not found, try to fall back to ID2D1Factory1\n", __FUNCTIONW__);

            ID2D1Factory1* pD2D1Factory1;

            result = pfnD2D1CreateFactory(factoryType, __uuidof(ID2D1Factory1), pFactoryOptions, (void**)&pD2D1Factory1);

            if (result == S_OK)
            {
                LogWrite(L"%s : Using ID2D1Factory1\n", __FUNCTIONW__);

                *ppIFactory = new D2D1Factory2Proxy(pD2D1Factory1);

                return S_OK;
            }
        }
    }

    return pfnD2D1CreateFactory(factoryType, riid, pFactoryOptions, ppIFactory);
}

#pragma endregion

#pragma region DWriteCreateFactory Proxy

// Original
auto pfnDWriteCreateFactory = DWriteCreateFactory;
// Hooked
HRESULT WINAPI Hook_DWriteCreateFactory(DWRITE_FACTORY_TYPE factoryType, REFIID iid, IUnknown** factory)
{
    if (iid == __uuidof(IDWriteFactory2))
    {
        HRESULT result = pfnDWriteCreateFactory(factoryType, iid, factory);

        if (result == E_NOINTERFACE)
        {
            LogWrite(L"%s : Interface IDWriteFactory2 was not found, try to fall back to IDWriteFactory\n", __FUNCTIONW__);

            IDWriteFactory* pDWriteFactory;

            result = pfnDWriteCreateFactory(factoryType, __uuidof(IDWriteFactory), (IUnknown**)&pDWriteFactory);

            if (result == S_OK)
            {
                LogWrite(L"%s : Using IDWriteFactory\n", __FUNCTIONW__);

                *factory = new DWriteFactory2Proxy(pDWriteFactory);

                return S_OK;
            }
        }
    }

    return pfnDWriteCreateFactory(factoryType, iid, factory);
}

#pragma endregion

#pragma region CoCreateInstance Proxy

// Original
auto pfnCoCreateInstance = CoCreateInstance;
// Hooked
HRESULT WINAPI Hook_CoCreateInstance(REFCLSID rclsid, LPUNKNOWN pUnkOuter, DWORD dwClsContext, REFIID riid, LPVOID  FAR* ppv)
{
    if (rclsid == CLSID_WICImagingFactory2 && riid == IID_IWICImagingFactory2)
    {
        HRESULT result = pfnCoCreateInstance(rclsid, pUnkOuter, dwClsContext, riid, ppv);

        if (result == E_NOINTERFACE)
        {
            LogWrite(L"%s : Interface IWICImagingFactory2 was not found, try to fall back to IWICImagingFactory1\n", __FUNCTIONW__);

            IWICImagingFactory* pWICImagingFactory;

            result = pfnCoCreateInstance(CLSID_WICImagingFactory1, pUnkOuter, dwClsContext, IID_IWICImagingFactory, (void**)&pWICImagingFactory);

            if (result == S_OK)
            {
                LogWrite(L"%s : Using IWICImagingFactory1\n", __FUNCTIONW__);

                *ppv = new WICImagingFactory2Proxy(pWICImagingFactory);

                return S_OK;
            }
        }
    }

    return pfnCoCreateInstance(rclsid, pUnkOuter, dwClsContext, riid, ppv);
}

#pragma endregion

#pragma region D3D11CreateDeviceAndSwapChain Proxy

// Original
auto pfnD3D11CreateDeviceAndSwapChain = D3D11CreateDeviceAndSwapChain;
// Hooked
HRESULT WINAPI Hook_D3D11CreateDeviceAndSwapChain(
    IDXGIAdapter* pAdapter,
    D3D_DRIVER_TYPE DriverType,
    HMODULE Software,
    UINT Flags,
    CONST D3D_FEATURE_LEVEL* pFeatureLevels,
    UINT FeatureLevels,
    UINT SDKVersion,
    CONST DXGI_SWAP_CHAIN_DESC* pSwapChainDesc,
    IDXGISwapChain** ppSwapChain,
    ID3D11Device** ppDevice,
    D3D_FEATURE_LEVEL* pFeatureLevel,
    ID3D11DeviceContext** ppImmediateContext)
{
    HRESULT result = pfnD3D11CreateDeviceAndSwapChain(pAdapter, DriverType, Software, Flags, pFeatureLevels, FeatureLevels,
        SDKVersion, pSwapChainDesc, ppSwapChain, ppDevice, pFeatureLevel, ppImmediateContext);

    if (result == S_OK)
    {
        IDXGISwapChain* pDXGISwapChain;
        IDXGISwapChain* pDXGISwapChain1;
        ID3D11Device* pD3D11Device;
        ID3D11Device* pD3D11Device1;
        ID3D11DeviceContext* pD3D11DeviceContext;
        ID3D11DeviceContext* pD3D11DeviceContext1;

        pDXGISwapChain = *ppSwapChain;
        pD3D11Device = *ppDevice;
        pD3D11DeviceContext = *ppImmediateContext;

        if (pD3D11Device->QueryInterface(&pD3D11Device1) == S_OK)
        {
            LogWrite(L"%s : Using D3D11Device2Proxy\n", __FUNCTIONW__);

            *ppDevice = new D3D11Device2Proxy(pD3D11Device1);
        }

        if (pD3D11DeviceContext->QueryInterface(&pD3D11DeviceContext1) == S_OK)
        {
            LogWrite(L"%s : Using D3D11DeviceContext2Proxy\n", __FUNCTIONW__);

            *ppImmediateContext = new D3D11DeviceContext2Proxy(pD3D11DeviceContext1);
        }

        if (pDXGISwapChain->QueryInterface(&pDXGISwapChain1) == S_OK)
        {
            LogWrite(L"%s : Using DXGISwapChain1Proxy\n", __FUNCTIONW__);

            *ppSwapChain = new DXGISwapChain1Proxy(pDXGISwapChain1);
        }
    }

    return result;
}

#pragma endregion

#pragma region MultiByteToWideChar Hook For Shift_JIS Support

// Original
auto pfnMultiByteToWideChar = MultiByteToWideChar;
// Hooked
int WINAPI Hook_MultiByteToWideChar(
    _In_ UINT CodePage,
    _In_ DWORD dwFlags,
    _In_NLS_string_(cbMultiByte) LPCCH lpMultiByteStr,
    _In_ int cbMultiByte,
    _Out_writes_to_opt_(cchWideChar, return) LPWSTR lpWideCharStr,
    _In_ int cchWideChar)
{
    if (CodePage == CP_ACP || CodePage == CP_THREAD_ACP)
        CodePage = 932;

    return pfnMultiByteToWideChar(CodePage, dwFlags, lpMultiByteStr, cbMultiByte, lpWideCharStr, cchWideChar);
}

#pragma endregion


#define FPS_LIMIT
#define SLEEP_TIME_MS 0x30

#ifdef FPS_LIMIT

// Original
typedef DWORD (_fastcall *PfProcessWindowMessages)(DWORD, DWORD);
PfProcessWindowMessages pfnProcessWindowMessages = NULL;
// Hooked
DWORD _fastcall Hook_ProcessWindowMessages(DWORD This, DWORD A1)
{
    Sleep(SLEEP_TIME_MS);
    return pfnProcessWindowMessages(This, A1);
}

#endif


//=============================================================================
// Startup Code
//=============================================================================


void InstallPatches()
{
#ifdef FPS_LIMIT
    DWORD Base = (DWORD)GetModuleHandle(NULL);

    // MOV EBX, 0x20
    // NOP
    // NOP
    // ...
    BYTE patch[] = { 0xBB, SLEEP_TIME_MS, 0x00, 0x00, 0x00, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 };
    PatchWrite((PVOID)(Base + 0x26F48), patch);
#endif
}


void InstallHooks()
{
    LogWrite(L"Patch Started\n");

    DWORD Base = (DWORD)GetModuleHandle(NULL);

    HMODULE hD2D1 = LoadLibraryW(L"D2D1.DLL");

    if (hD2D1 == NULL)
    {
        LogWrite(L"LoadLibrary \"D2D1.DLL\" Failed\n");
        return;
    }

    pfnD2D1CreateFactory = (PFND2D1CREATEFACTORYPROC)GetProcAddress(hD2D1, "D2D1CreateFactory");

    //IATHook(NULL, "D2D1.DLL", NULL, 1, Hook_D2D1CreateFactory);
    InlineHook(pfnD2D1CreateFactory, Hook_D2D1CreateFactory);

    IATHook(NULL, "D3D11.DLL", "D3D11CreateDeviceAndSwapChain", -1, Hook_D3D11CreateDeviceAndSwapChain);
    IATHook(NULL, "DWRITE.DLL", "DWriteCreateFactory", -1, Hook_DWriteCreateFactory);
    IATHook(NULL, "OLE32.DLL", "CoCreateInstance", -1, Hook_CoCreateInstance);

    IATHook(NULL, "KERNEL32.DLL", "MultiByteToWideChar", -1, Hook_MultiByteToWideChar);

#ifdef FPS_LIMIT
    pfnProcessWindowMessages = (PfProcessWindowMessages)(Base + 0x478B0);
    InlineHook(pfnProcessWindowMessages, Hook_ProcessWindowMessages);
#endif

    BT_InterceptSUEF(GetModuleHandle(NULL), TRUE);
    BT_SetAppName(_T("fuyukuru"));
    BT_SetFlags(BTF_DETAILEDMODE | BTF_SHOWADVANCEDUI | BTF_INTERCEPTSUEF);
}


//=============================================================================
// DLL Entry Point
//=============================================================================


BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
        case DLL_PROCESS_ATTACH:
        {
            // See https://github.com/microsoft/Detours/wiki/DetourRestoreAfterWith
            DetourRestoreAfterWith();

            LogInit(L"fuyukuru.patch.log");

            InstallPatches();
            InstallHooks();

            break;
        }
        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
        case DLL_PROCESS_DETACH:
            break;
    }
    return TRUE;
}


//=============================================================================
// Dummy Export Symbol
//=============================================================================


BOOL APIENTRY CreateObject()
{
    return TRUE;
}
