Imports School.StudentList
Public Class FormSearchStudent
    Private Sub search_Click(sender As Object, e As EventArgs) Handles search.Click
        ' First check if roll number exists
        If (srch_roll.Text = "") Then
            MessageBox.Show("Enter a roll to search")
            Return
        End If
        Dim flag As Integer
            flag = 0
        For i As Integer = 0 To stList.Count() - 1
            If (stList(i).getRoll() = srch_roll.Text) Then
                flag = 1
                ' Set texts
                srch_name.Text = stList(i).getName()
                srch_dept.Text = stList(i).getDept()
                srch_dcode.Text = stList(i).getDcode()
            End If
        Next

        If (flag = 0) Then
            MessageBox.Show("Invalid roll number")
        End If
    End Sub
End Class