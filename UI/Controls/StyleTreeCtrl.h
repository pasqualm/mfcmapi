#pragma once

namespace controls
{
	class StyleTreeCtrl : public CTreeCtrl
	{
	public:
		void Create(_In_ CWnd* pCreateParent, UINT nIDContextMenu, bool bReadOnly);
		_Check_return_ bool IsItemSelected() const { return m_bItemSelected; }
		void Refresh();
		HTREEITEM
		AddChildNode(
			_In_ const std::wstring& szName,
			HTREEITEM hParent,
			LPARAM lpData,
			const std::function<void(HTREEITEM hItem)>& callback) const;

		// Callbacks
		void SetHasChildrenCallback(const std::function<bool(HTREEITEM hItem)>& callback)
		{
			HasChildrenCallback = callback;
		}
		void SetItemSelectedCallback(const std::function<void(HTREEITEM hItem)>& callback)
		{
			ItemSelectedCallback = callback;
		}

	protected:
		LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam) override;
		BOOL PreTranslateMessage(MSG* pMsg) override;

		// Node management
		// Removes any existing node data and replaces it with lpData
		void SetNodeData(HWND hWnd, HTREEITEM hItem, LPARAM lpData) const;
		void OnSelChanged(_In_ NMHDR* pNMHDR, _In_ LRESULT* pResult);

		UINT m_nIDContextMenu{0};
		bool m_bShuttingDown{false};

	private:
		// Overrides for derived controls to customize behavior
		// Override to provide custom deletion of node data
		virtual void FreeNodeData(LPARAM /*lpData*/) const {};
		virtual void ExpandNode(HTREEITEM /*hParent*/) const {}
		virtual void OnRefresh() const {}
		virtual void OnLabelEdit(HTREEITEM /*hItem*/, LPTSTR /*szText*/) {}
		virtual void OnDisplaySelectedItem() {}
		virtual void OnLastChildDeleted(LPARAM /*lpData*/) {}

		// Return true to signal keystroke has been handled
		virtual bool HandleKeyDown(UINT /*nChar*/, bool /*bShiftPressed*/, bool /*bCtrlPressed*/, bool /*bMenuPressed*/)
		{
			return false;
		}

		void OnGetDispInfo(_In_ NMHDR* pNMHDR, _In_ LRESULT* pResult);

		// Overrides from base class
		void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);

		void OnCustomDraw(_In_ NMHDR* pNMHDR, _In_ LRESULT* pResult);
		void OnRightClick(_In_ NMHDR* pNMHDR, _In_ LRESULT* pResult);
		void OnItemExpanding(_In_ NMHDR* pNMHDR, _In_ LRESULT* pResult);
		_Check_return_ UINT OnGetDlgCode();
		virtual void HandleContextMenu(const int /*x*/, const int /*y*/) {}
		void OnContextMenu(_In_ HWND hwnd, int x, int y);
		void OnEndLabelEdit(_In_ NMHDR* pNMHDR, _In_ LRESULT* pResult);
		void OnDeleteItem(_In_ NMHDR* pNMHDR, _In_ LRESULT* pResult);
		void OnDblclk(_In_ NMHDR* pNMHDR, _In_ LRESULT* pResult);

		HTREEITEM m_hItemCurHover{nullptr};
		bool m_HoverButton{false};
		bool m_bItemSelected{false};
		bool m_bReadOnly{false};

		// Callbacks
		std::function<bool(HTREEITEM hItem)> HasChildrenCallback = nullptr;
		std::function<void(HTREEITEM hItem)> ItemSelectedCallback = nullptr;

		DECLARE_MESSAGE_MAP()
	};
} // namespace controls