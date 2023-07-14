#ifndef LANGUAGEMODEL_H
#define LANGUAGEMODEL_H

#include <QAbstractListModel>
#include <QQmlEngine>

#include "settings.h"

namespace LanguageSettings
{
    Q_NAMESPACE
    enum class AvailableLanguageEnum {
        English,
        Russian
    };
    Q_ENUM_NS(AvailableLanguageEnum)

    static void declareQmlAvailableLanguageEnum()
    {
        qmlRegisterUncreatableMetaObject(LanguageSettings::staticMetaObject, "AvailableLanguageEnum", 1, 0,
                                         "AvailableLanguageEnum", QString());
    }
}

struct LanguageModelData
{
    QString name;
    LanguageSettings::AvailableLanguageEnum index;
};

class LanguageModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum Roles {
        NameRole = Qt::UserRole + 1,
        IndexRole
    };

    LanguageModel(std::shared_ptr<Settings> settings, QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

public slots:
    void changeLanguage(const LanguageSettings::AvailableLanguageEnum language);
    int getCurrentLanguageIndex();
    QString getCurrentLanuageName();

signals:
    void updateTranslations(const QLocale &locale);

protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    QVector<LanguageModelData> m_availableLanguages;

    std::shared_ptr<Settings> m_settings;
};

#endif // LANGUAGEMODEL_H
