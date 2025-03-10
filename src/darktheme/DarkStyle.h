#ifndef DARKSTYLE_H
#define DARKSTYLE_H

#include <QPainter>
#include <QProxyStyle>

class QStyleOptionViewItem;

class DarkStyle : public QProxyStyle {
public:
private:
	struct Private;
	Private *m;

	class ButtonImages {
	public:
		QImage im_normal;
		QImage im_hover;
	};

	struct ScrollBarTextures {
		QImage page_bg;
		ButtonImages sub_line;
		ButtonImages add_line;
		ButtonImages slider;
	};

	QImage colorizeImage(QImage image);
	QImage loadColorizedImage(QString const &path, QString const &role = QString());
	ButtonImages generateButtonImages(QString const &path);
	QImage generateHoverImage(const QImage &source);
	QPixmap pixmapFromImage(QImage const &image, QSize size) const;
	void loadImages();

	QColor selectionColor() const;
	QColor colorForItemView(QStyleOption const *opt) const;

	void drawNinePatchImage(QPainter *p, QImage const &image, QRect const &r, int w, int h) const;
	void drawGutter(QPainter *p, QRect const &r) const;
	void drawSelectedItemFrame(QPainter *p, QRect rect, bool focus) const;
	void drawFocusFrame(QPainter *p, const QRect &rect, int margin) const;
	void drawButton(QPainter *p, QStyleOption const *option, bool mac_margin = true) const;
	void drawToolButton(QPainter *p, QStyleOption const *option) const;
	void drawMenuBarBG(QPainter *p, const QStyleOption *option, const QWidget *widget) const;
	QColor color(int level, int alpha = 255) const;
	void drawItemViewText(QPainter *p, const QStyleOptionViewItem *option, const QRect &rect, bool abbreviation) const;
public:
	DarkStyle(const QColor &base_color = QColor());
	~DarkStyle() override;

	QColor getBaseColor();
	void setBaseColor(const QColor &color);
	void setScrollBarExtent(int n);

	void polish(QPalette &palette) override;
	int pixelMetric(PixelMetric metric, const QStyleOption *option, const QWidget *widget) const override;
	QRect subControlRect(ComplexControl cc, const QStyleOptionComplex *option, SubControl sc, const QWidget *widget) const override;
	int styleHint(StyleHint stylehint, const QStyleOption *opt = nullptr, const QWidget *widget = nullptr, QStyleHintReturn *returnData = nullptr) const;
	void drawPrimitive(PrimitiveElement pe, const QStyleOption *option, QPainter *p, const QWidget *widget) const override;
	void drawControl(ControlElement ce, const QStyleOption *option, QPainter *p, const QWidget *widget) const override;
	void drawComplexControl(ComplexControl cc, const QStyleOptionComplex *option, QPainter *p, const QWidget *widget) const override;
};

#endif // DARKSTYLE_H
